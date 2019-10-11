#ifndef TECNICOS_H_INCLUDED
#define TECNICOS_H_INCLUDED

#include "ftecnicos.h"
void menu_tecnicos()
{

        while(1)
    {
        char opc;
        //system("color B0");
        cout<<endl<<endl;
        cout<<"\t""Menu Tecnicos"<<endl;
        cout<<"\t""-------------"<<endl;
        cout<<endl;
        cout<<"\t""1) Agregar Tecnico"<<endl;
        cout<<"\t""2) Modificar Tecnico"<<endl;
        cout<<"\t""3) Borrar Tecnico"<<endl;
        cout<<"\t""4) Restaurar Tecnico"<<endl;
        cout<<"\t""5) Listar Tecnicos"<<endl;
        cout<<"\t""6) Recaudacion por Tecnico total"<<endl;
        cout<<"\t""7) Recaudacion por Tecnico por Mes"<<endl;
        cout<<"\t""0) Volver al Menu Principal"<<endl;
        cout<<endl<<endl;
        cout<<"\t""Seleccione una opcion: ";
        opc=getch();
        system("cls");

        switch (opc)
        {
            case '1': agregar_tecnico();
                    system("pause>null");
                    break;

            case '2': modificar_tecnico();
                    system("pause>null");
                    break;

            case '3': borrar_tecnico();
                    system("pause>null");
                    break;

            case '4': alta_tecnico();
                    system("pause>null");
                        break;

            case '5': listar_tecnico();
                system("pause>null");
                    break;

            case '6': recaudacion_x_tecnico_t();
                    system("pause>null");
                      break;

            case '7': recaudacion_x_tecnico_mes();
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


#endif // TECNICOS_H_INCLUDED
