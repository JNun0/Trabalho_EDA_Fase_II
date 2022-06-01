/*****************************************************************//**
 * \file   Dados.h
 * \brief  Trabalho Pr�tico EDA (Fase II) - Dados
 * 
 * \author Jo�o Fernandes
 * \email  a20128@alunos.ipca.pt
 * \date   June 2022
 *********************************************************************/

#ifndef BTREE
#define BTREE

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#pragma region Structs

/**
 * @brief Armazenamento de uma m�quina
 *
 * Uma m�quina cont�m um id (@@id) e tempo (@@tempo).
 */
typedef struct Maquina 
{
    int id;
    int tempo;
}Maquina;

/**
 * @brief Armazenamento de uma lista de m�quinas
 *
 * Uma lista de m�quinas cont�m uma estrutura Maquina(@@maquina) e um apontador para a pr�xima(@@next).
 */

typedef struct ListaMaquina 
{
    struct Maquina maquina;
    struct ListaMaquina* next;
}ListaMaquina;

/**
 * @brief Armazenamento de uma opera��o
 *
 * Uma opera��o cont�m um id (@@id) e uma lista de m�quinas (@@listamaquina).
 */

typedef struct Operacao 
{
    int id;
    struct ListaMaquina* listamaquina;
}Operacao;

/**
 * @brief Armazenamento de uma lista de opera��es
 *
 * Uma lista de opera��es cont�m uma estrutura Operacao(@@operacao) e um apontador para a pr�xima(@@next).
 */

typedef struct ListaOperacao 
{
    struct Operacao operacao;
    struct ListaOperacao* next;
}ListaOperacao;

/**
 * @brief Armazenamento de um job
 *
 * Um job cont�m um id(@@id) e como � uma �rvore bin�ria tem um apontador para a esquerda(@@left) e para a direita(@@right)
 */


typedef struct Job
{
    int id;
    struct ListaOperacao* listaoperacao;
    struct Job* left;
    struct Job* right;
}Job;

#pragma endregion

#pragma region Fun��es da �rvore (Jobs)

    Job* Esvaziar(Job* listajobs);
    Job* Inserir(Job* listajobs, int id, ListaOperacao* listaoperacao);
    Job* Min(Job* listajobs);
    Job* Max(Job* listajobs);
    Job* Procurar(Job* listajobs, int id);
    int Altura(Job* listajobs);
    Job* Apagar(Job* listajobs, int idJob, Operacao* operacao, int idOp);
    void PorOrdem(Job* listajobs);
    void MostrarListaJobs(Job* listajobs);

#pragma endregion

#pragma region Fun��es de M�quinas

    Maquina* CriarMaquina(int id, int tempo);
    ListaMaquina* CriarListaMaquina(Maquina* maquina);
    bool MaquinaExiste(ListaMaquina* listamaquina, int id);
    ListaMaquina* InserirListaMaquina(ListaMaquina* listamaquina, Maquina* novamaquina);
    Maquina* ProcurarMaquina(ListaMaquina* listamaquina, int id);
    Maquina* AlterarMaquina(Maquina* maquina, int novoidMaq, int novoTempo);
    void MostrarListaMaquina(ListaMaquina* listamaquina);


#pragma endregion

#pragma region Fun��es de Opera��es

    Operacao* CriarOperacao(int id, ListaMaquina* listamaquina);
    ListaOperacao* CriarListaOperacao(Operacao* operacao);
    bool OperacaoExiste(ListaOperacao* listaoperacao, int id);
    ListaOperacao* InserirListaOperacao(ListaOperacao* listaoperacao, Operacao* novaoperacao);
    Operacao* ProcurarOperacao(ListaOperacao* listaoperacoes, int id);
    Operacao* AlterarOperacao(Operacao* operacao, int idJob, int idOp, int idMaq, int novoidMaq, int novoTempo);
    void MostrarListaOperacao(ListaOperacao* listaoperacao);
    Operacao* RemoverOperacao(Operacao* operacao, int idJob, int idOp);

#pragma endregion

#pragma region Fun��es de Escalonamento

    Job* Escalonamento(Job* job);

#pragma endregion

#endif