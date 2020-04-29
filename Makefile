all:
	g++ main.cpp Shop.cpp Menu.cpp Customer.cpp Worker.cpp Checkout.cpp Product.cpp -lncurses -pthread -lncurses -std=c++11 -o main
