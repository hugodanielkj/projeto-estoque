#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>

class Cliente{
  public:
    //HistoricoDeCompra _historico;
    std::string _nome;
    std::string _aniversario;
    int _contato;
    
    Cliente();

    //Gets
    std::string getNome();
    std::string getAniversario();
    int getContato();

    //Sets
    void setNome(std::string nome);
    void setAniversario(std::string aniversario);
    void setContato(int contato);
};

#endif // CLIENTE_H