#include "TarjetasManager.h"

TarjetasManager::TarjetasManager(){
    _archivoT = TarjetasArchivo("tarjetas.dat");
}

void TarjetasManager::agregar(){
    int numTarjeta, dni, valido, dia, mes, anio;
    float saldo = 0.0f;

    numTarjeta = generarNumeroTarjeta();

    cout << "Tarjeta num " << numTarjeta << endl;

    do{
        cout << "Ingrese numero de DNI: ";
        cin >> dni;

        valido = _archivoT.buscarDni(dni);

        if(valido > 0){
            cout << "Numero de DNI ya existe en el sistema: ";
            return;
        }

    }while(valido > 0);

    cout << "Ingrese monto: ";
    cin >> saldo;

    cout << "Ingrese fecha de alta de la tarjeta: " << endl;
    cout <<  "Dia: ";
    cin >> dia;

    cout << "Mes: ";
    cin >> mes;

    cout << "Anio: ";
    cin >> anio;

    Tarjeta tarjeta(numTarjeta, Fecha(dia,mes,anio), dni, saldo, true);

    if(_archivoT.guardar(tarjeta)){
        cout << "Se guardo tarjeta correctamente" << endl;
    }
    else{
        cout << "No se pudo guardar";
    }
}

int TarjetasManager::generarNumeroTarjeta(){
    return (_archivoT.getCantidadRegistros() + 1);
}

/*
        void agregar();
        void modificar();
        void buscarPorNumeroTarjeta();
        void buscarPorDni();
        void baja();

    private:
        TarjetasArchivo _archvoT;

        int generarNumeroTarjeta();
*/
