

#include "stoepgrid.hpp"

stoepgrid::stoepgrid( window & w, int start_x, int start_y, int end_x, int end_y ):
/*
	 osso0( w, 5, 40, 25,60  ),
	 osso1( w, 30, 40, 50,60  ),
	 osso2( w, 55, 40, 75,60  ),
	 osso3( w, 80, 40, 100,60  ),
	 osso4( w, 105, 40, 125,60  ),
*/	 
	 a( w, start_x, start_y+30, start_x+5, start_y+25  ),
	 b( w, start_x+10, start_y+30, start_x+15,start_y+25 ),
	 c( w, start_x+20, start_y+30, start_x+25, start_y+25  ),
	 d( w, start_x+30, start_y+30, start_x+35, start_y+25  ),
	 e( w, start_x+40, start_y+30, start_x+45, start_y+25  ),
	 f( w, start_x+50, start_y+30, start_x+55, start_y+25  ),
	 g( w, start_x+60, start_y+30, start_x+65, start_y+25  ),
	 h( w, start_x+70, start_y+30, start_x+75, start_y+25  ),
	 i( w, start_x+80, start_y+30, start_x+85, start_y+25  ),
	 j( w, start_x+90, start_y+30, start_x+95, start_y+25  ),
	 k( w, start_x+100, start_y+30, start_x+105, start_y+25  ),
	 l( w, start_x+110, start_y+30, start_x+115, start_y+25  ),
	 m( w, start_x+120, start_y+30, start_x+120, start_y+25  )

  
{}

void stoepgrid::print(){
	a.print();
	b.print();
	c.print();
	d.print();
	e.print();
	f.print();
	g.print();
	h.print();
	i.print();
	j.print();
	
	k.print();
	l.print();
	m.print();
	
}