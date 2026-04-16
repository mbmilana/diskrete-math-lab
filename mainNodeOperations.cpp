#include "Node.cpp"
#include "Operations.cpp"
#include <map>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

map<string, int> Commands = {               //словарь команда-номер
    {"new",1},
    {"del",2},
    {"add",3},
    {"rem",4},
    {"pow",5},
    {"see",6},
};