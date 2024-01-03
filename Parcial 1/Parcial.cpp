#include "Parcial.h"

Parcial::Parcial() {
	_cantRegistrosA = _archivoA.getCantidadRegistros(); //cantidad de registros del archivo agente
	_cantRegistrosM = _archivoM.getCantidadRegistros(); //cantidad de registros del archivo multa

	_vMultas = new Multa[_cantRegistrosM];
	_vAgentes = new Agente[_cantRegistrosA];

	if (_vMultas == nullptr) {
		cout << "Error al crear el array dinamico M" << endl;
		return;
	}

	if (_vAgentes == nullptr) {
		cout << "Error al crear el array dinamico A" << endl;
		return;
	}

	_archivoM.leer(_vMultas, _cantRegistrosM);  //vector con toda la informacion del archivo multa
	_archivoA.leer(_vAgentes, _cantRegistrosA); //vector con toda la informacion del archivo agente
}

void Parcial::Punto1() {
	/*1)Mostrar los números de tipo de infracción que hayan registrado al menos una multa en el 2022 pero ninguna multa en el 2021.*/
	bool vCon2022[10] = {}, vCon2021[10] = {};

	for (int i = 0; i < _cantRegistrosM; i++) {
		if (!_vMultas[i].getEliminado()) {
			if (_vMultas[i].getFechaMulta().getAnio() == 2022) {
				vCon2022[_vMultas[i].getTipoInfraccion() - 1] = true;
			}
			else{
				if (_vMultas[i].getFechaMulta().getAnio() == 2021) {
					vCon2021[_vMultas[i].getTipoInfraccion() - 1] = true;
				}
			}
		}
	}

	cout << "-------------------------------" << endl;
	cout << "           Punto 1" << endl;
	cout << "-------------------------------" << endl;
	for (int i = 0; i < 10; i++) {
		if (vCon2022[i] && !vCon2021[i]) {
			cout << "Tipo de infracion  " << i + 1 << endl;
			cout << endl;
		}
	}

}

void Parcial::Punto2() {
	//La multa pagada de mayor importe y el apellido y el nombre del agente que la realizó.
	Multa multaMayorImporte = getMultaImporteMayor(_vMultas, _cantRegistrosM);

	int posAgente = _archivoA.buscar(multaMayorImporte.getIDAgente());
	Agente agenteResponsable = _archivoA.leer(posAgente);

	cout << "-------------------------------" << endl;
	cout << "           Punto 2" << endl;
	cout << "-------------------------------" << endl;
	cout << "Multa Pagada de mayor importe" << endl << endl;
	_managerM.Listar(multaMayorImporte);
	cout << endl;
	cout << "Agente: " << agenteResponsable.getNombres() << " " << agenteResponsable.getApellidos() << endl;

}

void Parcial::Punto3() {
	//La cantidad de agentes distintos que hayan realizado al menos una multa con un monto individual de más de $25000.
	int cont = 0;

	for (int i = 0; i < _cantRegistrosA; i++) {
		bool topeDeMulta = getTopeSuperado(_vAgentes[i].getIdAgente());
		if (topeDeMulta) {
			cont++;
		}
	}
	
	cout << "-------------------------------" << endl;
	cout << "           Punto 3" << endl;
	cout << "-------------------------------" << endl;
	cout << "Cantidad de agentes que realizaron al menos una multa con un monto superior a $25000 es de: " << cont << endl << endl;

}

void Parcial::Punto4() {

	// ID de Agente, apellidos y nombres de los agentes que hayan realizado en el año 2022 más de una multa del mismo tipo de infracción.
	cout << "-------------------------------" << endl;
	cout << "           Punto 4" << endl;
	cout << "-------------------------------" << endl;
	cout << "agentes que hayan realizado en el año 2022 mas de una multa del mismo tipo de infraccion." << endl << endl;

	cout << "ID agente : " << '\t' << "Nombre Completo : " << endl;

	for (int i = 0; i < _cantRegistrosA; i++) {
		bool valido = getTipoInfraccionDuplicado(_vAgentes[i].getIdAgente());

		if (valido) {
			cout << "ID agente : " << _vAgentes[i].getIdAgente() << "    ";
			cout << "Nombre Completo : " << _vAgentes[i].getApellidos() << " " << _vAgentes[i].getNombres() << endl;
		}
	}

}

Multa Parcial::getMultaImporteMayor(Multa* listadoMultas, int cantRegistros) {
	Multa multa;
	bool flagPrimerPagada = false;

	for (int i = 0; i < cantRegistros; i++) {
		if (flagPrimerPagada && listadoMultas[i].getPagada()) {
			if (multa.getMonto() < listadoMultas[i].getMonto() && !listadoMultas[i].getEliminado()) {
				multa = listadoMultas[i];
			}
		}
		else {
			if (listadoMultas[i].getPagada() && !listadoMultas[i].getEliminado()) {
				multa = listadoMultas[i];
				flagPrimerPagada = true;
			}
		}
		
	}

	return multa;
}

bool Parcial::getTopeSuperado(int idAgente) {
	for (int i = 0; i < _cantRegistrosM; i++) {
		if (!_vMultas[i].getEliminado() && _vMultas[i].getIDAgente() == idAgente) {
			if (_vMultas[i].getMonto() > 25000) {
				return true;
			}
		}
	}

	return false;
}

bool Parcial::getTipoInfraccionDuplicado(int idAgente) {
	int vContTipoInfraccion[10] = {};
	
	for (int i = 0; i < _cantRegistrosM; i++) {
		if (!_vMultas[i].getEliminado() && _vMultas[i].getIDAgente() == idAgente && _vMultas[i].getFechaMulta().getAnio() == 2022) {
			vContTipoInfraccion[_vMultas[i].getTipoInfraccion() - 1]++;
		}
	}

	for (int i = 0; i < 10; i++) {
		if (vContTipoInfraccion[i] >= 2) {
			return true;
		}
	}

	return false;
}

Parcial::~Parcial() {
	delete _vMultas;
	delete _vAgentes;
}