#include "Book.hpp"
#include "HashTable.hpp"
#include <iostream>
#include <string>
#include <list>


int main(int argc, char const *argv[])
{
    HashTabel h;

    
    //Deep Reinforcement Learning Hands-On	Maxim Lapan	9781788839303	7	
    std::vector<std::string> authors;
    authors.push_back("James");
    authors.push_back("TOM");

    Book b = Book("Deep Reinforcement Learning Hands-On",authors,9781788839303,7);
    Book b2 = Book("Sohail",authors,123,2);
    h.insert(b);
    h.insert(b2);

    std::cout <<  h.search("Deep Reinforcement Learning Hands-On")<< std::endl;
    return 0;
}
