// Daniel López Marqués
// A39

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <vector>
#include <unordered_map>


using clasificacion=std::unordered_map<std::string,std::unordered_map<std::string,std::pair<bool,int>>>;
struct info{
    int problemas;
    int tiempo;
};
class comparador{
public:
    bool operator()(std::pair<std::string,info> p1,std::pair<std::string,info> p2){
        return (p1.second.problemas>p2.second.problemas)||
                ((p1.second.problemas==p2.second.problemas)&&(p1.second.tiempo<p2.second.tiempo))||
                 ((p1.second.problemas==p2.second.problemas)&&(p1.second.tiempo==p2.second.tiempo)&&(p1.first<p2.first));
    }
};
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    std::unordered_map<std::string,info> equipos;
    clasificacion c;
    std::string equipo,problema,veredicto;
    int tiempo;
    std::cin>>equipo;
    while(equipo!="FIN"){
        std::cin>>problema>>tiempo>>veredicto;
        if(equipos.count(equipo)==0) equipos[equipo]={0,0};
        bool correcto=(veredicto=="AC");
        int tiempoTotal=correcto?tiempo:20;
        if(c[problema].count(equipo)>0) tiempoTotal+=c[problema][equipo].second;
        c[problema][equipo]={correcto,tiempoTotal};
        if(correcto){
            equipos[equipo].problemas++;
            equipos[equipo].tiempo+=tiempoTotal;
        }
        std::cin>>equipo;
    }
    std::vector<std::pair<std::string,info>> aux;

    for(std::pair<std::string,info> p:equipos){
        aux.push_back(p);
    }
    std::sort(aux.begin(),aux.end(),comparador());
    for(std::pair<std::string,info> p:aux){
        std::cout<<p.first<<" "<<p.second.problemas<<" "<<p.second.tiempo<<"\n";
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
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    
    return 0;
}