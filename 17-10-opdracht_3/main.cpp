#include "window.hpp"
#include "line.hpp"
#include "ball.hpp"
#include "muur.hpp"
#include "victim.hpp"
int main(){
	window w( vector( 128, 64 ), 2 );
	muur top(w, vector(0, 0), vector(127, 4), true, vector(1,-1),true);
    muur right(w, vector(123, 0), vector(127, 63), true,vector(-1,1), true);
    muur bottom(w, vector(0, 59), vector(127, 63), true,vector(1,-1), true);
	muur left(w, vector(0, 0), vector(4, 63), true, vector(-1,1), true);
	ball b( w, vector( 50, 20 ), 9, vector( 1, -5 ) );
	victim obj(w, vector(50, 40), vector(60, 58));
   
	drawable * objects[] = { &b, &top,&right,&bottom,&left, &obj };

	for(;;){
		w.clear();
		for( auto & p : objects ){
			p->draw();
		}
		wait_ms( 200 );
		for( auto & p : objects ){
			p->update();
		}
		for( auto & p : objects ){
			for( auto & other : objects ){
				p->interact( *other );
			} 
		}
	}
}

