#ifndef MODEL_H
#define MODEL_H

#include "Clientes.h"
#include "Cliente.h"
#include "Estoque.h"
#include "Roupa.h"

class Model{
  public:
    Clientes _clientes;
    Cliente _cliente;
    Estoque _estoque;
    Roupa _roupa;

    Model();
};

#endif // MODEL_H