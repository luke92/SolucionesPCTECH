#ifndef CERRAR_H_INCLUDED
#define CERRAR_H_INCLUDED
void licencia_incorrecta();

void cerrar()
{
    cout<<endl<<endl<<endl;
    cout<<"\t""\t""\t""Gracias por Usar Soluciones PC-TECH!!"<<endl;
    cout<<"\t""\t""\t""-------------------------------"<<endl<<endl<<endl;
    cout<<"\t""\t""\t""Version 1.6 --> 8/12/2010"<<endl<<endl;
    cout<<"\t""\t""\t""Programa Hecho por Luke92"<<endl;
    cout<<"\t""\t""\t""Para la Materia Laboratorio II"<<endl;
    cout<<"\t""\t""\t""Del Profesor Daniel Kloster"<<endl;
    cout<<"\t""\t""\t""De la Universidad Tecnologica Nacional"<<endl;
    cout<<"\t""\t""\t""Facultad Regional General Pacheco"<<endl<<endl<<endl<<endl;
    cout<<"\t""\t""\t""Contacto: lucasjv92@gmail.com"<<endl;
    cout<<"\t""\t""\t""---------"<<endl<<endl;
    cout<<"\t""\t""\t""Legajo: 15510"<<endl;
    cout<<"\t""\t""\t""Nombre y Apellido: Lucas Vargas ";

    system("pause>null");
    exit(1);
}

int buscar_arch_licencia()
{
    FILE *p;
    p=fopen("licencia.dat","rb");
    if(p==NULL)
    {
        cout<<"Debe Registrar el programa para usarlo... "<<endl;
        system("pause>nul");
        cout<<endl<<endl<<endl;
        return -1;
    }
    fclose(p);
    return 1;
}

void registrar()
{
    FILE *p;
    char licencia[10];
    cout<<"Ingrese la Licencia del Programa: ";
    cin.sync();
    cin.getline(licencia,10);
    if(strcmp(licencia,"pctech")==0)
    {
        p=fopen("licencia.dat","wb");
        fwrite(licencia,sizeof(char*),1,p);
        fclose(p);
        cout<<endl<<endl;
        Sleep(300);
        cout<<"Programa Registrado con exito! ";
        system("pause>null");
    }
    else
    {
        licencia_incorrecta();
    }
}

int comparar()
{
        FILE *p;
        char licencia[10];
        p=fopen("licencia.dat","rb");
        fread(licencia,sizeof(char*),1,p);
        cout<<licencia;
        fclose(p);
        if(strcmp(licencia,"pctech")==0) { return 1;}
        return -1;
}

void licencia_incorrecta()
{
    int i;
    cout<<endl<<endl<<endl<<endl;
    cout<<"\t""\t""LICENCIA INVALIDA!! "<<endl;
    system("pause>null");
    for(i=3;i>0;i--)
    {
        system("cls");
        cout<<"El programa se cerrara en.. "<<i;
        Sleep(1000);
    }
    exit(1);
}

