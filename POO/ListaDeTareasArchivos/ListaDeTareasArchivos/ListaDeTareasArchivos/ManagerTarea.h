#pragma once
#include "ArchivoTareas.h"

class ManagerTarea
{
public:
	void cargar();
	void listarXId();
	void listarTodo();
	void editar();
	void eliminar();

	void listar(Tarea tarea);

private:
	ArchivoTareas _archivoTareas = ArchivoTareas("tareas.dat");
	bool existeId(int id);
	int generarId();
};

