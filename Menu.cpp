#include "Menu.h"

using namespace std;


Menu::Menu()
{

}

//Rozpoczecie watku tabelki stanow
void* Menu::start()
{
	//Inicjalizacja
	keypad(mainWindow, true);
	int c ;
	while(true)
	{	
		//Zakoncz prace watkow po nacisnieciu ESC
		c = wgetch(mainWindow);
		if(c==27)
		{
			this->work = false;
			break;
		}
	}
	//Zakoncz watek
	std::cout<<"Shop is closed";
	pthread_exit(0);
}

/*
//Utworzenie tabeli stanow
void Menu::create(int philNumber)
{
	int xMax = 0;
	int yMax = 0;
	//Wartosc wciecia wiersza
	int m = 2;
	
	//Przeskalowanie okna terminala wzgledem ilosci filozofow
	std::string comm = "resize -s " + std::to_string(philNumber+8) + " 93 > /dev/null";
	char const *command = comm.c_str();
	system(command);
	//Inicjalizacja
	initscr();
	//Pobranie maksymalnych wymiarow konsoli
	getmaxyx(stdscr, yMax, xMax);
	cbreak();
	noecho();
	//Ustawienie rozmiarow okna
	yWin = philNumber+6;
	xWin = xMax -4;
	
	//Ustawienie kolorow
	start_color();
	assume_default_colors(COLOR_BLACK, COLOR_WHITE);
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	
	//Utworzenie glownego okna
	mainWindow = newwin(yWin, xWin, 1,2);
	wbkgd(mainWindow,COLOR_PAIR(1));

	//Utworzenie ramek tabeli
	mvwhline(mainWindow, 2, 0, '_',xWin);
	mvwvline(mainWindow, 0, (xWin/5)-m, '|',yWin);
	mvwvline(mainWindow, 0, (2*(xWin/5))-m, '|',yWin);
	mvwvline(mainWindow, 0, (3*(xWin/5))-m, '|',yWin);
	mvwvline(mainWindow, 0, (4*(xWin/5))-m, '|',yWin);
	box(mainWindow, 0, 0);
	
	//Utworzenie naglowkow tabeli
	mvwprintw(mainWindow, 1,1+m, "%s", " Filozof:");
	mvwprintw(mainWindow, 1,(xWin/5)+m, "%s", "Czynnosc:");
	mvwprintw(mainWindow, 1,(2*(xWin/5))+m, "%s", " Licznik:");
	mvwprintw(mainWindow, 1,(3*(xWin/5))+m, "%s", " Widelec:");
	mvwprintw(mainWindow, 1,(4*(xWin)/5)+m, "%s", "Wlasciciel:");

	refresh();
	wrefresh(mainWindow);
}
*/

//Wyswietlenie stanu klienta
void Menu::updateCustomer(int id, std::string status, int resource_id)
{		
		if(resource_id == -1)
		{
			std::cout<<"Customer "<<id<<" is "<<status<<std::endl;
		}
		else
		{
			std::cout<<"Customer "<<id<<" is "<<status<<" "<<resource_id<<std::endl;
		}

		/*int m = 3;
		//Wyswietlenie id oraz czynnosci filozofa
		mvwprintw(mainWindow, id+4, 1+m, "   %d   ", id);
		//Jezeli filozof je
		if(status==1)
		{	clrtoeol();
			wattron(mainWindow, COLOR_PAIR(2));
			mvwprintw(mainWindow, id+4, (xWin/5)+m, "%s", "  je  ");
			wattroff(mainWindow, COLOR_PAIR(2));
		}
		//Jezeli filozof mysli
		if(status==0)
		{
			clrtoeol();
			wattron(mainWindow, COLOR_PAIR(4));
			mvwprintw(mainWindow, id+4, (xWin/5)+m, "%s", " mysli ");
			wattroff(mainWindow, COLOR_PAIR(4));		
		}
		//Jezeli filozof zakonczyl uczte
		if(status==-1)
		{
			clrtoeol();
			wattron(mainWindow, COLOR_PAIR(3));
			mvwprintw(mainWindow, id+4, (xWin/5)+m, "%s", " koniec");
			wattroff(mainWindow, COLOR_PAIR(3));		
		}
		mvwprintw(mainWindow, id+4, (2*(xWin/5))+m , "   %d   ", counter);
		wrefresh(mainWindow);
		*/
}

