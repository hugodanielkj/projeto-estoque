#include "../views/View.h"
#include "../models/Model.h"
#include <iostream>

Controller::Controller(View& view, Model& model){ _view = view; _model = model; }

void Controller::run(){
  int choice;
    do {
      _view.showMenu();
      _view.showMessage("Escolha uma opcao: ");
      std::cin >> choice

      switch (choice)
      {
      case 1:
        
        break;
      
      case 2:

        break;
      case 3:
        break;
      
      case 4:
        break;
      default:
        break;
      }

    } while (choice != 3);
}