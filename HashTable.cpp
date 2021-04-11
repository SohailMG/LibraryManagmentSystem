#include <iostream>
#include <cstdlib>
#include <string>
#include <ostream>
#include <fstream>
#include <cstdio>
#include "HashTable.hpp"
/**
 * HashTable.cpp
 * AUTHOR  :  M00716650
 * CREATED :  27/03/2021
 * UPDATED :  16/04/2021  
 * 
 */
/**
 * 
 * @brief Construct a new Hash Tabel:: Hash Tabel object
 * and initialises the current table values to  nullptr
 * @param size table size
 * 
 */
Hash::Hash(int size)
{   
    // setting the size of the table
    this->table_size = size;
    // initialsing an array of book pointer
    table = new Book *[table_size];
    // initialising each table index to nullptr
    for (size_t i = 0; i < this->table_size; i++)
    {
        table[i] = nullptr;
    }
}
// destructure
Hash::~Hash()
{
    delete[] this->table;
    this->table = NULL;
}
/**
 * @brief takes a string as input and adds up the ASCI value
 * of each char in the string and returns the mod of the resutls
 * of deviding sum of ASCI values by table size
 * @param key title of book as string
 * @return int hash value
 */
unsigned long Hash::hash_funtion(std::string key)
{

    int hash = 21;
    unsigned long index;
    for (size_t i = 0; i < key.length(); i++)
    {
        hash = hash + (int)key[i];
    }
    index = hash % table_size;

    return index;
}
/**
 * @brief takes title as input, gets the hash value of the input
 * declares pointer of the first book object in the table.
 * uses the hash value as index to access table element
 * if the first elm is not equal to title it will update
 * the pointer to the next elm and compares it
 * @param title string title of book
 * @return std::string of book details
 */

Book Hash::search(std::string title)
{
    // storing the index value of the given book title
    unsigned long index = Hash::hash_funtion(title);
    // pointer pointing to the first elm in the linked list
    Book *book_ptr = table[index];
    Book book;
    // checking if the first elm of the table cell has the default

    if (book_ptr == nullptr)
    {
        return book;
    }
    else if (table[index]->getTitle() == title)
    {
        book = *table[index];

        return book;
    }
    else
    {
        bool title_found = false;
        while (book_ptr != nullptr && title_found == false)
        {
            if (book_ptr->getTitle() == title)
            {
                book = *book_ptr;
                title_found = true;
                return book;
            }
            else
            {
                book_ptr = book_ptr->getNext();
            }
        }
    }

    return book;
}
/**
 * @brief gets the index value of the title of the passed
 * book object, checks if the index of the table is empty
 * or nullptr, then it will override that index with the new 
 * book object, otherwise it will make the first item of that cell
 * point to the new item using chaining.
 * @param book book object being added
 */
void Hash::insert(Book book)
{

    std::string title = book.getTitle();
    // getting the hash value of the book title being added
    unsigned long index = Hash::hash_funtion(title);
    // checking if the index of the table cell is empty
    if (table[index] == nullptr)
    {
        // overriding the current cell with new book data
        table[index] = new Book;
        table[index]->setTitle(book.getTitle());
        table[index]->setISBN(book.getISBN());
        table[index]->setQnty(book.getQuantity());
        table[index]->setAuthors(book.getAuthors());
        table[index]->setNext(nullptr);
    }
    // when index already has a book object stored
    else
    {
        // making pointer to point to the first book object in the table cell
        Book *ptr = table[index];
        // pointer pointing to new book object
        Book *bookptr = new Book;
        // setting new values of book added
        bookptr->setTitle(book.getTitle());
        bookptr->setISBN(book.getISBN());
        bookptr->setQnty(book.getQuantity());
        bookptr->setAuthors(book.getAuthors());
        // making new book to point to the end of the linked list
        bookptr->setNext(nullptr);

        // making the new book pointer to point to the end of the linked list
        while (ptr->getNext() != nullptr)
        {
            ptr = ptr->getNext();
        }
        ptr->setNext(bookptr);
    }
}

/**
 * @brief removes a book from the table by getting the index of the title
 * of the book being removed.checks if the index of the table book being removed.
 * @param title std::string title of book being removed
 */
