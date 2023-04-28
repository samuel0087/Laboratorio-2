#pragma once
#include <string>
#include <cstring>
#include "Fecha.h"

class Tarea
{
	private:
		int _idTarea;
		char _descripcion[31];
		int _dificultad;
		Fecha _fechaLimite;
		bool _estado;

	public:
		Tarea();
		Tarea(std::string des, int dif, Fecha fech, bool status);

		//setters
		bool setDescripcion(std::string des);
		void setDificultad(int dif);
		void setFechaLimite(Fecha fech);
		void setEstado(bool status);

		//getters
		std::string getDescripcion();
		std::string getDificultad();
		Fecha getFechaLimite();
		bool getEstado();

		//de clase
		void mostrar();

};

