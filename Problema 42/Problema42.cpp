// Daniel López Marqués
// A39


#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <vector>
#include <set>
#include <string>
#include <algorithm>


void ref_cruzadas(std::vector<std::string> const& lineas,std::map<std::string,std::set<int>>& mapa){
    for(int i=1;i<=lineas.size();i++){
        std::string linea=lineas[i-1];
        std::transform(linea.begin(),linea.end(),linea.begin(),::tolower);
        std::stringstream ss(linea);
        std::string aux;
        while(ss>>aux){
            if(aux.length()>2) mapa[aux].insert(i);
        }
    }
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int len;
    std::cin>>len;
    if (len==0)
        return false;
    std::cin.ignore();
    std::vector<std::string> lineas;
    for(int i=0;i<len;i++){
        std::string aux;
        std::getline(std::cin,aux);
        lineas.push_back(aux);
    }
    std::map<std::string,std::set<int>> mapa;
    ref_cruzadas(lineas,mapa);
    for(std::pair<std::string,std::set<int>> par:mapa){
        std::cout<<par.first<<" ";
        for(int n:par.second){
            std::cout<<n<<" ";
        }
        std::cout<<"\n";
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
