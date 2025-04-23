// test_list.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <list>
#include <string>
#include <iostream>

using namespace std;

class Students {
private:
    string name;
    double gpa;
public:
    Students(string n = "NoName", double g = 0.0) : name(n), gpa(g) {};

    string getName() { return name; }
    double getGpa() { return gpa; }

    void print() {
        cout << "Student name: " << name << ",\t Student GPA: " << gpa << endl;
    }

    friend bool operator< (Students& s1, Students& s2) {
        return (s1.name < s2.name);
    }

    friend ostream& operator<< (ostream& sout, Students& s) {
        sout << "Name: " << s.name << ", GPA: " << s.gpa << endl;
        return sout;
    }

    friend bool operator== (Students& s1, Students& s2) {
        return (s1.name == s2.name) && (s1.gpa == s2.gpa);
    }
};

void printL(list<Students> s, string title = "") {
    cout << title << endl;
    for (Students ss : s) {
        ss.print();
    }
}

void test01() {
    list<Students> std{
        {"Aman", 4.0},
        {"Jeren", 2.0},
        {"Kakajan", 3.3},
        {"Meret", 1.0}
    };

    printL(std, "Students in the beginning: ");
}

int main()
{
    test01();



    cout << "\nAll Done!\n";
}

