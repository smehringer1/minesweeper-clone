#ifndef PROJECT_3_MINESWEEPER_GAME_H
#define PROJECT_3_MINESWEEPER_GAME_H
#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Menu.h"
using namespace std;

class Game {
    map<string, sf::Texture> textureMap;
    sf::RenderWindow* window;
    Board board;
    Menu menu;
    bool ended = false;
    bool defeat = false;
public:
    Game(map<string, sf::Texture>& textureMap, sf::RenderWindow& window);
    void RenderLoop();
    void handleClick(sf::Mouse::Button mouseButton, int x, int y);
};

#endif //PROJECT_3_MINESWEEPER_GAME_H
