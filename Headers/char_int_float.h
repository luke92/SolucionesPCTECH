#ifndef CHAR_INT_FLOAT_H_INCLUDED
#define CHAR_INT_FLOAT_H_INCLUDED


int reconocer_coma(char *);
int convertir_int(char *,int);
float convertir(char *,int);
int potencia(int,int);

int validacioni(char *n)
{
    int n1=0;
    int n3=0;
    n1=convertir_int(n,n3);
    return n1;
}

float validacionf(char *n)
{
    float n1=0;
    int n3=0;
    n3=reconocer_coma(n);
    n1=convertir(n,n3);
    return n1;
}

int validar_cadenai(char *p)
{
    int i,c=0;
    c=strlen(p);
    for(i=0;i<c;i++)
    {
        if((p[i]<(char)48) || (p[i]>57))
        {
            return -1;
        }
    }
    return 1;
}

int validar_cadenaf(char *p)
{
    int i,c=0,band=0;
    c=strlen(p);
    for(i=0;i<c;i++)
    {
        if((p[i]<(char)46) || (p[i]>57))
        {
            return -1;
        }
        else
        {
            if(p[i]==(char) 47)
            {
                return -1;
            }
        }
        if((p[i]==(char) 46) && (band==0))
        {
            band=1;
        }
        else
        {
        if((p[i]==(char) 46) && (band==1))
        {
            return -1;
        }
        }
    }
    return 1;
}

float convertir(char *p,int n2)
{
    int c=0;
    int i,n,cont=0;
    float num=0;
    c=strlen(p);
    for(i=c-1;i>=0;i--)
    {
        if(p[i]!=46)
        {
        n=(int)p[i]-48;
        n=n*potencia(10,cont);
        num+=n;
        cont++;
        }

    }
    num=num/potencia(10,n2);
    return num;
}

int reconocer_coma(char *p)
{
    int c=0;
    int i,cont=0;
    c=strlen(p);
    for(i=c-1;i>=0;i--)
    {
        if(p[i]==(char) 46)
        {
            return cont;
        }
        cont++;
    }
    cont=0;
    return cont;
}

int potencia(int n,int p)
{
    int i,resultado=0;
    for(i=0;i<=p;i++)
    {
        if(i==0)
        {
            resultado=1;
        }
        else
        {
            resultado=resultado*n;
        }
    }
    return resultado;
}

int convertir_int(char *p,int n2)
{
    int c=0;
    int i,n,cont=0;
    int num=0;
    c=strlen(p);
    for(i=c-1;i>=0;i--)
    {
        if(p[i]!=46)
        {
        n=(int)p[i]-48;
        n=n*potencia(10,cont);
        num+=n;
        cont++;
        }

    }
    num=num/potencia(10,n2);
    return num;
}
#endif // CHAR_INT_FLOAT_H_INCLUDED
