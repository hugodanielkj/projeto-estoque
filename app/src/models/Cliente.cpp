#include "Cliente.h"

Cliente::Cliente(){}

std::string Cliente::getNome(){ return _nome; }
std::string Cliente::getAniversario(){ return _aniversario; }
int Cliente::getContato(){ return _contato; }

void Cliente::setNome(std::string nome){ _nome = nome; }
void Cliente::setAniversario(std::string aniversario){ _aniversario = aniversario; }
void Cliente::setContato(int contato){ _contato = contato; }