#include "HostelManagement.h"
#include<windows.h>

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

