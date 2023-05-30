#pragma once
#include "Fecha.h"

class Viaje
{
	public:
		Viaje();
		Viaje(int numViaje, int numTarjeta, int transporte, Fecha fecha, float importe);
		void setNumViaje(int numViaje);
		void setNumTarjeta(int numTargeta);
		void setTransporte(int transporte);
		void setFechaViaje(Fecha fechaViaje);
		void setImporte(float importe);

		int getNumViaje();
		int getNumTarjeta();
		int getTransporte();
		Fecha getFechaViaje();
		float getImporte();

	private:
		int _numeroViaje;
		int _numTarjeta;
		int _transporte;
		Fecha _fechaViaje;
		float _importeViaje;

};

