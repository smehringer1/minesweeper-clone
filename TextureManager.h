#ifndef PROJECT_3_MINESWEEPER_TEXTUREMANAGER_H
#define PROJECT_3_MINESWEEPER_TEXTUREMANAGER_H
#include <map>
#include <SFML/Graphics.hpp>
using namespace std;

class TextureManager {
    map<string, sf::Texture> textureMap;
public:
    sf::Texture getTexture(string textureName);
    void initializeTextures();
};

#endif //PROJECT_3_MINESWEEPER_TEXTUREMANAGER_H
