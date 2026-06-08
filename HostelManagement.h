#ifndef HOSTELMANAGEMENT_H
#define HOSTELMANAGEMENT_H

#include<iostream>
#include<fstream>
#include<windows.h>
#include<sstream>
using namespace std;

// ---------------------- Base Class (Inheritance + Dynamic Polymorphism) ----------------------
class Person{
protected:
    string Name;

public:
    Person() : Name("") {}

    // Static Polymorphism (Function Overloading)
    void setName(string name){
        Name = name;
    }

    void setName(string first, string last){
        Name = first + " " + last;
    }

    string getName(){
        return Name;
    }

    // Dynamic Polymorphism
    virtual void display(){
        cout << "Person Name: " << Name << endl;
    }
    virtual ~Person(){}
};
// ---------------------- Hostel Class ----------------------
class Hostel{
private:
    string Name;
    int Rent, Bed;
public:
    Hostel(string name, int rent, int bed){
        Name = name;
        Rent = rent;
        Bed = bed;
    }
    string getName(){
        return Name;
    }

    int getRent(){
        return Rent;
    }

    int getBed(){
        return Bed;
    }

    void reserve(){
        ifstream in("Hostel.txt");
        ofstream out("Hostel Temp.txt");
        string line;
        while(getline(in, line)){
            int pos = line.find(Name);
            if(pos != string::npos){
                Bed--;
                stringstream ss;
                ss << Bed;
                string strBed = ss.str();
                int bedPos = line.find_last_of(':');
                line.replace(bedPos + 1, string::npos, strBed);
            }
            out << line << endl;
        }
        in.close();
        out.close();
        remove("Hostel.txt");
        rename("Hostel Temp.txt", "Hostel.txt");
        cout << "\tBed Reserved Successfully" << endl;
    }
};

// ---------------------- Student Class (Inheritance) ----------------------
class Student : public Person{

private:
    string Rollno, Address;

public:

    Student() : Rollno(""), Address("") {}

    void setRollno(string rollno){
        Rollno = rollno;
    }

    void setAddress(string address){
        Address = address;
    }

    string getRollno(){
        return Rollno;
    }

    string getAddress(){
        return Address;
    }

    // Dynamic Polymorphism (Function Overriding)
    void display() override{
        cout << "\nStudent Information\n";
        cout << "Name    : " << Name << endl;
        cout << "Roll No : " << Rollno << endl;
        cout << "Address : " << Address << endl;
    }
};

#endif