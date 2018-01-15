/* 
 * File:   main.cpp
 * Author: ubuntu
 *
 * Created on 26 de Setembro de 2009, 09:55
 */

#include <stdlib.h>
#include "LDE.h"

/*
 * 
 */


/**
 * A funcao main, a primeira funcao a ser chamada,
 * instancia o objeto LDE da classe RegistroPessoa
 * Também foram criadas variáveis (alberto, gustavo, marina e rodrigo)
 * do tipo RegistroPessoa e, logo, em seguida, atribuído os campos:
 * matricula, nome e idade a eles.
 * Após isso, os métodos da classe LDE são usados, comprovando a veracidade
 * da suas respectivas perfeitas fucionalidades.
   \return int
 */
int main(int argc, char** argv) {

    cout << "Iniciando Lista Duplamente Encadeada.\n\n";
    LDE listadupla;
    RegistroPessoa alberto;
    alberto.matricula = 169;
    alberto.nome = "Alberto";
    alberto.idade = 23;
    RegistroPessoa gustavo;
    gustavo.matricula = 130;
    gustavo.nome = "Gustavo";
    gustavo.idade = 46;
    RegistroPessoa mariana;
    mariana.matricula = 196;
    mariana.nome = "Mariana";
    mariana.idade = 30;
    RegistroPessoa rodrigo;
    rodrigo.matricula = 111;
    rodrigo.nome = "Rodrigo";
    rodrigo.idade = 37;
    listadupla.insere(rodrigo);
    listadupla.insere(mariana);
    listadupla.insere(gustavo);
    listadupla.insere(alberto);
    listadupla.listar();
    listadupla.remove(123, 170);
    listadupla.listar();
    listadupla.busca(196);

    return (EXIT_SUCCESS);
}

