#ifndef PONTO_H_INCLUDED
#define PONTO_H_INCLUDED

//Define "Ponto" como um void pointer
typedef void *Ponto;

/*
*Cria uma struct ponto
*Precisa dos parametros necessarios para a criação de um ponto
*Retorna um void pointer para a struct ponto
*/
Ponto criaPonto(double x, double y);

/*
*Obtem o eixo x do ponto
*Precisa de um void pointer ponto como parametro
*Retorna o eixo x (x) do ponto
*/
double getPontoX(Ponto ponto);

/*
*Obtem o eixo y do ponto
*Precisa de um void pointer ponto como parametro
*Retorna o eixo y (y) do ponto
*/
double getPontoY(Ponto ponto);

/*
*Armazena um valor que é passado como parametro no eixo x do ponto também passado por parametro
*Precisa de um void pointer ponto e de um valor para o eixo x
*Não retorna nada
*/
void setPontoX(Ponto ponto, double x);

/*
*Armazena um valor que é passado como parametro no eixo y do ponto também passado por parametro
*Precisa de um void pointer ponto e de um valor para o eixo y
*Não retorna nada
*/
void setPontoY(Ponto ponto, double y);

#endif
