#pragma once
#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <ctime>
#include "Etiqueta.h"
#include "Tarea.h"
#include "ArchivoTareas.h"

using namespace std;
Etiqueta cargarEtiqueta(int can);
bool cargarTarea(Tarea, ArchivoTareas);
void mostrarTareas();
Fecha fechaActual();
int diferenciaDias(Fecha fechaActual, Fecha fechaLimite);