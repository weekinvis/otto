#ifndef _ottofuncional_hpp__
#define _ottofuncional_hpp__

#include <unordered_map>
#include <iostream>
#include <vector>

extern std::unordered_map<std::string, int> variaveis;

bool chamar(const std::vector<std::string>&);
bool verificar_existencia_comando(const std::string&);

#endif