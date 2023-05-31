#include "Tarjeta.h"
Tarjeta::Tarjeta() {
	_numeroTarjeta = 0;
	_fechaAlta = Fecha(0, 0, 0);
	_dniUsuario = 0;
	_saldo = 0.0f;
	_estado = false;
}

Tarjeta::Tarjeta(int num = 0, Fecha fecha = Fecha(), int dni = 0, float saldo = 0.0f, bool estado = false) {
	_numeroTarjeta = num;
	_fechaAlta = fecha;
	_dniUsuario = dni;
	_saldo = saldo;
	_estado = estado;
}

void Tarjeta::setNumeroTarjeta(int num) {
	_numeroTarjeta = num;
}

void Tarjeta::setFechaAlta(Fecha fecha) {
	_fechaAlta = fecha;
}

void Tarjeta::setDniUsuario(int dni) {
	_dniUsuario = dni;
}

void Tarjeta::setSaldo(float saldo) {
	_saldo = saldo;
}

void Tarjeta::setEstado(bool estado) {
	_estado = estado;
}

int Tarjeta::getNumeroTargeta() {
	return _numeroTarjeta;
}

Fecha Tarjeta::getFechaAlta() {
	return _fechaAlta;
}

int Tarjeta::getDniUsuario() {
	return _dniUsuario;
}

float Tarjeta::getSaldo() {
	return _saldo;
}

bool Tarjeta::getEstado() {
	return _estado;
}
