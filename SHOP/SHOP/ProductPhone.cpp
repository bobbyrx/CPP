#include <iostream>
#include <cstring>
#include "ProductPhone.h"
#include <string>

using namespace std;

ProductPhone::ProductPhone()
{
	Product:set_variant(phone);
	sizeScreen = 0;
}

string ProductPhone::getBrand() const
{
	return brand;
}

string ProductPhone::getModel() const
{
	return model;
}

long double ProductPhone::getSizeScreen()const
{
	return sizeScreen;
}

void ProductPhone::setWholePhone(long double price, string model, string brand,long double sizeScr)
{
	Product:set_price(price);
	this->model = model;
	this->brand = brand;
	sizeScreen = sizeScr;
}

void ProductPhone::Print() const
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
	cout << "\tModel: " << getModel() << "\n";
	cout << "\tScreen size: " << getSizeScreen() << " inches\n";
}
