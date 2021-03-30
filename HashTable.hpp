#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
#include "Book.hpp"
#include <string>
#include<list>
#include<vector>


// template <typename K, typename V>
class HashTabel
{
private:
     static const int TABEL_SIZE = 517;
     int ll_size;
     std::vector<Book> *table;
     Book* hashT[TABEL_SIZE];

public:
    HashTabel();
    int hash_funtion(std::string key);
    std::string search(std::string title);
    void insert(Book V);
    int getSize();
    void printTable();
    int numOfBooks(int index);
};

#endif