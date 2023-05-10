#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <iomanip>
#include "ArchivoTareas.h"
#include "funciones.h"

ArchivoTareas::ArchivoTareas(std::string nombre = "") {
	strcpy(_nombreArchivo, nombre.c_str());
}

void ArchivoTareas::setNombreArchivo(std::string nombre) {
	strcpy(_nombreArchivo, nombre.c_str());
}

std::string ArchivoTareas::getNombreArchivo() {
	std::string nombre = _nombreArchivo;
	return nombre;
}

bool ArchivoTareas::guardarTarea(Tarea tarea) {
	FILE* pTarea;

	pTarea = fopen(_nombreArchivo, "ab");

	if (pTarea == NULL) {
		return false;
	}

	fwrite(&tarea, sizeof(Tarea), 1, pTarea);

	fclose(pTarea);

	return true;
}

bool ArchivoTareas::listarTarea(bool deadline = false) {
	FILE* pTarea;
	Tarea tarea;
	Fecha fechActual = fechaActual();

	pTarea = fopen(_nombreArchivo, "rb");

	if (pTarea == NULL) {
		return false;
	}
	std::cout << std::left;
	std::cout << std::setw(4) << "id ";
	std::cout << std::setw(30) << "Descripcion";
	std::cout << std::setw(15) << "Dificultad";
	std::cout << std::setw(15) << "Fecha Limite";
	std::cout << std::setw(15) << "Estado";
	if(deadline) {
		std::cout << std::setw(10) << "Dias de expiracion : ";
	}

	std::cout << std::endl;

	while (fread(&tarea, sizeof(Tarea), 1, pTarea) != 0) {

		if (deadline) {
			if (!tarea.getEstado()) {				

				tarea.mostrar();

				std::cout << std::setw(15) << diferenciaDias(fechActual, tarea.getFechaLimite());
			}
		}
		else {
			tarea.mostrar();
		}

		std::cout << std::endl;

	}

	fclose(pTarea);

	return true;
}

Tarea ArchivoTareas::buscarTarea(int codTarea) {
	FILE* pTareas;
	Tarea tarea;

	pTareas = fopen(_nombreArchivo, "rb");

	if (pTareas == NULL) {
		return tarea;
	}

	while (fread(&tarea, sizeof(Tarea), 1, pTareas) != 0) {
		if (tarea.getId() == codTarea) {
			fclose(pTareas);
			return tarea;
		}
	}

	fclose(pTareas);

	return tarea;
}
