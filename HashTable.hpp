#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
#include "Book.hpp"
#include <string>
#include <vector>
/**
 * HashTable.hpp
 * AUTHOR  :  M00716650
 * CREATED :  27/03/2021
 * UPDATED :  16/04/2021  
*/


class Hash
{
private:
     static const int TABEL_SIZE = 271;
     int ll_size;
    //  std::vector<Book> *table;
     Book* hashT[TABEL_SIZE];

public:
    Hash();
    
    unsigned long hash_funtion(std::string key);
    Book search(std::string title);
    void insert(Book V);
    void remove_book(std::string title);
    bool check_dublicates(std::string title);
};

#endif
