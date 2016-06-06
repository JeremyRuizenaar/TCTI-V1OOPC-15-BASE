//#include "hwlib.hpp"

class display{
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
	hwlib::target::pin_in_out cancel;
	int uren;
	int minuten;
	int cancelstate;
	//niks
	int a ;
	int b ;
	int c ;
	int d ;
	int refresh = 0;

public:
	display(hwlib::hc595 & displayRegister0, hwlib::hc595 & displayRegister1, hwlib::hc595 & displayRegister2, hwlib::hc595 & displayRegister3, hwlib::hc595 & displayRegister4,
		hwlib::hc595 & displayRegister5, hwlib::target::pin_in_out & knop1,  hwlib::target::pin_in_out & knop2, hwlib::target::pin_in_out & enter,
		hwlib::target::pin_in_out & cancel):
			displayRegister0 ( displayRegister0 ),
			displayRegister1 ( displayRegister1 ),
			displayRegister2 ( displayRegister2 ),
			displayRegister3 ( displayRegister3 ),
			displayRegister4 ( displayRegister4 ),
			displayRegister5 ( displayRegister5 ),
			knop1 ( knop1),
			knop2 ( knop2 ),
			enter ( enter),
			cancel ( cancel)
			
		{}
		
		
		void updateA(int a){
			set(a, displayRegister0);
			hwlib::wait_ms(refresh);
			eraseA();
		}
		
		void updateB(int b){
			set(b, displayRegister1);
			hwlib::wait_ms(refresh);
			eraseB();
		}
		
		
		void updateC(int c){
			set(c, displayRegister2);
			hwlib::wait_ms(refresh);
			eraseC();
		}
		
		void updateD(int d){
			set(d, displayRegister3);
			hwlib::wait_ms(refresh);
			eraseD();
		}
		 void updateE(int e){
			set(e, displayRegister4);
			hwlib::wait_ms(refresh);
			eraseE();
		}
		
		void updateMin(){
		 set(10, displayRegister5);
		  hwlib::wait_ms(refresh);
		   eraseMin();
		  
		}
		 
		 
		 
	
	void eraseALL(){
		eraseA();
		eraseB();
		eraseC();
		eraseD();
		eraseE();
		eraseMin();
	}
	
	void eraseA(void){                             // wist het scherm
			displayRegister0.p0.set(0);//a
			displayRegister0.p1.set(0);//b
			displayRegister0.p2.set(0);//c
			displayRegister0.p3.set(0);//d
			displayRegister0.p4.set(0);//e
			displayRegister0.p5.set(0);//f
			displayRegister0.p6.set(0);//g
			displayRegister0.p7.set(0);//dot
		
		
	}
	
	void eraseB(void){                             // wist het scherm
			displayRegister1.p0.set(0);//a
			displayRegister1.p1.set(0);//b
			displayRegister1.p2.set(0);//c
			displayRegister1.p3.set(0);//d
			displayRegister1.p4.set(0);//e
			displayRegister1.p5.set(0);//f
			displayRegister1.p6.set(0);//g
			displayRegister1.p7.set(0);//dot
			
		
	}
	
		void eraseC(void){                             // wist het scherm
			displayRegister2.p0.set(0);//a
			displayRegister2.p1.set(0);//b
			displayRegister2.p2.set(0);//c
			displayRegister2.p3.set(0);//d
			displayRegister2.p4.set(0);//e
			displayRegister2.p5.set(0);//f
			displayRegister2.p6.set(0);//g
			displayRegister2.p7.set(0);//dot
			
		
	}
	
