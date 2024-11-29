#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Creating a book object
struct Book {
    string title;
    string author;
    string isbn;
    bool isAvailable;
};

// Creating a member object
struct Member {
    string name;
    string memberId;
    vector<Book*> borrowedBooks; 
};

// Creating the library
struct Library {
    vector<Book> books;
    vector<Member> members;


    // Creating a function to add a new book
    void addBook(const string& title, const string& author, const string& isbn) {
        books.push_back({title, author, isbn, true});
    }

    // Creating a function ot add a new member
    void registerMember(const string& name, const string& memberId) {
        members.push_back({name, memberId});
    }

    // Finding a Book Fromthe Library
    Book* findBook(const string& isbn) {
        auto It = find_if(books.begin(), books.end(), [&isbn](const Book& book){return book.isbn == isbn;});
        return (It != books.end()) ? &(*It) : nullptr;
    }

    // Finding a member
    Member* findMember(const string& memberId) {
        auto It = find_if(members.begin(), members.end(), [&memberId](const Member& member){return member.memberId == memberId;});
        return (It != members.end()) ? &(*It) : nullptr;
    }

    // Borrowing a Book
    bool borrowBook(const string& memberId, const string& isbn) {
        Book* book = findBook(isbn);
        Member* member = findMember(memberId);

        if (!member || !book) {
            if (!member) cout<<"\nThe member does not exist.\n";
            if (!book) cout<<"\nThe book does not exist.\n";
            return false;
        }
        if (book->isAvailable == false) {
            cout<<"\nThis book is not available right now\n";
            return false;
        }
        book->isAvailable = false;
        member->borrowedBooks.push_back(book);
        cout<<"\nThe Book has been added to your list.\n";
        return true;
    }

    // Returning a book
    bool returnBook(const string& memberId, const string& isbn) {
        Book* book = findBook(isbn);
        Member* member = findMember(memberId);

        if (!member || !book) {
            if (!member) cout<<"\nThe Member does not exist.\n";
            if (!book) cout<<"\nThe Book does not exist.\n";
            return false;
        }
        auto It = find(member->borrowedBooks.begin(), member->borrowedBooks.end(), book);
        if (It == member->borrowedBooks.end()) {
            cout<<"\nThe book isn't borrowed by this member.\n";
            return false;
        }
        member->borrowedBooks.erase(It);
        book->isAvailable = true;
        return true;
    }

    // Display all the books available in the library
    void displayBooks() {
        for (const auto& book : books) {
            cout<<"\nTitle: "<<book.title;            
            cout<<"\nAuthor: "<<book.author;            
            cout<<"\nISBN: "<<book.isbn;            
            cout<<"\nAvailablity: "<<(book.isAvailable==true ? "Yes" : "No")<<endl; 
            cout << "\n---------------------\n";           
        }
    }

    // Display Member's Borrowed books
    bool displayMemberBooks(const string& memberId) {
        Member* member = findMember(memberId);

        if (member) {
            if (member->borrowedBooks.empty()) {
                cout<<"\nThis member has no borrowed books";
                return true;
            }
            for (const auto& book : member->borrowedBooks) {
                cout<<"\nTitle: "<<book->title;            
                cout<<"\nAuthor: "<<book->author;            
                cout<<"\nISBN: "<<book->isbn;
                cout << "\n---------------------\n"; 
            }
            return true;
        }
        else {
            cout<<"\nThe member does not exist\n";
            return false;
        }
    }
};


int main() {
    Library library;

    // Adding a bunch of books
    library.addBook("The C++ Programming Language", "Bjarne Stroustrup", "1234567890");
    library.addBook("Clean Code: A Handbook of Agile Software Craftsmanship", "Robert C. Martin", "1234567891");
    library.addBook("Design Patterns: Elements of Reusable Object-Oriented Software", "Erich Gamma, Richard Helm, Ralph Johnson, John Vlissides", "1234567892");
    library.addBook("Introduction to Algorithms", "Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, Clifford Stein", "1234567893");
    library.addBook("The Pragmatic Programmer: Your Journey to Mastery", "Andrew Hunt, David Thomas", "1234567894");
    library.addBook("The Mythical Man-Month: Essays on Software Engineering", "Frederick P. Brooks", "1234567895");
    library.addBook("Refactoring: Improving the Design of Existing Code", "Martin Fowler", "1234567896");
    library.addBook("Code Complete: A Practical Handbook of Software Construction", "Steve McConnell", "1234567897");
    library.addBook("The Art of Computer Programming", "Donald E. Knuth", "1234567898");
    library.addBook("Algorithms", "Robert Sedgewick, Kevin Wayne", "1234567899");
    library.addBook("Computer Networks", "Andrew S. Tanenbaum", "1234567900");
    library.addBook("Operating System Concepts", "Abraham Silberschatz, Peter B. Galvin, Greg Gagne", "1234567901");

    // Registering multiple members
    library.registerMember("Satya Prasad Mondal", "mid1234567890");
    library.registerMember("Shubham Mitra", "mid1234567891");
    library.registerMember("Shivam Mishra", "mid1234567892");
    library.registerMember("Alok Singh", "mid1234567893");
    library.registerMember("Nikita Sharma", "mid1234567894");
    library.registerMember("Rahul Reddy", "mid1234567895");
    library.registerMember("Sonia Mehta", "mid1234567896");

    // Display the initial library catalogue
    cout << "\nThe Library Catalogue (Before Borrowing):\n";
    library.displayBooks();

    // Borrowing some books
    cout << "\nBorrowing books...\n";
    library.borrowBook("mid1234567890", "1234567890");  // Borrow "The C++ Programming Language"
    library.borrowBook("mid1234567890", "1234567894");  // Borrow "The Pragmatic Programmer"
    library.borrowBook("mid1234567891", "1234567891");  // Borrow "Clean Code"
    library.borrowBook("mid1234567892", "1234567893");  // Borrow "Introduction to Algorithms"
    library.borrowBook("mid1234567893", "1234567892");  // Borrow "Design Patterns"

    // Display books borrowed by members
    cout << "\nThe books borrowed by mid1234567890 are:\n";
    library.displayMemberBooks("mid1234567890");

    cout << "\nThe books borrowed by mid1234567891 are:\n";
    library.displayMemberBooks("mid1234567891");

    cout << "\nThe books borrowed by mid1234567892 are:\n";
    library.displayMemberBooks("mid1234567892");

    cout << "\nThe books borrowed by mid1234567893 are:\n";
    library.displayMemberBooks("mid1234567893");

    // Display updated library catalogue (after borrowing books)
    cout << "\nThe Library Catalogue (After Borrowing):\n";
    library.displayBooks();

    // Returning a book
    cout << "\nReturning books...\n";
    library.returnBook("mid1234567890", "1234567890");  // Return "The C++ Programming Language"
    library.returnBook("mid1234567891", "1234567891");  // Return "Clean Code"

    // Display books borrowed by members after returning books
    cout << "\nThe books borrowed by mid1234567890 after returning:\n";
    library.displayMemberBooks("mid1234567890");

    cout << "\nThe books borrowed by mid1234567891 after returning:\n";
    library.displayMemberBooks("mid1234567891");

    // Display final library catalogue (after returning books)
    cout << "\nThe Library Catalogue (After Returning):\n";
    library.displayBooks();

    return 0;
}
