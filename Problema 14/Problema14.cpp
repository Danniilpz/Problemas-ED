// Daniel López Marqués
// A39

#include <iostream>
#include <fstream>

#include "deque_eda.h"


template <class T>
class ListaDobleAmpliada : public deque<T> {
    using Nodo = typename deque<T>::Nodo;
public:
    void print() const {
        for(Nodo * i=(this->fantasma)->sig;i!=(this->fantasma);i=i->sig){
            std::cout<<i->elem<<" ";
        }
    }
    void invertir(){
        Nodo * siguiente_aux;
        for(Nodo * i=(this->fantasma)->sig;i!=(this->fantasma);i=siguiente_aux){
            siguiente_aux=i->sig;
            i->sig=i->ant;
            i->ant=siguiente_aux;
        }
        siguiente_aux=this->fantasma->sig;
        this->fantasma->sig=this->fantasma->ant;
        this->fantasma->ant=siguiente_aux;
    }
};



bool resuelveCaso() {
    int n;
    std::cin >> n;
    if (!std::cin) return false;
    ListaDobleAmpliada<int> lista;
    for (size_t i = 0; n!=0; ++i) {
        lista.push_back(n);
        std::cin >> n;
    }
    if(!lista.empty()){
        lista.invertir();
        lista.print();
    }
    std::cout<<"\n";



    return true;
}


int main() {
#ifndef DOMJUDGE
    std::ifstream in("1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    while (resuelveCaso()) {} //Resolvemos todos los casos

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
