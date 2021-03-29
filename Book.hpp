
#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>
#include <vector>
/**
 * @brief Books class that holds all objects of a book including
 * title,authors,ISBN and quantity
 * CREATED : 27/03/2021
 * 
 */
class Book
{
    // declaring private class memebers
private:
    std::string title;
    std::vector<std::string> authors;
    int ISBN, quantity;
    Book *next;

public:
    Book();
    // book class contructure
    Book(std::string title, std::vector<std::string> authors, int ISBN, int quantity);
    std::string getTitle();
    std::vector<std::string> getAuthors();
    int getISBN();
    int getQuantity();

    Book* getNext();
    void setNext(Book *next);
    void setAuthors(std::vector<std::string> authors);
    void setQnty(int quantity);
    void setISBN(int ISBN);
    void setTitle(std::string title);
};

#endif
