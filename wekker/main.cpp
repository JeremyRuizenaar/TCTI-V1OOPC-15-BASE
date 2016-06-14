#include "hwlib.hpp"
//#include "display.hpp"
//#include "timer.hpp"
//#include "tijd.hpp"
//#include "wekker.hpp"
//#include "speaker.hpp"
#include "analogklok.hpp"
#include "alarmklok.hpp"
#include "sevensegment.hpp"
#include "i2cRTC.hpp"
//#include "analogklok.hpp"
//#include "catch_with_main.hpp"
#include "assert.h"

int main( void ){
		//cd kill the watchdog
		WDT->WDT_MR = WDT_MR_WDDIS;
 
		//pinnen en objecten worden aangemaakt voor de demo 
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
		
		auto ds5   = target::pin_out( target::pins::d5); //5
		auto shcp5 = target::pin_out( target::pins::d6 ); //6
		auto stcp5 = target::pin_out( target::pins::d7 );  //7
		auto spi5  = hwlib::spi_bus_bit_banged_sclk_mosi_miso( 
		stcp5, 
		ds5, 
		hwlib::pin_in_dummy );
		auto display5 =  hwlib::hc595( spi5, shcp5 );
		
		auto ds6   = target::pin_out( target::pins::d47 ); // 47 49 51
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
		plus.direction_set_input();
		min.direction_set_input();
		enter.direction_set_input();
	
i2cRTClib chip = i2cRTClib(i2c,2,4,2,7,5,12,16);
		//assertsadwdeddkdew
/*
assert( chip.get_minuten() == 4 );   
assert( chip.get_uren() == 6 );    
assert( chip.get_dag_week()== 7 );    
assert( chip.get_dag_maand() == 5 );     
assert( chip.get_maand() == 12 );    
assert( chip.get_jaar() == 15 );     
chip.set_adres_x(10, 20);
assert( chip.get_adres_x(10)== 20);    
chip.set_adres_x(11, 20);
assert( chip.get_adres_x(12) == 20);   
chip.set_adres_x(12, 20);
assert( chip.get_adres_x(12) == 20);    
chip.set_minuten(22);
assert( chip.get_minuten() == 22);    
chip.set_uren(21);
assert( chip.get_uren() == 21);    
chip.set_dag_week(5);
assert( chip.get_dag_week() == 5);    
chip.set_dag_maand(30);
assert( chip.get_dag_maand() == 30);    
chip.set_maand(8);
assert( chip.get_maand()== 8);    
chip.set_jaar(99);
assert( chip.get_jaar()== 99);    

*/
	


	
		sevensegmentlib scherm = sevensegmentlib( display1, display2, display3, display4, display5, display6, plus , min, enter); 
		
			int data[26] = {26,24,28,28,0,-1,26,20,28,28,0,-1,27,24,30,-1,23,20,9,-1,23,20,23,24,28,-1};
			while(1){scherm.update(data,26,150);if(! enter.get()){hwlib::wait_ms(1000);break;}}
			
			for(int i = 0; i<1000000; i++){
				scherm.update(i);
				hwlib::wait_ms(2);
				if(! enter.get()){
					hwlib::wait_ms(500);
					break;
				}
			}
			
			//asdsschssdddsotsshsdsdk
			
			scherm.setdisplay(0);
			scherm.setdisplay(1);
			
			//i2cRTClib chip = i2cRTClib(i2c,44,3,18,5,16);
			while(1){
				if(! enter.get()){break;}
				for(int i =0; i<1; i++){
				hwlib::cout << "sec " << chip.get_seconden() << " min " << chip.get_minuten() << " uur " << chip.get_uren() <<
				" weekd " << chip.get_dag_week() << " dag " <<chip.get_dag_maand() << " maand "  << chip.get_maand()<< 
				" jaar "<< chip.get_jaar() <<	" \n";
				hwlib::wait_ms(1000);
				chip.set_adres_x(12,90);
				chip.set_adres_x(10,79);
				chip.set_adres_x(12,240);
				hwlib::cout << chip.get_adres_x(12) << "<-- 12 10 -->"  << chip.get_adres_x(10) << "\n";
			
				chip.set_time(10,10,10,5,5,5,5);
				hwlib::cout << "sec " << chip.get_seconden() << " min " << chip.get_minuten() << " uur " << chip.get_uren() <<
				" weekd " << chip.get_dag_week() << " dag " <<chip.get_dag_maand() << " maand "  << chip.get_maand()<< 
				" jaar "<< chip.get_jaar() <<	" \n";
				
				//chip.get_tijd();
				chip.set_maand(12);
				chip.set_dag_week(1);
				chip.set_dag_maand(17);
				chip.set_minuten(1);
				chip.set_uren(22);
				
				hwlib::cout << "sec " << chip.get_seconden() << " min " << chip.get_minuten() << " uur " << chip.get_uren() <<
				" weekd " << chip.get_dag_week() << " dag " <<chip.get_dag_maand() << " maand "  << chip.get_maand()<< 
				" jaar "<< chip.get_jaar() <<	" \n";
				}
			}
			
			analoogklok leds = analoogklok(wijs, wijs2);
				for(int d =0; d <1; d++)			
					for(int y =0; y <24; y++){
						leds.blinkwijzer_uren(y);
						hwlib::wait_ms(500);
					}
					
					hwlib::cout<< "next";
	
			
					
			while(1){
				
					leds.updateWijzer(chip.get_uren(), chip.get_minuten());
					//leds.blink(chip.get_minuten());
					scherm.update(3,(chip.get_minuten() / 10 ) % 10);
					scherm.update(4,chip.get_minuten() % 10);
					scherm.update(0,(chip.get_uren() / 10 ) % 10);
					scherm.update(1,chip.get_uren()% 10);
						//hwlib::cout<< chip.get_minuten()<< " < min uur > " << chip.get_uren()  << " display 4 ---> " << (chip.get_minuten() % 10) << "\n";
					if(! plus.get()){
						if(chip.get_minuten()+1 == 60){
							chip.set_minuten(0);
							hwlib::wait_ms(100);
							chip.set_uren(chip.get_uren() +1);
							
						}
						else{
							chip.set_minuten(chip.get_minuten()+1);
						}
					}
					if(! min.get()){
						chip.set_uren(chip.get_uren()+1);
						hwlib::wait_ms(100);
					}
					if( ! enter.get()){
						hwlib::wait_ms(300);
						break;
					}
					
				
			}
			//jsddspgd
			
			alarmklok mijnwekker = alarmklok();
			mijnwekker.init_wekker();
				 
				
				
	return 0;
}




		
		
		