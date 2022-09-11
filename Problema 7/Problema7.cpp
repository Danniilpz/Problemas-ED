// Daniel López Marqués
// A39

#include <iostream>
#include <iomanip>
#include <fstream>
#include <stack>
#include <string>


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    std::stack<std::pair<std::string, int>> pila;
    int len,victimasMax=0;
    std::cin >> len;
    if (!std::cin)
        return false;
    std::string f;
    int victimas;
    std::cin >> f >> victimas;
    pila.push({ f,victimas });
    std::cout << "NO HAY\n";
    for (int i = 1; i < len; i++) {
        std::cin >> f >> victimas;
        while(!pila.empty()&&pila.top().second<=victimas){
            pila.pop();
        }
        if(pila.empty()){
            pila.push({ f,victimas });
            std::cout << "NO HAY\n";
        }
        else{
            std::cout << pila.top().first<<"\n";
            pila.push({ f,victimas });
        }
    }
    std::cout << "---\n";
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