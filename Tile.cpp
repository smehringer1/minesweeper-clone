#include "Tile.h"
using namespace std;

Tile::Tile(float xPos, float yPos, sf::Texture& texture) {
    this->xPos = xPos;
    this->yPos = yPos;
    setPosition(xPos, yPos);
    setTexture(texture);
}

float Tile::getX() const { return xPos; }
float Tile::getY() const { return yPos; }
void Tile::incrementMinesAdjacent() { minesAdjacent++; }
int Tile::getNumberMinesAdjacent() const { return minesAdjacent; }
void Tile::addAdjacentTile(Tile* tile) { adjacentTiles.push_back(tile); }
vector<Tile*>& Tile::getAdjacentTiles() { return adjacentTiles; }
bool Tile::isBomb() const { return bomb; }
bool Tile::isFlagged() const { return flagged; }
void Tile::setFlagged(bool set) { flagged = set; }
bool Tile::isRevealed() const { return revealed; }
void Tile::setRevealed(bool revealState) { revealed = revealState; }
void Tile::setBomb(bool bombState) { bomb = bombState; }