// Daniel López Marqués
// A39

#include <iostream>
#include <fstream>

#include "queue_eda.h"


template <class T>
class ListaAmpliada : public queue<T> {
    using Nodo = typename queue<T>::Nodo;
public:
    void print() const {
        for(Nodo * i=this->prim;i!=nullptr;i=i->sig){
            std::cout<<i->elem<<" ";
        }
    }
    void mezclar(ListaAmpliada<int>& lista2){
        for(Nodo * i=this->prim,* j=lista2.prim;j!=nullptr;){
            if(this->empty()){
                this->prim=lista2.prim;
                this->ult=lista2.ult;
                j=nullptr;
                lista2.prim=nullptr;
                lista2.ult=nullptr;
            }
            else if(i==this->ult){
                i->sig=j;
                this->ult=lista2.ult;
                j=nullptr;
                lista2.prim=nullptr;
                lista2.ult=nullptr;
            }
            else{
                int n1=(i->sig)->elem,n2=j->elem;
                if(n1>n2){
                    Nodo * siguiente_j=j->sig;
                    j->sig=i->sig;
                    i->sig=j;
                    lista2.prim=siguiente_j;
                    i=i->sig;
                    j=siguiente_j;
                }
                else{
                    i=i->sig;
                }
            }


        }
    }
};



bool resuelveCaso() {
    int n;
    std::cin >> n;
    ListaAmpliada<int> lista1,lista2;
    for (size_t i = 0; n!=0; ++i) {
        lista1.push(n);
        std::cin >> n;
    }
    std::cin >> n;
    for (size_t i = 0; n!=0; ++i) {
        lista2.push(n);
        std::cin >> n;
    }
    if(!lista2.empty()){
        lista1.mezclar(lista2);
    }
    lista1.print();
    std::cout<<"\n";



    return true;
}


int main() {
#ifndef DOMJUDGE
    std::ifstream in("1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}