#include "ModeloParcial.h"

void ModeloParcial::Punto1() {
	//Mostrar la cantidad de agentes que no hayan realizado multas en el año 2022.
	int cantAgentes = _agenteArchivo.getCantidadRegistros();
	int cantMultas = _multaArchivo.getCantidadRegistros();
	int* vecAgentes = new int[cantAgentes]();

	if (vecAgentes == nullptr) {
		cout << "No se pudo crear puntero de agentes" << endl;
		return;
	}

	for (int i = 0; i < cantMultas; i++) {
		Multa  multa = _multaArchivo.leer(i);

		if (!multa.getEliminado() && multa.getFechaMulta().getAnio() == 2022) {
			int pos = _agenteArchivo.buscar(multa.getIDAgente());
				if (pos >= 0) {
					vecAgentes[pos]++;
				}
		}
	}
	
	int cantSinMultar = buscarNulos(vecAgentes, cantAgentes);
	delete[]vecAgentes;

	if (cantSinMultar > 0) {
		cout << "La cantidad de agentes que no multaron en 2022 : " << cantSinMultar << endl;
	}
	else {
		cout << "Todos los agentes multaron en el 2022" << endl;
	}

	
}

void ModeloParcial::Punto2() {
	int cantRegAgentes = _agenteArchivo.getCantidadRegistros();
	int* vContMultas = new int[cantRegAgentes]();
	float* vAcumMultas = new float[cantRegAgentes]();

	if (vContMultas == nullptr || vAcumMultas == nullptr) {
		cout << "Error en el punto 3" << endl;
		return;
	}

	for (int i = 0; i < cantRegAgentes; i++) {
		Agente reg = _agenteArchivo.leer(i);
		int id = reg.getIdAgente();
		
		vContMultas[i] = contarMultas(id);
		vAcumMultas[i] = (float)calcularMonto(id);
	}

	cout << "Punto 2" << endl;
	cout << "----------------------------------------------------" << endl;
	cout << left;
	cout << setw(6) << "ID  ";
	cout << setw(15) << "Apellidos";
	cout << setw(12) << "Nombres";
	cout << setw(6) << "MULT";
	cout << setw(8) << "Total" << endl;
	cout << "----------------------------------------------------" << endl;


	for (int i = 0; i < cantRegAgentes; i++) {
		Agente reg = _agenteArchivo.leer(i);
		int id = reg.getIdAgente();
		listarPunto2(reg, vContMultas[i], vAcumMultas[i]);
	}


	delete[]vAcumMultas;
	delete[]vContMultas;
}

void ModeloParcial::Punto3() {
	int cantInfracciones[10] = {};
	int cantRegistros = _multaArchivo.getCantidadRegistros();

	for (int i = 0; i < cantRegistros; i++) {
		Multa reg = _multaArchivo.leer(i);
		if (!reg.getEliminado()) {
			cantInfracciones[reg.getTipoInfraccion() - 1]++;
		}
	}

	cout << "----------------------------------------------------" << endl;
	cout << "Punto 3" << endl;
	cout << "----------------------------------------------------" << endl;
	for (int i = 0; i < 10; i++) {
		cout << "Cantidad de multas por infracciones #" << i + 1 << " :" << cantInfracciones[i] << endl;
	}

}

void ModeloParcial::Punto4() {
	int cantRegistros = _multaArchivo.getCantidadRegistros();
	Multa* multas = new Multa[cantRegistros];

	if (multas == nullptr) {
		cout << "Error en el punto 4" << endl;
		return;
	}

	_multaArchivo.leer(multas, cantRegistros);

	for (int i = 0; i < cantRegistros; i++) {
		if (multas[i].getFechaMulta().getAnio() == 2022 && multas[i].getPagada() && !multas[i].getEliminado()) {
			if (_multasPagadas2022.buscar(multas[i].getIDMulta()) < 0) {
				_multasPagadas2022.guardar(multas[i]);
			}
		}
	}
	delete[]multas;

	cout << "----------------------------------------------------" << endl;
	cout << "Punto 4" << endl;
	cout << "----------------------------------------------------" << endl;

	cantRegistros = _multasPagadas2022.getCantidadRegistros();

	for (int i = 0; i < cantRegistros; i++) {
		Multa reg = _multasPagadas2022.leer(i);
		listarPunto4(reg);
	}
}

int ModeloParcial::buscarNulos(int* vec, int tam) {
	int cont = 0;

	for (int i = 0; i < tam; i++) {
		if (vec[i] == 0) {
			cont++;
		}
	}

	return cont;
}

int ModeloParcial::contarMultas(int idAgente) {
	int cantRegistros = _multaArchivo.getCantidadRegistros();
	int cont = 0;
	Multa reg;

	for (int i = 0; i < cantRegistros; i++) {
		reg = _multaArchivo.leer(i);
		if (reg.getIDAgente() == idAgente && reg.getFechaMulta().getAnio() == 2023 && !reg.getEliminado() ) {
			cont++;
		}
	}

	return cont;
}

float ModeloParcial::calcularMonto(int idAgente) {
	int cantRegistros = _multaArchivo.getCantidadRegistros();
	float montoTotal = 0.0f;
	Multa reg;

	for (int i = 0; i < cantRegistros; i++) {
		reg = _multaArchivo.leer(i);
		if (reg.getIDAgente() == idAgente && reg.getFechaMulta().getAnio() == 2023 && !reg.getEliminado()) {
			montoTotal += (float)reg.getMonto();
		}
	}

	return montoTotal;
}

void ModeloParcial::listarPunto2(Agente reg, int cant, float monto) {
	cout << left;
	cout << setw(6) << reg.getIdAgente();
	cout << setw(15) << reg.getApellidos();
	cout << setw(12) << reg.getNombres();
	cout << setw(6) << cant;
	cout << "$ ";
	cout << setw(8) << monto * 1.0f << endl;
}

void ModeloParcial::listarPunto4(Multa reg) {
	if (!reg.getEliminado()) {
		cout << setw(8) << reg.getIDMulta();
		cout << setw(8) << reg.getPatente();
		cout << setw(12) << reg.getFechaMulta().toString();
		cout << setw(8) << reg.getTipoInfraccion();
		cout << setw(8) << reg.getMonto();
		cout << setw(8) << reg.getIDLocalidad();

		if (reg.getPagada()) {
			cout << setw(8) << "pagada" << endl;
		}
		else {
			cout << setw(8) << "Adeuda" << endl;
		}
	}
	

}

