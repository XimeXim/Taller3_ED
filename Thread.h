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
    bool resuelto=false;
    vector<thread> threads;


public:
    Thread(Laberinto &lab);
    ~Thread();
    void resolverLab(int cordXActual, int cordYActual,vector<vector<bool>> &verificado, vector<int,int> camino);
    bool isResuelto();
    void resolver();


};



#endif //THREAD_H
