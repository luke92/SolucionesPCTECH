#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
///--------BUSCAR ARCHIVOS----------------------
int buscar_arch_clientes();
int buscar_arch_tareas();
int buscar_arch_tecnicos();

int buscar_archivos()
{
    int ret=0;
    if(buscar_arch_clientes()==-1) {cout<<"No hay ningun Cliente cargado"<<endl;ret=1;}
    if(buscar_arch_tecnicos()==-1) {cout<<"No hay ningun Tecnico cargado"<<endl;ret=1;}
    if(buscar_arch_tareas()==-1) {cout<<"No hay ninguna Tarea cargada"<<endl; ret=1;}
    if(ret==1)
    {
        return ret;
    }
    return ret;
}

//////////////////////////////////////////////////////
int buscar_arch_clientes()
{
    FILE *p;
    p=fopen("datos//clientes.dat","rb");
    if(p==NULL)
    {
        return -1;
    }
    fclose(p);
    return 1;
}

///////////////////////////////////////////////////////

int buscar_arch_registros()
{
    FILE *p;
    p=fopen("datos//registros.dat","rb");
    if(p==NULL)
    {
        return -1;
    }
    fclose(p);
    return 1;
}

//////////////////////////////////////////////////////

int buscar_arch_tareas()
{
    FILE *p;
    p=fopen("datos//tareas.dat","rb");
    if(p==NULL)
    {
        return -1;
    }
    fclose(p);
    return 1;
}

/////////////////////////////////////////////////////

int buscar_arch_tecnicos()
{
    FILE *p;
    p=fopen("datos//tecnicos.dat","rb");
    if(p==NULL)
    {
        return -1;
    }
    fclose(p);
    return 1;
}

///////////////////////////////////////////////////////

int buscar_arch_det_reparacion()
{
    FILE *p;
    p=fopen("datos//detrep","rb");
    if(p==NULL)
    {
        return -1;
    }
    fclose(p);
    return 1;
}

///--------DETALLES REPARACION-----------------------------

float importe_tarea(int x)
{
    float imp=0;
    Tareas t;
    int pos=0;
    while(t.leer(pos)==1)
    {
        if(x==t.getcod_tarea())
        {
            imp=t.getimporte();
            return imp;
        }
        pos++;
    }
    return -1;
}

void borrar_detalles(int x)
{
    Detrep d;
    int pos=0;
    while(d.leer(pos)==1)
    {
        if(x==d.getcod_rep())
        {
            d.setestado(-1);
            d.modificar(pos);
        }
        pos++;
    }
}

////////////////////////////////////////////////////////

int cantlineas(int x)
{
    Detrep d;
    int pos=0,cont=0;
    while(d.leer(pos)==1)
    {
        if(x==d.getcod_rep())
        {
            cont++;
        }
        pos++;
    }
    return cont;
}

/////////////////////////////////////////////////////

float devolver_importes(int x)
{
    Detrep d;
    int pos=0;
    float acum=0;
    while(d.leer(pos)==1)
    {
        if(x==d.getcod_rep())
        {
            if(d.getestado()==true) {acum+=d.getimporte();}
        }
        pos++;
    }
    return acum;
}
//////////////////////////////////////////////////////

void mostrar_detalles(int cod)
{
    int pos1=0,pos2=0;
    Detrep d;
    Tareas t;
    while(d.leer(pos1)==1)
    {
        if((cod==d.getcod_rep()) && (d.getestado()==true))
        {
            pos2=0;
            while(t.leer(pos2)==1)
            {
                if(d.getcod_tarea()==t.getcod_tarea())
                {
                    cout<<t.getdescripcion()<<" . ";
                }
                pos2++;
            }
        }
        pos1++;
    }
}

//////////////////////////////////////////////////////////

void modificar_detrep(int cod,int cont, int tarea, float imp)
{
    int pos=0;
    Detrep d;
    while(d.leer(pos)==1)
    {
        if(cod==d.getcod_rep())
        {
            if(cont==d.getnum_linea())
            {
                d.setcod_rep(cod);
                d.setnumlinea(cont);
                d.setcod_tarea(tarea);
                d.setimporte(imp);
                d.setestado(1);
                d.modificar(pos);
                return;
            }
        }
        pos++;
    }
}

///-------BUSCAR POSICIONES Y CODIGOS-------------------------------------

int posicion_tecnico(int x)
{
    Tecnicos t;
    int cont=0;
    while(t.leer(cont)==1)
    {
        if(x==t.getcod())
        {
            return cont;
        }
        cont++;
    }
    return -1;
}

