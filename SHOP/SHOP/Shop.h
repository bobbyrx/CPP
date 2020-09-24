#pragma once
#include <iostream>
#include <cstring>
#include "Client.h"
#include "Product.h"
#include "ProductBook.h"
#include <vector>
#include <string>

using namespace std;

class Shop
{
private:

	string name;		//The name of the Store.
	
	vector<Product*> Store;		//The products the store has to offer.
	//Array of pointers		   //Note that the users can only buy products that are on the specific web site.
					          //A user cant't buy products that are not on the web shop.
	
	vector<Client> Users;		//Users in the web shop.
	
	vector<vector<Product*>> User_bag;		//The shopping bag of each user. It can have more than one product!!!
	
	ProductBook defaltProduct;     //When creating an empty user's bag I add this product as a default object.
	vector<Product*> defalt;      //Creating user's bag and push this default array in User_bag array. 

public:
	Shop();
	Shop(const Shop& rhs);                //Coping every thig except the name.
	Shop& operator=(const Shop& rhs);    //Same here.
	
	string get_name()const;
	void set_name(string name);

	void add_items_to_store(Product& rhs);	//Getting more products in the shop for the users to choose.
	
	void add_user(Client& rhs);	//The same function as registration. Just adding more users on the platform.
	
	void add_items_to_user(Product& item, Client& user);		//Adding a specific product to a specific user's shopping bag.
																  //Note that if the product or the user are not found on the web site
																 //it will display a proper message.
	void del_items_from_user(Product& item, Client& user);		//The same as add_items_to_user but it deletes it.
	
	void payment_user(Client& rhs);	//Displays the client's products in the shopping bag, sums their prices 
								   //and prints how much the user has to pay.
								  //Note that after this action the user's shopping bag will be empty.
	void Print();

};