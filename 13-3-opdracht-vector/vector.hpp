#ifndef VECTOR_HPP
#define VECTOR_HPP
#include "ostream"
/// @file

/// vector ADT
//
/// this is based on a vector
class vector {
private:

   
   
public:
int x;
   int y;
   /// constructor from explicit values
   //
   /// maakt een vector aan met x en y waardes gezet
   vector( int x = 0, int y = 0 ):
   
   
     x( x ), y( y )
	 {}
		
	



   /// output operator for a vector value
   //
	/// deze vector print een vector in tekst uit 
  friend std::ostream & operator<<( std::ostream & lhs, vector pos ){
		lhs << "(" << pos.x << "," << pos.y << ")";
		return lhs;
	}
   
   
   /// vector == vect0r
   //
   ///vergelijkt 2 vectoren
    bool operator==( const vector & rhs ) const {
		return (x == rhs.x && y == rhs.y);
   }
   
     ///vector + vector
   //
   /// telt een vector op bij een andere vector
   vector operator+( const vector & rhs ) const {
      return vector( x + rhs.x, y + rhs.y );
   }
   
     ///vector += vector
   //
   ///telt een vector bij een vector de linker vector wordt het resultaat
   
   vector operator+=( const vector & rhs )  {
	   x += rhs.x;
	   y+= rhs.y;
      return *this;
   }
   
     ///vector - vector
   //
   ///trek 2 vectoren van elkaar af
    vector operator-( const vector & rhs ) const {
      return vector( x - rhs.x, y - rhs.y );
   }
   
   
     ///vector -= vector
   //
   ///trekt 2 vectoren van elkaar af en slaat het resultaat op in de linker vector
   vector operator-=( const vector & rhs )  {
	   x -= rhs.x;
	   y -= rhs.y;
      return *this;
   }
	
	  ///vector * int
   //
   ///vermenigd een vector met een getal
   vector operator*( const int & rhs ) const {
      return vector( x * rhs, y*rhs);
   }
   /*
   vector operator*( const int & z ,const vector & rhs ) const {
      return vector( rhs.x * z, rhs.y * z);
   }*/
   
     ///vector *= int
   //
   ///vermenigdvuldigd vector met int en slaat resultaat op in dezelfde vector
   vector operator*=( const int & rhs )  {
	   x *= rhs;
	   y *= rhs;
      return *this;
	  
   } 
     ///vector / int
   //
   ///deelt een vector door een getal 
	  vector operator/( const int & rhs ) const {
      return vector(x / rhs, y / rhs);
   }
   
	  /// vector /= int
   //
   ///deelt een vector door een int en slaat het resultaat op in dezelfde vector
   vector operator/=( const int & rhs )  {
	   x /= rhs;
	   y /= rhs;
      return *this;
   }
   
   };
   


#endif