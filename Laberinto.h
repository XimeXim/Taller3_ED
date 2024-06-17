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

    int alto = 0;
    int ancho = 0;
    char** laberinto;
    int coordActual;
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
    /**
     * Metodo que crea el espacio para el laberinto
     * @param laberinto contenido del laberinto
     * @param alto alto del laberinto
     * @param ancho ancho del laberinto
     */
    void espacioLab(char** laberinto, int alto, int ancho);

    bool moverArriba(char** laberinto);

    //for (int i = 0; i < filas; i++) {
        //for (int j = 0; j < columnas; j++) {
          //  std::cout << matriz[i][j] << " ";
        //}
        //std::cout << std::endl;
    //}
};



#endif //LABERINTO_H
