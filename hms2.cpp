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

// ---------------------- Main Function ----------------------
int main(){
    Hostel h("UET HOSTEL", 5000, 2);
    ofstream out("Hostel.txt");
    out << "\t" << h.getName()
        << "   :   "
        << h.getRent()
        << "  :  "
        << h.getBed()
        << endl << endl;
    cout << "Hostel data saved" << endl;
    out.close();
    Student s;
    bool exit = false;
    while(!exit){
        system("cls");
        int val;
        cout << "\tWelcome to UET Hostel Management System" << endl;
        cout << "\t***************************************" << endl;
        cout << "\t1. Reserve A Bed" << endl;
        cout << "\t2. Exit" << endl;
        cout << "\tEnter Choice: ";
        cin >> val;
        if(val == 1){
            system("cls");
            string name, rollno, address;
            cout << "\tEnter Name of Student: ";
            cin >> name;
            s.setName(name);          // Overloaded version also exists
            cout << "\tEnter Roll No: ";
            cin >> rollno;
            s.setRollno(rollno);
            cout << "\tEnter Address: ";
            cin >> address;
            s.setAddress(address);
            if(h.getBed() > 0){
                h.reserve();
            }
            else{
                cout << "\tSorry, Bed is not available!" << endl;
            }
            ofstream outfile("Student.txt", ios::app);
            outfile
                << "\t"
                << s.getName()
                << "  :  "
                << s.getRollno()
                << "  :  "
                << s.getAddress()
                << endl << endl;
            outfile.close();

            // Dynamic Polymorphism Demonstration
            Person *p = &s;
            p->display();
            Sleep(5000);
        }
        else if(val == 2){
            system("cls");
            exit = true;
            cout << "Program is exiting! Thanks." << endl;

            Sleep(3000);
        }
    }
    return 0;
}