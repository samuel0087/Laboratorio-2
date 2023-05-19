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
		bool _eliminado;

	public:
		Tarea();
		Tarea(int id, std::string des, int dif, Fecha fech, bool status, bool eliminado);

		//setters
		void setId(int id);
		bool setDescripcion(std::string des);
		void setDificultad(int dif);
		void setFechaLimite(Fecha fech);
		void setTags(Etiqueta tags);
		void setEstado(bool status);
		void setEliminado(bool eliminado);

		//getters
		int getId();
		std::string getDescripcion();
		std::string getDificultad();
		Fecha getFechaLimite();
		Etiqueta getTags();
		std::string getEstado();
		bool getEliminado();

		//de clase
		void mostrar();

};

