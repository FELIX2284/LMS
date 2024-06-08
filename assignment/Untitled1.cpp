#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

//book storage
class Book {
private:
    string name;
    string title;
    string author;
    
	bool isAvailable;
public:
    Book(string n, string t, string a) : name(n), title(t), author(a),isAvailable(true) {}

    void input() {
        cout << "Input the name, title and author: " << endl;
        cin >> name >> title >> author;
    }

    void display() const {
    
        cout << name << " " << title << " " << author << endl;
    }
    string getName() const { return name; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    bool getAvailability() const { return isAvailable; }
    void borrowBook() { isAvailable = false; }
    void returnBook() { isAvailable = true; }
};

class User {
private:
    string name;
    string admissionnumber;
    string librarynumber;

public:
    User(string n, string t, string a) : name(n), admissionnumber(t), librarynumber(a) {} 

    void input() {
        cout << "Input the name, admissionnumber and librarynumber: " << endl;
        cin >> name >> admissionnumber >> librarynumber;
    }

    void display() const {
        cout << name << " " << admissionnumber << " " << librarynumber << endl;
    }

	string getname() const {return name;}
	string getadmno() const {return admissionnumber;}
	string getlibno() const {return librarynumber;}
};

class Library {
private:
    vector<Book> books;
    vector<User> users;
    vector<Book> borrowedBooks; 
    vector<Book> returnedBooks; 

public:
    void addBook(const Book& book) { 
        books.push_back(book);
    }

    void showBooks() const { 
        for (size_t i = 0; i < books.size(); ++i) {
            books[i].display();
        }
    }

    void addUser(const User& user) { 
        users.push_back(user);
    }

    void showUsers() const { 
        for (size_t i = 0; i < users.size(); ++i) {
        	
            users[i].display();
        }
    }
    void searchBook(const string& searchTerm) const {
        bool found = false;
        for (size_t i = 0; i < books.size(); ++i) {
            if (books[i].getName() == searchTerm || books[i].getTitle() == searchTerm || books[i].getAuthor() == searchTerm) {
                books[i].display();
                found = true;
            }
        }
        if (!found) {
            cout << "No book found with the search term: " << searchTerm << endl;
        }
    }
    void searchUser(const string& searchTerm) const {
        bool found = false;
        for (size_t i = 0; i < books.size(); ++i) {
            if (users[i].getname() == searchTerm || users[i].getadmno() == searchTerm || users[i].getlibno() == searchTerm) {
                users[i].display();
                found = true;
            }
        }
        if (!found) {
            cout << "No user found with the search term: " << searchTerm << endl;
        }
    }
 
};
	


int main() {
    string name, title, author,searchTerm;
    int choice;
    Library library;
    system("color 4F");

    while (true) {
         cout << "Enter number"<<endl;
         cout<<"1: Add books"<<endl;
		 cout<<"2: Display books"<<endl;
		 cout<<"3: enter a user"<<endl;
		 cout<<"4: display users"<<endl;
         cout<<"5: search book by name, title or author"<<endl;
		 cout<<"6: search person by name, admno or lib no"<<endl;
		 cout<<"#: exit"<<endl;
         cin >> choice;

        if (choice == 1) {
            cout << "Input the name, title and author: " << endl;
            cin >> name >> title >> author;
            Book newBook(name, title, author);
            library.addBook(newBook);
		}
        
    }

    return 0;
}
