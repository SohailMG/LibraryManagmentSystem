#include <iostream>
#include <cstdlib>
#include <string>
#include <ostream>
#include<fstream>
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
        book = "Name :" + hashT[index]->getTitle();
        return book;
    }
    else
    {
        while (ptr->getNext() != NULL)
        {
            if (ptr->getTitle() == title)
            {
                book = "Name :" + ptr->getTitle() + "\n" + "ISBN :" + std::to_string(ptr->getISBN());
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