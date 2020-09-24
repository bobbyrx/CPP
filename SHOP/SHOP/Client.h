#pragma once
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

static long IDclient = 1;

enum Type_g { Male,Female,Other };

class Client
{
private:

	long IDuser;	   //A unique ID number for the user.
	Type_g gender;    //The gender of the user.
	string user_name;
	string passwd;
	string email;
	string address;

public:

	Client();
	
	bool operator==(Client& rhs);	

	string get_user_name()const;
	string get_passwd()const;
	string get_email()const;
	string get_address()const;
	Type_g get_gender()const;

	void set_whole_client(string user_name, string passwd, string email, string address, Type_g sex);
	void Print()const;

	friend class Shop;	//Inorder the class Shop to have access to the protected functions of the Client class.
};