#include <iostream>
#include <cstring>
#include "Product.h"
#include "Client.h"
#include "Shop.h"
#include "ProductBook.h"
#include "ProductShoes.h"
#include "ProductPhone.h"
#include <string>
#include <vector>

using namespace std;

int main()
{
    ProductBook book;
	book.setWholeBook(25.99, "Game of thrones", 457);
	ProductShoes shoes;
	shoes.setWholeShoes(79.99, "Blue", "Adidas");
	ProductPhone phone;
	phone.setWholePhone(689.90, "Galaxy", "Samsung", 5.5);

	Client Bobby, Phobis, Alisa;
	Bobby.set_whole_client("Bobbyrx", "borislavhr", "bobbyrx19@gmail.com", "Svoboda N17",Male);
	Phobis.set_whole_client("Malaka", "12345", "phobis@gmail.com", "Greece N2", Other);
    Alisa.set_whole_client("Alis", "blackcanary123", "black_canary@gmail.com", "Sofia studentski grad blok N51", Female);

	Shop emag;
	emag.set_name("Emag");
	
	emag.add_items_to_store(book);
	emag.add_items_to_store(phone);
	emag.add_items_to_store(shoes);
	
	emag.add_user(Bobby);
	emag.add_user(Phobis);
	emag.add_user(Alisa);

	emag.add_items_to_user(book, Bobby);
	emag.add_items_to_user(phone, Bobby);
	emag.add_items_to_user(shoes, Bobby);
	emag.add_items_to_user(book, Alisa);
	emag.add_items_to_user(phone, Alisa);
	emag.add_items_to_user(shoes, Phobis);
	emag.Print();

	emag.payment_user(Alisa);
	emag.del_items_from_user(phone, Bobby);
	emag.Print();
	emag.add_user(Phobis);

	Shop amazon;
	amazon.set_name("Amazon");
	amazon = emag;
	amazon.Print();

	return 0;
}