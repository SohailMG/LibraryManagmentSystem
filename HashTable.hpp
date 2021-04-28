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
 * UPDATED :  27/04/2021  
*/

class Hash
{
private:
    int table_size;
    // pointer to book pointers
    Book **table;

public:
    /**
     * @brief Construct a new Hash Tabel:: Hash Tabel object
     * and initialises the current table values to  nullptr
     * @param size table size
     */
    Hash(int size);
    // DESTRUCTURE
    ~Hash();
    /**
    * @brief Construct a new Hash Tabel:: Hash Tabel object
    * and initialises the current table values to  nullptr
    * @param size table size
    */
    unsigned hash_title(std::string key);
    /**
    * @brief takes title as input, gets the hash value of the input
    * declares pointer of the first book object in the table.
    * uses the hash value as index to access table element
    * if the first elm is not equal to title it will update
    * the pointer to the next elm and compares it
    * @param title string title of book
    * @return std::string of book details
    */
    Book search(std::string title);
    /**
    * @brief gets the index value of the title of the passed
    * book object, checks if the index of the table is empty
    * or nullptr, then it will override that index with the new 
    * book object, otherwise it will make the first item of that cell
    * point to the new item using chaining.
    * @param book book object being added
    */
    void insert(Book V);
    /**
    * @brief removes a book from the table by getting the index of the title
    * of the book being removed.checks if the index of the table book being removed.
    * @param title std::string title of book being removed
    */
    void remove_book(std::string title);
    /**
    * @brief gets the hash value of the book title being added
    * checks the index of the table and compares it's elements with
    * the title for a match preventing doublicate keys
    * @param title 
    * @return true - if the new show title matching an exisiting book 
    * @return false  - if there is no match found
    */
    bool check_dublicates(std::string title);
};

#endif
