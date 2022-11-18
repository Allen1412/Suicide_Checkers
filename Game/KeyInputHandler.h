#ifndef KEYINPUTHANDLER_H
#define KEYINPUTHANDLER_H

#include <cassert>
#include <SFML/Graphics.hpp>

enum class Key
{
    A = 0, Up, Down, Right, Left, Space, Escape, PlayButton, Enter
};
 using sf::Keyboard;
/**
 * @class KeyInputHandler
 * @author  Masabata Pule (482412) and Tsietsi Gcanga(2104199)
 * @date 30/09/2022
 * @file KeyInputHandler.h
 * @brief class to detect keyboard pressed by user
 */
class KeyInputHandler
{
public:
   KeyInputHandler( ) {}
    ~KeyInputHandler( ) {}

 /**
  * @brief function that detects if a specific key is pressed or not
  * @param _key the specific key pressed
  * @return true if key was pressed and false if it was not
  */
    bool isButtonPressed (const Key& _key);
};

#endif // KEYINPUTHANDLER_H
