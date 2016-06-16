#include "vector.hpp"
//#include "ostream"
#include "catch_with_main.hpp"


TEST_CASE( "constructor 2  parameters" ){
   vector v( 3, 4 );
   REQUIRE( v == vector( 3, 4 ) );   
   
}

TEST_CASE( "operator +" ){
   vector v( 3, 4 );
   vector x( 5, 4 );
   vector y = v + x;
   REQUIRE( v == vector( 3, 4 ) );   
   REQUIRE( x == vector( 5, 4 ) );   
   REQUIRE( y == vector(8, 8 ) );   
}

TEST_CASE( "operator +=" ){
   vector v( 3, 4 );
   v+= vector( 9, 7 );
   REQUIRE( v == vector( 12, 11 ) );     
}

TEST_CASE( "operator -" ){
   vector v( 6, 4 );
   vector x( 3, 4 );
   vector y = v - x;
   REQUIRE( v == vector( 6, 4 ) );   
   REQUIRE( y == vector( 3, 0 ) );   
}

TEST_CASE( "operator -=" ){
   vector v( 12, 8 );
   v-= vector( 9, 7 );
   REQUIRE( v == vector( 3, 1 ) );    
}

TEST_CASE( "operator *" ){
	vector v( 3, 4 );
   vector y =  v * 5;
   REQUIRE( v == vector( 3, 4 ) );   
	REQUIRE( y == vector( 15, 20));  
}

TEST_CASE( "operator *=" ){
   vector v( 3, 4 );
   REQUIRE( v == vector( 3, 4 ) );  
    v *= 7;
   REQUIRE( v == vector( 21, 28 ) );   
}

TEST_CASE( "operator /" ){
   vector v( 3, 12 );
   REQUIRE 	(v == vector( 3, 12 ));
   vector y = v / 3;
   REQUIRE( y == vector( 1, 4 ) );   
 
}

TEST_CASE( "operator /=" ){
   vector v( 10, 8 );
   REQUIRE( v == vector( 10, 8 ));
   v /= 2;
   REQUIRE( v == vector( 5, 4 ) );   
   
}



