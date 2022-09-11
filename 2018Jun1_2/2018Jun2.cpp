// Daniel López Marqués
// A39

#include <iostream>
#include <iomanip>
#include <fstream>
#include <stack>
#include "list_eda.h"



// función que resuelve el problema
void invertirSegmento(list<char>& lista,int ini,int len) {
    std::stack<char> aux;
    list<char> sol;
    int i=1;
    for(char c:lista){
        if(i<ini||i>ini+len) sol.insert(sol.end(),c);
        else if(i>=ini&&i<ini+len) aux.push(c);
        else if(i==ini+len){
            while(aux.size()>0) {
                sol.insert(sol.end(),aux.top());
                aux.pop();
            }
            sol.insert(sol.end(),c);
        }
        i++;
    }
    lista=sol;
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    char c;
    std::cin>>c;
    list<char> lista;
    if (! std::cin)
        return false;
    while(c!='#'){
        lista.insert(lista.end(),c);
        std::cin>>c;
    }
    int i,k;
    std::cin>>i>>k;
    invertirSegmento(lista,i,k);
    for(char c:lista){
        std::cout<<c<<" ";
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