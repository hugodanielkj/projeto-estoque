#include "View.h"
#include <iostream>

void View::showMessage(const std::string& message){
  std::cout << message << std::endl;
}
void View::showMenu(){
  std::cout << "Menu de acoes:" << std::endl;
  std::cout << "1. Exibir informacoes de estoque." << std::endl;
  std::cout << "2. Exibir informacoes de clientes." << std::endl;
  std::cout << "3. Adicionar uma roupa ao estoque." << std::endl;
  std::cout << "4. Cadastrar novo cliente." << std::endl;
  std::cout << "5. Alterar a quantidade de pecas de um produto." << std::endl;
  std::cout << "6. Exibir clientes db." << std::endl;
  std::cout << "7. Fechar aplicativo." << std::endl;
}
void View::askForProductDetails(std::string& nome, int& quantidade, std::string& tamanho){
  std::cout << "Digite o nome da roupa: ";
  std::cin >> nome;
  std::cout << "Digite a quantidade de pecas dessa roupa: ";
  std::cin >> quantidade;
  std::cout << "Digite o tamanho dessas pecas: ";
  std::cin >> tamanho;
}

void View::askForClientsDetails(std::string& nome, std::string& aniversario, long int& contato){
  std::cout << "Digite o nome do cliente: ";
  std::cin >> nome;
  std::cout << "Digite o aniversario (ex:03/04/2014): ";
  std::cin >> aniversario;
  std::cout << "Digite o contato do cliente (ex:32972211343): ";
  std::cin >> contato;
}