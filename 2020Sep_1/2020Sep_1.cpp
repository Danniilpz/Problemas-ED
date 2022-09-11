// Daniel López Marqués
// A39

#include <iostream>
#include <iomanip>
#include <fstream>
#include "deque_eda.h"

template <class T>
class ListaDobleAmpliada:public deque<T>{
    using Nodo=typename deque<T>::Nodo;
public:
    void interseccion(ListaDobleAmpliada<T> lista2){
        Nodo* i=this->fantasma->sig, *j=lista2.fantasma->sig;
        while(i!=this->fantasma&&j!=lista2.fantasma){
            int n1=i->elem,n2=j->elem;
            if(n1<n2){
                Nodo* aux=i->sig;
                eliminarNodo(i);
                i=aux;
            }
            else if(n1>n2){
                Nodo* aux=i->sig;
                eliminarNodo(i);
                i=aux;
                j=j->sig;
            }
            else{
                i=i->sig;
                j=j->sig;
            }

        }
        if(i!=this->fantasma){
            while(i!=this->fantasma){
                Nodo* aux=i->sig;
                eliminarNodo(i);
                i=aux;
            }
        }
    }
    void eliminarNodo(Nodo* aEliminar){
        Nodo* ant=aEliminar->ant,*sig=aEliminar->sig;
        ant->sig=sig;
        sig->ant=ant;
        this->nelems--;
    }
    void print(){
        for(Nodo* i=this->fantasma->sig;i!=this->fantasma;i=i->sig){
            std::cout<<i->elem<<" ";
        }
        std::cout<<"\n";
    }

};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    ListaDobleAmpliada<int> cola1,cola2;
    int n;
    std::cin>>n;
    while(n!=0){
        cola1.push_back(n);
        std::cin>>n;
    }
    std::cin>>n;
    while(n!=0){
        cola2.push_back(n);
        std::cin>>n;
    }
    cola1.interseccion(cola2);
    cola1.print();
    
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