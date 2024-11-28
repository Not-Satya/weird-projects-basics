#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to store the details of the books
struct Book {
    string title;
    string author;
    string isbn;
    bool isAvailable;
};

// structure to store the details of the member
struct Member {
    string name;
    string memberId;
    vector<Book*> borrowedBooks;
};

// structure to store all the details of the members and books
struct Library {
    vector<Book> books;
    vector<Member> members;


    // add a new book to the Library
    void addBook(const string& title, const string& author, const string& isbn) {
        books.push_back({title, author, isbn, true});
    }

    // add new member to the library
    void registerMember(const string& name, const string& memberId) {
        members.push_back({name, memberId, {}});
    }

    // find book by isbn
    Book* findBook(const string& isbn) {
        auto it = find_if(books.begin(), books.end(), [&isbn](const Book& book){return book.isbn == isbn;});
        return (it != books.end()) ? &(*it) : nullptr;
    }

    // find member by member Id
    Member* findMember(const string& memberId) {
        auto it = find_if(members.begin(), members.end(), [&memberId](const Member& member){return member.memberId == memberId;});
        return (it != members.end()) ? &(*it) : nullptr;
    }

    // boroow a book
    bool borrowBook(const string& memberId, const string& isbn) {
        Book* book = findBook(isbn);
        Member* member = findMember(memberId);

        if (book && member && book->isAvailable) {
            book->isAvailable = false;
            member->borrowedBooks.push_back(book);
            return true;
        }
        else return false;
    }

    // return a book
    bool returnBook(const string& memberId, const string& isbn) {
        Book* book = findBook(isbn);
        Member* member = findMember(memberId);

        if (book && member) {
            auto it = find(member->borrowedBooks.begin(), member->borrowedBooks.end(), book);
            if (it != member->borrowedBooks.end()) {
                member->borrowedBooks.erase(it);
                book->isAvailable = true;
                return true;
            }
        }
        else return false;
    }

    // display all books
    void displayBooks() {
        cout<<"Library books:\n";
        for (const auto& book : books) {
            cout<<book.title<<endl;
            cout<<"by -"<<book.author<<endl;
            cout<<"ISBN: "<<book.isbn<<endl;
            cout<<"Available: "<<(book.isAvailable == true ? "Yes" : "No")<<endl;
            cout<<".\n";
        // here books.title is used because we are directly accessing the object cuz books is a container that contains the objects in Book
        // from vector<Book> books
        }
    }

    // display member's borrowed books
    void displayMemberBooks(const string& memberId) {
        Member* member = findMember(memberId);
        if (member) {
            for (const auto& book : member->borrowedBooks) {
                cout<<book->title<<endl;
                cout<<"by -"<<book->author<<endl;
                cout<<"ISBN: "<<book->isbn<<endl;
                cout<<"."<<endl;
            // here books->title is used because we are accessing this as a pointer from member->borrowedBooks that points to Book objects
            }
        }
        else cout<<"Error: Member Not found.";
    }
};


int main()
{
    Library library;

    // adding some books
    library.addBook("The C++ Programming Language", "Bjarne Stroustrup", "1234567890");
    library.addBook("The Clean Code", "Robert Martin", "1234567891");
    library.addBook("Design Patterns", "Gang of Four", "1234567892");
    
    // register members
    library.registerMember("Satya Prasad Mondal", "mid1234567890");
    library.registerMember("Shubham Mitra", "mid1234567891");
    library.registerMember("Shivam Mishra", "mid1234567892");

    // library operations
    cout<<"\nThe Library Catalogue:\n";
    library.displayBooks();

    //borrowing books
    cout<<"\nBorrowing a book\n";
    library.borrowBook("mid1234567890", "1234567890");
    library.borrowBook("mid1234567890", "1234567892");

    // find issued books of a member
    cout<<"\nThe books borrowed by mid1234567890 are:\n";
    library.displayMemberBooks("mid1234567890");

    // updated library catalogue
    cout<<"\nThe Library Catalogue:\n";
    library.displayBooks();

    return 0;
}