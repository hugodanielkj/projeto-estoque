#ifndef VIEW_H
#define VIEW_H

#include <string>

class View{
  public:
    void showMessage(const std::string& message);
    void showMenu();
    void askForDetails(std::string& nome, int& quantidade, std::string& tamanho);
};

#endif // VIEW_H