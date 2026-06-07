Hostel Management System (C++)

📌 Project Overview

The Hostel Management System is a console-based C++ application designed to manage hostel bed reservations and student records. The project demonstrates the practical implementation of major Object-Oriented Programming (OOP) concepts including Inheritance, Encapsulation, Polymorphism (Static & Dynamic), Abstraction, and File Handling.

This system allows students to reserve hostel beds, store student information, and manage hostel data using text files.

---

✨ Features

- Student registration and information management
- Hostel bed reservation system
- Automatic bed count updates
- Student record storage in files
- Hostel data management using file handling
- Console-based user-friendly interface
- Demonstration of core OOP principles

---

🛠 Technologies Used

- Language: C++
- Compiler: GCC / MinGW / CodeBlocks / Visual Studio
- Concepts: Object-Oriented Programming (OOP)
- Storage: Text Files ("Hostel.txt", "Student.txt")

---

📂 Project Structure

Hostel-Management-System/
│
├── hms2.cpp          # Main source code
├── Hostel.txt        # Stores hostel information
├── Student.txt       # Stores student records
└── README.md         # Project documentation

---

🎯 OOP Concepts Implemented

1. Encapsulation

Data members are kept private and accessed through public member functions.

class Student {
private:
    string Rollno, Address;
};

2. Inheritance

The "Student" class inherits from the "Person" class.

class Student : public Person

3. Static Polymorphism (Compile-Time)

Function overloading is implemented in the "setName()" function.

void setName(string name);
void setName(string first, string last);

4. Dynamic Polymorphism (Run-Time)

Function overriding is achieved through virtual functions.

virtual void display();

5. Abstraction

Classes hide implementation details and expose only required functionalities.

6. File Handling

Data is stored and retrieved using file streams.

ifstream
ofstream

---

🚀 How to Run

Step 1: Clone Repository

git clone https://github.com/Mian-Anas/Hostel-Management-System.git

Step 2: Open Project

Open the project in:

- CodeBlocks
- Dev C++
- Visual Studio
- VS Code

Step 3: Compile

g++ hms2.cpp -o hostel

Step 4: Run

./hostel

---

📋 Program Workflow

1. Application starts.
2. Hostel information is saved.
3. User selects an option.
4. Student enters:
   - Name
   - Roll Number
   - Address
5. System checks bed availability.
6. Bed is reserved if available.
7. Student data is saved to file.
8. Updated information is displayed.

---

📸 Sample Output

Welcome to UET Hostel Management System

1. Reserve A Bed
2. Exit

Enter Choice: 1

Enter Name of Student: Ali
Enter Roll No: 23-CS-101
Enter Address: Lahore

Bed Reserved Successfully

---

📖 Learning Outcomes

This project helps students understand:

- Object-Oriented Programming
- Class Design
- Inheritance
- Encapsulation
- Function Overloading
- Function Overriding
- Virtual Functions
- File Handling
- Console Application Development

---

👥 Contributors

- Anas Ilyas
- Muhammad Azan Faraz
- Muhammad Haseeb ul Hassan

---

📜 License

This project is developed for educational and academic purposes.

Feel free to use, modify, and improve it for learning and research purposes.

---

⭐ Support

If you found this project useful:

- Star the repository ⭐
- Fork the project 🍴
- Contribute improvements 🚀

---

Hostel Management System – A Simple Demonstration of OOP Concepts in C++
