
#include<iostream>
#include<fstream>
#include"LL.h"
using namespace std;

class Person {
public:
    int id;
    string name;

    friend ostream& operator<<(ostream& os, Person& per) {
        os << per.id << " " << per.name << endl;
        return os;
    } //bu satır sayesinde cout<<people  yazınca tüm liste yazdırılıyor
       
    bool operator==(Person& per) {
        return id == per.id;
    } 
};

int main() {
    ifstream inp("/Users/nilsu/Desktop/inp.dat.txt");
    LL<Person> people;
    Person s;
    while (inp >> s.name >> s.id) {
        people.insertLast(s);
    }

    cout << "Original list:\n" << people;

    s.id = 111;
    node<Person>* p;
    p = people.search(s);
    if (p == NULL)
        cout << "not found...";
    else
        p->info.name = "Cem";

    cout << "\nUpdated list:\n" << people;

    return 0;
}
