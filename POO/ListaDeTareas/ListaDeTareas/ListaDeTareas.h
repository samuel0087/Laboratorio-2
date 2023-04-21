#pragma once
#include "Tarea.h"

class ListaDeTareas
{
	private:
		int _idTareas[10];
		Tarea _tareas[10];
		int _cantidad;
		
	public:
		ListaDeTareas();
		void agregar(Tarea tarea);
		void mostrar(bool incluirDeadLine);
		Tarea buscar(int id);
		void cambiarEstado(int numTarea);
		int diferenciaDias(Fecha fechaActual, Fecha fechaLimite);
};

