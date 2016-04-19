#ifndef HUIS_HPP
#define HUIS_HPP

#include "window.hpp"
#include "line.hpp"
#include "fillrectangle.hpp"
#include "rectangle.hpp"
#include "circle.hpp"


class huis {
private:

   //window & w;
	rectangle doos; 		//geraamte huis
   fillrectangle deur;					// deur van huis
   
   line lschuin, rschuin; //dak
   
   rectangle raam;
   circle dakraam;
    line raamlijnx;
	line raamlijny;
	line  raamx;
	line raamy;

public:
   huis( window & w, int start_x, int start_y, int end_x, int end_y );
   void print();
};


#endif // HUIS_HPP