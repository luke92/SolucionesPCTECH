#ifndef FTECNICOS_H_INCLUDED
#define FTECNICOS_H_INCLUDED

#include "funciones.h"

void agregar_tecnico()
{
    cout<<endl<<"Agregar Tecnicos"<<endl;
    cout<<"----------------"<<endl<<endl;
    int cod;
    Tecnicos c;
    cout<<"Codigo de Tecnico: ";
    cod=autocod_tecnico();
    cout<<cod<<endl;
    c.setcod(cod);
    c.cargar();
    c.grabar();
    cout<<"Tecnico agregado con exito";
}

void modificar_tecnico()
{
    cout<<endl<<"Modificar Tecnicos"<<endl;
    cout<<"------------------"<<endl<<endl;
    int cod,pos,band=0;
    Tecnicos c;
    char n[10];
    if(buscar_arch_tecnicos()==-1) {cout<<"No hay ningun Tecnico cargado";return;}
    while(band==0)
    {
    cout<<"Codigo de Tecnico: ";
    cin>>n;
        if(validar_cadenai(n)==-1)
        {
            cout<<"No es un numero!"<<endl;
        }
        else
        {
            band=1;
        }
    }
    cod=validacioni(n);
    pos=posicion_tecnico(cod);
    if(pos==-1) { cout<<"No existe ese Codigo!"; return;}
    c.leer(pos);
    if(c.getestado()==false) {cout<<"No existe ese Codigo!"; return;}
    c.cargar2();
    c.modificar(pos);
    cout<<"Tecnico modificado con exito!";
}


void borrar_tecnico()
{
    cout<<endl<<"Borrar Tecnicos"<<endl;
    cout<<"---------------"<<endl<<endl;
    int cod,pos,band=0;
    Tecnicos c;
    char n[10];
    if(buscar_arch_tecnicos()==-1) {cout<<"No hay ningun Tecnico cargado";return;}
    while(band==0)
    {
        cout<<"Codigo de Tecnico: ";
        cin>>n;
        if(validar_cadenai(n)==-1)
        {
            cout<<"No es un numero!"<<endl;
        }
        else
        {
            band=1;
        }
    }
    cod=validacioni(n);
    pos=posicion_tecnico(cod);
    if(pos==-1) { cout<<"No existe ese Codigo!"; return;}
    c.leer(pos);
    if(c.getestado()==false) { cout<<"Ya esta borrado ese Tecnico"; return;}
    cout<<"Advertencia!! Esta seguro de borrar este codigo? (S/N)? ";
    if(opcion()==1)
    {
    c.setestado(-1);
    c.modificar(pos);
    cout<<"Tecnico borrado con exito!";
    }
}

void alta_tecnico()
{
    cout<<endl<<"Dar de Alta Tecnicos"<<endl;
    cout<<"--------------------"<<endl<<endl;
    int cod,pos,band=0;
    char n[10];
    Tecnicos c;
    if(buscar_arch_tecnicos()==-1) {cout<<"No hay ningun Tecnico cargado";return;}
    while(band==0)
    {
        cout<<"Codigo de Tecnico: ";
        cin>>n;
        if(validar_cadenai(n)==-1)
        {
            cout<<"No es un numero!"<<endl;
        }
        else
        {
            band=1;
        }
    }
    cod=validacioni(n);
    pos=posicion_tecnico(cod);
    if(pos==-1) { cout<<"No existe ese Codigo!"; return;}
    c.leer(pos);
    if(c.getestado()==true) { cout<<"Ya esta activo ese Cliente";}
    c.setestado(1);
    c.modificar(pos);
    cout<<"Tecnico restaurado con exito!";
}

void listar_tecnico()
{
    cout<<endl<<"Listar Tecnicos"<<endl;
    cout<<"---------------"<<endl<<endl;
    Tecnicos c;
    int band=0,pos=0;
    if(buscar_arch_tecnicos()==-1) {cout<<"No hay ningun Tecnico cargado";return;}
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
    if(band==0) { cout<<"No hay ningun tecnico cargado"; }
}

void recaudacion_x_tecnico_t()
{
    cout<<endl<<"Recaudacion x Tecnico Total"<<endl;
    cout<<"---------------------------"<<endl<<endl;
    Reparacion r;
    Tecnicos t;
    int cod,band=0;char n[10],pos=0,pos2=0;
    float acum=0;
    if(buscar_arch_tecnicos()==-1) { cout<<"No hay ningun tecnico cargado";}
    if(buscar_arch_registros()==-1) { cout<<"No hay ningun registro cargado"; return;}
    while(band==0)
    {
    cout<<"Codigo de Tecnico: ";
    cin>>n;
        if(validar_cadenai(n)==-1)
        {
            cout<<"No es un numero!"<<endl;
        }
        else
        {
            band=1;
        }
    }
    cod=validacioni(n);
    pos=posicion_tecnico(cod);
    if(pos==-1) { cout<<"No existe ese tecnico"; return;}
    t.leer(pos);
    if(t.getestado()==false) { cout<<"No existe ese tecnico"; return;}
    while(r.leer(pos2)==1)
    {
        if(cod==r.getcod_tecnico())
        {
            if(r.getestado()==true)
            {
                if((r.getreparado()==true) && (r.getanio_e()>0))
                {
                    acum+=r.getimporte();
                }
            }
        }
        pos2++;
    }
    cout<<"Total Recaudado del tecnico "<<cod<<" : ";
    cout<<acum;
}

void recaudacion_x_tecnico_mes()
{
    cout<<endl<<"Recaudacion x Tecnico x Mes"<<endl;
    cout<<"---------------------------"<<endl<<endl;
    Reparacion r;
    Tecnicos t;
    int i,cod,m,anio,band=0;char n[10],pos=0,pos2=0;
    float mes[12];
    for(i=0;i<12;i++)
    {
        mes[i]=0;
    }
    if(buscar_arch_tecnicos()==-1) { cout<<"No hay ningun tecnico cargado";}
    if(buscar_arch_registros()==-1) { cout<<"No hay ningun registro cargado"; return;}
    while(band==0)
    {
    cout<<"Codigo de Tecnico: ";
    cin>>n;
        if(validar_cadenai(n)==-1)
        {
            cout<<"No es un numero!"<<endl;
        }
        else
        {
            band=1;
        }
    }
    cod=validacioni(n);
    pos=posicion_tecnico(cod);
    if(pos==-1) { cout<<"No existe ese tecnico"; return;}
    t.leer(pos);
    if(t.getestado()==false) { cout<<"No existe ese tecnico"; return;}
    cout<<"Fecha: "<<endl;
    anio=anios();
    while(r.leer(pos2)==1)
    {
        if(cod==r.getcod_tecnico())
        {
            if(r.getestado()==true)
            {
                if(r.getanio()==anio)
                {
                    if((r.getreparado()==true) && (r.getanio_e()>0))
                    {
                        m=r.getmes()-1;
                        mes[m]+=r.getimporte();
                    }
                }
            }
        }
        pos2++;
    }
    cout<<"Recaudacion total del tecnico del "<<anio<<endl;
    for(i=0;i<12;i++)
    {
        cout<<"Mes "<<i+1<<": "<<mes[i]<<endl;
    }
}

#endif // FTECNICOS_H_INCLUDED
