#pragma once
#include <string>
#include <cstring>
#include "Fecha.h"
#include "Etiqueta.h"

class Tarea
{
	private:
		int _idTarea;
		char _descripcion[31];
		int _dificultad;
		Fecha _fechaLimite;
		Etiqueta _tags;
		bool _estado;

	public:
		Tarea();
		Tarea(int id, std::string des, int dif, Fecha fech, bool status);

		//setters
		void setId(int id);
		bool setDescripcion(std::string des);
		void setDificultad(int dif);
		void setFechaLimite(Fecha fech);
		void setTags(Etiqueta tags);
		void setEstado(bool status);

		//getters
		int getId();
		std::string getDescripcion();
		std::string getDificultad();
		Fecha getFechaLimite();
		Etiqueta getTags();
		std::string getEstado();

		//de clase
		void mostrar();

};

