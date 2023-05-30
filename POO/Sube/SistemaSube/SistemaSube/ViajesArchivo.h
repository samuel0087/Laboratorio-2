#pragma once
#include <cstring>
#include "Fecha.h"
#include "Viaje.h"
#include "Tarjeta.h"

class ViajesArchivo
{
public:
	ViajesArchivo(const char* ruta);
	int guardar(Viaje reg);
	int guardar(Viaje reg, int pos);
	int buscar(int numViaje);
	Viaje leer(int pos);
	void leer(Viaje* viajes, int cantidadRegistros);
	int getCantidadRegistros();
	

private:
	char _ruta[50];
};

