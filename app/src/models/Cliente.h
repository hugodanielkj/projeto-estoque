#include <string>

class Cliente{
  private:
    std::string _nome;
    HistoricoDeCompra _historico;

  public:
    Cliente(){};

    //Gets
    std::string getNome(){}

    //Sets
    void Cliente::setNome(std::string nome){}
};