/* Bibliotecas */
#include "falhas.hpp"
#include "otto.hpp"
#include <string>
#include <fstream>

/* Hello !*/

int main(int argc, char* argv[])
{
    if(argc != 2)
    {
        imprime_erro("Uso: ./otto [arquivo].blm.");
        return ERRO_QUANTIDADE_ARGV;
    }

    if(!verifica_extensao(argv[1]))
    {
        imprime_erro("Arquivo com extensao invalida.");
        return ERRO_EXTENSAO_ARQUIVO;
    }
    
    std::ifstream arquivo_blm(argv[1]);

    if(!arquivo_blm)
    {
        imprime_erro("Arquivo nao encontrado.");
        return ERRO_ARQUIVO_INALCANCAVEL;
    }

    std::string linha;
    while(std::getline(arquivo_blm, linha))
    {
        erro_t erro;

        erro = processa_linha(truncador(linha));

        if(erro)
        {
            return erro;
        }
    }

    return SUCESSO;
}
