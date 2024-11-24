#include <sqlite3.h>
#include <string>
#include "Cliente.h"

class Clientes{
  private:
    sqlite3* _db;

  public:
    Clientes();
    Clientes(sqlite3* db);
    void adicionarCliente(Cliente cliente);
    void exibirAniversariantes(std::string data_hoje);
    void exibirInfoCliente(std::string nome);
};