#ifndef RESUMENES_H_INCLUDED
#define RESUMENES_H_INCLUDED

#include "fresumenes.h"
void menu_resumenes()
{
    while(1)
    {
        char opc;
        //system("color CF");
        cout<<endl<<endl;
        cout<<"\t""Menu Resumenes"<<endl;
        cout<<"\t""--------------"<<endl;
        cout<<endl;
        cout<<"\t""1) Listar PC'S reparadas"<<endl;
        cout<<"\t""2) Listar PC'S no reparadas"<<endl;
        cout<<"\t""3) Recaudacion Total"<<endl;
        cout<<"\t""4) Recaudacion Total x Mes"<<endl;
        cout<<"\t""5) Los Mejores Tecnicos"<<endl;
        cout<<"\t""0) Volver al Menu Principal"<<endl;
        cout<<endl<<endl;
        cout<<"\t""Seleccione una opcion: ";
        opc=getch();
        system("cls");

        switch (opc)
        {
            case '1': listar_pc_reparadas();
                    system("pause>nul");
                    break;

            case '2': listar_pc_no_reparadas();
                    system("pause>nul");
                    break;

            case '3': recaudacion_total();
                    system("pause>nul");
                    break;

            case '4': recuadacion_total_x_mes();
                        system("pause>nul");
                        break;

            case '5' :  max_tecnicos();
                        system("pause>nul");
                        break;

            case '0': return;
                    break;

            default:
                    break;
        }

        system("cls");
    }
}


#endif // RESUMENES_H_INCLUDED
