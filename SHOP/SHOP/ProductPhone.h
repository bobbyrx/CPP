#include <iostream>
#include <cstring>
#include "Product.h"
#include <string>
#pragma once

using namespace std;

class ProductPhone : public Product
{
private:
	string model;
	string brand;
	long double sizeScreen;
public:
	ProductPhone();
	string getModel()const;
	string getBrand()const;
	long double getSizeScreen()const;
	void setWholePhone(long double price, string model, string brand,long double sizeScr);
	virtual void Print()const;
};

