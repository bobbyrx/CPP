#include <iostream>
#include <cstring>
#include <string>
#include "Client.h" 

using namespace std;

Client::Client():IDuser(IDclient)
{
	IDclient++;
}

bool Client::operator==(Client& rhs)
{
	if (IDuser == rhs.IDuser
		&&user_name==rhs.user_name
		&&passwd==rhs.passwd
		&&email==rhs.email
		&&address==rhs.address
		&&gender==rhs.get_gender()
	   )return true;

	else return false;
}

void Client::set_whole_client(string user_name, string passwd, string email, string address, Type_g sex)
{
	this->user_name = user_name;
	this->passwd = passwd;
	this->email = email;
	this->address = address;
	this->gender = sex;
}

string Client::get_user_name() const
{
	return user_name;
}

string Client::get_passwd() const
{
	return passwd;
}

string Client::get_email() const
{
	return email;
}

string Client::get_address() const
{
	return address;
}


Type_g Client::get_gender() const
{
	return gender;
}

void Client::Print() const
{
	cout << "User name: " << get_user_name()<< endl;
	cout << "Password: " << get_passwd() << endl;
	cout << "Email: " << get_email()<<endl;
	cout << "Address: " << get_address() << endl;
	cout << "ID user: " << IDuser << endl;
	cout << "Gender: ";
	switch (gender)
	{
	case Male:cout << "Male \n";
		break;
	case Female:cout << "Female \n";
		break;
	case Other:cout << "Other \n";
		break;
	default: cout << "\n";
		break;
	}
}


