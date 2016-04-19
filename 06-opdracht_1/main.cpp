// template

#include <iostream>

#include "window.hpp"
#include "line.hpp"
#include "rectangle.hpp"
#include "fillrectangle.hpp"
#include "circle.hpp"
#include "huis.hpp"
#include "straat.hpp"


int main(int argc, char **argv){
   window w( 128, 64, 2 );
   
   //line diagonal_line( w, 5, 5, 30, 40 );
   //diagonal_line.print();
   
   //rectangle box( w, 60, 10, 50, 20 );
   //box.print();
   
   //circle ball( w, 70, 30, 20 );
   //ball.print();
   
   //fillrectangle boxe( w, 20, 20, 40, 40 );
   //boxe.print();
   
   
   for(int i = 0; i <=4; i++){
	   straat roos (w, 5, 20, 25,40 , i );
	   roos.print();
	   for(int j = 0; j <=155555555; j++){
		   int a =0;
	   }
	   //w.clear();
   }
   /*
   
   int z= 3;
   straat roos (w, 5, 40, 25,60 , z );
	roos.print();
  */
   
   //huis osso( w, 5, 40, 25,60  );
   //huis osso1( w, 30, 40, 50,60  );
  // huis osso2( w, 55, 40, 75,60  );
  // huis osso3( w, 80, 40, 100,60  );
  // huis osso4( w, 105, 40, 125,60  );
   //osso.print();
   //osso1.print();
   //osso2.print();
   //osso3.print();
   //osso4.print();
   return 0;
}
