#include "Estoque.h"
#include <iostream>

Estoque::Estoque(){}

void Estoque::conectarAoBanco(){
  std::cout << "Preparando para conectar com o estoque..." << std::endl;
  const std::string DB_PATH = "/home/hugo/projeto-estoque/app/src/data/estoque.db"; 

  int exit = sqlite3_open(DB_PATH.c_str(), &_db);
  if(exit){
    std::cerr << "Erro ao abrir banco de dados: " << sqlite3_errmsg(_db) << std::endl;
    _db = nullptr;
  } else {
    std::cout << "Conexao estabelecida com sucesso." << std::endl;
  }
}

void Estoque::adicionarRoupa(const Roupa roupa){
  //int id = sqlite3_last_insert_rowid(_db) + 1; (descobrir por que nao funcionava)
  std::string sql = "INSERT INTO estoque (nome, quantidade, tamanho) VALUES('" + roupa._nome + "', " + std::to_string(roupa._quantidade) +", '" + roupa._tamanho + "');";

  char* mensagemErro = nullptr;
  int exit = sqlite3_exec(_db, sql.c_str(), 0, 0, &mensagemErro);
  if(exit != SQLITE_OK){
    std::cerr << "Erro para adicionar roupa: " << mensagemErro << std::endl;
    sqlite3_free(mensagemErro);
  } else {
    std::cout << "Roupa adicionada com sucesso!" << std::endl;
  }
}

void Estoque::alterarQuantidadeNumaRoupa(const std::string nome, const int valor_a_somar){
  std::string sql = "SELECT quantidade FROM estoque WHERE nome = ?;";

  sqlite3_stmt* stmt;
  if(sqlite3_prepare_v2(_db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK){
    std::cerr << "Erro ao preparar statement: " << sqlite3_errmsg(_db) << std::endl;
    return;
  }

  if(sqlite3_bind_text(stmt, 1, nome.c_str(), -1, SQLITE_STATIC) != SQLITE_OK){
    std::cerr << "Erro ao dar bind_text: " << sqlite3_errmsg(_db) << std::endl;
    sqlite3_finalize(stmt);
    return;
  }

  int quantidadeAtual = 0;
  if(sqlite3_step(stmt) == SQLITE_ROW) {
    quantidadeAtual = sqlite3_column_int(stmt, 0);
  } else {
    std::cerr << "Erro ao selecionar linha: " << sqlite3_errmsg(_db) << std::endl;
    sqlite3_finalize(stmt);
    return;
  }
  sqlite3_finalize(stmt);

  int novaQuantidade = quantidadeAtual + valor_a_somar;

  std::string sqlUpdate = "UPDATE estoque SET quantidade = ? WHERE nome = ?;";

  if(sqlite3_prepare_v2(_db, sqlUpdate.c_str(), -1, &stmt, nullptr) != SQLITE_OK){
    std::cerr << "Erro ao preparar statement: " << sqlite3_errmsg(_db) << std::endl;
    return;
  }

  if(sqlite3_bind_int(stmt, 1, novaQuantidade) != SQLITE_OK){
    std::cerr << "Erro ao dar bind_text: " << sqlite3_errmsg(_db) << std::endl;
    sqlite3_finalize(stmt);
    return;
  }

  if(sqlite3_bind_text(stmt, 2, nome.c_str(), -1, SQLITE_STATIC) != SQLITE_OK){
    std::cerr << "Erro ao dar bind_text: " << sqlite3_errmsg(_db) << std::endl;
    sqlite3_finalize(stmt);
    return;
  }

  if(sqlite3_step(stmt) != SQLITE_DONE){
    std::cerr << "Erro ao atualizar valor: " << sqlite3_errmsg(_db) << std::endl;
    sqlite3_finalize(stmt);
    return;
  } else {
    std::cout << "Valor atualizado com sucesso!" << std::endl;
  }
  sqlite3_finalize(stmt);
}

void Estoque::exibir(){
  std::string sql = "SELECT * FROM estoque;";

  sqlite3_stmt* stmt;
  if(sqlite3_prepare_v2(_db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK){
    std::cerr << "Erro ao fazer insercao: " << sqlite3_errmsg(_db) << std::endl;
    return;
  }

  std::cout << "Estoque atual: \n";
  std::cout << "-----------------------------------\n";
  std::cout << "Nome    | Quantidade    | Tamanho\n";
  std::cout << "-----------------------------------\n";

  while(sqlite3_step(stmt) == SQLITE_ROW){

    std::string nome = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
    const int quantidade = sqlite3_column_int(stmt, 2);
    std::string tamanho = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));

    std::cout << nome << " " << quantidade << " " << tamanho << std::endl;
    std::cout << "-------------------------------------" << std::endl;
  }
  sqlite3_finalize(stmt);
}

void Estoque::organizar(){}