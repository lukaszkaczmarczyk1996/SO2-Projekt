#include "Customer.h"
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <ctime>


Customer::Customer(int id, std::vector<Product> &products, std::vector<Checkout> &checkouts, Menu *menu)
{
	//Inicjalizacja
	srand(time(NULL));
	this->id = id;
	this->products = &products;
	this->checkouts = &checkouts;
	this->status = "going in";

	//Przypisanie tabeli wyswietlajacej wyniki
	this->menu = menu;	

	//Aktualizacja wyswietlanego stanu klienta
	//menu->updateCustomer(this->id, this->status, -1);
}

//Czynnosci klienta
void* Customer::run()
{
	//Czas na wejscie
	random_wait();
	
	//Do momentu przerwania pracy przez obiekt tabeli stanow
	while(menu->work)
	{
		//Utworzenie listy zakupow
		std::vector<Product*> shopping_list = rand_shopping_list();
		int total_cost = 0;

		for(int i=0; i<shopping_list.size(); i++)
		{
			//Klient bierze produkt
			pthread_mutex_lock(&shopping_list.at(i)->mutexProduct);

			//Jezeli nie ma juz produktu na polce
			if(shopping_list.at(i)->set_amount(shopping_list.at(i)->get_amount() - 1) == false)
			{
				this->status="waiting for product";
				menu->updateCustomer(this->id, this->status, shopping_list.at(i)->get_id());

				//Oczekiwanie na sygnal od pracownika o uzupelnieniu produktu
				pthread_cond_wait(&shopping_list.at(i)->condProduct, &shopping_list.at(i)->mutexProduct);
			}
			
			//Zabranie produktu z polki
			total_cost += shopping_list.at(i)->get_price();
			this->status = "taking product";
			menu->updateCustomer(this->id, this->status, shopping_list.at(i)->get_id());
			random_wait();
			pthread_mutex_unlock(&shopping_list.at(i)->mutexProduct);
		}
		
		//Placenie za zakupy
		pay(total_cost);
	}
	
	//Wyjscie ze sklepu
	this->status = "going out";
	menu->updateCustomer(this->id, this->status, -1);
	random_wait();

	//Zakonczenie watku
	pthread_exit(0);
}

//Losowy czas czynnosci
void Customer::random_wait()
{
	int duration = 1000000;
	int min_time = 2000000;
	int time = (std::rand()% duration)+min_time;
	usleep(time);
}

//Zwraca liste zakupow
std::vector<Product*> Customer::rand_shopping_list()
{
	//Losowanie ile produktow klient chce kupic
	int random_number_of_products = (std::rand()% this->products->size()) + 1;
	std::vector<Product*> shopping_list;

	//Losowanie jakiego rodzaju produkty klient chce kupic
	for(int i=0; i<random_number_of_products; i++)
	{
		Product* product = &this->products->at(std::rand()% this->products->size());
		shopping_list.push_back(product);
	}
	return shopping_list;
}

//Placenie za zakupy
void Customer::pay(int total_cost)
{
	//Cykliczne przeszukiwanie kas do momentu zaplacenia
	while(true)
	{

		//Sprawadzanie aktualnego stanu kas
		for(int i=0; i<checkouts->size(); i++)
		{
			//Jezeli kasa jest zajeta
			if(pthread_mutex_trylock(&checkouts->at(i).mutexCheckout) != 0)
			{
				//Sprawdzenie następnej kasy
				continue;
			}
			
			//Znaleziono wolna kase
			this->status = "paying at the checkout ";
			menu->updateCustomer(this->id, this->status, checkouts->at(i).get_id());
			random_wait();
		
			//Zaplacenie oraz przerwanie petli
			checkouts->at(i).add_cash(total_cost);
			pthread_mutex_unlock(&checkouts->at(i).mutexCheckout);
			return;
		}

		//Nieznaleziono wolnej kasy
		this->status = "waiting for checkout";
		menu->updateCustomer(this->id, this->status, -1);
		random_wait();		
	}
}


