/*
Un punto en el plano se puede representar mediante una estructura con dos campos. Escribir un programa que
realice las siguientes operaciones con puntos en el plano.
    -Dados dos puntos calcular la distancia entre ellos.
    -Dados dos puntos determinar el punto medio de la línea que los une.
*/

#include<stdio.h>
#include<math.h>

typedef struct punto{
    float x;
    float y;
}Punto;

void setPunto(Punto *p);
float getDistancia(Punto a, Punto b);
Punto getPuntoMedio(Punto a, Punto b);

int main(){
    Punto a,b,puntoMedio;
    printf("\n\nIngrese el punto A");
    setPunto(&a);
    printf("\nIngrese el punto B");
    setPunto(&b);
    printf("\nDistancia entre A y B: %f",getDistancia(a,b));
    puntoMedio=getPuntoMedio(a,b);
    printf("\nPunto medio entre A y B: (%f,%f)",puntoMedio.x,puntoMedio.y);
    return 0;
}

void setPunto(Punto *p){
    printf("\nCoordenada x: ");
    scanf("%f",&p->x);
    printf("Coordenada y: ");
    scanf("%f",&p->y);
}

float getDistancia(Punto a, Punto b){
    float base,altura;
    base=a.x-b.x;
    altura=a.y-b.y;
    return sqrt(base*base+altura*altura);
}

Punto getPuntoMedio(Punto a, Punto b){
    Punto pMedio;
    pMedio.x=(a.x+b.x)/2;
    pMedio.y=(a.y+b.y)/2;
    return pMedio;
}
