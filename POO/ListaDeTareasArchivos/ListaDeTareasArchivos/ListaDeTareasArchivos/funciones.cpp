#include "funciones.h"

/*bool cargarTarea(Tarea t, ArchivoTareas at) {

    int dia, mes, anio, dificultad, id, cantTag;
    string descripcion;
    Etiqueta tags;

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

    cout << "Ingrese la cantidad de etiquetas que desea (0 a 10): ";
    cin >> cantTag;

    tags = cargarEtiqueta(cantTag);

    
    t.setTags(tags);

    t.setEstado(false);

    return at.guardarTarea(t);

}

Etiqueta cargarEtiqueta(int canTags) {
    Etiqueta tags;
    bool status;

    cin.ignore();

    for (int i = 0; i < canTags; i++) {
        string tag;

        
        do {
            cout << "Ingrese etiqueta num " << i + 1 << ": ";
            getline(cin, tag);

            std::cout << tag;

            system("pause");

            status = tags.setNombre(tag);

            if (!status) {
                cout << "tag no valida, prueba otra vez." << endl;
            }

        } while (!status);


    }

    return tags;
}
*/

Fecha fechaActual() {
    time_t timeActual;
    timeActual = time(NULL);

    struct tm* fech;
    fech = localtime(&timeActual);

    return Fecha(fech->tm_mday, fech->tm_mon + 1, fech->tm_year + 1900);
}

int diferenciaDias(Fecha fechaActual, Fecha fechaLimite) {
    int cont = 0;
    Fecha aux;
    bool fechaMayor = (fechaActual.toString("YYYY/MM/DD") < fechaLimite.toString("YYYY/MM/DD"));

    if (!fechaMayor) {
        aux = fechaActual;
        fechaActual = fechaLimite;
        fechaLimite = aux;
    }

    while (fechaActual.toString("YYYY/MM/DD") != fechaLimite.toString("YYYY/MM/DD")) {
        fechaActual.agregarDias(1);
        cont++;
    }

    if (!fechaMayor) {
        return (cont * -1);
    }

    return cont;
}
