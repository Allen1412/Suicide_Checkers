#include "IceBlocks.h"

IceBlocks::IceBlocks(const unsigned& capx,
    const unsigned& capy,
    const Direction& dir,
    const float& xpos,
    const float& ypos)
{

    capacityX = capx;
    capacityY = capy;
    init = dir;
    x = xpos;
    y = ypos;
    allBlue = false;

    initial_tme = clock();

    auto space_between_ice_blocks = 2*(GameConstants::Ice_block_height);

    for(auto i = 0u; i < capacityY; i++) {
                auto ice_block = std::make_shared<IceColumn>(capacityX, init, x, y + i*space_between_ice_blocks);
                ice_blocks.push_back(ice_block);
    }
}


void IceBlocks::move()
{

    if(delay())
            move_all_ice_blocks(Direction::Left, Direction::Right);
}

bool IceBlocks::delay()
    {

        delta_time = clock() - initial_tme;

        if((delta_time / 1000.f) >= 0.5f) {
            initial_tme = clock();
            return true;
        }

        return false;
    }



void IceBlocks::move_all_ice_blocks(const Direction& dir1, const Direction& dir2)
    {

        for(unsigned i = 0; i < ice_blocks.size(); i++) {

                if(i ==1 || i==3)
                  ice_blocks.at(i)->moving_all(dir1);
                else
                    ice_blocks.at(i)->moving_all(dir2);


        }
    }

    bool IceBlocks::getAllBlue(){
        return allBlue;
    }
    bool IceBlocks::setAllBlue(bool allBlueSetter){

    allBlue = allBlueSetter;
    }
