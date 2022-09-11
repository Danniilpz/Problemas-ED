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
    void enlazar(Nodo * nodo1,Nodo * nodo2){
        nodo1->sig=nodo2;
        nodo2->ant=nodo1;
    }
    void mezclar(ListaDobleAmpliada<int>& lista2){
        Nodo * i=(this->fantasma)->sig,* j=(lista2.fantasma)->sig,* siguiente_aux;
        ListaDobleAmpliada<int> lista_aux;
        Nodo * k=lista_aux.fantasma;
        while(i!=(this->fantasma)&&j!=(lista2.fantasma)){
            int n1=i->elem,n2=j->elem;
            if(n1<n2){
                siguiente_aux=i->sig;
                enlazar(k,i);
                enlazar(i,lista_aux.fantasma);
                i=siguiente_aux;
                enlazar(this->fantasma,i);
                k=k->sig;
                this->nelems--;
                lista_aux.nelems++;
            }
            else{
                siguiente_aux=j->sig;
                enlazar(k,j);
                enlazar(j,lista_aux.fantasma);
                j=siguiente_aux;
                enlazar(lista2.fantasma,j);
                k=k->sig;
                lista2.nelems--;
                lista_aux.nelems++;
            }
        }
        if(i!=(this->fantasma)){
            enlazar((lista_aux.fantasma)->ant,this->fantasma->sig);
            enlazar(this->fantasma->ant,lista_aux.fantasma);
            enlazar(this->fantasma,this->fantasma);
            lista_aux.nelems+=this->nelems;
            this->nelems=0;
        }
        else if(j!=(lista2.fantasma)){
            enlazar((lista_aux.fantasma)->ant,lista2.fantasma->sig);
            enlazar(lista2.fantasma->ant,lista_aux.fantasma);
            enlazar(lista2.fantasma,lista2.fantasma);
            lista_aux.nelems+=lista2.nelems;
            lista2.nelems=0;
        }
        enlazar(this->fantasma,lista_aux.fantasma->sig);
        enlazar(lista_aux.fantasma->ant,this->fantasma);
        this->nelems=lista_aux.nelems;
        enlazar(lista_aux.fantasma,lista_aux.fantasma);
        lista_aux.nelems=0;
    }
};



bool resuelveCaso() {
    int n;
    std::cin >> n;
    ListaDobleAmpliada<int> lista1,lista2;
    for (size_t i = 0; n!=0; ++i) {
        lista1.push_back(n);
        std::cin >> n;
    }
    std::cin >> n;
    for (size_t i = 0; n!=0; ++i) {
        lista2.push_back(n);
        std::cin >> n;
    }
    lista1.mezclar(lista2);
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
