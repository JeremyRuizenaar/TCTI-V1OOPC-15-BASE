
///@file 
//#import "display.hpp"
///klasse voor een timer adt
//
///deze klasse bevat functies om een timer in te stellen
// een timer te weergeven op een display

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
	///constructor
	//
	///creert een timer object
	timer(display  & scherm, hwlib::target::pin_in_out & Printwekker):
	uren(0),
	minuten(0),
	scherm( scherm),
	printwekker(Printwekker)

	{}
	///timer actif
	//
	///deze functie retourneert de status van de timer 0 voor uit 1 voor aan
	int timer_active(){
		return active;
	}
	///set timer aan
	//
	///deze functie zet de timer op actief
	void set_timer_aan(){
		active = 1;
	}
	///set timer uit
	//
	///deze functie zet de timer uit
	void set_timer_uit(){
		active = 0;
	}
	///get uren
	//
	///return uren
	int get_uren(){
		return uren;
	}
	///get minuten
	//
	///return minuten
	int get_minuten(){
		return minuten;
	}
	
	///print timer
	//
	///deze functie print de tijd van de timer op het display
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
	///set timer
	//
	///deze functie roept de functie aan om waardes in het display in te voern
	/// deze waardes worden vast gezet als de uren en minuten waarop de timer geactiveerd zal worden
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
	///get timer segment a
	//
	///return timer segment a
	int get_timer_a(){
		return (uren / 10 ) %10;
	}
	///get timer segment b
	//
	///return timer segment b
	int get_timer_b(){
		return uren % 10;
	}
	///get timer segment c
	//
	///return timer segment c
	int get_timer_c(){
		return (minuten / 10 ) %10;
	}
	///get timer segment d
	//
	///return timer segment d
	int get_timer_d(){
		return minuten % 10;
	}
};

