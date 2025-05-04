#include <iostream>
#include <string>
#include "LL.h" 
using namespace std;

class ToDoList {
private:
    LL<string> tasks; 

public:
    // Görev ekleme
    void addTask(string task) {
        tasks.insertLast(task);  
        cout << "Task added: " << task << endl;
    }

   
    void listTasks() {
        if (tasks.emptyList()) {
            cout << "No tasks in the list!" << endl;
            return;
        }
        cout << "Tasks List:" << endl;
        cout << tasks; 
    }

    void deleteTask(string task) {
        tasks.deleteNode(task); 
        cout << "Task deleted: " << task << endl;
    }
};

  int main() {
    ToDoList myList;
    string task;
    int choice;

    while(true){
        cout<< "\n1. Add Task\n2. List Tasks\n3. Delete Task\n4. Exit\n";
        cout<< "Choose an option: ";
        cin>> choice;
        cin.ignore(); 

        switch(choice){
            case 1:
                cout << "Enter task: ";
                getline(cin, task);
                myList.addTask(task);
                break;
            case 2:
                myList.listTasks();
                break;
            case 3:
                cout << "Enter task to delete: ";
                getline(cin, task);
                myList.deleteTask(task);
                break;
            case 4:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid option, try again." << endl;
        }
    }

    return 0;
}
