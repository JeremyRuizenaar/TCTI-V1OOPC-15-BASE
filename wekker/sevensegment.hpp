///@file 
//#include "hwlib.hpp"
/// library v0or display bestaande uit 6 maal hc5959 ic
//
///deze klasse maakt een object aan van 6 losse 7segment-displays tot een voledig display
class sevensegmentlib{
private:

	hwlib::hc595 displayRegister0;
	hwlib::hc595 displayRegister1;
	hwlib::hc595 displayRegister2;
	hwlib::hc595 displayRegister3;
	hwlib::hc595 displayRegister4;
	hwlib::hc595 displayRegister5; //- teken
	
	hwlib::target::pin_in_out knop1;
	hwlib::target::pin_in_out knop2;
	hwlib::target::pin_in_out enter;
	
	int left;
	int right;
	int getal;


	int a ;
	int b ;
	int c ;
	int d ;
	int refresh = 0;
	
	void  breek_op(int i, int cijfer[]){
			cijfer[0] = (i / 100000) % 10;
			cijfer[1] = (i / 10000) % 10;
			cijfer[2] = (i / 1000) % 10;
			cijfer[3] = (i / 100) % 10;
			cijfer[4] = (i / 10) % 10;
			cijfer[5] = i % 10;
		}
		
		
	void shift_array(int array[],int size){
		int temp = array[0];
		for(int g = 0; g<size; g++){
			if(g == size-1){
				array[g] = temp;
			}
			else{
				array[g] = array[g+1];
			}
		}
	
		//hwlib::cout << array[0] << " " << array[1]  << " "  << array[2]  << " " << array[3] << " " 
		//<< array[4]  << " "  << array[5]  << " \n" ;
		}
		
		
	void set(int a, hwlib::hc595 displayRegister ){			// zet erste cijfer in display 
		if(a == -1){
			displayRegister.p0.set(0);//a
			displayRegister.p1.set(0);//b
			displayRegister.p2.set(0);//c
			displayRegister.p3.set(0);//d
			displayRegister.p4.set(0);//e
			displayRegister.p5.set(0);//f
			displayRegister.p6.set(0);//g
			displayRegister.p7.set(0);//dot
		}
		else if(a == 0){
			
			displayRegister.p0.set(1);//a
			displayRegister.p1.set(1);//b
			displayRegister.p2.set(1);//c
			displayRegister.p3.set(1);//d
			displayRegister.p4.set(1);//e
			displayRegister.p5.set(1);//f
			displayRegister.p6.set(0);//g
			displayRegister.p7.set(0);//dot
			
		}
		else if(a == 1){
			
			displayRegister.p0.set(0);
			displayRegister.p1.set(1);
			displayRegister.p2.set(1);
			displayRegister.p3.set(0);
			displayRegister.p4.set(0);
			displayRegister.p5.set(0);
			displayRegister.p6.set(0);
			displayRegister.p7.set(0);
			
		}
		else if(a == 2){
			displayRegister.p0.set(1);
			displayRegister.p1.set(1);
			displayRegister.p2.set(0);
			displayRegister.p3.set(1);
			displayRegister.p4.set(1);
			displayRegister.p5.set(0);
			displayRegister.p6.set(1);
			displayRegister.p7.set(0);
			
		}
		else if(a == 3){
			displayRegister.p0.set(1);
			displayRegister.p1.set(1);
			displayRegister.p2.set(1);
			displayRegister.p3.set(1);
			displayRegister.p4.set(0);
			displayRegister.p5.set(0);
			displayRegister.p6.set(1);
			displayRegister.p7.set(0);
		}
		else if(a == 4){
			displayRegister.p0.set(0);//a
			displayRegister.p1.set(1);//b
			displayRegister.p2.set(1);//c
			displayRegister.p3.set(0);//d
			displayRegister.p4.set(0);//e
			displayRegister.p5.set(1);//f
			displayRegister.p6.set(1);//g
			displayRegister.p7.set(0);//dot
		}
		else if(a == 5){
			displayRegister.p0.set(1);
			displayRegister.p1.set(0);
			displayRegister.p2.set(1);
			displayRegister.p3.set(1);
			displayRegister.p4.set(0);
			displayRegister.p5.set(1);
			displayRegister.p6.set(1);
			displayRegister.p7.set(0);
		}
		else if(a == 6){
			displayRegister.p0.set(1);
			displayRegister.p1.set(0);
			displayRegister.p2.set(1);
			displayRegister.p3.set(1);
			displayRegister.p4.set(1);
			displayRegister.p5.set(1);
			displayRegister.p6.set(1);
			displayRegister.p7.set(0);
		}
		else if(a == 7){
			displayRegister.p0.set(1);
			displayRegister.p1.set(1);
			displayRegister.p2.set(1);
			displayRegister.p3.set(0);
			displayRegister.p4.set(0);
			displayRegister.p5.set(0);
			displayRegister.p6.set(0);
			displayRegister.p7.set(0);
		}
		else if(a == 8){
			displayRegister.p0.set(1);
			displayRegister.p1.set(1);
			displayRegister.p2.set(1);
			displayRegister.p3.set(1);
			displayRegister.p4.set(1);
			displayRegister.p5.set(1);
			displayRegister.p6.set(1);
			displayRegister.p7.set(0);
		}
		else if(a == 9){
			displayRegister.p0.set(1);
			displayRegister.p1.set(1);
			displayRegister.p2.set(1);
			displayRegister.p3.set(1);
			displayRegister.p4.set(0);
			displayRegister.p5.set(1);
			displayRegister.p6.set(1);
			displayRegister.p7.set(0);
		}
		else if(a == 10){ //min teken
			displayRegister.p0.set(0);
			displayRegister.p1.set(0);
			displayRegister.p2.set(0);
			displayRegister.p3.set(0);
			displayRegister.p4.set(0);
			displayRegister.p5.set(0);
			displayRegister.p6.set(1);
			displayRegister.p7.set(0);
		}
		else if(a == 11){ //alles aan 
			displayRegister.p0.set(1);
			displayRegister.p1.set(1);
			displayRegister.p2.set(1);
			displayRegister.p3.set(1);
			displayRegister.p4.set(1);
			displayRegister.p5.set(1);
			displayRegister.p6.set(1);
			displayRegister.p7.set(1);
		}
		else if(a == 20){ //A
			displayRegister.p0.set(1);
			displayRegister.p1.set(1);
			displayRegister.p2.set(1);
			displayRegister.p3.set(0);
			displayRegister.p4.set(1);
			displayRegister.p5.set(1);
			displayRegister.p6.set(1);
			displayRegister.p7.set(0);
		}
		else if(a == 21){ //b
			displayRegister.p0.set(0);
			displayRegister.p1.set(0);
			displayRegister.p2.set(1);
			displayRegister.p3.set(1);
			displayRegister.p4.set(1);
			displayRegister.p5.set(1);
			displayRegister.p6.set(1);
			displayRegister.p7.set(0);
		}
		else if(a == 22){ //C
			displayRegister.p0.set(1);
			displayRegister.p1.set(0);
			displayRegister.p2.set(0);
			displayRegister.p3.set(1);
			displayRegister.p4.set(1);
			displayRegister.p5.set(1);
			displayRegister.p6.set(0);
			displayRegister.p7.set(0);
		}
		else if(a == 23){ //D
			displayRegister.p0.set(0);
			displayRegister.p1.set(1);
			displayRegister.p2.set(1);
			displayRegister.p3.set(1);
			displayRegister.p4.set(1);
			displayRegister.p5.set(0);
			displayRegister.p6.set(1);
			displayRegister.p7.set(0);
		}
		else if(a == 24){ //E
			displayRegister.p0.set(1);
			displayRegister.p1.set(0);
			displayRegister.p2.set(0);
			displayRegister.p3.set(1);
			displayRegister.p4.set(1);
			displayRegister.p5.set(1);
			displayRegister.p6.set(1);
			displayRegister.p7.set(0);
		}
		else if(a == 25){ //F 
			displayRegister.p0.set(1);
			displayRegister.p1.set(0);
			displayRegister.p2.set(0);
			displayRegister.p3.set(0);
			displayRegister.p4.set(1);
			displayRegister.p5.set(1);
			displayRegister.p6.set(1);
			displayRegister.p7.set(0);
		}
		else if(a == 26){ //H 
			displayRegister.p0.set(0);
			displayRegister.p1.set(1);
			displayRegister.p2.set(1);
			displayRegister.p3.set(0);
			displayRegister.p4.set(1);
			displayRegister.p5.set(1);
			displayRegister.p6.set(1);
			displayRegister.p7.set(0);
		}
		else if(a == 27){ //J 
			displayRegister.p0.set(0);
			displayRegister.p1.set(1);
			displayRegister.p2.set(1);
			displayRegister.p3.set(1);
			displayRegister.p4.set(0);
			displayRegister.p5.set(0);
			displayRegister.p6.set(0);
			displayRegister.p7.set(0);
		}
		else if(a == 28){ //L
			displayRegister.p0.set(0);
			displayRegister.p1.set(0);
			displayRegister.p2.set(0);
			displayRegister.p3.set(1);
			displayRegister.p4.set(1);
			displayRegister.p5.set(1);
			displayRegister.p6.set(0);
			displayRegister.p7.set(0);
		}
		else if(a == 29){ //P 
			displayRegister.p0.set(1);
			displayRegister.p1.set(1);
			displayRegister.p2.set(0);
			displayRegister.p3.set(0);
			displayRegister.p4.set(1);
			displayRegister.p5.set(1);
			displayRegister.p6.set(1);
			displayRegister.p7.set(0);
		}
		else if(a == 30){ //R
			displayRegister.p0.set(1);
			displayRegister.p1.set(0);
			displayRegister.p2.set(0);
			displayRegister.p3.set(0);
			displayRegister.p4.set(1);
			displayRegister.p5.set(1);
			displayRegister.p6.set(0);
			displayRegister.p7.set(0);
		}
		else if(a == 31){ //U 
			displayRegister.p0.set(0);
			displayRegister.p1.set(1);
			displayRegister.p2.set(1);
			displayRegister.p3.set(1);
			displayRegister.p4.set(1);
			displayRegister.p5.set(1);
			displayRegister.p6.set(0);
			displayRegister.p7.set(0);
		}
		else if(a == 32){ //N 
			displayRegister.p0.set(1);
			displayRegister.p1.set(1);
			displayRegister.p2.set(1);
			displayRegister.p3.set(0);
			displayRegister.p4.set(1);
			displayRegister.p5.set(1);
			displayRegister.p6.set(0);
			displayRegister.p7.set(0);
		}
	
	
	}

