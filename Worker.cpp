#include "Worker.h"
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <ctime>


Worker::Worker(int id, std::vector<Product> &products, Menu *menu)
{
	//Inicjalizacja
	srand(time(NULL));
	this->id = id;
	this->status = "waiting";
	this->products = &products;
	//Przypisanie tabeli wyswietlajacej wyniki
	this->menu = menu;

	//Aktualizacja wyswietlanego pracownika
	//menu->updateWorker(this->id, this->status, -1);
}

//Czynnosci pracownika
void* Worker::run()
{
	//Do momentu przerwania pracy przez obiekt tabeli stanow
	while(menu->work)
	{
		//Sprawdzenie oraz uzupelnienie produktow
		Product* product = check_products();
		if(product != NULL) {
			restock_product(product);
		}
		//Przerwa
		this->status = "waiting";
		menu->updateWorker(this->id, this->status, -1);
		random_wait();
	}
	
	//Aktualizacja tabeli stanow po zakmnięciu sklepu

	this->status = "finishing job";
	menu->updateWorker(this->id, this->status, -1);
	random_wait();

	//Zakonczenie watku
	pthread_exit(0);

}

//Losowy czas czynnosci
void Worker::random_wait()
{
	int duration = 1000000;
	int min_time = 2000000;
	int time = (std::rand()% duration)+min_time;
	usleep(time);
}

//Sprawdzenie polek przez pracownika
Product* Worker::check_products()
{	
	for(int i=0; i<this->products->size(); i++)
	{
		Product* p = &products->at(i);
		//Zablokowanie zasobow produktu
		pthread_mutex_lock(&p->mutexProduct);
		//Jezeli jakis produkt wymaga uzupelnienia
		if(p->get_amount() < p->get_max_amount())
		{
			return p;
		}
		pthread_mutex_unlock(&p->mutexProduct);
	}
	//Zaden produkt nie wymaga uzupelnienia
	return NULL;
}

//Uzupelnienie produtu
void Worker::restock_product(Product* product)
{		

		//Uzupelnienie produktu
		product->set_amount(product->get_max_amount());

		//Zmiana i aktualizacja statusu
		this->status = "restoring";
		menu->updateWorker(this->id, this->status, product->get_id());
		random_wait();

		//Wysłanie sygnału do klientow, ze produkt zostal uzupelniony
		pthread_cond_broadcast(&product->condProduct);

		//Odblokowanie zasobow produktu
		pthread_mutex_unlock(&product->mutexProduct);
}
