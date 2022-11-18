#include "Bailey.h"

Bailey::Bailey(const float& x, const float& y)
    : MoveableObjects()
{
    setVerticalSpeed(_playerVerticalSpeed);
    setHorizontalSpeed(_playerHorizontalSpeed);
    lost = false;
    isOnTop = false;
    blueSet = false;

    setSize(GameConstants::playerWidth_or, GameConstants::playerHeight_or, GameConstants::playerWidth,
        GameConstants::playerHeight);

    //if(x > (ScreenDimensions::_Screen_Width - GameConstants::playerWidth) || x < GameConstants::playerWidth ||
       // y > (ScreenDimensions::_Screen_Height - GameConstants::playerHeight) || y < GameConstants::playerHeight)
        //throw InvalidPosition{};
    setPosition(x, y);
}



void Bailey::move_manual(const Direction& _direction)
{
    switch(_direction) {
    case Direction::Left:

        move_left();
        break;
    case Direction::Right:
        move_right();
        break;
        case Direction::Up:
            if(getPosition().yCoord <= GameConstants::playerHeight + GameConstants::safe_zone_height) {
                return;
            }
            jump_up();
        return;
        break;
        case Direction::Down:
            if(getPosition().yCoord >= ScreenDimensions::_Screen_Height - GameConstants::playerHeight) {
                return;
            }
            jump_down();
        return;
        break;
    default:
        return;
    }
}


void Bailey::move_at_speeds(){

    if (getPosition().yCoord<3000){
        move_right();
        move_right();
    }else if(getPosition().yCoord<6000){
        move_left();
        move_left();
    }
    else if(getPosition().yCoord < 9000){

        move_right();
        move_right();
    }else if(getPosition().yCoord<1200){
        move_left();
        move_left();
    }


}

 bool Bailey::blueIsSet(){

 return blueSet;
 }

 bool Bailey::settingBlue(bool isBl){

     blueSet = isBl;
 }

void Bailey::move()
{

    if(delay()){

        if(getPosition().yCoord >= ScreenDimensions::_Screen_Height - GameConstants::playerHeight) {
                lost=true;
            }
            jump_down();

    }

}

bool Bailey::delay()
    {

        delta_time = clock() - initial_tme;

        if((delta_time / 1000.f) >= 0.5f) {
            initial_tme = clock();
            return true;
        }

        return false;
    }


    bool Bailey::isLost(){return lost;}

     bool Bailey::isTop(){

         if(getPosition().yCoord>(160))
            isOnTop = false;
         else
            isOnTop = true;

     return isOnTop;
     }

