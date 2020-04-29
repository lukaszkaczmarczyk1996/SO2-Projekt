#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Menu.h"
#include <string>
#include "Product.h"
#include "Checkout.h"
#include <vector>

class Customer
{
	public:
	Customer(int id, std::vector<Product> &products, std::vector<Checkout> &checkouts, Menu *menu);
	void* run();

	private:
	int id;
	std::string status;
	std::vector<Product>* products;
	std::vector<Checkout>* checkouts;
	Menu* menu;
	
	void pay(int total_cost);
	void random_wait();
	std::vector<Product*> rand_shopping_list();
};

#endif
