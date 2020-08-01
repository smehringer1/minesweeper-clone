#include "Board.h"
using namespace std;

Board::Board(map<string, sf::Texture>& textureMap) {
    this->textureMap = textureMap;
    resetTiles("testboard2.brd");
}

void Board::resetTiles(const string& boardFile) {
    cout << "Resetting..." << endl;
    boardTiles.clear();
    bombOverlays.clear();
    bombs.clear();
    boardTiles.resize(16);
    tilesRevealed = 0;
    mineNumber = 0;
    flags = 0;
    ifstream boardLayoutFile("../boards/" + boardFile);
    string line;
    float xPos, yPos = 0;
    for (int row = 0; row < 16; row++) {
        getline(boardLayoutFile, line);
        xPos = 0;
        for (int col = 0; col < 25; col++) {
            Tile* tile = new Tile(xPos, yPos, textureMap["tile_hidden"]);
            boardTiles.at(row).push_back(tile);
            if (line[col] == '1') {
                tile->setBomb(true);
                bombs.push_back(tile);
                sf::Sprite* bombOverlay = new sf::Sprite();
                bombOverlay->setPosition(tile->getX(), tile->getY());
                bombOverlay->setTexture(textureMap["mine"]);
                bombOverlays.push_back(bombOverlay);
                mineNumber++;
            }
            xPos += 32;
        }
        yPos += 32;
    }
    initializeAdjacents();
}

void Board::initializeAdjacents() {
    for (int row = 0; row < 16; row++) {
        for (int col = 0; col < 25; col++) {
            Tile* tile = boardTiles.at(row).at(col);
            for (int relRow = row - 1; relRow <= row + 1; relRow++) {
                for (int relCol = col - 1; relCol <= col + 1; relCol++){
                    if (relRow >= 0 && relCol >= 0 && relRow < 16 && relCol < 25) {
                        Tile* adjacent = boardTiles.at(relRow).at(relCol);
                        if (tile->isBomb()){
                            if (!adjacent->isBomb()) {
                                adjacent->incrementMinesAdjacent();
                            }
                        }
                        tile->addAdjacentTile(adjacent);
                    }
                }
            }
        }
    }
}

void Board::checkTiles(Tile *tile) {
    vector<Tile*> adjacentTiles = tile->getAdjacentTiles();
    bool bomb = false;
    for (Tile* adjacent : adjacentTiles) {
        if (adjacent->isBomb()){
            bomb = true;
        }
    }
    if (!bomb) {
        for (Tile* adjacent : adjacentTiles) {
            if (!adjacent->isRevealed() && !adjacent->isFlagged()) {
                adjacent->setRevealed(true);
                tilesRevealed++;
                if (adjacent->getNumberMinesAdjacent() == 0) {
                    checkTiles(adjacent);
                }
            }
        }
    }
}

int Board::handleBoardClick(int row, int col) {
    Tile *tile = boardTiles.at(row).at(col);
    if (tile->isFlagged()){
        return 1;
    } else {
        if (tile->isBomb()) {
            return 0;
        } else if (tile->isRevealed()){
            return 1;
        } else {
            tile->setRevealed(true);
            tilesRevealed++;
            checkTiles(tile);
            return 2;
        }
    }
}

void Board::toggleFlaggedRightClick(int tileRow, int tileCol) {
    Tile* tile = boardTiles.at(tileRow).at(tileCol);
    if (!tile->isFlagged()){
        tile->setFlagged(true);
        flags++;
    } else {
        tile->setFlagged(false);
        flags--;
    }
}

void Board::setTileFlagged(Tile *tile) {
    tile->setFlagged(true);
    flags++;
}

void Board::setDebug(bool set) { debug = set; }
bool Board::getDebugState() const { return debug; }
vector<vector<Tile*>>& Board::getTiles() { return boardTiles; }
vector<sf::Sprite*>& Board::getBombOverlays() { return bombOverlays; }

void Board::createRandomBoard() {
    deque<int> mineLocations;
    stringstream randomBoardSS;
    while(mineLocations.size() < 50) {
        int random = rand() % 400;
        if (find(mineLocations.begin(), mineLocations.end(), random) != mineLocations.end()){
            continue;
        } else {
            mineLocations.push_back(random);
        }
    }
    sort(mineLocations.begin(), mineLocations.end());
    int counter = 0;
    ofstream output("../boards/random.brd");
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 25; j++) {
            if (counter == mineLocations.front()) {
                mineLocations.pop_front();
                output <<  "1";
            } else {
                output <<  "0";
            }
            counter += 1;
        }
        output << endl;
    }
}

bool Board::checkWin() {
    if (tilesRevealed + mineNumber == 400) {
        return true;
    } else {
        return false;
    }
}

int Board::getFlagsNumber() { return flags; }
int Board::getMineCount() { return mineNumber; }

vector<Tile*>& Board::getBombTiles() {
    return bombs;
}
