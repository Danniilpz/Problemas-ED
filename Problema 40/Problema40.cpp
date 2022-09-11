// Daniel López Marqués
// A39


#include <iostream>
#include <iomanip>
#include <fstream>
#include "set_eda.h"

template <typename T>
class set_ext: public set<T>{
    using Link = typename set<T>::Link;
private:
    std::pair<bool,T> lower_bound(T const& e,Link r) const{
        if(r==nullptr) return {false,e};
        else if(r->iz!=nullptr&&r->iz->elem>=e) return lower_bound(e,r->iz);
        //else if(r->elem>=e) return {true,r->elem};
        else if(r->elem>=e){
            if(r->iz!=nullptr) {
                std::pair<bool,T> sol=lower_bound(e,r->iz->dr);
                if(sol.first) return sol;
            }
            return {true,r->elem};
        }
        else if(r->dr!=nullptr) return lower_bound(e,r->dr);
        else return {false,e};
    }
public:
    set_ext () : set <T >() {}
    std::pair<bool,T> lower_bound(T const& e) const{
        return this->lower_bound(e,this->raiz);
    }
};


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int len,len2;
    std::cin>>len;
    if (len==0)
        return false;
    set_ext<int> conjunto;
    int n;
    for(int i=0;i<len;i++){
        std::cin>>n;
        conjunto.insert(n);
    }
    std::cin>>len2;
    for(int i=0;i<len2;i++){
        std::cin>>n;
        std::pair<bool,int> sol=conjunto.lower_bound(n);
        if(sol.first) std::cout<<sol.second;
        else std::cout<<"NO HAY";
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
