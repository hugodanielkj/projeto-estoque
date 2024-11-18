#include "Cliente.h"

Cliente::Cliente(){}

std::string Cliente::getNome(){ return _nome; }
std::string Cliente::getAniversario(){ return _aniversario; }

void Cliente::setNome(std::string nome){ _nome = nome; }