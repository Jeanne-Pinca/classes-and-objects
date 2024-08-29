#include<iostream>
#include<string>
#include<vector>
#include <iomanip> 
using namespace std;

class Book{
	private: 
		string bookTitle;
		string bookAuthor;
		string bookYear;
		
	public:
		// constructor to initialize the title, author and year
		Book(string BT, string BA, string BY) : bookTitle(BT), bookAuthor(BA), bookYear(BY) {}
		

		//getter functions for each category of the book
		string getTitle() { return bookTitle; }
		string getAuthor()  { return bookAuthor; }
		string getYear()  { return bookYear; }
		
		//function to display book details
		void bookDisplay(){
			
			cout << setw(20) << left << bookTitle
             << setw(20) << left << bookAuthor
             << setw(6) << right << bookYear << endl;
		}
	};
	
class Library {
private:
    vector<Book> books;

public:
    // Function to add a new book with its details
    void addBook(string bookTitle, string bookAuthor, string bookYear) {
        Book newBook(bookTitle, bookAuthor, bookYear);
        books.push_back(newBook);
        cout << "Book added successfully!" << endl;
    }

    // Function to display all books with its details
    void displayBooks() {
        if (books.empty()) {
            cout << "No books in the library." << endl;
            return;
        }

        cout << setw(20) << left << "Title"
             << setw(20) << left << "Author"
             << setw(6) << right << "Year" << endl;
        cout << string(46, '-') << endl; 
        
        
        for (auto &book : books) {
            book.bookDisplay();
        }
    }

    // Function to search for a book by title
    void searchBook(string bookTitle) {
        for (auto &book : books) {
            if (book.getTitle() == bookTitle) {
                cout << "Book found!" << endl;
                cout << "Title: " << book.getTitle() << endl;
                cout << "Author: " << book.getAuthor() << endl;
                cout << "Year: " << book.getYear() << endl;
                return;
            }
        }
        cout << "Book not found!" << endl;
    }
};


int main(){
	Library bookLibrary;
    int choice;
    string bookTitle, bookAuthor;
    string bookYear;

    do {
        cout << "\nMenu" << endl;
        cout << "1 - Add Book" << endl;
        cout << "2 - Display Books" << endl;
        cout << "3 - Search Book" << endl;
        cout << "4 - Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

		cout << "" << endl;

        switch (choice) {
        case 1:
            cout << "Enter title: ";
            cin.ignore();
            getline(cin, bookTitle);
            cout << "Enter author: ";
            getline(cin, bookAuthor);
            cout << "Enter year: ";
            getline(cin, bookYear);
            bookLibrary.addBook(bookTitle, bookAuthor, bookYear);
            
            system("PAUSE");  
            system("CLS");
            break;

        case 2:
            cout << "Book List:" << endl;
            bookLibrary.displayBooks();
            system("PAUSE");  
            system("CLS");
            break;

        case 3:
            cout << "Enter a book to search: ";
            cin.ignore();
            getline(cin, bookTitle);
            bookLibrary.searchBook(bookTitle);
            system("PAUSE");  
            system("CLS");
            break;

        case 4:
            cout << "Exiting the program." << endl;
            break;

        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
	
}