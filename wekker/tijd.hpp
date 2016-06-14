///@file 
///klasse interface voor een rtc chip
//
///deze klasse bevat functies voor de interfacing naar een rtc chip
class tijdchip {
private:
	
	int uren;
	int minuten; //mogelijk verandereden in bytes
	int seconden;
	int week;
	int dag;
	int maand;
	int jaar;
	



	fast_byte  a = 0x68; //adres d1307 01101000
	byte data[7] = {0,0,0,0,0,0,0}; 
	byte  data_get[7];
	
	byte data_first[6] = {0,2,3,4,5,6};// not used
	

	hwlib::i2c_bus_bit_banged_scl_sda & i2c;  // i2c bus
	// benodigd heden 2c buss 
	display scherm;

	
public:
	///constructor
	//
	///creert een rtc object uit een display en een i2c bus
	tijdchip(hwlib::i2c_bus_bit_banged_scl_sda & i2c, display scherm):
			i2c( i2c),
			scherm( scherm )
		{}
		
		

		///decimal to binary coded decimal
		//
		///deze functie zet een bcd byte om naar een decimale byte
		byte dec_Bcd(byte waarde)
		{
			return( (waarde/10*16) + (waarde%10) );
		}
		///binary coded decimal to decimal
		//
		///deze functie zet een byte waarde om in een bcd
		byte bcd_Dec(byte waarde)
		{
			return( (waarde/16*10) + (waarde%16) );
		}
		
				
		///set time
		//
		///deze functie roept de invoer van het display aan om de minuten en uren in het rtc chip te schrijven
	
	void set_time(){ // 
			
		scherm.setdisplay();
		data[0] = 0;
		data[1] = 0; ;
		data[2] = dec_Bcd(scherm.get_minuten()) ;
		data[3] = dec_Bcd(scherm.get_uren());;
		data[4] = 0 ;
		data[5] = 0 ;
		data[6] = 0 ;
		i2c.write(a , data, 7);
	}
	
	///get tijd
	//
	///deze functie update de de variabelen met de verse waardes uit het rtc
	void get_tijd(){ // haal uren op uit rtc
		i2c.write(a,  data_first , 1);
		i2c.read(a, data_get, 4);
		seconden  = bcd_Dec(data_get[0]);
		minuten = bcd_Dec(data_get[1] & 0x7f);
		uren = bcd_Dec(data_get[2] & 0x3f);
//		week = bcdToDec(data_get[3]);
//		dag = bcdToDec(data_get[4]);
//		maand = bcdToDec(data_get[5]);
//		jaar = bcdToDec(data_get[6]);
		//hwlib::wait_ms( 1 );
//		hwlib::cout << "bcd " << seconden << "  seconden    "  << "byte   " << int(data_get[0]) << " NC " <<data[1] << "\n";
//		//hwlib::wait_ms( 1 );
//		hwlib::cout << "bcd " << minuten  << " minuten     "  << "byte   "  << int(data_get[1]) << " NC" <<data[2]  << "\n";
//		//hwlib::wait_ms( 1 );
//		hwlib::cout << "bcd " << uren  << "  uren    "  << "byte   "   << int(data_get[2]) << " NC  " <<data[3]  <<  "\n";
//		//hwlib::wait_ms( 1 );
//		hwlib::cout << "bcd " << week  << " week "   <<   "byte   " <<  int(data_get[3]) << " NC " <<data[4]  <<  "\n";
//		hwlib::wait_ms( 1 );
//		hwlib::cout << "bcd " << dag  << "   dag "    << "byte   "  <<  int(data_get[4]) << " NC " <<data[5]  <<  "\n";
//		hwlib::wait_ms( 1 );
//		hwlib::cout << "bcd " << maand  << "  maand  "   << "byte   "   <<  int(data_get[5]) << " NC " <<data[6]  <<  "\n";
		//hwlib::wait_ms( 1 );
		//hwlib::cout << "bcd " << jaar  << " jaar     "   << "byte   "   <<  int(data_get[6]) << "  NC " <<data[7]  <<  "\n";
		
		
		
		
		
	}
	///get uren
	//
	///retourneert uren 
	int get_uren(){
		return (bcd_Dec(data_get[2]));
	}
	///get minuten
	//
	///retourneert minuten
	int get_minuten(){
		 return (bcd_Dec(data_get[1]));
	}
	///rtc get a
	//
	///deze functie retourneert het getal voor segment a
	int rtc_get_a(){
		return (bcd_Dec(data_get[2]) / 10 ) % 10;
	}
	///rtc get b
	//
	///deze functie retourneert het getal voor segment b
	int rtc_get_b(){  
		return bcd_Dec(data_get[2])  % 10;
	}
	///rtc get c
	//
	///deze functie retourneert het getal voor segment c
	int rtc_get_c(){
		return (bcd_Dec(data_get[1]) / 10 ) % 10;
	}
	///rtc get d
	//
	///deze functie retourneert het getal voor segment d
	int rtc_get_d(){
		return bcd_Dec(data_get[1])  % 10;
	}

};