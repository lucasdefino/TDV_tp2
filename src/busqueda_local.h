#ifndef BUSQUEDA_LOCAL_H
#define BUSQUEDA_LOCAL_H

#include <cstdint>
#include <vector>
#include <iostream>
#include "read_instance.h"
#include "heuristica_2.h"
#include "heuristica_1.h"
#include "heuristica_0.h"
#include "solucion.h"

class BusquedaLocal
{
    public:
    BusquedaLocal();
    BusquedaLocal(Solucion &solucion);

    void Swap();
    double getObjectiveValue() const;
    Solucion getSolucion() const;

	private:
    Solucion _solucion;
    double _objective_value;


};

#endif
