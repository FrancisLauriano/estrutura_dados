#define PI 3.14

typedef struct cilindro *Cilindro;

Cilindro criar(double r, double h);
double areaBase(Cilindro p);
double areaLateral(Cilindro p);
double areaTotal(Cilindro p);
double acessarValores(Cilindro p, char opcao);
double volumeCilindro(Cilindro p);
void destruir(Cilindro p);
