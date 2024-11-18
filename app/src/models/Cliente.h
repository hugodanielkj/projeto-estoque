#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>

class Cliente{
  private:
    std::string _nome;
    std::string _aniversario;
    //HistoricoDeCompra _historico;

  public:
    Cliente();

    //Gets
    std::string getNome();
    std::string getAniversario();

    //Sets
    void setNome(std::string nome);
};

#endif // CLIENTE_H