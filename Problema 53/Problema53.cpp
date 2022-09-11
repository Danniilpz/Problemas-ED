//Daniel López Marqués
// A39

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <stdexcept>
#include <fstream>
#include "urgencias.h"


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    urgencias sol;
    std::string func;
    while (std::cin >> func, func != "FIN") {
        if (!std::cin)
            return false;
        try {
            if (func == "nuevo_paciente") {
                std::string param1;
                int param2;
                std::cin >> param1 >> param2;
                sol.nuevo_paciente(param1, param2);
            }
            else if (func == "gravedad_actual") {
                std::string param1;
                std::cin >> param1;
                int x = sol.gravedad_actual(param1);
                std::cout << "La gravedad de " << param1 << " es " << x << std::endl;
            }
            else if (func == "siguiente") {
                std::string x = sol.siguiente();
                std::cout << "Siguiente paciente: " << x << std::endl;
            }
            else if (func == "mejora") {
                std::string param1;
                std::cin >> param1;
                sol.mejora(param1);
            }
            else if (func == "recuperados") {
                std::vector<std::string> x = sol.recuperados();
                std::cout << "Lista de recuperados: ";
                for (std::string y : x) {
                    std::cout << y << " ";
                }
                std::cout << std::endl;
            }
        }
        catch (std::domain_error e) {
            std::cout << "ERROR: " << e.what() << std::endl;
        }
    }
    std::cout << "---" << std::endl;

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