#pragma once
#include "relationsOpAndProperties.h"

void PrintValuesNode(Node* Set){
    Node*current=Set->next;
    cout<<"   ";
    while(current!=nullptr){
        cout << current->value << "  ";
        current=current->next;
    }
    cout<<'\n';
}

bool** unific(bool** a, bool** b, int n){   // +
    bool** c=new bool*[n];
    for(int i=0;i<n;++i){
        c[i]=new bool[n];
        for(int j=0;j<n;++j)
            c[i][j] = a[i][j] || b[i][j];
    }
    return c;
}

bool** inters(bool** a, bool** b, int n){   // *
    bool** c=new bool*[n];
    for(int i=0;i<n;++i){
        c[i]=new bool[n];
        for(int j=0;j<n;++j)
            c[i][j] = a[i][j] && b[i][j];
    }
    return c;
}

bool subset(bool** a, bool** b, int n){   // <
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j)
            if(a[i][j] < b[i][j])
                return 0;
    }
    return 1;
}



bool reflexivity(bool**matr, int n){            // рефлексивность
    for(int i=0;i<n;++i)
        if(!matr[i][i])
        return false;
    return true;
}

bool antireflexivity(bool**matr, int n){        //антирефлексивность
    for(int i=0;i<n;++i)
        if(matr[i][i])
            return false;
    return true;
}

bool symmetry(bool**matr, int n){               //симметричность
    for(int i=0;i<n;++i)
        for(int j=i+1;j<n;++j)
            if(matr[i][j]!=matr[j][i])
                return false;
    return true;
}

bool antisymmetry(bool**matr, int n){           //антисимметричность
    for(int i=0;i<n;++i)
        for(int j=i+1;j<n;++j)
            if(matr[i][j] && matr[j][i])
                return false;
    return true;
}

bool asymmetry(bool**matr, int n){              //асимметричность
    if(antisymmetry(matr,n)==true && antireflexivity(matr,n)==true)
        return true;
    return false;
}

bool** R2(bool**matr, int n){
    bool**c=new bool*[n];
    for(int i=0;i<n;++i){
        c[i]=new bool[n];
        for(int j=0;j<n;++j)
            for(int k=0;k<n;++k){
                if(matr[i][k] && matr[k][i]){
                    c[i][j]=1;
                    break;
                }
            }
    }
    return c;
}

bool transitivity(bool** matr, int n){          //транзитивность ( R2 <= matr )
    bool**r2=R2(matr, n);
    if(subset(r2,matr,n))
        return true;
    return false;
}

bool antitransitivity(bool**matr, int n){       //антитранзитивность ( R2 И matr = o )
    bool**r2=R2(matr, n);
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            if(r2[i][j] && matr[i][j])
                return false;
    return true;
}

bool completeness(bool**matr, int n){           //связность(полнота)
    for(int i=0;i<n;++i)
        for(int j=i+1;j<n;++j)
            if((matr[i][j] || matr[j][i])==0)
                return false;
    return true;
}