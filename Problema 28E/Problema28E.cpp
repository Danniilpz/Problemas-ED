// Daniel López Marqués
// A39


#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include "bintree_eda.h"
template <class T>
T minimo(bintree<T> arbol){
        if(arbol.empty()) throw new std::invalid_argument("arbol vacio");
        else if(arbol.left().empty()&&arbol.right().empty()) return arbol.root();
        else if(!arbol.right().empty()&&arbol.left().empty()){
            T elem= minimo(arbol.right());
            return std::min(elem,arbol.root());
        }
        else if(!arbol.left().empty()&&arbol.right().empty()){
            T elem= minimo(arbol.left());
            return std::min(elem,arbol.root());
        }
        else{
            T elemIz=minimo(arbol.left());
            T elemDcha=minimo(arbol.right());
            return std::min({elemIz,elemDcha,arbol.root()});
        }
    }

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    char tipo;
    std::cin>>tipo;
    if (! std::cin)
        return false;
    if(tipo=='N'){
        bintree<int> arbol=leerArbol(-1);
        std::cout<<minimo(arbol)<<"\n";
    }
    else if(tipo=='P'){
        std::string vacio="#";
        bintree<std::string> arbol=leerArbol(vacio);
        std::cout<<minimo(arbol)<<"\n";
    }
    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("1.in");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif


    while (resuelveCaso())
        ;

    
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    
    return 0;
}