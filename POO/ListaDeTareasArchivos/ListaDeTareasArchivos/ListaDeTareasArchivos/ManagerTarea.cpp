#include "ManagerTarea.h"

void ManagerTarea::cargar() {
	cout << "-------------------------------" << endl;
	cout << "        Carga de tareas        " << endl;
	cout << "-------------------------------" << endl;
	int dia, mes, anio, dificultad, id, cantTag;
	string descripcion;
	Etiqueta tags;
	Tarea t;

	cout << "Ingrese id: ";
	cin >> id;

	do {
		cout << "Ingrese Descripcion de la tarea: ";
		cin.ignore();
		getline(cin, descripcion);

	} while (!t.setDescripcion(descripcion));

	cout << "Ingrese dificultad ( 1 - baja, 2 - media y 3 - alta) ";
	cin >> dificultad;

	cout << "Fecha limite: " << endl;
	cout << "Dia: ";
	cin >> dia;

	cout << "Mes: ";
	cin >> mes;

	cout << "Anio: ";
	cin >> anio;

	cout << "Ingrese la cantidad de etiquetas que desea (0 a 10): ";
	cin >> cantTag;

	if (cantTag > 0) {
		tags.cargar(cantTag);
	}

	t.setId(id);
	t.setFechaLimite(Fecha(dia, mes, anio));
	t.setDificultad(dificultad);
	t.setTags(tags);
	t.setEstado(false);
	ArchivoTareas _archivoTareas;

	if (_archivoTareas.guardarTarea(t)) {
		cout << "Tareas ingresadas con exito" << endl;
	}
	else {
		cout << "Error al registrar " << endl;
	}
}

void ManagerTarea::listarTodo() {
	cout << "-------------------------------" << endl;
	cout << "        Lista de tareas        " << endl;
	cout << "-------------------------------" << endl;

	if (!_archivoTareas.listarTarea(false)) {
		cout << "Error al Listar tareas " << endl;
	}
}

void ManagerTarea::listarXId() {
	int id;
	cout << "Ingrese ID: ";
	cin >> id;

	int posicion = _archivoTareas.buscarTarea(id);
	if (posicion >= 0) {
		Tarea reg = _archivoTareas.leer(posicion);
		reg.mostrar();
	}
	else {
		cout << "No existe el registro con ID #" << id << endl;
	}
}

void ManagerTarea::editar() {
	int id;
	cout << "Ingrese ID: ";
	cin >> id;

	int posicion = _archivoTareas.buscarTarea(id);
	if (posicion >= 0) {
		Tarea reg = _archivoTareas.leer(posicion);
		listar(reg);
		cout << endl;

		int nuevoEstado;
		cout << "Ingresar nuevo estado: ";
		cin >> nuevoEstado;
		reg.setEstado(nuevoEstado);
		_archivoTareas.guardarTarea(reg, posicion);
	}
	else {
		cout << "No existe el registro con ID #" << id << endl;
	}
}

void ManagerTarea::listar(Tarea tarea) {
	cout << "Id          :" << tarea.getId() << endl;
	cout << "Descripcion :" << tarea.getDescripcion() << endl;
	cout << "Dificultad  :" << tarea.getDificultad() << endl;
	cout << "Fecha limite:" << tarea.getFechaLimite().toString() << endl;
	cout << "Estado      :" << tarea.getEstado() << endl;
}