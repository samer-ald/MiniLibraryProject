#include <iostream>

using namespace std;

int bookids[100];
string booktitles[100];
string bookauthors[100];
bool isborrowed[100];
int bookcount=0;

void addbook()
{

    int id;
    string title,author;
    bool uID = false;

    while(!uID)
    {
        cout << "Enter book ID : " << endl;
        cin >> id;

        uID = true;
        for(int i = 0; i < bookcount; i++)
        {
            if(bookids[i] == id)
            {
                cout << "This ID already exists! Please enter a different ID." << endl;
                uID = false;
                break;
            }
        }
    }
    cout<<endl;
    cout<<"Enter book title : "<<endl;
    cin>>title;
    cout<<endl;
    cout<<"Enter book author : "<<endl;
    cin>>author;
    cout<<endl;
    bookids[bookcount]=id;
    booktitles[bookcount]=title;
    bookauthors[bookcount]=author;
    isborrowed[bookcount]=false;

    bookcount++;

    cout<<"The book has been added"<<endl;

    cout<<endl<<endl<<endl;
    cout<<"____________________________________________________\n";
    cout<<endl;

}


void deleteBook()
{
    int id;
    cout << "Enter book ID "<<endl<<"---"<<endl;
    cin >> id;
    cout<<"---"<<endl;
    bool found = false;

    for (int i = 0; i < bookcount; i++)
    {
        if (bookids[i] == id)
        {
            found = true;

            for (int j = i; j < bookcount - 1; j++)
            {
                bookids[j] = bookids[j + 1];
                booktitles[j] = booktitles[j + 1];
                bookauthors[j] = bookauthors[j + 1];
                isborrowed[j] = isborrowed[j + 1];
            }
            bookcount--;
            cout << "The book has been deleted" << endl;
            break;
        }
    }

    if (!found)
    {
        cout << "Book not found!" << endl;
    }

    cout << "____________\n";
}


void displayBooks()
{
    if (bookcount == 0)
    {
        cout << " there are no books in the library. "<<endl;
        cout<<endl;
        cout<<"____________________________________________________\n";

        return;
    }
    for(int i=0; i<bookcount; i++)
    {
        cout<<" Book ID     : "<<bookids[i]<<endl;
        cout<<" Book title  : "<<booktitles[i]<<endl;
        cout<<" Book author : "<<bookauthors[i]<<endl;
        cout<<" Book status : "<<(isborrowed[i]==0 ? "available " : "not available ")<<endl;
        cout<<"---------------------------\n";
    }
    cout<<endl<<endl;
    cout<<"          Done!"<<endl;
    cout<<endl<<endl;
    cout<<"____________________________________________________\n";
    cout<<endl;
}

void borrowBook()
{
    cout<<endl;
    cout<<endl;
    int idr;
    bool found = false;

    cout<<"Enter the book ID : "<<endl;
    cin>>idr;
    cout<<endl;
    for(int i=0; i<bookcount; i++)
    {
        if(idr==bookids[i])
        {
            if (!isborrowed[i])
            {
                isborrowed[i]=true;
                cout<<" the book has been borrowed "<<endl;
            }
            else
            {
                cout<<"you can not borrow the book"<<endl;

            }
            found=true;
            break;

        }
    }
    if (!found)
    {
        cout << " Book not found. ";
    }
    cout<<endl;
    cout<<"____________________________________________________\n";
    cout<<endl;
}

void returnBook()
{
    cout<<endl;
    cout<<endl;
    int idr;
    bool found=false;
    cout<<"Enter the book ID : "<<endl;
    cin>>idr;
    cout<<endl;
    cout<<endl;
    for(int i=0; i<bookcount; i++)
    {
        if(idr==bookids[i])
        {
            if(isborrowed[i])
            {
                cout<<" the book has been returned "<<endl;
                isborrowed[i]=false;
            }
            else
            {
                cout<<" this book is not borrowed "<<endl;
            }
            found=true;
            break;
        }
    }
    if (!found)
    {
        cout << " Book not found. ";
    }
    cout<<endl;
    cout<<"____________________________________________________\n";
    cout<<endl;
}

