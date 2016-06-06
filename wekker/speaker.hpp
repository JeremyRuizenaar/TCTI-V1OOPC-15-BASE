class speaker {
private:
	
	hwlib::target::pin_out buzzerpin;
	display scherm;
	hwlib::target::pin_in_out cancel;
	int toggle =0;
	
public:
	speaker(hwlib::target::pin_out & buzzer, display scherm, hwlib::target::pin_in_out cancel):
	buzzerpin (buzzer),
	scherm (scherm),
	cancel ( cancel )
	{}
	
	void buzz_on(){
		
		namespace target = hwlib::target;
		hwlib::wait_ms(10);
		while( ! cancel.get()){
			//scherm.updateA(4);
			//scherm.updateB(4);
			buzzerpin.set(0);
			hwlib::wait_us(30);
			buzzerpin.set(1);
			hwlib::wait_us(800);
			//hwlib::wait_ms(10);
			//hwlib::wait_ms(100);
			if(  cancel.get()){
				hwlib::wait_ms(100);
				break;
			}
		
		}
		
		
		
		//buzzerpin.set(0);
	}
	
	void box_hold(){
		namespace target = hwlib::target;
		hwlib::wait_ms(1000);
		for (volatile int i = 0; i<3; i++){
			scherm.updateA(6);
			scherm.updateB(6);
			hwlib::wait_ms(100);
			if( ! cancel.get()){
				hwlib::wait_ms(100);
				break;
			}
		
		}
	}
	
	void play(int lengte, int toon_down ,int toon_up){
		for(int i = 0; i<lengte; i++){
			buzzerpin.set(0);
			hwlib::wait_us(toon_down);
			buzzerpin.set(1);
			hwlib::wait_us(toon_up);
			//scherm.updateA(0);
			//scherm.updateB(0);
			
		}
	}
	
	
	void play_alarm(int lengte, int toon_down ,int toon_up){
		for(int i = 0; i<lengte; i++){
			if(toggle){
				break;
			}
			buzzerpin.set(0);
			hwlib::wait_us(toon_down);
			buzzerpin.set(1);
			hwlib::wait_us(toon_up);
			if ( ! cancel.get()){
				toggle = 1;
			}
		}
	}
	
	void pokoe(){
		hwlib::wait_us(1);
		for(int i = 0; i <2; i++){
	
			play(500, 30,500);
			slow();
			play(400, 30,600);
			slow();
			play(200, 30,800);
			slow();
			play(300, 40,1000);
		//hwlib::wait_ms(1200);
			play(400, 30,300);
			slow();
			play(400, 40,400);
			slow();
			play(500, 50,500);
			slow();
			play(200, 80,800);
			slow();
			play(100, 60,600);
			slow();
			play(400, 50,500);
		}  
	}
	
	void alarm_pokoe(){
		hwlib::wait_us(1);
		
			play_alarm(500, 30,500);
			scherm.updateA(2);
			scherm.updateB(2);
			play_alarm(400, 30,600);
			scherm.updateA(2);
			scherm.updateB(2);
			play_alarm(200, 30,800);
			scherm.updateA(2);
			scherm.updateB(2);
			play_alarm(300, 40,1000);
			scherm.updateA(2);
			scherm.updateB(2);
			//hwlib::wait_ms(1200);
			play_alarm(400, 30,300);
			scherm.updateA(2);
			scherm.updateB(2);
			play_alarm(400, 40,400);
			scherm.updateA(2);
			scherm.updateB(2);
			play_alarm(500, 50,500);
			scherm.updateA(2);
			scherm.updateB(2);
			play_alarm(200, 80,800);
			scherm.updateA(2);
			scherm.updateB(2);
			play_alarm(100, 60,600);
			scherm.updateA(2);
			scherm.updateB(2);
			play_alarm(400, 50,500);
	}
	
	void play_pokoe(){
		toggle = 0;
		alarm_pokoe();
		
	}
	
	void slow(){
		scherm.updateA(2);
			scherm.updateB(2);
	}
	
};


  