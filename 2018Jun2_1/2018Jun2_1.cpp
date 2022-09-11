// Daniel López Marqués
// A39

#include <iostream>
#include <iomanip>
#include <fstream>
#include "queue_eda.h"

template <class T>
class ListaAmpliada:public queue<T>{
    using Nodo = typename queue<T>::Nodo;
public:
    void print() const {
        for(Nodo * i=this->prim;i!=nullptr;i=i->sig){
            std::cout<<i->elem<<" ";
        }
    }
    void insertQueue(ListaAmpliada<int>& lista2){
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
                if(i!=this->prim){
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
                else{
                    this->prim = j;
                    Nodo * aux=j;
                    j=j->sig;
                    aux->sig=i;
                    i->sig=j;
                }

            }


        }
    }
};


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    ListaAmpliada<int> cola1,cola2;
    int n;
    std::cin>>n;
    if (! std::cin)
        return false;
    while(n!=0) {
        cola1.push(n);
        std::cin>>n;
    }
    std::cin>>n;
    while(n!=0) {
        cola2.push(n);
        std::cin>>n;
    }
    cola1.insertQueue(cola2);
    cola1.print();
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