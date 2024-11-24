#ifndef VIEW_H
#define VIEW_H

#include <string>

class View{
  public:
    void showMessage(const std::string& message);
    void showMenu();
    void askForProductDetails(std::string& nome, int& quantidade, std::string& tamanho);
    void askForClientsDetails(std::string& nome, std::string& aniversario, long int& contato);
};

#endif // VIEW_H