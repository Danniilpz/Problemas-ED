// Daniel López Marqués
// A39


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

template <class T>
int numeroNodos(bintree<T> arbol){
    if(arbol.empty()) return 0;
    else{
        int numIz=numeroNodos(arbol.left());
        int numDcha=numeroNodos(arbol.right());
        return numIz+numDcha+1;
    }
}
int numHojas(bintree<char> arbol){
    if(arbol.empty()) return 0;
    else{
        int numIz=numHojas(arbol.left());
        int numDcha=numHojas(arbol.right());
        if(numIz==0&&numDcha==0) return 1;
        else return numIz+numDcha;
    }
}
int altura(bintree<char> arbol){
    if(arbol.empty()) return 0;
    else{
        int numIz=altura(arbol.left());
        int numDcha=altura(arbol.right());
        return ((numIz>numDcha)?numIz:numDcha)+1;
    }
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<char> arbol=leerArbol('.');
    // escribir sol
    std::cout<<numeroNodos(arbol)<<" "<<numHojas(arbol)<<" "<<altura(arbol)<<"\n";

    
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