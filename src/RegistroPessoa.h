/* 
 * File:   RegistroPessoa.h
 * Author: ubuntu
 *
 * Created on 2 de Outubro de 2009, 13:59
 */

#ifndef _REGISTROPESSOA_H
#define	_REGISTROPESSOA_H
#include "Chave.h"
#include <iostream>
using namespace std;


//! RegistroPessoa.
/*!
 * Aqui, é criado um tipo registro RegistoPessoa, no qual terá os campos
 * matricula (do tipo Chave), nome (do tipo string) e idade do tipo int.
*/
typedef struct RegistroPessoa {
    Chave matricula; //!< Representa a matrícula de um aluno.
    string nome; //!< Representa o nome do aluno.
    int idade; //!< Representa a idade de um aluno.
};

#endif	/* _REGISTROPESSOA_H */

