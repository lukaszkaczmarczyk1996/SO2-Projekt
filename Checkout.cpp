#include "Checkout.h"
#include <iostream>

Checkout::Checkout(int id, Menu *menu)
{
	this->id = id;
	//Przypisanie tabeli wyswietlajacej wyniki
	this->menu = menu;
	this->status = "free";
	this->cash = 0;

	//Wyswietlenie poczatkowego stanu kas
	//menu->updateCheckout(this->id, this->cash);
}

int Checkout::get_id()
{
	return this->id;
}

int Checkout::get_cash()
{
	return this->cash;
}

void Checkout::add_cash(int value)
{
	this->cash = this->cash + value;
	menu->updateCheckout(this->id, this->cash);
}
