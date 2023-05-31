#pragma once
#include "Fecha.h"
class Tarjeta
{
	public:
	    Tarjeta();
		Tarjeta(int num, Fecha fecha, int dni, float saldo, bool estado);
		void setNumeroTarjeta(int num);
		void setFechaAlta(Fecha fecha);
		void setDniUsuario(int dni);
		void setSaldo(float saldo);
		void setEstado(bool estado);

		int getNumeroTargeta();
		Fecha getFechaAlta();
		int getDniUsuario();
		float getSaldo();
		bool getEstado();

	private:
		int _numeroTarjeta;
		Fecha _fechaAlta;
		int _dniUsuario;
		float _saldo;
		bool _estado;
};

