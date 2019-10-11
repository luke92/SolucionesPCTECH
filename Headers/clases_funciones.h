#ifndef CLASES_FUNCIONES_H_INCLUDED
#define CLASES_FUNCIONES_H_INCLUDED

#include "char_int_float.h"
#include "Ingresos.h"
#include "funciones.h"


///--------------METODOS DE LAS CLASES-------------------------------

///--------------METODOS CLASE DIRECCION-----------------------------

void Direccion::cargar()
{
    strcpy(nombre_calle,getcalle());
    strcpy(numero,getnumcalle());
    strcpy(piso,getpiso());
    strcpy(depto,getdepartamento());
    strcpy(localidad,getlocalidad());
    strcpy(cod_postal,getcodpostal());
}

void Direccion::modificardir()
{
    int band=0;
    cout<<"Calle: "<<nombre_calle<<endl;
    cout<<"Desea cambiar la Calle? (S/N): ";
    while(band==0)
    {
        band=opcion();
        if(band==1)
        {
            cout<<"Calle: ";
            cin.sync();
            cin.getline(nombre_calle,30);
            strcpy(nombre_calle,letra_capital(nombre_calle));
        }
    }
    band=0;
    cout<<"Numero: "<<numero<<endl;
    cout<<"Desea cambiar el Numero? (S/N): ";
    while(band==0)
    {
        band=opcion();
        if(band==1)
        {
            cout<<"Numero: ";
            cin>>numero;
        }
    }
    band=0;
    cout<<"Piso: "<<piso<<endl;
    cout<<"Desea cambiar el Piso? (S/N): ";
    while(band==0)
    {
        band=opcion();
        if(band==1)
        {
            cout<<"Piso: ";
            cin>>piso;
        }
    }
    band=0;
    cout<<"Departamento: "<<depto<<endl;
    cout<<"Desea cambiar el Departamento? (S/N): ";
    while(band==0)
    {
        band=opcion();
        if(band==1)
        {
            cout<<"Departamento: ";
            cin>>depto;
        }
    }
    band=0;
    cout<<"Localidad: "<<localidad<<endl;
    cout<<"Desea cambiar la Localidad? (S/N): ";
    while(band==0)
    {
        band=opcion();
        if(band==1)
        {
            cout<<"Localidad: ";
            cin.sync();
            cin.getline(localidad,30);
            strcpy(localidad,letra_capital(localidad));
        }
    }
    cout<<"Codigo Postal: "<<cod_postal<<endl;
    cout<<"Desea cambiar el Cod. Postal? (S/N): ";
    band=0;
    while(band==0)
    {
        band=opcion();

        if(band==1)
        {
            cout<<"Codigo Postal: ";
            cin>>cod_postal;
        }
    }
}

istream& operator>>(istream &entrada,Direccion &obj)
 {
   entrada.ignore();
   cout<<"Ingrese la calle: ";
   entrada.getline(obj.nombre_calle,25);
   cout<<"Ingrese el numero: ";
   entrada>>obj.numero;
   cout<<"Ingrese el piso: ";
   entrada>>obj.piso;
   cout<<"Ingrese el departamento: ";
   entrada>>obj.depto;
   cout<<"Ingrese la localidad: ";
   entrada.ignore();
   entrada.getline(obj.localidad,30);
   cout<<"Ingrese el codigo postal: ";
   entrada>>obj.cod_postal;
   return entrada;
}

ostream & operator<<(ostream &salida ,Direccion &obj)
{
   cout<<"Calle: ";
   cout<<obj.nombre_calle<<endl;
   cout<<"Numero: ";
   salida<<obj.numero<<endl;
   cout<<"Piso: ";
   salida<<obj.piso<<endl;
   cout<<"Departamento: ";
   salida<<obj.depto<<endl;
   cout<<"Localidad: ";
   salida<<obj.localidad<<endl;
   cout<<"Codigo postal: ";
   salida<<obj.cod_postal<<endl;
   return salida;
}

///--------------METODOS CLASE TAREAS-----------------------------

void Tareas::cargar()
{
    int band=0;
    char n[10];
    cout<<"Descripcion: ";
    cin.sync();
    cin.getline(descripcion,30);
    strcpy(descripcion,letra_capital(descripcion));
    while(band==0)
    {
        cout<<"Importe: ";
        cin>>n;
        if(validar_cadenaf(n)==-1)
        {
            cout<<"No es un numero!"<<endl;
        }
        else
        {
            band=1;
        }
    }
    importe=validacionf(n);
    estado=true;
}

