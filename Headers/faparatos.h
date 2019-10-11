#ifndef FAPARATOS_H_INCLUDED
#define FAPARATOS_H_INCLUDED

#include "funciones.h"


void agregar_pc()
{
    cout<<endl<<"Agregar PC"<<endl;
    cout<<"----------"<<endl<<endl;
    Reparacion r;
    Detrep d;
    int cont=0,band=0,pos=0;
    float impt=0;
    if(buscar_archivos()==1) return;
    if(r.cargar()==-1) { return; }
    r.grabar();
    band=1;
    while(band==1)
    {
        if(d.cargar(r.getcod_rep(),cont)==1) { d.grabar(); cont++; }
        cout<<"Agregar otra Tarea? (S/N): ";
        band=opcion();
    }
    pos=posicion_reparacion(r.getcod_rep());
    r.leer(pos);
    impt=devolver_importes(r.getcod_rep());
    r.setimporte(impt);
    r.modificar(pos);
    cout<<"Equipo Agregado con exito!";
}

void modificar_pc()
{
    cout<<endl<<"Modificar PC"<<endl;
    cout<<"------------"<<endl<<endl;
    char n[10];
    Reparacion r;
    Detrep d;
    int cod,cont=0,band=0,band1=0,ret=0,pos,pos2;
    float impt=0;
    char opc;
    if(buscar_archivos()==1) {ret=1;}
    if(buscar_arch_registros()==-1) {cout<<"No hay ningun Registro"<<endl; ret=1;}
    if(ret==1) {return;}
    while(band==0)
    {
        cout<<"Codigo de Reparacion: ";
        cin>>n;
        if(validar_cadenai(n)==-1) { cout<<"No es un numero!"<<endl;}
        else { band=1;}
    }
    cod=validacioni(n);
    pos=posicion_reparacion(cod);
    if(pos==-1) { cout<<"No existe ese codigo"; return;}
    r.leer(pos);
    if(r.getreparado()==true) { cout<<"Este equipo ya esta reparado, por lo tanto no se puede modificar"; return;}
    if(r.cargar2()==-1) { return; };
    r.modificar(pos);
    cout<<"Tarea/s: "; mostrar_detalles(cod); cout<<endl;
    cout<<"Desea modificar la/s Tarea/s (S/N)? ";
    band=0;
    while(band==0)
    {
        opc=getch();
        if((opc=='s') || (opc=='S') || (opc=='n') || (opc=='N'))
        {
            cout<<opc<<endl;
            band=1;
        }
    }
    if((opc=='s') || (opc=='S'))
    {
        borrar_detalles(cod);
        while(band1==0)
        {
            if(d.cargar(cod,cont)==1)
            {
                pos2=posicion_detrep(cod,cont);
                if(pos2==-1)
                {
                    d.grabar();
                }
                else
                {
                    d.modificar(pos2);
                }
                cont++;
            }
            band=0;
            cout<<"Agregar otra Tarea? (S/N): ";
            opc=getch();
            while(band==0)
            {
                if(opc=='n' || opc=='N')
                {
                    cout<<opc<<endl;
                    band=1;
                    band1=1;
                }
                if(opc=='s' || opc=='S')
                {
                    cout<<opc<<endl;
                    band=1;
                }
            }
        }
    }
    impt=devolver_importes(cod);
    r.setimporte(impt);
    r.modificar(pos);
    cout<<"Equipo modificado con exito!";
}


void listar_pc()
{
    cout<<endl<<"Listar PC"<<endl;
    cout<<"---------"<<endl<<endl;
    Reparacion r;
    int cod,pos=0;
    int band=0;
    if(buscar_arch_registros()==-1) {cout<<"No hay ningun equipo cargado"; return;}
    while(r.leer(pos)==1)
    {
        if(r.getestado()==true)
        {
            band=1;
            system("pause>nul");
            r.mostrar();
            cod=r.getcod_rep();
            cout<<"Tareas: ";
            mostrar_detalles(cod);
            cout<<endl<<endl;
        }
        pos++;
    }
    if(band==0) { cout<<"No hay ningun equipo cargado"; }
}

