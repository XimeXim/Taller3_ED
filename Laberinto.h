//
// Created by Ximena on 10-06-2024.
//

#ifndef LABERINTO_H
#define LABERINTO_H
#include <iostream>
#include <vector>

using namespace std;



class Laberinto {
public:
    //vector matriz
    int inicioX, inicioY;
    int finalX, finalY;
private:
    Laberinto();
    ~Laberinto();
    void cargarArchivo(string nombreTXT);
    void generadorDeLaberinto(int filas, int columnas);
    void imprimirLaberinto();
    void recorridoPorLaberinto(vector<pair<int,int>> camino);
    void resolverLaberinto(Laberinto laberinto);
    void encontrarCamino(Laberinto laberinto, int inicioX,int inicioY);
};



#endif //LABERINTO_H
