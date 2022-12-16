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

    printf("f(a): %.2lf\n", f(a));
    printf("f(b): %.2lf\n\n", f(b));
    // Calculando os valores das integrais
    *vi = f(a)*(b-a);
    *vs = f(b)*(b-a);

    printf("Metodo do Retangulo:\n");
    printf("Limite inferior: %.2lf \nLimite superior: %.2lf\n\n", *vi, *vs);

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

    
    // Metodo do retangulo
    metodo_retangulo(funcao, a, b, &si, &ss);






    
    return 0;
}