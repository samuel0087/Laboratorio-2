#pragma once
#include <iostream>
#include "Multa.h"
#include "Agente.h"
#include "MultaArchivo.h"
#include "MultaManager.h"
#include "AgenteArchivo.h"

using namespace std;

class Parcial
{
	public:
		Parcial();
		~Parcial();
		void Punto1();
		void Punto2();
		void Punto3();
		void Punto4();

	private:
		Multa* _vMultas;
		int _cantRegistrosM;

		Agente* _vAgentes;
		int _cantRegistrosA;

		MultaArchivo _archivoM = MultaArchivo("multas.dat");
		AgenteArchivo _archivoA = AgenteArchivo("agentes.dat");
		MultaManager _managerM;

		Multa getMultaImporteMayor(Multa* listadoMultas, int cantRegistros);
		bool getTopeSuperado(int idAgente);
		bool getTipoInfraccionDuplicado(int idAgente);
};

