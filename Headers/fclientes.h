#ifndef FCLIENTES_H_INCLUDED
#define FCLIENTES_H_INCLUDED

#include "funciones.h"
#include "buscar.h"
void agregar_cliente()
{
    cout<<endl<<"Agregar Cliente"<<endl;
    cout<<"---------------"<<endl<<endl;
    int cod;
    Clientes c;
    cout<<"Codigo de Cliente: ";
    cod=autocod_cliente();
    cout<<cod<<endl;
    c.setcod(cod);
    c.cargar();
    c.grabar();
    cout<<"Cliente agregado con exito!";
}

void modificar_cliente()
{
    cout<<endl<<"Modificar Cliente"<<endl;
    cout<<"-----------------"<<endl<<endl;
    int cod,pos,band=0;
    char n[10];
    Clientes c;
    if(buscar_arch_clientes()==-1) {cout<<"No hay ningun Cliente cargado"; return; }
    cout<<"Codigo de Cliente: ";
    while(band==0)
    {
        cin>>n;
        if(validar_cadenai(n)==-1) {cout<<"No es un numero!"<<endl;}
        else { band=1; }
    }
    cod=validacioni(n);
    pos=posicion_cliente(cod);
    if(pos==-1) { cout<<"No existe ese Codigo!"; return;}
    c.leer(pos);
    if(c.getestado()==false) { cout<<"No existe ese Codigo!"; return;}
    c.cargar2();
    c.modificar(pos);
    cout<<"Cliente modificado con exito!";
}

void borrar_cliente()
{
    cout<<endl<<"Borrar Cliente"<<endl;
    cout<<"--------------"<<endl<<endl;
    int cod,pos,band=0;
    Clientes c;
    char n[10];
    if(buscar_arch_clientes()==-1) {cout<<"No hay ningun Cliente cargado"; return; }
    cout<<"Codigo de Cliente: ";
    while(band==0)
    {
        cin>>n;
        if(validar_cadenai(n)==-1) { cout<<"No es un numero!"<<endl; }
        else { band=1; }
    }
    cod=validacioni(n);
    pos=posicion_cliente(cod);
    if(pos==-1) { cout<<"No existe ese Codigo!"; return;}
    c.leer(pos);
    if(c.getestado()==false) {cout<<"Ya esta borrado ese Cliente"; return;}
    cout<<"Advertencia!! Esta seguro de borrar este codigo? (S/N)? ";
    if(opcion()==1)
    {
        c.setestado(-1);
        c.modificar(pos);
        cout<<"Cliente borrado con exito!";
    }
}

void listar_cliente()
{
    cout<<endl<<"Listar Clientes"<<endl;
    cout<<"---------------"<<endl<<endl;
    Clientes c;
    int band=0,pos=0;
    if(buscar_arch_clientes()==-1) {cout<<"No hay ningun Cliente cargado"; return; }
    while(c.leer(pos)==1)
    {
        if(c.getestado()==true)
        {
            band=1;
            system("pause>nul");
            c.mostrar();
            cout<<endl;
            cout<<endl;
        }
        pos++;
    }
    if(band==0) { cout<<"No hay ningun cliente cargado"; }
}

void buscar_cliente()
{
    if(buscar_arch_clientes()==-1) {cout<<"No hay ningun Cliente cargado"; return; }
    while(1)
    {
        char opc;
        cout<<endl<<endl;
        cout<<"\t""Buscar Cliente"<<endl;
        cout<<"\t""-------------"<<endl;
        cout<<endl;
        cout<<"\t""1) Buscar por Nombre"<<endl;
        cout<<"\t""2) Buscar por Apellido"<<endl;
        cout<<"\t""3) Borrar por Telefono"<<endl;
        cout<<"\t""4) Buscar por Localidad"<<endl;
        cout<<"\t""5) Buscar por Direccion"<<endl;
        cout<<"\t""6) Buscar por Codigo Postal"<<endl;
        cout<<"\t""7) Buscar por Codigo Cliente"<<endl;
        cout<<"\t""0) Volver al Menu Principal"<<endl;
        cout<<endl<<endl;
        cout<<"\t""Seleccione una opcion: ";
        opc=getch();
        system("cls");

            switch (opc)
            {
                case '1': buscar_nombre();
                    system("pause>null");
                    break;

                case '2': buscar_apellido();
                    system("pause>null");
                        break;

                case '3': buscar_telefono();
                    system("pause>null");
                        break;

                case '4': buscar_localidad();
                    system("pause>null");
                            break;

                case '5': buscar_direccion();
                    system("pause>null");
                        break;

                case '6': buscar_codpostal();
                    system("pause>null");
                        break;

                case '7': buscar_codcliente();
                    system("pause>null");

                case '0': return;
                        break;

                default:
                        break;
        }
        system("cls");
    }
}

void alta_cliente()
{
    cout<<endl<<"Dar de Alta Cliente"<<endl;
    cout<<"-------------------"<<endl<<endl;
    int cod,pos,band=0;
    Clientes c;
    char n[10];
    if(buscar_arch_clientes()==-1) {cout<<"No hay ningun Cliente cargado"; return; }
    cout<<"Codigo de Cliente: ";
    while(band==0)
    {
        cin>>n;
        if(validar_cadenai(n)==-1) { cout<<"No es un numero!"<<endl;}
        else
        {
            band=1;
        }
    }
    cod=validacioni(n);
    pos=posicion_cliente(cod);
    if(pos==-1) { cout<<"No existe ese Codigo!"; return;}
    c.leer(pos);
    if(c.getestado()==true){ cout<<"Ya esta activo ese cliente"; return;}
    c.setestado(1);
    c.modificar(pos);
    cout<<"Cliente restaurado con exito!";
}
#endif // FCLIENTES_H_INCLUDED
