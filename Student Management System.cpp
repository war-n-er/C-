#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Define the Student class
class Student {
private:
    string name;
    int id;
    float gpa;

public:
    // Constructor
    Student(string n, int i, float g) : name(n), id(i), gpa(g) {}

    // Method to display student details
    void displayStudent() const {
        cout << "ID: " << id << ", Name: " << name << ", GPA: " << gpa << endl;
    }

    // Getters for file storage
    string getName() const { return name; }
    int getId() const { return id; }
    float getGpa() const { return gpa; }
};

// Function to save student data to a file
void saveToFile(const vector<Student>& students, const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (const auto& student : students) {
            file << student.getId() << " " << student.getName() << " " << student.getGpa() << endl;
        }
        file.close();
        cout << "Data saved successfully!" << endl;
    } else {
        cerr << "Error opening file!" << endl;
    }
}

int main() {
    vector<Student> students;
    int choice;

    do {
        cout << "\n1. Add Student\n2. Display All Students\n3. Save to File\n4. Exit\nChoose an option: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string name;
                int id;
                float gpa;
                cout << "Enter ID: ";
                cin >> id;
                cout << "Enter Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter GPA: ";
                cin >> gpa;
                students.emplace_back(name, id, gpa);
                cout << "Student added successfully!" << endl;
                break;
            }
            case 2:
                for (const auto& student : students) {
                    student.displayStudent();
                }
                break;
            case 3:
                saveToFile(students, "students.txt");
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid option! Please try again." << endl;
        }
    } while (choice != 4);
// nnw 
    return 0;
}
