///@file 
///klassen voor de analoge klok
//
///deze klasse beheert de analoge klok
class analoogklok{
private:

int uren;
int minuten;

hwlib::hc595 & d;
hwlib::hc595 & e;





public:
///constructor
//
///creert een analoog klok object uit 2 hc595
	analoogklok(hwlib::hc595  d, hwlib::hc595  e):
	d (d),
	e(e)
	
	{}
	
	///set uren
	//
	///deze functie set het aantal uren in de klok
	void set_uren(int y){
		uren = y;
	}
	
	///set minuten
	//
	///deze functie set het aantal minuten in de klok
	void set_minuten(int y){
		minuten = y;
	}
	/// update klok wijzerss
	//
	/// deze functie update de wijzerleds naar de uren en minuten die meegeven worden.
	
	void update(int uren){
		//eraseWijzer();
		hwlib::wait_ms(1000);
		//hwlib::cout << "wijzer gewist\n";
			
		blinkwijzer_uren(uren);
		//hwlib::cout << "wijzer geupdate\n";
		hwlib::wait_ms(1000);	
		
	}
	
void eraseWijzer(){
	d.p0.set(0);
	d.p1.set(0);
	d.p2.set(0);
	d.p3.set(0);
	d.p4.set(0);
	d.p5.set(0);
	d.p6.set(0);
	d.p7.set(0);
	e.p0.set(0);
	e.p1.set(0);
	e.p2.set(0);
	e.p3.set(0);
	
}

