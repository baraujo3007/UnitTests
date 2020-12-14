#ifndef BAR_H
#define BAR_H

#include <vector>
#include <mutex>
#include "grafo.h"

class Bar
{
    public:
        vector<mutex> garrafas;
        Bar(Grafo g1);
        virtual ~Bar();
};

#endif // BAR_H
