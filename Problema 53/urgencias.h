#ifndef Header
#define Header
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <map>
#include <stdexcept>
#include <set>
#include <list>

using paciente = std::string;
using gravedad = int;

class urgencias {
	std::unordered_map<paciente, std::pair<gravedad, std::list<paciente>::iterator >> pacientes; //los pacientes con su gravedad e iterador para 
//borrar de la lista correspondiente por si se recuperan antes de entrar a consulta
	std::map<gravedad, std::list<paciente>, std::greater<gravedad>> por_gravedad; //sala espera segun gravedades
	std::set<paciente> curados;
	std::list<paciente>::iterator insertar_por_gravedad(paciente p, gravedad g) { // O(log n)
		auto& x = por_gravedad[g];

		return x.insert(x.end(), p);
	}
	std::list<paciente>::iterator insertar_por_gravedad_bg(paciente p, gravedad g) { // O(log n)
		auto& x = por_gravedad[g];

		return x.insert(x.begin(), p);
	}
public:
	urgencias() {};
	void nuevo_paciente(paciente p, gravedad g) { // O(log n)
		auto itP = pacientes.find(p);
		if (g < 1 || g > 3) throw std::domain_error("Gravedad incorrecta");
		if (itP != pacientes.end()) throw std::domain_error("Paciente repetido");
		pacientes[p] = {g,insertar_por_gravedad(p,g)};
	}
	gravedad gravedad_actual(paciente p) { // O(1)
		auto itP = pacientes.find(p);
		if (itP == pacientes.end()) throw std::domain_error("Paciente inexistente");
		
		return itP->second.first; 
	}
	paciente siguiente() { // 0(n) siendo n el num de gravedades

		for (auto const& par : por_gravedad) {
			if (!par.second.empty()) {
				//nos quedamos con el nombre del paciente a atender y lo sacamos de la lista de espera
				paciente sale = par.second.front();
				auto itP = pacientes.find(sale);
				por_gravedad[itP->second.first].pop_front();
				pacientes.erase(itP->first);
				return sale;
			}
		}
		throw std::domain_error("No hay pacientes");

	}
	void mejora(paciente p) { //O(log n)
		auto itP = pacientes.find(p);
		if (itP == pacientes.end()) throw std::domain_error("Paciente inexistente");
		if (itP->second.first - 1 != 0) {
			por_gravedad[itP->second.first].erase(itP ->second.second); //eliminamos cola espera gravedad anterior
			itP->second.first -= 1;//restamos gravedad
			pacientes[itP->first].second = insertar_por_gravedad_bg(itP->first, itP->second.first);//incluimos cola espera gravedad nueva
		}
		else {
			por_gravedad[itP->second.first].erase(itP->second.second); //eliminamos cola espera
			curados.insert(itP->first); //metemos en curados
			pacientes.erase(itP->first); //eliminamos de pacientes
		}
		
	}
	std::vector<paciente> recuperados() { //0(log n)
		std::vector<paciente> x;
		for (auto it = curados.cbegin(); it != curados.cend(); it++) {
			x.push_back((*it));
		}
		return x;
	}
};

#endif // !Urgencias
