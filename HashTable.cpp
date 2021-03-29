#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>
#include "HashTable.hpp"

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

int HashTabel::hash_funtion(std::string key)
{

    int hash = 17;
    int index;
    for (size_t i = 0; i < key.length(); i++)
    {
        hash = hash + (int)key[i];
    }
    index = hash % TABEL_SIZE;

    return index;
}
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
        book = "Name :" + hashT[index]->getTitle() + "\n" + "ISBN :" + std::to_string(hashT[index]->getISBN());
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
            ptr = ptr->getNext();
        }
    }

    return book;
}
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
        Book *n = new Book;
        n->setTitle(V.getTitle());
        n->setISBN(V.getISBN());
        n->setQnty(V.getQuantity());
        n->setAuthors(V.getAuthors());
        n->setNext(NULL);
        while (ptr->getNext() != NULL)
        {
            ptr = ptr->getNext();
        }
        ptr->setNext(n);
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