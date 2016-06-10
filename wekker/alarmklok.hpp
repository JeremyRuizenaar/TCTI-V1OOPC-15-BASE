#include "hwlib.hpp"
#include "display.hpp"
#include "timer.hpp"
#include "tijd.hpp"
#include "wekker.hpp"
#include "speaker.hpp"

class alarmklok{
	private:

//void update420(display jonko);
//void startup(hwlib::target::pin_out buzzer);
//int check_alarm(int & zetaan, tijdchip klok, timer & alarm0, timer & alarm1, timer & alarm2, timer & alarm3, hwlib::hc595 display1, hwlib::hc595 display2, hwlib::hc595 display3, hwlib::hc595 display4);
//void displaytest(hwlib::hc595 digit, display jonko);

public:
	void init_wekker(){
		//cd kill the watchdog
		WDT->WDT_MR = WDT_MR_WDDIS;
   
   
		namespace target = hwlib::target;
		
		
		auto scl   = due::pin_oc(target::pins::d8); 	
		auto sda   = due::pin_oc(target::pins::d9) ;
	
		
		auto i2c = hwlib::i2c_bus_bit_banged_scl_sda( scl, sda);
		
		auto ds   = target::pin_out( target::pins::d22 );
		auto shcp = target::pin_out( target::pins::d23 );
		auto stcp = target::pin_out( target::pins::d26 );
		auto spi  = hwlib::spi_bus_bit_banged_sclk_mosi_miso( 
		stcp, 
		ds, 
		hwlib::pin_in_dummy );
		auto display1 =  hwlib::hc595( spi, shcp );
	
		auto ds2   = target::pin_out( target::pins::d30 );
		auto shcp2 = target::pin_out( target::pins::d32 );
		auto stcp2 = target::pin_out( target::pins::d34 );
		auto spi2  = hwlib::spi_bus_bit_banged_sclk_mosi_miso( 
		stcp2, 
		ds2, 
		hwlib::pin_in_dummy );
		auto display2 =  hwlib::hc595( spi2, shcp2 );
		
		auto ds3   = target::pin_out( target::pins::d2 );
		auto shcp3 = target::pin_out( target::pins::d3 );
		auto stcp3 = target::pin_out( target::pins::d4 );
		auto spi3  = hwlib::spi_bus_bit_banged_sclk_mosi_miso( 
		stcp3, 
		ds3, 
		hwlib::pin_in_dummy );
		auto display3 =  hwlib::hc595( spi3, shcp3 );
		
		auto ds4   = target::pin_out( target::pins::d46 );
		auto shcp4 = target::pin_out( target::pins::d48 );
		auto stcp4 = target::pin_out( target::pins::d50 );
		auto spi4  = hwlib::spi_bus_bit_banged_sclk_mosi_miso( 
		stcp4, 
		ds4, 
		hwlib::pin_in_dummy );
		auto display4 =  hwlib::hc595( spi4, shcp4 );
		
		auto ds5   = target::pin_out( target::pins::d5);
		auto shcp5 = target::pin_out( target::pins::d6 );
		auto stcp5 = target::pin_out( target::pins::d7 );
		auto spi5  = hwlib::spi_bus_bit_banged_sclk_mosi_miso( 
		stcp5, 
		ds5, 
		hwlib::pin_in_dummy );
		auto display5 =  hwlib::hc595( spi5, shcp5 );
		
		auto ds6   = target::pin_out( target::pins::d47 );
		auto shcp6 = target::pin_out( target::pins::d49 );
		auto stcp6 = target::pin_out( target::pins::d51 );
		auto spi6  = hwlib::spi_bus_bit_banged_sclk_mosi_miso( 
		stcp6, 
		ds6, 
		hwlib::pin_in_dummy );
		auto display6 =  hwlib::hc595( spi6, shcp6 );
		
		
		
		auto plus = hwlib::target::pin_in_out( target::pins::d14 );
		auto min = hwlib::target::pin_in_out( target::pins::d15 );
		auto enter = hwlib::target::pin_in_out( target::pins::d16 );
		auto cancel = hwlib::target::pin_in_out( target::pins::d17 );
		auto printwekker = hwlib::target::pin_in_out( target::pins::d18 );
		auto stelwekker = hwlib::target::pin_in_out( target::pins::d19 );
		auto stelklok = hwlib::target::pin_in_out( target::pins::d20 );
		plus.direction_set_input();
		min.direction_set_input();
		enter.direction_set_input();
		cancel.direction_set_input();
		printwekker.direction_set_input();
		stelwekker.direction_set_input();
		stelklok.direction_set_input();
   
		//auto buzzer = hwlib::target::pin_out( target::pins::d10 );
		auto buzzerbox = hwlib::target::pin_out( target::pins::d12); 
		//auto buzzer = hwlib::dac(target::pins::d3);
		
   
   
		display scherm = display( display1, display2, display3, display4, display5, display6, plus , min, enter, cancel); // constructer aanpassen voor 5 display objecten
   
		timer alarm0 = timer(scherm, printwekker);
		timer alarm1 = timer(scherm, printwekker);
		timer alarm2 = timer(scherm, printwekker);
		timer alarm3 = timer(scherm, printwekker);
		wekker klokken = wekker(); 
		tijdchip klok = tijdchip(i2c,scherm);
		speaker box = speaker(klok, buzzerbox, scherm, cancel);

		start_wekker(display1, display2, display3, display4,scherm,alarm0,alarm1,alarm2,alarm3,klokken,klok,box,plus,min,enter,cancel,printwekker,stelwekker,stelklok);
	}

