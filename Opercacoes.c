/*****************************************************************//**
 * \file   Opercacoes.c
 * \brief  Trabalho Pr�tico EDA (Fase II) - Opera��es
 * 
 * \author Jo�o Fernandes
 * \email  a20128@alunos.ipca.pt
 * \date   June 2022
 *********************************************************************/

#include <stdio.h>
#include "Dados.h"

 /**
 * @brief Cria uma nova Opera��o
 * @param [in] id		id da opera��o
 * @param [in] listamaquina		lista de m�quinas
 * @return	Opera��o
 */
Operacao* CriarOperacao(int id, ListaMaquina* listamaquina)
{
	Operacao* aux = (Operacao*)calloc(1, sizeof(Operacao));

	aux->id = id;
	aux->listamaquina = listamaquina;

	return aux;
}

/**
* @brief Cria uma lista de opera��es
* @param [in] operacao		opera��o
* @return	Lista de opera��es
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
* @brief Verifica se a opera��o existe
* @param [in] listaoperacao		lista de opera��es
* @param [in] id		id da opera��o
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
* @brief Inserir opera��o na lista
* @param [in] listaoperacao		lista de opera��es
* @param [in] novaoperacao		nova opera��o
* @return	Lista de opera��es 
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
* @brief Procura uma opera��o na lista
* @param [in] listaoperacao		lista de opera��es
* @param [in] id		id da opera��o
* @return	Opera��o
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
* @brief Altera os valores da opera��o
* @param [in] operacao		opera��o
* @param [in] idJob		id do job
* @param [in] idOp		id da opera��o
* @param [in] idMaq		id da m�quina
* @param [in] novoidMaq		novo id da m�quina
* @param [in] novoTempo		novo tempo da m�quina
* @return	Opera��o
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
* @brief Mostra os valores da opera��o
* @param [in] listaoperacao		lista de opera��es
* @return	Nada
*/
void MostrarListaOperacao(ListaOperacao* listaoperacao) 
{
	if (listaoperacao != NULL) 
	{
		printf("\nOperac�o: %d: \n", listaoperacao->operacao.id);
		MostrarListaMaquina(listaoperacao->operacao.listamaquina);
		
		while (listaoperacao->next != NULL) 
		{
			listaoperacao= listaoperacao->next;
			printf("\nOperac�o: %d: \n", listaoperacao->operacao.id);
			MostrarListaMaquina(listaoperacao->operacao.listamaquina);
		};
	}
}

/**
* @brief Remove uma opera��o
* @param [in] operacao		opera��o
* @param [in] idJob		id do job
* @param [in] idOp		id da opera��o
* @return	Opera��o
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
