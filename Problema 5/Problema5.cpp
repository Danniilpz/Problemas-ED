// Daniel López Marqués
// A39

#include <iostream>
#include <iomanip>
#include <fstream>
#include "conjunto.h"
#include <string>


// función que resuelve el problema
template <typename T>
void resolver(T fin,int k) {
    set<T> cjto;
    T n;
    std::cin>>n;
    for(int i=0;cjto.size()<k&&n!=fin;i++){
        cjto.insert(n);
        std::cin>>n;
    }
    while(n!=fin){
        if(!cjto.contains(n)&&n>cjto.get_min()){
            cjto.erase_min();
            cjto.insert(n);
        }
        std::cin>>n;
    }
    cjto.print();
    std::cout<<"\n";
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    char tipo;
    int k;
    std::cin>>tipo>>k;
    if (! std::cin)
        return false;

    if(tipo=='N'){
        resolver(-1,k);
    }
    else if(tipo=='P'){
        std::string aux = "FIN";
        resolver(aux,k);
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