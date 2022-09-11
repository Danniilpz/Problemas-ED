// Daniel Lopez Marques
// A39


#include <iostream>
#include <fstream>
#include "gestor_futbolistas.h"

using namespace std;

bool resuelveCaso() {

    string operacion;

    cin >> operacion;

    if (!cin) return false;

    GestorFutbolistas gestorFutbolistas;

    string futbolista, equipo,temp;
    int n, aux;

    while (operacion != "FIN") {

        try {

            if (operacion == "fichar") {

                cin >> futbolista >> equipo;
                gestorFutbolistas.fichar(futbolista, equipo);
            }
            else if (operacion == "ultimos_fichajes") {

                cin >> equipo >> n;
                vector<string> ultimosFichajes = gestorFutbolistas.ultimos_fichajes(equipo, n);

                cout << "Ultimos fichajes de " << equipo << ": ";
                for (auto it : ultimosFichajes) cout << it << " " ;
                cout << endl;
            }
            else if (operacion == "cuantos_equipos") {

                cin >> futbolista;
                aux = gestorFutbolistas.cuantos_equipos(futbolista);

                cout << "Equipos que han fichado a " << futbolista << ": " << aux << "\n";
            }
            else if (operacion == "equipo_actual") {

                cin >> futbolista;
                temp = gestorFutbolistas.equipo_actual(futbolista);

                cout << "El equipo de " << futbolista << " es " << temp << endl;
            }
            else if (operacion == "fichados") {

                cin >> equipo;
                aux = gestorFutbolistas.fichados(equipo);

                cout << "Jugadores fichados por "<< equipo<< ": " << aux <<  endl;
            }  

        }
        catch (domain_error de) {
            cout << "ERROR: " << de.what() << endl;
        }

        cin >> operacion;

    }

    cout << "---\n";
    return true;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

    while (resuelveCaso());

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}