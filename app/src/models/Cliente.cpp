#include "Cliente.h"
#include <string>

Cliente::Cliente(){}

std::string Cliente::getNome(){ return _nome; }

void Cliente::setNome(std::string nome){ _nome = nome; }