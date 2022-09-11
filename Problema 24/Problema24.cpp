// Daniel López Marqués
// A39

#include <iostream>
#include <iomanip>
#include <fstream>
#include <stack>

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int len,n,count,borrados;
    std::cin>>len;
    if (len==0)
        return false;
    std::stack<std::pair<int,int>> pila;
    for(int i=0;i<len;i++){
        std::cin>>n;
        count=0;
        if(pila.empty()){
            pila.push({n,0});
        }
        else{
            while(!pila.empty()&&pila.top().first<=n){
                count++;
                count+=pila.top().second;
                pila.pop();
            }

            pila.push({n,count});
        }
        std::cout<<count<<" ";
    }
    std::cout<<"\n";
    
    // escribir sol
    
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