void Tareas::cargar2()
{
    int band=1;
    cout<<"Descripcion: "<<descripcion<<endl;
    cout<<"Desea cambiar la Descripcion? (S/N): ";
    band=0;
    while(band==0)
    {
        band=opcion();
        if(band==1)
        {
            cout<<"Descripcion: ";
            cin.sync();
            cin.getline(descripcion,30);
            strcpy(descripcion,letra_capital(descripcion));
        }
    }
    cout<<"Importe: "<<importe<<endl;
    cout<<"Desea cambiar el Importe? (S/N): ";
    band=0;
    while(band==0)
    {
        band=opcion();
        if(band==1)
        {
            cout<<"Importe: ";
            cin>>importe;
        }
    }
    estado=true;
}

void Tareas::mostrar()
{
    cout<<"Codigo Tarea: ";
    cout<<cod_tarea<<endl;
    cout<<"Descripcion: ";
    cout<<descripcion<<endl;
    cout<<"Importe: ";
    cout<<importe<<endl;
}

void Tareas::grabar()
{
    FILE *p;
    p=fopen("datos//tareas.dat","ab");
    if(p==NULL) {system("md datos"); p=fopen("datos/tareas.dat","ab");}
    fwrite(this,sizeof(*this),1,p);
    fclose(p);
}

void Tareas::modificar(int pos)
{
    FILE *p;
    p=fopen("datos//tareas.dat","rb+");
    fseek(p,sizeof(*this)*pos,0);
    fwrite(this,sizeof(*this),1,p);
    fclose(p);
}

int Tareas::leer(int pos)
{
    int leyo;
    FILE *p;
    p=fopen("datos//tareas.dat","rb");
    fseek(p,sizeof(*this)*pos,0);
    leyo=fread(this,sizeof(*this),1,p);
    fclose(p);
    return leyo;
}

///--------------METODOS CLASE REPARACION-----------------------------

