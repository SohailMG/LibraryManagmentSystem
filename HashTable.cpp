#include <iostream>
#include <cstdlib>
#include <string>
#include <ostream>
#include <fstream>
#include <cstdio>
#include "HashTable.hpp"

/**
 * @brief Construct a new Hash Tabel:: Hash Tabel object
 * and initialises the current table values to empty or null
 * 
 */
HashTabel::HashTabel()
{
    std::vector<std::string> authors;
    for (size_t i = 0; i < HashTabel::TABEL_SIZE; i++)
    {
        hashT[i] = new Book;
        hashT[i]->setTitle("Empty");
        hashT[i]->setISBN(0);
        hashT[i]->setQnty(0);
        hashT[i]->setAuthors(authors);
        hashT[i]->setNext(NULL);
    }
}
/**
 * @brief takes a string as input and adds up the ASCI value
 * of each char in the string and returns the mod of the resutls
 * of deviding sum of ASCI values by table size
 * @param key title of book as string
 * @return int hash value
 */
int HashTabel::hash_funtion(std::string key)
{

    int hash = 21;
    int index;
    for (size_t i = 0; i < key.length(); i++)
    {
        hash = hash + (int)key[i];
    }
    index = hash % TABEL_SIZE;

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
std::string HashTabel::search(std::string title)
{
    int index = HashTabel::hash_funtion(title);
    Book *ptr = hashT[index];
    std::string book;
    if (ptr->getTitle() == "Empty")
    {
        std::cout << index << " Is Empty" << std::endl;
    }
    else if (hashT[index]->getTitle() == title)
    {
        book = "Name     : " + hashT[index]->getTitle() + "\n" +
               "ISBN     : " + std::to_string(hashT[index]->getISBN()) + "\n" +
               "Quantity : " + std::to_string(hashT[index]->getQuantity()) + "\n" +
               "------------------------------------------------------\n" +
               "Authors  :" + hashT[index]->showAuthors();

        return book;
    }
    else
    {
        while (ptr->getNext() != NULL)
        {
            if (ptr->getTitle() == title)
            {
                book =
                    "Name     : " + ptr->getTitle() + "\n" +
                    "ISBN     : " + std::to_string(ptr->getISBN()) + "\n" +
                    "Quantity : " + std::to_string(ptr->getQuantity()) + "\n" +
                    "Authors  : " + ptr->showAuthors();
                return book;
            }
            else
            {
                ptr = ptr->getNext();
            }
        }
    }

    return book;
}
/**
 * @brief 
 * 
 * @param V 
 */

void HashTabel::insert(Book V)
{

    std::string title = V.getTitle();

    int index = HashTabel::hash_funtion(title);
    if (hashT[index]->getTitle() == "Empty")
    {
        hashT[index]->setTitle(V.getTitle());
        hashT[index]->setISBN(V.getISBN());
        hashT[index]->setQnty(V.getQuantity());
        hashT[index]->setAuthors(V.getAuthors());
    }
    else
    {
        Book *ptr = hashT[index];
        Book *book = new Book;
        book->setTitle(V.getTitle());
        book->setISBN(V.getISBN());
        book->setQnty(V.getQuantity());
        book->setAuthors(V.getAuthors());
        book->setNext(NULL);

        while (ptr->getNext() != NULL)
        {
            ptr = ptr->getNext();
        }
        ptr->setNext(book);
    }
}
int HashTabel::getSize()
{
    return HashTabel::table->size();
}
void HashTabel::printTable()
{
    int nums;
    for (size_t i = 0; i < TABEL_SIZE; i++)
    {
        nums = numOfBooks(i);
        std::cout << "INDEX[" << i << "]  Has[" << nums << "]" << hashT[i]->getTitle() << std::endl;
    }
}
int HashTabel::numOfBooks(int index)
{
    int count = 0;
    if (hashT[index]->getTitle() == "Empty")
    {
        return count;
    }
    else
    {
        count++;
        Book *ptr = hashT[index];
        while (ptr->getNext() != NULL)
        {
            count++;
            std::cout << "SUB : " << ptr->getTitle() << std::endl;
            ptr = ptr->getNext();
        }
        return count;
    }
}

void HashTabel::remove_book(std::string title)
{
    int index = HashTabel::hash_funtion(title);

    Book *delete_ptr;
    Book *ptr1;
    Book *ptr2;

    if (hashT[index]->getTitle() == "Empty")
    {
        std::cout << title << " -  was not found" << std::endl;
    }
    else if (hashT[index]->getTitle() == title && hashT[index]->getNext() == NULL)
    {
        hashT[index]->setTitle("Empty");
        hashT[index]->setTitle("Empty");
        hashT[index]->setISBN(0);
        hashT[index]->setQnty(0);
        std::cout << "Title  : " << title << std::endl;
        std::cout << "Status : *Removed*" << std::endl;
    }
    else if (hashT[index]->getTitle() == title)
    {
        delete_ptr = hashT[index];
        hashT[index] = hashT[index]->getNext();
        delete delete_ptr;
        std::cout << "Title  : " << title << std::endl;
        std::cout << "Status : *Removed* " << std::endl;
    }
    else
    {
        // setting first pointer to point to the second book object
        ptr1 = hashT[index]->getNext();
        /* 
        setting second pointer to point to the first book object 
        and keep track of the previous book object
        */
        ptr2 = hashT[index];

        /* 
        keeps advancing first and second pointer by one book object 
        as long as first pointer is pointing to a book object
        and it does not find a match
        */
        while (ptr1 != NULL && ptr1->getTitle() != title)
        {

            ptr2 = ptr1;
            ptr1 = ptr1->getNext();
        }
        if (ptr1 == NULL)
        {
            std::cout << title << " Was not found" << std::endl;
        }
        else
        {
            /* 
            setting the deleting pointer to the matched book object 
            and setting first pointer to point to next item in the 
            linked list 
            */
            delete_ptr = ptr1;
            ptr1 = ptr1->getNext();

            // setting second pointer to point to the new item first pointer pointing to
            ptr2->setNext(ptr1);

            delete delete_ptr;
            std::cout << "Title  : " << title << std::endl;
            std::cout << "Status : *Removed* " << std::endl;
        }
    }
}