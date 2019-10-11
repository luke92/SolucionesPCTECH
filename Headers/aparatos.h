#ifndef APARATOS_H_INCLUDED
#define APARATOS_H_INCLUDED

#include "faparatos.h"
void menu_aparatos()
{
    while(1)
    {
        char opc;
        //system("color 20");
        cout<<endl<<endl;
        cout<<"\t""Menu Equipos"<<endl;
        cout<<"\t""------------"<<endl;
        cout<<endl;
        cout<<"\t""1) Agregar Equipo"<<endl;
        cout<<"\t""2) Modificar Equipo"<<endl;
        cout<<"\t""3) Listar Equipo"<<endl;
        cout<<"\t""4) Listar Equipos segun fechas"<<endl;
        cout<<"\t""5) Borrar Equipo"<<endl;
        cout<<"\t""6) Restaurar Equipo"<<endl;
        cout<<"\t""7) Dar como reparado un Equipo"<<endl;
        cout<<"\t""8) Entregar Equipo"<<endl;
        cout<<"\t""0) Volver al Menu Principal"<<endl;
        cout<<endl<<endl;
        cout<<"\t""Seleccione una opcion: ";
        opc=getch();
        system("cls");

        switch (opc)
        {
            case '1': agregar_pc();
                system("pause>null");
                    break;

            case '2': modificar_pc();
                system("pause>null");
                    break;

            case '3': listar_pc();
                system("pause>null");
                    break;

            case '4': listar_pc_x_fecha();
                system("pause>null");
                      break;

            case '5': borrar_pc();
                system("pause>null");
                      break;

            case '6': alta_pc();
                system("pause>null");
                        break;

            case '7': reparado_pc();
                system("pause>null");
                      break;

            case '8': entregar_pc();
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


#endif // APARATOS_H_INCLUDED
