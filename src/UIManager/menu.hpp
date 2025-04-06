#ifndef MENU_HPP
#define MENU_HPP

#include <SFML/Graphics.hpp>
#include <string>

class Menu {
public:
    Menu();
    ~Menu();
    void run_menu();

private:
    void handle_events();
    void render();

    sf::RenderWindow window;
    sf::Font font;
    sf::Text parisButton;
    sf::Text londonButton;
    sf::Text newYorkButton;

    void loadMap(const std::string& mapName); // Fonction pour charger une carte
};

#endif // MENU_HPP