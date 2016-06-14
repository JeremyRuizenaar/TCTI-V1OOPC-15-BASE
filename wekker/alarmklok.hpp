///@file 
///klasse alarmklok
//
///deze klasse  bevat functies voor initializiate van alle pinnen en objecten 
///deze initialisatie start vervolgens de main-eventloop van de alarmklok op
#include "hwlib.hpp"
#include "display.hpp"
#include "timer.hpp"
#include "tijd.hpp"
#include "wekker.hpp"
#include "speaker.hpp"
//#include "analogklok.hpp"
//a
class alarmklok{
	private:

int check_alarm(int & zetaan,tijdchip klok, timer & alarm0, timer  &alarm1, timer  & alarm2, timer & alarm3, hwlib::hc595 display1, hwlib::hc595 display2, hwlib::hc595 display3, hwlib::hc595 display4){
	   if(alarm0.timer_active()){
		   display1.p7.set(1);
		  if(alarm0.get_minuten() == klok.get_minuten() && alarm0.get_uren() == klok.get_uren()){
			  //buzzer.set(1);
			  zetaan = 1;
			   //[hwlib::cout << "alarm0 is aangezet before zet uit  " << alarm0.timer_active() << "\n" ;
			  alarm0.set_timer_uit();
			  //hwlib::cout << "alarm0 is aangezet na zet uit " << alarm0.timer_active() << "\n" ;
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

	
	void start_wekker( hwlib::hc595 display1,  hwlib::hc595 display2,  hwlib::hc595 display3,  hwlib::hc595 display4,
			display & scherm, timer & alarm0,timer & alarm1,timer alarm2,timer alarm3, wekker klokken, tijdchip klok, speaker box, 
			hwlib::target::pin_in_out plus, hwlib::target::pin_in_out min, hwlib::target::pin_in_out enter, hwlib::target::pin_in_out cancel, 
			hwlib::target::pin_in_out printwekker, hwlib::target::pin_in_out stelwekker, hwlib::target::pin_in_out stelklok, analoogklok leds){
			
	
		
	//leds.blink(4);
		box.sound();
		int zetaan =0;

		while(1){
	   
			klok.get_tijd();
			if(check_alarm(zetaan, klok,alarm0,alarm1,alarm2,alarm3,display1,display2,display3,display4  )){
				//buzzer.set(1);
				zetaan = box.alarm_sound();
				//hwlib::cout << "buzzer is aangezet  " << zetaan << "\n " ;
			}
	//a

			scherm.updateA(klok.rtc_get_a());
			scherm.updateB(klok.rtc_get_b());
			scherm.updateC(klok.rtc_get_c());
			scherm.updateD(klok.rtc_get_d());
			scherm.updateE(klokken.get_select());
			scherm.updateMin();
			//leds.eraseWijzer();
			leds.blink(4);

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
				zetaan = 0;
				//buzzer.set(0);
				//hwlib::cout << "buzzer en zetaan uitgezet \n";
				hwlib::wait_ms(600);
			}
			else if (! cancel.get()){
				box.sound();
			}
			else if(! stelklok.get()){
				klok.set_time();
				hwlib::wait_ms(100);
			}
		}
	}


public:
		///constructor
		//
		///creert alarmklok objecte

		
		///init wekker
		//
		///deze functie stelt alle pinnen in en maakt alle objecten gereed
		///en geeft al deze objecten door naar de main-eventloop
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
		
		auto ds7   = target::pin_out( target::pins::a0 );   //29 33 35
		auto shcp7 = target::pin_out( target::pins::a1);
		auto stcp7 = target::pin_out( target::pins::a2 );
		auto spi7  = hwlib::spi_bus_bit_banged_sclk_mosi_miso( 
		stcp7, 
		ds7, 
		hwlib::pin_in_dummy );
		auto wijs =  hwlib::hc595( spi7, shcp7 );
		
		auto ds8   = target::pin_out( target::pins::a3 );   //39 41 43
		auto shcp8 = target::pin_out( target::pins::a4);
		auto stcp8 = target::pin_out( target::pins::a5 );
		auto spi8  = hwlib::spi_bus_bit_banged_sclk_mosi_miso( 
		stcp8, 
		ds8, 
		hwlib::pin_in_dummy );
		auto wijs2 =  hwlib::hc595( spi8, shcp8 );
		
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
		//auto buzzer = hwlib::dac(target::pins::d3);x
		
   
   
		display scherm = display( display1, display2, display3, display4, display5, display6, plus , min, enter, cancel); // constructer aanpassen voor 5 display objecten
   
		timer alarm0 = timer(scherm, printwekker);
		timer alarm1 = timer(scherm, printwekker);
		timer alarm2 = timer(scherm, printwekker);
		timer alarm3 = timer(scherm, printwekker);
		wekker klokken = wekker(); 
		tijdchip klok = tijdchip(i2c,scherm);
		speaker box = speaker(klok, buzzerbox, scherm, cancel);
		analoogklok leds = analoogklok(wijs,wijs2);
		start_wekker(display1, display2, display3, display4,scherm,alarm0,alarm1,alarm2,alarm3,klokken,klok,box,plus,min,enter,cancel,printwekker,stelwekker,stelklok,leds);
	}



};