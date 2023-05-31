#pragma once
#include <cstring>
#include <stdio.h>
#include "Fecha.h"
#include "Viaje.h"
#include "Tarjeta.h"


class TarjetasArchivo
{
    public:
        TarjetasArchivo();
        int guardar(Tarjeta reg);
        int guardar(Tarjeta reg, int pos);
        int buscar(int numTarjeta);
        Tarjeta leer(int pos);
        void leer(Tarjeta* tarjetas, int cantidadRegistros);
        int getCantidadRegistros();

    private:
        char _ruta[50];
};

