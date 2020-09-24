#include <iostream>
#include <cstring>
#include "Product.h"
#include <string>
#pragma once

using namespace std;

class ProductShoes : public Product
{
private:
	string color;
	string brand;
public:
	ProductShoes();
	string getColor()const;
	string getBrand()const;
	void setWholeShoes(long double price, string color, string brand);
	virtual void Print()const;
};