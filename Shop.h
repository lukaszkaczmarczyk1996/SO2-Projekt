#ifndef SHOP_H
#define SHOP_H

#include <vector>
#include "Customer.h"
#include "Worker.h"
#include "Checkout.h"
#include "Product.h"

#include "Menu.h"

class Shop
{
private:
	Menu* menu;
	static void* menu_helper(void* arg);

	static void* customer_run_helper(void* arg);
	static void* worker_run_helper(void* arg);

	std::vector<Customer> customers;
	void create_customers(int number_of_workers);
	std::vector<Worker> workers;
	void create_workers(int number_of_workers);
	std::vector<Checkout> checkouts;
	void create_checkouts(int number_of_checkouts);
	std::vector<Product> products;
	void create_products(int number_of_product_types, int number_of_products);

public:
	Shop(int number_of_customers, int number_of_workers, int number_of_checkouts, int number_of_product_types, int number_of_products);
	void open();
};

#endif
