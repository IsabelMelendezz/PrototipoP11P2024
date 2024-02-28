//LOURDES ISABEL MELENDEZ PINEDA
//CARNET 9959-23-1379
// VARIANTE A
//----------CONTROL DE FACULTADES DE UNA UNIVERSIDAD------------

//Declaracion de liberias a utilizar
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <iomanip>

using namespace std;
//DECLARACION DE CONSTANTES
#define NUMERO_ALUMNOS 5
#define NUMERO_MATERIAS 5
#define NUMERO_NOTAS 4
#define MAX_CALIFICACION 100
#define MIN_CALIFICACION 0
#define NOMBRES 50

//PROTOTIPOS DE FUNCIONES VOID NO DEVUELVE VALOR
void llamaCiclo();
int busquedaAleatorios(int minimo, int maximo);
//NUMERO_NOTAS+1 tiene una columna extra para resultados
void llenarMatriz(float matriz[NUMERO_ALUMNOS][NUMERO_NOTAS + 1]);
void imprimirMatrizLinea();
float imprimirMatriz(float matriz[NUMERO_ALUMNOS][NUMERO_NOTAS + 1], char alumnos[NUMERO_ALUMNOS][NOMBRES], string nombreFacultad);

//INICIO DEL MAIN O PROGRAMA PRINCIPAL
int main()
{
    srand(getpid());//Semilla que genera los numeros aleatorios de la funcion numeros aleatorios
    llamaCiclo();
    return 0;
}
void llamaCiclo()
{
    //Declaracion de matrices por facultad
    float matriz_facultad_1[NUMERO_ALUMNOS][NUMERO_NOTAS + 1];
    float matriz_facultad_2[NUMERO_ALUMNOS][NUMERO_NOTAS + 1];
    float matriz_facultad_3[NUMERO_ALUMNOS][NUMERO_NOTAS + 1];
    char opcion;
    bool repetir = true;

    //declaracion de promedios
    float promedio_facultad_1;
    float promedio_facultad_2;
    float promedio_facultad_3;
    //declaracion de vector para llenar los nombres
    char alumnos[NUMERO_ALUMNOS][NOMBRES] = {"ANA","HECTOR","LUCIA ","PABLO","EMILIO"};

    //comienzo del ciclo do while para controlar el flujo de repeticion
    do
    {

        system("cls");
        promedio_facultad_1=0;
        promedio_facultad_2=0;
        promedio_facultad_3=0;
        //impresion de encabezado
        cout<<"------------------------Bienvenido---------------------" << endl;
        cout<<"-----------------Comparacion de facultades-------------"<<endl<<endl;
        llenarMatriz(matriz_facultad_1);
        promedio_facultad_1 = imprimirMatriz(matriz_facultad_1, alumnos, "Facultad de Ingenieria");
        llenarMatriz(matriz_facultad_2);
        promedio_facultad_2 = imprimirMatriz(matriz_facultad_2, alumnos, "Facultad de Arquitectura");
        llenarMatriz(matriz_facultad_3);
        promedio_facultad_3 = imprimirMatriz(matriz_facultad_3, alumnos, "Facultad de Administracion");
        //comparativa de promedios
        if (promedio_facultad_1 > promedio_facultad_2 && promedio_facultad_1 > promedio_facultad_3)
        {
            cout << " La facultad con el mejor promedio es : " << "Facultad de Ingenieria" << " con un promedio de: " << promedio_facultad_1 << endl;
        } else
        if (promedio_facultad_2 > promedio_facultad_1 && promedio_facultad_2 > promedio_facultad_3)
        {
            cout << " La facultad con el mejor promedio es : " << "Facultad de Arquitectura" << " con un promedio: " << promedio_facultad_2 << endl;
        } else
        if (promedio_facultad_3 > promedio_facultad_2 && promedio_facultad_3 > promedio_facultad_1)
        {
            cout << " La facultad con el mejor promedio es : " << "Facultad de Administracion" << " con un promedio: " << promedio_facultad_3 << endl;
        } else
        {
            cout << " Algunas facultades tienen el mismo promedio " << endl << endl;
        }
        cout << "Desea otro calculo (s/n)? ";
        cin >> opcion;
        if (opcion == 'n')
        {
            repetir=false;
        }
    } while (repetir);
}
// fin del while
int busquedaAleatorios(int minimo, int maximo)
{
    return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1); //formula de numeros aleatorios
}

