#ifndef PROJECT_3_MINESWEEPER_MENU_H
#define PROJECT_3_MINESWEEPER_MENU_H
#include "Tile.h"
#include <SFML/Graphics.hpp>
using namespace std;

class Menu {
    map<string, sf::Texture> textureMap;
    map<string, sf::Sprite> menuElements;
    vector<sf::Sprite> mineCounterSprites;
    vector<sf::Texture> digitTextures;
public:
    Menu(map<string, sf::Texture>& textureMap);
    map<string, sf::Sprite> getMenuElements();
    vector<sf::Sprite>& getMineCounterSprites();
    void setFace(string faceVariant);
    void setMineCounter(int num);
};

#endif //PROJECT_3_MINESWEEPER_MENU_H
