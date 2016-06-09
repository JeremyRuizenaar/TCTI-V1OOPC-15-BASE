
class speaker {
private:
	tijdchip klok;
	hwlib::target::pin_out buzzerpin;
	display scherm;
	hwlib::target::pin_in_out cancel;
	int toggle =0;
	
public:
	speaker(tijdchip klok, hwlib::target::pin_out & buzzer, display scherm, hwlib::target::pin_in_out cancel):
	klok ( klok ),
	buzzerpin (buzzer),
	scherm (scherm),
	cancel ( cancel )
	
	{}
	
	
		
		
		
	

	
	void play(int lengte, int toon_down ,int toon_up){
		for(int i = 0; i<lengte; i++){
			buzzerpin.set(0);
			hwlib::wait_us(toon_down);
			buzzerpin.set(1);
			hwlib::wait_us(toon_up);

			
		}
	}
	
	
	void play_alarm(int lengte, int toon_down ,int toon_up){
		for(int i = 0; i<lengte; i++){
			if(!toggle){
				break;
			}
			buzzerpin.set(0);
			hwlib::wait_us(toon_down);
			buzzerpin.set(1);
			hwlib::wait_us(toon_up);
			if ( ! cancel.get()){
				toggle = 0;
			}
		}
	}
	
	void sound(){
		hwlib::wait_us(1);
		for(int i = 0; i <2; i++){
	
			play(500, 30,500);
			slow();
			play(400, 30,600);
			slow();
			play(200, 30,800);
			slow();
			play(300, 40,1000);
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
	
	int alarm_sound(){
			hwlib::wait_us(1);
			toggle = 1;
			play_alarm(500, 30,500);
			slow();
			play_alarm(400, 30,600);
			slow();
			play_alarm(200, 30,800);
			slow();
			play_alarm(300, 40,1000);
			slow();
			play_alarm(400, 30,300);
			slow();
			play_alarm(400, 40,400);
			slow();
			play_alarm(500, 50,500);
			slow();
			play_alarm(200, 80,800);
			slow();
			play_alarm(100, 60,600);
			slow();
			play_alarm(400, 50,500);
			return toggle;
	}
	
	void play_sound(){
		toggle = 0;
		alarm_sound();
		
	}
	
	void slow(){
			klok.get_tijd();
			scherm.updateA(klok.rtc_get_a());
			scherm.updateB(klok.rtc_get_b());
			scherm.updateC(klok.rtc_get_c());
			scherm.updateD(klok.rtc_get_d());
			scherm.updateE(10);
			scherm.updateMin();
			//hwlib::cout << "slow aangeropen\nA  " << klok.rtc_get_a() << "\nB  "<< klok.rtc_get_b() << "\nC  " << klok.rtc_get_c() << "\nD  " << klok.rtc_get_d() << "\n" ;
	}
	
};


  