#include <iostream>
#include <cstring>
#include "ProductBook.h"
#include <string>

using namespace std;

ProductBook::ProductBook()
{
	Product:set_variant(book);
	numPages = 0;
}

string ProductBook::getTitle() const
{
	return title;
}

long ProductBook::getNumPages() const
{
	return numPages;
}

void ProductBook::setWholeBook(long double price,string name, long Pages)
{
    Product:set_price(price);
	title = name;
	numPages = Pages;
}

void ProductBook::Print() const
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
	cout << "\tTitle: " << getTitle() << "\n";
	cout << "\tNumber of pages: " << getNumPages() << "\n";
}
