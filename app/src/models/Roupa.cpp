#include "Roupa.h"
#include <iostream>

Roupa::Roupa(std::string nome, int quantidade, std::string tamanho){
  _nome = nome;
  _quantidade = quantidade;
  _tamanho = tamanho;
}

//Gets
std::string Roupa::getNome(){ return _nome; }
int Roupa::getQuantidade(){ return _quantidade; }
std::string Roupa::getTamanho(){ return _tamanho; }

//Sets
void Roupa::setNome(std::string nome){
  if(nome.length() > 12)
    std::cerr << "Erro! Nome da roupa com muitos caracteres." << std::endl;
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

