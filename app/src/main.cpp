#include <iostream>
#include <sqlite3.h>
#include <string>
#include "controllers/Controller.h"

int main(){
  std::cout << "Iniciando programa." << std::endl;
  View view;
  
  const std::string DB_PATH = "/home/hugo/projeto-estoque/app/src/data/database.db";

  sqlite3* db;
  int exit = sqlite3_open(DB_PATH.c_str(), &db);
  if(exit){
    std::cerr << "Erro ao abrir banco de dados clientes: " << sqlite3_errmsg(db) << std::endl;
    db = nullptr;
  } else {
    std:: cout << "Conexao estabelecida com sucesso.\n";
  }

  Clientes clientes(db);
  Cliente cliente;
  Estoque estoque(db);
  Roupa roupa;

  Controller controller(view, clientes, cliente, estoque, roupa);
  controller.run();
  return 0;
}

/*
//std::cout << "Preparando para conectar com clientes(bd)...\n";
const std::string DB_PATH = "/home/hugo/projeto-estoque/app/src/data/database.db";

int exit = sqlite3_open(DB_PATH.c_str(), &_db);
if(exit){
  std::cerr << "Erro ao abrir banco de dados clientes: " << sqlite3_errmsg(_db) << std::endl;
  _db = nullptr;
} else {
  std:: cout << "Conexao estabelecida com sucesso.\n";
}

Clientes::Clientes(sqlite3** db){
  _db = db;
}

*/