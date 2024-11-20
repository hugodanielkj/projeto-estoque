#include "Clientes.h"
#include <iostream>

Clientes::Clientes(){}

void Clientes::conectarAoBanco(){
  std::cout << "Preparando para conectar com clientes(bd)...\n";
  const std::string DB_PATH = "/home/hugo/projeto-estoque/app/src/data/clientes.db";
  
  int exit = sqlite3_open(DB_PATH.c_str(), &_db);
  if(exit){
    std::cerr << "Erro ao abrir banco de dados clientes: " << sqlite3_errmsg(_db) << std::endl;
    _db = nullptr;
  } else {
    std:: cout << "Conexao estabelecida com sucesso.\n";
  }
}

void Clientes::adicionarCliente(){
  std::string sql = "INSERT INTO clientes VALUES(?, ?);";

  std::string nome = "teste";
  std::string aniversario = "14/05/2014";

  sqlite3_stmt* stmt;
  if(sqlite3_prepare_v2(_db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK){
    std::cerr << "Erro ao preparar insercao: " << sqlite3_errmsg(_db) << std::endl;
    return;
  }

  if(sqlite3_bind_text(stmt, 1, nome.c_str(), -1, SQLITE_STATIC) != SQLITE_OK){
    std::cerr << "Erro ao fazer bind: " << sqlite3_errmsg(_db) << std::endl;
    return;
  }

  if(sqlite3_step(stmt) != SQLITE_DONE){
    std::cerr << "Erro ao executar comando no db: " << sqlite3_errmsg(_db) << std::endl;
    return;
  } else {
    std::cout << "Sucesso ao adicionar novo cliente no banco de dados" << std::endl;
  }
}

void Clientes::exibirAniversariantes(std::string data_hoje){
  std::cout << "sucesso ao entrar na funcao exibir aniversariantes." << std::endl;
  std::string sql = "SELECT nome FROM clientes WHERE aniversario = '"+ data_hoje +"';";

  sqlite3_stmt* stmt;
  if(sqlite3_prepare_v2(_db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK){
    std::cerr << "Erro ao fazer insercao: " << sqlite3_errmsg(_db) << std::endl;
    return;
  }

  std::cout << "-------------------------\n"; 
  std::cout << "ANIVERSARIANTES DO DIA:\n|";
  
  while(sqlite3_step(stmt) == SQLITE_ROW){
    std::string nome = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
    std::cout << nome << " |" << std::endl;
  }
  std::cout << "-------------------------\n";
  sqlite3_finalize(stmt); 
}