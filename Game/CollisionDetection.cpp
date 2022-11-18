#include "CollisionDetection.h"


CollisionDetection::CollisionDetection(collision_ptr& col):_collision(col)
{

}

void CollisionDetection::ice_player_col(player_ptr& bailey, ice_blocks_ptr& ices_ptr)
{


    for(auto& i : ices_ptr->getIceBlocks()) {
        for(auto& j : i->getIce()) {



                if(_collision->collided(bailey,j)) {

                    j->setBlue(true);
                    bailey->settingBlue(true);


                }
                else{
                    j->setBlue(false);
                     bailey->settingBlue(false);


                }

            }
        }
}

