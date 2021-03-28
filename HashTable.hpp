#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
#include "Book.hpp"
#include <string>
#include<list>


// template <typename K, typename V>
class HashTabel
{
private:
     static const int TABEL_SIZE = 10;

public:
    HashTabel();
     std::list<Book>hashT[TABEL_SIZE];
    int hash_funtion(std::string key);
    int getHashT();
    void insert(int Key,Book V);
};

#endif