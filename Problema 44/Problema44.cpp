// Daniel López Marqués
// A39


#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int len,aux;
    std::cin>>len;
    int act=0,max=0,posAct=0;
    std::map<int,int> mapa;
    for(int i=0;i<len;i++){
        std::cin>>aux;
        if(mapa.find(aux)==mapa.end()){
            act++;
        }
        else{
            if(posAct<=mapa[aux]){
                posAct=mapa[aux]+1;
                act=i-posAct+1;
            }
            else{
                act++;
            }
        }
        mapa[aux]=i;
        max=std::max(act,max);
    }
    std::cout<<max<<"\n";
    
    
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