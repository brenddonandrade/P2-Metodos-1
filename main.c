#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define A -5
#define B 5
#define N 10



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
void metodo_retangulo_composto(double f(), double a, double b, double *vi, double *vs, int n){
    // vi = valor da soma usando o retangulo menor ( inferior )
    // vs = usando o maior ( superior )

    // Soma usando o limite inferior e superior
    double soma_inferior, soma_superior;

    int i, h;

    printf("A integral precisa dar algo entre: %.2lf e %.2lf \n\n", f(a)*(b-a), f(b)*(b-a));


    soma_inferior = 0;
    soma_superior = 0;


    h = (b-a)/n;

    for (i=0; i<n; i++){        
        soma_inferior += f(a)*(h);
        a+=h;
    }

    for (i=0; i<n; i++){        
        soma_superior += f(b)*(h);
        a+=h;
    }

    *vi = soma_inferior;
    *vs = soma_superior;
    
    return;
}


// Método do ponto central;


// Trapezoidal e trapezoidal composto




// Simpson, Simpson 1/3 e Simpson3 /8



int main(){
    // soma do retangulo inferior ( menor )
    // ss = soma superior
    double a, b, si, ss;

    // n é o nume de retangulos considerado
    int n;

    a = A;
    b = B;

    n = N;

    
    // Metodo do retangulo composto
    metodo_retangulo_composto(funcao, a, b, &si, &ss, n);

    printf("Soma inferior: %.2lf\nSoma superior: %.2lf\n\n", si, ss);




    
    return 0;
}