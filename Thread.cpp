//
// Created by Ximena on 10-06-2024.
//

#include "Thread.h"


Thread::Thread(Laberinto &lab): laberinto(lab),resuelto(false) {
}

Thread::~Thread() {
}

void Thread::resolverLab(int cordXActual, int cordYActual, vector<vector<bool>> &verificado, vector<int, int> camino) {
    if (resuelto) {
        return;
    }
    //if(cordXActual<0)
}

bool Thread::isResuelto() {
    return resuelto;
}

void Thread::resolver() {
}
