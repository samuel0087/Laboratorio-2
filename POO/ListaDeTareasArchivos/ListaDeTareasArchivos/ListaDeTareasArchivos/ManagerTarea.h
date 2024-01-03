#pragma once
#include "ArchivoTareas.h"
#include <iomanip>

class ManagerTarea
{
public:
	void cargar();
	void listarXId();
	void listarTodo();
	void editar();
	void eliminar();

	void listar(Tarea tarea);
	void listarCuadro(Tarea tarea);
	void generarRenglon();

private:
	ArchivoTareas _archivoTareas = ArchivoTareas("tareas.dat");
	bool existeId(int id);
	int generarId();
};

