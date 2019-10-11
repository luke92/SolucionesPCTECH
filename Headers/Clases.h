#ifndef CLASES_H_INCLUDED
#define CLASES_H_INCLUDED

/*Archivos
--------
Tecnicos
Clientes
Registros
Detalle Reparacion
Tareas
*/

///---------------CLASE DIRECCION-------------------------

class Direccion
{
  private:
    char nombre_calle[30];
    char numero[10];
    char piso[3];
    char depto[3];
    char localidad[30];
    char cod_postal[10];
  public:
    void Cargar();
    void Mostrar();
    char *getNombre_calle(){return nombre_calle;}
    char *getNumero(){return numero;}
    char *getPiso(){return piso;}
    char * getDepto(){return depto;}
    char * getLocalidad(){return localidad;}
    char * getCod_postal(){return cod_postal;}
    void cargar();
    void modificardir();
    void setNombre_calle(char *n){strcpy(nombre_calle,n);}
    void setNumero(char * n){strcpy(numero,n);}
    void setPiso(char *p){strcpy(piso,p);}
    void setDepto(char *d){strcpy(depto,d);}
    void setLocalidad(char *l){strcpy(localidad,l);}
    void setCod_postal(char *cp){strcpy(cod_postal,cp);}
    friend istream& operator>>(istream &,Direccion&);
    friend ostream& operator<<(ostream &,Direccion&);
};


///---------------CLASE TECNICOS-------------------------

class Tecnicos
{
  private:
    int dia,mes,anio; //Antiguedad
    int cod;
    char nombre[30];
    char apellido[30];
    char telefono[15];
    bool estado;
    Direccion dir;

  public:
    int getcod() { return cod;}
    char *getnombre() { return nombre;}
    char *getapellido() { return apellido;}
    char *gettelefono() {return telefono;}
    bool getestado() { return estado;}

    void mostrar();
    void cargar();
    void cargar2();
    void grabar();
    void modificar(int);
    int leer(int);

    void setcod(int x) {cod=x;}
    void setnombre(char *x)   { strcpy(nombre,x);}
    void setapellido(char *x) { strcpy(apellido,x);}
    void settelefono(char *x) { strcpy(telefono,x);}
    void setestado(int x) { if(x==1) {estado=true;} if(x==-1){estado=false;}}

};

///---------------CLASE CLIENTES-------------------------

class Clientes
{
  private:
    int cod;
    char nombre[30];
    char apellido[30];
    char telefono[15];
    bool estado;
    Direccion dir;

  public:
    int getcod() { return cod;}
    char *getlocalidad() { return dir.getLocalidad();}
    char *getnombre_calle() { return dir.getNombre_calle();}
    char *getnumero() { return dir.getNumero();}
    char *getCodPostal() { return dir.getCod_postal();}
    char *getnombre() { return nombre;}
    char *getapellido() { return apellido;}
    char *gettelefono() {return telefono;}
    bool getestado() { return estado;}

    void mostrar();
    void cargar();
    void cargar2();
    void grabar();
    void modificar(int);
    int leer(int);

    void setcod(int x) {cod=x;}
    void setnombre(char *x)   { strcpy(nombre,x);}
    void setapellido(char *x) { strcpy(apellido,x);}
    void settelefono(char *x) { strcpy(telefono,x);}
    void setestado(int x) { if(x==1) {estado=true;} if(x==-1){estado=false;}}

};

///---------------CLASE REPARACION-------------------------

class Reparacion
{
    private:
    int cod_rep;
    ///Fecha Ingreso, Egreso
    int anio,anio_e;
    int mes,mes_e;
    int dia,dia_e;
    /////////////////////////
    int cod_cliente;
    int cod_tecnico;
    bool reparado;
    bool estado;
    float importe;
    public:
    int cargar();
    void mostrar();
    void grabar();
    void modificar(int);
    int leer(int);
    int cargar2();

    int getcod_rep() {return cod_rep; }
    float getimporte() {return importe;}
    int getanio() { return anio;}
    int getmes() { return mes;}
    int getdia() { return dia;}
    int getanio_e() { return anio_e;}
    int getmes_e() { return mes_e;}
    int getdia_e() { return dia_e;}
    int getcod_cliente() { return cod_cliente;}
    int getcod_tecnico() {return cod_tecnico;}
    bool getestado() { return estado;}
    bool getreparado() { return reparado;}
    void technic(int x,float *);

    void setcod_cliente(int x) {cod_cliente=x;}
    void setcod_tecnico(int x) {cod_tecnico=x;}
    void setcod_rep(int x) {cod_rep=x;}
    void setfecha_ingreso();
    void setfecha_ingreso2();
    void setfecha_egreso();
    void setfe() { dia_e=0; mes_e=0; anio_e=0;}
    void setanio(int x) { anio=x;}
    void setmes(int x) { mes=x;}
    void setdia(int x) { dia=x;}
    void setanio_e(int x) { anio_e=x;}
    void setmes_e(int x) { mes_e=x;}
    void setdia_e(int x) { dia_e=x;}
    void setreparar(int x) { if(x==1) {reparado=true;} else { reparado=false;}}
    void setimporte(float x) { importe=x;}
    void setestado(int x) { if(x==1) {estado=true;} if(x==-1){estado=false;}}
};

///---------------CLASE TAREAS-------------------------

class Tareas
{
    private:
    bool estado;
    int cod_tarea;
    char descripcion[30];
    float importe;

    public:
    void cargar();
    void cargar2();
    void mostrar();
    void grabar();
    void modificar(int );
    int leer(int );

    int getcod_tarea() { return cod_tarea;}
    char *getdescripcion() { return descripcion;}
    float getimporte() { return importe;}
    bool getestado() { return estado;}
    void setcod_tarea(int x) { cod_tarea=x;}
    void setdescripcion(char *x) { strcpy(descripcion,x);}
    void setimporte(float x) { importe=x;}
    void setestado(int x) { if(x==1) {estado=true;} if(x==-1){estado=false;}}
};

///---------------CLASE DETALLES DE REPARACION-------------------------

class Detrep
{
    private:
    int cod_rep;
    int num_linea;
    int cod_tarea;
    float importe;
    bool estado;

    public:
    int cargar(int,int);
    void grabar();
    void modificar(int);
    int leer(int);

    bool getestado() { return estado;}
    int getcod_rep() { return cod_rep;}
    int getnum_linea() { return num_linea;}
    int getcod_tarea() { return cod_tarea;}
    float getimporte() { return importe;}

    void setcod_tarea(int x) { cod_tarea=x;}
    void setcod_rep(int x) { cod_rep=x;}
    void setnumlinea(int x) { num_linea=x;}
    void setimporte(float x) { importe=x;}
    void setestado(int x) { if(x==1) {estado=true;} else{estado=false;}}
};

//////////////////////////////////////////////////////////////

#endif // CLASES_H_INCLUDED
