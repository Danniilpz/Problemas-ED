// Daniel López Marqués
// A39


#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>
#include <stack>

void print(std::queue<int> c){
    while(!c.empty()){
        std::cout<<c.front()<<" ";
        c.pop();
    }
}

// función que resuelve el problema
std::queue<int> ordenar(std::queue<int>& c) {
    std::queue<int> q1,q2;
    std::stack<int> s;
    int aux,aux2;
    aux=c.front();
    c.pop();
    q1.push(aux);
    while(!c.empty()){
        aux2=c.front();
        c.pop();
        if(aux>aux2){
            s.push(aux2);
        }
        else{
            q1.push(aux2);
            aux=aux2;
        }
    }
    if(!s.empty()){
        while(!s.empty()){
            aux=s.top();
            s.pop();
            q2.push(aux);
        }
    }
    if(!q1.empty()){
        while(!q1.empty()){
            aux=q1.front();
            q1.pop();
            q2.push(aux);
        }
    }
    return q2;

    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int len;
    std::cin>>len;
    if (len==0)
        return false;
    std::queue<int> c;
    int n;
    for(int i=0;i<len;i++){
        std::cin>>n;
        c.push(n);
    }

    std::queue<int> colaOrd = ordenar(c);
    
    print(colaOrd);
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
