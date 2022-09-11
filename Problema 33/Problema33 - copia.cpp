// Daniel López Marqués
// A39

#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

class multiploSiete {
public:
    bool operator()(int n) {
        return n % 7 == 0;
    }
};

class primo {
public:
    bool operator()(int n) {
        if (n == 0 || n == 1 || n == 4) return false;
        for (int i = 2; i < n / 2; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }
};

template<typename T, typename P, typename B>
std::pair<bool, std::pair<T, int >> resolver(bintree<T> const &arbol, P propiedad, B barrera) {
    bool encontrado = false;
    T nodo{};
    int nivel = 0;
    if (arbol.empty()) return {false, {}};
    else if (arbol.left().empty() && arbol.right().empty()&&!barrera(arbol.root()))
        return {propiedad(arbol.root()), {arbol.root(), 1}};

    std::queue<std::pair<int, bintree<T>>> cola;

    if(!barrera(arbol.root())) cola.push({1, arbol});

    while (!cola.empty() && !encontrado) {
        std::pair<int, bintree<T>> const &par = cola.front();
        bintree<T> const &a = par.second;
        if(!barrera(a.root())){
            if (propiedad(a.root())) {
                encontrado = true;
                nodo = a.root();
                nivel = par.first;
            } else {
                if (!a.left().empty())
                    cola.push({par.first + 1, a.left()});
                if (!a.right().empty())
                    cola.push({par.first + 1, a.right()});
            }
        }
        cola.pop();
    }
    return {encontrado, {nodo, nivel}};
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<int> arbol = leerArbol(-1);
    auto p = resolver(arbol, multiploSiete(), primo());
    if (p.first)
        std::cout << p.second.first << ' ' << p.second.second << '\n';
    else
        std::cout << "NO HAY \n";

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