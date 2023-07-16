#include "header.h"

/** implementation of menu 1
 * @brief searchBook func searches books according to user input
 * @param library - this is the array of Book_Node* type in which each indexed variable is the head of Book_Node type linked list
 */
void searchBook(BookNodePtr library[]){

    int book_code;
    string book_title;
    cout << "Enter code" << setw(4) <<  ": ";
    cin >> book_code;
    cout << "Enter title : ";
    cin >> book_title;
    cout << endl;
    string check = "";

    if(book_code > 1000 && book_code <= 2000){//if the code is 1000 ~ 2000, search the book in children category
        try
        {
            for(BookNodePtr p = library[0]; p; p = p->getBookLink()){
                if(book_code == p->getBook()->getCode()){
                    if(book_title == p->getBook()->getTitle()){
                        cout << book_title << "(" << book_code << ") exists." << endl;     
                        cout << "category : children" << endl;
                        cout << "age : " << p->getBook()->getAge() << endl; 
                        cout << p->getBook()->getAvailableBook() << " available, " << p->getBook()->getRentedBook() << " rented" << endl;  
                        check = "Found";
                        break;
                    }    
                }
                else{
                    check = "Not Found";
                }
            }
            //cout << check << endl;
            if(check == "Not Found"){
                throw book_code;
            }
        }
        catch(int book_code)
        {
            cout << "No match (code - " << book_code << " and title - " << book_title << " do not match)" << endl;
        }
    }

    else if(book_code > 2000 && book_code <= 3000){//if the code is 2001 ~ 3000, search the book in computer category
        try
        {
            for(BookNodePtr p = library[1]; p; p = p->getBookLink()){
                if(book_code == p->getBook()->getCode()){
                    if(book_title == p->getBook()->getTitle()){
                        cout << book_title << "(" << book_code << ") exists." << endl;
                        cout << "category : computer" << endl;
                        cout << "publisher : " << p->getBook()->getPublisher() << endl;
                        cout << p->getBook()->getAvailableBook() << " available, " << p->getBook()->getRentedBook() << " rented" << endl;
                        check = "Found";
                        break;
                    }
                }
                else{
                    check = "Not Found";
                }
            }
            //cout << check << endl;
            if(check == "Not Found"){
                throw book_code;
            }
        }
        catch(int book_code)
        {
            cout << "No match (code - " << book_code << " and title - " << book_title << " do not match)" << endl;
        }
    }

    else{//if the code is 3001 ~ 4000, search the book in novel category
        try
        {
            for(BookNodePtr p = library[2]; p; p = p->getBookLink()){
                if(book_code == p->getBook()->getCode()){
                    if(book_title == p->getBook()->getTitle()){
                        cout << book_title << "(" << book_code << ") exists." << endl;
                        cout << "category : novel" << endl;
                        cout << "publish date : " << p->getBook()->getPublishDate() << endl;
                        cout << p->getBook()->getAvailableBook() << " available, " << p->getBook()->getRentedBook() << " rented" << endl;
                        check = "Found";
                        break;
                    }
                }
                else{
                        check = "Not Found";
                }
            }
            //cout << check << endl;
            if(check == "Not Found"){
                throw book_code;
            }
            
        }
        catch(int book_code)
        {
            cout << "No match (code - " << book_code << " and title - " << book_title << " do not match)" << endl;
        }
    }
}

//--------------------------------------------------------------------------------------------------------------------------------
/** implementation of menu 2
 * @brief rentBook func lets teachers and students rent the books according to the limits of books that they can rent
 * @param library - this is library array of Book_Node* type in which each indexed variable is the head of Book_Node type linked list
 * @param person - this is person array of Person_Node* type in which each indexed variable is the head of Person_Node type linked list
 */