void imagen_utn()
{
    system("pause>nul");
    cout<<endl<<"            ©©©©©©©     #©©©©©©©     ©©©©©©©4           ";
    Sleep(50);
    cout<<endl<<"            ©©©©©©©     Ã©©©©©©©     ©©©©©©©!           ";
    Sleep(50);
    cout<<endl<<"            ©©©©©©©©    Ã©©©©©©©     ©©©©©©©            ";
    Sleep(50);
    cout<<endl<<"            *©©©©©©©    Ã©©©©©©©    ©©©©©©©©            ";
    Sleep(50);
    cout<<endl<<"             ©©©©©©©©   Ã©©©©©©©   ©©©©©©©©©            ";
    Sleep(50);
    cout<<endl<<"             ©©©©©©©©0 Ã©©©©©©©  @©©©©©©©©              ";
    Sleep(50);
    cout<<endl<<"              ©©©©©©©©©©@©©©©©©©©©©©©©©©©©              ";
    Sleep(50);
    cout<<endl<<"               ©©©©©©©©©©©©©©©©©©©©©©©©©©Ã              ";
    Sleep(50);
    cout<<endl<<"                ©©©©©©©©©©©©©©©©©©©©©©©©                ";
    Sleep(50);
    cout<<endl<<"                  ©©©©©©©©©©©©©©©©©©©©©                 ";
    Sleep(50);
    cout<<endl<<"                   /©©©©©©©©©©©©©©©©©                   ";
    Sleep(50);
    cout<<endl<<"            ©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©           ";
    Sleep(50);
    cout<<endl<<"            ©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©           ";
    Sleep(50);
    cout<<endl<<"            ©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©           ";
    Sleep(50);
    cout<<endl<<"            ©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©           ";
    Sleep(50);
    cout<<endl<<"            ©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©           ";
    Sleep(50);
    cout<<endl<<"                  M©©©©©©©©©©©©©©©©©©©                  ";
    Sleep(50);
    cout<<endl<<"                 ©©©©©©©©©©©©©©©©©©©©©©#                ";
    Sleep(50);
    cout<<endl<<"                ©©©©©©©©©©©©©©©©©©©©©©©©©               ";
    Sleep(50);
    cout<<endl<<"              $©©©©©©©©©©©©©©©©©©©©©©©©©©©              ";
    Sleep(50);
    cout<<endl<<"              ©©©©©©©©© #©©©©©©© ©©©©©©©©©@             ";
    Sleep(50);
    cout<<endl<<"             ©©©©©©©©©  Ã©©©©©©©  '©©©©©©©©             ";
    Sleep(50);
    cout<<endl<<"             ©©©©©©©©   Ã©©©©©©©    ©©©©©©©©            ";
    Sleep(50);
    cout<<endl<<"            ©©©©©©©©    Ã©©©©©©©    /©©©©©©©            ";
    Sleep(50);
    cout<<endl<<"            ©©©©©©©$    Ã©©©©©©©     ©©©©©©©            ";
    Sleep(50);
    cout<<endl<<"            ©©©©©©©     Ã©©©©©©©     ©©©©©©©/           ";
    Sleep(50);
    cout<<endl<<"                                                        ";
    Sleep(50);
    cout<<endl<<"                ©©   ©©©5©©©©©©© ©©©, ©©©               ";
    Sleep(50);
    cout<<endl<<"                ©©   ©©©   ©©©   ©©©©M©©©               ";
    Sleep(50);
    cout<<endl<<"                ©©   ©©©   ©©©   ©©!©©©©©               ";
    Sleep(50);
    cout<<endl<<"                ©©© 4©©    ©©©   ©©! ©©©©               ";
    Sleep(50);
    cout<<endl<<"                 ©©©©©     ©©©   ©©!  @©©               ";

    cout<<endl<<endl<<endl;
    system("pause>nul");
}

void logo()
{
cout<<endl<<"        ©©©©           ©                  ©©                             ";
Sleep(100);
cout<<endl<<"      ©©©  ©          ©©                                                 ";
Sleep(100);
cout<<endl<<"     ©©        ©©©©  ©©' ©©  ©©   ©©©©  ©©   ©©©©  ©© ©©©   ©©©©© .©©©©©©";
Sleep(100);
cout<<endl<<"      ©©©©©© ©©   ©©.©© ©©   ©© ©©   ©  ©© ©©©  ©© ©©© ©© ©© '©©© ©©©    ";
Sleep(100);
cout<<endl<<"          ©©©©   ©© ©©  ©©  ©© ©©      @© ©©   ©© ©©©  ©@©©©©©     ©©©@  ";
Sleep(100);
cout<<endl<<"  ©©    ©©© ©©  @©  ©©  ©   ©© ©©  ©© '©© ©©  ©©  ©©  ©© ©©   ©©     ©©  ";
Sleep(100);
cout<<endl<<"   ©©©©©     ©©©    ©   ©©@©©   ©©©   ©©   ©©©   ©©   ©©  ©©©©   ©©©©    ";
Sleep(100);
cout<<endl<<"                                                                         ";
Sleep(100);
cout<<endl<<" ©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©";
Sleep(100);
cout<<endl<<"                                                                         ";
Sleep(100);
cout<<endl<<"      ©©©©        ©©©         @©©©©©©    ©©©©©©©      © ©  ©      ©©     ";
Sleep(100);
cout<<endl<<"     ©©  ©©    ©©©©©          ©©©©©©©©© ©©         ©©©©©© ©©     ©©      ";
Sleep(100);
cout<<endl<<"    ©©   @©  ©©                  ©      ©©       ©©      ©©      ©©      ";
Sleep(100);
cout<<endl<<"    ©©©©©© ©©@                  ©©     ©©©©©©©  @©       ©©@@©©©©@       ";
Sleep(100);
cout<<endl<<"   ©©©     ©        ©©©©©©      ©©    ©©       ©©       ©©©©   '©        ";
Sleep(100);
cout<<endl<<"  ©@      ©©   ©©@             ©©     ©©      ©©©   ©©  ©©     ©@        ";
Sleep(100);
cout<<endl<<"  ©©       ©©©©@               ©©     ©©©©©©©  ©©©©©   ©©     ©©         ";
Sleep(100);
cout<<endl<<"                                                                         ";
Sleep(100);
cout<<endl<<" ©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©©        ";

        system("pause>nul");
        system("cls");
}

