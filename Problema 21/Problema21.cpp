// Daniel López Marqués
// A39

#include <iostream>
#include <iomanip>
#include <fstream>
#include <list>
#include "Persona.h"

// función que resuelve el problema
template <class T, class Predicate>
void remove_if(std::list<T> & lista, Predicate pred){
    for(auto it=lista.cbegin();it!=lista.cend();){
        if(!pred(*it)) it=lista.erase(it);
        else ++it;
    }
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int len,edad_min,edad_max;
    std::cin>>len>>edad_min>>edad_max;
    if (len==0&&edad_max==0&&edad_min==0)
        return false;
    std::list<Persona> personas(len);
    for(Persona& p:personas){
        std::cin>>p;
    }
    remove_if(personas, filtro_edad(edad_min,edad_max));
    for(Persona& p:personas){
        p.print();
        std::cout<<"\n";
    }
    std::cout<<"---\n";
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
