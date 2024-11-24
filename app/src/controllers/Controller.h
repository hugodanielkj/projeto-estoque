#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../views/View.h"
#include "../models/Cliente.h"
#include "../models/Clientes.h"
#include "../models/Estoque.h"
#include "../models/Roupa.h"

class Controller{
  private:
    View _view;
    Clientes _clientes;
    Cliente _cliente;
    Estoque _estoque;
    Roupa _roupa;

  public:
    Controller(View& view, Clientes& clientes, Cliente& cliente, Estoque& estoque, Roupa& roupa);
    void run();
};

#endif // CONTROLLER_H