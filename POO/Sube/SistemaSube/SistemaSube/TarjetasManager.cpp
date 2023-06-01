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

        if(valido >= 0){
            cout << "Numero de DNI ya existe en el sistema " << endl;
            system("pause");
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

    cout << endl;

    Tarjeta tarjeta(numTarjeta, Fecha(dia,mes,anio), dni, saldo, true);  

    if(_archivoT.guardar(tarjeta)){
        cout << "-------------------------------" << endl;
        cout << "Se guardo tarjeta correctamente" << endl;
        cout << "-------------------------------" << endl;
        mostrar(tarjeta);
    }
    else{
        cout << "No se pudo guardar";
    }
    system("pause");
}

void TarjetasManager::listarTodo() {
    int cantRegistros = _archivoT.getCantidadRegistros();
    Tarjeta* tarjetas = new Tarjeta[cantRegistros];

    if (tarjetas == nullptr) {
        return;
    }

    _archivoT.leer(tarjetas, cantRegistros);

    

    cout << "            Listado de tarjetas SUBE -> " << cantRegistros << endl;
    cout << "--------------------------------------------------" << endl;

    for (int i = 0; i < cantRegistros; i++) {
        if (tarjetas[i].getEstado()) {
            mostrar(tarjetas[i]);
            cout << "----------------------------------------" << endl;
        }
    }

    system("pause");
}

void TarjetasManager::mostrar(Tarjeta tarjeta) {
    cout << "Numero de tarjeta : " << tarjeta.getNumeroTargeta() << endl;
    cout << "Fecha de alta     : " << tarjeta.getFechaAlta().toString() << endl;
    cout << "DNI de propietario: " << tarjeta.getDniUsuario() << endl;
    cout << "Saldo actual      : " << tarjeta.getSaldo() << endl;
}

int TarjetasManager::generarNumeroTarjeta() {
    return (_archivoT.getCantidadRegistros() + 1);
}

void TarjetasManager::modificar() {
    int dni;
    float saldo;

    cout << "Ingrese numero de DNI: ";
    cin >> dni;

    int pos = _archivoT.buscarDni(dni);
    
    if (pos < 0) {
        cout << "No hay ningun elemento con ese DNI" << endl;
        return;
    }

    Tarjeta tarjeta = _archivoT.leer(pos);

    cout << "Ingrese monto a cargar: ";
    cin >> saldo;

    saldo += (float)tarjeta.getSaldo();
    tarjeta.setSaldo(saldo);

    if (_archivoT.guardar(tarjeta, pos)) {
        cout << "-------------------------------" << endl;
        cout << "Se guardo tarjeta correctamente" << endl;
        cout << "-------------------------------" << endl;
        mostrar(tarjeta);
    }
    else {
        cout << "No se pudo guardar";
    }
    system("pause");
}

/*
        void modificar();
        void buscarPorNumeroTarjeta();
        void buscarPorDni();
        void baja();

    private:
        TarjetasArchivo _archvoT;

        int generarNumeroTarjeta();
*/
