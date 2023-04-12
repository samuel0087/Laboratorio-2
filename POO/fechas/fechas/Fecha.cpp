#include "Fecha.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

///ERROR EN EL CONSTRUCTOR

//constructores
Fecha::Fecha(int dia = 1, int mes = 1, int anio = 2023) {
	int canDias = cantidadDiaMes(mes, anio);
	if ((anio > 0) && (mes >= 1 && mes <= 12) && (dia >= 1 && dia <= canDias)) {
		this->setAnio(anio);
		this->setMes(mes);
		this->setDia(dia);
	}
	else {
		setAnio(2023);
		setMes(1);
		setDia(1);		
	}
}

Fecha::Fecha() {
	setDia(1);
	setMes(1);
	setAnio(2023);
}

//setters
void Fecha::setDia(int numD) {
   if(numD >= 1 && numD <= cantidadDiaMes(_mes) {
      _dia = numD;
   }
}

void Fecha::setMes(int numM) {
	if (numM >= 1 && numM <= 12) {
		_mes = numM;
	}
}

void Fecha::setAnio(int numA) {
	if (numA >= 1) {
		_anio = numA;
	}
}

//getters
int Fecha::getDia() {
	return _dia;
}

int Fecha::getMes() {
	return _mes;
}

int Fecha::getAnio() {
	return _anio;
}

//Funciones de clase
bool Fecha::anioBisiesto(int numAnio) {
	if ((numAnio % 4 == 0 && numAnio % 100 != 0) || numAnio%400 == 0) {
		return true;
	}
	return false;
}

int Fecha::cantidadDiaMes(int numMes, int numAnio) {
	int canDias = 0;


	switch (numMes) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			canDias = 31;
			break;

		case 2:
			if (anioBisiesto(numAnio)) {
				canDias = 29;
			}
			else {
				canDias = 28;
			}
			break;

		case 4:
		case 6:
		case 9:
		case 11:
			canDias = 30;
			break;
	}
	return canDias;
}

void Fecha::agregarDia() {
	if (_dia < cantidadDiaMes(_mes, _anio)) {
		_dia++;
	}
	else {
		_dia = 01;

		if (_mes != 12) {
			_mes++;
		}
		else {
			_mes = 01;
			_anio++;
		}
	}
}