// Daniel López Marqués
// A39


#include <iostream>
#include <iomanip>
#include <fstream>
#include <deque>


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int len, k;
    std::cin>>len>>k;
    if (len==0&&k==0)
        return false;
    std::deque<std::pair<int,int>> cola;
    int n;
    for(int i=0;i<len;i++) {
        std::cin >> n;
        while (cola.size() > 0 && cola.back().second < n) {
            cola.pop_back();
        }
        while (cola.size() > 0 &&cola.front().first <= i-k) {
            cola.pop_front();
        }
        cola.push_back({i,n});
        if(i>=(k-1)) std::cout<<cola.front().second<<" ";
    }
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
