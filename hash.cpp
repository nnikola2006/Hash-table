#include <iostream>
#include <string>
#include "hash.h"
using std::cout, std::endl, std::string;

// Creates a linked list for every index in the HashTable
Hash::Hash(){
    for(size_t i = 0; i < table_size; i++){
        HashTable[i] = new Item;
        HashTable[i]->name = "empty";
        HashTable[i]->drink = "empty";
        HashTable[i]->next = nullptr;
    }
}

// Returns a index where our data will be stored by passing in a key
int Hash::hash(string key){
    int hash = 0;
    int index;

    // Gets the sum of all of the characters from a key as ASCII values
    for(size_t i = 0; i < key.length(); i++){
        hash = (hash + static_cast<int>(key[i])) * 17; // (int)key[i] also works
    }

    // Gets the index of our data in the hash table
    index = hash % table_size;
    
    // Prints out they ASCII values for each character of the key
    // cout << "key[0] = " << static_cast<int>(key[0]) << endl; // (int)key[0] also works but this is a C++ feature, 
    // cout << "key[0] = " << static_cast<int>(key[1]) << endl; // you must use (int)key[1] if it's C
    // cout << "key[0] = " << static_cast<int>(key[2]) << endl;
    // cout << "key[0] = " << static_cast<int>(key[3]) << endl;    

    return index;
}

// Adds a item to the HashTable
void Hash::addItem(string name, string drink){
    // Gets the index of the key(name)
    int index = hash(name);

    if(HashTable[index]->name == "empty"){
        // If the name is empty set the values
        HashTable[index]->name = name;
        HashTable[index]->drink = drink;
    }
    else{
        // If it's not empty it creates a new Item
        // index_ptr points to the beginning of the linked list for
        // that index in the HashTable
        Item* index_ptr = HashTable[index];
        Item* newHashTable = new Item;
         
        // Sets the values 
        newHashTable->name = name;
        newHashTable->drink = drink;
        newHashTable->next = nullptr;

        // Loops the index_ptr ptr until it points to the last Item
        // and then points the index_ptr->next to the new Item
        while(index_ptr->next != nullptr){
            index_ptr = index_ptr->next;
        }
        index_ptr->next = newHashTable;
    }
}

// Returns the number of items in the index
int Hash::numberOfItemsInIndex(int index){
    int count = 0;

    // If the index is empty returns 0
    if(HashTable[index]->name == "empty"){
        return count;
    }
    else{
        count++;
        Item* index_ptr = HashTable[index];

        // Increments the index_ptr until it gets to the end
        while(index_ptr->next != nullptr){
            count++;
            index_ptr = index_ptr->next;
        }
    }

    return count;
}

// Prints only the 1st Item in the HashTable
void Hash::printTable(){
    int number;
    
    for(size_t i = 0; i < table_size; i++){
        number = numberOfItemsInIndex(i);

        cout << "--------------------\n";
        cout << "index = " << i << endl;
        cout << "Name: " << HashTable[i]->name << endl;
        cout << "Drink: " << HashTable[i]->drink << endl;
        cout << "# of items = " << number << endl;
        cout << "--------------------\n"; 
    }
}

// Prints all the Items inside a index
void Hash::printItemsInIndex(int index){
    Item* index_ptr = HashTable[index];

    if(index_ptr->name == "empty"){
        // If the index is empty
        cout << "index = " << index << " is empty";
    }
    else{
        // If the index has some items
        cout << "index " << index << " contains the following item\n";
         
        while(index_ptr != nullptr){
            cout << "--------------------\n";
            cout << "Name: " << index_ptr->name << endl;
            cout << "Drink: " << index_ptr->drink << endl;
            cout << "--------------------\n";
            index_ptr = index_ptr->next;
        }
    }
    
}

// Returns the drink with the correct name (key)
void Hash::findDrink(string name){
    int index = hash(name);
    bool foundName = false;
    string drink;

    // Loops until it finds the drink if possible
    Item* index_ptr = HashTable[index];
    while(index_ptr != nullptr){
        if(index_ptr->name == name){
            foundName = true;
            drink = index_ptr->drink;
        }
        index_ptr = index_ptr->next;
    }

    if(foundName == true){
        cout << "Favorite drink = " << drink << endl;
    }
    else{
        cout << name << "'s info was not found in the Hash Table" << endl;
    }
}

void Hash::removeItem(string name){
    int index = hash(name);

    // Case 0 - Bucket is empty
    if(HashTable[index]->name == "empty" && HashTable[index]->drink == "empty"){
        cout << name << " was not found in the Hash Table" << endl;
    }

    // Case 1 - Only 1 item contained in bucket and that item has a matching name
    else if(HashTable[index]->name == name && HashTable[index]->next == nullptr){
        HashTable[index]->name = "empty";
        HashTable[index]->drink = "empty";
        
        cout << name << " was removed from the Hash Table" << endl;
    }

    // Case 2 - Match is located in the first item in the bucket but there are more items in the bucket
    else if(HashTable[index]->name == name){
        Item* del_ptr = HashTable[index];
        HashTable[index] = HashTable[index]->next;
        delete del_ptr;
        del_ptr = nullptr;

        cout << name << " was removed from the Hash Table" << endl;
    }

    // Case 3 - Bucket contains items but first item is not a match
    else{
        Item* next = HashTable[index]->next;
        Item* prev = HashTable[index];
        Item* del_ptr = nullptr;

        while(next != nullptr && next->name != name){
            prev = next;
            next = next->next;
        }

        // Case 3.1 - No items have a match
        if(next == nullptr){
            cout << name << " was removed from the Hash Table" << endl;
        }

        // Case 3.2 - Additional items have a match
        else{
            del_ptr = next;
            next = next->next;
            prev->next = next;

            delete del_ptr;
            del_ptr = nullptr;
            cout << name << " was removed from the Hash Table" << endl;
        }
    }
    
    
}