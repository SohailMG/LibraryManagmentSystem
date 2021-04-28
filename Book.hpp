
#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>
#include <vector>
/**
 * @brief Books class that holds all objects of a book including
 * title,authors,ISBN and quantity
 * 
 * Book.hpp
 * AUTHOR  :  M00716650
 * CREATED :  27/03/2021
 * UPDATED :  27/04/2021 
 * 
 */
class Book
{
    // declaring private class memebers
private:
    std::string title;
    std::vector<std::string> authors;
    unsigned long ISBN;
    int quantity;
    Book *next;

public:
    Book();
    // book class contructure
    Book(std::string title, std::vector<std::string> authors, unsigned long ISBN, int quantity);
    //getters
    std::string getTitle();
    std::vector<std::string> getAuthors();
    unsigned long getISBN();
    int getQuantity();
    Book *getNext();
    /**
    * @brief loops through vector of authors 
    * and adds them to a string
    * @return std::string of authors 
    */
    std::string showAuthors();

    //setters
    void setNext(Book *next);
    void setAuthors(std::vector<std::string> authors);
    void setQnty(int quantity);
    void setISBN(unsigned long ISBN);
    void setTitle(std::string title);
    /**
    * @brief overloading the output stream to print out the 
    * book object if the book object d
    * 
    * @param out output stream being displayed in the console
    * @param b refrence to the book object
    * @return std::ostream& 
    */
    friend std::ostream &operator<<(std::ostream &strm, Book &b);
};

#endif
