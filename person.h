/*#ifndef AYE_KYI
#define AYE_KYI

#include <iostream>
using namespace std;

//Person class interface and implementations
class Person{
private:
    int id;
    string name;
    int count;
public:
    Person(): id(0), name(""), count(0){ }
    Person(int person_id, string person_name, int num_of_rented_book): id(person_id), name(person_name), count(num_of_rented_book){ }
    void setId(int person_id){
        id = person_id;
    }
    void setName(string person_name){
        name = person_name;
    }
    void setCount(int num_of_rented_book){
        count = num_of_rented_book;
    }
    int getId(){
        return id;
    }
    string getName(){
        return name;
    }
    int getNumOfRentedBook(){
        return count;
    }
};

//Student class interface
class Student : public Person{
private:
    int code[2];
public:
    //constructors
    Student(){
        code[0] = 0;
        code[1] = 0;
    }
    Student(int first){
        code[0] = first;
        code[1] = 0;
    }
    Student(int first, int second){
        code[0] = first;
        code[1] = second;
    }

    //setters and getters
    void setFirstCode(int first){
        code[0] = first;
    }
    void setSecondCode(int first, int second){
        code[0] = first;
        code[1] = second;
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
    Teacher(){
        code[0] = 0, code[1] = 0, code[2] = 0;
    }
    Teacher(int first){
        code[0] = first, code[1] = 0, code[2] = 0;
    }
    Teacher(int first, int second){
        code[0] = first, code[1] = second, code[2] = 0;
    }
    Teacher(int first, int second, int third){
        code[0] = first, code[1] = second, code[2] = third;
    }

    //setters and getters
    void setFirstCode(int first){
        code[0] = first;
    }
    void setSecondCode(int first, int second){
        code[0] = first;
        code[1] = second;
    }
    void setThirdCode(int first, int second, int third){
        code[0] = first, code[1] = second, code[2] = third;
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

//--------------------------------------------------------------
//Node class for person
class Person_Node{
private:
    Student student;
    Teacher teacher;
    Person_Node* person_link;

public:
    Person_Node():person_link(NULL){ }
    Person_Node(Student stu, Teacher teach, Person_Node* link): student(stu), teacher(teach), person_link(link){ }

    void setStudent(Student stu){
        student = stu;
    }
    void setTeacher(Teacher teach){
        teacher = teach;
    }
    void setPersonLink(Person_Node* link){
        person_link = link;
    }
    Student getStudent(){
        return student;
    }
    Teacher getTeacher(){
        return teacher;
    }
    Person_Node* getPersonLink(){
        return person_link;
    }
};
typedef Person_Node* PersonNodePtr;
void readPersonInfo(PersonNodePtr[]);

#endif*/