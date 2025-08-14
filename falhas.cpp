#include "falhas.hpp"
#include <iostream>
#include <cstring>

void imprime_erro(const std::string& msg)
{
    std::cerr << "Erro: " << msg << std::endl;
}

bool verifica_extensao(const char * nome_arquivo)
{
    const char* ext = strrchr(nome_arquivo, '.');
    return ext && strcmp(ext, ".blm") == 0;

}
