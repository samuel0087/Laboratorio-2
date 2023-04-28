#pragma once
#include <iostream>
#include "funciones.h"
using namespace std;

int main()
{
    ListaDeTareas tareas;
    Tarea tarea("Hola mundo soy un stringaaaaa",1, Fecha(), true);
    int opc, numTarea;

    do {

        cout << "-------------------------------" << endl;
        cout << "        Lista de tareas        " << endl;
        cout << "-------------------------------" << endl;

        cout << "1 - Cargar tareas" << endl;
        cout << "2 - Listado de tareas" << endl;
        cout << "3 - Buscar tarea" << endl;
        cout << "4 - Vencimiento de tareas" << endl;
        cout << "0 - Salir" << endl;
        cin >> opc;
        system("cls");

        switch (opc) {
            case 1:
                cout << "-------------------------------" << endl;
                cout << "        Carga de tareas        " << endl;
                cout << "-------------------------------" << endl;

                tareas.agregar(cargarTarea());

                cout << "Tareas ingresadas con exito" << endl;
                break;

            case 2:
                cout << "-------------------------------" << endl;
                cout << "        Lista de tareas        " << endl;
                cout << "-------------------------------" << endl;
                
                tareas.mostrar(false);
                break;

            case 3:
                cout << "-------------------------------" << endl;
                cout << "       Buscar Tarea        " << endl;
                cout << "-------------------------------" << endl;

                cout << "Ingrese el numero de tarea: ";
                cin >> numTarea;

                tarea = tareas.buscar(numTarea);

                cout << "Numero de tarea: " << numTarea << endl;
                tarea.mostrar();

                cout << endl;
                cout << "-------------------------------" << endl;
                cout << "¿Desea cambiar el estado de la tarea?" << endl;
                cout << "           1 - si                    " << endl;
                cout << "           2 - No          " << endl;
                cout << "           0 - Salir          " << endl;
                cout << "-------------------------------" << endl;
                
                cin >> opc;

                if (opc == 1) {
                    tareas.cambiarEstado(numTarea);
                }

                break;

            case 4:
                cout << "-------------------------------" << endl;
                cout << "       Tareas pendientes       " << endl;
                cout << "-------------------------------" << endl;

                tareas.mostrar(true);
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