void llenarMatriz(float matriz[NUMERO_ALUMNOS][NUMERO_NOTAS + 1])
{
    int y, x;
    for (y = 0; y < NUMERO_ALUMNOS; y++)
    {
        float suma = 0;
        int calificacion = 0;
        for (x = 0; x < NUMERO_NOTAS; x++)
        {
            if (x == 0 || x == 3)  //primer parcial
            {
                calificacion = busquedaAleatorios(MIN_CALIFICACION, 20);
            } else if (x == 1)  //segundo parcial
            {
                calificacion = busquedaAleatorios(MIN_CALIFICACION, 25);
            } else if (x == 2)  //examen final
            {
                calificacion = busquedaAleatorios(MIN_CALIFICACION, 35);
            }
            suma += (float)calificacion;
            matriz[y][x] = calificacion;
            calificacion=0;
        }
        // Agregar promedio

        matriz[y][NUMERO_NOTAS] = suma;
    }
}

void imprimirMatrizLinea()
{
    int x;

    cout << "+--------";
    for (x = 0; x < NUMERO_NOTAS + 1; x++)
    {
        cout << "+---------";
    }
    cout << "+\n";
}
float imprimirMatriz(float matriz[NUMERO_ALUMNOS][NUMERO_NOTAS + 1], char alumnos[NUMERO_ALUMNOS][NOMBRES], string nombreFacultad)
{
    //Funcion que imprime la matriz en pantalla y realizando los calculos necesarios del promedio
    int y, x;

    float promedioMayor = matriz[0][NUMERO_NOTAS];
    float promedioMenor = matriz[0][NUMERO_NOTAS];
    float totalGeneral = 0;
    float promedioGeneral = 0;
    char alumnoPromedioMayor[NOMBRES];
    char alumnoPromedioMenor[NOMBRES];
    memcpy(alumnoPromedioMayor, alumnos[0], NOMBRES);
    memcpy(alumnoPromedioMenor, alumnos[0], NOMBRES);
    cout << nombreFacultad << endl;
    imprimirMatrizLinea();
    cout << setw(9) << " Alumno";
    for (x =0; x <3; x++)
    {
        cout << setw(9) << " Parcial " << x+1;
    }
    //dejo estas iteraciones fuera para poder modificar el encabezado de columna de tabla
    cout << setw(9) << " Actividad" <<setw(9)<<"Total"<<endl;

    //funcion que imprime el promedio
    imprimirMatrizLinea();
    for (y = 0; y < NUMERO_ALUMNOS; y++)
    {
        cout << "!" << setw(8) << alumnos[y] << "!";
        float suma = 0;
        for (x = 0; x < NUMERO_NOTAS; x++)
        {
            int calificacion = matriz[y][x];
            cout << setw(9) << calificacion << "!";
        }
        float promedio = matriz[y][NUMERO_NOTAS];
        totalGeneral += matriz[y][NUMERO_NOTAS];
        if (promedio > promedioMayor)
        {
            promedioMayor = promedio;
            memcpy(alumnoPromedioMayor, alumnos[y], NOMBRES);
        }
        if (promedio < promedioMenor)
        {
            promedioMenor = promedio;
            memcpy(alumnoPromedioMenor, alumnos[y], NOMBRES);
        }
        cout << setw(9) << fixed << setprecision(2) << promedio << "!" << endl;
        imprimirMatrizLinea();
    }
    promedioGeneral = totalGeneral / NUMERO_ALUMNOS;
    cout << "La Nota mayor la tiene: "<< alumnoPromedioMayor << " con: "<< promedioMayor<<" puntos" << endl;
    cout << "La Nota menor la tiene: " << alumnoPromedioMenor <<" con: " << promedioMenor <<" puntos"<< endl;
    cout << "Nota promedio de la facultad : " << setw(10) <<  promedioGeneral << endl << endl;
    return promedioGeneral;
}
