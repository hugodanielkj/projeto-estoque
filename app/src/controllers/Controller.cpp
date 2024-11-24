#include "../views/View.h"
#include "Controller.h"
#include <iostream>
#include <string>

Controller::Controller(View& view, Clientes& clientes, Cliente& cliente, Estoque& estoque, Roupa& roupa){
  _view = view;
  _clientes = clientes;
  _cliente = cliente;
  _estoque = estoque;
  _roupa  = roupa;
}

void Controller::run(){
  //Avisar sobre clientes aniversariantes
  _clientes.exibirAniversariantes("14/05/2014");
  int choice;
    do {
      //Controller inicia:
      _view.showMenu();
      _view.showMessage("Escolha uma opcao: ");
      std::cin >> choice;

      switch (choice)
      {
      case 1:{
        _estoque.exibir();
        break;
      }
      case 2:{
        std::string nome;
        _view.showMessage("Coloque o nome do cliente que se quer informacoes: ");
        std::cin >> nome;
        //_clientes.exibirInfoCliente(nome);
      }
      case 3:{
        std::string nome, tamanho; int quantidade;
        _view.askForProductDetails(nome, quantidade, tamanho);   //Seta valores para nome, quantidade, tamanho via terminal
        Roupa roupa(_roupa);
        if(roupa.criarRoupa(nome, quantidade, tamanho) != 0){   //Retorna 0 a nova roupa foi criada
          std::cout << "Nao foi possivel inserir nova roupa." << std::endl;
          break;
        }
        //std::cout << roupa._nome << roupa._quantidade << roupa._tamanho << std::endl;
        _estoque.adicionarRoupa(roupa);
        break;
      }
      case 4:{
        //Exibe nome, aniversario e contato; Dado o nome do cliente
        std::string nome, aniversario; long int contato;
        _view.askForClientsDetails(nome, aniversario, contato);
        _cliente.setNome(nome);
        _cliente.setAniversario(aniversario);
        _cliente.setContato(contato);
        _clientes.adicionarCliente(_cliente);
        break;
      }
      default:
        break;
      }

    } while (choice != 7);
}