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
        //std::cout<<this->nelems<<" "<<this->prim->elem<<" "<<this->ult->elem;
    }
    void mezclar(ListaAmpliada<int>& lista2){
        Nodo * i=this->prim,* j=lista2.prim,* k;
        ListaAmpliada<int> lista_aux;
        while(i!=nullptr&&j!=nullptr){
            int n1=i->elem,n2=j->elem;
            if(n1<n2){
                if(lista_aux.prim==nullptr){
                    lista_aux.prim=i;
                    k=lista_aux.prim;
                }
                else{
                    k->sig=i;
                    k=k->sig;
                }
                i=i->sig;
                this->prim=j;
                this->nelems--;
                lista_aux.nelems++;
            }
            else{
                if(lista_aux.prim==nullptr){
                    lista_aux.prim=j;
                    k=lista_aux.prim;
                }
                else{
                    k->sig=j;
                    k=k->sig;
                }
                j=j->sig;
                lista2.prim=j;
                lista2.nelems--;
                lista_aux.nelems++;

            }
        }
        if(i!=nullptr){
            if(lista_aux.prim==nullptr){
                lista_aux.prim=i;
                k=lista_aux.prim;
                lista_aux.nelems++;
                i=i->sig;
                this->prim=j;
                this->nelems--;
            }
            k->sig=i;
            lista_aux.ult=this->ult;
            lista_aux.nelems+=this->nelems;
        }
        else if(j!=nullptr){
            if(lista_aux.prim==nullptr){
                lista_aux.prim=j;
                k=lista_aux.prim;
                lista_aux.nelems++;
                j=j->sig;
                lista2.prim=j;
                lista2.nelems--;
            }
            k->sig=j;
            lista_aux.ult=lista2.ult;
            lista_aux.nelems+=lista2.nelems;
            lista2.prim=nullptr;
            lista2.nelems=0;
        }
        else{
            lista_aux.ult=k;
        }
        this->prim=lista_aux.prim;
        this->ult=lista_aux.ult;
        this->nelems=lista_aux.nelems;
        lista_aux.prim=nullptr;
        lista_aux.ult=nullptr;
        lista_aux.nelems=0;
    }
    int getPrim(){
        return this->prim->elem;
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
