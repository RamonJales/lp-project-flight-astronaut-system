#include <iostream>
#include "../includes/interface.hpp"


void print_menu() {
    std::cout << "======================================" << std::endl;
    std::cout << "           MENU DE OPÇÕES             " << std::endl;
    std::cout << "======================================" << std::endl;
    std::cout << "Selecione uma opção:" << std::endl;
    std::cout << "1. Cadastrar Astronauta" << std::endl;
    std::cout << "2. Cadastrar Voo" << std::endl;
    std::cout << "3. Adicionar Astronauta em Voo" << std::endl;
    std::cout << "4. Remover Astronauta do Voo" << std::endl;
    std::cout << "5. Lançar Voo" << std::endl;
    std::cout << "6. Explodir Voo" << std::endl;
    std::cout << "7. Finalizar Voo" << std::endl;
    std::cout << "8. Listar Todos os Voos" << std::endl;
    std::cout << "9. Listar Todos os Astronautas mortos" << std::endl;
    std::cout << "10. Listar Todos os Astronautas" << std::endl;
    std::cout << "0. Sair" << std::endl;
    std::cout << "======================================" << std::endl;
}