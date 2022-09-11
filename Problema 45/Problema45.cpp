// Daniel López Marqués
// A39

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <unordered_map>
#include <set>
#include <vector>
#include <algorithm>


using par=std::pair<std::string,std::set<std::string>>;
using tablon=std::unordered_map<std::string,std::set<std::string>>;
using lista_alumnos=std::unordered_map<std::string,std::string>;
class comparadorDemanda{
public:
    bool operator()(par p1,par p2){
        return p1.second.size()>p2.second.size()||((p1.second.size()==p2.second.size())&&(p1.first<p2.first));
    }
};
void volcar(tablon const& t,std::vector<par>& v){
    for(par p:t){
        v.push_back(p);
    }
}
bool yaApuntado(lista_alumnos& l,std::string alumno){
    if(l.count(alumno)!=0) return true;
    return false;
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    std::string asignatura;
    std::cin>>asignatura;
    if (! std::cin)
        return false;
    std::string alumno;
    tablon t;
    lista_alumnos l;
    while(asignatura!="_FIN_"){
        t[asignatura]={};
        std::cin>>alumno;
        while(alumno!="_FIN_"&&!std::isupper(alumno[0])){
            if(!yaApuntado(l,alumno)){
                    t[asignatura].insert(alumno);
                    l[alumno]=asignatura;
            }
            else if(l[alumno]!=asignatura){
                t[l[alumno]].erase(alumno);
            }
            std::cin>>alumno;
        }
        asignatura=alumno;
    }
    std::vector<par> sol;
    volcar(t,sol);
    std::sort(sol.begin(),sol.end(),comparadorDemanda());
    for(auto p:sol){
        std::cout<<p.first<<" "<<p.second.size()<<"\n";
    }
    std::cout<<"---\n";
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