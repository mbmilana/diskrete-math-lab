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

// int main() {

//     string command,
//             str, w;                            //входные данные
//     char setName;                           //входные данные
//     Node** sets = new Node*[26]{ nullptr }; //массив указателей head на множества
//     bool f=false;
//     char value;                             //значение элемента
//     char op,                                //операция над множествами
//         set1, set2;                         //над какими множествами операция
//     Node* res;                              //результат операции над множествами

//     cout << "Введите команду: ";
//     while (getline(cin,str)) {
//         command="unknown";

//         //разделение слов в строке
//         vector<string>words;
//         stringstream ss(str);
//         while(getline(ss,w,' ')){
//             words.push_back(w);
//         }
        
//         if(words.size()>=2)
//             command=words[0];
        
//         switch (Commands[command]) {
//         case 1: //command new
//             setName=words[1][0];
//             if (setName < 'A' || setName>'Z') {
//                 cout << "Некорректное название множества\n";
//                 break;
//             }
//             if (sets[setName - 'A'] != nullptr) {
//                 cout << "Множество " << setName << " уже было создано\n";
//                 break;
//             }
//             f = NewSet(sets, setName);
//             if (f)
//                 cout << "Множество " << setName << " создано\n";
//             else cout << "Множество " << setName << " не было создано\n";
//             break;
//         case 2: //command del
//             setName=words[1][0];
//             if (setName < 'A' || setName>'Z') {
//                 cout << "Некорректное название множества\n";
//                 break;
//             }
//             if (sets[setName - 'A'] == nullptr) {
//                 cout << "Множество " << setName << " не было создано\n";
//                 break;
//             }
//             f = sets[setName - 'A']->Delete();
//             sets[setName - 'A'] = nullptr;
//             if (f) cout << "Множество " << setName << " удалено\n";
//             else cout << "Множества " << setName << " не было создано\n";
//             break;
//         case 3: //coomand add
//             setName=words[1][0];
//             if (setName < 'A' || setName>'Z') {
//                 cout << "Некорректное название множества\n";
//                 break;
//             }
//             if(words.size()>2)
//                 value=words[2][0];
//             else {
//                 cout<<"Некорректная команда\n";
//                 break;
//             }
//             if (sets[setName - 'A'] != nullptr) {
//                 f = sets[setName - 'A']->Add(value);
//                 if (f) cout << "Элемент " << value << " добавлен в множество " << setName << '\n';
//                 else cout << "Элемент " << value << " уже был добавлен в множество " << setName << '\n';
//             }
//             else
//                 cout << "Множество " << setName << " не было создано\n";
//             break;
//         case 4: //command rem
//             setName=words[1][0];
//             if (setName < 'A' || setName>'Z') {
//                 cout << "Некорректное название множества\n";
//                 break;
//             }
//             if(words.size()>2)
//                 value=words[2][0];
//             else {
//                 cout<<"Некорректная команда\n";
//                 break;
//             }
//             if (sets[setName - 'A'] != nullptr) {
//                 f = sets[setName - 'A']->Rem(value);
//                 if (f)
//                     cout << "Элемент " << value << " удален\n";
//                 else
//                     cout << "Элемент " << value << " не найден\n";
//             }
//             else
//                 cout << "Множество " << setName << " не было создано\n";
//             break;
//         case 5: //command pow
//             setName=words[1][0];
//             if (setName < 'A' || setName>'Z') {
//                 cout << "Некорректное название множества\n";
//                 break;
//             }
//             if (sets[setName - 'A'] != nullptr)
//                 sets[setName - 'A']->Pow();
//             else
//                 cout << "Множество " << setName << " не было создано\n";
//             break;
//         case 6: //command see
//             if(words[1].size()==3){
//             setName=words[1][1];
//                 if (setName < 'A' || setName>'Z') {
//                     cout << "Некорректное название множества\n";
//                     break;
//                 }
//                 if (sets[setName - 'A'] != nullptr)
//                     sets[setName - 'A']->SeeSet();
//                 else
//                     cout << "Множество " << setName << " не было создано\n";
//             }
//             else if(words[1]=="[]") {
//                 for (int i = 0; i < 26; ++i)
//                     if (sets[i] != nullptr)
//                         cout << sets[i]->value << ' ';
//                 cout << '\n';
//             }
//             else
//             cout<<"Некорректная команда\n";
//             break;
//         default:
//             if(words.size()!=3){
//                 cout << "Некорректная операция\n";
//                 break;
//             }
//             if (words[0][0] < 'A' || words[0][0] > 'Z' 
//                 || words[2][0] < 'A' || words[2][0] > 'Z') { //если не название множества - неверная команда
//                     cout<<"Операция не может быть выполнена\n";
//                     break;
//             }
//             set1=words[0][0]; op=words[1][0]; set2=words[2][0];
//             if (sets[set1 - 'A'] == nullptr) {
//                 cout << "Множество " << set1 << " не было создано\n";
//                 break;
//             }
//             if (sets[set2 - 'A'] == nullptr) {
//                 cout << "Множество " << set2 << " не было создано\n";
//                 break;
//             }
//             switch (op) {
//             case '+':  //operation unification
//                 res = Unific(sets[set1 - 'A']->next, sets[set2 - 'A']->next);
//                 res->SeeSet();        //вывести объединение
//                 break;
//             case '&':  //operation
//                 res = Inters(sets[set1 - 'A'], sets[set2 - 'A']);
//                 res->SeeSet();        //вывести пересечение
//                 break;
//             case '-':  //operation difference
//                 res = Differ(sets[set1 - 'A'], sets[set2 - 'A']);
//                 res->SeeSet();        //вывести разность
//                 break;
//             case '<':
//                 if (Subset(sets[set1 - 'A'], sets[set2 - 'A']) > 0) 
//                     cout << "Множество " << set1 << " является подмножеством множества " << set2 << '\n';
//                 else 
//                     cout << "Множество " << set1 << " не является подмножеством множества " << set2 << '\n';
//                 break;
//             case '=':
//                 f = Equal(sets[set1 - 'A'], sets[set2 - 'A']);
//                 if (f)
//                     cout << "Множества равны\n";
//                 else
//                     cout << "Множества не равны\n";
//                 break;
//             break;
//             default:
//                 cout << "Некорректная операция\n";
//             }
//         }
//         cout << "\nВведите команду: ";
//     }
//     return 0;
// }