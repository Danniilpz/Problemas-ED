// Daniel López Marqués
// A39

#include <iostream>
#include <fstream>

#include <list>

void duplicar(std::list<int>& lista){
    for(auto it=lista.cbegin();it!=lista.cend();++it){
        lista.insert(it,*it);
    }
}
void print(std::list<int>& lista){
    for(auto it=lista.crbegin();it!=lista.crend();++it){
        std::cout<<*it<<" ";
    }
}

bool resuelveCaso() {
    int n;
    std::cin >> n;
    if (!std::cin) return false;
    std::list<int> lista;
    for (size_t i = 0; n!=0; ++i) {
        lista.push_front(n);
        std::cin >> n;
    }
    if(!lista.empty()){
        duplicar(lista);
        print(lista);
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
