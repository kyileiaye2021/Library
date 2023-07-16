#include "header.h"
//#include "person.h"

/**
 * @brief readBookInfo() func read the data from the book.txt file and creates three linked lists 
 */
void readBookInfo(BookNodePtr library[]){
    //three heads for three linked lists
    BookNodePtr childrenBook_head = NULL;
    BookNodePtr computerBook_head = NULL;
    BookNodePtr novelBook_head = NULL;
    
    ifstream infile;
    infile.open("book.txt");
    if(infile.fail()){
        cout << "Input file opening failed." << endl;
        exit(1);
    }

    int book_code = 0, available_book = 0, rented_book = 0, age = 0, book_publish_date = 0;
    string book_title = "", book_publisher = "";

    while(!infile.eof()){
        infile >> book_code;

        //for children book linked list
        if(book_code > 1000 && book_code <= 2000){
            infile >> book_title >> age >> available_book >> rented_book;
            Children* chd = new Children(book_code, book_title, age, available_book, rented_book);//child obj pointer to assign it to the BookNodePtr type pointer and get rid off slice-off problem
            BookNodePtr ptr = new Book_Node;//Children node ptr
            ptr->setBook(chd);//child obj pointer was assigned to the BookNodePtr type pointer
            ptr->setBookLink(NULL);

            //setting up the first node of the children book list
            if(!childrenBook_head){//if the head is NULL, make head point to the ptr
                childrenBook_head = ptr;
                continue;
            }

            if(book_code < childrenBook_head->getBook()->getCode()){//insert the node at the beginning of the list if the number is less than the current first node
                ptr->setBookLink(childrenBook_head); 
                childrenBook_head = ptr;
            }
            else{//insert the node in the middle or at the end of the list
                BookNodePtr temp = childrenBook_head;
                for(; temp->getBookLink() && book_code > temp->getBookLink()->getBook()->getCode(); temp = temp->getBookLink());
                ptr->setBookLink(temp->getBookLink());
                temp->setBookLink(ptr);
            }
        }

        //for computer book linked list
        else if(book_code > 2000 && book_code <= 3000){
            infile >> book_title >> book_publisher >> available_book >> rented_book;
            Computer* c = new Computer(book_code, book_title, book_publisher, available_book, rented_book);//child obj pointer to assign it to the BookNodePtr type pointer and get rid off slice-off problem
            BookNodePtr ptr = new Book_Node;
            ptr->setBook(c);//child obj pointer was assigned to the BookNodePtr type pointer
            ptr->setBookLink(NULL);

            if(!computerBook_head){//setting up the first node of the computer book list
                computerBook_head = ptr;
                continue;
            }

            if(book_code < computerBook_head->getBook()->getCode()){//insert the node at the beginning of the computer list if the number is less than the current first node
                ptr->setBookLink(computerBook_head);
                computerBook_head = ptr;
            }
            else{//insert the node in the middle or at the end of the node
                BookNodePtr temp = computerBook_head;
                for(; temp->getBookLink() && book_code > temp->getBookLink()->getBook()->getCode(); temp = temp->getBookLink());
                ptr->setBookLink(temp->getBookLink());
                temp->setBookLink(ptr);
            }
            
        }

        //for novel book linked list
        else{
            infile >> book_title >> book_publish_date >> available_book >> rented_book;
            Novel* n = new Novel(book_code, book_title, book_publish_date, available_book, rented_book);//child obj pointer to assign it to the BookNodePtr type pointer and get rid off slice-off problem
            BookNodePtr ptr = new Book_Node;
            ptr->setBook(n);//child obj pointer was assigned to the BookNodePtr type pointer
            ptr->setBookLink(NULL);

            if(!novelBook_head){//setting up the first node of the novel book list
                novelBook_head = ptr;
                continue;
            }

            if(book_code < novelBook_head->getBook()->getCode()){
                ptr->setBookLink(novelBook_head);
                novelBook_head = ptr;
            }
            else{
                BookNodePtr temp = novelBook_head;
                for(; temp->getBookLink() && book_code > temp->getBookLink()->getBook()->getCode(); temp = temp->getBookLink());
                ptr->setBookLink(temp->getBookLink());
                temp->setBookLink(ptr);
            }

        }

    }
    //assigning each linked list into each index Book_Node pointer of the library array
    library[0] = childrenBook_head;
    library[1] = computerBook_head;
    library[2] = novelBook_head;

    cout << endl;
}

