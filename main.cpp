#include "data.cpp"
#include "action.cpp"

int main(){
    int option;
    BookNodePtr library[3];//static array of Book_Node* type in which each indexed var is the head of the linked list of Book_Node* type
    PersonNodePtr person[2];//static array of Person_Node* type in which each indexed var is the head of the linked list of Person_Node* type
    readBookInfo(library);
    readPersonInfo(person);
    menu(option, library, person);
}

void menu(int& choice, BookNodePtr library[], PersonNodePtr person[]){
    do{
        cout << "-----------------------" << endl;
        cout << "         Menu          " << endl;
        cout << "-----------------------" << endl;
        cout << "1. Search a book" << endl;
        cout << "2. Rent a book" << endl;
        cout << "3. Return a book" << endl;
        cout << "4. Show my information" << endl;
        cout << "5. Show all books" << endl;
        cout << "6. Exit" << endl;
        cout << endl;
        cout << "Select (1~6) : ";
        cin >> choice;
        cin.ignore();
        menuAction(choice, library, person);
        cout << endl;
    }while(choice != 6);
}

void menuAction(int choice, BookNodePtr library[], PersonNodePtr person[]){
    switch (choice){
        case 1:
            searchBook(library);
            break;
        
        case 2:
            rentBook(library, person);
            break;

        case 3:
            returnBook(library, person);
            break;
        
        case 4:
            showPersonInfo(library, person);
            break;
        
        case 5:
            showAllBook(library);
            break;
        
        default:
            exit(0);
    }
}
