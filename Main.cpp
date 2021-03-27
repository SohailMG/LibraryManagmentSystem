#include "Book.hpp"
#include <iostream>
#include <string>


int main(int argc, char const *argv[])
{
    std::vector<std::string> authors;
    authors.push_back("James");
    authors.push_back("TOM");
    Book book("Title",authors,1232123234,2);
    std::cout <<  book.getTitle() << std::endl;
    return 0;
}
