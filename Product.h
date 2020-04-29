#ifndef PRODUCT_H
#define PRODUCT_H

#include"Menu.h"

class Product
{
private:
	int id;
	Menu* menu;
	int amount;
	int max_amount;
	int price;

public:
	pthread_mutex_t mutexProduct = PTHREAD_MUTEX_INITIALIZER;
	pthread_cond_t condProduct = PTHREAD_COND_INITIALIZER;
	
	Product(int id, int number_of_products, Menu *menu);
	int get_id();
	int get_amount();
	int get_price();
	int get_max_amount();
	bool set_amount(int amount);
};

#endif
