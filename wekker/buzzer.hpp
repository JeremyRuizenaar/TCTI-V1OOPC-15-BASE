#include "hwlib.hpp"
class buzzer {
private:
	
	hwlib::target::pin_out buzzerpin;
	
public:
	buzzer(hwlib::target::pin_out & buzzpin):
	buzzerpin (buzzpin)
	{}
	
	
	void play(int lengte, int toon_down ,int toon_up){
		for(int i = 0; i<lengte; i++){
			buzzerpin.set(0);
			hwlib::wait_us(toon_down);
			buzzerpin.set(1);
			hwlib::wait_us(toon_up);

			
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
		
};


  