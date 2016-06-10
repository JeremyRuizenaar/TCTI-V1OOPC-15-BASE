//#include "hwlib.hpp"
class i2cRTC {
private:
	
	int uren;
	int minuten; 
	int seconden;
	int week;
	int dag;
	int maand;
	int jaar;
	
	

	fast_byte  a = 0x68; //adres d1307 01101000
	byte data[8] = {0,0,0,0,0,0,0}; //test  date
	byte  data_get[7];
	
	
	
	hwlib::i2c_bus_bit_banged_scl_sda & i2c;  // i2c bus
	// benodigd heden 2c buss 
		byte dec_Bcd(byte val)
		{
			return( (val/10*16) + (val%10) );
		}
		
		byte bcd_Dec(byte val)
		{
			return( (val/16*10) + (val%16) );
		}
	

	
public:
	i2cRTC(hwlib::i2c_bus_bit_banged_scl_sda & i2c, int sec =0, int min=0, int uur=0, int dag_week=0, int dag_maand=0, int maand=0, int jaar=0):
			i2c( i2c)
		{
			set_seconden(sec);
			set_minuten(min);
			set_uren(uur);
			set_dag_week(dag_week);
			set_dag_maand(dag_maand);
			set_maand(maand);
			set_jaar(jaar);
			
			}
		


	void set_time(int sec, int min, int uur, int dag_week, int dag_maand, int maand, int jaar){ // 
		//voer uren en minuten in op display  haaal deze waardes op en stuur ze naar rtc
		//i2c.write(a , data_first, 1);
		
		data[0] = 0;
		data[1]= dec_Bcd(sec);
		data[2] = dec_Bcd(min) ;
		data[3] = dec_Bcd(uur);;
		data[4] = dec_Bcd(dag_week) ;
		data[5] = dec_Bcd(dag_maand) ;
		data[6] = dec_Bcd(maand) ;
		data[7] = dec_Bcd(jaar) ;
		i2c.write(a , data, 8);
	}
	
	void get_tijd(){ // haal uren op uit rtc
		i2c.write(a,  data , 1);
		i2c.read(a, data_get, 7);
		seconden  = bcd_Dec(data_get[0]);
		minuten = bcd_Dec(data_get[1] & 0x7f);
		uren = bcd_Dec(data_get[2] & 0x3f);
		week = bcd_Dec(data_get[3]);
		dag = bcd_Dec(data_get[4]);
		maand = bcd_Dec(data_get[5]);
		jaar = bcd_Dec(data_get[6]);
		hwlib::wait_ms( 1 );
		hwlib::cout << "bcd " << seconden << "  seconden    "  << "byte   " << int(data_get[0]) << " NC " <<data[1] << "\n";
		//hwlib::wait_ms( 1 );
		hwlib::cout << "bcd " << minuten  << " minuten     "  << "byte   "  << int(data_get[1]) << " NC" <<data[2]  << "\n";
		//hwlib::wait_ms( 1 );
		hwlib::cout << "bcd " << uren  << "  uren    "  << "byte   "   << int(data_get[2]) << " NC  " <<data[3]  <<  "\n";
		//hwlib::wait_ms( 1 );
		hwlib::cout << "bcd " << week  << " week "   <<   "byte   " <<  int(data_get[3]) << " NC " <<data[4]  <<  "\n";
		hwlib::wait_ms( 1 );
		hwlib::cout << "bcd " << dag  << "   dag "    << "byte   "  <<  int(data_get[4]) << " NC " <<data[5]  <<  "\n";
		hwlib::wait_ms( 1 );
		hwlib::cout << "bcd " << maand  << "  maand  "   << "byte   "   <<  int(data_get[5]) << " NC " <<data[6]  <<  "\n";
		hwlib::wait_ms( 1 );
		hwlib::cout << "bcd " << jaar  << " jaar     "   << "byte   "   <<  int(data_get[6]) << "  NC " <<data[7]  <<  "\n";
		
		
		
		
		
	}
	
	int get_seconden(){  // haal minuten op uit rtc
		byte rtcRegister[1] = {0}; 
		byte buffer[1] = {0};
		i2c.write(a,  rtcRegister , 1);
		i2c.read(a, buffer, 1);
		return bcd_Dec(buffer[0]);
	}
	void set_seconden(int x){  // haal minuten op uit rtc
		byte rtcRegister[2] = {0,dec_Bcd(x)}; 
		i2c.write(a,  rtcRegister , 2);
	}
	
	int get_minuten(){  // haal minuten op uit rtc
		byte rtcRegister[1] = {1}; 
		byte buffer[1] = {0};
		i2c.write(a,  rtcRegister , 1);
		i2c.read(a, buffer, 1);
		return bcd_Dec(buffer[0]);
	}
	void set_minuten(int x){  // haal minuten op uit rtc
		byte rtcRegister[2] = {1,dec_Bcd(x)}; 
		i2c.write(a,  rtcRegister , 2);
	}
	
