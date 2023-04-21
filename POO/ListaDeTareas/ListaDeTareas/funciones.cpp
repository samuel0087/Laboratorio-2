#include "funciones.h"

Tarea cargarTarea() {
    int dia, mes, anio, dificultad;
    string descripcion;

    cout << "Ingrese Descripcion de la tarea: ";
    cin.ignore();
    getline(cin, descripcion);

    cout << "Ingrese dificultad ( 1 - baja, 2 - media y 3 - alta) ";
    cin >> dificultad;

    cout << "Fecha limite: " << endl;
    cout << "Dia: ";
    cin >> dia;

    cout << "Mes: ";
    cin >> mes;

    cout << "Anio: ";
    cin >> anio;

    return Tarea(descripcion, dificultad, Fecha(dia, mes, anio), false);

}