		void eraseD(void){                             // wist het scherm
			displayRegister3.p0.set(0);//a
			displayRegister3.p1.set(0);//b
			displayRegister3.p2.set(0);//c
			displayRegister3.p3.set(0);//d
			displayRegister3.p4.set(0);//e
			displayRegister3.p5.set(0);//f
			displayRegister3.p6.set(0);//g
			displayRegister3.p7.set(0);//dot
			
		
	}
	  void eraseE(void){                             // wist het scherm
			displayRegister4.p0.set(0);//a
			displayRegister4.p1.set(0);//b
			displayRegister4.p2.set(0);//c
			displayRegister4.p3.set(0);//d
			displayRegister4.p4.set(0);//e
			displayRegister4.p5.set(0);//f
			displayRegister4.p6.set(0);//g
			displayRegister4.p7.set(0);//dot
			
		
	}
		void eraseMin(void){                             // wist het scherm
			displayRegister5.p0.set(0);//a
			displayRegister5.p1.set(0);//b
			displayRegister5.p2.set(0);//c
			displayRegister5.p3.set(0);//d
			displayRegister5.p4.set(0);//e
			displayRegister5.p5.set(0);//f
			displayRegister5.p6.set(0);//g
			displayRegister5.p7.set(0);//dot
			
		
	}
	 