int Reparacion::cargar()
{
    int band=0;
    char n[10];
    cod_rep=autocod_rep();
    cout<<"Codigo de Reparacion: "<<cod_rep<<endl;
    while(band==0)
    {
        cout<<"Codigo de Cliente: ";
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
    cod_cliente=validacioni(n);
    if(posicion_cliente(cod_cliente)==-1) {cout<<"No existe ese cliente"; return -1;}
    band=0;
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
    cod_tecnico=validacioni(n);
    if(posicion_tecnico(cod_tecnico)==-1) {cout<<"No existe ese Tecnico"; return -1;}
    setfecha_ingreso();
    setfe();
    estado=true;
    reparado=false;
    importe=0;
    return 1;
}

int Reparacion::cargar2()
{
    int band=0,band2=0;
    char n[10];
    cout<<"Codigo de Cliente: "<<cod_cliente<<endl;
    cout<<"Desea Cambiar el Codigo de Cliente (S/N)?: ";
    band=0;
    while(band==0)
    {
        band=opcion();

        if(band==1)
        {
            while(band2==0)
            {
                cout<<"Codigo de Cliente: ";
                cin>>n;
                if(validar_cadenai(n)==-1)
                {
                    cout<<"No es un numero!"<<endl;
                }
                else
                {
                    band2=1;
                }
            }
            cod_cliente=validacioni(n);
            if(posicion_cliente(cod_cliente)==-1) {cout<<"No existe ese cliente"; return -1;}
        }
    }
    band2=0;
    cout<<"Codigo de Tecnico: "<<cod_tecnico<<endl;
    cout<<"Desea Cambiar el Codigo de Tecnico (S/N)?: ";
    band=0;
    while(band==0)
    {
        band=opcion();

        if(band==1)
        {
            while(band2==0)
            {
                cout<<"Codigo de Tecnico: ";
                cin>>n;
                if(validar_cadenai(n)==-1)
                {
                    cout<<"No es un numero!"<<endl;
                }
                else
                {
                    band2=1;
                }
            }
            cod_tecnico=validacioni(n);
            if(posicion_tecnico(cod_tecnico)==-1) {cout<<"No existe ese tecnico"; return -1;}
        }
    }
    setfecha_ingreso2();
    return 1;
}

void Reparacion::mostrar()
{
    int x;
    Clientes c;
    Tecnicos t;
    cout<<"Codigo Reparacion: ";
    cout<<cod_rep<<endl;
    x=posicion_cliente(cod_cliente);
    c.leer(x);
    x=posicion_tecnico(cod_tecnico);
    t.leer(x);
    cout<<"Cliente: ";
    cout<<cod_cliente<<"  "<<c.getnombre()<<" "<<c.getapellido()<<endl;
    cout<<"Tecnico: ";
    cout<<cod_tecnico<<"  "<<t.getnombre()<<" "<<t.getapellido()<<endl;
    cout<<"Importe: ";
    cout<<importe<<endl;
    cout<<"Fecha de Ingreso: "<<dia<<"/"<<mes<<"/"<<anio<<endl;
    cout<<"Reparado: ";
    if(reparado==true)
    {
        cout<<"SI"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    cout<<"Entregado: ";
    if((dia_e!=0) && (mes_e!=0) && (anio_e!=0))
    {
        cout<<dia_e<<"/"<<mes_e<<"/"<<anio_e<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
}

void Reparacion::grabar()
{
    FILE *p;
    p=fopen("datos//registros.dat","ab");
    fwrite(this,sizeof(*this),1,p);
    fclose(p);
}

void Reparacion::modificar(int pos)
{
    FILE *p;
    p=fopen("datos//registros.dat","rb+");
    fseek(p,sizeof(*this)*pos,0);
    fwrite(this,sizeof(*this),1,p);
    fclose(p);
}

int Reparacion::leer(int pos)
{
    int leyo;
    FILE *p;
    p=fopen("datos//registros.dat","rb");
    fseek(p,sizeof(*this)*pos,0);
    leyo=fread(this,sizeof(*this),1,p);
    fclose(p);
    return leyo;
}

void Reparacion::setfecha_ingreso()
{
    time_t tiempo;
    struct tm *tmPtr;
    tiempo = time(NULL);
    tmPtr = localtime(&tiempo);
    anio=tmPtr->tm_year+1900;
    mes=tmPtr->tm_mon+1;
    dia=tmPtr->tm_mday;
}

void Reparacion::setfecha_ingreso2()
{
    int cantdias=0,cant=0,band=0,band1=0,anio_s,mes_s,dia_s;
    char opc;
    time_t tiempo;
    struct tm *tmPtr;
    tiempo = time(NULL);
    tmPtr = localtime(&tiempo);
    anio_s=tmPtr->tm_year+1900;
    mes_s=tmPtr->tm_mon+1;
    dia_s=tmPtr->tm_mday;
    cout<<"Fecha de Ingreso: "<<dia<<"/"<<mes<<"/"<<anio<<endl;
    cout<<"Desea cambiar la fecha de ingreso (S/N)? ";
    while(band==0)
    {
        opc=getch();
        if((opc=='s') || (opc=='S') || (opc=='n') || (opc=='N'))
        {
            cout<<opc<<endl;
            band=1;
        }
        if((opc=='s') || (opc=='S'))
        {
            while(band1==0)
            {
                cantdias=dia_s+mes_s*30+anio_s*365;
                dia=dias();
                mes=meses();
                anio=anios();
                cant=dia+mes*30+anio*365;
                if(cant<=cantdias)
                {
                    band1=1;
                }
                else
                {
                    cout<<"La fecha de ingreso no puede ser mayor a la del sistema!"<<endl;
                    cout<<"Por favor vuelva a ingresarla ";
                    system("pause>nul");
                    cout<<endl;
                }
            }
        }
    }
}

void Reparacion::setfecha_egreso()
{
    time_t tiempo;
    struct tm *tmPtr;
    tiempo = time(NULL);
    tmPtr = localtime(&tiempo);
    anio_e=tmPtr->tm_year+1900;
    mes_e=tmPtr->tm_mon+1;
    dia_e=tmPtr->tm_mday;
}

///--------------METODOS CLASE CLIENTES-----------------------------

void Clientes::cargar()
{
    cout<<"Nombre: ";
    cin.sync();
    cin.getline(nombre,30);
    strcpy(nombre,letra_capital(nombre));
    cout<<"Apellido: ";
    cin.sync();
    cin.getline(apellido,30);
    strcpy(apellido,letra_capital(apellido));
    cout<<"Telefono: ";
    cin.sync();
    cin.getline(telefono,15);
    dir.cargar();
    estado=true;
}


void Clientes::cargar2()
{
    int band=1;
    cout<<"Nombre: "<<nombre<<endl;
    cout<<"Desea cambiar el Nombre? (S/N): ";
    band=0;
    while(band==0)
    {
        band=opcion();

        if(band==1)
        {
            cout<<"Nombre: ";
            cin.sync();
            cin.getline(nombre,30);
            strcpy(nombre,letra_capital(nombre));
        }
    }
    cout<<"Apellido: "<<apellido<<endl;
    cout<<"Desea cambiar el Apellido? (S/N): ";
    band=0;
    while(band==0)
    {
        band=opcion();

        if(band==1)
        {
            cout<<"Apellido: ";
            cin.sync();
            cin.getline(apellido,30);
            strcpy(apellido,letra_capital(apellido));
        }
    }
    cout<<"Telefono: "<<telefono<<endl;
    cout<<"Desea cambiar el Telefono? (S/N): ";
    band=0;
    while(band==0)
    {
        band=opcion();

        if(band==1)
        {
            cout<<"Telefono: ";
            cin.sync();
            cin.getline(telefono,15);
        }
    }
    dir.modificardir();
    estado=true;
}


void Clientes::mostrar()
{
    cout<<"Codigo Cliente: ";
    cout<<cod<<endl;
    cout<<"Nombre: ";
    cout<<nombre<<endl;
    cout<<"Apellido: ";
    cout<<apellido<<endl;
    cout<<"Telefono: ";
    cout<<telefono<<endl;
    cout<<dir;
}

void Clientes::grabar()
{
    FILE *p;
    p=fopen("datos//clientes.dat","ab");
    if(p==NULL) {system("md datos"); p=fopen("datos/clientes.dat","ab");}
    fwrite(this,sizeof(*this),1,p);
    fclose(p);
}

void Clientes::modificar(int pos)
{
    FILE *p;
    p=fopen("datos//clientes.dat","rb+");
    fseek(p,sizeof(*this)*pos,0);
    fwrite(this,sizeof(*this),1,p);
    fclose(p);
}

int Clientes::leer(int pos)
{
    int leyo;
    FILE *p;
    p=fopen("datos//clientes.dat","rb");
    fseek(p,sizeof(*this)*pos,0);
    leyo=fread(this,sizeof(*this),1,p);
    fclose(p);
    return leyo;
}



///--------------METODOS CLASE TECNICOS-----------------------------

void Tecnicos::cargar()
{
    int band=0,cantdias=0,cant=0,anio_s,mes_s,dia_s;
    time_t tiempo;
    struct tm *tmPtr;
    tiempo = time(NULL);
    tmPtr = localtime(&tiempo);
    anio_s=tmPtr->tm_year+1900;
    mes_s=tmPtr->tm_mon+1;
    dia_s=tmPtr->tm_mday;
    cout<<"Nombre: ";
    cin.sync();
    cin.getline(nombre,30);
    strcpy(nombre,letra_capital(nombre));
    cout<<"Apellido: ";
    cin.sync();
    cin.getline(apellido,30);
    strcpy(apellido,letra_capital(apellido));
    cout<<"Telefono: ";
    cin.sync();
    cin.getline(telefono,15);
    cout<<"Fecha de Ingreso: "<<endl;
    cantdias=dia_s+mes_s*30+anio_s*365;
    while(band==0)
    {
        dia=dias();
        mes=meses();
        anio=anios();
        cant=dia+mes*30+anio*365;
        if(cant<=cantdias)
        {
            band=1;
        }
        else
        {
            cout<<"La fecha de ingreso del tecnico no puede ser mayor a la del sistema!"<<endl;
            cout<<"Vuelva a ingresar la fecha ";
            system("pause>nul");
            cout<<endl;
        }
    }
    dir.cargar();
    estado=true;
}


void Tecnicos::cargar2()
{
    int band=1,band1=0;
    int cantdias=0,cant=0,anio_s,mes_s,dia_s;
    time_t tiempo;
    struct tm *tmPtr;
    tiempo = time(NULL);
    tmPtr = localtime(&tiempo);
    anio_s=tmPtr->tm_year+1900;
    mes_s=tmPtr->tm_mon+1;
    dia_s=tmPtr->tm_mday;
    cout<<"Nombre: "<<nombre<<endl;
    cout<<"Desea cambiar el Nombre? (S/N): ";
    band=0;
    while(band==0)
    {
        band=opcion();

        if(band==1)
        {
            cout<<"Nombre: ";
            cin.sync();
            cin.getline(nombre,30);
            strcpy(nombre,letra_capital(nombre));
        }
    }
    cout<<"Apellido: "<<apellido<<endl;
    cout<<"Desea cambiar el Apellido? (S/N): ";
    band=0;
    while(band==0)
    {
        band=opcion();
        if(band==1)
        {
            cout<<"Apellido: ";
            cin.sync();
            cin.getline(apellido,30);
            strcpy(apellido,letra_capital(apellido));
        }
    }
    cout<<"Telefono: "<<telefono<<endl;
    cout<<"Desea cambiar el Telefono? (S/N): ";
    band=0;
    while(band==0)
    {
        band=opcion();

        if(band==1)
        {
            cout<<"Telefono: ";
            cin.sync();
            cin.getline(telefono,15);
        }
    }
    cout<<"Fecha de Ingreso: "<<dia<<"/"<<mes<<"/"<<anio<<endl;
    cout<<"Desea cambiar la Fecha? (S/N): ";
    band=0;
    while(band==0)
    {
        band=opcion();
        if(band==1)
        {
            cantdias=dia_s+mes_s*30+anio_s*365;
            while(band1==0)
            {
                dia=dias();
                mes=meses();
                anio=anios();
                cant=dia+mes*30+anio*365;
                if(cant<=cantdias)
                {
                    band1=1;
                }
                else
                {
                    cout<<"La fecha de ingreso del tecnico no puede ser mayor a la del sistema!"<<endl;
                    cout<<"Vuelva a ingresar la fecha ";
                    system("pause>nul");
                    cout<<endl;
                }
            }
        }
    }
    dir.modificardir();
    estado=true;
}


void Tecnicos::mostrar()
{
    cout<<"Codigo Tecnico: ";
    cout<<cod<<endl;
    cout<<"Nombre: ";
    cout<<nombre<<endl;
    cout<<"Apellido: ";
    cout<<apellido<<endl;
    cout<<"Telefono: ";
    cout<<telefono<<endl;
    cout<<"Fecha de Ingreso: "<<dia<<"/"<<mes<<"/"<<anio<<endl;
    cout<<dir;
}

void Tecnicos::grabar()
{
    FILE *p;
    p=fopen("datos//tecnicos.dat","ab");
    if(p==NULL) {system("md datos"); p=fopen("datos/tecnicos.dat","ab");}
    fwrite(this,sizeof(*this),1,p);
    fclose(p);
}


void Tecnicos::modificar(int pos)
{
    FILE *p;
    p=fopen("datos//tecnicos.dat","rb+");
    fseek(p,sizeof(*this)*pos,0);
    fwrite(this,sizeof(*this),1,p);
    fclose(p);
}

int Tecnicos::leer(int pos)
{
    int leyo;
    FILE *p;
    p=fopen("datos//tecnicos.dat","rb");
    fseek(p,sizeof(*this)*pos,0);
    leyo=fread(this,sizeof(*this),1,p);
    fclose(p);
    return leyo;
}

///--------------METODOS CLASE DETALLE REPARACION-----------------------------

int Detrep::cargar(int cod,int cont)
{
    int band=0;
    char n[10];
    while(band==0)
    {
    cout<<"Tarea : ";
    cin>>n;
    if(validar_cadenai(n)==-1) { cout<<"No es un numero!"<<endl; }
    else { band=1; }
    }
    cod_tarea=validacioni(n);
    if(posicion_tareas(cod_tarea)==-1) { cout<<"No existe ese Codigo"<<endl; return -1;}
    importe=importe_tarea(cod_tarea);
    cod_rep=cod;
    num_linea=cont;
    estado=true;
    return 1;
}

void Detrep::grabar()
{
    FILE *p;
    p=fopen("datos//detrep.dat","ab");
    fwrite(this,sizeof(*this),1,p);
    fclose(p);
}

void Detrep::modificar(int pos)
{
    FILE *p;
    p=fopen("datos//detrep.dat","rb+");
    fseek(p,sizeof(*this)*pos,0);
    fwrite(this,sizeof(*this),1,p);
    fclose(p);
}

int Detrep::leer(int pos)
{
    int leyo;
    FILE *p;
    p=fopen("datos//detrep.dat","rb");
    fseek(p,sizeof(*this)*pos,0);
    leyo=fread(this,sizeof(*this),1,p);
    fclose(p);
    return leyo;
}

#endif // CLASES_FUNCIONES_H_INCLUDED
