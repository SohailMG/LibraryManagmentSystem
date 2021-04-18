#include "Book.hpp"
/**
 * Book.cpp
 * AUTHOR  :  M00716650
 * CREATED :  27/03/2021
 * UPDATED :  16/04/2021  
 * */
Book::Book(){
    
}
/**
 * @brief Construct a new Book:: Book object
 * 
 * @param title of book of type std::string
 * @param authors vector of authors of type std::string
 * @param ISBN  an unsigned long integer
 * @param quantity number of book copies of type int
 */
Book::Book(std::string title, std::vector<std::string> authors, unsigned long ISBN, int quantity)
{
    this->title = title;
    this->authors = authors;
    this->ISBN = ISBN;
    this->quantity = quantity;
}
// GETTERS
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

// SETTERS
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
/**
 * @brief loops through vector of authors and adds them to a string
 * 
 * @return std::string of authors 
 */
std::string Book::showAuthors(){
    std::string authorsList;
    for (size_t i = 0; i < this->authors.size(); i++)
    {
            
        authorsList += 
        " [" + std::to_string(i + 1)+"] - " 
        +  this->authors.at(i)  + "\n\t   ";
        
    }
    return authorsList;
}
/**
 * @brief overloading the output stream to print out the 
 * book object if the book object d
 * 
 * @param out output stream being displayed in the console
 * @param b refrence to the book object
 * @return std::ostream& 
 */
 std::ostream& operator<<(std::ostream &out, Book &b){
    
     
    if (b.title != "")
    {
    out << "Title     : " << b.getTitle()    << "\n"
        << "ISBN      : " << b.getISBN()     << "\n"
        << "Quantity  : " << b.getQuantity() << "\n"
        <<"------------------------------------------------------\n"
        << "Author(s) :" << b.showAuthors() << std::endl;

    }else out << " Book Not found";
    return out;
}
