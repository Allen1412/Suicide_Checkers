#ifndef COLLISIONDETECTION_H
#define COLLISIONDETECTION_H

#include "IceBlocks.h"
#include "Collissions.h"
#include "Bailey.h"

#include <iostream>

using player_ptr = std::shared_ptr<Bailey>;
using collision_ptr = std::shared_ptr<Collissions>;
using ice_blocks_ptr = std::shared_ptr<IceBlocks>;

/**
 * @class CollisionDetection
 * @author Masabata Pule (482412) and Tsietsi Gcanga(2104199)
 * @file CollisionDetection.h
 * @brief class that takes care of collisions between particular objects
 */
class CollisionDetection
{
public:
    CollisionDetection(){};
    CollisionDetection(collision_ptr& col);
    ~CollisionDetection()
    {
    }
    /**
     * @brief function to detect collision between Ice and player
     */
    void ice_player_col(player_ptr& bailey, ice_blocks_ptr& ices_ptr);


private:
    collision_ptr _collision;

};
#endif // COLLISIONDETECTION_H
