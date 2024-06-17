//
// Created by Ximena on 10-06-2024.
//

#ifndef LABERINTO_H
#define LABERINTO_H
#include <iostream>
#include <vector>
using namespace std;

class Laberinto {

private:

    int alto = 0;
    int ancho = 0;
    char** laberinto;
    int coordXActual;
    int coordYActual;
    int inicioX, inicioY;
    int finalX, finalY;

public:
    Laberinto();
    ~Laberinto();
    int getCoordXActual() const;
    void setCoordXActual(int coordXActual);
    int getCoordYActual() const;
    void setCoordYActual(int coordYActual);
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
    void espacioLab();

    /**
     * Metodo que mueve al robot hacia arriba
     * @return true si se puede mover hacia arriba
     */
    bool moverArriba();

    /**
     * Metodo que mueve al robot hacia abajo
     * @return true si se puede mover hacia abajo
     */
    bool moverAbajo();

    /**
     * true si se puede mover hacia la derecha
     * @return true si se puede mover hacia la derecha
     */
    bool moverDerecha();

    /**
     * true si se puede mover hacia la izquierda
     * @return true si se puede mover hacia la izquierda
     */
    bool moverIzquierda();

    //for (int i = 0; i < filas; i++) {
        //for (int j = 0; j < columnas; j++) {
          //  std::cout << matriz[i][j] << " ";
        //}
        //std::cout << std::endl;
    //}
};



#endif //LABERINTO_H
