#include "View.h"
#include <iostream>

void View::showMessage(const std::string& message){
  std::cout << message << std::endl;
}
void View::showMenu(){
  std::cout << "Menu de acoes:" << std::endl;
  std::cout << "1. Exibir estoque." << std::endl;
  std::cout << "2. Adicionar uma roupa ao estoque." << std::endl;
  std::cout << "3. Alterar a quantidade de pecas de um produto." << std::endl;
  std::cout << "4. Exibir clientes db." << std::endl;
  std::cout << "5. Fechar aplicativo." << std::endl;
}
void View::askForDetails(std::string& nome, int& quantidade, std::string& tamanho){
  std::cout << "Digite o nome da roupa: ";
  std::cin >> nome;
  std::cout << "Digite a quantidade de pecas dessa roupa: ";
  std::cin >> quantidade;
  std::cout << "Digite o tamanho dessas pecas: ";
  std::cin >> tamanho;
}