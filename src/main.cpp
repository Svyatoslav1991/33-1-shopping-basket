#include <iostream>
#include "onlinestore.h"

int main() {
	std::cout << "\tTASK 31.1 SHOPPING BASKET\n\n";

    try {
        OnlineStore myStore;

        myStore.addItemToStore("aaa", 10);
        myStore.addItemToStore("bbb", 5);
        myStore.addItemToStore("ccc", 8);
        myStore.addItemToStore("aaa", 5);

        std::cout << "Initial state of the store:\n";
        myStore.printDataBase();
        std::cout << "Initial state of the basket:\n";
        myStore.printBasket();

        std::cout << "\n--------------------------------------------\n";

        myStore.add("aaa", 3);
        myStore.add("bbb", 2);
        myStore.add("ccc", 8);
        myStore.add("aaa", 4);  

        std::cout << "State of the store:\n";
        myStore.printDataBase();
        std::cout << "State of the basket:\n";
        myStore.printBasket();

        std::cout << "\n--------------------------------------------\n";

        myStore.remove("aaa", 3);
        myStore.remove("bbb", 1);
        myStore.remove("ccc", 4);
        myStore.add("aaa", 5); 


        std::cout << "Finish state of the store:\n";
        myStore.printDataBase();

        std::cout << "Finish state of the basket:\n";
        myStore.printBasket();
    }
    catch (const std::invalid_argument& e) 
    {
        std::cerr << "Invalid argument exception: " << e.what() << "\n";
    }
    catch (const std::exception& e) 
    {
        std::cerr << "Exception: " << e.what() << "\n";
    }
    catch (...) 
    {
        std::cerr << "Something went wrong\n";
    }

	return 0;
}