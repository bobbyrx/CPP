#include <iostream>
#include <cstring>
#include "ProductShoes.h"
#include <string>

using namespace std;

ProductShoes::ProductShoes()
{
	Product:set_variant(shoes);
}

string ProductShoes::getBrand() const
{
	return brand;
}

string ProductShoes::getColor() const
{
	return color;
}

void ProductShoes::setWholeShoes(long double price, string color, string brand)
{
	Product:set_price(price);
	this->color = color;
	this->brand=brand;
}

void ProductShoes::Print() const
{
	cout << "\n\tPrinting the product info\n";
	cout << "\tPrice: " << get_price() << " lv.\n";
	cout << "\tIDtag: " << get_IDtag() << "\n";
	cout << "\tType: ";
	switch (variant)
	{
	case book:cout << "Book\n";
		break;
	case shoes:cout << "Shoes\n";
		break;
	case phone:cout << "Phone\n";
		break;
	default: cout << " \n";
		break;
	}
	cout << "\tBrand: " << getBrand() << "\n";
	cout << "\tColor: " << getColor() << "\n";
}
