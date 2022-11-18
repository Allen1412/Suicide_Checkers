#ifndef ICEBLOCKS_H
#define ICEBLOCKS_H

#include <ctime>
#include <vector>
#include "IceColumn.h"
using ice_column_ptr = std::shared_ptr<IceColumn>;
using ice_column_vector = std::vector<ice_column_ptr>;

/**
 * @class IceBlocks
 * @author Masabata Pule (482412) and Tsietsi Gcanga(2104199)
 * @date 04/10/2022
 * @file IceBlocks.h
 * @brief class that models all Ice blocks
 */

class IceBlocks{
    public:

    IceBlocks(const unsigned& capx, const unsigned& capy, const Direction& dir,
        const float& xpos,
        const float& ypos);
    /**
     * @brief function that gets the vector of Ice blocks by reference
     * @return returns a vector of ice
     */
    ice_column_vector &getIceBlocks(){return ice_blocks;}
    /**
     * @brief function to move the army
     */
    void move();
    /**
     * @brief function used to delay movement
     * @return boolean, true if time delay is greater than 5 seconds false otherwise
     */

    bool delay();

private:

    ice_column_vector ice_blocks;
    float x,y;
    Direction init;
    unsigned capacityX, capacityY;
    float initial_tme, delta_time;
    /**
     * @brief function that moves all ice
     * @param dir direction of movement of all ice
     */
    void move_all_ice_blocks(const Direction& dir);

    };


#endif // ICEBLOCKS_H
