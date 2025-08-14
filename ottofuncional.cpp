#include <iostream>
#include <unordered_map>
#include "ottofuncional.hpp"
#include "falhas.hpp"
#include <functional>
#include <string>

std::unordered_map<std::string, int> variaveis;

int obter_valor(const std::vector<std::string>& tokens, size_t& pos) {
    std::string tok = tokens[pos++];
    if (isdigit(tok[0])) {
        return std::stoi(tok);
    } else if (variaveis.count(tok)) {
        return variaveis[tok];
    } else {
        imprime_erro("Variavel desconhecida ou valor invalido.");
        exit(1);
    }
}

// Lida com * e /
int obter_expressao_alta_prioridade(const std::vector<std::string>& tokens, size_t& pos) {
    int resultado = obter_valor(tokens, pos);

    while (pos < tokens.size()) {
        std::string operacao = tokens[pos];
        if (operacao == "*") {
            pos++;
            resultado *= obter_valor(tokens, pos);
        } else if (operacao == "/") {
            pos++;
            resultado /= obter_valor(tokens, pos);
        } else {
            break;
        }
    }
    return resultado;
}

// Lida com + e -
int obter_valores(const std::vector<std::string>& tokens, size_t& pos) {
    int resultado = obter_expressao_alta_prioridade(tokens, pos);

    while (pos < tokens.size()) {
        std::string operacao = tokens[pos];

        if(operacao == "+") {
            pos++;
            resultado += obter_expressao_alta_prioridade(tokens, pos);
        } else if(operacao == "-") {
            pos++;
            resultado -= obter_expressao_alta_prioridade(tokens, pos);
        } else {
            break;
        }
    }

    return resultado;
}

static void func_assign(const std::vector<std::string>& args) {
    if(args.size() < 4 || args[2] != "=") {
        imprime_erro("Sintaxe invalida para operacao de igualdade.");
        return;
    }
    std::string var = args[1];
    size_t pos = 3;
    int valor = obter_valores(args, pos);
    variaveis[var] = valor;

    return;

}

static void func_show(const std::vector<std::string>& args) {
    size_t pos = 1;
    int valor = obter_valores(args, pos);
    std::cout << valor << "\n";
}

static const std::unordered_map<std::string, std::function<void(const std::vector<std::string>&)>> comandos = 
{
    {"assign", func_assign},
    {"show", func_show}
};

bool chamar(const std::vector<std::string>& tokens) 
{
    auto ref_comando = comandos.find(tokens[0]);

    ref_comando->second(tokens); 

    return true;

}

bool verificar_existencia_comando(const std::string& comando)
{

    return !(comandos.find(comando) == comandos.end());

}