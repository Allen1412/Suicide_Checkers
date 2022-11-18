#include "Ice.h"



Ice::Ice(const Direction& init_dir, const float& x, const float& y)
    : MoveableObjects()
{
    direc = init_dir;
    setSize(GameConstants::Ice_block_width_or, GameConstants::Ice_block_height_or, GameConstants::Ice_block_width,
        GameConstants::Ice_block_height);

        blue = false;

    setPosition(x, y);
    setActiveState(true);
}


bool Ice::setBlue(bool color){
    blue = color;
}
bool Ice::getBlue(){

    return blue;
}



void Ice::move(const Direction& dir)
{

    switch(dir) {
    case Direction::Right:
        if(getPosition().xCoord >= (ScreenDimensions::_Screen_Width))
            {
                setPosition(0,this->getPosition().yCoord);
            }
        setHorizontalSpeed(GameObjectSpeed::_iceBlockSpeed);
        move_right();
        break;
    case Direction::Left:
        if(getPosition().xCoord <0){
            setPosition(ScreenDimensions::_Screen_Width, this->getPosition().yCoord);
        }
        setHorizontalSpeed(GameObjectSpeed::_iceBlockSpeed);
        move_left();
        break;
    default:
        return;
    }
}
