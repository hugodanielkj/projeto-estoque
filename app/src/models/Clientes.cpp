#include "Clientes.h"
#include <iostream>

Clientes::Clientes(){}

Clientes::Clientes(sqlite3* db){ _db = db; }

void Clientes::adicionarCliente(Cliente cliente){
  std::string sql = "INSERT INTO clientes (produto, quantidade, numero_vendas) VALUES(?, ?, ?);";

  sqlite3_stmt* stmt;
  if(sqlite3_prepare_v2(_db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK){
    std::cerr << "Erro ao preparar insercao: " << sqlite3_errmsg(_db) << std::endl;
    return;
  }

  if(sqlite3_bind_text(stmt, 1, cliente._nome.c_str(), -1, SQLITE_STATIC) != SQLITE_OK){
    std::cerr << "Erro ao fazer bind: " << sqlite3_errmsg(_db) << std::endl;
    return;
  }

  if(sqlite3_bind_text(stmt, 2, cliente._aniversario.c_str(), -1, SQLITE_STATIC) != SQLITE_OK){
    std::cerr << "Erro ao fazer bind: " << sqlite3_errmsg(_db) << std::endl;
    return;
  }

  if(sqlite3_bind_int(stmt, 3, cliente._contato) != SQLITE_OK){
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
  std::string sql = "SELECT nome FROM clientes WHERE aniversario = '"+ data_hoje +"';";

  sqlite3_stmt* stmt;
  if(sqlite3_prepare_v2(_db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK){
    std::cerr << "Erro ao fazer insercao: " << sqlite3_errmsg(_db) << std::endl;
    return;
  }

  std::cout << "-------------------------\n"; 
  std::cout << "ANIVERSARIANTES DO DIA:\n|";
  
  bool existeAniversariante = false;
  while(sqlite3_step(stmt) == SQLITE_ROW){
    std::string nome = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0));
    std::cout << nome << " |" << std::endl;
    existeAniversariante = true;
  }

  if(!existeAniversariante)
    std::cout << "Nao ha aniversariantes hoje|" << std::endl;

  std::cout << "-------------------------\n";
  sqlite3_finalize(stmt); 
}

void Clientes::exibirInfoCliente(std::string nome){
  std::string sql = "SELECT "+ nome +" FROM clientes";

  sqlite3_stmt* stmt;
  if(sqlite3_prepare_v2(_db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK){
    std::cerr << "Erro ao fazer insercao: " << sqlite3_errmsg(_db) << std::endl;
    return;
  }

  std::string aniversario;
  long int contato;

  if(sqlite3_step(stmt) == SQLITE_ROW){
    aniversario = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
    contato = sqlite3_column_int(stmt, 3);
  }

  std::cout << "-------------------------------" << std::endl;
  std::cout << "Nome   |Aniversario    |Contato" << std::endl;
  std::cout << "-------------------------------" << std::endl;
  std::cout << nome << " " << aniversario << " " << contato << std::endl;
}