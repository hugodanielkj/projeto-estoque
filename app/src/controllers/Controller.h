#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../views/View.h"
#include "../models/Model.h"

class Controller{
  private:
    View _view;
    Model _model;
  
  public:
    Controller(View& view, Model& model);
    void run();
};

#endif // CONTROLLER_H