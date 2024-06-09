/* 
 * File: hash.h
 * Author: Dzonex
 * 
 * Has a private variable table_size that tells how many indexes are
 * available in the hash table
 * Constructor creates a linked list at every index in the HashTable ptr
 * hash function returns a index of our data by passing in a key
 * 
 * Created on June 9, 2024, 6:46 PM
*/

#include <string>
using std::string;

#ifndef HASH_H
#define HASH_H

class Hash{
private:
    static const int table_size = 4;
    
    struct Item{
        string name;
        string drink;
        Item* next;
    };
    Item* HashTable[table_size];

public:
    Hash();
    int hash(string key);
    void addItem(string name, string drink);
    int numberOfItemsInIndex(int index);
    void printTable();
    void printItemsInIndex(int index);
    void findDrink(string name);
    void removeItem(string name);
};

#endif /* HASH_H */