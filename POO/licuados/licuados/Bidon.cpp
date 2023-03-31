#include "Bidon.h"
#include <string>

Bidon::Bidon() {
	_sabor = "Sin sabor";
	_capacidad = 0.0f;
}

void Bidon::setSabor(std::string sabor) {
	_sabor = sabor;
}

void Bidon::setCapacidad(float capacidad) {
	_capacidad = capacidad;
}

std::string  Bidon::getSabor() {
	return _sabor;
}

float Bidon::getCapacidad() {
	return _capacidad;
}

void Bidon::cargaVaso(float vaso) {
	if (vaso <= _capacidad) {
		_capacidad -= vaso;
	}
}