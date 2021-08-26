/*  
Salvador Santana Blanco
A01703523
*/
#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
using namespace std;


class Funciones{
    public:
        long sumaIterativa(int n);
        long sumaRecursiva(int n);
        long sumaDirecta(int n);
};

long Funciones::sumaIterativa(int n){
    int acum=0;
    for(int i=1; i<=n; i++){
        acum += i;
    }
    return acum;
}

long Funciones::sumaRecursiva(int n){
    if(n ==0){
        return 0;
    }else{
        return (n + sumaRecursiva(n-1));
    }
}


long Funciones::sumaDirecta(int n){
    long acum=(n*(n+1))/2;
    return acum;
}

#endif