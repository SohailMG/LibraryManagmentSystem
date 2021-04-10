#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "HashTable.hpp"
#include "Book.hpp"
/**
 * @brief This file performs all unit tests for the hash table class
 * and it's main operations including search,insert and remove
 * @see README.md for compilation command
 * 
 * hash_tests.cpp
 * AUTHOR  :  M00716650
 * CREATED :  8/03/2021
 * UPDATED :  16/04/2021 
 * 
 */


Hash h = Hash(317);
Book b = Book();

// testing hash function giving different output for each key
TEST_CASE("testing hash function", "[hash]")
{

  REQUIRE(h.hash_funtion("Head First SQL") == 131);
  REQUIRE(h.hash_funtion("Handbook of Graph Theory") == 101);
  REQUIRE(h.hash_funtion("Learning MySQL") == 223);
}
// testing to see if ISBN gets stored entily when it's type is unsigned long
TEST_CASE("testing ISBN gets stored entirly","[ISBN]")
{
  b.setISBN(9780130457868);
  REQUIRE(b.getISBN() == 9780130457868);
}
// testing insert functionality when inserting dublicate books
TEST_CASE("testing dublicate insertion of books","[Insert]")
{
  std::vector<std::string> authors;
  authors.push_back("J. B. Priestley");
  authors.push_back("Tom H");
  Book book = Book("Inspector Calls",authors,9780130457868,2);
  // checking for dublicates returning false when book is not already stored
  REQUIRE(h.check_dublicates(book.getTitle()) == false);
  h.insert(book);
  // checking for dublicates returning true when same book exists
  REQUIRE(h.check_dublicates(book.getTitle()) == true);
}

TEST_CASE("removing books","[Remove]"){
  std::vector<std::string> authors;
  authors.push_back("John Steinbeck");
  authors.push_back("Tom H");
  Book book = Book("of mice and men",authors,9780130457868,3);
  h.insert(book);

    // removing all copies
    for (size_t i = 0; i < book.getQuantity(); i++)
    {
      h.remove_book(book.getTitle());
      // testing book exists when removing 1 copy each iteration
      REQUIRE(h.check_dublicates("of mice and men") == true);

      
    }
      // testing book shouldn't exist when book object is removed
      h.remove_book(book.getTitle());
      REQUIRE(h.check_dublicates("of mice and men") == false);
  
}
/**
 * @brief testing when searching for two books with same hash value.
 * then search function should only return the matching book title
 * and not the first book in the table cell
 */
TEST_CASE("testing search function","[search]"){
  // inserting two book objects that have the hash value 
  std::vector<std::string> authors;
  authors.push_back("John Steinbeck");
  authors.push_back("Tom H");
  Book book1 = Book("Complex Analysis with Applications",authors,9780130457868,3);
  Book book2 = Book("Practical Common Lisp",authors,9780130457868,3);

  // checking that hash value for both books are equal
  REQUIRE(h.hash_funtion(book1.getTitle()) == h.hash_funtion(book2.getTitle()));
  h.insert(book1);
  h.insert(book2);
  /* 
  performing a search for first book and second book by it's title 
  and checking that returned result matches searched title
  */
  Book result1 = h.search(book1.getTitle());
  REQUIRE(result1.getTitle() == book1.getTitle());

  Book result2 = h.search(book2.getTitle());
  REQUIRE(result2.getTitle() == book2.getTitle());


}