void Hash::remove_book(std::string title)
{
    unsigned long index = Hash::hash_funtion(title);

    // delcaring pointer to point to the book being removed
    Book *delete_ptr;
    // declaring two pointers to iterate through the linked list and maintain the order
    Book *ptr1;
    Book *ptr2;

    // first condition - checking if the index has no books
    if (table[index] == nullptr)
    {
        std::cout << title << " -  was not found" << std::endl;
    }
    // second condition - checking if first index matches given title and there are no other books
    else if (table[index]->getTitle() == title && table[index]->getNext() == nullptr)
    {
        if (table[index]->getQuantity() > 0)
        {
            table[index]->setQnty(table[index]->getQuantity() - 1);
            std::cout << "Title            : " << table[index]->getTitle() << std::endl;
            std::cout << "Copies Remaining : " << table[index]->getQuantity() << std::endl;
        }
        else
        {
            table[index]->setTitle("Empty");
            std::cout << "\nTitle  : " << title << std::endl;
            std::cout << "Status : *Removed*" << std::endl;
        }
    }
    // third condition - checking if match is found but there are other books in the linked list
    else if (table[index]->getTitle() == title)
    {
        if (table[index]->getQuantity() > 0)
        {
            table[index]->setQnty(table[index]->getQuantity() - 1);
            std::cout << "Title            : " << table[index]->getTitle() << std::endl;
            std::cout << "Copies Remaining : " << table[index]->getQuantity() << std::endl;
        }
        else
        {
            delete_ptr = table[index];
            table[index] = table[index]->getNext();
            std::cout << table[index]->getQuantity();
            delete delete_ptr;
            std::cout << "\nTitle  : " << title << std::endl;
            std::cout << "Status : *Removed* " << std::endl;
        }
    }
    // final condition - checking when first index has no match but there are other books in the linked list
    else
    {
        // setting first pointer to point to the second book object
        ptr1 = table[index]->getNext();
        /* 
        setting second pointer to point to the first book object 
        and keep track of the previous book object
        */
        ptr2 = table[index];

        /* 
        keeps advancing first and second pointer by one book object 
        as long as first pointer is pointing to a book object
        and it does not find a match
        */
        while (ptr1 != nullptr && ptr1->getTitle() != title)
        {

            ptr2 = ptr1;
            ptr1 = ptr1->getNext();
        }
        if (ptr1 == nullptr)
        {
            std::cout << title << " - Was not found" << std::endl;
        }
        else
        {
            /* 
            setting the deleting pointer to the matched book object 
            and setting first pointer to point to next item in the 
            linked list 
            */
            delete_ptr = ptr1;
            if (delete_ptr->getQuantity() > 0)
            {
                delete_ptr->setQnty(delete_ptr->getQuantity() - 1);
                std::cout << "Title            : " << delete_ptr->getTitle() << std::endl;
                std::cout << "Copies Remaining : " << delete_ptr->getQuantity() << std::endl;
            }
            else
            {
                ptr1 = ptr1->getNext();

                // setting second pointer to point to the new item first pointer pointing to
                ptr2->setNext(ptr1);

                delete delete_ptr;
                std::cout << "\nTitle  : " << title << std::endl;
                std::cout << "Status : *Removed* " << std::endl;
            }
        }
    }
}
/**
 * @brief gets the hash value of the book title being added
 * checks the index of the table and compares it's elements with
 * the title for a match preventing doublicate keys
 * @param title 
 * @return true - if the new show title matching an exisiting book 
 * @return false  - if there is no match found
 */
bool Hash::check_dublicates(std::string title)
{
    // storing the index value of the given book title
    unsigned long index = Hash::hash_funtion(title);
    //
    Book *ptr = table[index];
    bool exists = false;
    // checking if the first elm of the table cell has the default
    if (ptr == nullptr)
    {
        exists = false;
    }
    else if (table[index]->getTitle() == title)
    {

        exists = true;
    }
    else
    {
        bool title_found = false;
        while (ptr != nullptr && title_found == false)
        {
            if (ptr->getTitle() == title)
            {
                title_found = true;
                exists = true;
            }
            else
            {
                ptr = ptr->getNext();
            }
            if (ptr == nullptr)
            {
                exists = false;
            }
        }
    }

    return exists;
}