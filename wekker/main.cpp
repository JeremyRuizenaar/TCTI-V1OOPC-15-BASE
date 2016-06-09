//#include "hwlib.hpp"
//#include "display.hpp"
//#include "timer.hpp"
//#include "tijd.hpp"
//#include "wekker.hpp"
//#include "speaker.hpp"

#include "alarmklok.hpp"

int main( void ){
	alarmklok apparaat = alarmklok();
	apparaat.init_wekker();
	return 0;
}

void startup(hwlib::target::pin_out buzzer){
	int a= 0;
	for(int i = 0; i < 5; i++){
		hwlib::wait_ms(500);
		if(a){
		buzzer.set(0);
		a=0;
		}
		else{
		buzzer.set(1);
		a=1;
		
		}
	}
	buzzer.set(0);
}
 
void displaytest(hwlib::hc595 digit, display jonko){
	  int time = 51;
	  jonko.eraseALL();
	  digit.p0.set(1);
	  hwlib::wait_ms(time);
	  digit.p0.set(0);
	  hwlib::wait_ms(time);
	  digit.p1.set(1);
	  hwlib::wait_ms(time);
	  digit.p1.set(0);
	  hwlib::wait_ms(time);
	  digit.p2.set(1);
	  hwlib::wait_ms(time);
	  digit.p2.set(0);
	  hwlib::wait_ms(time);
	  digit.p3.set(1);
	  hwlib::wait_ms(time);
	  digit.p3.set(0);
	  hwlib::wait_ms(time);
	  digit.p4.set(1);
	  hwlib::wait_ms(time);
	  digit.p4.set(0);
	  hwlib::wait_ms(time);
	  digit.p5.set(1);
	  hwlib::wait_ms(time);
	  digit.p5.set(0);
	  hwlib::wait_ms(time);
	  digit.p6.set(1);
	  hwlib::wait_ms(time);
	  digit.p6.set(0);
	  hwlib::wait_ms(time);
	  digit.p7.set(1);
	  hwlib::wait_ms(time);
	  digit.p7.set(0);
	  hwlib::wait_ms(time);


  }
   
int check_alarm(int & zetaan,tijdchip klok, timer & alarm0, timer  &alarm1, timer  & alarm2, timer & alarm3, hwlib::hc595 display1, hwlib::hc595 display2, hwlib::hc595 display3, hwlib::hc595 display4){
	   if(alarm0.timer_active()){
		   display1.p7.set(1);
		  if(alarm0.get_minuten() == klok.get_minuten() && alarm0.get_uren() == klok.get_uren()){
			  //buzzer.set(1);
			  zetaan = 1;
			   hwlib::cout << "alarm0 is aangezet before zet uit  " << alarm0.timer_active() << "\n" ;
			  alarm0.set_timer_uit();
			  hwlib::cout << "alarm0 is aangezet na zet uit " << alarm0.timer_active() << "\n" ;
			  //hwlib::cout << "timer 0 is actief " << alarm0.get_minuten() << " " << klok.get_minuten() << " " << alarm0.get_uren() << " " << klok.get_uren() << "\n";
		  }
	   }
		if(alarm1.timer_active()){
		   display2.p7.set(1);
		   if(alarm1.get_minuten() == klok.get_minuten() && alarm1.get_uren() == klok.get_uren()){
			  //buzzer.set(1);
			  zetaan = 1;
			  alarm1.set_timer_uit();
			//hwlib::cout << "timer 1 is actief " << alarm1.get_minuten() << " " << klok.get_minuten() << " " << alarm1.get_uren() << " " << klok.get_uren() << "\n";

		  }
	   }
		if(alarm2.timer_active()){
		   display3.p7.set(1);
		   if(alarm2.get_minuten() == klok.get_minuten() && alarm2.get_uren() == klok.get_uren()){
			  //buzzer.set(1);
			  zetaan = 1;
			  alarm2.set_timer_uit();
			 // hwlib::cout << "timer 2 is actief " << alarm2.get_minuten() << " " << klok.get_minuten() << " " << alarm2.get_uren() << " " << klok.get_uren() << "\n";
		  }
	   }	 
	  if(alarm3.timer_active()){
		 display4.p7.set(1);
		   if(alarm3.get_minuten() == klok.get_minuten() && alarm3.get_uren() == klok.get_uren()){
			  //buzzer.set(1);
			  zetaan = 1;
			  alarm3.set_timer_uit();
			 // hwlib::cout << "timer 3 is actief " << alarm3.get_minuten() << " " << klok.get_minuten() << " " << alarm3.get_uren() << " " << klok.get_uren() << "\n";
		  }
	   }
	   return zetaan;
	}	
	
