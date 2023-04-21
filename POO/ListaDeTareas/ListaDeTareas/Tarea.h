#pragma once
#include <string>
#include "Fecha.h"

class Tarea
{
	private:
		int _idTarea;
		std::string _descripcion;
		int _dificultad;
		Fecha _fechaLimite;
		bool _estado;

	public:
		Tarea();
		Tarea(std::string des, int dif, Fecha fech, bool status);

		//setters
		void setDescripcion(std::string des);
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

