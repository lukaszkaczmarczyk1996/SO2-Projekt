#ifndef CHECKOUT_H
#define CHECKOUT_H

#include"Menu.h"
#include<string>

class Checkout
{
private:
	int id;
	Menu* menu;
	std::string status;
	int cash;

public:
	pthread_mutex_t mutexCheckout = PTHREAD_MUTEX_INITIALIZER;

	Checkout(int id, Menu *menu);
	int get_id();
	int get_cash();
	void add_cash(int value);
};

#endif