void listar_pc_x_fecha()
{
    cout<<endl<<"Listar PC x Fecha"<<endl;
    cout<<"-----------------"<<endl<<endl;
    Reparacion r;
    int cod,diai,mesi,anioi,diaf,mesf,aniof,inicio=0,fin=0,tdias=0,band=0,pos=0;
    if(buscar_arch_registros()==-1) {cout<<"No hay ningun equipo cargado"; return;}
    cout<<"Fecha de Ingreso de el/los aparato/s: "<<endl;
    while(band==0)
    {
    cout<<"Fecha de Inicio: "<<endl;
    diai=dias();
    mesi=meses();
    anioi=anios();
    cout<<"Fecha de Fin: "<<endl;
    diaf=dias();
    mesf=meses();
    aniof=anios();
    inicio=((anioi*365)+(mesi*30)+diai);
    fin=((aniof*365)+(mesf*30)+diaf);
    cout<<endl<<endl;
    if(inicio>fin)
    {
        cout<<"La fecha de inicio no puede ser mayor a la de fin";
        cout<<endl<<"Vuelva a ingresar las fechas ";
        system("pause>nul"); cout<<endl;
    }
    else
    {
        band=1;
    }
    }
    band=0;
    while(r.leer(pos)==1)
    {
        tdias=((r.getanio()*365)+(r.getmes()*30)+r.getdia());
        if((inicio<=tdias) && (tdias<=fin))
        {
            if(r.getestado()==true)
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
    if(band==0) { cout<<"No hay ningun equipo cargado o dentro de esas fechas"; }
}

void borrar_pc()
{
    cout<<endl<<"Borrar PC"<<endl;
    cout<<"---------"<<endl<<endl;
    Reparacion r;
    int cod,pos,band=0;char n[10];
    if(buscar_arch_registros()==-1) {cout<<"No hay ningun equipo cargado"; return;}
    while(band==0)
    {
        cout<<"Codigo de Reparacion: ";
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
    pos=posicion_reparacion(cod);
    if(pos==-1) { cout<<"No existe ese Codigo"; return;}
    r.leer(pos);
    if(r.getestado()==true)
    {
        cout<<"Advertencia!! Esta seguro de borrar este codigo? (S/N)? ";
        if(opcion()==1)
        {
            r.setestado(-1);
            r.modificar(pos);
            cout<<"Equipo borrado con exito!";
        }
    }
    else
    {
        cout<<"Ese equipo ya estaba borrado!";
    }
}

void alta_pc()
{
    cout<<endl<<"Restaurar PC"<<endl;
    cout<<"------------"<<endl<<endl;
    Reparacion r;
    int cod,pos,band=0;char n[10];
    if(buscar_arch_registros()==-1) {cout<<"No hay ningun equipo cargado"; return;}
    while(band==0)
    {
        cout<<"Codigo de Reparacion: ";
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
    pos=posicion_reparacion(cod);
    if(pos==-1) { cout<<"No existe ese Codigo"; return;}
    r.leer(pos);
    if(r.getestado()==false)
    {
        r.setestado(1);
        r.modificar(pos);
        cout<<"Equipo restaurado con exito!";
    }
    else
    {
        cout<<"Ese equipo ya esta activo!";
    }
}

void reparado_pc()
{
    cout<<endl<<"Reparar PC"<<endl;
    cout<<"----------"<<endl<<endl;
    Reparacion r;
    int cod,pos,band=0;char n[10];
    if(buscar_arch_registros()==-1) {cout<<"No hay ningun equipo cargado"; return;}
    while(band==0)
    {
        cout<<"Codigo de Reparacion: ";
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
    pos=posicion_reparacion(cod);
    if(pos==-1) { cout<<"No existe ese Codigo"; return;}
    r.leer(pos);
    if(r.getestado()==true)
    {
        if(r.getreparado()==false)
        {
        r.setreparar(1);
        r.modificar(pos);
        cout<<"Equipo reparado con exito!";
        }
        else
        {
            cout<<"Ese equipo ya estaba reparado!";
        }
    }
    else
    {
        cout<<"No existe ese Codigo";
    }
}


void entregar_pc()
{
    cout<<endl<<"Entregar PC"<<endl;
    cout<<"-----------"<<endl<<endl;
    Reparacion r;
    int cod,pos,band=0;
    char n[10];
    if(buscar_arch_registros()==-1) {cout<<"No hay ningun equipo cargado";return;}
    while(band==0)
    {
        cout<<"Codigo de Reparacion: ";
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
    pos=posicion_reparacion(cod);
    if(pos==-1) { cout<<"No existe ese Codigo"; return;}
    r.leer(pos);
    if(r.getestado()==true)
    {
        if(r.getanio_e()!=0) { cout<<"Ya ha sido entregado este equipo!"; return;}
        r.setfecha_egreso();
        r.modificar(pos);
        cout<<"Se ha entregado el equipo con exito!";
    }
    else
    {
        cout<<"No existe ese Codigo";
    }
}
#endif // FAPARATOS_H_INCLUDED
