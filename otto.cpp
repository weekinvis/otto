#include "ottofuncional.hpp"
#include "falhas.hpp"
#include <unordered_map>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

static std::vector<std::string> obter_tokens(const std::string& comando_truncado) {
    std::istringstream ss(comando_truncado);
    std::vector<std::string> tokens;
    std::string token;

    while(ss >> token) {
        tokens.push_back(token);
    }

    return tokens;

}

std::string truncador(const std::string& linha) {
    // Primeira ocorrencia de algo que nao seja um separador de espacos
    size_t indice_primeiro = linha.find_first_not_of(" \t\n\r");
    size_t indice_ultimo = linha.find_last_not_of(" \t\n\r");

    if(indice_primeiro == std::string::npos) {
        return "";
    }

    return linha.substr(indice_primeiro, indice_ultimo - indice_primeiro + 1);

}

erro_t processa_linha(const std::string& comando_truncado) {
    std::vector<std::string> tokens = obter_tokens(comando_truncado);
    if(tokens.empty()) return SUCESSO;

    if(verificar_existencia_comando(tokens[0])) {
        chamar(tokens);
    } else {
        imprime_erro("Sintaxe ruim, comando nao encontrado.");
        return ERRO_SINTAXE_RUIM;
    }

    return SUCESSO;

}