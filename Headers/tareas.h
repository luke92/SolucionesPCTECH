#ifndef TAREAS_H_INCLUDED
#define TAREAS_H_INCLUDED

#include "ftareas.h"
void menu_tareas()
{
    while(1)
    {
        char opc;
        //system("color 30");
        cout<<endl<<endl;
        cout<<"\t""Menu Tareas"<<endl;
        cout<<"\t""-----------"<<endl;
        cout<<endl;
        cout<<"\t""1) Agregar Tarea"<<endl;
        cout<<"\t""2) Modificar Tarea"<<endl;
        cout<<"\t""3) Listar Tareas"<<endl;
        cout<<"\t""0) Volver al Menu Principal"<<endl;
        cout<<endl<<endl;
        cout<<"\t""Seleccione una opcion: ";
        opc=getch();
        system("cls");

        switch (opc)
        {
            case '1': agregar_tareas();
                    system("pause>null");
                      break;

            case '2': modificar_tareas();
                    system("pause>null");
                      break;

            case '3': listar_tareas();
                    system("pause>null");
                      break;

            case '0': return;
                      break;

            default:
                    break;
        }

        system("cls");
    }
}


#endif // TAREAS_H_INCLUDED
