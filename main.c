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
void metodo_retangulo(double f(), double a, double b, double *vi, double *vs){
    // vi = valor da soma usando o retangulo menor ( inferior )
    // vs = usando o maior ( superior )

    // Calculando os valores das integrais
    *vi = f(a)*(b-a);
    *vs = f(b)*(b-a);

    printf("\nMetodo do Retangulo:\n");
    printf("I_i: %.2lf \nI_s: %.2lf\n\n", *vi, *vs);

    return;
}


// Método do ponto central;
void metodo_ponto_central(double f(), double a, double b, double *m){
    //Calculando a integral
    *m = f(((a+b)/2.0))*(b-a);

    printf("Metodo do Ponto Central:\n");
    printf("I: %.2lf\n\n", *m);

    return;
}


// Trapezoidal 
void metodo_trapezoidal(double f(), double a, double b, double *t){
    // Calculando  a integral
    *t = ((f(a) + f(b))/2.0)*(b-a);

    printf("Metodo do Trapezio:\n");
    printf("I: %.2f\n\n", *t);

    return;
}




// Trapezoidal composto
void metodo_trapezoidal_composto(double f(), double a, double b, double *tc, int n){
    int h;
    double soma, xi;

    soma = 0;

    // Largura do interval = h
    h = (b-a)/n;


    // Calculando a integral
    xi = a+h;
    do {
        soma += f(xi);
        xi+=h;
    
    }while(xi != (b-h));
    soma *= h;

    soma = (h/2.0)*(f(a)+ f(b));


    *tc = soma;

    printf("Metodo do Trapezio Composto:\n");
    printf("I: %.2f\n\n", *tc);

    return;
}


// Simpson, Simpson 1/3 e Simpson3 /8



int main(){
    // soma do retangulo inferior ( menor )
    // ss = soma superior
    double a, b, si, ss, m, t, tc;

    // n é o nume de retangulos considerado
    int n;

    a = A;
    b = B;

    n = N;

    
    // Metodo do retangulo
    metodo_retangulo(funcao, a, b, &si, &ss);

    // Metodo do Ponto Central
    metodo_ponto_central(funcao, a, b, &m);

    // Metodo Trapezoidal
    metodo_trapezoidal(funcao, a, b, &t);

    // Metodo Trapezoidal composto
    metodo_trapezoidal_composto(funcao, a, b, &tc, n);
    
    
    //

    return 0;
}