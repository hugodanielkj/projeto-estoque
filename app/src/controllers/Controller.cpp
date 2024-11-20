#include "../views/View.h"
#include "../models/Model.h"
#include "Controller.h"
#include <iostream>
#include <string>

Controller::Controller(View& view, Model& model){ _view = view; _model = model; }

void Controller::run(){
  //Avisar sobre clientes aniversariantes
  _model._clientes.exibirAniversariantes("14/05/2014");
  std::cout << "teste" << std::endl;
  int choice;
    do {
      //Controller inicia:
      _view.showMenu();
      _view.showMessage("Escolha uma opcao: ");
      std::cin >> choice;

      switch (choice)
      {
      case 1:{
        _model._estoque.exibir();
        break;
      }
      case 2:{
        std::string nome, tamanho; int quantidade;
        _view.askForDetails(nome, quantidade, tamanho);   //Seta valores para nome, quantidade, tamanho via terminal
        Roupa roupa(_model._roupa);
        if(roupa.criarRoupa(nome, quantidade, tamanho) != 0){   //Retorna 0 a nova roupa foi criada
          std::cout << "Nao foi possivel inserir nova roupa." << std::endl;
          break;
        }
        //std::cout << roupa._nome << roupa._quantidade << roupa._tamanho << std::endl;
        _model._estoque.adicionarRoupa(roupa);
        break;
      }
      case 4:{
        _model._clientes.exibirAniversariantes("14/05/2014");
        break;
      }
      default:
        break;
      }

    } while (choice != 5);
}