#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// eu dividi o intervalo e vou multiplicar por 2 pois é uma funcao impar
#define A 0
#define B 5
#define N 10000

// valor exato da integral I ~ 216.36



// Mensionado para poder aplica-la
double derivada(double);

// Funcao do problema
double funcao(double x){
    double p1, p2;

    //Particionando a funcao
    p1 = 2 * M_PI *x;
    p2 = sqrt(1+ pow(derivada(x),2));

    return p1*p2;
}


// Derivada da funcao
double derivada(double x){
 

    return (-M_PI*sin((M_PI/10.0)*x));
}



// Método do Retângulo  
void metodo_retangulo(double f(), double a, double b, double *vi, double *vs){
    // vi = valor da soma usando o retangulo menor ( inferior )
    // vs = usando o maior ( superior )

    // Calculando os valores das integrais
    *vi = 2*f(a)*(b-a);
    *vs = 2*f(b)*(b-a);

    printf("\nMetodo do Retangulo--------------------------------------------------------\n");
    printf("I_i~ %.2lf \nI_s~ %.2lf\n\n", *vi, *vs);

    return;
}


// Método do ponto central;
void metodo_ponto_central(double f(), double a, double b, double *m){
    //Calculando a integral
    *m = 2*(f(((a+b)/2.0))*(b-a));


    printf("Metodo do Ponto Central---------------------------------------------------\n");
    printf("I~ %.2lf\n\n", *m);

    return;
}



// Trapezoidal 
void metodo_trapezoidal(double f(), double a, double b, double *t){
    // Calculando  a integral
    *t = 2*(((f(a) + f(b))/2.0)*(b-a));

    printf("Metodo do Trapezio---------------------------------------------------\n");
    printf("I~ %.2f\n\n", *t);

    return;
}




// Trapezoidal composto
void metodo_trapezoidal_composto(double f(), double a, double b, double *tc, int n){
    double h;
    double soma, xi;

    soma = 0;

    // Largura do interval = h
    h = (b-a)/((float) n);


    // Calculando a integral
    xi = a+h;
    do {
        soma += f(xi);
        xi+=h;
    
    }while(xi < (b-h));
    soma *= h;

    soma += (h/2.0)*(f(a)+ f(b));


    *tc = 2*soma;

    printf("Metodo do Trapezio Composto---------------------------------------------------\n");
    printf("I~ %.2f\n\n", *tc);

    return;
}


// Simpson 1/3 
void metodo_simpson_1_3(double f(), double a, double b, double *s1){
    double h;

    h = (b-a)/2.0;

    // Calculando a integral
    *s1 =  2*((h/3)*(f(a) + (4*f((a+b)/2.0)) + f(b)));

    
    printf("Metodo de Simpson 1/3:\n");
    printf("I~ %.2lf\n\n", *s1);

    return;
}



// Simpson 3/8
void metodo_simpson_3_8(double f(), double a, double b, double *s3){
    double h, x2, x3;

    h = (b-a)/3.0;
    x2 = a+h;
    x3 = x2+h;

    
    // Calculo da integral
    *s3 = 2*((3/8)*h*(f(a) + 3*f(x2) + 3*f(x3) + f(b)));

    printf("Antes do calculo: f(a): %.2lf\t3*f(x2): %.2lf\t3*f(x3): %.2lf\tf(b): %.2lf\n\n\n", f(a), 3*f(x2), 3*f(x3), f(b));

    printf("Metodo de Simpson 3/8:\n");
    printf("I~ %.2lf\n\n", *s3);

    return;
}




int main(){
    // soma do retangulo inferior ( menor )
    // ss = soma superior
    double a, b, si, ss, m, t, tc, s1, s3;

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
    
    // Metodo de Simpson 1/3
    metodo_simpson_1_3(funcao, a, b, &s1); 

    // Metodo de Simpson 3/8
    metodo_simpson_3_8(funcao, a, b, &s3);

    return 0;
}