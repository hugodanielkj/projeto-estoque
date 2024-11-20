#include "Roupa.h"
#include <iostream>

Roupa::Roupa(){};

//Gets
std::string Roupa::getNome(){ return _nome; }
int Roupa::getQuantidade(){ return _quantidade; }
std::string Roupa::getTamanho(){ return _tamanho; }

//Sets
void Roupa::setNome(std::string nome){
  if(nome.length() > 15)
    std::cerr << "Erro! Nome da roupa com muitos caracteres(lim=15)." << std::endl;
  else
    _nome = nome;
}

void Roupa::setQuantidade(int quantidade){
  if(quantidade < 0)
    std::cerr << "Erro! Numero invalido." << std::endl;
  else
    _quantidade = quantidade;
}

void Roupa::setTamanho(std::string tamanho){ _tamanho = tamanho; }

int Roupa::criarRoupa(std::string nome, int quantidade, std::string tamanho){
  setNome(nome);
  setQuantidade(quantidade);
  setTamanho(tamanho);
  if(_nome == nome && _quantidade == quantidade && _tamanho == tamanho)
    return 0;
  return 1;
}