



// Daniel López Marqués
// A39

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <stack>



// función que resuelve el problema
bool equilibrado(std::string const& cad) {
    bool equilibrado = true;
    std::stack<char> caracteres;
    for (char c : cad) {
        if (c == '(' || c == '{' || c == '[') caracteres.push(c);
        else if ((c == ')' || c == '}' || c == ']') && caracteres.empty()) equilibrado = false;
        else if (c == ')') {
            if (caracteres.top() != '(') equilibrado = false;
            else caracteres.pop();
        }
        else if (c == '}') {
            if (caracteres.top() != '{') equilibrado = false;
            else caracteres.pop();
        }
        else if (c == ']') {
            if (caracteres.top() != '[') equilibrado = false;
            else caracteres.pop();
        }
    }
    if(!caracteres.empty()) equilibrado = false;
    return equilibrado;

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    std::string cad;
    std::getline(std::cin, cad);
    if (!std::cin)
        return false;

    bool sol = equilibrado(cad);
    std::cout << (sol ? "SI" : "NO");
    std::cout << "\n";
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