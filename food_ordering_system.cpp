// Student Name: Nilsu Altıparmak
// Student ID: 22244710047

#include <iostream>
#include <fstream>
#include <string>
#include "linked_list.h"

using namespace std;

struct FoodItem {
    string name;
    double price;
    bool available;

    FoodItem(string n="", double p=0.0, bool a=true):name(n),price(p),available(a){}

    friend ostream& operator<<(ostream& os, const FoodItem& item)
    {
        os << "- " << item.name << " ($" << item.price << ") ["
           << (item.available ? "Available" : "Not Available") << "]";

        return os;
    }

    bool operator==(const FoodItem& other)const{
        return (name ==other.name && price==other.price && available==other.available);
    }
};

const int c_count= 3;  

const string c_names[c_count]= {"Appetizers", "MainCourse", "Desserts"};

int getCategoryIndex(const string& category) {
    for (int i = 0; i < c_count; i++) {
        if (category == c_names[i]) {
            return i;
        }
    }
    return -1; 
}

int main() {
    LinkedList<FoodItem> categories[c_count];  

    ifstream file("menu.txt");
    if (!file.is_open()){
        cerr << "Error opening file" << endl;
        return 1;
    }

    string category;
    string name;
    double price;
    int available;

    while (file >> category >> name >> price >> available){
        int index = getCategoryIndex(category);
        if (index != -1) {
            categories[index].addItem(FoodItem(name, price, available));
        }
    }

    file.close();

    for (int i = 0; i < c_count; i++) {
        cout << "Category: " << c_names[i] << endl;
        categories[i].display();
        cout<<endl;
    }

    return 0;
}
