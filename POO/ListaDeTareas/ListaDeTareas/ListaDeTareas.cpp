#pragma once
#include <iostream>
#include <iomanip>
#include "ListaDeTareas.h"

using namespace std;

ListaDeTareas::ListaDeTareas() {
	_cantidad = 0;
	for(int id : _idTareas)
	{
		id = 0;
	}
}


void ListaDeTareas::agregar(Tarea tarea) {
	if (_cantidad < 10) {
		_tareas[_cantidad] = tarea;
		_idTareas[_cantidad] = _cantidad + 1;
		_cantidad++;
	}
}

void ListaDeTareas::mostrar(bool incluirDeadLine = false) {
	cout << left;
	cout << setw(4) << "ID";
	cout << setw(45) << "DESCRIPCION";
	cout << setw(15) << "DIFICULT";
	cout << setw(15) << "F. LIMIT.";

	if (incluirDeadLine) {
		cout << setw(5) << "DIAS";
	}

	cout << setw(15) << "ESTADO" << endl;
	for (int i = 0; i < _cantidad; i++) {
		cout << setw(4) << _idTareas[i];
		cout << setw(45) << _tareas[i].getDescripcion();
		cout << setw(15) << _tareas[i].getDificultad();
		cout << setw(15) << _tareas[i].getFechaLimite().toString();

		if (incluirDeadLine) {
			cout << setw(5) << diferenciaDias(Fecha(20,04,2023), _tareas[i].getFechaLimite());
		}

		if (_tareas[i].getEstado()) {
			cout << setw(15) << "Hecho" << endl;
		}
		else {
			cout << setw(15) << "Pendiente" << endl;
		}
	}
}

Tarea ListaDeTareas::buscar(int id) {
	for (int i = 0; i < _cantidad; i++) {
		if (id == _idTareas[i]) {
			return _tareas[i];
		}
	}

	return Tarea();
}

void ListaDeTareas::cambiarEstado(int numTarea) {
	if (_tareas[numTarea - 1].getEstado()) {
		_tareas[numTarea - 1].setEstado(false);
	}
	else {
		_tareas[numTarea - 1].setEstado(true);
	}
}

int ListaDeTareas::diferenciaDias(Fecha fechaActual, Fecha fechaLimite) {
	int cont = 0;
	bool fechaMayor = (fechaActual.toString() < fechaLimite.toString());

	if (fechaMayor) {
		while (fechaActual.toString() != fechaLimite.toString()) {
			fechaActual.agregarDias(1);
			cont++;
		}
	}

	return cont;
}