///---------------------------------------

int posicion_cliente(int x)
{
    Clientes c;
    int cont=0;
    while(c.leer(cont)==1)
    {
        if(x==c.getcod())
        {
            return cont;
        }
        cont++;
    }
    return -1;
}

///---------------------------------------

int posicion_reparacion(int x)
{
    Reparacion r;
    int cont=0;
    while(r.leer(cont)==1)
    {
        if(x==r.getcod_rep())
        {
            return cont;
        }
        cont++;
    }
    return -1;
}

///---------------------------------------

int posicion_tareas(int x)
{
    Tareas t;
    int cont=0;
    while(t.leer(cont)==1)
    {
        if(x==t.getcod_tarea())
        {
            return cont;
        }
        cont++;
    }
    return -1;
}

///---------------------------------------

int posicion_detrep(int x,int j)
{
    Detrep d;
    int cont=0;
    while(d.leer(cont)==1)
    {
        if(x==d.getcod_rep())
        {
            if(j==d.getnum_linea()) { return cont;}
        }
        cont++;
    }
    return -1;
}


///------------CODIGOS AUTONUMERICOS----------------------

int autocod_tarea()
{
    Tareas t;
    FILE *p;
    int cont=1;
    p=fopen("datos//tareas.dat","rb");
    if(p==NULL)
    {
        return cont;
    }
    fclose(p);
    while(t.leer(cont-1)==1)
    {
        cont++;
    }
    return cont;
}

///////////////////////////////////////////////

int autocod_rep()
{
    Reparacion r;
    FILE *p;
    int cont=1;
    p=fopen("datos//registros.dat","rb");
    if(p==NULL)
    {
        return cont;
    }
    fclose(p);
    while(r.leer(cont-1)==1)
    {
        cont++;
    }
    return cont;
}

///////////////////////////////////////////////////

int autocod_cliente()
{
    Clientes c;
    FILE *p;
    int cont=1;
    p=fopen("datos//clientes.dat","rb");
    if(p==NULL)
    {
        return cont;
    }
    fclose(p);
    while(c.leer(cont-1)==1)
    {
        cont++;
    }
    return cont;
}

////////////////////////////////////////////////////

int autocod_tecnico()
{
    Tecnicos t;
    FILE *p;
    int cont=1;
    p=fopen("datos//tecnicos.dat","rb");
    if(p==NULL)
    {
        return cont;
    }
    fclose(p);
    while(t.leer(cont-1)==1)
    {
        cont++;
    }
    return cont;
}

///-------------------------------------------------------///

void Technic(int x,float *v)
{
    Reparacion r;
    int pos=0;
    while(r.leer(pos)==1)
    {
        if(x==r.getcod_tecnico())
        {
            if((r.getanio_e()>0) && (r.getreparado()==true) && (r.getestado()==true))
            {
                v[0]+=1;
                v[1]+=r.getimporte();
            }
        }
        pos++;
    }
}

int opcion()
{
    char opc;
    while(1)
    {
        opc=getch();
        if(opc=='n' || opc=='N')
        {
            cout<<opc<<endl;
            return -1;
        }
        if(opc=='s' || opc=='S')
        {
            cout<<opc<<endl;
            return 1;
        }
    }
}

char *getmayusculas(char *cadena)
{
    int cant=0,letra;
    cant=strlen(cadena);
    for(int i=0;i<cant;i++)
    {
        letra=cadena[i];
        if((letra>= 97) && (letra<= 122))
        {
            cadena[i]=letra-32;
        }
        else
        {
            if(cadena[i]==(char)164) { cadena[i]=letra+1;}
        }
    }
    return cadena;
}

char *letra_capital(char *cadena)
{
    int cant=0,letra;
    cant=strlen(cadena);
    for(int i=0;i<cant;i++)
    {
        if(i==0)
        {
            letra=cadena[i];
            if((letra>= 97) && (letra<= 122))
            {
                cadena[i]=letra-32;
            }
            else
            {
                if(cadena[i]==(char)164) { cadena[i]=letra+1;}
            }
        }
        else
        {
            letra=cadena[i];
            if((letra>= 65) && (letra<= 90))
            {
                cadena[i]=letra+32;
            }
            else
            {
                if(cadena[i]==(char)165) { cadena[i]=letra-1;}
            }
        }
    }
    return cadena;
}


#endif // FUNCIONES_H_INCLUDED
