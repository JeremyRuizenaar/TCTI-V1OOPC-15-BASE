#ifndef STRAAT_HPP
#define STRAAT_HPP

#include "window.hpp"
#include "line.hpp"
#include "fillrectangle.hpp"

#include "huis.hpp"
#include "stoepgrid.hpp"



class straat {
private:


   huis osso0;
   huis osso1;
   huis osso2;
   huis osso3;
   huis osso4;
   
   fillrectangle weg;
   line stoep;
   stoepgrid grid;
   stoepgrid grid2;
   int aantal;
    

public:
   straat( window & w, int start_x, int start_y, int end_x, int end_y , int aantal);
   //aantal (aantal)
   //{}
   void print();
   
};


#endif //STRAAT_HPP