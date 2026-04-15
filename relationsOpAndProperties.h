#pragma once
void PrintValuesNode(Node* Set);
bool** unific(bool** a, bool** b, int m);        //+
bool** inters(bool** a, bool** b, int m);        //*
bool subset(bool** a, bool** b, int m);          //<
bool reflexivity(bool**matr, int n);             // рефлексивность
bool antireflexivity(bool**matr, int n);         //антирефлексивность
bool symmetry(bool**matr, int n);                //симметричность
bool antisymmetry(bool**matr, int n);            //антисимметричность
bool asymmetry(bool**matr, int n);               //асимметричность
bool** R2(bool**matr, int n);
bool transitivity(bool** matr, int n);           //транзитивность ( R2 <= matr )
bool antitransitivity(bool**matr, int n);        //антитранзитивность ( R2 И matr = o )
bool completeness(bool**matr, int n);            //связность (полнота)