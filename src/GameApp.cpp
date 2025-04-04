#include "GameApp.hpp"
#include "Events.hpp"
#include "GameManager/GameManager.hpp"
#include "UIManager/UIManager.hpp"
#include <SFML/Graphics.hpp>
#include <map>
#include <iostream>

int GameApp::run(const std::string& mapName)
{
    std::map<std::string, MapConfig> mapConfigs = {
        {"paris", {"Paris", "assets/maps/paris.png", 10, 3, 6, 10.f}},
        {"london", {"London", "assets/maps/london.png", 15, 4, 8, 7.f}},
        {"newyork", {"New York", "assets/maps/newyork.png", 20, 5, 10, 5.f}},
    };

    if (!mapConfigs.count(mapName)) {
        std::cerr << "Map not found: " << mapName << std::endl;
        return 1;
    }

    const MapConfig& config = mapConfigs[mapName];

    sf::RenderWindow window(sf::VideoMode(1280, 720), "Infinite Metro - " + config.name);
    window.setFramerateLimit(60);

    GameManager game(config.maxStations, config.stationSpawnDelay, config.startLines, config.maxLines);
    UIManager ui;
    ui.loadBackground(config.backgroundPath, window, config.name);

    while (window.isOpen()) {
        handleEvents(window, game, ui, _isPaused, _isMuted);

        if (!_isPaused) {
            game.update();
            game.updateStations();
        }

        window.clear(sf::Color::Black);
        ui.render(window, game.getStations(), game.getMetroLines(), game.getSelectedLineIndex(), _isPaused, _isMuted);
        game.renderLinePreview(window, sf::Vector2f(sf::Mouse::getPosition(window)));
        window.display();
    }

    return 0;
}
