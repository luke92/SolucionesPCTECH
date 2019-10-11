#ifndef FRESUMENES_H_INCLUDED
#define FRESUMENES_H_INCLUDED

#include "funciones.h"

void listar_pc_reparadas()
{
    cout<<endl<<"Listar PC Reparadas"<<endl;
    cout<<"-------------------"<<endl<<endl;
    int band=0;
    Reparacion r;
    int cod,pos=0;
    if(buscar_arch_registros()==-1) {cout<<"No hay ninguna PC"; return;}
    while(r.leer(pos)==1)
    {
        if(r.getestado()==true)
        {
            if(r.getreparado()==true)
            {
                band=1;
                system("pause>nul");
                r.mostrar();
                cod=r.getcod_rep();
                cout<<"Tareas: ";
                mostrar_detalles(cod);
                cout<<endl<<endl;
            }
        }
        pos++;
    }
    if(band==0) { cout<<"No hay ninguna PC Reparada";}
}

void listar_pc_no_reparadas()
{
    cout<<endl<<"Listar PC NO Reparadas"<<endl;
    cout<<"----------------------"<<endl<<endl;
    int band=0;
    Reparacion r;
    int cod,pos=0;
    if(buscar_arch_registros()==-1) {cout<<"No hay ninguna PC"; return;}
    while(r.leer(pos)==1)
    {
        if(r.getestado()==true)
        {
            if(r.getreparado()==false)
            {
                band=1;
                system("pause>nul");
                r.mostrar();
                cod=r.getcod_rep();
                cout<<"Tareas: ";
                mostrar_detalles(cod);
                cout<<endl<<endl;
            }
        }
        pos++;
    }
    if(band==0) { cout<<"No hay ninguna PC sin Reparar";}
}


void recaudacion_total()
{
    cout<<endl<<"Recaudacion Total del Local"<<endl;
    cout<<"---------------------------"<<endl<<endl;
    Reparacion r;
    int pos=0;
    float acum=0;
    if(buscar_arch_registros()==-1) { cout<<"No hay ningun registro cargado"; return;}
    while(r.leer(pos)==1)
    {
        if(r.getestado()==true)
        {
            if((r.getreparado()==true) && (r.getanio_e()>0))
            {
            acum+=r.getimporte();
            }
        }
        pos++;
    }
    cout<<"Total Recaudado del Local: ";
    cout<<acum;
}

void recuadacion_total_x_mes()
{
    cout<<endl<<"Recaudacion total del local por Meses"<<endl;
    cout<<"-------------------------------------"<<endl<<endl;
    Reparacion r;
    int i,anio,m,pos=0;
    float mes[12];
    for(i=0;i<12;i++)
    {
        mes[i]=0;
    }
    if(buscar_arch_registros()==-1) { cout<<"No hay ningun registro cargado"; return;}
    cout<<"Fecha: "<<endl;
    anio=anios();
    while(r.leer(pos)==1)
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
        pos++;
    }
    cout<<"Recaudacion del A"<<(char)164<<"o: "<<anio<<endl;
    for(i=0;i<12;i++)
    {
        cout<<"Mes "<<i+1<<": "<<mes[i]<<endl;
    }
}


void max_tecnicos()
{
    cout<<endl;
    cout<<"\t""\t""Los Mejores Tecnicos"<<endl;
    cout<<"\t""\t""--------------------"<<endl<<endl;
    int id[2],i,pos=0;
    float v[2],maxv[2];
    Tecnicos t;
    if(buscar_arch_registros()==-1) { cout<<"No hay ningun registro"; return;}
    for(i=0;i<2;i++)
    {
        id[i]=0;
        v[i]=0;
        maxv[i]=0;
    }
    while(t.leer(pos)==1)
    {
        if(t.getestado()==true)
        {
            v[0]=0; v[1]=0;
            Technic(t.getcod(),v);

            if(v[0]>maxv[0])
            {
                maxv[0]=v[0];
                id[0]=t.getcod();
            }
            if(v[1]>maxv[1])
            {
                maxv[1]=v[1];
                id[1]=t.getcod();
            }
        }
        pos++;
    }
    cout<<endl<<endl;
    cout<<"\t""El Tecnico con mas reparaciones es el "<<id[0]<<" con "<<maxv[0]<<" reparacion/es"<<endl;
    cout<<"\t""El Tecnico con la mayor recaudacion es el "<<id[1]<<" con $"<<maxv[1]<<" pesos";
}

#endif // FRESUMENES_H_INCLUDED
