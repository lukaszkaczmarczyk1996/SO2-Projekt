#include "Product.h"
#include <iostream>

Product::Product(int id, int number_of_products, Menu *menu)
{
	this->menu = menu;
	this->id = id;
	this->amount = number_of_products;
	this->max_amount = number_of_products;
	this->price = 10;

	//Wyswietlenie poczatkowego stanu produktów
	//menu->updateProduct(this->id,this->amount);
}

int Product::get_id()
{
	return this->id;		
}

int Product::get_amount()
{
	return this->amount;		
}

int Product::get_max_amount()
{
	return this->max_amount;		
}

int Product::get_price()
{
	return this->price;		
}

bool Product::set_amount(int amount)
{
	//Jezeli wartosc poprawna
	if(amount <= this->max_amount && amount >= 0)
	{
		this->amount = amount;
		//Wyswietlenie stanu productu
		menu->updateProduct(this->id,this->amount);
		return true;
	}
	return false;
}
