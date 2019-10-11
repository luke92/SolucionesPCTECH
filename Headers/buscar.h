#ifndef BUSCAR_H_INCLUDED
#define BUSCAR_H_INCLUDED
void buscar_codcliente()
{
    cout<<endl;
    cout<<"Buscar Cliente por Codigo de Cliente"<<endl;
    cout<<"------------------------------------"<<endl<<endl;
    int cod,band=0,pos;
    Clientes c;
    char n[10];
    cout<<"Codigo de Cliente: ";
    while(band==0)
    {
        cin>>n;
        if(validar_cadenai(n)==-1) { cout<<"No es un numero!"<<endl; }
        else { band=1; }
    }
    cod=validacioni(n);
    pos=posicion_cliente(cod);
    if(pos==-1) { cout<<"Ese codigo de cliente no existe"; return;}
    c.leer(pos);
    c.mostrar();
    cout<<"Estado: ";
    if(c.getestado()==true) {cout<<"Activo";}
    if(c.getestado()==false) {cout<<"Borrado";}
}

void buscar_nombre()
{
    cout<<endl;
    cout<<"Buscar Cliente por Nombre"<<endl;
    cout<<"-------------------------"<<endl<<endl;
    int band=0,pos=0;
    Clientes c;
    char n[30];
    cout<<"Nombre: ";
    cin.sync();
    cin.getline(n,30);
    strcpy(n,getmayusculas(n));
    while(c.leer(pos)==1)
    {
        if(strcmp(getmayusculas(c.getnombre()),n)==0)
        {
            cout<<endl<<endl;
            band=1;
            c.mostrar();
            cout<<"Estado: ";
            if(c.getestado()==true) {cout<<"Activo";}
            if(c.getestado()==false) {cout<<"Borrado";}

        }
        pos++;
    }
    if(band==0) { cout<<"No hay ningun Cliente con ese Nombre";}
}

void buscar_apellido()
{
    cout<<endl;
    cout<<"Buscar Cliente por Apellido"<<endl;
    cout<<"---------------------------"<<endl<<endl;
    int band=0,pos=0;
    Clientes c;
    char n[30];
    cout<<"Apellido: ";
    cin.sync();
    cin.getline(n,30);
    strcpy(n,getmayusculas(n));
    while(c.leer(pos)==1)
    {
        if(strcmp(getmayusculas(c.getapellido()),n)==0)
        {
            cout<<endl<<endl;
            band=1;
            c.mostrar();
            cout<<"Estado: ";
            if(c.getestado()==true) {cout<<"Activo";}
            if(c.getestado()==false) {cout<<"Borrado";}

        }
        pos++;
    }
    if(band==0) { cout<<"No hay ningun Cliente con ese Apellido";}
}

void buscar_telefono()
{
    cout<<endl;
    cout<<"Buscar Cliente por Telefono"<<endl;
    cout<<"---------------------------"<<endl<<endl;
    int band=0,pos=0;
    Clientes c;
    char n[15];
    cout<<"Telefono: ";
    cin>>n;
    while(c.leer(pos)==1)
    {
        if(strcmp(c.gettelefono(),n)==0)
        {
            cout<<endl<<endl;
            band=1;
            c.mostrar();
            cout<<"Estado: ";
            if(c.getestado()==true) {cout<<"Activo";}
            if(c.getestado()==false) {cout<<"Borrado";}

        }
        pos++;
    }
    if(band==0) { cout<<"No hay ningun Cliente con ese Telefono";}
}

void buscar_localidad()
{
    cout<<endl;
    cout<<"Buscar Cliente por Localidad"<<endl;
    cout<<"----------------------------"<<endl<<endl;
    int band=0,pos=0;
    Clientes c;
    char n[30];
    cout<<"Localidad: ";
    cin.sync();
    cin.getline(n,30);
    strcpy(n,getmayusculas(n));
    while(c.leer(pos)==1)
    {
        if(strcmp(getmayusculas(c.getlocalidad()),n)==0)
        {
            cout<<endl<<endl;
            band=1;
            c.mostrar();
            cout<<"Estado: ";
            if(c.getestado()==true) {cout<<"Activo";}
            if(c.getestado()==false) {cout<<"Borrado";}

        }
        pos++;
    }
    if(band==0) { cout<<"No hay ningun Cliente con esa Localidad";}
}

void buscar_direccion()
{
    cout<<endl;
    cout<<"Buscar Cliente por Direccion"<<endl;
    cout<<"----------------------------"<<endl<<endl;
    int band=0,pos=0;
    Clientes c;
    char n[30],n2[10];
    cout<<"Calle: ";
    cin.sync();
    cin.getline(n,30);
    strcpy(n,getmayusculas(n));
    cout<<"Numero: ";
    cin>>n2;
    while(c.leer(pos)==1)
    {
        if(strcmp(getmayusculas(c.getnombre_calle()),n)==0)
        {
            if(strcmp(c.getnumero(),n2)==0)
            {
                cout<<endl<<endl;
                band=1;
                c.mostrar();
                cout<<"Estado: ";
                if(c.getestado()==true) {cout<<"Activo";}
                if(c.getestado()==false) {cout<<"Borrado";}

            }
        }
        pos++;
    }
    if(band==0) { cout<<"No hay ningun Cliente con esa Direccion";}
}

void buscar_codpostal()
{
    cout<<endl;
    cout<<"Buscar Cliente por Codigo Postal"<<endl;
    cout<<"--------------------------------"<<endl<<endl;
    int band=0,pos=0;
    Clientes c;
    char n[100];
    cout<<"Nombre: ";
    cin>>n;
    while(c.leer(pos)==1)
    {
        if(strcmp(c.getCodPostal(),n)==0)
        {
            cout<<endl<<endl;
            band=1;
            c.mostrar();
            cout<<"Estado: ";
            if(c.getestado()==true) {cout<<"Activo";}
            if(c.getestado()==false) {cout<<"Borrado";}
        }
        pos++;
    }
    if(band==0) { cout<<"No hay ningun Cliente con ese Nombre";}
}
#endif // BUSCAR_H_INCLUDED
