/* 
 * File:   NoLDE.h
 * Author: Daniel Enos e Digo Cirne
 *
 * Created on 28 de Setembro de 2009, 19:59
 */

#ifndef _NOLDE_H
#define	_NOLDE_H
#include "RegistroPessoa.h"


//! NoLDE.
/*!
 *  O tipo estrutura NoLDE tem como campos pessoa (do tipo RegistroPessoa),
 * *prox (do tipo NolDE) e *ante (do tipo NolDE).
*/
typedef struct NoLDE{  
    RegistroPessoa pessoa; //!< Informacao armazenada em um no
    NoLDE *prox; //!< Ponteiro para proximo da lista
    NoLDE *ante; //!< Ponteiro para anterior da lista
} NoLDE;

#endif	/* _NOLDE_H */

