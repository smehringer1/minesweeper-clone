#ifndef PROJECT_3_MINESWEEPER_TILE_H
#define PROJECT_3_MINESWEEPER_TILE_H
#include <SFML/Graphics.hpp>
using namespace std;

class Tile : public sf::Sprite {
    float xPos, yPos;
    bool bomb = false;
    bool flagged = false;
    bool revealed = false;
    int minesAdjacent = 0;
    vector<Tile*> adjacentTiles;
public:
    //Tile();
    Tile(float xPos, float yPos, sf::Texture& texture);
    float getX() const;
    float getY() const;
    void incrementMinesAdjacent();
    int getNumberMinesAdjacent() const;
    void addAdjacentTile(Tile* tile);
    vector<Tile*>& getAdjacentTiles();
    bool isBomb() const;
    void setBomb(bool bombState);
    bool isFlagged() const;
    void setFlagged(bool set);
    bool isRevealed() const;
    void setRevealed(bool revealState);
};

#endif //PROJECT_3_MINESWEEPER_TILE_H