void searchbook()
{
    int ids;
    cout<<" Enter the book ID "<<endl<<endl<<"----------------"<<endl<<endl;
    cin>>ids;
    cout<<endl<<"----------------"<<endl;
    for(int i=0; i<bookcount; i++)
    {
        if (ids==bookids[i])
        {
            cout<<"Book ID: "<<bookids[i]<<endl;
            cout<<"Book Title: "<<booktitles[i]<<endl;
            cout<<"Book Author: "<<bookauthors[i]<<endl;
            cout<<"Book status: "<<(isborrowed[i]==0 ? " available " : " not available ")<<endl;
            break;
        }
    }
    cout<<endl<<endl;
    cout<<"____________________________________________________\n";
    cout<<endl;
}
void EditBook()
{
    int ids;
    bool uID = false;

    cout<<" Enter the book ID "<<endl<<"---"<<endl;
    cin>>ids;
    cout<<"---"<<endl;
    for(int i=0; i<bookcount; i++)
    {
        if (ids==bookids[i])
        {
            cout<<endl<<"--------------  the old information   ----------------"<<endl<<endl;

            cout<<"Book ID: "<<bookids[i]<<endl;
            cout<<"Book Title: "<<booktitles[i]<<endl;
            cout<<"Book Author: "<<bookauthors[i]<<endl;
            cout<<"Book status: "<<(isborrowed[i]==0 ? " available " : " not available ")<<endl;

            cout<<endl<<"--------------  the new information   ----------------"<<endl<<endl;

            int id;
            while(!uID)
            {
                cout << "Book ID : " << endl;
                cin >> id;

                uID = true;
                for(int i = 0; i < bookcount; i++)
                {
                    if(bookids[i] == id)
                    {
                        cout << "This ID already exists! Please enter a different ID." << endl;
                        uID = false;
                        break;
                    }
                }
                bookids[i]=id;
            }
            cout<<endl;

            cout<<endl<<"Book Title: ";
            cin>>booktitles[i];

            cout<<endl<<"Book Author: ";
            cin>>bookauthors[i];

            break;
        }
    }
    cout<<endl<<endl;
    cout<<"____________________________________________________\n";
    cout<<endl;
}

void Libraryinfo()
{
    int borrowed=0,available=0;
    for(int i=0; i<bookcount; i++)
    {
        if(isborrowed[i])
            borrowed++;
        else
            available++;
    }
    cout<<"Total books     : "<<bookcount<<endl;
    cout<<"borrowed books  : "<<borrowed<<endl;
    cout<<"available books : "<<available<<endl;

    cout<<endl<<endl;
    cout<<"____________________________________________________\n";
    cout<<endl;
}

void DisplayBorrowedBooks()
{
    bool found = false;
    for (int i = 0; i < bookcount; i++)
    {
        if (isborrowed[i])
        {
            cout<<"Book ID: "<<bookids[i]<<endl;
            cout<<"Book Title: "<<booktitles[i]<<endl;
            cout<<"Book Author: "<<bookauthors[i]<<endl;
            cout<<"---------------------------\n";
            found = true;
        }
    }
    if (!found) cout << "No borrowed books" << endl;
    cout << "____________________________________________________\n";
}


int main()
{
    bookids[bookcount] = 1;
    booktitles[bookcount] = "C++";
    bookauthors[bookcount] = "Samer";
    isborrowed[bookcount] = false;
    bookcount++;

    bookids[bookcount] = 2;
    booktitles[bookcount] = "Data Structures";
    bookauthors[bookcount] = "Anas";
    isborrowed[bookcount] = false;
    bookcount++;

    bookids[bookcount] = 3;
    booktitles[bookcount] = "java";
    bookauthors[bookcount] = "Rateb";
    isborrowed[bookcount] = false;
    bookcount++;

    bookids[bookcount] = 4;
    booktitles[bookcount] = "AI";
    bookauthors[bookcount] = "Baraa";
    isborrowed[bookcount] = false;
    bookcount++;

    bookids[bookcount] = 5;
    booktitles[bookcount] = "c#";
    bookauthors[bookcount] = "Ahmed";
    isborrowed[bookcount] = false;
    bookcount++;

    while(true)
    {
        cout<<"      //Library menu//  "<<endl;
        cout<<endl;
        cout<<" 1. Add new book "<<endl;
        cout<<" 2. Display the books "<<endl;
        cout<<" 3. Borrow book "<<endl;
        cout<<" 4. Retern book  "<<endl;
        cout<<" 5. Search for a book by ID "<<endl;
        cout<<" 6. Edit book information "<<endl;
        cout<<" 7. Delete a book "<<endl;
        cout<<" 8. Library information "<<endl;
        cout<<" 9. Display borrowed books "<<endl;
        cout<<" 0. Exit "<<endl;
        cout<<endl;
        cout<<"____________________________________________________"<<endl;
        cout<<endl;

        int choice;

        cout<<"Choose: ";

        cin>>choice;
        cout<<endl;
        cout<<"____________________________________________________"<<endl;
        cout<<endl;

        switch (choice)
        {
        case 1:
            addbook();
            break;

        case 2:
            displayBooks();
            break;

        case 3:
            borrowBook();
            break;

        case 4:
            returnBook();
            break;

        case 5:
            searchbook();
            break;

        case 6:
            EditBook();
            break;

        case 7:
            deleteBook();
            break;

        case 8:
            Libraryinfo();
            break;

        case 9:
            DisplayBorrowedBooks();
            break;

        case 0:
            cout<<"thanks for using our library!!"<<endl;
            cout<<endl;
            cout<<"____________________________________________________"<<endl;
            cout<<endl;
            return 0;

        default :
            cout<<endl;
            cout<<"Enter a Correct Choice !!"<<endl;
            cout<<endl;
            cout<<"____________________________________________________"<<endl;
            cout<<endl;
        }
    }
}

