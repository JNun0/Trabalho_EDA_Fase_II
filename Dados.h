/*****************************************************************//**
 * \file   Dados.h
 * \brief  Trabalho Prático EDA (Fase II) - Dados
 * 
 * \author João Fernandes
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
 * @brief Armazenamento de uma máquina
 *
 * Uma máquina contêm um id (@@id) e tempo (@@tempo).
 */
typedef struct Maquina 
{
    int id;
    int tempo;
}Maquina;

/**
 * @brief Armazenamento de uma lista de máquinas
 *
 * Uma lista de máquinas contêm uma estrutura Maquina(@@maquina) e um apontador para a próxima(@@next).
 */

typedef struct ListaMaquina 
{
    struct Maquina maquina;
    struct ListaMaquina* next;
}ListaMaquina;

/**
 * @brief Armazenamento de uma operação
 *
 * Uma operação contêm um id (@@id) e uma lista de máquinas (@@listamaquina).
 */

typedef struct Operacao 
{
    int id;
    struct ListaMaquina* listamaquina;
}Operacao;

/**
 * @brief Armazenamento de uma lista de operações
 *
 * Uma lista de operações contêm uma estrutura Operacao(@@operacao) e um apontador para a próxima(@@next).
 */

typedef struct ListaOperacao 
{
    struct Operacao operacao;
    struct ListaOperacao* next;
}ListaOperacao;

/**
 * @brief Armazenamento de um job
 *
 * Um job contêm um id(@@id) e como é uma árvore binária tem um apontador para a esquerda(@@left) e para a direita(@@right)
 */


typedef struct Job
{
    int id;
    struct ListaOperacao* listaoperacao;
    struct Job* left;
    struct Job* right;
}Job;

#pragma endregion

#pragma region Funções da árvore (Jobs)

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

#pragma region Funções de Máquinas

    Maquina* CriarMaquina(int id, int tempo);
    ListaMaquina* CriarListaMaquina(Maquina* maquina);
    bool MaquinaExiste(ListaMaquina* listamaquina, int id);
    ListaMaquina* InserirListaMaquina(ListaMaquina* listamaquina, Maquina* novamaquina);
    Maquina* ProcurarMaquina(ListaMaquina* listamaquina, int id);
    Maquina* AlterarMaquina(Maquina* maquina, int novoidMaq, int novoTempo);
    void MostrarListaMaquina(ListaMaquina* listamaquina);


#pragma endregion

#pragma region Funções de Operações

    Operacao* CriarOperacao(int id, ListaMaquina* listamaquina);
    ListaOperacao* CriarListaOperacao(Operacao* operacao);
    bool OperacaoExiste(ListaOperacao* listaoperacao, int id);
    ListaOperacao* InserirListaOperacao(ListaOperacao* listaoperacao, Operacao* novaoperacao);
    Operacao* ProcurarOperacao(ListaOperacao* listaoperacoes, int id);
    Operacao* AlterarOperacao(Operacao* operacao, int idJob, int idOp, int idMaq, int novoidMaq, int novoTempo);
    void MostrarListaOperacao(ListaOperacao* listaoperacao);
    Operacao* RemoverOperacao(Operacao* operacao, int idJob, int idOp);

#pragma endregion

#pragma region Funções de Escalonamento

    Job* Escalonamento(Job* job);

#pragma endregion

#endif