#ifndef IPUD
#define IPUD

#include <iostream>
#include <iomanip>
#include <fstream>
#include <unordered_map>
#include <list>

struct info{
    std::string artista;
    int duracion;
    std::list<std::string>::iterator enPlaylist;
    std::list<std::string>::iterator enRecientes;
};

class ipud{

    std::unordered_map<std::string,info> canciones;
    std::list<std::string> playlist;
    std::list<std::string> recientes;
    int duracionPlaylist=0;
public:
    void addSong(std::string cancion,std::string artista,int duracion){
        if(canciones.count(cancion)!=0) throw std::domain_error("addSong");
        else canciones[cancion]={artista,duracion,playlist.end(),recientes.end()};
    }
    void addToPlaylist(std::string cancion){
        if(canciones.count(cancion)==0) throw std::domain_error("addToPlaylist");
        else if(canciones[cancion].enPlaylist==playlist.end()){
            canciones[cancion].enPlaylist=playlist.insert(playlist.end(),cancion);
            duracionPlaylist+=canciones[cancion].duracion;
        }
    }
    std::string current(){
        if(playlist.size()==0) throw std::domain_error("current");
        else return playlist.front();
    }
    std::string play(){
        if(playlist.size()>0){
            std::string cancion=playlist.front();
            playlist.erase(canciones[cancion].enPlaylist);
            canciones[cancion].enPlaylist=playlist.end();
            duracionPlaylist-=canciones[cancion].duracion;
            if(canciones[cancion].enRecientes==recientes.end()){
                recientes.insert(recientes.begin(),cancion);
            }
            else{
                recientes.erase(canciones[cancion].enRecientes);
                canciones[cancion].enRecientes=recientes.insert(recientes.begin(),cancion);
            }
            return cancion;
        }
        return "";
    }
    int totalTime(){
        return duracionPlaylist;
    }
    std::list<std::string> recent(int n){
        if(n<=recientes.size()) return recientes;
        else{
            std::list<std::string> aux;
            for(std::string c:recientes){
                aux.insert(aux.end(),c);
                if(aux.size()==n) break;
            }
            return aux;
        }
    }
    void deleteSong(std::string cancion){
        if(canciones.count(cancion)!=0){
            playlist.erase(canciones[cancion].enPlaylist);
            recientes.erase((canciones[cancion].enRecientes));
            canciones.erase(cancion);
        }
    }


};
#endif