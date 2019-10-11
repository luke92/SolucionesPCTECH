#ifndef BORRADOS_H_INCLUDED
#define BORRADOS_H_INCLUDED

#include "fborrados.h"
void menu_borrados()
{
    while(1)
    {
        char opc;
        //system("color 41");
        cout<<endl<<endl;
        cout<<"\t""Menu Borrados"<<endl;
        cout<<"\t""-------------"<<endl;
        cout<<endl;
        cout<<"\t""1) Listar PC'S borradas"<<endl;
        cout<<"\t""2) Listar Clientes borrados"<<endl;
        cout<<"\t""3) Listar Tecnicos borrados"<<endl;
        //cout<<"\t""4) Listar Tareas borradas"<<endl;
        cout<<"\t""0) Volver al Menu Principal"<<endl;
        cout<<endl<<endl;
        cout<<"\t""Seleccione una opcion: ";
        opc=getch();
        system("cls");

        switch (opc)
        {
            case '1': listar_pc_borradas();
                system("pause>null");
                    break;

            case '2': listar_clientes_borrados();
                system("pause>null");
                    break;

            case '3': listar_tecnicos_borrados();
                system("pause>null");
                    break;

            /*case '4': listar_tareas_borradas();
                system("pause>null");
                        break;*/

            case '0': return;
                    break;

            default:
                    break;
        }

        system("cls");
    }
}


#endif // BORRADOS_H_INCLUDED
