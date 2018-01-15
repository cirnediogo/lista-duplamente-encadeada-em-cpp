/* 
 * File:   ListaDuplamenteEncadeada.h
 * Author: ubuntu
 *
 * Created on 28 de Setembro de 2009, 20:01
 */

#ifndef _LDE_H
#define	_LDE_H
#include "NoLDE.h"
#include <iostream>
using namespace std;

class LDE {
public:


    //! listar.
/*!
 *
 * O método listar imprime todas as pessoas junto com suas informações da lista encadeada.
    \return void.
 */
    void listar();


    //! busca.
/*!
 *
 * O método busca procura uma determinada pessoa na lista, caso a encontre será imprimido
 * as informações (matricula, nome e idade) dela. Caso contrário, imprime uma mensagem
 * avisando que não está na lista.
    \param mat é um elemento do tipo Chave.
    \return void.
 */
    void busca(Chave mat);


    //! remove.
/*!
 *
 * O método remove é responsável por remover as matrículas entre o um determinado intervalo
 * de matrículas dado (passado pelo os argumentos de entradas do método). Ou seja, ele remove as matrículas
 * entre dois números de matrículas.
    \param a é um elemento do tipo Chave e representa o limite inferior do intervalo das matriculas que serão removidas.
    \param b é um elemento do tipo Chave e representa o limite superior do intervalo das matriculas que serão removidas.
    \return void.
 */
    void remove(Chave a, Chave b);

    //! removeAux.
/*!
 *
 * O método removeAux é um método auxiliar, que será uusado no remove, o qual remove uma matricula
 * (passada no argumento de entrada do método).  Caso o elemento
 * a ser inserido na lista não exista, o método avisa o usuário disso.
    \param mat é um elemento do tipo Chave que representa o número de matrícula de um aluno a ser removido.
    \return void.
 */
    void removeAux(Chave mat);

    //! insere.
/*!
 *
 * O método insere é responsável por inserir uma pessoa na lista encadeada. Caso o elemento
 * a ser inserido na lista já exista, o método avisa o usuário disso.
    \param x é um elemento do tipo RegistroPessoa e representa a nova pessoa que será inserida na lista.
    \return void.
 */
    void insere(RegistroPessoa x);

    //! buscaAux.
/*!
 *
 * O método buscaAux é um método auxiliar ultilizado dentro de outros métodos.
    \param mat é um elemento do tipo Chave.
    \return NoLDE*.
 */
    NoLDE* buscaAux(Chave mat);


    //! Construtor.
/*!
 * O Construtor gera um novo espaço de mémoria, o qual será denominado de AIL,
 * que guardará algo do tipo NoLDE. O AIL representará a cabeça da lista.
 * Como a lista é duplamente encadeada, teremos
 * que o elemente anterior da lista será o último e o próximo do último
 * será o primeiro. Como a lista inicia vazia, tanto os ponteiros ante quanto o
 * prox apontarão para o AIL.
*/
    LDE();


    //! Destrutor.
/*!
 * O destrutor da classe Lista sequencial temos um "cout" para comprovar a sua chamada
 * e a funcao "delete" para desalocar o espaco de memória ocupado pelo AIL.
*/
    virtual ~LDE();
private:

      /** Na classe LDE foram declaradas as variaveis privadas length e AIL.Essas
     * variaveis são reconhecidas por todos os metodos da classe LDE.*/
    int length;
    NoLDE *AIL;

};

#endif	/* _LDE_H */

