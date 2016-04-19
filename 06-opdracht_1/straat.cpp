

#include "straat.hpp"

straat::straat( window & w, int start_x, int start_y, int end_x, int end_y , int aantal):

	 osso0( w, start_x, start_y, end_x, end_y  ),
	 osso1( w, start_x+25, start_y, end_x+25,end_y ),
	 osso2( w, start_x+50, start_y, end_x+50, end_y  ),
	 osso3( w, start_x+75, start_y, end_x+75, end_y  ),
	 osso4( w, start_x+100, start_y, end_x+100, end_y  ),
	 
	 weg(w, start_x-5, start_y+30, start_x+123 ,start_y+37),
	 stoep(w, start_x-5, start_y+25, start_x+123, start_y+25),
	 grid(w, start_x, start_y, end_x, end_y),
	 grid2(w, start_x, start_y+12, end_x, start_y+17),
	 aantal (aantal)
  
{}

void straat::print(){
	switch(aantal){
		case 0:
			weg.print();
			stoep.print();
			grid.print();
			grid2.print();
			break;
		
		case 1:
			 osso0.print();
			 stoep.print();
			 weg.print();
			 grid.print();
			 grid2.print();
			break;
		case 2:
			osso0.print();
			osso1.print();
			stoep.print();
			weg.print();
			grid.print();
			grid2.print();
			break;
		case 3:
			osso0.print();
			osso1.print();
			osso2.print();
			stoep.print();
			weg.print();
			grid.print();
			grid2.print();
			break;
		case 4:
			osso0.print();
			osso1.print();
			osso2.print();
			osso3.print();
			stoep.print();
			weg.print();
			grid.print();
			grid2.print();
			break;
		case 5:
			osso0.print();
			osso1.print();
			osso2.print();
			osso3.print();
			osso4.print();
			stoep.print();
			stoep.print();
			weg.print();
			grid.print();
			grid2.print();
			break;
	}
	
}