#ifndef AYE_KYI_LEI
#define AYE_KYI_LEI

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;


//Class interfaces and implementations
//Book class interface and implementations
class Book{
private:
    int code;
    string title;
    int available;
    int rented;
public:
    //constructors
    Book():code(0), title(""), available(0), rented(0){ }
    Book(int book_code, string book_title, int available_book, int rented_book){ 
        code = book_code;
        title = book_title;
        available = available_book;
        rented = rented_book;
    }

    //setters and getters
    void setCode(int book_code){
        code = book_code;
    }
    void setTitle(string book_title){
        title = book_title;
    }
    void setAvailableBook(int available_book){
        available = available_book;
    }
    void setRentedBook(int rented_book){
        rented = rented_book;
    }
    int getCode(){
        return code;
    }
    string getTitle(){
        return title;
    }
    int getAvailableBook(){
        return available;
    }
    int getRentedBook(){
        return rented;
    }
    virtual int getAge(){
        return 0;
    }
    virtual string getPublisher(){
        return "";
    }
    virtual int getPublishDate(){
        return 0;
    }
};

//Children class inherited from Book class
class Children : public Book{
private:
    int age;
public:
    //constructors
    Children():Book(0, "", 0, 0), age(0){ }
    Children(int book_code, string book_title, int child_age, int available_book, int rented_book):
    Book(book_code, book_title, available_book, rented_book), age(child_age){ }

    //setters and getters
    void setAge(int child_age){
        age = child_age;
    };
    int getAge(){
        return age;
    }
};

//Computer class inherited from Book class
class Computer : public Book{
private:
    string publisher;
public:
    //constructors
    Computer():Book(0, "", 0, 0), publisher(""){ }
    Computer(int book_code, string book_title, string book_publisher, int available_book, int rented_book):
    Book(book_code, book_title, available_book, rented_book), publisher(book_publisher){ }

    //setters and getters
    void setPublisher(string book_publisher){
        publisher = book_publisher;
    }
    string getPublisher(){
        return publisher;
    }
};

//Novel class inherited from Book class
class Novel : public Book{
private:
    int publish_date;
public:
    //constructors
    Novel():Book(0, "", 0, 0), publish_date(0){ }
    Novel(int book_code, string book_title, int book_publish_date, int available_book, int rented_book):
    Book(book_code, book_title, available_book, rented_book), publish_date(book_publish_date){ }

    //setters and getters
    void setPublishDate(int book_publish_date){
        publish_date = book_publish_date;
    }
    int getPublishDate(){
        return publish_date;
    }
};

class Book_Node{//for creating linked list
private:
    Book* book;
    Book_Node* book_link;
public:
    Book_Node():book_link(NULL){}
    Book_Node(Book* book_type, Book_Node* link):book(book_type), book_link(link){}
    //setters and getters
    void setBook(Book* book_type){
        book = book_type;
    }
    void setBookLink(Book_Node* link){
        book_link = link;
    }
    Book* getBook(){
        return book;
    }
    Book_Node* getBookLink(){
        return book_link;
    }

};
class Person{
private:
    int id;
    string name;
    int count;
public:
    Person():id(0), name(""), count(0){ }
    Person(int person_id, string person_name, int person_book_count):id(person_id), name(person_name), count(person_book_count){ }
    void setId(int person_id){id = person_id;}
    void setName(string person_name){name = person_name;}
    void setCount(int person_book_count){count = person_book_count;}
    int getId(){return id;}
    string getName(){return name;}
    int getCount(){return count;}
    virtual void setFirstCode(int x){}
    virtual void setSecondCode(int y){}
    virtual void setThirdCode(int z){}
    virtual int getFirstCode(){return 0;}
    virtual int getSecondCode(){return 0;}
    virtual int getThirdCode(){return 0;}
};

//Student class interface
class Student : public Person{
private:
    int code[2];
public:
    //constructors
    Student():Person(0, "", 0){
        code[0] = 0;
        code[1] = 0;
    }
    Student(int student_id, string student_name, int student_book_count):Person(student_id, student_name, student_book_count){ }
    Student(int book_code1, int book_code2){
        code[0] = book_code1;
        code[1] = book_code2;
    }

    //setters and getters
    void setCode(int index, int book_code_data){
        code[index] = book_code_data;
    }
    void setFirstCode(int x){
        code[0] = x;
    }
    void setSecondCode(int y){
        code[1] = y;
    }
    int getFirstCode(){
        return code[0];
    }
    int getSecondCode(){
        return code[1];
    }
};

//Teacher class interface
class Teacher : public Person{
private:
    int code[3];
public:
    //constructors
    Teacher():Person(0, "", 0){
        code[0] = 0, code[1] = 0, code[2] = 0;
    }
    Teacher(int teacher_id, string teacher_name, int teacher_book_count):Person(teacher_id, teacher_name, teacher_book_count){}
    Teacher(int book_code1, int book_code2, int book_code3){
        code[0] = book_code1;
        code[1] = book_code2;
        code[2] = book_code3;
    }

    //setters and getters
    void setCode(int index, int book_code_data){
        code[index] = book_code_data;
    }
    void setFirstCode(int x){
        code[0] = x;
    }
    void setSecondCode(int y){
        code[1] = y;
    }
    void setThirdCode(int z){
        code[2] = z;
    }
    int getFirstCode(){
        return code[0];
    }
    int getSecondCode(){
        return code[1];
    }
    int getThirdCode(){
        return code[2];
    }
};
class Person_Node{
    //general node to create a class pointer that points to pointers of Student_Node and Teacher_Node
private:
    Person* person;
    Person_Node * person_link;
public:
    //constructors for Person_Node classes
    Person_Node():person_link(NULL){ }
    Person_Node(Person* p, Person_Node* link):person(p), person_link(link){ }
    //setters and getters
    void setPerson(Person* p){person = p;}
    void setPersonLink(Person_Node* link){person_link = link;}
    Person* getPerson(){return person;}
    Person_Node* getPersonLink(){return person_link;}
};

typedef Person_Node* PersonNodePtr;
typedef Book_Node* BookNodePtr;

//ordinary func declarations
void readBookInfo(BookNodePtr[]);//this is for reading data from book.txt to three linked lists of Book_Node* type
void readPersonInfo(PersonNodePtr[]);//this is for reading data from person.txt to two linked lists of Person_Node* type
void menu(int& choice, BookNodePtr library[], PersonNodePtr person[]);//this is for the menu and user choices
void menuAction(int choice, BookNodePtr library[], PersonNodePtr person[]);//this is for the action according to user choice
void searchBook(BookNodePtr library[]);//this searches for books in each category (menu 1)
void rentBook(BookNodePtr library[], PersonNodePtr person[]);//this searches the book and update the book and person data (menu 2)
void returnBook(BookNodePtr library[], PersonNodePtr person[]);
void showPersonInfo(BookNodePtr library[], PersonNodePtr person[]);//this shows person information according to id and name (menu 4)
void showAllBook(BookNodePtr library[]);//this shows all books according to their categories (menu 5)
string convertName(string book_name);//this eliminates '_' in book titles
void updateData(BookNodePtr library[], PersonNodePtr p, string book_title, int index);//this updates the data of book and person linked list in renting process
void updateData(PersonNodePtr person[], int person_index, int person_id, int book_code, BookNodePtr b);//this updates the data of book and person linked list in returning process
#endif