	void set(int a, hwlib::hc595 displayRegister ){			// zet erste cijfer in display 
		if(a == 0){
			
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
			displayRegister.p3.set(0);
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
	
	}
	/*
	void setB(int b, hwlib::hc595 displayRegister){			// zet tweede cijfer in display 2
		if(b == 0){
			displayRegister2.p0.set(1);//a
			displayRegister2.p1.set(1);//b
			displayRegister2.p2.set(1);//c
			displayRegister2.p3.set(1);//d
			displayRegister2.p4.set(1);//e
			displayRegister2.p5.set(1);//f
			displayRegister2.p6.set(0);//g
			displayRegister2.p7.set(0);//dot
			
		}
		else if(b == 1){
			displayRegister2.p0.set(0);
			displayRegister2.p1.set(1);
			displayRegister2.p2.set(1);
			displayRegister2.p3.set(0);
			displayRegister2.p4.set(0);
			displayRegister2.p5.set(0);
			displayRegister2.p6.set(0);
			displayRegister2.p7.set(0);
			
		}
		else if(b == 2){
			displayRegister2.p0.set(1);
			displayRegister2.p1.set(1);
			displayRegister2.p2.set(0);
			displayRegister2.p3.set(1);
			displayRegister2.p4.set(1);
			displayRegister2.p5.set(0);
			displayRegister2.p6.set(1);
			displayRegister2.p7.set(0);
			
		}
		else if(b == 3){
			displayRegister2.p0.set(1);
			displayRegister2.p1.set(1);
			displayRegister2.p2.set(1);
			displayRegister2.p3.set(1);
			displayRegister2.p4.set(0);
			displayRegister2.p5.set(0);
			displayRegister2.p6.set(1);
			displayRegister2.p7.set(0);
		}
		else if(b == 4){
			displayRegister2.p0.set(0);//a
			displayRegister2.p1.set(1);//b
			displayRegister2.p2.set(1);//c
			displayRegister2.p3.set(0);//d
			displayRegister2.p4.set(0);//e
			displayRegister2.p5.set(1);//f
			displayRegister2.p6.set(1);//g
			displayRegister2.p7.set(0);//dot
		}
		else if(b == 5){
			displayRegister2.p0.set(1);
			displayRegister2.p1.set(0);
			displayRegister2.p2.set(1);
			displayRegister2.p3.set(1);
			displayRegister2.p4.set(0);
			displayRegister2.p5.set(1);
			displayRegister2.p6.set(1);
			displayRegister2.p7.set(0);
		}
		else if(b == 6){
			displayRegister2.p0.set(1);
			displayRegister2.p1.set(0);
			displayRegister2.p2.set(1);
			displayRegister2.p3.set(1);
			displayRegister2.p4.set(1);
			displayRegister2.p5.set(1);
			displayRegister2.p6.set(1);
			displayRegister2.p7.set(0);
		}
		else if(b == 7){
			displayRegister2.p0.set(1);
			displayRegister2.p1.set(1);
			displayRegister2.p2.set(1);
			displayRegister2.p3.set(0);
			displayRegister2.p4.set(0);
			displayRegister2.p5.set(0);
			displayRegister2.p6.set(0);
			displayRegister2.p7.set(0);
		}
		else if(b == 8){
			displayRegister2.p0.set(1);
			displayRegister2.p1.set(1);
			displayRegister2.p2.set(1);
			displayRegister2.p3.set(1);
			displayRegister2.p4.set(1);
			displayRegister2.p5.set(1);
			displayRegister2.p6.set(1);
			displayRegister2.p7.set(0);
		}
		else if(b == 9){
			displayRegister2.p0.set(1);
			displayRegister2.p1.set(1);
			displayRegister2.p2.set(1);
			displayRegister2.p3.set(0);
			displayRegister2.p4.set(0);
			displayRegister2.p5.set(1);
			displayRegister2.p6.set(1);
			displayRegister2.p7.set(0);
		}
	}
	*/
	void set_wekker_active(int getal){		// roep aan om een getal 0 -99 in linker of rechter 2 displays te zetten
		if(getal == 0){
			set(0, displayRegister1)	;
		}
		else if(getal ==1){
			set(1 , displayRegister1)	;	
		}
		else{
			//set(getal , displayRegister1)	;
		}
		
	}
	/*
	void setR(int getal){		// roep aan om een getal 0 -99 in linker of rechter 2 displays te zetten
		int c = (getal / 10) % 10;
		int d = getal % 10;
		//eraseR();
		set(c, displayRegister2)	;	
		set(d, displayRegister3);
		
	}
	*/
	
	void setdisplay(){			// roep asan om een  voer een waarde in in het display
		uren = 0;
		minuten = 0;
		//setL(0);
		//setR(0)
		//eraseR();
		seturen();
		//setL(70); // verander in setR
		
		//eraseL();
		//setR(0)
		setminuten();
		
		//s();
		
		
		
	}
	
	
	
	void seturen(){			//voer uren in via knoppen
		cancelstate = 0;
		
		
		while(1){
		a =  (uren / 10) % 10;
		b = uren % 10;
		updateA(a);
		updateB(b);
			hwlib::wait_ms( 500 );
			if(! knop1.get() ){
				uren++;
				if( uren == 24){
					uren = 0;
				}
				//setL(uren);
			}
			else if ( ! knop2.get() ){
				uren--;
				if ( uren == -1){
					uren = 23;
				}
				//setL(uren);
				
			}
			else if ( ! enter.get() ){
				//setL(0); //mogelijk weghalen
				hwlib::wait_ms(500);
				break;
			}
			else if ( ! cancel.get()){
				cancelstate = 1;
				//setL(44);              // verander in config scherm
				//hwlib::wait_ms(2000);
				break;
			}
			
		}
	}
	
	int get_cancelstate(){
		return cancelstate;
	}
	
	void setminuten(){			//voer minuten in via knoppen
		while(1){
			
			a =  (minuten / 10) % 10;				// verander in c en d 
			b = minuten % 10;
			updateC(a);
			updateD(b);
			hwlib::wait_ms( 500 );
			if(! knop1.get() ){
				minuten++;
				if( minuten == 60){
					minuten = 0;
				}
				//setL(minuten);
			}
			else if ( ! knop2.get() ){
				minuten--;
				if( minuten == -1){
					minuten = 59;
				}
				//setL(minuten);
				
			}
			else if ( ! enter.get() ){
				//setL(80); //mogelijk weghalen
				hwlib::wait_ms(500);
				break;
			}
			else if ( cancelstate){
				cancelstate = 1;
				//setL(44); // verander in config scherm
				hwlib::wait_ms(500);
				break;
			}
			else if ( ! cancel.get()){
				cancelstate =1;
				hwlib::wait_ms(500);
				break;
			}
			
		}
	}
	/*
	void weergeeftimer(){
		while(1){
			setL(uren);
			if(! enter.get()){
				setL(0);
				break;
			}
		}
		
	}*/

	int get_uren(){		// haal ingevoerd uren op
		return uren;
	}
	
	int get_minuten(){ //haal ingevoerde minuten op
		return minuten;
	}

};



   