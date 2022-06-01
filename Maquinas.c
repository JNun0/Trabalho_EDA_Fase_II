/*****************************************************************//**
 * \file   Maquinas.c
 * \brief  Trabalho Prático EDA (Fase II) - Máquinas
 * 
 * \author João Fernandes
 * \email  a20128@alunos.ipca.pt
 * \date   June 2022
 *********************************************************************/

#include <stdio.h>
#include "Dados.h"

 /**
 * @brief Cria uma máquina
 * @param [in] id		id da máquina
 * @param [in] tempo		tempo da máquina
 * @return	máquina
 */
Maquina* CriarMaquina(int id, int tempo)
{

	Maquina* aux = (Maquina*)calloc(1, sizeof(Maquina));

	aux->id = id;
	aux->tempo = tempo;

	return aux;
}

/**
* @brief Cria uma lista das máquinas
* @param [in] maquina		Máquina
* @return	lista de máquinas
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
* @brief Verificar se a máquina existe
* @param [in] listamaquina		lista de máquinas
* @param [in] id		id da máquina
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
* @brief Inserir uma máquina na lista
* @param [in] listamaquina		lista de máquinas
* @param [in] novamaquina		máquina nova
* @return	lista de máquinas
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
* @brief Procurar uma máquina na lista
* @param [in] listamaquina		lista de máquinas
* @param [in] id		id da máquina
* @return	máquina
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
* @brief Alterar valores da máquina
* @param [in] maquina		máquina
* @param [in] novoidMaq		novo id da máquina
* @param [in] novoTempo		novo tempo da máquina
* @return	máquina
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
* @brief Mostra os valores da máquina
* @param [in] listamaquina		lista de máquinas
* @return	Nada
*/
void MostrarListaMaquina(ListaMaquina* listamaquina) 
{
	if (listamaquina != NULL) 
	{
		printf("Máquina: %d | Tempo: %d\n", listamaquina->maquina.id, listamaquina->maquina.tempo);
		
		while (listamaquina->next != NULL) 
		{
			listamaquina = listamaquina->next;
			printf("Máquina: %d | Tempo: %d\n", listamaquina->maquina.id, listamaquina->maquina.tempo);
		};
	}
}