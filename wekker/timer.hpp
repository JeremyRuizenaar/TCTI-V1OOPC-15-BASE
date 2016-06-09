//#import "display.hpp"

class timer{
private:
	int uren;
	int minuten;
	
	int prevuren;
	int prevminuten;

	int a;
	int b;
	int c;
	int d;
	
	display scherm;
	hwlib::target::pin_in_out printwekker;
	int active = 0;
	
public:
	timer(display  & scherm, hwlib::target::pin_in_out & Printwekker):
	uren(0),
	minuten(0),
	scherm( scherm),
	printwekker(Printwekker)

	{}
	
	int timer_active(){
		return active;
	}
	
	void set_timer_aan(){
		active = 1;
	}
	
	void set_timer_uit(){
		active = 0;
	}
	
	int get_uren(){
		return uren;
	}
	
	int get_minuten(){
		return minuten;
	}
	

	void print_timer(){
		while(1){
			scherm.updateA(get_timer_a());
			scherm.updateB(get_timer_b());
			scherm.updateC(get_timer_c());
			scherm.updateD(get_timer_d());
			scherm.updateMin();
			if(! printwekker.get()){
				hwlib::wait_ms(500);
				scherm.eraseALL();
				break;
			}
		}
		
	}
	void set_timer(){
		
		prevuren = uren;
		prevminuten = minuten;
		
		scherm.setdisplay();
		
		if(scherm.get_cancelstate()){
			uren = prevuren;
			minuten = prevminuten;
		}
		else{
			uren = scherm.get_uren();
			minuten = scherm.get_minuten();
		}
	}
	
	int get_timer_a(){
		return (uren / 10 ) %10;
	}
	
	int get_timer_b(){
		return uren % 10;
	}
	
	int get_timer_c(){
		return (minuten / 10 ) %10;
	}
	
	int get_timer_d(){
		return minuten % 10;
	}
};