void rentBook(BookNodePtr library[], PersonNodePtr person[]){
    
    PersonNodePtr temp = NULL;
    int person_id = 0, num_of_books_rented = 0;
    string book_title = "";
    char opt = '0';
    cout << "Enter your id" << setw(6) << ": ";
    cin >> person_id;
    cout << "Enter book title : ";
    cin >> book_title;
    cout << endl;

    if(person_id > 1 && person_id <= 100){//searching for the data for teachers
        for(PersonNodePtr p = person[0]; p; p = p->getPersonLink()){
            if(person_id == p->getPerson()->getId()){//comfirm the name of the person
                cout << "You are " << p->getPerson()->getName() << ". You rented " << p->getPerson()->getCount() <<" book." << endl;
                cout << "Do you want to rent '" << book_title << "' (y/n)? ";
                cin >> opt;
                if(opt == 'y' || opt == 'Y'){//if the person rents
                    try
                    {
                        if(p->getPerson()->getCount() >= 3){//if the teacher already rented 3 books
                            throw person_id;
                        }
                        //if the teacher didn't rent more than 3 books
                        for(int i = 0; i < 3; i++){//search for the book in three categories and update the data
                            updateData(library, p, book_title, i);
                        }
                    }
                    catch(int x)
                    {
                        cout << "You already rented 3 books." << endl;
                    }
                    catch(string y){
                        cout << "The book is not available (all rented out)." << endl;
                    }
                    
                }
                break;
            }
        }
    }

    else{//search for the data for students
        for(PersonNodePtr p = person[1]; p; p = p->getPersonLink()){
            if(person_id == p->getPerson()->getId()){
                cout << "You are " << p->getPerson()->getName() << ". You rented " << p->getPerson()->getCount() <<" book." << endl;
                cout << "Do you want to rent '" << book_title << "' (y/n)? ";
                cin >> opt;
                if(opt == 'y' || opt == 'Y'){//if the person rents
                    try
                    {
                        if(p->getPerson()->getCount() >= 2){//if the teacher already rented 3 books
                            throw person_id;
                        }
                        //if the teacher didn't rent more than 3 books
                        for(int i = 0; i < 3; i++){//search for the book in three categories and update the data
                            updateData(library, p, book_title, i);
                        }
                        
                    }
                    catch(int x)
                    {
                        cout << "You already rented 2 books." << endl;
                    }
                    catch(string y){
                        cout << "The book is not available (all rented out)." << endl;
                    }
                    
                }
                break;
            }
        }
    }
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------
/** implementation of menu 3
 * @brief returnBook func update the data of books and person according to the code the person return
 * @param library - this is the array of Book_Node* type in which each indexed variable is the head of Book_Node type linked list
 * @param person  - this is the array of Person_Node* type in which each indexed variable is the head of Person_Node type linked list
 */
void returnBook(BookNodePtr library[], PersonNodePtr person[]){
    int person_id = 0;
    int book_code = 0;
    char opt = '0';
    cout << "Enter your id      : ";
    cin >> person_id;
    cout << "Enter the book code to return : ";
    cin >> book_code;

    if(book_code > 1000 && book_code <= 2000){//if the person wants to return the children book
        for(BookNodePtr b = library[0]; b; b = b->getBookLink()){
            if(book_code == b->getBook()->getCode()){
                cout << "Do you want to return '" << b->getBook()->getTitle() << "' (y/n)? ";
                cin >> opt;

                if(opt == 'Y' || opt == 'y'){
                    try
                    {   
                        if(person_id > 0 && person_id <= 100){//searching the person id for teachers
                           updateData(person, 0, person_id, book_code, b);
                        }
                        else{//searching the person id for students
                            updateData(person, 1, person_id, book_code, b);
                        }
                    }
                    catch(int x)
                    {
                        cout << "The id - " << person_id << " did not rent the book." << endl;
                    }    
                }
            }
        }
    }

    else if(book_code > 2000 && book_code <= 3000){//if the person wants to return the computer book
        for(BookNodePtr b = library[1]; b; b = b->getBookLink()){
            if(book_code == b->getBook()->getCode()){
                cout << "Do you want to return '" << b->getBook()->getTitle() << "' (y/n)? ";
                cin >> opt;

                if(opt == 'Y' || opt == 'y'){
                    try
                    {   
                        if(person_id > 0 && person_id <= 100){//searching the person id for teachers
                           updateData(person, 0, person_id, book_code, b);
                        }
                        else{//searching the person id for students
                            updateData(person, 1, person_id, book_code, b);
                        }
                    }
                    catch(int x)
                    {
                        cout << "The id - " << person_id << " did not rent the book." << endl;
                    }    
                }
            }
        }
    }

    else{//if the person wants to return the novel book
        for(BookNodePtr b = library[2]; b; b = b->getBookLink()){
            if(book_code == b->getBook()->getCode()){
                cout << "Do you want to return '" << b->getBook()->getTitle() << "' (y/n)? ";
                cin >> opt;

                if(opt == 'Y' || opt == 'y'){
                    try
                    {   
                        if(person_id > 0 && person_id <= 100){//searching the person id for teachers
                           updateData(person, 0, person_id, book_code, b);
                        }
                        else{//searching the person id for students
                            updateData(person, 1, person_id, book_code, b);
                        }
                    }
                    catch(int x)
                    {
                        cout << "The id - " << person_id << " did not rent the book." << endl;
                    }    
                }
            }
        }
    }
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------
/** implementation of menu 4
 * @brief showPersonInfo func will print out the info of books according to person's id and name
 * @param library - this is BookNodePtr array in which each indexed var is Book_Node pointer
 * @param person - this is PersonNodePtr array in which each indexed var is Person_Node pointer
 */
void showPersonInfo(BookNodePtr library[], PersonNodePtr person[]){
    
    int person_id, book_code1 = 0, book_code2 = 0, book_code3 = 0;
    string person_name;
    cout << "Enter your id   : ";
    cin >> person_id;
    cout << "Enter your name : ";
    cin >> person_name;

    if(person_id > 0 && person_id <= 100){//searching the info for teachers
        for(PersonNodePtr p = person[0]; p; p = p->getPersonLink()){
            if(person_id == p->getPerson()->getId()){
                cout << "You rented " << p->getPerson()->getCount() << " book(s)." << endl;
                //searching for the book code data
                if(p->getPerson()->getCount() == 1){
                    book_code1 = p->getPerson()->getFirstCode();
                }
                else if(p->getPerson()->getCount() == 2){
                    book_code1 = p->getPerson()->getFirstCode();
                    book_code2 = p->getPerson()->getSecondCode();
                }
                else if(p->getPerson()->getCount() == 3){
                    book_code1 = p->getPerson()->getFirstCode();
                    book_code2 = p->getPerson()->getSecondCode();
                    book_code3 = p->getPerson()->getThirdCode();
                }
                break;
            }
        }
        //looking for codes in library array to print out the info of rented books
        for(BookNodePtr b = library[0]; b; b = b->getBookLink()){//find the code in children category
            if(book_code1 == b->getBook()->getCode() || book_code2 == b->getBook()->getCode() || book_code3 == b->getBook()->getCode()){
                cout << "* " << b->getBook()->getTitle() << "(" << b->getBook()->getCode() << ")" << " - age " << b->getBook()->getAge() << endl;
            }
        }
        for(BookNodePtr b = library[1]; b; b = b->getBookLink()){//find the code in computer category
            if(book_code1 == b->getBook()->getCode() || book_code2 == b->getBook()->getCode() || book_code3 == b->getBook()->getCode()){
                cout << "* " << b->getBook()->getTitle() << "(" << b->getBook()->getCode() << ")" << " - publisher " << b->getBook()->getPublisher() << endl;
            }
        }
        for(BookNodePtr b = library[2]; b; b = b->getBookLink()){//find the code in novel category
            if(book_code1 == b->getBook()->getCode() || book_code2 == b->getBook()->getCode() || book_code3 == b->getBook()->getCode()){
                cout << "* " << b->getBook()->getTitle() << "(" << b->getBook()->getCode() << ")" << " - publish date " << b->getBook()->getPublishDate() << endl;
            }
        }     
    }
    else{//searching data for students
        for(PersonNodePtr p = person[1]; p; p = p->getPersonLink()){
            if(person_id == p->getPerson()->getId()){
                cout << "You rented " << p->getPerson()->getCount() << " book(s)." << endl;
                if(p->getPerson()->getCount() == 1){
                    book_code1 = p->getPerson()->getFirstCode();
                }
                else if(p->getPerson()->getCount() == 2){
                    book_code1 = p->getPerson()->getFirstCode();
                    book_code2 = p->getPerson()->getSecondCode();
                }
                break;
            }
        }
        for(BookNodePtr b = library[0]; b != nullptr; b = b->getBookLink()){//search for the code in children category
            if(book_code2 == b->getBook()->getCode() || book_code1 == b->getBook()->getCode()){
                cout << "* " << b->getBook()->getTitle() << "(" << b->getBook()->getCode() << ")" << " - age " << b->getBook()->getAge() << endl;
            }
        }
        for(BookNodePtr b = library[1]; b != nullptr; b = b->getBookLink()){//look for the code in computer category
            if(book_code1 == b->getBook()->getCode() || book_code2 == b->getBook()->getCode()){
                cout << "* " << b->getBook()->getTitle() << "(" << b->getBook()->getCode() << ")" << " - publisher " << b->getBook()->getPublisher() << endl;
            }
        }
        for(BookNodePtr b = library[2]; b != nullptr; b = b->getBookLink()){//look for the code in novel category
            if(book_code1 == b->getBook()->getCode() || book_code2 == b->getBook()->getCode()){
                cout << "* " << b->getBook()->getTitle() << "(" << b->getBook()->getCode() << ")" << " - published date " << b->getBook()->getPublishDate() << endl;
            }
        }
    }
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------
/** implementing menu 5
 * @brief showAllBook func print out every book in the file according to the category
 * @param library - this is BookNodePtr array in which each indexed var is Book_Node pointer
 */
void showAllBook(BookNodePtr library[]){
    
    cout << "==================================================================" << endl;
    cout << "               Children Books" << endl;
    cout << "==================================================================" << endl;
    cout << "code" << setw(20) << "title" << setw(20) << "age" << setw(10) << "available" << setw(8) << "rented" << endl;
    cout << "------------------------------------------------------------------" << endl;
    for(BookNodePtr p = library[0]; p; p = p->getBookLink()){
        string book_title = convertName(p->getBook()->getTitle());
        cout << p->getBook()->getCode() << setw(30) << book_title << setw(9) << p->getBook()->getAge() << setw(8) << p->getBook()->getAvailableBook() << setw(10) << p->getBook()->getRentedBook() << endl;
    }
    cout << endl;

    cout << "===========================================================================" << endl;
    cout << "                      Computer Books" << endl;
    cout << "===========================================================================" << endl;
    cout << "code" << setw(20) << "title" << setw(30) << "publisher" << setw(10) << "available" << setw(8) << "rented" << endl;
    cout << "---------------------------------------------------------------------------" << endl;
    for(BookNodePtr p = library[1]; p; p = p->getBookLink()){
        string book_title = convertName(p->getBook()->getTitle());
        cout << p->getBook()->getCode() << setw(30) << book_title << setw(20) << p->getBook()->getPublisher() << setw(8) << p->getBook()->getAvailableBook() << setw(10) << p->getBook()->getRentedBook() << endl;
    }
    cout << endl;

    cout << "==============================================================================" << endl;
    cout << "                       Novel Books" << endl;
    cout << "==============================================================================" << endl;
    cout << "code" << setw(20) << "title" << setw(30) << "published date" << setw(10) << "available" << setw(8) << "rented" << endl;
    cout << "------------------------------------------------------------------------------" << endl;
    for(BookNodePtr p = library[2]; p; p = p->getBookLink()){
        string book_title = convertName(p->getBook()->getTitle());
        cout << p->getBook()->getCode() << setw(30) << book_title << setw(20) << p->getBook()->getPublishDate() << setw(8) << p->getBook()->getAvailableBook() << setw(10) << p->getBook()->getRentedBook() << endl;
    }
    cout << endl;
}