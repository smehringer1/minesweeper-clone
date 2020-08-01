#include "Game.h"
#include <iostream>
using namespace std;

Game::Game(map<string, sf::Texture>& textureMap, sf::RenderWindow& window) : board(textureMap), menu(textureMap) {
    this->textureMap = textureMap;
    this->window = &window;
    menu.setMineCounter(board.getMineCount());
}

void Game::RenderLoop() {
    window->setFramerateLimit(60);
    while (window->isOpen()) {
        sf::Event event;
        // Event handler
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
            if (event.type == sf::Event::MouseButtonPressed) {
                int x = event.mouseButton.x, y = event.mouseButton.y;
//                cout << x << endl;
//                cout << y << endl;
                handleClick(event.mouseButton.button, x, y);
            }
        }

        // Render
        window->clear();
        auto tiles = board.getTiles();
        for (int row = 0; row < 16; row++) {
            for (int col = 0; col < 25; col++) {
                Tile* tile = tiles.at(row).at(col);
                if (tile->isRevealed()) {
                    tile->setTexture(textureMap["tile_revealed"]);
                    window->draw(*tile);
                    if (tile->getNumberMinesAdjacent() > 0) {
                        sf::Sprite numberOverlay;
                        numberOverlay.setPosition(tile->getX(), tile->getY());
                        string numberTexture = "number_" + to_string(tile->getNumberMinesAdjacent());
                        numberOverlay.setTexture(textureMap[numberTexture]);
                        window->draw(numberOverlay);
                    }
                } else {
                    window->draw(*tile);
                }
                if (tile->isFlagged()) {    // Draw flag on right click
                    sf::Sprite flagOverlay;
                    flagOverlay.setTexture(textureMap["flag"]);
                    flagOverlay.setPosition(tile->getX(), tile->getY());
                    window->draw(flagOverlay);
                }
            }
        }

        // Check to draw mines
        if (board.getDebugState() || defeat) {
            for (sf::Sprite* overlay : board.getBombOverlays()) {
                window->draw(*overlay);
            }
        }

        // Draw menu elements
        auto menuElementMap = menu.getMenuElements();
        for (auto & it : menuElementMap) {
            window->draw(it.second);
        }

        // Draw counter
        for (sf::Sprite digit : menu.getMineCounterSprites()){
            window->draw(digit);
        }
        window->display();
    }
}

void Game::handleClick(sf::Mouse::Button mouseButton, int x, int y) {
    if (y < 512 && !ended) {
        int row = y / 32;
        int col = x / 32;
        cout << "Valid tile click" << endl;
        if (mouseButton == sf::Mouse::Left) {
            int response = board.handleBoardClick(row, col);
            if (response == 0){ // Bomb clicked
                ended = true;
                defeat = true;
                menu.setFace("face_lose");
                board.setDebug(true);
                for (Tile* bombTile : board.getBombTiles()){
                    bombTile->setRevealed(true);
                }
                cout << "Game lost" << endl;
            } else if (response == 1) {  // Tile already revealed or is flagged
                cout << "Click rejected" << endl;
            } else if (response == 2){ // New tile revealed
                cout << "Successful click action" << endl;
                if (board.checkWin()) {
                    cout << "Game won" << endl;
                    ended = true;
                    board.setDebug(false);
                    menu.setFace("face_win");
                    for (Tile* bombTile : board.getBombTiles()){
                        board.setTileFlagged(bombTile);
                    }
                    menu.setMineCounter(board.getMineCount() - board.getFlagsNumber());
                }
            }
        } else if (mouseButton == sf::Mouse::Right) {
            board.toggleFlaggedRightClick(row, col);
            menu.setMineCounter(board.getMineCount() - board.getFlagsNumber());
        }
    } else if (y > 512){
        if (x > 368 && x < 432 && y < 576) {
            cout << "Face click" << endl;
            if (ended) {
                ended = false;
                defeat = false;
                menu.setFace("face_happy");
                board.setDebug(false);
            }
            board.createRandomBoard();
            board.resetTiles("random.brd");
            menu.setMineCounter(board.getMineCount());
        } else if (x > 544 && x < 607 && y < 576) {
            if (!ended) {
                cout << "Debug click" << endl;
                board.setDebug(!board.getDebugState());
            }
        } else if (x > 607 && y < 576) {
            if (x < 672) {
                board.resetTiles("testboard1.brd");
                menu.setMineCounter(board.getMineCount());
                cout << "Board reset to 1" << endl;
            } else if (x < 736) {
                board.resetTiles("testboard2.brd");
                menu.setMineCounter(board.getMineCount());
                cout << "Board reset to 2" << endl;
            } else {
                board.resetTiles("testboard3.brd");
                menu.setMineCounter(board.getMineCount());
                cout << "Board reset to 3" << endl;
            }
            if (ended) {
                ended = false;
                defeat = false;
                menu.setFace("face_happy");
                board.setDebug(false);
            }
        }
    }
}

