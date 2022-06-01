/*****************************************************************//**
 * \file   Opercacoes.c
 * \brief  Trabalho Prático EDA (Fase II) - Operações
 * 
 * \author João Fernandes
 * \email  a20128@alunos.ipca.pt
 * \date   June 2022
 *********************************************************************/

#include <stdio.h>
#include "Dados.h"

 /**
 * @brief Cria uma nova Operação
 * @param [in] id		id da operação
 * @param [in] listamaquina		lista de máquinas
 * @return	Operação
 */
Operacao* CriarOperacao(int id, ListaMaquina* listamaquina)
{
	Operacao* aux = (Operacao*)calloc(1, sizeof(Operacao));

	aux->id = id;
	aux->listamaquina = listamaquina;

	return aux;
}

/**
* @brief Cria uma lista de operações
* @param [in] operacao		operação
* @return	Lista de operações
*/
ListaOperacao* CriarListaOperacao(Operacao* operacao)
{
	ListaOperacao* novo = (ListaOperacao*)calloc(1, sizeof(ListaOperacao));

	novo->operacao.id = operacao->id;
	novo->operacao.listamaquina = operacao->listamaquina;
	novo->next = NULL;

	return novo;
}

/**
* @brief Verifica se a operação existe
* @param [in] listaoperacao		lista de operações
* @param [in] id		id da operação
* @return	true ou false
*/
bool OperacaoExiste(ListaOperacao* listaoperacao, int id)
{

	if (listaoperacao != NULL)
	{

		ListaOperacao* aux = listaoperacao;

		while (aux != NULL)
		{

			if (aux->operacao.id == id)
			{
				return true;
			}
			aux = aux->next;
		}
	}

	return false;
}

/**
* @brief Inserir operação na lista
* @param [in] listaoperacao		lista de operações
* @param [in] novaoperacao		nova operação
* @return	Lista de operações 
*/
ListaOperacao* InserirListaOperacao(ListaOperacao* listaoperacao, Operacao* novaoperacao)
{

	if (novaoperacao == NULL)
	{
		return listaoperacao;
	}

	ListaOperacao* aux = CriarListaOperacao(novaoperacao);

	if (OperacaoExiste(listaoperacao, aux->operacao.id))
	{
		return listaoperacao;
	}

	if (listaoperacao == NULL)
	{
		listaoperacao = aux;
	}
	else
	{

		ListaOperacao* tmp = listaoperacao;

		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = aux;
	}

	return listaoperacao;
}
/**
* @brief Procura uma operação na lista
* @param [in] listaoperacao		lista de operações
* @param [in] id		id da operação
* @return	Operação
*/
Operacao* ProcurarOperacao(ListaOperacao* listaoperacoes , int id) 
{
	ListaOperacao* aux = listaoperacoes;

	if (listaoperacoes != NULL) 
	{
		while (aux != NULL) 
		{
			if (aux->operacao.id == id) 
			{
				return (aux);
			}
			aux = aux->next;
		}
	}

	return NULL;
}

/**
* @brief Altera os valores da operação
* @param [in] operacao		operação
* @param [in] idJob		id do job
* @param [in] idOp		id da operação
* @param [in] idMaq		id da máquina
* @param [in] novoidMaq		novo id da máquina
* @param [in] novoTempo		novo tempo da máquina
* @return	Operação
*/
Operacao* AlterarOperacao(Operacao* operacao, int idJob, int idOp, int idMaq, int novoidMaq, int novoTempo) 
{
	if (operacao != NULL) 
	{
		Job* job = Procurar(operacao, idJob);
		
		if (job != NULL && job->listaoperacao != NULL) 
		{
			Operacao* auxOp = ProcurarOperacao(job->listaoperacao, idOp);
			
			if (auxOp != NULL) 
			{
				Maquina* auxMaq = ProcurarMaquina(auxOp->listamaquina, idMaq);
				auxMaq = AlterarMaquina(auxMaq, novoidMaq, novoTempo);
			}
		}
	}

	return operacao;
}

/**
* @brief Mostra os valores da operação
* @param [in] listaoperacao		lista de operações
* @return	Nada
*/
void MostrarListaOperacao(ListaOperacao* listaoperacao) 
{
	if (listaoperacao != NULL) 
	{
		printf("\nOperacão: %d: \n", listaoperacao->operacao.id);
		MostrarListaMaquina(listaoperacao->operacao.listamaquina);
		
		while (listaoperacao->next != NULL) 
		{
			listaoperacao= listaoperacao->next;
			printf("\nOperacão: %d: \n", listaoperacao->operacao.id);
			MostrarListaMaquina(listaoperacao->operacao.listamaquina);
		};
	}
}

/**
* @brief Remove uma operação
* @param [in] operacao		operação
* @param [in] idJob		id do job
* @param [in] idOp		id da operação
* @return	Operação
*/
Operacao* RemoverOperacao(Operacao* operacao, int idJob, int idOp) 
{
	if (operacao != NULL) 
	{
		Job* job = Procurar(operacao, idJob);
		if (job != NULL && job->listaoperacao != NULL) 
		{
			ListaOperacao* aux = job->listaoperacao;
			ListaOperacao* auxAnt = aux;
			
			if (aux->operacao.id == idOp) 
			{				            //primeira operacao
				job->listaoperacao = job->listaoperacao->next;		//head passa para a segunda operacao
				free(aux);
			}
			else 
			{
				while (aux && aux->operacao.id != idOp) 
				{			//procura para remover
					auxAnt = aux;
					aux = aux->next;
				}
				if (aux != NULL) 
				{									    //se encontrou, remove
					auxAnt->next = aux->next;
					free(aux);
				}
			}
		}
	}

	return operacao;
}
