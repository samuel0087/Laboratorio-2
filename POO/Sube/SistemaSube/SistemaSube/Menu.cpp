#include "Menu.h"

void Menu::menuPrincipal(){
    int opc;

    do{
        system("cls");
        cout << "--------BIENVENIDOS------" << endl;
        cout << "1 - Tarjetas Sube" << endl;
        cout << "2 - Viajes" << endl;
        cout << "0 - Salir" << endl;
        cout << endl;

        cout << "Ingrese una opcion: ";
        cin >> opc;

        switch(opc){
            case 1:
                menuTarjetas();
                break;
            case 2:
                menuViajes();
                break;
            case 0:
                cout << "Gracias por visitar esta app :)" << endl;
                break;
        }
    }while(opc != 0);

    system("pause");
}

void Menu::menuTarjetas(){
    int opc;

    do{
        system("cls");
        cout << "--------TARJETAS------" << endl;
        cout << "1 - Agregar Sube" << endl;
        cout << "2 - --------" << endl;
        cout << "0 - Salir" << endl;
        cout << endl;

        cout << "Ingrese una opcion: ";
        cin >> opc;

        switch(opc){
            case 1:
                _tarjetaManager.agregar();
                break;
            case 2:
                break;
            case 0:
                cout << "Gracias por visitar esta app :)" << endl;
                break;
        }
    }while(opc != 0);

    system("pause");

}

void Menu::menuViajes(){

}
