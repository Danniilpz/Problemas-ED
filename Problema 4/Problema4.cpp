// Daniel López Marqués
// A39

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Polinomio.h"

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    Polinomio p=Polinomio();
    int coef,exp;
    std::cin>>coef>>exp;
    if (! std::cin)
        return false;
    
    while(coef!=0){
        p.addMonomio({coef,exp});
        std::cin>>coef>>exp;
    }
    int len;
    std::cin>>len;
    for (int i = 0; i < len; i++) {
        int c;
        std::cin >> c;
        std::cout << p.evaluar(c) << " ";
    }
    std::cout<<"\n";
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