//
// Created by Ximena on 10-06-2024.
//

#ifndef THREAD_H
#define THREAD_H
#include <thread>
#include <vector>
#include <mutex>

#include "Laberinto.h"
using namespace std;

class Thread {
private:
    Laberinto &laberinto;
    mutex mtx;
    bool resuelto = false;
    vector<thread> threads;

public:
    Thread(Laberinto &lab);

    ~Thread();

    bool isResuelto();

    /**
     * Metodo que resuelve el laberinto segun el hilo y sus coordenadas
     * @param x coordenada en x del laberinto
     * @param y coordenada en y del laberinto
     * @param hilo indica cual es el hilo que esta usando el metodo
     */
    void resolverLab(int x, int y, int hilo);

    /**
     * Metodo con orden de verificacion con inicio desde la Izquierda
     * @param x coordenada en x del laberinto
     * @param y coordenada en y del laberinto
     */
    void resolverIzquierdaPrimero(int x, int y);

    /**
     * Metodo con orden de verificacion con inicio desde Arriba
     * @param x coordenada en x del laberinto
     * @param y coordenada en y del laberinto
     */
    void resolverArribaPrimero(int x, int y);

    /**
     * Metodo con orden de verificacion con inicio desde la Derecha
     * @param x coordenada en x del laberinto
     * @param y coordenada en y del laberinto
     */
    void resolverDerechaPrimero(int x, int y);

    /**
     * Metodo con orden de verificacion con inicio desde Abajo
     * @param x coordenada en x del laberinto
     * @param y coordenada en y del laberinto
     */
    void resolverAbajoPrimero(int x, int y);

    /**
     * Metodo que da inicio a la resolucion del laberinto, creando hilos para este objetivo
     */
    void comienzaAResolver();
};


#endif //THREAD_H