	void set_display_left(){			//voer uren in via knoppen
		
			while(1){
				a =  (left / 10) % 10;
				b = left % 10;
				update(0,a);
				update(1,b);
				update(2,10);
				update(3,0);
				update(4,0);
				hwlib::wait_ms( 50 );
				if(! knop1.get() ){
					left++;
					if( left == 24){
						left = 0;
					}
				}
				else if ( ! knop2.get() ){
					left--;
					if ( left == -1){
						left = 23;
					}				
				}
				else if ( ! enter.get() ){
					hwlib::wait_ms(500);
					break;
				}
			}
		}

	void set_display_right(){			//voer minuten in via knoppen
		while(1){
			
			
			c =  (right / 10) % 10;				// verander in c en d 
			d = right % 10;
			update(0,(left / 10) % 10);
			update(1,left % 10);
			update(2,10);
			update(3,c);
			update(4,d);
			hwlib::wait_ms( 50 );
			if(! knop1.get() ){
				right++;
				if( right == 60){
					right = 0;
				}
			}
			else if ( ! knop2.get() ){
				right--;
				if( right == -1){
					right = 59;
				}
			}
			else if ( ! enter.get() ){
				hwlib::wait_ms(500);
				break;
			}
		}
			
		}
	
	void set_display_full(){
		while(1){
			
			update(getal);
			
			hwlib::wait_ms( 50 );
			
			if(! knop1.get() ){
				getal++;
				if( getal == 1000000){
					getal = 0;
				}
			}
			else if ( ! knop2.get() ){
				getal--;
				if( getal == -1){
					getal = 999999;
				}
			}
			else if ( ! enter.get() ){
				hwlib::wait_ms(500);
				break;
			}
		}
	}
public:
	///default constructor
	//
	///creert het display bestaande uit de 6 segmenten en 
	///en de 3 knoppen om interactie met het scherm aan te kunnnen gaan
	sevensegmentlib(hwlib::hc595 & displayRegister0, hwlib::hc595 & displayRegister1, hwlib::hc595 & displayRegister2, hwlib::hc595 & displayRegister3, hwlib::hc595 & displayRegister4,
		hwlib::hc595 & displayRegister5, hwlib::target::pin_in_out & knop1,  hwlib::target::pin_in_out & knop2, hwlib::target::pin_in_out & enter):
			displayRegister0 ( displayRegister0 ),
			displayRegister1 ( displayRegister1 ),
			displayRegister2 ( displayRegister2 ),
			displayRegister3 ( displayRegister3 ),
			displayRegister4 ( displayRegister4 ),
			displayRegister5 ( displayRegister5 ),
			knop1 ( knop1),
			knop2 ( knop2 ),
			enter ( enter)
		{}	
		
	

