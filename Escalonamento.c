/*****************************************************************//**
 * \file   Escalonamento.c
 * \brief  Trabalho Prático EDA (Fase II)
 * 
 * \author João Fernandes
 * \email  a20128@alunos.ipca.pt
 * \date   June 2022
 *********************************************************************/

#include <stdio.h>
#include "Dados.h"

Job* Escalonamento(Job* job) 
{
    int idJob = 1;
    int idOp = 1;
    int tempo = 0;
    Job* aux = job;
    Job* aux2 = job;
    Job* aux3 = job;

    while (aux->id == idJob)
    {
        if (aux->listaoperacao != NULL)
        {
            while (aux->listaoperacao->operacao.id = idOp )
            {
                if (aux->listaoperacao->next != NULL && aux->listaoperacao->operacao.listamaquina->next!=NULL)
                {
                    tempo = aux->listaoperacao->operacao.listamaquina->maquina.tempo;

                    if (tempo < aux->listaoperacao->operacao.listamaquina->next->maquina.tempo)
                    {
                        aux = aux->listaoperacao->operacao.listamaquina->next;
                    }
                    else
                    {
                        tempo = aux->listaoperacao->operacao.listamaquina->next->maquina.tempo;
                        aux = aux->listaoperacao->operacao.listamaquina->next;
                    }
                }
                else
                {
                    aux->listaoperacao->next;
                    idOp = idOp++;
                }
            }
        }
    }
    printf("%d", tempo);
    return job;

}
