#include <iostream>
using namespace std;

// Base Class
class Item {
protected:
    int id;
    string title;
    bool isIssued;

public:
    Item(int i, string t) {
        id = i;
        title = t;
        isIssued = false;
    }

    void issueItem() {
        if (!isIssued) {
            isIssued = true;
            cout << "Item issued successfully!\n";
        } else {
            cout << "Item already issued!\n";
        }
    }

    void returnItem() {
        if (isIssued) {
            isIssued = false;
            cout << "Item returned successfully!\n";
        } else {
            cout << "Item was not issued!\n";
        }
    }

    virtual void display() {
        cout << "ID: " << id << endl;
        cout << "Title: " << title << endl;
        cout << "Status: " << (isIssued ? "Issued" : "Available") << endl;
    }

    bool isAvailable() {
        return !isIssued;
    }
};

// Derived Class: Book
class Book : public Item {
    string author;

public:
    Book(int i, string t, string a) : Item(i, t) {
        author = a;
    }

    void display() {
        Item::display();
        cout << "Author: " << author << endl;
    }
};

// Derived Class: Magazine
class Magazine : public Item {
    int issueNumber;

public:
    Magazine(int i, string t, int issue) : Item(i, t) {
        issueNumber = issue;
    }

    void display() {
        Item::display();
        cout << "Issue Number: " << issueNumber << endl;
    }
};

// Main Function
int main() {
    Book b1(1, "C++ Basics", "Bjarne");
    Magazine m1(2, "Tech Monthly", 101);

    int choice;

    do {
        cout << "\n--- LIBRARY MENU ---\n";
        cout << "1. Display Book\n";
        cout << "2. Display Magazine\n";
        cout << "3. Issue Book\n";
        cout << "4. Return Book\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            b1.display();
            break;
        case 2:
            m1.display();
            break;
        case 3:
            b1.issueItem();
            break;
        case 4:
            b1.returnItem();
            break;
        }

    } while (choice != 5);

    return 0;
}
