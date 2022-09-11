// Daniel López Marqués
// A39

#include <iostream>
#include <iomanip>
#include <fstream>
#include <stack>
#include <deque>


void volcar(std::stack<char>& pila,std::deque<char>& cola){
    while(!pila.empty()){
        cola.push_front(pila.top());
        pila.pop();
    }
}
std::string print(std::deque<char> cola){
    std::string resultado="";
    while(!cola.empty()){
        resultado+=cola.front();
        cola.pop_front();
    }
    return resultado;
}
// función que resuelve el problema
std::string teclado_estropeado(std::string linea) {
    std::stack<char> pila;
    std::deque<char> cola;
    int modo=1;
    for(char c:linea){
        if(c=='-'){
            volcar(pila,cola);
            modo=0;
        }
        else if(c=='+') {
            volcar(pila,cola);
            modo=1;
        }
        else if(c=='*') {
            if(modo==0){
                pila.push(cola.front());
                cola.pop_front();
            }
        }
        else if(c=='3'){
            if(modo==0) cola.pop_front();
        }
        else{
            if(modo==0) pila.push(c);
            else if(modo==1) cola.push_back(c);
        }
    }
    volcar(pila,cola);
    return print(cola);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    std::string linea;
    std::getline(std::cin,linea);
    if (! std::cin)
        return false;

    std::cout<<teclado_estropeado(linea)<<"\n";
    
    
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