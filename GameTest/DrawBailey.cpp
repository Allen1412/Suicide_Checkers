#include "DrawBailey.h"

DrawBailey::DrawBailey(const std::shared_ptr<Bailey>& position, DataManagement& data, const string& path, float scale_x,float scale_y) : _position(position)
{
    data.texture_loader(Texture_::Player_, path);

    _playerTex = data.get_texture(Texture_::Player_);
    _playerDrawable.setTexture(_playerTex);
     _playerDrawable.setScale(scale_x, scale_y);
}


void DrawBailey::UpdateDrawBailey()
{
    _playerDrawable.setPosition(_position->getPosition().xCoord, _position->getPosition().yCoord);
}





void DrawBailey::draw(sf::RenderTarget& _target, sf::RenderStates _states) const
{

    _target.draw(_playerDrawable);

}
