#include <iostream>
#include <sqlite3.h>
#include "models/Estoque.h"
#include "views/View.h"

int main(){
  std::cout << "Iniciando programa." << std::endl;
  View view;
  view.showMenu();
  Estoque estoque;
  estoque.exibir();
  return 0;
}