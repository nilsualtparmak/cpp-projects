#include<iostream>
#include<fstream>
#include"ll_airline.h"
using namespace std;

struct flightNode {
    int fno;
    LL<string> pass;
};

int main() {
    flightNode flights[4];
    string comm, name;
    int no;

    // Uçuş numaralarını ayarlıyoruz
    for (int i = 100; i <= 400; i += 100)
        flights[i / 100 - 1].fno = i;

    do {
        cout << "Enter add, delete, list, check or quit: ";
        cin >> comm;

        if (comm == "add" || comm == "Add") {
            cout << "Enter flight no and passenger name: ";
            cin >> no >> name;
            flights[no / 100 - 1].pass.insertLast(name);
        }
        else if (comm == "delete" || comm == "Delete") {
            cout << "Enter flight no and passenger name: ";
            cin >> no >> name;
            flights[no / 100 - 1].pass.deleteNode(name);
        }
        else if (comm == "list" || comm == "List") {
            cout << "Enter flight no: ";
            cin >> no;
            cout << flights[no / 100 - 1].pass;
        }
        else if (comm == "check" || comm == "Check") {
            cout << "Enter passenger name: ";
            cin >> name;
            for (int i = 0; i < 4; i++) {
                if (flights[i].pass.search(name) != NULL)
                    cout << name << " is on flight " << flights[i].fno << endl;
            }
        }
    } while (comm != "quit" && comm != "Quit");

    return 0;
}
