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

int ArchivoTareas::getCantidadRegistros() {
	FILE* pTarea;
	pTarea = fopen(_nombreArchivo, "rb");

	if (pTarea == NULL) {
		return 0;
	}

	fseek(pTarea, 0, SEEK_END);
	int byte = ftell(pTarea);
	return byte / sizeof(Tarea);
}

Tarea ArchivoTareas::leer(int numRegistro) {
	Tarea aux;
	FILE* pTarea;
	pTarea = fopen(_nombreArchivo, "rb");

	if (pTarea == NULL) {
		return aux;
	}

	fseek(pTarea, numRegistro * sizeof(Tarea), SEEK_SET);
	fread(&aux, sizeof(Tarea), 1, pTarea);
	fclose(pTarea);

	return aux;
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
	Tarea aux;
	Fecha fechActual = fechaActual();
	int cantRegistros = this->getCantidadRegistros();

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

	for (int i = 0; i < cantRegistros; i++) {
		aux = this->leer(i);

		if (deadline) {
			if (!aux.getEstado()) {				
				aux.mostrar();
				std::cout << std::setw(15) << diferenciaDias(fechActual, aux.getFechaLimite());
			}
		}
		else {
			aux.mostrar();
		}

		std::cout << std::endl;
	}

	return true;
}

int ArchivoTareas::buscarTarea(int codTarea) {
	Tarea aux;
	int i, cantRegistros = this->getCantidadRegistros();

	for (i = 0; i < cantRegistros; i++) {
		aux = this->leer(i);
		if (aux.getId() == codTarea) {
			return i;
		}
	}

	return -1;
}
