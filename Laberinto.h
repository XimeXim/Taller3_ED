//
// Created by Ximena on 10-06-2024.
//

#ifndef LABERINTO_H
#define LABERINTO_H
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Laberinto {

private:
    char** laberinto;
    int coordXActual;
    int coordYActual;
    int inicioX, inicioY;
    int finalX, finalY;

public:
    Laberinto(std::string nombreArchivo);
    ~Laberinto();
    int alto=0;
    int ancho=0;
    int getCoordXActual() const;
    void setCoordXActual(int coordXActual);
    int getCoordYActual() const;
    void setCoordYActual(int coordYActual);
    void imprimirLaberinto();
    void recorridoPorLaberinto(vector<pair<int,int>> camino);
    void resolverLaberinto(Laberinto laberinto);
    void encontrarCamino();
    /**
     * Metodo que crea el espacio para el laberinto
     * @param laberinto contenido del laberinto
     * @param alto alto del laberinto
     * @param ancho ancho del laberinto
     */
    void espacioLab();

    /**
     * Metodo que verifica si hay un espacio libre arriba
     * @return True si arriba hay un espacio libre
     */
    bool verificarUp();

    /**
     * Metodo que verifica si hay un espacio libre abajo
     * @return True si arriba hay un espacio libre
     */
    bool verificarDown();

    /**
     * Metodo que verifica si hay un espacio libre a la derecha
     * @return True si arriba hay un espacio libre
     */
    bool verificarRight();

    /**
     * Metodo que verifica si hay un espacio libre a la izquierda
     * @return True si arriba hay un espacio libre
     */
    bool verificarLeft();

    /**
     * Metodo que mueve al robot hacia arriba
     */
    void moverArriba();

    /**
     * Metodo que mueve al robot hacia abajo
     */
    void moverAbajo();

    /**
     * Metodo que mueve al robot hacia la derecha
     */
    void moverDerecha();

    /**
     * Metodo que mueve al robot hacia la izquierda
     */
    void moverIzquierda();

    /**
     * Metodo que comprueba si hay salida un camino sin salida por arriba
     * @return True si hay un camino sin salida
     */
    bool noExitUp();

    /**
     * Metodo que comprueba si hay salida un camino sin salida por abajo
     * @return True si hay un camino sin salida
     */
    bool noExitDown();

    /**
     * Metodo que comprueba si hay salida un camino sin salida por la derecha
     * @return True si hay un camino sin salida
     */
    bool noExitRight();

    /**
     * Metodo que comprueba si hay salida un camino sin salida por la izquierda
     * @return True si hay un camino sin salida
     */
    bool noExitLeft();

    /**
     * Metodo que verifica si la salida esta arriba
     * @return True si esta y sale del laberinto
     */
    bool testExitUp();

    /**
     * Metodo que verifica si la salida esta abajo
     * @return True si esta y sale del laberinto
     */
    bool testExitDown();

    /**
     * Metodo que verifica si la salida esta a la derecha
     * @return True si esta y sale del laberinto
     */
    bool testExitRight();

    /**
     * Metodo que verifica si la salida esta a la izquierda
     * @return True si esta y sale del laberinto
     */
    bool testExitLeft();

    //for (int i = 0; i < filas; i++) {
        //for (int j = 0; j < columnas; j++) {
          //  std::cout << matriz[i][j] << " ";
        //}
        //std::cout << std::endl;
    //}
};



#endif //LABERINTO_H
