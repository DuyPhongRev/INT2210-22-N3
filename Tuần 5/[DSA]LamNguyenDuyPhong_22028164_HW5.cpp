#include <iostream>
#include <map>

using namespace std;

class Student {
private:
    string Name;
    unsigned int ID;
    string Class;
public:
    Student(string Name, unsigned int ID, string Class){
        this->Name = Name;
        this->ID = ID;
        this->Class = Class;
    }
    string getName() const { return Name; }
    string getClass() const { return Class; }
    unsigned int getID() const { return ID; }
};

class ManageStudent {
private:
    map<unsigned int, Student*> studentList;
public:
    void insert(string Name, unsigned int ID, string Class) {
        Student* newStudent = new Student(Name, ID, Class);
        if (studentList.find(ID) == studentList.end()) studentList[ID] = newStudent;
    }
    void remove(unsigned int ID) {
        studentList.erase(ID);
    }
    void information(unsigned int ID) {
        if (studentList.find(ID) != studentList.end())
        {
            cout << "Student " << studentList[ID]->getID() << endl
                << "Name: " << studentList[ID]->getName() << endl
                << "Class: " << studentList[ID]->getClass() << endl;
                return;
        }
        cout << "NA,NA" << endl;
    }
};

int main() {
    ManageStudent* manager = new ManageStudent();
    manager->insert("Leo", 1, "K67");
    manager->information(1);
    manager->remove(1);
    manager->information(1);
    return 0;
}
