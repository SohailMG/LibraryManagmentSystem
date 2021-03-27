
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
    private:
    std::string title;
    std::vector<std::string> authors;
    int ISBN,quantity;
    public:
    Book(){
      
    }
    Book(std::string title,std::vector<std::string> authors,int ISBN,int quantity){
      this->title = title;
      this->authors = authors;
      this->ISBN = ISBN;
      this->quantity = quantity;

    }
    std::string getTitle(){
      return title;
    }
    std::vector<std::string> getAuthors(){
      return authors;
    }
    int getISBN(){
      return ISBN;
    }
    int getQuantity(){
      return quantity;
    }

};

#endif
