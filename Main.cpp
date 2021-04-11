#include "Book.hpp"
#include "HashTable.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <list>
#include <limits>
/**
 * @brief Main Program Runner
 * Main.cpp
 * AUTHOR  :  M00716650
 * CREATED :  27/03/2021
 * UPDATED :  16/04/2021 
 *
 */

/**
 * @brief out puts a menu to the console and reads in the option
 * 
 * @return int option being selected from menu
 */
int select_Option()
{
    int option;
    std::cout << "\n\t\t+----------[MENU]---------+---+"
              << std::endl;
    std::cout << "\t\t|Search Book By Title     | 1 |" << std::endl;
    std::cout << "\t\t+-------------------------+---+\n";
    std::cout << "\t\t|Insert New Book          | 2 |" << std::endl;
    std::cout << "\t\t+-------------------------+---+\n";
    std::cout << "\t\t|Remove lost/damaged book | 3 |" << std::endl;
    std::cout << "\t\t+-------------------------+---+\n";
    std::cout << "\t\t|Exit Program             | 0 |" << std::endl;
    std::cout << "\t\t+-------------------------+---+\n"
              << std::endl;
    std::cout << "\t\tChoose an Option    > ";
    std::cin >> option;

    return option;
}

/**
 * @brief takes string of authors seperated by ; , splits the string
 * and stores them into a vector
 * @param s refrence to a string 
 * @return std::vector<std::string> of authors
 */
std::vector<std::string> split(const std::string &s)
{
    char delim = ';';
    std::vector<std::string> result;
    std::stringstream ss(s);
    std::string item;

    while (std::getline(ss, item, delim))
    {
        result.push_back(item);
    }
    return result;
}

// MAIN PROGRAM
int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
        std::cout << "\tmissing arguments\n";
        std::cout << "Expected -> ./Program <datafile>" << std::endl;
        return 0;
    }

    std::ifstream datafile(argv[1]);
    std::string data;
    std::vector<std::string> tokens;
    std::vector<std::string> authors;
    std::vector<Book> books;
    std::ofstream MyFile("searches.txt");
    int lines_count = 0;
    while (getline(datafile, data))
    {
        std::stringstream ss(data);
        std::string title, author, ISBN, Q;

        // reading file data seperated by tabs
        std::stringstream split_authors(author);
        std::getline(ss, title, '\t');
        std::getline(ss, author, '\t');
        std::getline(ss, ISBN, '\t');
        std::getline(ss, Q, '\t');

        // splitting the string of authors by delimeter
        std::vector<std::string> tokens = split(author);
        // storing each author into a vector
        for (size_t i = 0; i < tokens.size(); i++)
        {
            authors.push_back(tokens.at(i));
        }
        // making a book object and storing them into a vector
        Book b = Book(title, authors, std::stoul(ISBN), std::stoi(Q));
        books.push_back(b);
        authors.clear();
        lines_count++;
    }

    // declaring a hashtable object and the table size
    Hash table = Hash(lines_count);
    // storing each book object into the table
    for (size_t i = 0; i < books.size(); i++)
    {
        table.insert(books.at(i));
        MyFile << table.search(books.at(i).getTitle()).getTitle() <<" " <<  table.hash_funtion(books.at(i).getTitle()) << "\n";
    }
    MyFile.close();

    

    // program loop
    while (true)
    {
        try
        {

            int option = select_Option();
            // condition when user chooses to search for a book
            if (option == 1)
            {
                std::string title;
                std::cout << "\t\tSearch (Full) Book Title   > ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::getline(std::cin, title);
                std::cout << "\n--------------------[RESULTS]-------------------------\n";
                Book b = table.search(title);
                std::cout << b << std::endl;
                std::cout << "------------------------------------------------------\n";
            }
            // conditon when user chooses to add a new book
            else if (option == 2)
            {
                std::string title;
                std::string author;
                unsigned long ISBN;
                int quantity;

                // reading in new book data
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "\t\tEnter Title    > ";
                std::getline(std::cin, title);
                // checking if the new book is already stored in the hash table to prevent dublicate keys
                if (table.check_dublicates(title))
                {
                    std::cout << "\n\n------------------[FAILED]-----------------" << std::endl;
                    std::cout << "Book   : " << title << std::endl;
                    std::cout << "Reason : Book exists " << std::endl;
                    std::cout << "--------------------------------------------\n";
                }
                // adding new book details
                else
                {

                    std::cout << "\t\tEnter ISBN     > ";
                    std::cin >> ISBN;

                    std::cout << "\t\tEnter Quantity > ";
                    std::cin >> quantity;

                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "\t\tEnter Authors seperated by (;) > ";
                    std::getline(std::cin, author);
                    // splitting authors by del and adding into a vector
                    std::vector<std::string> tokens = split(author);
                    // splitting the given authors list by the delimerte
                    for (size_t i = 0; i < tokens.size(); i++)
                    {
                        authors.push_back(tokens.at(i));
                    }

                    Book book = Book(title, authors, ISBN, quantity);
                    table.insert(book);
                    std::cout << "\n\tNew Book Added\n";
                    std::cout << "------------------------------" << std::endl;
                    std::cout << "Book     - " << book.getTitle() << std::endl;
                    std::cout << "Location - " << table.hash_funtion(book.getTitle()) << std::endl;
                    std::cout << "------------------------------" << std::endl;
                }
            }
            // condition when user chooses to remove lost or damaged book
            else if (option == 3)
            {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::string title;
                std::cout << "\t\tEnter Book Title  > ";
                std::getline(std::cin, title);
                std::cout << "\n\n---------------------[BOOK]-----------------------\n";
                table.remove_book(title);
                std::cout << "--------------------------------------------------\n";
            }
            else if (option == 0)
            {
                break;
            }
            else
            {
                std::cout << "\t\t[" << option << "]"
                          << " is invalid choose [1][2][3][0]" << std::endl;
            }
            std::string key;
            std::cout << "type any key to continue  > ";
            std::cin >> key;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    return 0;
}
