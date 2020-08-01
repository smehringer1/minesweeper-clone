#include "Menu.h"
#include <iostream>
using namespace std;

Menu::Menu(map<string, sf::Texture>& textureMap) {
    this->textureMap = textureMap;
    menuElements["faceButton"].setTexture(textureMap["face_happy"]);
    menuElements["faceButton"].setPosition(368, 512);
    menuElements["debugButton"].setTexture(textureMap["debug"]);
    menuElements["debugButton"].setPosition(544, 512);
    menuElements["test_1"].setTexture(textureMap["test_1"]);
    menuElements["test_1"].setPosition(608, 512);
    menuElements["test_2"].setTexture(textureMap["test_2"]);
    menuElements["test_2"].setPosition(672, 512);
    menuElements["test_3"].setTexture(textureMap["test_3"]);
    menuElements["test_3"].setPosition(736, 512);
    for (int i = 0; i < 11; i++) {
        sf::Texture texture;
        texture.loadFromFile("../images/digits.png", sf::IntRect(i * 21,0,21,32));
        digitTextures.push_back(texture);
    }
}

map<string, sf::Sprite> Menu::getMenuElements() { return menuElements; }
vector<sf::Sprite>& Menu::getMineCounterSprites() { return mineCounterSprites; }

void Menu::setFace(string faceVariant) {
    menuElements["faceButton"].setTexture(textureMap[faceVariant]);
}

void Menu::setMineCounter(int num) {
    mineCounterSprites.clear();
    if (num >= 0) {
        if (num > 99){
            int first = num / 100;
            int second = num / 10 - 10;
            int third = num % 10;
            sf::Sprite digit1;
            digit1.setTexture(digitTextures.at(first));
            digit1.setPosition(0, 512);
            mineCounterSprites.push_back(digit1);
            sf::Sprite digit2;
            digit2.setTexture(digitTextures.at(second));
            digit2.setPosition(21, 512);
            mineCounterSprites.push_back(digit2);
            sf::Sprite digit3;
            digit3.setTexture(digitTextures.at(third));
            digit3.setPosition(42, 512);
            mineCounterSprites.push_back(digit3);
        } else if (num > 9) {
            int first = num / 10;
            int second = num % 10;
            sf::Sprite digit1;
            digit1.setTexture(digitTextures.at(first));
            digit1.setPosition(0, 512);
            mineCounterSprites.push_back(digit1);
            sf::Sprite digit2;
            digit2.setTexture(digitTextures.at(second));
            digit2.setPosition(21, 512);
            mineCounterSprites.push_back(digit2);
        } else {
            sf::Sprite digit;
            digit.setTexture(digitTextures.at(num));
            digit.setPosition(0, 512);
            mineCounterSprites.push_back(digit);
        }
    } else {
        sf::Sprite negative;
        negative.setTexture(digitTextures.at(10));
        negative.setPosition(0, 512);
        mineCounterSprites.push_back(negative);
        num = abs(num);
        if (num > 99){
            int first = num / 100;
            int second = num / 10 - 10;
            int third = num % 10;
            sf::Sprite digit1;
            digit1.setTexture(digitTextures.at(first));
            digit1.setPosition(21, 512);
            mineCounterSprites.push_back(digit1);
            sf::Sprite digit2;
            digit2.setTexture(digitTextures.at(second));
            digit2.setPosition(42, 512);
            mineCounterSprites.push_back(digit2);
            sf::Sprite digit3;
            digit3.setTexture(digitTextures.at(third));
            digit3.setPosition(61, 512);
            mineCounterSprites.push_back(digit3);
        } else if (num > 9) {
            int first = num / 10;
            int second = num % 10;
            sf::Sprite digit1;
            digit1.setTexture(digitTextures.at(first));
            digit1.setPosition(21, 512);
            mineCounterSprites.push_back(digit1);
            sf::Sprite digit2;
            digit2.setTexture(digitTextures.at(second));
            digit2.setPosition(42, 512);
            mineCounterSprites.push_back(digit2);
        } else {
            sf::Sprite digit;
            digit.setTexture(digitTextures.at(num));
            digit.setPosition(21, 512);
            mineCounterSprites.push_back(digit);
        }
    }
}