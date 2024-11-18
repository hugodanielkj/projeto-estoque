#ifndef ESTOQUE_H
#define ESTOQUE_H

#include <sqlite3.h>
#include <string>

class Estoque{
  private:
    sqlite3* _db;

  public:
    Estoque();
    void adicionarRoupa(const std::string nome, const int quantidade, const std::string tamanho);
    void alterarQuantidadeNumaRoupa(const std::string nome, const int valor_a_somar);
    void exibir();
    void organizar();

};

#endif // ESTOQUE_H