#include "TextureManager.h"

sf::Texture TextureManager::getTexture(string textureName) {
    return textureMap[textureName];
}

void TextureManager::initializeTextures() {
    textureMap["debug"].loadFromFile("../images/debug.png");
    textureMap["face_happy"].loadFromFile("../images/face_happy.png");
    textureMap["face_lose"].loadFromFile("../images/face_lose.png");
    textureMap["face_win"].loadFromFile("../images/face_win.png");
    textureMap["flag"].loadFromFile("../images/flag.png");
    textureMap["mine"].loadFromFile("../images/mine.png");
    textureMap["number_1"].loadFromFile("../images/number_1.png");
    textureMap["number_2"].loadFromFile("../images/number_2.png");
    textureMap["number_3"].loadFromFile("../images/number_3.png");
    textureMap["number_4"].loadFromFile("../images/number_4.png");
    textureMap["number_5"].loadFromFile("../images/number_5.png");
    textureMap["number_6"].loadFromFile("../images/number_6.png");
    textureMap["number_7"].loadFromFile("../images/number_7.png");
    textureMap["number_8"].loadFromFile("../images/number_8.png");
    textureMap["test_1"].loadFromFile("../images/test_1.png");
    textureMap["test_2"].loadFromFile("../images/test_2.png");
    textureMap["test_3"].loadFromFile("../images/test_3.png");
    textureMap["tile_hidden"].loadFromFile("../images/tile_hidden.png");
    textureMap["tile_revealed"].loadFromFile("../images/tile_revealed.png");
}
