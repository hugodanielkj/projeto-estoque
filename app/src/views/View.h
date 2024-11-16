#include <string>

class View{
  public:
    void showMessage(const std::string& message);
    void showMenu();
    void askForDetails(std::string nome, int quantidade, std::string tamanho);
};