#pragma once
#include "Multa.h"

class ArchivoMultasPagadas2022
{
public:
	int getCantidadRegistros();
	bool guardar(Multa reg);

	Multa leer(int nroRegistro);
	void leer(Multa* vec, int cantidadRegistrosALeer);
	int buscar(int ID);
	void vaciar();

	ArchivoMultasPagadas2022();
	ArchivoMultasPagadas2022(std::string ruta);
private:
	std::string _ruta;
};

