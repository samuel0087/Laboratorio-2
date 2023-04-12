// fechas.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;

#include "Fecha.h";
int main()
{
    Fecha fech, fech2(29, 2, 2024);

    cout << "Dia: " << fech.getDia() << endl;
    cout << "Mes: " << fech.getMes() << endl;
    cout << "Anio: " << fech.getAnio() << endl;

    cout << "-----------------------" << endl;

    cout << "Dia: " << fech2.getDia() << endl;
    cout << "Mes: " << fech2.getMes() << endl;
    cout << "Anio: " << fech2.getAnio() << endl;
    

    cout << "Hello World!\n";
    cout << endl;



}