/**
 * @brief readPersonInfo func read the data of person txt file to create linked lists and assign those linked list into static array
 * @param person - PersonNodePtr type static array
 */
void readPersonInfo(PersonNodePtr person[]){
    PersonNodePtr studentHead = NULL;
    PersonNodePtr teacherHead = NULL;

    ifstream infile;
    infile.open("person.txt");
    if(infile.fail()){
        cout << "Input file opening." << endl;
        exit(1);
    }

    int person_id = 0, person_book_count = 0, book_code = 0;
    string person_name = "";

    while(!infile.eof()){
        infile >> person_id;

        if(person_id > 0 && person_id <= 100){//read data for teachers
            infile >> person_name >> person_book_count;
            Teacher* teach = new Teacher(person_id, person_name, person_book_count);//child obj pointer to assign it to the PersonNodePtr type pointer and get rid off slice-off problem

            for(int i = 0; i < person_book_count; i++){//setting up the data of book codes
                infile >> book_code;
                teach->setCode(i, book_code);
            }

            PersonNodePtr ptr = new Person_Node;
            ptr->setPerson(teach);//child obj pointer was assigned to the PersonNodePtr type pointer
            ptr->setPersonLink(NULL);

            if(!teacherHead){
                teacherHead = ptr;
                continue;
            }
            if(person_id < teacherHead->getPerson()->getId()){
                ptr->setPersonLink(teacherHead);
                teacherHead = ptr;
            }
            else{
                PersonNodePtr temp = teacherHead;
                for(; temp->getPersonLink() && person_id > temp->getPersonLink()->getPerson()->getId(); temp = temp->getPersonLink());
                ptr->setPersonLink(temp->getPersonLink());
                temp->setPersonLink(ptr);
            }
        }

        else{
            infile >> person_name >> person_book_count;
            Student* stu = new Student(person_id, person_name, person_book_count);//child obj pointer to assign it to the BookNodePtr type pointer and get rid off slice-off problem

            for(int i = 0; i < person_book_count; i++){
                infile >> book_code;
                stu->setCode(i, book_code);
            }
            PersonNodePtr ptr = new Person_Node;
            ptr->setPerson(stu);//child obj pointer was assigned to the PersonNodePtr type pointer
            ptr->setPersonLink(NULL);

            if(!studentHead){
                studentHead = ptr;
                continue;
            }

            if(person_id < studentHead->getPerson()->getId()){
                ptr->setPersonLink(studentHead);
                studentHead = ptr;
            }
            else{
                PersonNodePtr temp = studentHead;
                for(; temp->getPersonLink() && person_id > temp->getPersonLink()->getPerson()->getId(); temp = temp->getPersonLink());
                ptr->setPersonLink(temp->getPersonLink());
                temp->setPersonLink(ptr);
            }
        }
    }
    //assigning each linked list into each index Person_Node pointer of the person array
    person[0] = teacherHead;
    person[1] = studentHead;
}

/**
 * @brief convertName func eliminates '_' in the titles of book
 * @param book_name - this is the book title 
 * @return string 
 */
string convertName(string book_name){
    string res = "";
    for(int i = 0; i < book_name.length(); i++){
        if(book_name[i] == '_'){
            res += " ";
        }
        else{
            res += book_name[i];
        }
    }
    return res;
}

/**
 * @brief updateData func updates the data of available and rented books and the num of books that the person already rented in renting process
 * @param library - this is library array of Book_Node* type in which each indexed variable is the head of Book_Node type linked list
 * @param p - this is the linked list of Person_Node* type (person[0] or person[1])
 * @param book_title - this is the name of book that the person wants to rent
 * @param index - this is the index of the linked list of books
 */
