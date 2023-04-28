#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include "ArchivoTareas.h"

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

bool ArchivoTareas::listarTarea() {
	FILE* pTarea;
	Tarea tarea;

	pTarea = fopen(_nombreArchivo, "rb");

	if (pTarea == NULL) {
		return false;
	}

	while (fread(&tarea, sizeof(Tarea), 1, pTarea) != 0) {
		tarea.mostrar();
		std::cout << std::endl;
	}

	fclose(pTarea);

	return true;
}
