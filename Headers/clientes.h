#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

#include "fclientes.h"
void menu_clientes()
{
    while(1)
    {
        char opc;
        //system("color C1");
        cout<<endl<<endl;
        cout<<"\t""Menu Clientes"<<endl;
        cout<<"\t""-------------"<<endl;
        cout<<endl;
        cout<<"\t""1) Agregar Cliente"<<endl;
        cout<<"\t""2) Modificar Cliente"<<endl;
        cout<<"\t""3) Borrar Cliente"<<endl;
        cout<<"\t""4) Restaurar Cliente"<<endl;
        cout<<"\t""5) Listar Cliente"<<endl;
        cout<<"\t""6) Buscar Cliente"<<endl;
        cout<<"\t""0) Volver al Menu Principal"<<endl;
        cout<<endl<<endl;
        cout<<"\t""Seleccione una opcion: ";
        opc=getch();
        system("cls");

        switch (opc)
        {
            case '1': agregar_cliente();
                system("pause>null");
                    break;

            case '2': modificar_cliente();
                system("pause>null");
                    break;

            case '3': borrar_cliente();
                system("pause>null");
                    break;

            case '4': alta_cliente();
                system("pause>null");
                        break;

            case '5': listar_cliente();
                system("pause>null");
                    break;

            case '6': buscar_cliente();
                    break;

            case '0': return;
                    break;

            default:
                    break;
        }

        system("cls");
    }
}


#endif // CLIENTES_H_INCLUDED
