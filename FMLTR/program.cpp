#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cmath>

using namespace std;

class Person {
public:
    Person(string name) : name(name) {}
    void addParent(Person* parent) { parents.push_back(parent); }
    void addChild(Person* child) { children.push_back(child); }
    string getName() { return name; }
    vector<Person*> getParents() { return parents; }
    vector<Person*> getChildren() { return children; }

private:
    string name;
    vector<Person*> parents;
    vector<Person*> children;
};

void displayTree(Person* root, int level) {
    for (int i = 0; i < level; i++) cout << "    ";
    cout << root->getName() << endl;
    for (Person* child : root->getChildren()) {
        displayTree(child, level + 1);
    }
}

int main() {
    map<string, Person*> familyTree;

    Person* p1 = new Person("John");
    Person* p2 = new Person("Jane");
    Person* p3 = new Person("Jimmy");
    Person* p4 = new Person("Jenny");
    familyTree["John"] = p1;
    familyTree["Jane"] = p2;
    familyTree["Jimmy"] = p3;
    familyTree["Jenny"] = p4;

    p1->addChild(p3);
    p2->addChild(p3);
    p3->addParent(p1);
    p3->addParent(p2);
    p3->addChild(p4);
    p4->addParent(p3);

    cout << "Family Tree:" << endl;
    displayTree(p1, 0);

    return 0;
}