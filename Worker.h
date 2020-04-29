#ifndef WORKER_H
#define WORKER_H

#include "Menu.h"
#include "Product.h"
#include <vector>
#include <string>

class Worker
{
	public:
	Worker(int id, std::vector<Product> &products, Menu *menu);
	void* run();

	private:
	int id;
	std::string status;
	std::vector<Product>* products;
	Menu* menu;
	
	Product* check_products();
	void restock_product(Product* product);
	void random_wait();
};

#endif
