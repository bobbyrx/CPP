#include <iostream>
#include <cstring>
#include "Product.h"
#include <string>
#pragma once

using namespace std;

class ProductBook: public Product
{
private:
	long numPages;
	string title;
public:
	ProductBook();
	string getTitle()const;
	long getNumPages()const;
	void setWholeBook(long double price, string name, long Pages);
	virtual void Print()const;
};