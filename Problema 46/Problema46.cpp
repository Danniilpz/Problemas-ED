// Daniel López Marqués
// A39


#include <iostream>
#include <iomanip>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <algorithm>

struct info{
    int resueltos;
    int tiempoTotal;
};
using clasificacion=std::unordered_map<std::string,std::unordered_map<std::string,std::pair<bool,int>>>;
// función que resuelve el problema
class comparador{
public:
    bool operator()(std::pair<std::string,info> p1,std::pair<std::string,info> p2){
        return p1.second.resueltos>p2.second.resueltos||
                ((p1.second.resueltos==p2.second.resueltos)&&(p1.second.tiempoTotal<p2.second.tiempoTotal))||
                ((p1.second.resueltos==p2.second.resueltos)&&(p1.second.tiempoTotal==p2.second.tiempoTotal)&&(p1.first<p2.first));
    }
};
void volcar(std::unordered_map<std::string,info> const& t,std::vector<std::pair<std::string,info>>& v){
    for(std::pair<std::string,info> p:t){
        v.push_back(p);
    }
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    std::string line;
    std::getline(std::cin,line);
    clasificacion c;
    std::unordered_map<std::string,info> infoEquipos;
    while(line!="FIN"){
        std::stringstream ss(line);
        std::string equipo,problema,resultado;
        int tiempo,aux;
        while(ss>>equipo>>problema>>tiempo>>resultado){
            if(infoEquipos.count(equipo)==0) infoEquipos[equipo]={0,0};
            if(c[equipo].count(problema)==0||(c[equipo].count(problema)!=0&&!c[equipo][problema].first)){
                if(resultado=="AC"){
                    c[equipo][problema].first=true;
                    c[equipo][problema].second+=tiempo;
                    infoEquipos[equipo].resueltos++;
                    infoEquipos[equipo].tiempoTotal+=c[equipo][problema].second;

                }
                else{
                    c[equipo][problema].first=false;
                    c[equipo][problema].second+=20;
                }
            }
        }
        std::getline(std::cin,line);
    }
    std::vector<std::pair<std::string,info>> sol;
    volcar(infoEquipos,sol);
    std::sort(sol.begin(),sol.end(),comparador());
    for(auto n:sol){
        std::cout<<n.first<<" "<<n.second.resueltos<<" "<<n.second.tiempoTotal<<"\n";
    }
    std::cout<<"---\n";
    
    
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
    std::cin.ignore();
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    
    return 0;
}