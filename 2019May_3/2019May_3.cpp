// Daniel López Marqués
// A39

#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"


// función que resuelve el problema
int resolver(bintree<int> arbol,int k,int profundidad) {
    if(arbol.empty()) return 0;
    else if(arbol.left().empty()&&arbol.right().empty()){
        if(profundidad>k) return 1;
        else return 0;
    }
    else{
        int iz=resolver(arbol.left(),k,profundidad+1);
        int dcha=resolver(arbol.right(),k,profundidad+1);
        int numNodos=iz+dcha;
        return numNodos;
    }
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int k;
    std::cin>>k;
    bintree<int> arbol=leerArbol(-1);

    
    std::cout<<resolver(arbol,k,1)<<"\n";
    
    
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