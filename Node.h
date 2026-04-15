#pragma once
#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Node{
    char value;          //значение
    Node* next;          //указатель на следующий
    Node(char value);
    bool Delete();
    bool Rem(char val);
    bool Add(char value);
    void SeeSet();
    void Pow();
    int Power();
    bool AtSet(char value);
    int Number(char value);
    vector<char> IndexChar();
    map<char, int> CharIndex();
};