	void blink( int a){
		eraseWijzer();
		//hwlib::cout << "blink aangeroepen \n";
		int time = 0;
					if(a==0){
						d.p0.set(1);
						hwlib::wait_ms(time);
						d.p0.set(0);
						hwlib::wait_ms(time);
					}
					else if(a==1){
						d.p1.set(1);
						hwlib::wait_ms(time);
						d.p1.set(0);
						hwlib::wait_ms(time);
					}
					else if(a==2){
						//hwlib::cout << "blink  2 aangeroepen " << a << "\n";
						d.p2.set(1);
						hwlib::wait_ms(time);
						d.p2.set(0);
						hwlib::wait_ms(time);
					}
					else if(a==3){
						d.p3.set(1);
						hwlib::wait_ms(time);
						d.p3.set(0);
						hwlib::wait_ms(time);
					}
					else if(a==4){
						d.p4.set(1);
						hwlib::wait_ms(time);
						d.p4.set(0);
						hwlib::wait_ms(time);
					}
					else if(a==5){
						d.p5.set(1);
						hwlib::wait_ms(time);
						d.p5.set(0);
						hwlib::wait_ms(time);
					}
					else if(a==6){
						//hwlib::cout << "blink 6 aangeroepen " << a << "\n";
						d.p6.set(1);
						hwlib::wait_ms(time);
						d.p6.set(0);
						hwlib::wait_ms(time);
					}
					else if(a==7){
						d.p7.set(1);
						hwlib::wait_ms(time);
						d.p7.set(0);
						hwlib::wait_ms(time);
					}
					else if(a==8){
						e.p0.set(1);
						hwlib::wait_ms(time);
						e.p0.set(0);
						hwlib::wait_ms(time);
					}
					else if(a==9){
						e.p1.set(1);
						hwlib::wait_ms(time);
						e.p1.set(0);
						hwlib::wait_ms(time);
					}
					else if(a==10){
						e.p2.set(1);
						hwlib::wait_ms(time);
						e.p2.set(0);
						hwlib::wait_ms(time);
					}
					else if(a==11){
						e.p3.set(1);
						hwlib::wait_ms(time);
						e.p3.set(0);
						hwlib::wait_ms(time);
					}
					else if(a==12){
						d.p0.set(1);
						hwlib::wait_ms(time);
						d.p0.set(0);
						hwlib::wait_ms(time);
					}
					else if(a==13){
						d.p1.set(1);
						hwlib::wait_ms(time);
						d.p1.set(0);
						hwlib::wait_ms(time);
					}
					else if(a==14){
						d.p2.set(1);
						hwlib::wait_ms(time);
						d.p2.set(0);
						hwlib::wait_ms(time);
					}
					else if(a==15){
						d.p3.set(1);
						hwlib::wait_ms(time);
						d.p3.set(0);
						hwlib::wait_ms(time);
					}
					else if(a==16){
						d.p4.set(1);
						hwlib::wait_ms(time);
						d.p4.set(0);
						hwlib::wait_ms(time);
					}
					else if(a==17){
						d.p5.set(1);
						hwlib::wait_ms(time);
						d.p5.set(0);
						hwlib::wait_ms(time);
					}
					else if(a==18){
						d.p6.set(1);
						hwlib::wait_ms(time);
						d.p6.set(0);
						hwlib::wait_ms(time);
					}
					else if(a==19){
						d.p7.set(1);
						hwlib::wait_ms(time);
						d.p7.set(0);
						hwlib::wait_ms(time);
					}
					else if(a==20){
						e.p0.set(1);
						hwlib::wait_ms(time);
						e.p0.set(0);
						hwlib::wait_ms(time);
					}
					else if(a==21){
						e.p1.set(1);
						hwlib::wait_ms(time);
						e.p1.set(0);
						hwlib::wait_ms(time);
					}
					else if(a==22){
						e.p2.set(1);
						hwlib::wait_ms(time);
						e.p2.set(0);
						hwlib::wait_ms(time);
					}
					else if(a==23){
						e.p3.set(1);
						hwlib::wait_ms(time);
						e.p3.set(0);
						hwlib::wait_ms(time);
					}
	}
	
	
void updateWijzer(int uren, int minuten){
	eraseWijzer();
	blinkwijzer_uren(uren);
	blinkwijzer_minuten(minuten);
}

void blinkwijzer_minuten( int a){
	//hwlib::cout << "blinkwijzer aangeroepen \n";
	//eraseWijzer();
					if(a < 5){
						d.p0.set(1);
					}
					else if(a>4 && a <10 ){
						d.p1.set(1);
					}
					else if(a>9 && a <15){
						d.p2.set(1);
					}
					else if(a>14 && a <20){
						d.p3.set(1);
					}
					else if(a>19 && a <25){
						d.p4.set(1);
					}
					else if(a>24 && a <30){
						d.p5.set(1);
					}
					else if(a>29 && a <35){
						d.p6.set(1);
					}
					else if(a>34 && a <40){
						d.p7.set(1);
					}
					else if(a>39 && a <45){
						e.p0.set(1);
					}
					else if(a>44 && a <50){
						e.p1.set(1);
					}
					else if(a>49 && a <55){
						e.p2.set(1);
					}
					else if(a>45 && a <60){
						e.p3.set(1);
					}
					
					//hwlib::wait_ms(500);
	}

void blinkwijzer_uren( int a){
	//hwlib::cout << "blinkwijzer aangeroepen \n";
	//eraseWijzer();
					if(a==0){
						d.p0.set(1);
					}
					else if(a==1){
						d.p1.set(1);
					}
					else if(a==2){
						d.p2.set(1);
					}
					else if(a==3){
						d.p3.set(1);
					}
					else if(a==4){
						d.p4.set(1);
					}
					else if(a==5){
						d.p5.set(1);
					}
					else if(a==6){
						d.p6.set(1);
					}
					else if(a==7){
						d.p7.set(1);
					}
					else if(a==8){
						e.p0.set(1);
					}
					else if(a==9){
						e.p1.set(1);
					}
					else if(a==10){
						e.p2.set(1);
					}
					else if(a==11){
						e.p3.set(1);
					}
					else if(a==12){
						d.p0.set(1);
					}
					else if(a==13){
						d.p1.set(1);
					}
					else if(a==14){
						d.p2.set(1);
					}
					else if(a==15){
						d.p3.set(1);
					}
					else if(a==16){
						d.p4.set(1);
					}
					else if(a==17){
						d.p5.set(1);
					}
					else if(a==18){
						d.p6.set(1);
					}
					else if(a==19){
						d.p7.set(1);
					}
					else if(a==20){
						e.p0.set(1);
					}
					else if(a==21){
						e.p1.set(1);
					}
					else if(a==22){
						e.p2.set(1);
					}
					else if(a==23){
						e.p3.set(1);
					}
					//hwlib::wait_ms(500);
	}
};

