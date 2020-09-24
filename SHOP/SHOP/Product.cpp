#pragma once
#include <iostream>
#include <cstring>
#include "Product.h"
using namespace std;

Product::Product():IDtag(IDproduct),price(0)
{
	IDproduct++; //Inorder each product to have a unique ID number.
}

bool Product::operator==(const Product& rhs)
{
	if (IDtag == rhs.IDtag)return true;
	else return false;
}

void Product::set_variant(Type product)
{
	this->variant = product;
}

Type Product::get_variant() const
{
	return variant;
}

void Product::set_price(long double price)
{
	this->price = price;
}

long double Product::get_price() const
{
	return price;
}

long Product::get_IDtag() const
{
	return IDtag;
}



