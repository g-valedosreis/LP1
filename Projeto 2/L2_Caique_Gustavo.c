/*
Caique Rosendo da Silva		0030482521001
Gustavo Vale dos Reis		0030482521016

Lista 2 - Projeto
*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

typedef struct Data{
	int dia;
	int mes;
	int ano;
}Data;

typedef struct Registro{
	Data data;
	float temperatura;
}Registro;
//Funções do exercício 1
int lerQuantidade();
bool validarData(Data d);
void lerRegistros(Registro *v,int quantidade);
//Funções do exercício 2
int indiceMaiorTemperatura(Registro *r);
float calcularMedia(Registro *r);
float calcularVariancia(Registro *r);
float calcularDesvioPadrao(Registro *r);
int calcularModa(Registro *r);
//Funções do exercício 3
int abaixoMedia(Registro *r,int v[]);
void listarAbaixoMedia(Registro *r,int v[], int qtd);
//Funlções do exercício 4
void calcularDiaSemana(Registro *r,int ds[]);
char* nomeDiaSemana(int ds);

//Variáveis globais
int qtdRegistros=0;

int main ()
{
	Registro registros[31];
	int menu, vAbaixoMedia[31], qtdAbaixoMedia, diasSemana[31],i;
	
	do
	{
		system("cls");
		printf("Menu\n");
		printf("------------------------------------\n");
		printf("[1] Cadastrar Registros\n");
		printf("[2] Mostrar estatisticas\n");
		printf("[3] Listar abaixo da media\n");
		printf("[4] Mostrar dias da semana\n");
		printf("[5] Sair\n");
		printf("------------------------------------\n");
		scanf("%i",&menu);
		switch(menu)
		{
			case 1:
				qtdRegistros = lerQuantidade();
				lerRegistros(registros,qtdRegistros);
				break;
			case 2:
				if(qtdRegistros>0)
				{
					printf("A maior temperatura registrada: %.2f\n",registros[indiceMaiorTemperatura(registros)].temperatura);
					printf("A media das temperaturas: %.2f\n",calcularMedia(registros));
					printf("A variancia populacional: %.2f\n",calcularVariancia(registros));
					printf("O desvio padrao populacional: %.2f\n",calcularDesvioPadrao(registros));
					printf("A moda: %i\n",calcularModa(registros));
					system("pause");	
				}else{
					printf("Ainda nao ha registros\n");
					system("pause");
				}
				break;
			case 3:
				if(qtdRegistros>0)
				{
					qtdAbaixoMedia = abaixoMedia(registros,vAbaixoMedia);
					listarAbaixoMedia(registros,vAbaixoMedia,qtdAbaixoMedia);
				}else{
					printf("Ainda nao ha registros\n");
					system("pause");
				}
				
				break;
			case 4:					
				if(qtdRegistros>0)
				{
					calcularDiaSemana(registros,diasSemana);
					for(i=0;i<qtdRegistros;i++)
					{
						printf("Dia %i/%i/%i - %s\n",registros[i].data.dia,registros[i].data.mes,registros[i].data.ano,nomeDiaSemana(diasSemana[i]));
					}
					system("pause");
				}else{
					printf("Ainda nao ha registros\n");
					system("pause");
				}
				break;
		}	
	}while(menu != 5);
}


int lerQuantidade()
{
	int qtd;
	do{
		system("cls");
		printf("Cadastrar Registros\n");
		printf("------------------------------------\n");
		printf("Deseja cadastrar quantos registros?\n");
		scanf("%i",&qtd);
		if(qtd <1 || qtd > 31)
		{
			system("cls");
			printf("Digite um valor va1lido (1 a 31)\n");
			system("pause");
		}
	}while(qtd < 1 || qtd > 31);
	return qtd;		
}

void lerRegistros(Registro *v, int quantidade)
{
	int i;
	for(int i = 0; i < quantidade; i++)
	{
		system("cls");
		printf("Cadastrar Registros\n");
		printf("------------------------------------\n");
		printf("Digite a %i(a) data:\n",i+1);
		do
		{
			scanf("%i/%i/%i",&(v+i)->data.dia,&(v+i)->data.mes,&(v+i)->data.ano);
			if(!validarData((v+i)->data))
			{
				system("cls");
				printf("Digite uma data valida\n");
			}
		}while(!validarData((v+i)->data));
		
		printf("Digite a temperatura para %i/%i/%i:\n",(v+i)->data.dia,(v+i)->data.mes,(v+i)->data.ano);
		do
		{
			scanf("%f",&(v+i)->temperatura);
			if((v+i)->temperatura < -50 || (v+i)->temperatura > 60)
			{
				system("cls");
				printf("Digite um valor valido (-50 graus a 60 graus)\n");
			}
		}while((v+i)->temperatura < -50 || (v+i)->temperatura > 60);
	}
}

bool validarData(Data d)
{
	if(d.ano < 1)
		return false;
	if(d.mes<1 || d.mes >12)
		return false;
	switch(d.mes)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if(d.dia<1 || d.dia > 31)
			return false;
			break;
		case 2:
			if(d.ano%400==0 || (d.ano%4==0 && d.ano%100!=0))
			{
				if(d.dia < 1 || d.dia > 29)
						return false;	
			}else{
				if(d.dia < 1 || d.dia > 28)
					return false;
			}
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if(d.dia<1 || d.dia > 30)
			return false;
			break;
	}
	return true;
}

int indiceMaiorTemperatura(Registro *r){
	int i,indice;
	float tMaior=0;
	for(i = 0; i < qtdRegistros; i++)
	{
		if((r+i)->temperatura > tMaior)
		{
			tMaior = (r+i)->temperatura;
			indice = i;
		}
	}
	return indice;
}

float calcularMedia(Registro *r){
	int i;
	float media;
	for(i=0; i < qtdRegistros; i++)
	{
		media += (r+i)->temperatura;
	}
	media /= qtdRegistros;
	return media;
}

float calcularVariancia(Registro *r){
	int i;
	float variancia, media;
	media = calcularMedia(r);
	for(i=0; i < qtdRegistros; i++)
	{
		variancia += pow(((r+i)->temperatura - media),2);
	}
	variancia /= qtdRegistros;
	return variancia;
}

float calcularDesvioPadrao(Registro *r){
	return sqrt(calcularVariancia(r));
}

int calcularModa(Registro *r){
	int i,j,cont[qtdRegistros],moda;
	for(i=0;i<qtdRegistros;i++)
	{
		cont[i]=0;
	}
	for (i=0;i<qtdRegistros;i++)
	{
		for(j=0;j<qtdRegistros;j++)
		{
			if((int)(r+i)->temperatura == (int)(r+j)->temperatura)
			{
				cont[i]++;
			}
		}
	}
	int contMaior = 0;
	for(i=0;i<qtdRegistros;i++)
	{
		if(cont[i]>contMaior || (cont[i]=contMaior && (int)(r+i)->temperatura > moda))
		{
			moda = (int)(r+i)->temperatura;
			contMaior = cont[i];
		}
	}
	return moda;
}

int abaixoMedia(Registro *r,int v[])
{
	int i, indiceAbaixoMedia;
	int j=0;
	for(i=0;i<qtdRegistros;i++)
	{
		v[i]=0;
	}
	for(i=0;i<qtdRegistros;i++)
	{
		if((r+i)->temperatura<calcularMedia(r))
		{
			v[j]= i;
			j++;
		}
	}
	return j;
}

void listarAbaixoMedia(Registro *r,int v[], int qtd)
{
	int i,j;
	printf("Dias e temperaturas a baixo da media:\n");
	for(i=0;i<qtd;i++)
	{
		j=v[i];
		printf("Dia: %i/%i/%i\nTemperatura: %.2f\n\n",(r+j)->data.dia,(r+j)->data.mes,(r+j)->data.ano,(r+j)->temperatura);
	}
	system("pause");	                                                  
}

void calcularDiaSemana(Registro *r,int ds[])
{
	int i,d,m,a1,a2;
	for(i=0;i<qtdRegistros;i++)
	{
		m = (r+i)->data.mes - 2;
		a2=(r+i)->data.ano%100;
		a1=(r+i)->data.ano/100;
		d=(r+i)->data.dia;
		if(m<1)
		{
			m+=12;
			a2-=1;
		}
		ds[i] = (((int)(2.6*m -0.1) + d + a2 + (a2/4) + (a1/4) - 2 * a1)%7);	
	}
}

char* nomeDiaSemana(int ds)
{
	switch(ds)
	{
		case 0:
			return "Domingo";
		case 1:
			return "Segunda-feira";
		case 2:
			return "Terca-feira";
		case 3:
			return "Quarta-feira";
		case 4:
			return "Quinta-feira";
		case 5:
			return "Sexta-feira";
		case 6:
			return "Sabado";
	}
	return "";
}