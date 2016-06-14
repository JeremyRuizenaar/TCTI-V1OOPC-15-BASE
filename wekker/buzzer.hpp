///@file 
#include "hwlib.hpp"
/// library  interface voor een buzzer object
//
///deze klasse heeft de functies om toontjes achter elkaar te plaatsen en deze af te spelen

class buzzer {
private:
	
	hwlib::target::pin_out buzzerpin;
	
public:
	///default constructor
	//
	///creert een buzzer object uit een pin
	buzzer(hwlib::target::pin_out & buzzpin):
	buzzerpin (buzzpin)
	{}
	///play
	//
	///deze functie neemt 3 paramters
	///lengte van de toon
	///toon_down downtime van de pin
	///toon_up uptime van de pin
	///deze functie implementeert het idee van PWM om een sound via een buzzer af te spelen
	
	void play(int lengte, int toon_down ,int toon_up){
		for(int i = 0; i<lengte; i++){
			buzzerpin.set(0);
			hwlib::wait_us(toon_down);
			buzzerpin.set(1);
			hwlib::wait_us(toon_up);

			
		}
	}
	
	
	///sound
	//
	///deze functie speelt een deuntje af
	
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
		
};


  