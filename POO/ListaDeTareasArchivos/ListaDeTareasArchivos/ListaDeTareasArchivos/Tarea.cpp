#pragma once
#include  <iostream>
#include <cstring>
#include <iomanip>
#include "Tarea.h"

Tarea::Tarea() {
	_idTarea = 0;
	strcpy_s(_descripcion, "");
	_dificultad = 0;
	_fechaLimite = Fecha();
	_estado = false;
}

Tarea::Tarea(int id, std::string des, int dif, Fecha fech, bool status) {
	if (des.length() <= 30) {
		_idTarea = id;
		strcpy_s(_descripcion, des.c_str());
		_dificultad = dif;
		_fechaLimite = fech;
		_estado = status;
	}
	else {
		_idTarea = 0;
		strcpy_s(_descripcion, "");
		_dificultad = 0;
		_fechaLimite = Fecha();
		_estado = false;
	}
}

//setters
void Tarea::setId(int id) {
	_idTarea = id;
}

bool Tarea::setDescripcion(std::string des) {
	if (des.length() <= 30) {
		strcpy_s(_descripcion, des.c_str());
		return true;
	}
	return false;
}

void Tarea::setDificultad(int dif) {
	_dificultad = dif;
}

void Tarea::setFechaLimite(Fecha fech) {
	_fechaLimite = fech;
}

void Tarea::setTags(Etiqueta tags) {
	_tags = tags;
}

void Tarea::setEstado(bool status) {
	_estado = status;
}

//getters

int Tarea::getId() {
	return _idTarea;
}

std::string Tarea::getDescripcion() {
	return _descripcion;
}

std::string Tarea::getDificultad() {
	switch (_dificultad) {
		case 1:
			return "Baja";
			break;

		case 2:
			return "Media";
			break;

		case 3:
			return "Alta";
			break;

		default:
			return " - ";
			break;

	}
}

Fecha Tarea::getFechaLimite() {
	return _fechaLimite;
}

Etiqueta Tarea::getTags() {
	return _tags;
}

std::string Tarea::getEstado() {
	std::string estado = "Pendiente";
	if (_estado) {
		estado = "Hecho";
	}

	return estado;
}

void Tarea::mostrar() {
	std::cout << "Id          :" <<getId() << std::endl;
	std::cout << "Descripcion :" <<getDescripcion() << std::endl;
	std::cout << "Dificultad  :" <<getDificultad() << std::endl;
	std::cout << "Fecha limite:" <<getFechaLimite().toString() << std::endl;
	std::cout << "Estado      :" << getEstado() << endl;

}