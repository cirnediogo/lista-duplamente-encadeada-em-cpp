/* 
 * File:   ListaDuplamenteEncadeada.cpp
 * Author: ubuntu
 * 
 * Created on 28 de Setembro de 2009, 20:01
 */

#include "LDE.h"



//! listar.
/*!
 *
 * O método listar imprime todas as pessoas junto com suas informações da lista encadeada.
    \return void.
 */
void LDE::listar() {
    NoLDE *ptr = AIL->prox;
    if (length == 0) {
        cout << "Lista Vazia.\n\n";
    } else {
        cout << "Lista:\n";
    for (int i = 0; i < length; i++) {
        cout << "Matricula = " << (ptr->pessoa).matricula <<
                "; Nome = " << (ptr->pessoa).nome << ""
                "; Idade = " << (ptr->pessoa).idade << "\n";
        ptr = ptr->prox;
    };
    cout << "\n";
    }
}


//! buscaAux.
/*!
 *
 * O método buscaAux é um método auxiliar ultilizado dentro de outros métodos.
    \param mat é um elemento do tipo Chave.
    \return NoLDE*.
 */
NoLDE* LDE::buscaAux(Chave mat) {
    NoLDE *ultimo = AIL->ante;
    NoLDE *procurado = NULL;
    NoLDE *pont = NULL;
    (AIL->pessoa).matricula = mat + 1;
    if (mat <= (ultimo->pessoa).matricula) {
        pont = AIL->prox;
        while ((pont->pessoa).matricula < mat){
            pont = pont->prox;
        }
        procurado = pont;
    }
    else{
        procurado = AIL;
    }
    return procurado;
}

//! busca.
/*!
 *
 * O método busca procura uma determinada pessoa na lista, caso a encontre será imprimido
 * as informações (matricula, nome e idade) dela. Caso contrário, imprime uma mensagem
 * avisando que não está na lista.
    \param mat é um elemento do tipo Chave.
    \return void.
 */
void LDE::busca(Chave mat) {
    NoLDE* noProcurado = buscaAux(mat);
    if ((noProcurado->pessoa).matricula != mat) {
        cout << "Matricula nao esta na lista.\n\n";
    } else {
    cout << "Buscando matricula " << mat << "\n" <<
            "Pessoa procurada:\n";
    cout << "Matricula = " << (noProcurado->pessoa).matricula <<
                "; Nome = " << (noProcurado->pessoa).nome << ""
                "; Idade = " << (noProcurado->pessoa).idade << "\n\n";
    }
}

//! insere.
/*!
 *
 * O método insere é responsável por inserir uma pessoa na lista encadeada. Caso o elemento
 * a ser inserido na lista já exista, o método avisa o usuário disso.
    \param x é um elemento do tipo RegistroPessoa e representa a nova pessoa que será inserida na lista.
    \return void.
 */
void LDE::insere(RegistroPessoa x) {
    NoLDE* pt = NULL;
    NoLDE* anterior = NULL;
    NoLDE *pont = NULL;
    pont = buscaAux(x.matricula);
    if ((pont == AIL) || ((pont->pessoa).matricula != x.matricula))
    {
        anterior = pont->ante;
        pt = new NoLDE;
        pt->pessoa = x;
        pt->ante = anterior;
        pt->prox = pont;
        anterior->prox = pt;
        pont->ante = pt;
        length = length +1;
    }
    else
    {
        cout << "Elemento já está na lista.\n\n";
    }
}


//! removeAux.
/*!
 *
 * O método removeAux é um método auxiliar, que será uusado no remove, o qual remove uma matricula
 * (passada no argumento de entrada do método).  Caso o elemento
 * a ser inserido na lista não exista, o método avisa o usuário disso.
    \param mat é um elemento do tipo Chave que representa o número de matrícula de um aluno a ser removido.
    \return void.
 */
void LDE::removeAux(Chave mat) {
    NoLDE* posterior = NULL;
    NoLDE* anterior = NULL;
    NoLDE* pont = NULL;
    pont = buscaAux(mat);
    if ((pont != AIL) && ((pont->pessoa).matricula = mat)) {
        anterior = pont->ante;
        posterior = pont->prox;
        anterior->prox = posterior;
        posterior->ante = anterior;
        delete pont;
        length = length - 1;
    }
    else {
        cout << "Elemento nao se encontra na lista.\n\n";
    }
}

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
void LDE::remove(Chave a, Chave b) {
    cout << "Remover pessoa(s) entre matriculas " <<
            a << " e " << b << "\n\n";
    Chave menor;
    Chave maior;
    if (a <= b) {
        menor = a+1;
        maior = b;
    } else {
        menor = b+1;
        maior = a;
    };
    NoLDE* limInferior;
    while (menor < maior) {
        Chave proximo;
        limInferior = buscaAux(menor);
        proximo = ((limInferior->prox)->pessoa).matricula;
        removeAux(menor);
        menor = proximo;
    }
}



//! Construtor.
/*!
 * No Construtor gera um novo espaço de mémoria, o qual será denominado de AIL,
 * que guardará algo do tipo NoLDE. O AIL representará a cabeça da lista.
 * Como a lista é duplamente encadeada, teremos
 * que o elemente anterior da lista será o último e o próximo do último
 * será o primeiro. Como a lista inicia vazia, tanto os ponteiros ante quanto o
 * prox apontarão para o AIL.
*/
LDE::LDE() {
    cout << "Executando Construtor.\n\n";
    AIL = new NoLDE;
    AIL->ante = AIL->prox = AIL;
    length = 0;
}




//! Destrutor.
/*!
 * O destrutor da classe Lista sequencial temos um "cout" para comprovar a sua chamada
 * e a funcao "delete" para desalocar o espaco de memória ocupado pelo AIL.
*/
LDE::~LDE() {
    cout << "Executando Destrutor.\n\n";
    delete AIL;
}

