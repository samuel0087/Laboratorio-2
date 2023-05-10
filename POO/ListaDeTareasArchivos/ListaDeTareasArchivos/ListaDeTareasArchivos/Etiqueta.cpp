#pragma once
#define _CRT_SECURE_NO_DEPRECATE
#include "Etiqueta.h"


Etiqueta::Etiqueta() {
	_cantidad = 0;
}

bool Etiqueta::setNombre(std::string tag) {
	if (_cantidad < 10) {

		if (tag.length() <= 20) {
			strcpy(_nombre[_cantidad], tag.c_str());
			_cantidad++;
			return true;
		}
		return false;
	}
	return false;
}

int Etiqueta::getCantidad() {
	return _cantidad;
}

std::string* Etiqueta::getNombre() {
	std::string nombre[10];

	for (int i = 0; i < _cantidad; i++) {
		nombre[i] = _nombre[i];
	}

	return nombre;
}

void Etiqueta::mostrar() {
	std::cout << std::endl;
	std::cout << "Etiquetas: " << std::endl;

	for (int i = 0; i < _cantidad; i++) {
		std::cout << _nombre[i] << std::endl;
	}
}
