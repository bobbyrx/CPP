#include "Shop.h"
#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

void Shop::set_name(string name)
{
	this->name = name;
}

Shop::Shop()
{
	defalt.push_back(&defaltProduct); //For the delaft product, if we don't have any items.
}

Shop::Shop(const Shop& rhs)
{
	Store = rhs.Store;
	Users = rhs.Users;
	User_bag = rhs.User_bag;
}

Shop& Shop::operator=(const Shop& rhs)
{
	if (this != &rhs)
	{
		Store = rhs.Store;
		Users = rhs.Users;
		User_bag = rhs.User_bag;
	}
	return *this;
}

string Shop::get_name() const
{
	return name;
}

void Shop::add_items_to_store(Product& rhs)
{
	Store.push_back(&rhs);
}

void Shop::add_user(Client& rhs)
{
	bool if_exist = false;
	for (long i = 0;i < Users.size();i++)
	{
		if (Users[i].user_name==rhs.user_name)
		{
			if_exist = true;
			break;
		}
		else
		{
			continue;
		}
	}
	if (if_exist == true)
	{
		cout << "\n\n  Sorry, the user name [ "<<rhs.get_user_name()<<" ] is already taken!!!\n\n";
		return;
	}
	else
	{
		Users.push_back(rhs);
		User_bag.push_back(defalt);    //adding a defalt Shopping bag;
	}
}

void Shop::add_items_to_user(Product& item, Client& user)
{
	long user_num_bag=-1;	
	for (long i = 0;i < Users.size();i++)
	{
		if (Users[i] == user) 
		{
			user_num_bag = i;	//The place where the user is in Users.
			break;
		}
	}
	if (user_num_bag == -1)		//If the user is not found.
	{
		cout << "\n\n  Sorry, there isn't a user with a name ["<<user.get_user_name()<<"] on this website!!!\n\n";
		return;
	}
	else
	{
		bool if_product = false;
		for (long i = 0;i < Store.size();i++)
		{
			if (Store[i] == &item)
			{
				if_product = true;
				break;
			}
		}
		if (if_product == false)
		{
			cout << "\n\n  Sorry, no such item on this website!!!\n\n";
			return;
		}
		else
		{
			if (User_bag[user_num_bag][0] == &defaltProduct)
			{
				User_bag[user_num_bag].erase(User_bag[user_num_bag].begin()); //deleting a delaftProduct;
			}

			User_bag[user_num_bag].push_back(&item); //Adding the product to the user's shopping cart.
		}
	}
}

void Shop::del_items_from_user(Product& item, Client& user)
{
	long user_num_bag = -1;
	for (long i = 0;i < Users.size();i++)
	{
		if (Users[i] == user)
		{
			user_num_bag = i;	//The place where the user is in Users.
			break;
		}
	}
	if (user_num_bag == -1)	//If the user is not found.
	{
		cout << "\n\n  Sorry, there isn't a user with a name [" << user.get_user_name() << "] on this website!!!\n\n";
		return;
	}
	else
	{
		long productNum = -1;
		for (long i = 0; i < User_bag[user_num_bag].size(); i++)
		{
			if (User_bag[user_num_bag][i] == &item)
			{
				productNum = i;
				break;
			}
		}
		if (productNum == -1)
		{
			cout << "\n\n  Sorry, no such item in "<<user.get_user_name()<<"'s shopping bag!!!\n\n";
			return;
		}
		else
		{
			User_bag[user_num_bag].erase(User_bag[user_num_bag].begin() + productNum);
			//Deleting the product from the user's shopping cart.
		}
	}
}

void Shop::payment_user(Client& rhs)
{
	long user_num_bag = -1;
	for (long i = 0; i < Users.size(); i++)
	{
		if (Users[i] == rhs)
		{
			user_num_bag = i;	//The place where the user is in Users.
			break;
		}
	}
	if (user_num_bag == -1)	//If the user is not found.
	{
		cout << "\n\n  Sorry, there isn't a user with a name [" << rhs.get_user_name() << "] on this website!!!\n\n";
		return;
	}
	else
	{
		cout << "\n\n" <<this->get_name()<<" : "<< rhs.get_user_name(); 
		if (User_bag[user_num_bag].empty())
		{
			cout << "\n\n\tSorry, "<<rhs.get_user_name()<<"'s shopping bag is empthy!!!\n\n";
			return;
		}
		else
		{
			cout << " paying the following products:\n\n";                 //Prints all the products in a shopping bag and sums all their 											
			long double payment = 0;                                      //prices and prints how much the client must pay.
			for (long i = 0; i < User_bag[user_num_bag].size(); i++) //Also the bag becomes empty when the client pays it.
			{
				cout << i + 1 << "#"; User_bag[user_num_bag][i]->Print();
				payment += User_bag[user_num_bag][i]->get_price();
			}
			cout << "\n\n\tPRICE: " << payment << " lv.\n\n";
			User_bag[user_num_bag].clear();
		}
		cout << "  "<<rhs.get_user_name()<<"'s products will arrive after 2-3 days at " << rhs.get_address() << ".\n";
		cout << "  Thank you "<<rhs.get_user_name()<<" for your purchase!\n\n\n";
	}
}

void Shop::Print()
{
	cout << "\n\n\n\t" << get_name() << " information\n\n";
	for (long i = 0;i < Users.size();i++)
	{
		Users[i].Print();
		cout << "\n"<<Users[i].get_user_name()<<"'s shopping list:\n\n";
		if (User_bag[i].empty()||User_bag[i][0] == &defaltProduct) //Default here is an indicator that User_bag is empty.
		{
			cout << "!!! Empty !!!\n\n";
		}
		else
		{
			for (long j = 0; j < User_bag[i].size(); j++)
			{
				cout << j + 1 << "#"; User_bag[i][j]->Print(); //Printing every product one by one from the bags.
			}
			cout << "\n";
		}
	}
}


