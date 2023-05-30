#include "Viaje.h"
Viaje::Viaje() {
	_numeroViaje = 0;
	_numTarjeta = 0;
	_transporte = 0;
	_fechaViaje = Fecha();
	_importeViaje = 0.0f;
}

Viaje::Viaje(int numViaje = 0, int numTarjeta = 0, int transporte = 0, Fecha fecha = Fecha(0,0,0), float importe = 0.0f) {
	_numeroViaje = numViaje;
	_numTarjeta = numTarjeta;
	_transporte = transporte;
	_fechaViaje = fecha;
	_importeViaje = importe;
}

void Viaje::setNumViaje(int numViaje) {
	_numeroViaje = numViaje;
}

void Viaje::setNumTarjeta(int numTargeta) {
	_numTarjeta = numTargeta;
}

void Viaje::setTransporte(int transporte) {
	_transporte = transporte;
}
void Viaje::setFechaViaje(Fecha fechaViaje) {
	_fechaViaje = fechaViaje;
}
void Viaje::setImporte(float importe) {
	_importeViaje = importe;
}

int Viaje::getNumViaje() {
	return _numeroViaje;
}

int Viaje::getNumTarjeta() {
	return _numTarjeta;
}

int Viaje::getTransporte() {
	return _transporte;
}

Fecha Viaje::getFechaViaje() {
	return _fechaViaje;
}

float Viaje::getImporte() {
	return _importeViaje;
}