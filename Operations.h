#pragma once
#include "Node.h"

bool NewSet(Node* sets[26], char setName);
Node* Unific(Node* s1, Node* s2);
Node* Inters(Node* s1, Node* s2);
Node* Differ(Node* s1, Node* s2);
int Subset(Node* s1, Node* s2);
bool Equal(Node* s1, Node* s2);