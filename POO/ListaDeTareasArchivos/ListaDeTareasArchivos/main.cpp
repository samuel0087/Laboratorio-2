#pragma once
#include <iostream>
#include "funciones.h"
using namespace std;

int main()
{
    ArchivoTareas aTareas("tarea.dat");
    Tarea tarea;
    int opc, numTarea;
    Fecha fechaAtual = fechaActual();

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

                if (cargarTarea(tarea, aTareas)) {
                    cout << "Tareas ingresadas con exito" << endl;
                }
                else {
                    cout << "Error al registrar " << endl;
                }

                
                break;

            case 2:
                cout << "-------------------------------" << endl;
                cout << "        Lista de tareas        " << endl;
                cout << "-------------------------------" << endl;
                
                if (!aTareas.listarTarea(false)) {
                    cout << "Error al registrar " << endl;
                }
              
                break;

            case 3:
                cout << "-------------------------------" << endl;
                cout << "       Buscar Tarea        " << endl;
                cout << "-------------------------------" << endl;

                do {
                    cout << "Ingrese el numero de tarea: ";
                    cin >> numTarea;

                    cout << "Numero de tarea: " << numTarea << endl;
                    tarea = aTareas.buscarTarea(numTarea);

                    if (tarea.getId() == numTarea) {
                        tarea.mostrar();
                        tarea.getTags().mostrar();
                    }
                    else {
                        cout << "Ingrese un codigo de tarea valido por favor." << endl;
                    }


                } while (tarea.getId() != numTarea);           
                
                cout << endl;
                cout << "-------------------------------" << endl;
                cout << "¿Desea cambiar el estado de la tarea?" << endl;
                cout << "           1 - si                    " << endl;
                cout << "           2 - No          " << endl;
                cout << "           0 - Salir          " << endl;
                cout << "-------------------------------" << endl;
                
                cin >> opc;

                if (opc == 1) {
                    
                }

                break;

            case 4:
                cout << "-------------------------------" << endl;
                cout << "   Tareas pendientes :" << fechaAtual.toString() << endl;
                cout << "-------------------------------" << endl;

                if (!aTareas.listarTarea(true)) {
                    cout << "Error al registrar " << endl;
                }
                
                break;

            case 0:
                break;

            default:
                break;
        }

        system("pause");
        system("cls");



    } while (opc != 0);

    return 0;
}

