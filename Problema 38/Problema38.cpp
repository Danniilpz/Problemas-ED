// Daniel López Marqués
// A39


#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include "bintree_eda.h"

struct tSol{
    int minValue;
    int maxValue;
    bool deBusqueda;
};
// función que resuelve el problema
tSol arbolDeBusqueda(bintree<int> arbol) {
    if(arbol.empty()) return {0,0,true};
    else if(arbol.left().empty()&&arbol.right().empty()) return {arbol.root(),arbol.root(),true};
    else if(arbol.right().empty()){
        tSol iz=arbolDeBusqueda(arbol.left());
        int minValue=std::min(iz.minValue,arbol.root());
        int maxValue=std::max(iz.maxValue,arbol.root());
        return {minValue,maxValue,iz.deBusqueda&&(iz.maxValue<arbol.root())};
    }
    else if(arbol.left().empty()){
        tSol dcha=arbolDeBusqueda(arbol.right());
        int minValue=std::min(dcha.minValue,arbol.root());
        int maxValue=std::max(dcha.maxValue,arbol.root());
        return {minValue,maxValue,dcha.deBusqueda&&(dcha.minValue>arbol.root())};
    }
    else{
        tSol iz=arbolDeBusqueda(arbol.left());
        tSol dcha=arbolDeBusqueda(arbol.right());
        int minValue=std::min({iz.minValue,dcha.minValue,arbol.root()});
        int maxValue=std::max({iz.maxValue,dcha.maxValue,arbol.root()});
        return {minValue,maxValue,iz.deBusqueda&&dcha.deBusqueda&&(iz.maxValue<arbol.root())&&(dcha.minValue>arbol.root())};
    }
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<int> arbol=leerArbol(-1);
    std::cout<<(arbolDeBusqueda(arbol).deBusqueda?"SI":"NO")<<"\n";
    
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("1.in");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif 
    
    
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    
    return 0;
}