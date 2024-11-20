#include <sqlite3.h>
#include <string>

class Clientes{
  private:
    sqlite3* _db;

  public:
    Clientes();
    void conectarAoBanco();
    void adicionarCliente();
    void exibirAniversariantes(std::string data_hoje);
};