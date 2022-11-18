#ifndef ICE_H
#define ICE_H

#include "MoveableObjects.h"

using namespace GameObjectSpeed;

/**
 * @class Ice
 * @author Masabata Pule (482412) and Tsietsi Gcanga(2104199)
 * @date 03/10/2022
 * @file Ice.h
 * @brief class that models each ice on the screen
 */
class Ice : public MoveableObjects
{
public:
    Ice(const Direction& dir, const float& x, const float& y);//initial direction, initial x-coord, initial y-coord
    /**
     * @brief function that moves the ice at a particular speed
     * @param dir a specific direction to which the ice should go
     */
    void move(const Direction& dir);
    /**
     * @brief function to return the direction of movement
     * @return enum of directions
     */
    Direction& getDirection(){return direc;}


private:
Direction direc;
};

class InvalidEnemyInitialPosition{ };
#endif // ICE_H
