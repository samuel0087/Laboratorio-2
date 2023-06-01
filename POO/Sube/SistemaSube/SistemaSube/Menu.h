#pragma once
#include <iostream>
#include "TarjetasManager.h"
#include "ViajesManager.h"

class Menu
{
    public:
        void menuPrincipal();
        void menuTarjetas();
        void menuViajes();

    private:
        TarjetasManager _tarjetaManager;
        ViajesManager _viajemanager;

};

