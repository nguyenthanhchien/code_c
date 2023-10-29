#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Book
{
private:
    int id;
    char name[50];
    char audior[50];
    int number;

public:
    Book(int id, const char* name, const char* audior, int number)
    {
        this->id = id;
        strcpy(this->name, name);
        strcpy(this->audior, audior);
        this->number = number;
    }

    int getId() const
    {
        return id;
    }

    const char* getAudior() const
    {
        return audior;
    }

    const char* getName() const
    {
        return name;
    }

    int getNumber() const
    {
        return number;
    }

    void setName(const char* name)
    {
        strcpy(this->name, name);
    }

    void setAudior(const char* audior)
    {
        strcpy(this->audior, audior);
    }

    void setNumber(int number)
    {
        this->number = number;
    }
};

class Library
{
private:
    vector<Book> books;

public:
    void addBook(const Book& book)
    {
        books.push_back(book);
    }

    void displayBooks() const
    {
        for (const Book& book : books) {
            cout << "ID: " << book.getId() << endl;
            cout << "Name: " << book.getName() << endl;
            cout << "Audior: " << book.getAudior() << endl;
            cout << "Number: " << book.getNumber() << endl;
            cout << "---------------" << endl;
        }
    }

    void removeBook(int id)
    {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->getId() == id) {
                books.erase(it);
                return; // Exit the loop once the book is removed
            }
        }
    }

    void updateBook(int id, const char* name, const char* audior, int number)
    {
        for (Book& book : books) {
            if (book.getId() == id) {
                book.setName(name);
                book.setAudior(audior);
                book.setNumber(number);
                return; // Exit the loop once the book is updated
            }
        }
    }
};

int main()
{
    Library library;

    library.addBook(Book(1, "Book 1", "Author 1", 10));
    library.addBook(Book(2, "Book 2", "Author 2", 5));
    library.addBook(Book(3, "Book 3", "Author 3", 7));

    library.displayBooks();

    cout << "Updating book with ID 2..." << endl;
    library.updateBook(2, "Updated Book 2", "Updated Author 2", 3);

    cout << "Updated list of books:" << endl;
    library.displayBooks();

    cout << "Deleting book with ID 2..." << endl;
    library.removeBook(2);
    library.displayBooks();
    return 0;
}
