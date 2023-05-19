#pragma once
#include "Agente.h"
#include "Multa.h"
#include "AgenteArchivo.h"
#include "MultaArchivo.h"
#include <iostream>
#include <iomanip>
using namespace std;

class ModeloParcial
{
	public:
		void Punto1();
		void Punto2();
		void Punto3();
		void Punto4();

	private:
		AgenteArchivo _agenteArchivo;
		MultaArchivo _multaArchivo;

		int buscarNulos(int* vec, int tam);
		int contarMultas(int idAgente);
		float calcularMonto(int idAgente);
		void listarPunto2(Agente reg, int cant, float monto);

};

