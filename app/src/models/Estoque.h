#ifndef ESTOQUE_H
#define ESTOQUE_H

#include <sqlite3.h>
#include <string>
#include "Roupa.h"

class Estoque{
  private:
    sqlite3* _db;

  public:
    Estoque();
    Estoque(sqlite3* db);
    void adicionarRoupa(const Roupa roupa);
    void alterarQuantidadeNumaRoupa(const std::string nome, const int valor_a_somar);
    void exibir();
    void exibirPorQuantidade();

};

#endif // ESTOQUE_H