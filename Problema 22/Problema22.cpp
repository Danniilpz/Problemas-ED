// Daniel López Marqués
// A39

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <stack>

struct infoEtiqueta{
    bool esEtiqueta;
    bool cierre;
    char valor;
};
// función que resuelve el problema
infoEtiqueta parsearEtiqueta(std::string& html,int& i) {
    bool esEtiqueta=false,cierre=false;
    char valor;
    int j=i+1;
    if(html[i+1]=='/'){
        cierre=true;
        j++;
    }
    if(html[j]=='p'||html[j]=='b'||html[j]=='i'||html[j]=='q') {
        valor=html[j];
        j++;
        if (html[j] == '>'){
            esEtiqueta = true;
        }
    }
    else{
        valor=' ';
    }
    i=j;
    infoEtiqueta info;
    info.esEtiqueta=esEtiqueta;
    info.valor=valor;
    info.cierre=cierre;
    return info;
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int pCont=0,bCont=0,iCont=0,qCont=0;
    // leer los datos de la entrada
    std::string html;
    std::getline(std::cin,html);
    if (! std::cin)
        return false;
    std::stack<char> etiquetas;
    bool equilibrado = true;
    html=html.substr(6,html.length()-13);
    for(int i=0;i<html.size();i++){
        if(html[i]=='<') {
            infoEtiqueta info=parsearEtiqueta(html,i);
            if(info.esEtiqueta&&!info.cierre){
                switch(info.valor){
                    case 'p':
                        pCont++;
                        break;
                    case 'b':
                        bCont++;
                        break;
                    case 'i':
                        iCont++;
                        break;
                    case 'q':
                        qCont++;
                        break;
                }
            }
            if(info.esEtiqueta){
                if (!info.cierre) etiquetas.push(info.valor);
                else if (info.cierre && etiquetas.empty()) equilibrado = false;
                else if (info.cierre && info.valor == 'p') {
                    if (etiquetas.top() != 'p') equilibrado = false;
                    else etiquetas.pop();
                }
                else if (info.cierre && info.valor == 'b') {
                    if (etiquetas.top() != 'b') equilibrado = false;
                    else etiquetas.pop();
                }
                else if (info.cierre && info.valor == 'i') {
                    if (etiquetas.top() != 'i') equilibrado = false;
                    else etiquetas.pop();
                }
                else if (info.cierre && info.valor == 'q') {
                    if (etiquetas.top() != 'q') equilibrado = false;
                    else etiquetas.pop();
                }
            }
        }
    }
    if(!etiquetas.empty()) equilibrado = false;
    if(equilibrado) std::cout<<"SI "<<pCont<<" "<<bCont<<" "<<iCont<<" "<<qCont<<"\n";
    else std::cout<<"NO\n";
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