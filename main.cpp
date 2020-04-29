#include <iostream>
#include <stdlib.h>
#include "Shop.h"

int main(int argc, char* argv[])
{
	//Sprawdzenie poprawnosci wywolania programu
	/*if(argc != 6)
	{
		std::cout<<"Niepoprawnie wprowadzone argumenty"<<std::endl;
	}
	else
	{*/
		//int number_of_philosophers = atoi(argv[1]);
		int number_of_customers = 10;
		int number_of_workers = 3;
		int number_of_checkouts = 5;
		int number_of_product_types = 15;
		int number_of_products = 15;

		//Otwarcie sklepu
		Shop shop(number_of_customers, number_of_workers, number_of_checkouts, number_of_product_types, number_of_products);
		shop.open();
	//}
	std::cout<<"Zakonczono main"<<std::endl;
	return 0;
}
