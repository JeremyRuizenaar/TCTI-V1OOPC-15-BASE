class tijdchip {
private:
	
	int uren;
	int minuten; //mogelijk verandereden in bytes
	int seconden;
	int week;
	int dag;
	int maand;
	int jaar;
	
	
	byte bUren = decToBcd(21);
	byte bMinuten = decToBcd(17);
	byte bSeconden = decToBcd(18);


	fast_byte  a = 0x68; //adres d1307 01101000
	byte data[7] = {decToBcd(8),bSeconden,bMinuten,bUren,decToBcd(4),decToBcd(3),decToBcd(2)}; //test  date
	byte  data_get[7];
	
	byte data_first[6] = {0,2,3,4,5,6};// not used
	
	fast_byte n; // number of bytes
	fast_byte o = 0x00;
	
	hwlib::i2c_bus_bit_banged_scl_sda & i2c;  // i2c bus
	// benodigd heden 2c buss 
	display scherm;

	
public:
	tijdchip(hwlib::i2c_bus_bit_banged_scl_sda & i2c, display scherm):
			i2c( i2c),
			scherm( scherm )
		{}
		

		
		byte decToBcd(byte val)
		{
			return( (val/10*16) + (val%10) );
		}
// Convert binary coded decimal to normal decimal numbers mogelijk vernanderen return type int
		byte bcdToDec(byte val)
		{
			return( (val/16*10) + (val%16) );
		}
	
	void set_time(){ // 
		//voer uren en minuten in op display  haaal deze waardes op en stuur ze naar rtc
		//i2c.write(a , data_first, 1);
		
		scherm.setdisplay();
		data[0] = 0;
		data[1] = 0; ;
		data[2] = decToBcd(scherm.get_minuten()) ;
		data[3] = decToBcd(scherm.get_uren());;
		data[4] = 0 ;
		data[5] = 0 ;
		data[6] = 0 ;
		i2c.write(a , data, 7);
	}
	
	void get_tijd(){ // haal uren op uit rtc
		i2c.write(a,  data_first , 1);
		i2c.read(a, data_get, 4);
		seconden  = bcdToDec(data_get[0]);
		minuten = bcdToDec(data_get[1] & 0x7f);
		uren = bcdToDec(data_get[2] & 0x3f);
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
	
	int get_minuten(){  // haal minuten op uit rtc
		return minuten;
	}
	
	int get_uren(){  // haal seconden op uit rtc
		return uren;
	}
	
	void get_date(){  // haal datum op uit rtc
		
	}
	
	int rtc_get_a(){
		return (bcdToDec(data_get[2]) / 10 ) % 10;
	}
	
	int rtc_get_b(){  
		return bcdToDec(data_get[2])  % 10;
	}
	
	int rtc_get_c(){
		return (bcdToDec(data_get[1]) / 10 ) % 10;
	}
	
	int rtc_get_d(){
		return bcdToDec(data_get[1])  % 10;
	}
	
		int rtc_get_a_sec(){
		return ( seconden /10) % 10;
	}
	
	int rtc_get_b_sec(){  
		return seconden % 10;
	}
};