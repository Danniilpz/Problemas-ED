// Daniel López Marqués
// A39


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include "bintree_eda.h"

template <class T>
class bintreeExt:public bintree<T>{
    using Link = typename bintree<T>::Link;
    void frontera(std::vector<int>& v,Link& r){
        if(r!=nullptr){
            if(r->left==nullptr&&r->right==nullptr) v.push_back(r->elem);
            else{
                frontera(v,r->left);
                frontera(v,r->right);
            }
        }
    }
public:
    bintreeExt():bintree<T> (){};
    bintreeExt(bintree<T> const& iz,int const& raiz,bintree<T> const& dcha):bintree<T>(iz,raiz,dcha){};
    void frontera(std::vector<int>& v){
        this->frontera(v,this->raiz);
    }
};

template <class T>
inline bintreeExt<T> leerArbolExt(T vacio) {
    T raiz;
    std::cin >> raiz;
    if (raiz == vacio) { // es un árbol vacío
        return {};
    } else { // leer recursivamente los hijos
        auto iz = leerArbolExt(vacio);
        auto dr = leerArbolExt(vacio);
        return {iz, raiz, dr};
    }
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
   bintreeExt<int> arbol=leerArbolExt(-1);
    std::vector<int> sol;
    arbol.frontera(sol);
    for(int& i:sol) std::cout<<i<<" ";
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