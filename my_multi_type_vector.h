#ifndef MY_MULTI_TYPE_VECTOR_H
#define MY_MULTI_TYPE_VECTOR_H

#include <iostream>
#include <vector>
#include <string>

class Aux
{
	 protected:
		  virtual void print( std::ostream& os ) const = 0;
	 public:
		  friend std::ostream&
		  operator<< ( std::ostream& os, const Aux& a )
			   {			   
				    a.print ( os );
					return os;
			   }
};

template < typename T >
class AuxTemp : public Aux
{	private:
		  T* real_obj;
	 public:
		  AuxTemp ( const T& obj ) : real_obj ( new T ( obj ) ) { }
		  ~AuxTemp ( ) { delete real_obj; }
		  void print ( std::ostream& os ) const override
			   {
					os << *real_obj;
			   }
};

class MyVector
{
	 private:
		  std::vector <	Aux* > v;
		  public:
		  template < typename T > void Add ( const T& value )
			   {
					v.push_back( new AuxTemp < T > ( value ) );
			   }

		  friend std::ostream&
		  operator<< ( std::ostream& os, const MyVector& mV )
			   {
					for ( auto& element : mV.v )
					{
						 os << *element << std::endl;
					}
					return os;
			   }
};

#endif
