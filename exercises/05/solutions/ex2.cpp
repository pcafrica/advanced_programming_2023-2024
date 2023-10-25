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

bool compare_by_year_ascending(const Book &a, const Book &b) {
  return a.publication_year < b.publication_year;
}

class ComparatorByName {
public:
  bool operator()(const Book &a, const Book &b) const {
    return a.author < b.author;
  }
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
  std::vector<Book> books = {
      {"Go set a watchman", "Harper Lee", "Fiction", 2015},
      {"Animal farm", "George Orwell", "Satire", 1945},
      {"To kill a mockingbird", "Harper Lee", "Fiction", 1960},
      {"1984", "George Orwell", "Science fiction", 1949},
      {"Pride and prejudice", "Jane Austen", "Romance", 1813},
      {"Sense and sensibility", "Jane Austen", "Romance", 1811}};

  std::cout << "Original list of books:" << std::endl;
  print(books);

  // Sort in ascending order by year.
  std::sort(books.begin(), books.end(), compare_by_year_ascending);
  std::cout << std::endl
            << "Books sorted in ascending order by year:" << std::endl;
  print(books);

  // Sort in descending order by year.
  std::sort(books.begin(), books.end(), [](const Book &a, const Book &b) {
    return a.publication_year > b.publication_year;
  });
  std::cout << std::endl
            << "Books sorted in descending order by year:" << std::endl;
  print(books);

  // Sort in ascending order by author name.
  std::sort(books.begin(), books.end(), ComparatorByName{});
  std::cout << std::endl
            << "Books sorted in ascending order by author name:" << std::endl;
  print(books);

  // Filter books by author.
  const std::string author_to_filter = "Jane Austen";
  std::vector<Book> filtered_books;
  std::copy_if(books.begin(), books.end(), std::back_inserter(filtered_books),
               [author_to_filter](const Book &book) {
                 return book.author == author_to_filter;
               });

  if (filtered_books.empty()) {
    std::cout << std::endl
              << "No books by " << author_to_filter << " found." << std::endl;
  } else {
    std::cout << std::endl
              << "Books by " << author_to_filter << ":" << std::endl;
    print(filtered_books);
  }

  return 0;
}