	int get_uren(){  // haal seconden op uit rtc
		byte rtcRegister[1] = {2}; 
		byte buffer[1] = {0};
		i2c.write(a,  rtcRegister , 1);
		i2c.read(a, buffer, 1);
		return bcd_Dec(buffer[0]);
	}
	void set_uren(int x){  // haal seconden op uit rtc
		byte rtcRegister[2] = {2,dec_Bcd(x)}; 
		i2c.write(a,  rtcRegister , 2);
	}
	
	void toggle_24h_set(int toggle){
		if(toggle == 1){
			byte b = dec_Bcd(get_uren()) | 0x40;

			byte rtcRegister[2] ={2,b};
			i2c.write(a,  rtcRegister , 2);
		}
		else if (toggle ==0){
			byte b = dec_Bcd(get_uren()) & 0x2f;
			byte rtcRegister[2] ={2,b};
			i2c.write(a,  rtcRegister , 2);
		}
	}
	
	int get_dag_week(){  // haal seconden op uit rtc
		byte rtcRegister[1] = {3}; 
		byte buffer[1] = {0};
		i2c.write(a,  rtcRegister , 1);
		i2c.read(a, buffer, 1);
		return bcd_Dec(buffer[0]);
	}
	void set_dag_week(int x){  // haal seconden op uit rtc
		byte rtcRegister[2] = {3,dec_Bcd(x)}; 
		i2c.write(a,  rtcRegister , 2);
	}
	
	int get_dag_maand(){  // haal seconden op uit rtc
		byte rtcRegister[1] = {4}; 
		byte buffer[1] = {0};; 
		i2c.write(a,  rtcRegister , 1);
		i2c.read(a, buffer, 1);
		return bcd_Dec(buffer[0]);
	}
	void set_dag_maand(int x){  // haal seconden op uit rtc
		byte rtcRegister[2] = {4,dec_Bcd(x)}; 
		i2c.write(a,  rtcRegister , 2);
	}
	
	int get_maand(){  // haal seconden op uit rtc
		byte rtcRegister[1] = {5}; 
		byte buffer[1] = {0};
		i2c.write(a,  rtcRegister , 1);
		i2c.read(a, buffer, 1);
		return bcd_Dec(buffer[0]);
	}
	void set_maand(int x){  // haal seconden op uit rtc
		byte rtcRegister[2] = {5,dec_Bcd(x)}; 
		i2c.write(a,  rtcRegister , 2);
	}
	
	int get_jaar(){  // haal seconden op uit rtc
		byte rtcRegister[1] = {6}; 
		byte buffer[1] = {0}; 
		i2c.write(a,  rtcRegister , 1);
		i2c.read(a, buffer, 1);
		return bcd_Dec(buffer[0]);
	}
	void set_jaar(int x){  // haal seconden op uit rtc
		byte rtcRegister[2] = {6,dec_Bcd(x)}; 
		i2c.write(a,  rtcRegister , 2);
	}
	
	void set_adres_x(byte x, byte waarde){
		byte rtcRegister[2] = {x,waarde}; 
		i2c.write(a,  rtcRegister , 2);
	}
	int get_adres_x(byte x){
		byte rtcRegister[1] = {x}; 
		byte buffer[1] = {0}; 
		i2c.write(a,  rtcRegister , 1);
		i2c.read(a, buffer, 1);
		return buffer[0];
	}
	
	void osc_set(int toggle){
		if(toggle ==1){
			byte b = dec_Bcd(get_adres_x(7)) | 0x80;
			
			byte rtcRegister[2] ={7,b};
			i2c.write(a,  rtcRegister , 2);
		}
		else{
			byte b = dec_Bcd(get_adres_x(7)) & 0x7f;
			byte rtcRegister[2] ={7,b};
			i2c.write(a,  rtcRegister , 2);
		}
	}
	
	void sqwe_set(int toggle){
		if(toggle ==1){
			byte b = dec_Bcd(get_adres_x(7)) | 0x10;
			byte rtcRegister[2] ={7,b};
			i2c.write(a,  rtcRegister , 2);
		}
		else{
			byte b = dec_Bcd(get_adres_x(7)) & 0xef;
			byte rtcRegister[2] ={7,b};
			i2c.write(a,  rtcRegister , 2);
		}
	}
	
	void rs0_set (int toggle){
		if(toggle ==1){
			byte b = dec_Bcd(get_adres_x(7)) | 0x01;
			byte rtcRegister[2] ={7,b};
			i2c.write(a,  rtcRegister , 2);
		}
		else{
			byte b = dec_Bcd(get_adres_x(7)) & 0xfe;
			byte rtcRegister[2] ={7,b};
			i2c.write(a,  rtcRegister , 2);
		}
	}
	
	void rs1_set(int toggle){
		if(toggle ==1){
			byte b = dec_Bcd(get_adres_x(7)) | 0x20;
			byte rtcRegister[2] ={7,b};
			i2c.write(a,  rtcRegister , 2);
		}
		else{
			byte b = dec_Bcd(get_adres_x(7)) & 0xfd;
			byte rtcRegister[2] ={7,b};
			i2c.write(a,  rtcRegister , 2);
		}
	}
	
	
};