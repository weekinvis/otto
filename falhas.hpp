#ifndef _falhas_ot_h__
#define _falhas_ot_h__

/* Bibliotecas */
#include <iostream>

/* Codigos de erro */
#define SUCESSO                   0
#define ERRO_QUANTIDADE_ARGV      1
#define ERRO_EXTENSAO_ARQUIVO     1
#define ERRO_ARQUIVO_INALCANCAVEL 1
#define ERRO_SINTAXE_RUIM         1

/* Tipos Derivados */
typedef short int erro_t;

/* Funções exportadas */
void imprime_erro(const std::string&);
bool verifica_extensao(const char*);

#endif