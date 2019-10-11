#include <windows.h>
#include <iostream>
#include <time.h>
#include <conio.h>
using namespace std;


#include "Headers/todos.h"


int main()
{
    if(buscar_arch_licencia()==-1)
    {
        registrar();
    }
    //if(comparar()==-1) { licencia_incorrecta();}
    system("cls");
    system("color F0");
    imagen_utn();
    logo();
    presentacion();
    system("cls");
    while(1)
    {
        system("color 17");
        menu();
    }
}
