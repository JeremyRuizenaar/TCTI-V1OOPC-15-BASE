#include "hwlib.hpp"
//#include "display.hpp"
//#include "timer.hpp"
//#include "tijd.hpp"
//#include "wekker.hpp"
//#include "speaker.hpp"

#include "alarmklok.hpp"
#include "sevensegment.hpp"
#include "i2cRTC.hpp"
int main( void ){
	//alarmklok apparaat = alarmklok();
	//apparaat.init_wekker();
	//init_wekker();
	
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
		plus.direction_set_input();
		min.direction_set_input();
		enter.direction_set_input();
	
	
	


	
		sevensegment scherm = sevensegment( display1, display2, display3, display4, display5, display6, plus , min, enter); 
		
			int data[26] = {26,24,28,28,0,-1,26,20,28,28,0,-1,27,24,30,-1,23,20,9,-1,23,20,23,24,28,-1};
			while(1){scherm.update(data,26,150);if(! enter.get()){hwlib::wait_ms(300);break;}}
			
			for(int i = 0; i<1000000; i++){
				scherm.update(i);
				hwlib::wait_ms(2);
				if(! enter.get()){
					hwlib::wait_ms(500);
					break;
				}
			}
			
			
			
			scherm.setdisplay(0);
			scherm.setdisplay(1);
			
			i2cRTC chip = i2cRTC(i2c,44,3,18,5,16);
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
				
				chip.get_tijd();
				chip.set_maand(12);
				chip.set_dag_week(1);
				chip.set_dag_maand(17);
				chip.set_minuten(55);
				chip.set_uren(22);
				
				hwlib::cout << "sec " << chip.get_seconden() << " min " << chip.get_minuten() << " uur " << chip.get_uren() <<
				" weekd " << chip.get_dag_week() << " dag " <<chip.get_dag_maand() << " maand "  << chip.get_maand()<< 
				" jaar "<< chip.get_jaar() <<	" \n";
				}
			}

			alarmklok mijnwekker = alarmklok();
			mijnwekker.init_wekker();

	return 0;
}


   
		
	//sssewwscs4ssewsssswedsssdSSdgGEwwsfewdcd,dssssssrdwssd