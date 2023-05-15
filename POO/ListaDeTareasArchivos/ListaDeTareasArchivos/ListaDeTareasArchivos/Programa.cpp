#include "Programa.h"
using namespace std;

void Programa::ejecutar() {
	int opc;

	do {
		cout << "-------MI PROGRAMA------" << endl;
		cout << "1 - TAREAS" << endl;
		cout << "0 - SALIR" << endl;
		cout << "------------------------" << endl;

		cout << "Opcion: ";
		cin >> opc;

		switch (opc) {
			case 1:
				_tareaMenu.mostrar();
				break;
			case 0:
				cout << "Gracias por utilizar nuestra aplicacion :)...";
				break;
		}

	} while (opc != 0);
}