#include "Operations.h"
bool NewSet(Node* sets[26], char setName) {
    Node* currentSet = new Node(setName);
    sets[setName - 'A'] = currentSet;           //добавление нового множества в массив
    return true;
}

Node* Unific(Node* s1, Node* s2) {       //объединение
    Node* u = new Node('+'),
        * res = u,                      //результат
        * a = s1, * b = s2;
    while (a != nullptr && b != nullptr) {
        if (a->value < b->value) {                      // a < b - добавляем a
            u->next = new Node(a->value);
            a = a->next;
            u = u->next;
        }
        else if (a->value > b->value) {                 // a > b - добавляем b
            u->next = new Node(b->value);
            b = b->next;
            u = u->next;
        }
        else {                                          //равны - перемещаем оба указателя
            u->next = new Node(a->value);
            a = a->next;
            b = b->next;
            u = u->next;
        }
    }
    while (a != nullptr) {                              //если остались необработанные элементы - добавляем все
        u->next = new Node(a->value);
        a=a->next;
        u = u->next;
    }
    while (b != nullptr) {                              //если остались необработанные элементы - добавляем все
        u->next = new Node(b->value);
        b = b->next;
        u = u->next;
    }
    return res;
}

Node* Inters(Node* s1, Node* s2) {     //пересечение
    Node* n = new Node('&'),
        * res = n,
        * a = s1, * b = s2;
    while (a != nullptr && b != nullptr) {
        while (a!=nullptr && a->value < b->value) {      //если a < b - перемещаем a
            a = a->next;
        }
        while (b!=nullptr && a != nullptr && b->value < a->value) { //если a > b - перемещаем b
            b = b->next;
        }
        while (a != nullptr && b != nullptr && a->value == b->value) { //если равны - добавляем элемент в результат
            n->next = new Node(a->value);
            n = n->next;
            a = a->next;                                               //перемещаем a и b
            b = b->next;
        }
    }
    return res;
}
Node* Differ(Node* s1, Node* s2) {      //разность
    Node* d = new Node('-'),
        * res = d,
        * a = s1->next, * b = s2->next;
    while (a != nullptr && b != nullptr) {
        while (a != nullptr && a->value < b->value) {
            d->next = new Node(a->value);                                              //следующий элемент - a
            d = d->next;                                                               //перемещение на следующий элемент
            a = a->next;
        }
        while (a != nullptr && b!=nullptr && a->value == b->value) {                  //если элементы равны, не добавляем в результат
            a = a->next;
            b = b->next;
        }
        while (a != nullptr && b != nullptr && a->value > b->value) {
            b = b->next;
        }
    }
    while (a != nullptr) {                                             //если в множестве b дошли до конца, оставшиеся элементы из а добавляем без проверки
        d->next = new Node(a->value);                                  //следующий элемент - a
        d = d->next;                                                   //перемещение на следующий элемент
        a = a->next;
    }
    return res;
}

int Subset(Node* s1, Node* s2) {       //подмножество
    Node* a = s1->next,
        *b = s2->next;
    while (a != nullptr && b != nullptr) {
        if (a->value < b->value) {
            return 0;
        }
        else if (a->value > b->value)
            b = b->next;
        else {  //равны
            a = a->next;
            b = b->next;
        }
    }

    if (a == nullptr) {
        return 2;              //явл подмножеством
    }
    return 0;                      //не явл подмножеством
}

bool Equal(Node* s1, Node* s2) {              //равенство
    Node* a = s1->next,
        * b = s2->next;
    while (a != nullptr && b != nullptr) {
        if (a->value != b->value) {
            return 0;
        }
        a = a->next;
        b = b->next;
    }
    if (a != nullptr || b != nullptr) return 0;
    return 1;
}