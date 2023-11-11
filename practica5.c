/*
   Nombre del archivo: practica5.c
   Autor: Lizeth Barrios Retana
   Fecha de creación: 20 de septiembre de 2023
   Descripción: Este programa tiene 2 opciones, uno que es un juego de una loteria de numeros, el numero es aleatorio y si sale el mismo numero que en que esta estipulado ganas, de lo contrario pierdes; el segundo es un programa que simula una carrera de carros y te dice cual es el ganador.
*/
#include <stdio.h>
#include "BRL.h"
#include <time.h>

static int numeroGanador = 9;

int generarNumeroLoteria(int ri, int rf);
int randomcarro(int ri, int rf);
void iniciarCarrera();

int main()
{
    srand(time(NULL));
    int menu = 0;
    int op;
    int num;

    do
    {
        op = validarnumeros("\n    menu\n1. Juego de la loteria\n2. Carrera de carros\n3. Salir\n", 1, 3);
        switch (op)
        {
        case 1:
            num = generarNumeroLoteria(1, 100);
            if (num == numeroGanador)
            {
                printf("¡Felicidades, ganaste la lotería!");
            }
            else
            {
                printf("Lo siento, no ganaste esta vez.");
            }
            menu = 1;
            break;
        case 2:
            iniciarCarrera();
            menu = 1;
            break;
        case 3:
            system("cls");
            printf("FIN DEL PROGRAMA");
            menu = 0;
            break;
        }

    } while (menu == 1);
    return 0;
}

/*
   Función: generarNumeroLoteria
   Descripción: Esta función genera numeros aleatorios para el numero de la loteria.
   Parámetros:
     - r: es el resultado
     - ri: rango inicial
     - rf: rango final
   Valor de retorno: numero generado aleatoriamente.
*/

int generarNumeroLoteria(int ri, int rf)
{
    int r;
    r = (rf - ri) + 1;
    return (rand() % r) + ri;
}

/*
   Función: iniciarCarrera
   Descripción: hace la simulacion de la carrera de los automobiles.
   Parámetros:
     - carro1: es el carro 1.
     - carro2: es el carro 2.
     - carro3: es el carro 3.
     - tiempo1: es el tiempo del carro 1.
     - tiempo2: es el tiempo del carro 2.
     - tiempo3: es el tiempo del carro 3.
   Valor de retorno: no retorna, solo muestra los tiempos y distancias de los carros y el carro ganador.
*/

void iniciarCarrera()
{
    register int carro1, carro2, carro3;
    float tiempo1, tiempo2, tiempo3;
    carro1 = randomcarro(100, 200);
    carro2 = randomcarro(100, 200);
    carro3 = randomcarro(100, 200);

    tiempo1 = 1000.0 / (carro1 / 3.6);
    tiempo2 = 1000.0 / (carro2 / 3.6);
    tiempo3 = 1000.0 / (carro3 / 3.6);

    printf("El carro1 tardo %f segundos para recorrer %d km\n", tiempo1, carro1);
    printf("El carro2 tardo %f segundos para recorrer %d km\n", tiempo2, carro2);
    printf("El carro3 tardo %f segundos para recorrer %d km\n", tiempo3, carro3);

    if (tiempo2 < tiempo1)
    {
        if (tiempo2 < tiempo3)
        {
            printf("Carro gandor: Carro2\n");
        }
        else
        {
            printf("Carro gandor: Carro3\n");
        }
    }
    else
    {
        if (tiempo1 < tiempo3)
        {
            printf("Carro gandor: Carro1");
        }
    }
}

/*
   Función: randomcarro
   Descripción: Esta función genera numeros aleatorios para los kilometros de los carros.
   Parámetros:
     - r: es el resultado
     - ri: rango inicial
     - rf: rango final
   Valor de retorno: numero generado aleatoriamente.
*/

int randomcarro(int ri, int rf)
{
    int r;
    r = (rf - ri) + 1;
    return (rand() % r) + ri;
}