		///weergeeft een integer op het display
		//
		///deze functie breekt een getal op in zijn individuele cijfers
		///en zorgt er voor dat elk segment zijn eigen cijfer toegeschreven krijgt
		void update(int getal){
			int cijfer[6];
			int h;
			breek_op(getal,cijfer);
			if(getal <1000000){
				h =0;
			}
			if(getal < 100000){
				h=1;
				erase(0);
			}
			if(getal <10000){
				h=2;
				erase(0);
				erase(1);
			}
			
			
			if(getal <1000){
				h=3;
				erase(2);
			}
			if(getal <100){
				h=4;
				erase(3);
			}
			if(getal <10){
				h=5;
				erase(4);
			}
			 
			for(int z= h; z<6; z++){
				
					update(z,cijfer[z]);
				
			
			}
			
		}
		///weergeeft een getal of letter op segment naar keuze
		//
		///deze functie schrijft een integer of letter naar een segment naar keuze
		///en wist het scherm zodat er maar 1 segment per keer geactiveerd is
		void update(int segment, int a){
			
			if(segment == 0){  //a
				set(a, displayRegister0);
				//hwlib::cout << "display 0 " << a << "\n";
				hwlib::wait_ms(refresh);
				erase(segment);			
			}
			else if (segment == 1){ //b_
				set(a, displayRegister1);
				//hwlib::cout << "display 1 " << a << "\n";
				hwlib::wait_ms(refresh);
				erase(segment);	
			}
			else if (segment == 2){ //c
				set(a, displayRegister5);
				//hwlib::cout << "display 2 " << a << "\n";
				hwlib::wait_ms(refresh);
				erase(segment);	
			}
			else if (segment == 3){ //d
				set(a, displayRegister2);
				//hwlib::cout << "display 3 " << a << "\n";
				hwlib::wait_ms(refresh);
				erase(segment);	
			}
			else if (segment == 4){  //e
				set(a, displayRegister3);
				//hwlib::cout << "display 4 " << a << "\n";
				hwlib::wait_ms(refresh);
				erase(segment);	
			}
			else if (segment == 5){ //min
				set(a, displayRegister4);
				//hwlib::cout << "display 5 " << a << "\n";
				hwlib::wait_ms(refresh);
				erase(segment);	
			}
		}
		///rolt een string van numbers of letters over het display
		//
		///deze functie accepteert een array van onbepaalde lengte 
		///in deze array staan de waardes van de af te beelden cijfers of letters
		///deze functie weergeeft de cijfers op het display en verschuift daarna de inhoud van het array 1 positie opzij
		///totdat het eerste letter van de oorspronkelijke array weer op zijn oorspronkelijke plek staat
		///per verschuiving worden de waardes van het array uitgeprint die zich binnen de range van het display passen
		void update(int array[], int size, int delay){
			for(int p =0; p <size; p++){
				update(0,array[0]);
				update(1,array[1]);
				update(2,array[2]);
				update(3,array[3]);
				update(4,array[4]);
				update(5,array[5]);
				shift_array(array,size);
				hwlib::wait_ms(delay);
			}
			hwlib::wait_ms(10);
		}
		

