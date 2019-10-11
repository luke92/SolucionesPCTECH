#ifndef FECHAS_H_INCLUDED
#define FECHAS_H_INCLUDED

char *letra_capital(char *);

///-------------INGRESO DE DIA--------------------------
int dias()
{
    int band=0,band1=0,dias;
    char n[10];
    while(band1==0)
    {
        while(band==0)
        {
            cout<<"Dia (1 a 31):  ";
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
        band=0;
        dias=validacioni(n);
        if(dias<1 || dias>31)
        {
            cout<<"Dia ingresado erroneo, vuelva a ingresar el dia ";
            system("pause>null");
            cout<<endl;
        }
        else
        {
            band1=1;
        }
    }
    return dias;
}

///----------------INGRESO DE MES---------------------------

int meses()
{
    int band=0,band1=0,mes;
    char n[10];
    while(band1==0)
    {
        while(band==0)
        {
            cout<<"Mes (1 a 12):  ";
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
        band=0;
        mes=validacioni(n);
        if(mes<0 || mes>12)
        {
            cout<<"Mes ingresado erroneo, vuelva a ingresar el mes ";
            system("pause>null");
            cout<<endl;
        }
        else
        {
            band1=1;
        }
    }
    return mes;
}

///------------------------INGRESO DE ANIOS----------------------

int anios()
{
    int band=0,band1=0,anio;
    char n[10];
    while(band1==0)
    {
        while(band==0)
        {
            cout<<"A"<<(char)164<<"o (2000 a 2050):  ";
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
        band=0;
        anio=validacioni(n);
        if(anio<2000 || anio>2050)
        {
            cout<<"A"<<(char)164<<"o ingresado erroneo, vuelva a ingresar el A"<<(char)164<<"o ";
            system("pause>null");
            cout<<endl;
        }
        else
        {
            band1=1;
        }
    }
    return anio;
}

///-----------------INGRESO DE DIRECCION----------------------------

char * getcalle()
{
    char cadena[30];
    cout<<"Calle: ";
    cin.sync();
    cin.getline(cadena,30);
    letra_capital(cadena);
    return cadena;
}

char * getnumcalle()
{
    char cadena[10];
    cout<<"Numero: ";
    cin>>cadena;
    return cadena;
}

char * getpiso()
{
    char cadena[3];
    cout<<"Piso: ";
    cin>>cadena;
    return cadena;
}

char * getdepartamento()
{
    char cadena[3];
    cout<<"Departamento: ";
    cin>>cadena;
    return cadena;
}

char * getlocalidad()
{
    char cadena[30];
    cout<<"Localidad: ";
    cin.sync();
    cin.getline(cadena,30);
    letra_capital(cadena);
    return cadena;
}

char * getcodpostal()
{
    char cadena[10];
    cout<<"Codigo postal: ";
    cin>>cadena;
    return cadena;
}

#endif // FECHAS_H_INCLUDED
