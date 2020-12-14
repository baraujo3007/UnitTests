#ifndef FILOSOFO_H
#define FILOSOFO_H

#include <thread>
#include <chrono>
#include "grafo.h"
#include "bar.h"

class Filosofo
{
    private:
       // chrono::steady_clock::time_point comeca_sede, termina_sede, comeca_tranq, termina_tranq;

    public:
        int i=1;
        int filosofo_id;
        double tempo_tranquilo;
        double tempo_sede;
        Bar& bar;
        Grafo& g1;

        Filosofo(const int n, Bar& bar, Grafo& g1);
        virtual ~Filosofo();
        //Metodos
        thread* criaTrhead();
        void existir();
        void tranquilo();
        void bebendo();
};

#endif // FILOSOFO_H
