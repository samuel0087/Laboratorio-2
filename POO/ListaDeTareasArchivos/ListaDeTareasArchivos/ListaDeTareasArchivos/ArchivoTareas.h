#pragma once
#include <stdio.h>
#include <cstring>
#include "Tarea.h"

class ArchivoTareas
{
	private:
		char  _nombreArchivo[50];

	public:
		ArchivoTareas();
		ArchivoTareas(std::string nombre);


		void setNombreArchivo(std::string nombre);
		std::string getNombreArchivo();
		int getCantidadRegistros();

		Tarea leer(int id);
		bool guardarTarea(Tarea tarea);
		bool guardarTarea(Tarea tarea, int posRegistro);
		bool listarTarea(bool deadline);
		int buscarTarea(int codTarea);
};

