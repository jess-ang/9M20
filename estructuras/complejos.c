/*
Escribir un programa que permita hacer las operaciones de suma, resta y multiplicación
de números complejos. El tipo complejo ha de definirse en una estructura.
*/

#include<stdio.h>
#include<ctype.h>
typedef struct complejo{
   float real;
   float imag;
} Complejo;

void printMenu();
void opcionEsValida(int *opcion);
void printComplejo(Complejo c);
void setComplejo(Complejo *c);
Complejo suma(Complejo a,Complejo b);
Complejo resta(Complejo a,Complejo b);
Complejo multiplicacion(Complejo a,Complejo b);

int main(){
    Complejo a, b, resultado;
    int opcion;
    printMenu();
    opcionEsValida(&opcion);
    printf("\n\nIngrese el primer numero"); /*Falta validar la captura de numeros*/
    setComplejo(&a);
    printf("\nIngrese el segundo numero");
    setComplejo(&b);
    switch(opcion){
        case 1: resultado=suma(a,b);
            break;
        case 2: resultado=resta(a,b);
            break;
        case 3: resultado=multiplicacion(a,b);
            break;
    };
    printf("\nResultado: ");
    printComplejo(resultado);
    return 0;
}

void printMenu(){
    printf("\n--- Operaciones de numeros complejos ---\n");
    printf("\n1) Suma");
    printf("\n2) Resta");
    printf("\n3) Multiplicacion");
    printf("\nOpcion: ");
}

void opcionEsValida(int *opcion){
    scanf("%d",opcion);
    while(*opcion<1 || *opcion>3){
        printf("\n\nOpcion no valida! Ingrese de nuevo: ");
        setbuf(stdin, NULL);
        scanf("%d",opcion);
    }
}
void printComplejo(Complejo c){
    printf("%f + %f i",c.real,c.imag);
}

void setComplejo(Complejo *c){
    printf("\nParte real: ");
    scanf("%f",&c->real);
    printf("\nParte imaginaria: ");
    scanf("%f",&c->imag);
}

Complejo suma(Complejo a,Complejo b){
    Complejo resultado;
    resultado.real=a.real+b.real;
    resultado.imag=a.imag+b.imag;
    return resultado;
}

Complejo resta(Complejo a,Complejo b){
    Complejo resultado;
    resultado.real=a.real-b.real;
    resultado.imag=a.imag-b.imag;
    return resultado;
}

Complejo multiplicacion(Complejo a,Complejo b){
    Complejo resultado;
    resultado.real=a.real*b.real - a.imag*b.imag;
    resultado.imag=a.real*b.imag + a.imag*b.real;
    return resultado;
}


