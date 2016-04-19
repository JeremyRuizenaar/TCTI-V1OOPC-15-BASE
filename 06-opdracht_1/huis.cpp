#include "huis.hpp"


huis::huis( window & w, int start_x, int start_y, int end_x, int end_y ):

	doos( w, start_x, start_y, end_x, end_y ),
	deur(  w, start_x+5, start_y+10, start_x+10, end_y ),
	lschuin(w,  start_x,  start_y, end_x-10, end_y-40  ),
	rschuin(w, end_x, start_y, end_x-10, end_y-40 ),
	raam(w, start_x+13,  start_y+10, start_x+18,start_y+15),
	dakraam(w, start_x+10, start_y-5, 3),
	raamlijnx(w, start_x+7,start_y-5, start_x+13, start_y-5),
	raamlijny(w,start_x+10,start_y-2,start_x+10,start_y-8),
	raamx(w, start_x+14, start_y+12, start_x+18,start_y+12),
	raamy(w, start_x+16,start_y+10, start_x+14,start_y+15)
{}




void huis::print(){

   doos.print();
   lschuin.print();
   rschuin.print();
   deur.print();
   raam.print();
   dakraam.print();
   raamlijnx.print();
   raamlijny.print();
   raamx.print();
   raamy.print();
}