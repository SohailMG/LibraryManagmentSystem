#include "Book.hpp"
#include "HashTable.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <list>
#include <ctype.h>
/**
 * @brief Main Program Runner
 * TODOs : DEAL WITH COLLISIONs
 * !FIX  : FILE HAS ISSUE AT LINE  396 
 *
 */

int select_Option()
{
    int option;
    std::cout << "+----------------------------+\n"
              << std::endl;
    std::cout << "|Search Book By Title......1 |" << std::endl;
    std::cout << "|Insert New Book...........2 |" << std::endl;
    std::cout << "|Remove Book...............3 |" << std::endl;
    std::cout << "+----------------------------+\n"
              << std::endl;
    std::cout << "Choose an Option    > ";
    std::cin >> option;

    return option;
}

int main(int argc, char const *argv[])
{
    HashTabel h;

    //Deep Reinforcement Learning Hands-On	Maxim Lapan	9781788839303	7
    int lineCounter = 0;
    std::ifstream datafile(argv[1]);
    std::string data;
    std::vector<std::string> tokens;
    std::vector<std::string> authors;
std::ofstream MyFile("searches.txt");
    while (getline(datafile, data))
    {
        // Output the text from the file

        std::stringstream ss(data);

        std::string title, author, ISBN, Q;

        std::getline(ss, title, '\t');
        std::getline(ss, author, '\t');
        std::getline(ss, ISBN, '\t');
        std::getline(ss, Q, '\t');

        if (std::stoi(Q) == 0)
        {
            std::cout << title << std::endl;
        }
        
        authors.push_back(author);
        Book b = Book(title, authors, std::stoul(ISBN), std::stoi(Q));
        h.insert(b);
        
        MyFile << h.search(b.getTitle()) << std::endl;
    }
        MyFile.close();

    int option = select_Option();
    if (option == 1)
    {
        std::string title;
        std::cout << "Search Book Title > ";
        std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
        std::getline(std::cin,title);
        std::cout << h.search(title) << std::endl;
    }else if(option == 2){
        std::string title;
        std::string author;
        unsigned long ISBN;
        int quantity;

        std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
        std::cout << "Enter Title    > ";
        std::getline(std::cin,title);

        std::cout << "Enter ISBN     > ";
        std::cin >> ISBN;

        std::cout << "Enter Quantity > ";
        std::cin >> quantity;

        std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
        std::cout << "Enter Authors  > ";
        std::getline(std::cin,author);
        authors.clear();
        authors.push_back(author);

        Book book = Book(title,authors,ISBN,quantity);
        h.insert(book);
        std::cout << "\n\tNew Book Added\n";
        std::cout << "------------------------------"<<std::endl;
        std::cout << "Book     - " << book.getTitle() << std::endl;
        std::cout << "Location - " << h.hash_funtion(book.getTitle()) << std::endl;
        std::cout << "------------------------------"<<std::endl;
        

    }

    // std::cout << h.search("Operating System (A Practical App)") << std::endl;
    // std::cout << h.search("SCO UNIX in a Nutshell") << std::endl;

    return 0;
}
