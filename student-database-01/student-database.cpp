#include <iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/resultset.h>
#include <cppconn/exception.h>
#include <string>
#include <iomanip>
#include <openssl/sha.h> // Include OpenSSL for encryption (SHA)
#include <sstream>

using namespace std;

class Student {
public:
    int id;
    string name;
    int age;
    string grade;
    string email;

    Student(int id, const string& name, int age, const string& grade, const string& email) {
        this->id = id;
        this->name = name;
        this->age = age;
        this->grade = grade;
        this->email = email;
    }
};

class StudentDB {
private:
    sql::mysql::MySQL_Driver *driver;
    sql::Connection *con;

public:
    StudentDB() {
        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "root", "password"); // Change your MySQL credentials
        con->setSchema("student_db");
    }

    ~StudentDB() {
        delete con;
    }

    void addStudent(const Student& student) {
        try {
            sql::PreparedStatement *pstmt;
            pstmt = con->prepareStatement("INSERT INTO students (name, age, grade, email) VALUES (?, ?, ?, ?)");
            pstmt->setString(1, student.name);
            pstmt->setInt(2, student.age);
            pstmt->setString(3, student.grade);
            pstmt->setString(4, student.email);
            pstmt->executeUpdate();
            delete pstmt;
            cout << "Student added successfully!" << endl;
        }
        catch (sql::SQLException &e) {
            cout << "Error: " << e.what() << endl;
        }
    }

    void viewStudents() {
        try {
            sql::PreparedStatement *pstmt;
            pstmt = con->prepareStatement("SELECT * FROM students");
            sql::ResultSet *res = pstmt->executeQuery();
            cout << left << setw(10) << "ID" << setw(20) << "Name" << setw(10) << "Age" << setw(15) << "Grade" << setw(30) << "Email" << endl;
            while (res->next()) {
                cout << left << setw(10) << res->getInt("id")
                     << setw(20) << res->getString("name")
                     << setw(10) << res->getInt("age")
                     << setw(15) << res->getString("grade")
                     << setw(30) << res->getString("email") << endl;
            }
            delete pstmt;
        }
        catch (sql::SQLException &e) {
            cout << "Error: " << e.what() << endl;
        }
    }

    void updateStudent(int id, const Student& student) {
        try {
            sql::PreparedStatement *pstmt;
            pstmt = con->prepareStatement("UPDATE students SET name = ?, age = ?, grade = ?, email = ? WHERE id = ?");
            pstmt->setString(1, student.name);
            pstmt->setInt(2, student.age);
            pstmt->setString(3, student.grade);
            pstmt->setString(4, student.email);
            pstmt->setInt(5, id);
            pstmt->executeUpdate();
            delete pstmt;
            cout << "Student updated successfully!" << endl;
        }
        catch (sql::SQLException &e) {
            cout << "Error: " << e.what() << endl;
        }
    }

    void deleteStudent(int id) {
        try {
            sql::PreparedStatement *pstmt;
            pstmt = con->prepareStatement("DELETE FROM students WHERE id = ?");
            pstmt->setInt(1, id);
            pstmt->executeUpdate();
            delete pstmt;
            cout << "Student deleted successfully!" << endl;
        }
        catch (sql::SQLException &e) {
            cout << "Error: " << e.what() << endl;
        }
    }

    string encryptPassword(const string& password) {
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256_CTX sha256;
        SHA256_Init(&sha256);
        SHA256_Update(&sha256, password.c_str(), password.length());
        SHA256_Final(hash, &sha256);

        stringstream ss;
        for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
            ss << hex << setw(2) << setfill('0') << (int)hash[i];
        }

        return ss.str();
    }
};

int main() {
    StudentDB db;
    int choice;
    while (true) {
        cout << "1. Add Student" << endl;
        cout << "2. View Students" << endl;
        cout << "3. Update Student" << endl;
        cout << "4. Delete Student" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string name, grade, email;
                int age;
                cout << "Enter Name: ";
                cin >> name;
                cout << "Enter Age: ";
                cin >> age;
                cout << "Enter Grade: ";
                cin >> grade;
                cout << "Enter Email: ";
                cin >> email;

                Student student(0, name, age, grade, email); // ID will be auto-generated
                db.addStudent(student);
                break;
            }
            case 2:
                db.viewStudents();
                break;
            case 3: {
                int id;
                string name, grade, email;
                int age;
                cout << "Enter Student ID to Update: ";
                cin >> id;
                cout << "Enter Name: ";
                cin >> name;
                cout << "Enter Age: ";
                cin >> age;
                cout << "Enter Grade: ";
                cin >> grade;
                cout << "Enter Email: ";
                cin >> email;

                Student student(id, name, age, grade, email);
                db.updateStudent(id, student);
                break;
            }
            case 4: {
                int id;
                cout << "Enter Student ID to Delete: ";
                cin >> id;
                db.deleteStudent(id);
                break;
            }
            case 5:
                exit(0);
                break;
            default:
                cout << "Invalid choice, try again!" << endl;
        }
    }

    return 0;
}
