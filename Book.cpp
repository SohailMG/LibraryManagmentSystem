#include "Book.hpp"

Book::Book(std::string title, std::vector<std::string> authors, int ISBN, int quantity)
{
    this->title = title;
    this->authors = authors;
    this->ISBN = ISBN;
    this->quantity = quantity;
}
std::string Book::getTitle(){
    return Book::title;
}
int Book::getISBN(){
    return Book::ISBN;
}
int Book::getQuantity(){
    return Book::quantity;
}
std::vector<std::string> Book::getAuthors(){
    return Book::authors;
}