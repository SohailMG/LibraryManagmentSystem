#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "HashTable.hpp"
#include "Book.hpp"

Hash h = Hash();
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
  REQUIRE(b.getISBN()== 9780130457868);
}
// testing insert functionality when inserting dublicate books
TEST_CASE("testing dublicate insertion of books","[Insert]")
{
  std::vector<std::string> authors;
  authors.push_back("J. B. Priestley");
  authors.push_back("Tom H");
  Book book = Book("Inspector Calls",authors,9780130457868,2);

  REQUIRE(h.check_dublicates(book.getTitle()) == FALSE);
  h.insert(book);
  REQUIRE(h.check_dublicates(book.getTitle()) == TRUE);
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
      REQUIRE(h.check_dublicates("of mice and men")== TRUE);

      
    }
      // testing book shouldn't exist when book object is removed
      h.remove_book(book.getTitle());
      REQUIRE(h.check_dublicates("of mice and men")== FALSE);
  
}

