//
// Created by Ximena on 10-06-2024.
//

#ifndef THREAD_H
#define THREAD_H
#include <thread>
#include <vector>

#include "Laberinto.h"
using namespace std;

class Thread {
public:
    Laberinto laberinto;


private:
    Thread(Laberinto laberinto, pair<int,int> inicio, vector<pair<int,int>> final);
    ~Thread();

};



#endif //THREAD_H
