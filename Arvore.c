/*****************************************************************//**
 * \file   Arvore.c
 * \brief  Trabalho Prático EDA (Fase II) - Árvore
 * 
 * \author João Fernandes
 * \email  a20128@alunos.ipca.pt
 * \date   June 2022
 *********************************************************************/

#include <stdio.h>
#include "Dados.h"


 /**
 * @brief Esvaziar uma árvore
 * @param [in] listajobs		lista de  jobs
 * @return	Nada
 */
Job* Esvaziar(Job* listajobs)
{
    if (listajobs != NULL)
    {
        Esvaziar(listajobs->left);

        Esvaziar(listajobs->right);
        
        free(listajobs);
    }
    return NULL;
}

/**
* @brief Inserir na lista um job que contêm uma lista de operações
* @param [in] listajobs		lista de jobs
* @param [in] id		id do job
* @param [in] listaoperacao		lista de operações
* @return	lista de jobs
*/
Job* Inserir(Job* listajobs, int id, ListaOperacao* listaoperacao)
{
    if (listajobs == NULL)
    {
        //Calloc cria vários bloco de memória, malloc cria apenas um
        listajobs = (Job*)calloc(1, sizeof(Job));
        
        listajobs->id = id;
        
        listajobs->listaoperacao = listaoperacao;
        
        listajobs->left = listajobs->right = NULL;
    }
    else if (id < listajobs->id) 
    {
        listajobs->left = Inserir(listajobs->left, id, listaoperacao);
    }
    else if (id > listajobs->id)
    {
        listajobs->right = Inserir(listajobs->right, id, listaoperacao);
    }
    return listajobs;
}

/**
* @brief Encontrar o job de menor valor
* @param [in] listajobs		lista de jobs
* @return	o job de menor valor
*/
Job* Min(Job* listajobs)
{
    if (listajobs == NULL)
    {
        return NULL;
    }
    else if (listajobs->left == NULL)
    {
        return listajobs;
    }
    else
    {
        return Min(listajobs->left);
    }
}

/**
* @brief Encontrar o job de maior valor
* @param [in] listajobs		lista de jobs
* @return	o job de maior valor
*/

Job* Max(Job* listajobs)
{
    if (listajobs == NULL)
    {
        return NULL;
    }
    else if (listajobs->right == NULL)
    {
        return listajobs;
    }
    else
    {
        return Max(listajobs->right);
    }
}

/**
* @brief Procurar um job na lista
* @param [in] listajobs		lista de jobs
* @param [in] id	id do job
* @return	o job com o id selecionado
*/
Job* Procurar(Job* listajobs, int id)
{
    if (listajobs == NULL)
    {
        return NULL;
    }
    else if (id = listajobs->id)
    {
        return listajobs;
    }
    else if (id < listajobs->id)
    {
        return Procurar(listajobs->left, id);
    }
    else if (id > listajobs->id)
    {
        return Procurar(listajobs->right, id);
    }
    else
    {
        return listajobs;
    }
}

/**
* @brief Saber a altura da árvore
* @param [in] listajobs		lista de jobs
* @return	A altura da árvore
*/
int Altura(Job* listajobs)
{
    int lefth, righth;
    if (listajobs == NULL)
    {
        return -1;
    }
    lefth = Altura(listajobs->left);

    righth = Altura(listajobs->right);

    return (lefth > righth ? lefth : righth) + 1;
}

/**
* @brief Apagar um job e as operações incluidas nele
* @param [in] listajobs		lista de jobs
* @param [in] id	id do job
* @param [in] operacao	  operação
* @param [in] idOp	  id da operação
* @return	lista dos jobs
*/
Job* Apagar(Job* listajobs, int idJob, Operacao* operacao, int idOp)
{
    RemoverOperacao(operacao, idJob, idOp);
    Job* temp;
    if (listajobs == NULL)
    {
        return NULL;
    }
    else if (idJob < listajobs->id)
    {
        listajobs->left = Apagar(listajobs->left, idJob, operacao, idOp);
    }
    else if (idJob > listajobs->id)
    {
        listajobs->right = Apagar(listajobs->right, idJob, operacao, idOp);
    }
    else if (listajobs->left && listajobs->right)
    {
        temp = Min(listajobs->right);
        listajobs->id = temp->id;
        listajobs->right = Apagar(listajobs->right, listajobs->id, operacao, idOp);
    }
    else
    {
        temp = listajobs;
        if (listajobs->left == NULL)
        {
            listajobs = listajobs->right;
        }
        else if (listajobs->right == NULL)
        {
            listajobs = listajobs->left;
        }
        free(temp);
    }
    return listajobs;
}

/**
* @brief Mostra os jobs por ordem
* @param [in] listajobs		lista de jobs
* @return	lista dos jobs por ordem
*/
void PorOrdem(Job* listajobs)
{
    if (listajobs == NULL)
    {
        return;
    }
    PorOrdem(listajobs->left);

    printf("%d ", listajobs->id);

    PorOrdem(listajobs->right);
}

/**
* @brief Mostra os jobs e as operações e máquinas nele incluídas
* @param [in] listajobs		lista de jobs
* @return	lista dos jobs e as operações e máquinas nele incluídas
*/
void MostrarListaJobs(Job* listajobs)
{
    if (listajobs != NULL)
    {
        printf("\nJob: %d: \n", listajobs->id);
        MostrarListaOperacao(listajobs->listaoperacao);

        while (listajobs->left != NULL)
        {
            listajobs = listajobs->left;
            printf("\nJob: %d: \n", listajobs->id);
            MostrarListaOperacao(listajobs->listaoperacao);
        };

        while (listajobs->right != NULL)
        {
            listajobs = listajobs->right;
            printf("\nJob: %d: \n", listajobs->id);
            MostrarListaOperacao(listajobs->listaoperacao);
        };
    }
}

