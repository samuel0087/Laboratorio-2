#include "Bidon.h"
#include <string>

Bidon::Bidon() {
	_sabor = "Sin sabor";
	_capacidad = 0.0f;
	_ventas = 0;
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

bool Bidon::cargaVaso(float vaso) {
	if (vaso <= _capacidad) {
		_capacidad -= vaso;
		_ventas++;
		return true;
	}
	return false;
}

int Bidon::getVentas() {
	return _ventas;
}