		///wist alle segmenten
		//
		/// deze functie zet alle segmenten op uit
		void eraseALL(){
			for(int y=0; y <6; y++){
				erase(y);
			}
		}
		///wist een segment naar keuze
		//
		///deze functie wist een segment naar keuze aangeven met een integer tussen 0 en 6
		void erase(int segment){ 

		if(segment == 0){
			displayRegister0.p0.set(0);//a
			displayRegister0.p1.set(0);//b
			displayRegister0.p2.set(0);//c
			displayRegister0.p3.set(0);//d
			displayRegister0.p4.set(0);//e
			displayRegister0.p5.set(0);//f
			displayRegister0.p6.set(0);//g
			displayRegister0.p7.set(0);//dot
		}
		
		else if(segment == 1){
			displayRegister1.p0.set(0);//a
			displayRegister1.p1.set(0);//b
			displayRegister1.p2.set(0);//c
			displayRegister1.p3.set(0);//d
			displayRegister1.p4.set(0);//e
			displayRegister1.p5.set(0);//f
			displayRegister1.p6.set(0);//g
			displayRegister1.p7.set(0);//dot
		}
		
		else if(segment == 3){
			displayRegister2.p0.set(0);//a
			displayRegister2.p1.set(0);//b
			displayRegister2.p2.set(0);//c
			displayRegister2.p3.set(0);//d
			displayRegister2.p4.set(0);//e
			displayRegister2.p5.set(0);//f
			displayRegister2.p6.set(0);//g
			displayRegister2.p7.set(0);//dot
		}
		
		else if(segment == 4){
			displayRegister3.p0.set(0);//a
			displayRegister3.p1.set(0);//b
			displayRegister3.p2.set(0);//c
			displayRegister3.p3.set(0);//d
			displayRegister3.p4.set(0);//e
			displayRegister3.p5.set(0);//f
			displayRegister3.p6.set(0);//g
			displayRegister3.p7.set(0);//dot
		}
		
		else if(segment == 5){
			displayRegister4.p0.set(0);//a
			displayRegister4.p1.set(0);//b
			displayRegister4.p2.set(0);//c
			displayRegister4.p3.set(0);//d
			displayRegister4.p4.set(0);//e
			displayRegister4.p5.set(0);//f
			displayRegister4.p6.set(0);//g
			displayRegister4.p7.set(0);//dot
		}
		
		else if(segment == 2){
			displayRegister5.p0.set(0);//a
			displayRegister5.p1.set(0);//b
			displayRegister5.p2.set(0);//c
			displayRegister5.p3.set(0);//d
			displayRegister5.p4.set(0);//e
			displayRegister5.p5.set(0);//f
			displayRegister5.p6.set(0);//g
			displayRegister5.p7.set(0);//dot
		}
		
	}
	
		///deze functie zorgt dat er een waarde in het display ingevoerd kan worden
		//
		///deze functie kan aangeroepen met een 0 voor uren en minuten modus
		///en aangeroepen worden met een 1 om een getal in range 0 - 999999 in te voeren
		void setdisplay(int toggle){			// roepe asan om een  voer een waarde in in het display
		left = 0;
		right = 0;
		getal = 0;
		if(toggle == 0){
			set_display_left();
			set_display_right();
		}
		else{
			set_display_full();
		}
	}
	
		
		///geeft getal in uren segment terug
		//
		///geeft getal in uren segment terug
		
		int get_left(){		// haal ingevoerd uren op
			return left;
		}
		//geeft getal in minuten segment terug
		//
		///geeft getal in minuten segment terug
		int get_right(){ //haal ingevoerde minuten op
			return right;
		}
		///geeft getal in volledig segment terug
		//
		///geeft getal in volledig segment terug
		int get_getal(){
			return getal;
		}
};



   