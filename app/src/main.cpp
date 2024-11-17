#include <iostream>
#include <sqlite3.h>
#include <string>
#include "views/View.h"
#include "models/Model.h"
#include "controllers/Controller.h"

int main(){
  std::cout << "Iniciando programa." << std::endl;
  View view;
  Model model;
  Controller controller(view, model);
  controller.run();
  return 0;
}