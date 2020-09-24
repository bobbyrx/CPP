#pragma once
#include <iostream>
#include <cstring>

using namespace std;

static long IDproduct = 1;

enum Type { book, shoes, phone }; //Categories.

class Product //Making an abstract class it's subclasses are ProductBook, ProductShoes and ProductPhone 
{
protected:
	long double price;
	long IDtag;     //A unique indicator for a product.
	Type variant;  //The category of the product.

	void set_variant(Type product);
	void set_price(long double price);

public:

	Product();

	bool operator==(const Product& rhs);
	
	Type get_variant()const;
	long double get_price()const;
	long get_IDtag()const;
	
	virtual void Print()const=0;//the pure virtual function
};