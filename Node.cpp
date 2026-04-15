#include "Node.h"
#include <math.h>

Node::Node(char value) :value(value), next(nullptr) {}

bool Node::Delete() {                         //удаление множества
    Node* current = this,
    *next;
    while (current != nullptr) {
        next = current->next;
        delete current;
        current = next;
    }
    return true;
}

bool Node::Rem(char val) {                      //удаление элемента множества
    Node* set = this->next,                     //текущий элемент
        * prev = this;                          //предыдущий элемент
    if (set == nullptr) return false;
    while (set->next != nullptr && set->value != val) {
        prev = set;
        set = set->next;
    }
    if (set->value == val) {
        prev->next = set->next;
        delete set;
        return true;                            //элемент удален
    }
    return false;                               //элемент не найден
}

bool Node::Add(char value) {                          //добавление элемента
    Node* current = new Node(value);                  //создание текущего элемента
    Node* set = this;
    while (set->next != nullptr && current->value > set->next->value) {
        set = set->next;
    }
    if (set->next!=nullptr && set->next->value == value)
        return false;
    current->next = set->next;                  //добавление элемента на нужную позицию
    set->next = current;
    return true;
}

void Node::SeeSet() {                                 //печать множества
    Node* current = this->next;
    cout << "{ ";
    while (current != nullptr) {
        if (current->next == nullptr) {
            cout << current->value;
            break;
        }
        cout << current->value << " , ";
        current = current->next;
    }
    cout << " }\n";
}

void Node::Pow() {  //2) стр. 27
    Node* current = this->next;
    int n = 0;                                  //количество элементов
    while (current != nullptr) {
        n++;
        current = current->next;
    }
    cout << "{ ";
    for (int mask = 0; mask < pow(2,n); ++mask) {   //количество всех возможных подмножеств
        current = this->next;
        cout << "{ ";
        for (int j = 0; j < n; ++j) {
            if (mask & (1 << j))
                cout << current->value << ' ';
            current = current->next;
        }
        cout << "} ";
    }
    cout << "}\n";
}

int Node::Power(){
    int cnt=0;
    Node* current=this->next;
    while(current!=nullptr){
        ++cnt;
        current=current->next;
    }
    return cnt;
}

bool Node::AtSet(char value){
    Node* current=this->next;
    while(current!=nullptr){
        if(current->value==value)
            return true;
        current=current->next;
    }
    return false;
}

int Node::Number(char value){
    int n=-1;
    Node* current=this->next;
    while(current!=nullptr){
        ++n;
        if(current->value==value)
            return n;
    }
    return n;
}

vector<char> Node::IndexChar(){
    vector<char> elems;
    Node* current=this->next;
    while(current!=nullptr){
        elems.push_back(current->value);
        current=current->next;
    }
    return elems;
}
map<char, int> Node::CharIndex(){
    map<char,int> elems;
    int i=0;
    Node* current=this->next;
    while(current!=nullptr){
        elems[current->value]=i++;
        current=current->next;
    }
    return elems;
}