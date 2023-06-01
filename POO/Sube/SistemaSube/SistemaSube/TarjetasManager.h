#pragma once
#include <iostream>
#include "Tarjeta.h"
#include "TarjetasArchivo.h"
using namespace std;

class TarjetasManager
{
    public:
        TarjetasManager();
        void agregar();
        void modificar();
        void buscarPorNumeroTarjeta();
        void buscarPorDni();
        void baja();

    private:
        TarjetasArchivo _archivoT;

        int generarNumeroTarjeta();

};
