#include "MenuTarea.h"

void MenuTarea::mostrar() {
	int opc;
	Fecha fechaAtual = fechaActual();

	do {

		cout << "-------------------------------" << endl;
		cout << "        Lista de tareas        " << endl;
		cout << "-------------------------------" << endl;

		cout << "1 - Cargar tareas" << endl;
		cout << "2 - Listado de tareas" << endl;
		cout << "3 - Buscar tarea" << endl;
		cout << "4 - Editar estado de tarea" << endl;
		cout << "5 - Eliminar registro" << endl;
		cout << "0 - Salir" << endl;
		cin >> opc;
		system("cls");

		switch (opc) {
		case 1:
			_managerTareas.cargar();
			break;
		case 2:
			_managerTareas.listarTodo();
			break;
		case 3:
			_managerTareas.listarXId();
			break;
		case 4:
			_managerTareas.editar();
			break;
		case 5:
			_managerTareas.eliminar();
			break;
		case 0:
			break;
		default:
			break;
		}

		system("pause");
		system("cls");



	} while (opc != 0);
}

