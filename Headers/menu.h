#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

//#include "gotoxy.h"
#include "aparatos.h"
#include "clientes.h"
#include "tecnicos.h"
#include "resumenes.h"
#include "tareas.h"
#include "extras.h"
#include "borrados.h"
#include "gotoxy.h"
#include <windows.h>


void menu()
{
    char opc;
    //recuadro(5,5,20,20,cBLANCO,cNEGRO);
    cout<<endl<<endl;
    cout<<"\t""\t""\t""Fecha Actual: ";mostrar_fecha();cout<<endl;
    cout<<"\t""\t""\t""------------- ""---------";cout<<endl<<endl;
    cout<<"\t""\t""\t""  Soluciones PC-TECH"<<endl;
    cout<<"\t""\t""\t""  ------------------"<<endl;
    cout<<endl;
    cout<<"\t""\t""\t""    Menu Principal"<<endl;
    cout<<"\t""\t""\t""    --------------"<<endl;
    cout<<endl;
    cout<<"\t""\t""\t""   1) Menu Equipos"<<endl;
    cout<<"\t""\t""\t""   2) Menu Clientes"<<endl;
    cout<<"\t""\t""\t""   3) Menu Tecnicos"<<endl;
    cout<<"\t""\t""\t""   4) Menu Resumenes"<<endl;
    cout<<"\t""\t""\t""   5) Menu Tareas"<<endl;
    cout<<"\t""\t""\t""   6) Menu Borrados"<<endl;
    cout<<"\t""\t""\t""   7) Instrucciones"<<endl;
    cout<<"\t""\t""\t""   8) Acerca de"<<endl;
    cout<<"\t""\t""\t""   0) Cerrar Programa"<<endl;

    cout<<endl<<endl;
    cout<<"\t""\t""\t""   Ingrese una opcion: ";
    opc=getch();
    system("cls");
    switch(opc)
    {
        case '1' :  menu_aparatos();
                    break;

        case '2' :  menu_clientes();
                    break;

        case '3' :  menu_tecnicos();
                    break;

        case '4' :  menu_resumenes();
                    break;

        case '5' :  menu_tareas();
                    break;

        case '6' :  menu_borrados();
                    break;

        case '7' :  manual();
                    break;

        case '8' :  acerca_de();
                    break;

        case '0' :  cerrar();
                    break;

        default :
                    break;
    }
    /*cout<<"Presione una tecla para continuar ";
    system("pause>null");*/
    system("cls");
}

#endif // MENU_H_INCLUDED