   /*geehele wekker test functie
    * 
	* wekker check wekker() deze functie checkt of er tussen alle wekkers die active zijn er 1 is dei gelijk is aan de tijd
    * de functie returned een 1 als er iets gevonden. deze 1 bepaalt of de alarm_play word aangeroepen.
	* een maal in de eplay sound functie als de cancel knp wordt in gedrukt moet ern een wekker functie zet uit zijn die het huidige timer object uitzet dit door een zet uit functie uit te roepen op de huidig geselecteerdde wekker
	* de huidig geselecteerde wekker moet altijd gelijk zijn aan de wekker die geluid maakt. dit is de toen door de functie die checkt of er een wekker aan staat de huidige wekker stant te forceren naar zijn nummer
	* 
	*/
	void start_wekker( hwlib::hc595 display1,  hwlib::hc595 display2,  hwlib::hc595 display3,  hwlib::hc595 display4,
	display & scherm, timer & alarm0,timer & alarm1,timer alarm2,timer alarm3, wekker klokken, tijdchip klok, speaker box, 
	 hwlib::target::pin_in_out plus, hwlib::target::pin_in_out min, hwlib::target::pin_in_out enter, hwlib::target::pin_in_out cancel, 
	 hwlib::target::pin_in_out printwekker, hwlib::target::pin_in_out stelwekker, hwlib::target::pin_in_out stelklok ){
		 
	
		
		while(1){
			scherm.updateA(11);
			scherm.updateB(11);
			scherm.updateC(11);
			scherm.updateD(11);
			scherm.updateE(11);
			scherm.updateMin(11);
			if( ! cancel.get()){
				break;
			}
 
		box.sound();
		update420(scherm);
		int zetaan =0;
		//startup(buzzer);

		while(1){
	   
			klok.get_tijd();
			if(check_alarm(zetaan, klok,alarm0,alarm1,alarm2,alarm3,display1,display2,display3,display4  )){
				//buzzer.set(1);
				zetaan = box.alarm_sound();
				hwlib::cout << "buzzer is aangezet  " << zetaan << "\n" ;
			}
	
	   
			if( klok.get_uren() == 16 &&  klok.get_minuten() == 20){
				while(klok.get_minuten() == 20){
					update420(scherm);
					klok.get_tijd();
		   
				}
			}
	 
			scherm.updateA(klok.rtc_get_a());
			scherm.updateB(klok.rtc_get_b());
			scherm.updateC(klok.rtc_get_c());
			scherm.updateD(klok.rtc_get_d());
			scherm.updateE(klokken.get_select());
			scherm.updateMin();

	   // updatswe a b c d e d in loop check +- in standaard loop voor wekker select andere +- min functies zijn specief aangeroepenin anderen objeceten
			if(!stelwekker.get()){
				hwlib::wait_ms(50);
				if (klokken.get_select() == 0){
					alarm0.set_timer();		   
				}
				else if (klokken.get_select() == 1){
					alarm1.set_timer();		   
				}
				else if (klokken.get_select() == 2){
					alarm2.set_timer();		   
				}
				else if (klokken.get_select() == 3){
					alarm3.set_timer();		   
				}
			}
			else if(! plus.get()){
				klokken.wekkerup();
				hwlib::wait_ms(200);
			}
			else if(! min.get()){
				klokken.wekkerdown();
				hwlib::wait_ms(200);
			}
			else if (! printwekker.get()){
				hwlib::wait_ms(200);
				if (klokken.get_select() == 0){
						alarm0.print_timer();		   
				}
				else if (klokken.get_select() == 1){
					alarm1.print_timer();	   
				}
				else if (klokken.get_select() == 2){
					alarm2.print_timer();	   
				}
				else if (klokken.get_select() == 3){
					alarm3.print_timer();	   
				}
	   
			}
			else if( ! enter.get()){
				hwlib::wait_ms(200);
				if (klokken.get_select() == 0){
					if(alarm0.timer_active()){
						alarm0.set_timer_uit();	
					}
					else{
						alarm0.set_timer_aan();
					}
				}
				else if (klokken.get_select() == 1){
					if(alarm1.timer_active()){
						alarm1.set_timer_uit();	
					}
					else{
						alarm1.set_timer_aan();
					}	   
			}
				else if (klokken.get_select() == 2){
					if(alarm2.timer_active()){
						alarm2.set_timer_uit();	
					}
					else{
						alarm2.set_timer_aan();
					}		   
				}
				else if (klokken.get_select() == 3){
					if(alarm3.timer_active()){
						alarm3.set_timer_uit();	
					}
					else{
						alarm3.set_timer_aan();
					}		   
				}
			}
			else if (! cancel.get() && zetaan){
				//box.buzz_on();
				//box.box_hold();
				zetaan = 0;
				//buzzer.set(0);
				hwlib::cout << "buzzer en zetaan uitgezet \n";
				hwlib::wait_ms(600);
			}
			else if (! cancel.get()){
				//box.buzz_on();
				//box.box_hold();
				box.sound();
				//buzzer.set(1);
				//hwlib::cout << "cancel test zonder toggle  \n";
				//hwlib::wait_ms(10);
			}
			else if(! stelklok.get()){
				klok.set_time();
				hwlib::wait_ms(100);
			}
		}
    
	}
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

  
void displaytest(hwlib::hc595 digit, display scherm){
	  int time = 51;
	  scherm.eraseALL();
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
	
void update420(display scherm){
		int time = 200;
		scherm.updateA(4);
		scherm.updateB(2);
		scherm.updateMin(0);
		hwlib::wait_ms(time);
		scherm.updateE(4);
		scherm.updateA(2);
		scherm.updateB(0);
		hwlib::wait_ms(time);		

		scherm.updateD(4);
		scherm.updateE(2);
		scherm.updateA(0);
		hwlib::wait_ms(time);
		scherm.updateC(4);
		scherm.updateD(2);
		scherm.updateE(0);
		hwlib::wait_ms(time);
		scherm.updateMin(4);
		scherm.updateC(2);
		scherm.updateD(0);
		hwlib::wait_ms(time);
		scherm.updateB(4);
		scherm.updateMin(2);
		scherm.updateC(0);
		hwlib::wait_ms(time);
	}

};