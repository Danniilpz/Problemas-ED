// Daniel López Marqués
// A39

#include <iostream>
#include <iomanip>
#include <fstream>
#include <list>


std::string print(std::list<char> lista){
    std::string resultado="";
    for(char c:lista){
        resultado+=c;
    }
    return resultado;
}
// función que resuelve el problema
std::string teclado_estropeado(std::string linea) {
    std::list<char> lista;
    auto it=lista.cbegin();
    for(char c:linea){
        if(c=='-'){
            it=lista.cbegin();
        }
        else if(c=='+') {
            it=lista.cend();
        }
        else if(c=='*') {
            if(it!=lista.cend()) ++it;
        }
        else if(c=='3'){
            if(it!=lista.cend()) it=lista.erase(it);
        }
        else{
            lista.insert(it,c);
        }
    }
    return print(lista);
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