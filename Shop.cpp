#include "Shop.h"
#include <pthread.h>
#include <iostream>
#include <unistd.h>

Shop::Shop(int number_of_customers, int number_of_workers, int number_of_checkouts, int number_of_product_types, int number_of_products)
{

	//Utworzenie tabeli wyświetlajacej stan watkow
	menu = new Menu();
	//menu->create(number_of_philosophers);

	//Utworzenie obiektow klientow, pracownikow, kas i produktow
	create_checkouts(number_of_checkouts);
	create_products(number_of_product_types, number_of_products);
	create_customers(number_of_customers);
	create_workers(number_of_workers);
}


//Funckja zwracajaca funkcje do wykonania z obiektu klienta
void* Shop::customer_run_helper(void * arg)
{
	return ((Customer*) arg)->run();
}

//Funckja zwracajaca funkcje do wykonania z obiektu pracownika
void* Shop::worker_run_helper(void * arg)
{
	return ((Worker*) arg)->run();
}

//Funckja zwracajaca funkcje do wykonania z obiektu tabeli stanow
void* Shop::menu_helper(void * arg)
{
	return ((Menu*) arg)->start();
}

void Shop::open()
{
	std::cout<<"Shop is open"<<std::endl;

	//Utworzenie watkow klientow
	int num_of_thr = customers.size() + workers.size();
	pthread_t thread_id[num_of_thr];

	for (int i=0; i<customers.size();i++)
	{
		pthread_create(&thread_id[i], NULL, &Shop::customer_run_helper, &customers.at(i));

	}

	//Utworzenie watkow pracownikow
	for (int i=0; i<workers.size();i++)
	{
		pthread_create(&thread_id[customers.size() + i], NULL, &Shop::worker_run_helper, &workers.at(i));
	}

	//Watek wyswietlajacy tabele stanow watkow
	pthread_t menu_thread_id;
	pthread_create(&menu_thread_id, NULL, &Shop::menu_helper, menu);
	
	//Oczekiwanie na zakonczenie wszystkich watkow filozofow
	for(int i=0; i<num_of_thr; i++)
	{
	pthread_join(thread_id[i], NULL);
	}
	
	//Zamkniecie tabeli wyswietlajacej watki
	//menu->closeMenu();
}


//Tworzenie obiektow klientow
void Shop::create_customers(int number_of_customers)
{
	for(int i=0; i<number_of_customers; i++)
	{	
		Customer* customer = new Customer(i, this->products, this->checkouts, menu);
		customers.push_back(*customer);		
	}
}

//Tworzenie obiektow pracownikow
void Shop::create_workers(int number_of_workers)
{
	for(int i=0; i<number_of_workers; i++)
	{	
		Worker* worker = new Worker(i, this->products, menu);
		workers.push_back(*worker);	
	}
}

//Tworzenie obiektow kas
void Shop::create_checkouts(int number_of_checkouts)
{
	for(int i=0; i<number_of_checkouts; i++)
	{	
		Checkout* checkout = new Checkout(i, menu);
		checkouts.push_back(*checkout);	
	}
}

//Tworzenie obiektow produktow
void Shop::create_products(int number_of_product_types, int number_of_products)
{
	for(int i=0; i<number_of_product_types; i++)
	{	
		Product* product = new Product(i, number_of_products, menu);
		products.push_back(*product);
	}
}