void presentacion()
{
    cout<<endl<<endl;
    cout<<"\t""\t""\t""Bienvenido a Soluciones PC-TECH!!"<<endl;
    cout<<"\t""\t""\t""-------------------------------"<<endl<<endl<<endl;
    cout<<"\t""\t""\t""Version 1.6 --> 8/12/2010"<<endl<<endl;
    cout<<"\t""\t""\t""Programa Hecho por Luke92"<<endl;
    cout<<"\t""\t""\t""Para la Materia Laboratorio II"<<endl;
    cout<<"\t""\t""\t""Del Profesor Daniel Kloster"<<endl;
    cout<<"\t""\t""\t""De la Universidad Tecnologica Nacional"<<endl;
    cout<<"\t""\t""\t""Facultad Regional General Pacheco"<<endl<<endl<<endl<<endl;
    cout<<"\t""\t""\t""Contacto: lucasjv92@gmail.com"<<endl;
    cout<<"\t""\t""\t""---------"<<endl<<endl;
    cout<<"\t""\t""\t""Legajo: 15510"<<endl;
    cout<<"\t""\t""\t""Nombre y Apellido: Lucas Vargas "<<endl<<endl;

    cout<<"\t""\t""\t";system("pause");
}

void mostrar_fecha()
{
    time_t tiempo;
    struct tm *tmPtr;
    tiempo = time(NULL);
    tmPtr = localtime(&tiempo);
    cout<<tmPtr->tm_mday;
    cout<<"/";
    cout<<tmPtr->tm_mon+1;
    cout<<"/";
    cout<<tmPtr->tm_year+1900;
}

void acerca_de()
{
    cout<<endl<<endl;
    cout<<"\t""\t""\t""     Soluciones PC-TECH"<<endl;
    cout<<"\t""\t""\t""     ------------------"<<endl<<endl<<endl;
    cout<<"\t""\t""\t""Version 1.6 --> 8/12/2010"<<endl<<endl;
    cout<<"\t""\t""\t""Programa Hecho por Luke92"<<endl;
    cout<<"\t""\t""\t""Para la Materia Laboratorio II"<<endl;
    cout<<"\t""\t""\t""Del Profesor Daniel Kloster"<<endl;
    cout<<"\t""\t""\t""De la Universidad Tecnologica Nacional"<<endl;
    cout<<"\t""\t""\t""Facultad Regional General Pacheco"<<endl<<endl<<endl<<endl;
    cout<<"\t""\t""\t""Contacto: lucasjv92@gmail.com"<<endl;
    cout<<"\t""\t""\t""---------"<<endl<<endl;
    cout<<"\t""\t""\t""Legajo: 15510"<<endl;
    cout<<"\t""\t""\t""Nombre y Apellido: Lucas Vargas "<<endl<<endl;
    cout<<"\t""\t""\t";system("pause");
}

void manual()
{
    cout<<endl<<endl<<"\t""\t""Instrucciones para el Uso del Programa"<<endl;
    cout<<"\t""\t""--------------------------------------"<<endl<<endl;
    cout<<"\t""1) Antes de poder agregar un registro de alguna reparacion"<<endl;
    cout<<"\t""debe primero agregar un Cliente, Tecnico y Tarea."<<endl<<endl;
    cout<<"\t""2) Siempre cerrar el programa desde el menu principal"<<endl<<endl;
    cout<<"\t""3) Al borrar algun registro, el mismo se podra recuperar."<<endl<<endl;
    cout<<"\t""4) La fecha del sistema no se puede cambiar, a menos"<<endl;
    cout<<"\t""que la cambies desde el sistema operativo."<<endl<<endl;
    cout<<"\t""5) Una vez que un equipo es reparado y entregado"<<endl;
    cout<<"\t""se tomara como una ganancia para el local."<<endl<<endl;
    cout<<"\t""6) Una vez que el equipo este reparado y/o entregado"<<endl;
    cout<<"\t""no se podra modificar ningun campo de el."<<endl<<endl<<endl;
    cout<<"\t""\t""\t";system("pause");
}

#endif // CERRAR_H_INCLUDED
