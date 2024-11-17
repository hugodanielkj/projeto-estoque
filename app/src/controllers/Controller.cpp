#include "../views/View.h"
#include "../models/Model.h"
#include "Controller.h"
#include <iostream>
#include <string>

Controller::Controller(View& view, Model& model){ _view = view; _model = model; }

void Controller::run(){
  int choice;
    do {
      _view.showMenu();
      _view.showMessage("Escolha uma opcao: ");
      std::cin >> choice;

      switch (choice)
      {
      case 1:{
        _model._estoque.exibir();
      }
      case 2:{
        std::string nome, tamanho;
        int quantidade;
        _view.askForDetails(nome, quantidade, tamanho);
        _model._roupa.criarRoupa(nome, quantidade, tamanho);  //Sem funcionalidade, precisa ser incluida no estoque
        _model._estoque.adicionarRoupa(nome, quantidade, tamanho);
        break;
      }
        break;
      default:
        break;
      }

    } while (choice != 3);
}