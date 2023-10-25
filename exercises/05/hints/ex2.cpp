#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Book {
public:
  std::string title;
  std::string author;
  std::string genre;
  unsigned int publication_year;
};

void print(const std::vector<Book> &books) {
  for (const Book &book : books) {
    std::cout << "  Title: " << book.title << " | Author: " << book.author
              << " | Genre: " << book.genre
              << " | Year: " << book.publication_year << std::endl;
  }
}

int main() {
  // Define a list of books.
  const std::vector<Book> books = {
      {"Go set a watchman", "Harper Lee", "Fiction", 2015},
      {"Animal farm", "George Orwell", "Satire", 1945},
      {"To kill a mockingbird", "Harper Lee", "Fiction", 1960},
      {"1984", "George Orwell", "Science fiction", 1949},
      {"Pride and prejudice", "Jane Austen", "Romance", 1813},
      {"Sense and sensibility", "Jane Austen", "Romance", 1811}};

  std::cout << "Original list of books:" << std::endl;
  print(books);

  // Sort in ascending order by year.
  // ...

  // Sort in descending order by year.
  // ...

  // Sort in ascending order by author name.
  // ...

  // Filter books by author.
  // ...

  return 0;
}
