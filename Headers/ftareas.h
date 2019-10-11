#ifndef FTAREAS_H_INCLUDED
#define FTAREAS_H_INCLUDED

#include "funciones.h"

void agregar_tareas()
{
    cout<<endl<<"Agregar Tareas"<<endl;
    cout<<"--------------"<<endl<<endl;
    int cod;
    Tareas t;
    cout<<"Codigo de Tarea: ";
    cod=autocod_tarea();
    cout<<cod<<endl;
    t.setcod_tarea(cod);
    t.cargar();
    t.grabar();
    cout<<"Tarea agregada con exito!";
}

void modificar_tareas()
{
    cout<<endl<<"Modificar Tareas"<<endl;
    cout<<"----------------"<<endl<<endl;
    int cod,pos,band=0;
    Tareas t;char n[10];
    if(buscar_arch_tareas()==-1) {cout<<"No hay ninguna tarea cargada"; return; }
    while(band==0)
    {
    cout<<"Codigo de Tarea: ";
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
    pos=posicion_tareas(cod);
    if(pos==-1) {cout<<"No existe ese Codigo"; return; }
    t.leer(pos);
    t.cargar2();
    t.modificar(pos);
    cout<<"Tarea modificada con exito";
}


void listar_tareas()
{
    cout<<endl<<"Lustar Tareas"<<endl;
    cout<<"-------------"<<endl<<endl;
    Tareas t;
    int band=0,pos=0;
    if(buscar_arch_tareas()==-1) {cout<<"No hay ninguna tarea cargada"; return; }
    while(t.leer(pos)==1)
    {
        if(t.getestado()==true)
        {
            band=1;
            system("pause>nul");
            t.mostrar();
            cout<<endl;
        }
        pos++;
    }
    if(band==0) { cout<<"No hay ningun equipo cargado"; }
}

#endif // FTAREAS_H_INCLUDED
