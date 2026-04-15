#include "mainNodeOperations.cpp"
#include "relationsOpAndProperties.cpp"
#include <fstream>
#include <iomanip>
#include <set>

// 1) чтение множества и чтение отношений
// 2) вывод 8 свойств для каждого отношения

// test1.txt - ни одной пары
// test2.txt - диагональ
// test3.txt - все пары
// test4.txt - частичный порядок
// test5.txt -
// test6.txt - один элемент
// test7.txt - проверка на ошибку
// test8.txt - символы 
// test9.txt - символы и буквы


int main(){
    string filename,                    //имя файла
            str;                        //строки из файла

    cout<<string(60, '-')<<"\nВведите название файла: ";
    while(cin>>filename){               //считывание названий файлов
        stringstream ss;
        int n;                          //можность множества-носителя
        ifstream file(filename);
        if(!file.is_open()){
            cout<<"error: file is not open\n";
            cout<<string(60, '-')<<"\n\n";
            cout<<string(60, '-')<<"\nВведите название файла: ";
            continue;
        }

        getline(file,str);              //чтение элементов
        string el;
        Node* Set = new Node('A');
        ss << str;
        while(getline(ss,el,' ')){
            if(el.size()>1){
                cout<<"Элемент "<<el<<" не может быть добавлен в множество\n";
                continue;
            }
            else Set->Add(el[0]);
        }
        cout<<'\n';

        cout<<"A: "; Set->SeeSet();

        n=Set->Power();                 //можность множества-носителя
        bool** matr=new bool*[n];       //матрица для хранения отношения
        for(int i=0;i<n;++i){
            matr[i]=new bool[n];
            for(int j=0;j<n;++j)
                matr[i][j]=0;
        }

        vector<char> elemsVec = Set->IndexChar();           // значение по индексу
        map<char, int> elemsMap = Set->CharIndex();         // индекс по значению

        while(getline(file, str)){
            bool flag=true;
            vector<char> e;
            ss.str("");
            ss.clear();
            ss << str;
            int countel=0,                                               // количество подхоящих элементов в паре
                i=-1, j=-1;                                              // индексы элемнтов пары
            while(getline(ss,el,' ')){
                if(el.size()>1 || el.size()==1 && !Set->AtSet(el[0])){
                    cout<< "ошибка: пара не добавлена в отношение - " << el<< " не является элементом множества\n";
                    flag=false;
                }
                else {
                    countel++;
                    i=j;
                    j=elemsMap[el[0]];
                }
                if(countel==2 && i>=0 && j>=0){
                    matr[i][j]=1;
                    continue;
                }
            }
        }

        // вывод матрицы
        cout<<"\nМатрица отношения:\n";
        PrintValuesNode(Set);
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(j==0) cout<<elemsVec[i]<<"  ";
                cout<<matr[i][j]<<"  ";
            }
            cout<<'\n';
        }
        cout<<'\n';

        ////////////////////свойства/////////////////////////////////////////
        auto m=matr;
        char ref, anref, sym, ansym, asym, tr, antr, com;
        ref = reflexivity(m, n) ? '+' : '-';
        anref = antireflexivity(m, n) ? '+' : '-';
        sym = symmetry(m, n) ? '+' : '-';
        ansym = antisymmetry(m, n) ? '+' : '-';
        asym = asymmetry(m, n) ? '+' : '-';
        tr = transitivity(m, n) ? '+' : '-';
        antr = antitransitivity(m, n) ? '+' : '-';
        com = completeness(m, n) ? '+' : '-';
        cout<<"Рефлексивность: "<< ref << '\n'
            << "Антирефлексивность: "<< anref <<'\n'
            <<"Симметричность: "<< sym <<'\n'
            <<"Антисимметричность: "<< ansym <<'\n'
            <<"Асимметричность: "<< asym <<'\n'
            <<"Транзитивность: "<< tr <<'\n'
            <<"Антитранзитивность: "<< antr <<'\n'
            <<"Связность: "<< com <<'\n';

        if (ref=='+' && sym=='+' && tr=='+'){       //если явл отношением эквивалентности
            cout<<"\nЯвляется отношением эквивалентности:\nКлассы эквивалентности:\n";

            vector<Node*> classes;                  // классы эквивалентности
            map<char,int> valueClass;               // связь элемента множества и класса

            for(auto c: elemsVec){
                valueClass[c]=0;
            }

            for(int k=0;k<n;++k){
                if(valueClass[elemsVec[k]]>0){continue;}  //элемент уже добавлен в какой-либо класс
                Node* CL=new Node('B'+classes.size());    //новый класс
                CL-> Add(elemsVec[k]);                    //элемент добавлен в класс
                valueClass[elemsVec[k]]=true;             //элемент добавлен в класс
                
                for(int j=0;j<n;++j){
                    if(matr[k][j] && k!=j){
                        CL-> Add(elemsVec[j]);                    //элемент добавлен в класс
                        valueClass[elemsVec[j]]=true;             //элемент добавлен в класс
                    }
                }
                classes.push_back(CL);
            }
            int i=1;
            for(auto CL:classes){                   //вывод классов эквивалентности
                cout<<i++<<": ";
                CL->SeeSet();
            }
            cout<<"индекс разбиения: "<<classes.size() <<"\n";
        }

        if(ref=='+' && ansym=='+' && tr=='+'){                  //если явл частичным порядком

            Node *Maxs=new Node('M'),
                 *Mins=new Node('m');

            //минимальные и максимальные элементы
            for(int j=0;j<n;++j){                               // min
                bool fl=true;
                for(int k=0;k<n;++k){
                    if(j!=k && matr[k][j]){
                        fl=false;
                        break;
                    }
                }
                if (fl) Mins->Add(elemsVec[j]);
            }

            for(int k=0;k<n;++k){                              // max
                bool fl=true;
                for(int j=0;j<n;++j){
                    if(k!=j && matr[k][j]){
                        fl=false;
                        break;
                    }
                }
                if(fl) Maxs->Add(elemsVec[k]);
            }

            if(Mins->next!=nullptr){
                cout<<"\nМинимальные элементы: ";                  // печать min элементов
                Mins->SeeSet();
            }

            if(Maxs->next!=nullptr){
                cout<<"Максимальные элементы: ";                 // печать max элементов
                Maxs->SeeSet();
            }
            
                
            if(Mins->Power()!=1)                                // наименьший и наибольший элементы
                cout<<"\nНаименьшего элемента нет\n";
            else{                                               // проверяем всю строку: если есть хотя бы один 0 => не наименьший
                int naim=elemsMap[Mins->next->value];           // единственный элемент множества
                bool fl=true;
                for(int j=0;j<n;++j){
                    if(matr[naim][j]!=1){
                        fl=false;
                        break;
                    }
                }
                if(fl) cout<<"\nНаименьший: "<<elemsVec[naim]<<'\n';
                else cout<<"\nНаименьшего элемента нет\n";
            }

            if(Maxs->Power()!=1)
                cout<<"\nНаибольшего элемента нет\n";
            else{                                               // проверяем весь столбец: если есть хотя бы один 0 => не наибольший
                int naib=elemsMap[Maxs->next->value];           // единственный элемент множества
                bool fl=true;
                for(int k=0;k<n;++k){
                    if(matr[k][naib]!=1){
                        fl=false;
                        break;
                    }
                }
                if(fl) cout<<"\nНаибольший: "<<elemsVec[naib]<<'\n';
                else cout<<"\nНаибольшего элемента нет\n";
            }
        }
        else cout<<"\nНе является порядком\n";

        cout<<string(60, '-')<<"\n\n";
        cout<<string(60, '-')<<"\nВведите название файла: ";
    }
}