#include "Collissions.h"


bool Collissions::collided(const std::shared_ptr<MoveableObjects>& char_1,
    const std::shared_ptr<MoveableObjects>& char_2)
{

    auto minDY = (char_1->getSize().width_ + char_2->getSize().width_) + 40;

    auto dis = calculateDistance(char_1->getPosition().xCoord, char_1->getPosition().yCoord,
        char_2->getPosition().xCoord, char_2->getPosition().yCoord);

    if(dis< minDY )
        return true;

    return false;
}



float Collissions::calculateDistance(const float& x1, const float& y1, const float& x2, const float& y2)
{

    auto distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

    return distance;
}
