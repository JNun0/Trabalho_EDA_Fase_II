/*****************************************************************//**
 * \file   Main.c
 * \brief  Trabalho Prático EDA (Fase II) - Main
 * 
 * \author João Fernandes
 * \email  a20128@alunos.ipca.pt
 * \date   June 2022
 *********************************************************************/

#include <stdio.h>
#include <locale.h>	
#include "Dados.h"

int main() {

    setlocale(LC_ALL, "Portuguese");

    Job* temp;
    Job* listajobs;

    Maquina* M1 = CriarMaquina(1,3);
    Maquina* M2 = CriarMaquina(2,4);


    Maquina* M3 = CriarMaquina(2, 4);
    Maquina* M4 = CriarMaquina(4, 5);

    ListaMaquina* listamaquinasOP1 = NULL;
    ListaMaquina* listamaquinasOP2 = NULL;

    listamaquinasOP1 = InserirListaMaquina(listamaquinasOP1, M1);
    listamaquinasOP1 = InserirListaMaquina(listamaquinasOP1, M2);

    listamaquinasOP2 = InserirListaMaquina(listamaquinasOP2, M3);
    listamaquinasOP2 = InserirListaMaquina(listamaquinasOP2, M4);

    Operacao* OP1 = CriarOperacao(1, listamaquinasOP1);
    Operacao* OP2 = CriarOperacao(2, listamaquinasOP2);


    ListaOperacao* listaoperacoesJ1 = NULL;

    listaoperacoesJ1 = InserirListaOperacao(listaoperacoesJ1, OP1);
    listaoperacoesJ1 = InserirListaOperacao(listaoperacoesJ1, OP2);


    listajobs = NULL;

    listajobs = Inserir(listajobs, 1, listaoperacoesJ1);
    listajobs = Inserir(listajobs, 2, listaoperacoesJ1);


    printf("Altura: %d\n", Altura(listajobs));

    temp = Procurar(listajobs, 1);
    printf("%d\n",temp->id);

    PorOrdem(listajobs); printf("\n");

    temp = Max(listajobs);
    printf("Max: %d\n", temp->id);

    temp = Min(listajobs);
    printf("Min: %d\n", temp->id);

    MostrarListaJobs(listajobs);

    //listajobs = Apagar(listajobs, 1, OP1J1, 1);
    RemoverOperacao(OP2,1,2);
    PorOrdem(listajobs); printf("\n");

    //listajobs = Esvaziar(listajobs);

    //MostrarListaJobs(listajobs);

}
