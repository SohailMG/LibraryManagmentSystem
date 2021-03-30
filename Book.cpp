#include "Book.hpp"

Book::Book(){
    
}
Book::Book(std::string title, std::vector<std::string> authors, unsigned long ISBN, int quantity)
{
    this->title = title;
    this->authors = authors;
    this->ISBN = ISBN;
    this->quantity = quantity;
}
std::string Book::getTitle()
{
    return this->title;
}
unsigned long Book::getISBN()
{
    return this->ISBN;
}
int Book::getQuantity()
{
    return this->quantity;
}
std::vector<std::string> Book::getAuthors()
{

    return this->authors;
}

void Book::setTitle(std::string title)
{
    this->title = title;
}
void Book::setISBN(unsigned long ISBN)
{
    this->ISBN = ISBN;
}
void Book::setQnty(int quantity)
{
    this->quantity = quantity;
}
void Book::setAuthors(std::vector<std::string> authors)
{
    this->authors = authors;
}
void Book::setNext(Book *next)
{
    this->next = next;
}
Book* Book::getNext(){
    return this->next;
}
std::string Book::showAuthors(){
    std::string authorsList;
    for (size_t i = 0; i < this->authors.size(); i++)
    {
            
        authorsList = authorsList + "[" + std::to_string(i + 1)+"] - " +  this->authors.at(i)  + "\n\t  ";
        
    }
    return authorsList;
}
