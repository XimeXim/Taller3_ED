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
    char **laberinto;
    int coordXActual;
    int coordYActual;
    int inicioX, inicioY;
    int finalX, finalY;
    bool salidaExiste = false;
    bool fin = false;
    int alto = 0;
    int ancho = 0;

public:
    Laberinto(std::string direccionArchivo);

    ~Laberinto();

    bool getFin() const;

    int getCoordXActual() const;

    void setCoordXActual(int coordXActual);

    int getCoordYActual() const;

    void setCoordYActual(int coordYActual);

    bool get_salida_existe() const;

    void imprimirLaberinto();

    void imprimirLaberintoConRecorrido(int x, int y);

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
    bool verificarArriba();

    /**
     * Metodo que verifica si hay un espacio libre abajo
     * @return True si arriba hay un espacio libre
     */
    bool verificarAbajo();

    /**
     * Metodo que verifica si hay un espacio libre a la derecha
     * @return True si arriba hay un espacio libre
     */
    bool verificarDerecha();

    /**
     * Metodo que verifica si hay un espacio libre a la izquierda
     * @return True si arriba hay un espacio libre
     */
    bool verificarIzquierda();

    /**
     * Metodo que mueve al robot hacia arriba
     */
    int moverArriba();

    /**
     * Metodo que mueve al robot hacia abajo
     */
    int moverAbajo();

    /**
     * Metodo que mueve al robot hacia la derecha
     */
    int moverDerecha();

    /**
     * Metodo que mueve al robot hacia la izquierda
     */
    int moverIzquierda();

    void marcarCamino(int x, int y);

    bool movimientoValido(int x, int y);
};


#endif //LABERINTO_H
