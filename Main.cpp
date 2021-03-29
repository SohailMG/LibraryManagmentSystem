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

int main(int argc, char const *argv[])
{
    HashTabel h;

    //Deep Reinforcement Learning Hands-On	Maxim Lapan	9781788839303	7
    int lineCounter = 0;
    std::ifstream datafile(argv[1]);
    std::string data;
    std::vector<std::string> tokens;
    std::vector<std::string> authors;
    
    while (getline(datafile, data))
    {
        // Output the text from the file
        lineCounter++;
        std::stringstream ss(data);

        std::string title, author, ISBN, Q;

        std::getline(ss, title, '\t');
        std::getline(ss, author, '\t');
        std::getline(ss, ISBN, '\t');
        std::getline(ss, Q, '\t');

        authors.push_back(author);
        Book b = Book(title, authors, std::stoul(ISBN), std::stoi(Q));
        h.insert(b);
    }

    std::cout << h.search("Graph Databases") << std::endl;
    return 0;
}
