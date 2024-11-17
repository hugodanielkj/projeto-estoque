#ifndef ROUPA_H
#define ROUPA_H

#include <string>

class Roupa{
  private:
    std::string _nome;
    int _quantidade;
    std::string _tamanho;

  public:
    Roupa();

    //Gets
    std::string getNome();
    int getQuantidade();
    std::string getTamanho();

    //Sets
    void setNome(std::string nome);
    void setQuantidade(int quantidade);
    void setTamanho(std::string tamanho);

    //Methods
    void criarRoupa(std::string nome, int quantidade, std::string tamanho);
};

#endif // ROUPA_H