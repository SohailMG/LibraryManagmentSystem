#include "Book.hpp"
#include "HashTable.hpp"
#include <iostream>
#include <string>
#include <list>


int main(int argc, char const *argv[])
{
    HashTabel h;

    
    
    std::vector<std::string> authors;
    authors.push_back("James");
    authors.push_back("TOM");
    Book b = Book("Title",authors,1232123234,2);
    Book b2 = Book("Sohail",authors,123,2);

    int index =  h.hash_funtion("Parallel and Concurrent Programming in Haskell") ;
    h.insert(b);
    h.insert(b2);

    

    std::cout <<  h.search("Sohail")<< std::endl;
    return 0;
}