void updateData(BookNodePtr library[], PersonNodePtr p, string book_title, int index){
    for(BookNodePtr b = library[index]; b; b = b->getBookLink()){//search for the book
        if(book_title == b->getBook()->getTitle()){
            if(b->getBook()->getAvailableBook() <= 0){//check the book is available or not
                throw book_title;
            }
            else{
                b->getBook()->setAvailableBook(b->getBook()->getAvailableBook() - 1);//reduce the number of available books
                b->getBook()->setRentedBook(b->getBook()->getRentedBook() + 1);//increase the number of rent in book info
                p->getPerson()->setCount(p->getPerson()->getCount() + 1);//increase the number of books that the teacher rented in teacher info
                //update the info of new book code that the person rents
                if(p->getPerson()->getCount() == 1){
                    p->getPerson()->setFirstCode(b->getBook()->getCode());
                }
                else if(p->getPerson()->getCount() == 2){
                    p->getPerson()->setSecondCode(b->getBook()->getCode());
                }
                else{
                    p->getPerson()->setThirdCode(b->getBook()->getCode());
                }
                cout << "***** Rent succeed. Check your info!" << endl;
            }
        }
    }                          
}

/**
 * @brief updateData func updates the data of available and rented books and the num of books that the person already rented in returning process
 * @param person - this is person array of Person_Node* type in which each indexed variable is the head of Person_Node type linked list
 * @param person_index - this is the index of the person array(person[0] or person[1])
 * @param person_id - this is the id number of the person 
 * @param book_code - this is the book code of the book that the person wants to return
 * @param b - Book_Node pointer type pointing to the cuurent book type linked list node
 */
void updateData(PersonNodePtr person[], int person_index, int person_id, int book_code, BookNodePtr b){
     for(PersonNodePtr p = person[person_index]; p; p = p->getPersonLink()){
        if(person_id == p->getPerson()->getId()){
            if(p->getPerson()->getCount() <= 0){//if the num of books that the person rented is 0, there is an exception
                throw book_code;
            }
            if(p->getPerson()->getCount() == 1 && p->getPerson()->getFirstCode() == book_code){//if the num of books that the person rented is 1, reassign the value of 0 int0 code[0]
                p->getPerson()->setFirstCode(0);
            }
            else if(p->getPerson()->getCount() == 2){//if the num of books that the person rented is 2
                if(p->getPerson()->getFirstCode() == book_code){//if the first code is equal to book code
                    p->getPerson()->setFirstCode(p->getPerson()->getSecondCode());//set the value of code[1] to code[0]
                }
                p->getPerson()->setSecondCode(0);//set the value of 0 to code[1] if the code[1] is equal to book code
            }
            else{//if the num of books that the person rented is 3
                if(p->getPerson()->getFirstCode() == book_code){//if the first code is equal to book code
                    p->getPerson()->setFirstCode(p->getPerson()->getSecondCode());//set the value of code[1] to code[0]
                    p->getPerson()->setSecondCode(p->getPerson()->getThirdCode());//set the value of code[2] to code[1]
                }
                else if(p->getPerson()->getSecondCode() == book_code){//if the second code is equal to book code
                    p->getPerson()->setSecondCode(p->getPerson()->getThirdCode());//set the value of code[2] to code[1]
                }
                p->getPerson()->setThirdCode(0);//set the value of 0 to code[2] if the third code is equal to book code
            }
            p->getPerson()->setCount(p->getPerson()->getCount() - 1);//decrease the num of books that the person rented by 1
            b->getBook()->setAvailableBook(b->getBook()->getAvailableBook() + 1);//increase the available num of book by 1
            b->getBook()->setRentedBook(b->getBook()->getRentedBook() - 1);//decrease the rent num of book by 1
            cout << "***** Return succeed. Check your info!" << endl;
            break;
        }
    }
}