#ifndef STOEPGRID_HPP
#define STOEPGRID_HPP

#include "window.hpp"
#include "line.hpp"



class stoepgrid {
private:


  
   
   line a;
   line b;
   line c;
   line d;
   line e;
   line f;
   line g;
   line h;
   line i;
   line j;
   line k;
   line l;
   line m;
   
    

public:
   stoepgrid( window & w, int start_x, int start_y, int end_x, int end_y);
   //aantal (aantal)
   //{}
   void print();
   
};


#endif //STOEPGRID_HPP