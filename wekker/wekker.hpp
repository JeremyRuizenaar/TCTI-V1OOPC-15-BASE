class wekker{
private:

int select_huidig = 0;

public:
	wekker():
	select_huidig(0)
	{}
	

	int get_select(){
		return select_huidig;
	}
	
	void wekkerup(){
		select_huidig++;
		if(select_huidig == 4){
			select_huidig = 0;
		}
	}
	
	void wekkerdown(){
		select_huidig--;
		if(select_huidig == -1){
			select_huidig = 3;
		}
	}
};

