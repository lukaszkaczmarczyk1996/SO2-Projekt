#ifndef MENU_H
#define MENU_H

#include<iostream>
#include<ncurses.h>
#include <vector>
#include<mutex>
#include<string>

//#include "Philosopher.h"

class Menu
{
private:	
	WINDOW * mainWindow;
	//WINDOW * philWindow;
public:
	Menu();
	void* start();
	void updateCustomer(int id, std::string status, int resource_id);
	void updateWorker(int id, std::string status, int resource_id);
	void updateProduct(int id, int amount);
	void updateCheckout(int id, int cash);
	/*
	int xWin, yWin;
	void create(int philNumber);
	void updatePhilosopher(int id, int status, int counter);
	void updateFork(int id, int status, int owner);
	std::mutex window_lock_m;
	*/
	void closeMenu();
	bool work = true;
	
};
#endif
