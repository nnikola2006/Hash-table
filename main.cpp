#include <iostream>
#include <cstdlib>
#include <string>
#include "hash.h"
using std::cout, std::cin, std::endl;

int main(int argc, char** argv){
    Hash hashy;
    string name = "";

    hashy.addItem("Paul", "Locha");
	hashy.addItem("Kim", "Iced Mocha");
	hashy.addItem("Emma", "Strawberry Smoothie");
	hashy.addItem("Annie", "Hot Chocolate");
	hashy.addItem("Sarah", "Passion Tea");
	hashy.addItem("Pepper", "Caramel Mocha");
	hashy.addItem("Mike", "Chai Tea");
	hashy.addItem("Steve", "Apple Cider");
	hashy.addItem("Bill", "Root Beer");
	hashy.addItem("Marie", "Skinny Latte");
	hashy.addItem("Susan", "Water");
	hashy.addItem("Joe", "Green Tea");

    // hashy.printTable();
    // hashy.printItemsInIndex(9);

    // while(name != "exit"){
    //     cout << "Search for ";
    //     cin >> name;
    //     if(name != "exit"){
    //         hashy.findDrink(name);
    //     }
    // }

    // hashy.printTable(); used for case 1 and 2
    hashy.printItemsInIndex(2);

    while(name != "exit"){
        cout << "Remove ";
        cin >> name;
        if(name != "exit"){
            hashy.removeItem(name);
        }
    }

    // hashy.printTable(); Used for case 1 and 2
    hashy.printItemsInIndex(2);

    return 0;
}

