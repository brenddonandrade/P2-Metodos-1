#include <stdio.h>
#include <stdlib.h>
#include <math.h>


// Mensionado para poder aplica-la
double derivada(double);

// Funcao do problema
double funcao(double x){
    double p1, p2;

    //Particionando a funcao
    p1 = 2 * M_PI *x;
    p2 = sqrt(1+ pow(abs(derivada(x)),2));

    return p1*p2;
}


// Derivada da funcao
double derivada(double x){
    double p1, p2;

    p1 = 10 * (M_PI/10.0);
    p2 = - sin((M_PI/10.0)*x);

    return p1*p2;
}



// Método do Retângulo  
void metodo_retangulo_composto(double f(), double a, double b, double *pi, double *ps, int n){
    double limite_inferior, limite_superior;
    int i, h;

    printf("A integral precisa dar algo entre: %.2lf e %.2lf \n\n", f(a)*(b-a), f(b)*(b-a));


    limite_inferior = 0;
    limite_superior = 0;


    h = (b-a)/n;

    for (i=0; i<n; i++){        
        limite_inferior += f(a)*(h);
        a+=h;
    }

    for (i=0; i<n; i++){        
        limite_superior += f(b)*(h);
        a+=h;
    }
    
    *pi = limite_inferior;
    *ps = limite_superior;
    
    return;
}


// Método do ponto central;


// Trapezoidal e trapezoidal composto




// Simpson, Simpson 1/3 e Simpson3 /8



int main(){

    double x1;

    x1 = 0;

    printf("f(0)= %lf", funcao(x1));

    return 0;
}