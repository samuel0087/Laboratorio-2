#include "funciones.h"

bool cargarTarea(Tarea t, ArchivoTareas at) {

    int dia, mes, anio, dificultad, id;
    string descripcion;

    cout << "Ingrese id: ";
    cin >> id;

    t.setId(id);

    do {
        cout << "Ingrese Descripcion de la tarea: ";
        cin.ignore();
        getline(cin, descripcion);
        
    } while (!t.setDescripcion(descripcion));

    cout << "Ingrese dificultad ( 1 - baja, 2 - media y 3 - alta) ";
    cin >> dificultad;
    t.setDificultad(dificultad);

    cout << "Fecha limite: " << endl;
    cout << "Dia: ";
    cin >> dia;

    cout << "Mes: ";
    cin >> mes;

    cout << "Anio: ";
    cin >> anio;
    t.setFechaLimite(Fecha(dia, mes, anio));

    t.setEstado(false);

    return at.guardarTarea(t);

}
