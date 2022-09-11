#ifndef TABLADESEQUILIBRADOS_H
#define TABLADESEQUILIBRADOS_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <set>
#include "bintree_eda.h"

struct info{
    int factor;
    std::string camino;
};
struct tSol1{
    bool equilibrado;
    int altura;
    int factor;
};
class comparador{
public:
    bool operator()(std::pair<char,info> p1,std::pair<char,info> p2){
        return p1.second.factor<p2.second.factor||
                ((p1.second.factor==p2.second.factor)&&p1.second.camino<p2.second.camino);
    }
};
class TablaDesequilibrados {
    std::set<std::pair<char,info>,comparador> lista;
public:
    std::set<std::pair<char,info>,comparador> getLista(){
        return lista;
    }
    tSol1 equilibrado(bintree<char> arbol) {
        if(arbol.empty()) return {true,0};
        else{
            tSol1 iz=equilibrado(arbol.left());
            tSol1 dcha=equilibrado(arbol.right());
            int difAltura=iz.altura-dcha.altura;
            if(difAltura<0) difAltura=0-difAltura;
            bool equilibrado=difAltura==0||difAltura==1;
            int altura=std::max(iz.altura,dcha.altura)+1;
            return {equilibrado,altura,difAltura};
        }
    }
    void recorrerArbol(bintree<char> arbol){
        recorrerArbolInt(arbol,"");
    }
    void recorrerArbolInt(bintree<char> arbol,std::string camino){
        if(!arbol.empty()){
            std::string aux1=camino,aux2=camino;
            recorrerArbolInt(arbol.left(),aux1+="0");
            recorrerArbolInt(arbol.right(),aux2+="1");
            tSol1 equi=equilibrado(arbol);
            if(!equi.equilibrado) lista.insert({arbol.root(),{equi.factor,camino}});
        }
    }
};


#endif
