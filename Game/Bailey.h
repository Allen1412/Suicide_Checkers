#ifndef BAILEY_H
#define BAILEY_H
#include <ctime>

#include "MoveableObjects.h"

using GameObjectSpeed::_playerHorizontalSpeed;
using GameObjectSpeed::_playerVerticalSpeed;

/**
 * @class Bailey
 * @author Masabata Pule (482412) and Tsietsi Gcanga(2104199)
 * @date 02/10/2022
 * @file Bailey
 * @brief class that models a player and it capabilities
 */


class Bailey : public MoveableObjects
{
public:
//constructor to set the initial position of a player
    Bailey(const float& x, const float& y);
/**
 * @brief function to move a player
 * @param direction is the direction of movement, of type Direction
 */
    void move();
    void move_manual(const Direction& _direction);
    bool delay();
    bool isLost();
    bool isTop();
    bool blueIsSet();
    bool settingBlue(bool isBl);
    void move_at_speeds();



private:
    float initial_tme, delta_time;
    bool lost;
    bool isOnTop;
    bool blueSet;

};

class InvalidPosition{ };

#endif // BAILEY_H
