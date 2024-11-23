#include <iostream>
#include <sqlite3.h>
#include <string>
#include "controllers/Controller.h"

int main(){
  std::cout << "Iniciando programa." << std::endl;
  View view;
  Clientes clientes;
  Estoque estoque;
  clientes.conectarAoBanco();
  estoque.conectarAoBanco();
  Controller controller(view);
  controller.run();
  return 0;
}