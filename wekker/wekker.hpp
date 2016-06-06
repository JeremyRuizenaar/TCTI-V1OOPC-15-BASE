class wekker{
private:

int select= 0;

public:
	wekker():
	select(0)
	{}
	
/*
	void set_select(){
		//updateE(select); //impl 5 scherm
		while(1){
				hwlib::wait_ms( 500 );
			if(! knop1.get() ){
				select++;
				if( select == 4){
					select = 0;
				}
			}
			else if ( ! knop2.get() ){
				select--;
				if ( select == -1){
					select = 3;
				}				
			}
			else if ( ! enter.get() ){
				hwlib::wait_ms(500);
				break;
			}
		
		}
		
	}
*/
	int get_select(){
		return select;
	}
	
	void wekkerup(){
		select++;
		if(select == 4){
			select = 0;
		}
	}
	
	void wekkerdown(){
		select--;
		if(select == -1){
			select = 3;
		}
	}
};

