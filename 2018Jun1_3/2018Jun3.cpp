// Daniel López Marqués
// A39


#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include "bintree_eda.h"
#include "TablaDesequilibrados.h"

struct tSol2{
    bool buenPadre;
    bool equilibrado;
};
struct tSol3{
    int numNodosBuenosPadres;
    double porcentaje;
    int totalNodos;
    int totalNodosPadres;
};
tSol1 equilibrado(bintree<char> arbol) {
    if(arbol.empty()) return {true,0};
    else{
        tSol1 iz=equilibrado(arbol.left());
        tSol1 dcha=equilibrado(arbol.right());
        int difAltura=iz.altura-dcha.altura;
        if(difAltura<0) difAltura=0-difAltura;
        bool equilibrado=difAltura==0||difAltura==1;
        int altura=std::max(iz.altura,dcha.altura)+1;
        return {equilibrado,altura,difAltura};

    }

}
bool padre(bintree<char> arbol){
    return !arbol.empty()&&(!arbol.right().empty()||!arbol.left().empty());
}
// función que resuelve el problema
tSol2 buenPadre(bintree<char> arbol){
    if(arbol.empty()) return {false,true};
    else if(!padre(arbol)) return {false,true};
    else{
        tSol2 iz=buenPadre(arbol.left());
        tSol2 dcha=buenPadre(arbol.right());
        bool buenPadre=iz.equilibrado&&dcha.equilibrado;
        bool equi=equilibrado(arbol).equilibrado;
        return {buenPadre,equi};

    }
}
tSol3 porcentaje(bintree<char> arbol){
    if(arbol.empty()) return {0,0,0,0};
    else{
        tSol3 iz=porcentaje(arbol.left());
        tSol3 dcha=porcentaje(arbol.right());
        int numNodosBP=iz.numNodosBuenosPadres+dcha.numNodosBuenosPadres;
        bool buenP=buenPadre(arbol).buenPadre;
        if(buenP) numNodosBP++;
        int numNodosP=iz.totalNodosPadres+dcha.totalNodosPadres;
        if(padre(arbol)) numNodosP++;
        int totalNodos=iz.totalNodos+dcha.totalNodos+1;
        double porcentaje;
        if(numNodosP>0) porcentaje=((double)numNodosBP/(double)numNodosP)*100;
        else porcentaje=100;
        return {numNodosBP,porcentaje,totalNodos,numNodosP};

    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<char> arbol=leerArbol('.');
    // escribir sol
    std::cout<<porcentaje(arbol).porcentaje<<"\n";
    TablaDesequilibrados tabla=TablaDesequilibrados();
    tabla.recorrerArbol(arbol);
    for(std::pair<char,info> p:tabla.getLista()){
        std::cout<<p.first<<" "<<p.second.factor<<" "<<p.second.camino<<"\n";
    }

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