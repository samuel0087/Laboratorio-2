#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <iomanip>
#include "ArchivoTareas.h"
#include "funciones.h"

ArchivoTareas::ArchivoTareas() {
	strcpy(_nombreArchivo, "tareas.dat");
}

ArchivoTareas::ArchivoTareas(std::string nombre) {
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

bool ArchivoTareas::guardarTarea(Tarea tarea, int posRegistro) {
	FILE* pTarea;
	pTarea = fopen(_nombreArchivo, "rb+");

	if (pTarea == NULL) {
		return false;
	}

	fseek(pTarea, posRegistro * sizeof(Tarea), SEEK_SET);
	fwrite(&tarea, sizeof(Tarea), 1, pTarea);
	fclose(pTarea);
	return true;
}

bool ArchivoTareas::listarTarea(bool deadline = false) {
	Tarea aux;
	Fecha fechActual = fechaActual();
	int cantRegistros = this->getCantidadRegistros();

	for (int i = 0; i < cantRegistros; i++) {
		aux = this->leer(i);

		if (deadline) {
			if (aux.getEstado() == "Pendiente") {
				aux.mostrar();
				std::cout << "Dias de expiracion : " << diferenciaDias(fechActual, aux.getFechaLimite()) << std::endl;
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