//Wyswietlenie stanu pracownika
void Menu::updateWorker(int id, std::string status, int resource_id)
{		
		if(resource_id == -1)
		{
			std::cout<<"Worker "<<id<<" is "<<status<<std::endl;
		}

		else
		{
			std::cout<<"Worker "<<id<<" is "<<status<<" "<<resource_id<<std::endl;
		}
		/*int m = 3;
		//Wyswietlenie id oraz czynnosci filozofa
		mvwprintw(mainWindow, id+4, 1+m, "   %d   ", id);
		//Jezeli filozof je
		if(status==1)
		{	clrtoeol();
			wattron(mainWindow, COLOR_PAIR(2));
			mvwprintw(mainWindow, id+4, (xWin/5)+m, "%s", "  je  ");
			wattroff(mainWindow, COLOR_PAIR(2));
		}
		//Jezeli filozof mysli
		if(status==0)
		{
			clrtoeol();
			wattron(mainWindow, COLOR_PAIR(4));
			mvwprintw(mainWindow, id+4, (xWin/5)+m, "%s", " mysli ");
			wattroff(mainWindow, COLOR_PAIR(4));		
		}
		//Jezeli filozof zakonczyl uczte
		if(status==-1)
		{
			clrtoeol();
			wattron(mainWindow, COLOR_PAIR(3));
			mvwprintw(mainWindow, id+4, (xWin/5)+m, "%s", " koniec");
			wattroff(mainWindow, COLOR_PAIR(3));		
		}
		mvwprintw(mainWindow, id+4, (2*(xWin/5))+m , "   %d   ", counter);
		wrefresh(mainWindow);
		*/
}

//Wyswietlenie stanu produktu
void Menu::updateProduct(int id, int amount)
{
		std::cout<<"Product "<<id<<" : "<<amount<<" left "<<std::endl;

		/*
		int m = 3;
		//Wyswietlenie id oraz stanu widelca
		mvwprintw(mainWindow, id+4, (3*(xWin/5))+m, "   %d   ", id);
		//Jezeli widelec jest podniesiony
		if(status==1)
		{	clrtoeol();
			wattron(mainWindow, COLOR_PAIR(4));
			mvwprintw(mainWindow, id+4, (4*(xWin)/5)+m, "   %d  ", owner);
			wattroff(mainWindow, COLOR_PAIR(4));
		}
		//Jezeli widelec jest wolny
		if(status==0)
		{
			clrtoeol();
			wattron(mainWindow, COLOR_PAIR(2));
			mvwprintw(mainWindow, id+4, (4*(xWin)/5)+m, "%s", " wolny");	
			wattroff(mainWindow, COLOR_PAIR(2));	
		}	
		wrefresh(mainWindow);
		*/
}

//Wyswietlenie stanu kasy
void Menu::updateCheckout(int id, int cash)
{	
		std::cout<<"Checkout "<<id<<" : "<<cash<<" $"<<std::endl;

		/*
		int m = 3;
		//Wyswietlenie id oraz stanu widelca
		mvwprintw(mainWindow, id+4, (3*(xWin/5))+m, "   %d   ", id);
		//Jezeli widelec jest podniesiony
		if(status==1)
		{	clrtoeol();
			wattron(mainWindow, COLOR_PAIR(4));
			mvwprintw(mainWindow, id+4, (4*(xWin)/5)+m, "   %d  ", owner);
			wattroff(mainWindow, COLOR_PAIR(4));
		}
		//Jezeli widelec jest wolny
		if(status==0)
		{
			clrtoeol();
			wattron(mainWindow, COLOR_PAIR(2));
			mvwprintw(mainWindow, id+4, (4*(xWin)/5)+m, "%s", " wolny");	
			wattroff(mainWindow, COLOR_PAIR(2));	
		}	
		wrefresh(mainWindow);
		*/
}

void Menu::closeMenu()
{
	endwin();
}
