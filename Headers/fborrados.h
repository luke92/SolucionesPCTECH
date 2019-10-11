#ifndef FBORRADOS_H_INCLUDED
#define FBORRADOS_H_INCLUDED

void listar_pc_borradas()
{
    cout<<endl<<"Listar PC Borradas"<<endl;
    cout<<"------------------"<<endl<<endl;
    Reparacion r;
    int cod,pos=0;
    int band=0;
    if(buscar_arch_registros()==-1) {cout<< " No hay ningun Equipo cargado";return;}
    while(r.leer(pos)==1)
    {
        if(r.getestado()==false)
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
    if(band==0) { cout<<"No hay ningun equipo borrado"; }
}

void listar_clientes_borrados()
{
    cout<<endl<<"Listar Clientes Borrados"<<endl;
    cout<<"------------------------"<<endl<<endl;
    Clientes c;
    int band=0,pos=0;
    if(buscar_arch_clientes()==-1) {cout<<"No hay ningun Cliente cargado"; return; }
    while(c.leer(pos)==1)
    {
        if(c.getestado()==false)
        {
            band=1;
            system("pause>nul");
            c.mostrar();
            cout<<endl;
            cout<<endl;
        }
        pos++;
    }
    if(band==0) { cout<<"No hay ningun cliente borrado"; }
}

void listar_tecnicos_borrados()
{
    cout<<endl<<"Listar Tecnicos Borrados"<<endl;
    cout<<"------------------------"<<endl<<endl;
    Tecnicos c;
    int band=0,pos=0;
    if(buscar_arch_tecnicos()==-1) {cout<<"No hay ningun Tecnico cargado";return;}
    while(c.leer(pos)==1)
    {
        if(c.getestado()==false)
        {
            band=1;
            system("pause>nul");
            c.mostrar();
            cout<<endl;
            cout<<endl;
        }
        pos++;
    }
    if(band==0) { cout<<"No hay ningun tecnico borrado"; }
}

void listar_tareas_borradas()
{
    cout<<endl<<"Listar Tareas Borradas"<<endl;
    cout<<"----------------------"<<endl<<endl;
    Tareas t;
    int band=0,pos=0;
    if(buscar_arch_tareas()==-1) {cout<<"No hay ninguna tarea cargada"; return; }
    while(t.leer(pos)==1)
    {
        if(t.getestado()==false)
        {
            band=1;
            system("pause>nul");
            t.mostrar();
            cout<<endl;
            cout<<endl;
        }
        pos++;
    }
    if(band==0) { cout<<"No hay ninguna tarea borrada"; }
}

#endif // FBORRADOS_H_INCLUDED
