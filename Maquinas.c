/*****************************************************************//**
 * \file   Maquinas.c
 * \brief  Trabalho Pr�tico EDA (Fase II) - M�quinas
 * 
 * \author Jo�o Fernandes
 * \email  a20128@alunos.ipca.pt
 * \date   June 2022
 *********************************************************************/

#include <stdio.h>
#include "Dados.h"

 /**
 * @brief Cria uma m�quina
 * @param [in] id		id da m�quina
 * @param [in] tempo		tempo da m�quina
 * @return	m�quina
 */
Maquina* CriarMaquina(int id, int tempo)
{

	Maquina* aux = (Maquina*)calloc(1, sizeof(Maquina));

	aux->id = id;
	aux->tempo = tempo;

	return aux;
}

/**
* @brief Cria uma lista das m�quinas
* @param [in] maquina		M�quina
* @return	lista de m�quinas
*/
ListaMaquina* CriarListaMaquina(Maquina* maquina)
{

	ListaMaquina* novo = (ListaMaquina*)calloc(1, sizeof(ListaMaquina));

	novo->maquina.id = maquina->id;
	novo->maquina.tempo = maquina->tempo;
	novo->next = NULL;

	return novo;
}

/**
* @brief Verificar se a m�quina existe
* @param [in] listamaquina		lista de m�quinas
* @param [in] id		id da m�quina
* @return	true ou false
*/
bool MaquinaExiste(ListaMaquina* listamaquina, int id)
{

	if (listamaquina != NULL)
	{
		ListaMaquina* aux = listamaquina;

		while (aux != NULL)
		{
			if (aux->maquina.id == id)
			{
				return true;
			}
			aux = aux->next;
		}
	}

	return false;
}

/**
* @brief Inserir uma m�quina na lista
* @param [in] listamaquina		lista de m�quinas
* @param [in] novamaquina		m�quina nova
* @return	lista de m�quinas
*/
ListaMaquina* InserirListaMaquina(ListaMaquina* listamaquina, Maquina* novamaquina)
{

	if (novamaquina == NULL)
	{
		return listamaquina;
	}

	ListaMaquina* aux = CriarListaMaquina(novamaquina);

	if (MaquinaExiste(listamaquina, aux->maquina.id))
	{
		return listamaquina;
	}

	if (listamaquina == NULL)
	{
		listamaquina = aux;
	}
	else
	{

		ListaMaquina* tmp = listamaquina;

		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = aux;
	}

	return listamaquina;
}

/**
* @brief Procurar uma m�quina na lista
* @param [in] listamaquina		lista de m�quinas
* @param [in] id		id da m�quina
* @return	m�quina
*/
Maquina* ProcurarMaquina(ListaMaquina* listamaquina, int id) 
{
	ListaMaquina* aux = listamaquina;

	if (listamaquina != NULL) 
	{
		while (aux != NULL) 
		{
			if (aux->maquina.id == id) 
			{
				return (aux);
			}
			aux = aux->next;
		}
	}

	return NULL;
}

/**
* @brief Alterar valores da m�quina
* @param [in] maquina		m�quina
* @param [in] novoidMaq		novo id da m�quina
* @param [in] novoTempo		novo tempo da m�quina
* @return	m�quina
*/
Maquina* AlterarMaquina(Maquina* maquina, int novoidMaq, int novoTempo) 
{
	
	if (maquina != NULL) 
	{
		maquina->id = novoidMaq;
		maquina->tempo = novoTempo;
	}

	return maquina;
}

/**
* @brief Mostra os valores da m�quina
* @param [in] listamaquina		lista de m�quinas
* @return	Nada
*/
void MostrarListaMaquina(ListaMaquina* listamaquina) 
{
	if (listamaquina != NULL) 
	{
		printf("M�quina: %d | Tempo: %d\n", listamaquina->maquina.id, listamaquina->maquina.tempo);
		
		while (listamaquina->next != NULL) 
		{
			listamaquina = listamaquina->next;
			printf("M�quina: %d | Tempo: %d\n", listamaquina->maquina.id, listamaquina->maquina.tempo);
		};
	}
}