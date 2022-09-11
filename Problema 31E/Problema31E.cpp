// Daniel López Marqués
// A39


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

struct tSol{
    bool zurdo;
    int numNodos;
};
tSol zurdo (bintree<char> arbol){
    if(arbol.empty()) return {true,0};
    else if(arbol.left().empty()&&arbol.right().empty()) return {true,1};
    else{
        tSol iz=zurdo(arbol.left());
        tSol dcha=zurdo(arbol.right());
        return {iz.zurdo&&dcha.zurdo&&(iz.numNodos>dcha.numNodos),iz.numNodos+dcha.numNodos+1};
    }
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<char> arbol=leerArbol('.');
    // escribir sol
    std::cout<<(zurdo(arbol).zurdo?"SI":"NO")<<"\n";

    
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