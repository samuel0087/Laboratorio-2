#pragma once
#include  <iostream>
#include "Tarea.h"

Tarea::Tarea() {
	_descripcion = "";
	_dificultad = 0;
	_fechaLimite = Fecha();
	_estado = false;
}

Tarea::Tarea(std::string des, int dif, Fecha fech, bool status) {
	_descripcion = des;
	_dificultad = dif;
	_fechaLimite = fech;
	_estado = status;
}

//setters
void Tarea::setDescripcion(std::string des) {
	_descripcion = des;
}

void Tarea::setDificultad(int dif) {
	_dificultad = dif;
}

void Tarea::setFechaLimite(Fecha fech) {
	_fechaLimite = fech;
}

void Tarea::setEstado(bool status) {
	_estado = status;
}

//getters

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

bool Tarea::getEstado() {
	return _estado;
}

void Tarea::mostrar() {
	std::cout << "Descripcion: " << getDescripcion() << std::endl;
	std::cout << "Dificultad: " << getDificultad() << std::endl;
	std::cout << "Fecha Limite: " << getFechaLimite().toString() << std::endl;
	std::cout << "Estado: ";

	if (getEstado()) {
		std::cout << "Hecho" << std::endl;
	} 
	else {
		std::cout << "Pendiente" << std::endl;
	}
}