///@file 
///klassen voor de wekker adt
//
///deze classe houd bij welke timer huidig geselecteerd is
class wekker{
private:

int select_huidig = 0;

public:
///constructor
//
///creert een wekker object
	wekker():
	select_huidig(0)
	{}
	
	///get select
	//
	///deze functie retourneert het nummer van de huidig geselecteerde timer
	int get_select(){
		return select_huidig;
	}
	///wekker up
	//
	///deze functie verhoorgt de de huidig geselecteerde timer naar de volgende timer
	void wekkerup(){
		select_huidig++;
		if(select_huidig == 4){
			select_huidig = 0;
		}
	}
	
	///wekker down
	//
	///deze functie verlaagt de huidig geselecteerde timer  naar de vorige timer
	void wekkerdown(){
		select_huidig--;
		if(select_huidig == -1){
			select_huidig = 3;
		}
	}
};

