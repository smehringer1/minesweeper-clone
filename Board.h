#ifndef PROJECT_3_MINESWEEPER_BOARD_H
#define PROJECT_3_MINESWEEPER_BOARD_H
#include "Tile.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <deque>
using namespace std;

class Board {
    vector<vector<Tile*>> boardTiles;
    vector<sf::Sprite*> bombOverlays;
    map<string, sf::Texture> textureMap;
    vector<Tile*> bombs;
    bool debug = false;
    int mineNumber = 0;
    int tilesRevealed = 0;
    int flags = 0;
public:
    Board(map<string, sf::Texture>& textureMap);
    void resetTiles(const string& boardFile);
    void initializeAdjacents();
    void checkTiles(Tile* tile);
    int handleBoardClick(int row, int col);
    vector<vector<Tile*>>& getTiles();
    vector<sf::Sprite*>& getBombOverlays();
    void setDebug(bool set);
    bool getDebugState() const;
    void toggleFlaggedRightClick(int tileRow, int tileCol);
    void setTileFlagged(Tile* tile);
    void createRandomBoard();
    bool checkWin();
    int getFlagsNumber();
    int getMineCount();
    vector<Tile*>& getBombTiles();
};

#endif //PROJECT_3_MINESWEEPER_BOARD_H
