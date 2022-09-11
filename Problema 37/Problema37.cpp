// Daniel López Marqués
// A39


#include <iostream>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include "bintree_eda.h"
struct tSol{
    int pares;
    bool pareado;
};
tSol pareado(bintree<int> arbol){
    if(arbol.empty()) return {0,true};
    else{
        tSol iz=pareado(arbol.left());
        tSol dcha=pareado(arbol.right());
        int difpares=iz.pares-dcha.pares;
        if(difpares<0) difpares*=(-1);
        int numpares=iz.pares+dcha.pares+(arbol.root()%2==0?1:0);
        return {numpares,iz.pareado&&dcha.pareado&&difpares<=1};

    }
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<int> arbol=leerArbol(-1);
    // escribir sol
    std::cout<<(pareado(arbol).pareado?"SI":"NO");
    std::cout<<"\n";

    
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