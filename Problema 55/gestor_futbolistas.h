#ifndef GESTOR_FUTBOLISTAS
#define GESTOR_FUTBOLISTAS

#include <unordered_map>
#include <map>
#include <set>
#include <stdexcept>
#include <vector>
#include <list>
#include <unordered_set>

class GestorFutbolistas {
private:
    using Futbolista = std::string;
    using Equipo = std::string;
    using TablaIteradoresFutbolista = std::unordered_map<Futbolista, std::list<Futbolista> ::iterator>; // clave : futbolista , valor = iterador a la lista de fichajes del equipo

    using TablaFutbolistas = std::unordered_map <Futbolista, std:: pair <Equipo,std::unordered_set<std::string>> >;  // clave : nombreFutbolista && valor: par de equipo y  equipos distintos por los que ha estado fichado
    using TablaEquipos = std::unordered_map <Equipo, std:: pair <std:: list <Futbolista> , TablaIteradoresFutbolista > >; // clave : nombreEquipo valor : ́par de lista de fichajes y tabla de iteradoras a la lista de fichajes.

    TablaEquipos tablaEquipos;
    TablaFutbolistas tablaFutbolistas;

    
    TablaEquipos::iterator findEquipo(Equipo equipo) { // O(1)
        auto it = tablaEquipos.find(equipo); // O(1)

        if (it == tablaEquipos.end()) throw std::domain_error("Equipo inexistente");

        return it;
    }
    TablaFutbolistas::iterator findFutbolista(Futbolista futbolista) { // O(1)
        auto it = tablaFutbolistas.find(futbolista); // O(1)

        if (it == tablaFutbolistas.end()) throw std::domain_error("Jugador inexistente");

        return it;
    }
    
    void ficharJugadorEnEquipo(Futbolista const & futbolista, std::pair <std::list <Futbolista>, TablaIteradoresFutbolista > &datosEquipo) { // O(1)
        datosEquipo.first.push_back(futbolista); // O(1)
        auto it = --datosEquipo.first.end();
        datosEquipo.second[futbolista] = it; // O(1)
    }

public:
    GestorFutbolistas() {}; //sobrescritura del constructor por defecto

    int fichados(Equipo equipo) { // O(1)
        auto it = findEquipo(equipo);
        return it->second.first.size();
    }
  
    int cuantos_equipos(Futbolista jugador) { // // O(1)

        auto it = tablaFutbolistas.find(jugador);

        if (it == tablaFutbolistas.end()) return 0;

        return it->second.second.size();

    }

    Equipo equipo_actual(Futbolista futbolista) { // O(1)
        auto it = findFutbolista(futbolista);
        return it->second.first;
    }

    std::vector<Futbolista> ultimos_fichajes(Equipo equipo,int n) { // O(n) donde n es el numero de ultimos fichajes
        auto it = findEquipo(equipo);
        std::vector <Futbolista> ultimosFichajes;
        auto& fichajes = it->second.first;
        int i = 0;

        auto itV = fichajes.end();
        
        while (itV != fichajes.begin() && i < n) {
            itV--;
            ultimosFichajes.push_back(*itV);
            i++;
        }
 
        return ultimosFichajes;
    }

    void fichar(Futbolista futbolista, Equipo equipo) {

        auto& datosEquipo = tablaEquipos[equipo]; // 0(1)

        if (!tablaFutbolistas.count(futbolista)) {// Si el futbolista no esta registrado  // O(1)
            tablaFutbolistas.insert({ futbolista, { equipo,{equipo} } }); // O(1)
           
            if (tablaEquipos.count(equipo)) { //Y Si el equipo ya esta registrado  // O(1)
                ficharJugadorEnEquipo(futbolista, datosEquipo); // O(1)
            }
        }

        if (!tablaEquipos.count(equipo)) { // El equipo no esta registrado
            std::list <Futbolista> fichajes;
            fichajes.push_back(futbolista); // O(1)

            TablaIteradoresFutbolista iteradoresFutbolista;
            iteradoresFutbolista[futbolista] = fichajes.begin();

            tablaEquipos.insert({ equipo, {fichajes , iteradoresFutbolista } }); // O(1)
        }

 
        auto& datosFutbolista = tablaFutbolistas[futbolista]; // O(1)
        auto & equipoActual = datosFutbolista.first;

        if (equipoActual != equipo) { // El equipoActual es distinto al equipoNuevo

            auto& datosEquipoAntiguo = tablaEquipos[equipoActual]; // O(1)
            auto& fichajesEquipoAntiguo = datosEquipoAntiguo.first;

            fichajesEquipoAntiguo.erase(datosEquipoAntiguo.second[futbolista]); // O(1)
            datosEquipoAntiguo.second.erase(futbolista); // Lo borramos de la tabla de Futbolistas del equipo // O(1)

            datosFutbolista.second.insert(equipo); // Le insertamos el nuevo equipo // O(1)

            ficharJugadorEnEquipo(futbolista, datosEquipo);  // O(1)

            equipoActual = equipo; // Le cambiamos de equipo
        }

    }
};

#endif


