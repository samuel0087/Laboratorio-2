#pragma once
#include <stdio.h>
#include <cstring>
#include "Tarea.h"

class ArchivoTareas
{
	private:
		char  _nombreArchivo[50];

	public:
		ArchivoTareas(std::string nombre);

		void setNombreArchivo(std::string nombre);
		std::string getNombreArchivo();

		bool guardarTarea(Tarea tarea);
		bool listarTarea(bool deadline);
		Tarea buscarTarea(int codTarea);
};

