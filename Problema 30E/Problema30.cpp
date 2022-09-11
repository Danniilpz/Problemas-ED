// Daniel López Marqués
// A39


#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include "bintree_eda.h"

struct tSol{
    int equipos;
    int max;
};
// función que resuelve el problema
tSol rescate(bintree<int> arbol) {
    if(arbol.empty()) return {0,0};
    else{
        tSol iz=rescate(arbol.left());
        tSol dcha=rescate(arbol.right());
        int equipos=iz.equipos+dcha.equipos;
        if(arbol.root()>0&&equipos==0) equipos=1;
        int max=std::max(iz.max,dcha.max);
        max+=arbol.root();
        return {equipos,max};
    }
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada

    bintree<int> arbol=leerArbol(-1);
    tSol sol=rescate(arbol);
    std::cout<<sol.equipos<<" "<<sol.max<<"\n";
    
    
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