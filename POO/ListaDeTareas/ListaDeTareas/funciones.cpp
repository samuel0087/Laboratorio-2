#include "funciones.h"

Tarea cargarTarea() {
    Tarea t;
    int dia, mes, anio, dificultad;
    string descripcion;

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

    return t;

}