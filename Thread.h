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

    void resolverLab(int x, int y, int hilo);

    void resolverIzquierdaPrimero(int x, int y);

    void resolverArribaPrimero(int x, int y);

    void resolverDerechaPrimero(int x, int y);

    void resolverAbajoPrimero(int x, int y);

    void comienzaAResolver();

    void hiloAvanzaDerecha(int x, int y);

    void hiloAvanzaIzquierda(int x, int y);

    void hiloAvanzaArriba(int x, int y);

    void hiloAvanzaAbajo(int x, int y);
};


#endif //THREAD_H
