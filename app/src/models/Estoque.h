#include <sqlite3.h>
#include <iostream>
#include <string>

class Estoque{
  private:
    sqlite3* _db;

  public:
    Estoque(){}
    void adicionarRoupa(sqlite3* db, const std::string nome, const int quantidade, const std::string tamanho){}
    void alterarQuantidadeNumaRoupa(sqlite3* db, const std::string nome, const int valor_a_somar){}
    void exibir(){}
    void organizar(){}

};