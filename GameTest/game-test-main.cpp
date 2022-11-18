#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "../game-source-code/Display.h"
#include "../game-source-code/Application.h"
#include "../game-source-code/WelcomeWindow.h"
#include "../game-source-code/Player.h"
#include "../game-source-code/IceFloe.h"
#include "../game-source-code/Settings.h"
#include "../game-source-code/Enums.h"

TEST_CASE("Check if game window is loading")
{
    CHECK_NOTHROW(Application app);
}
TEST_CASE("Verify that player texture is loaded ")
{
    CHECK_NOTHROW(Player player);
}
TEST_CASE("Verify player initial position")
{
    auto player = Player();
    auto xpos = player.getXposition();
    CHECK(xpos == 30 );
    CHECK(player.getYposition() == 100);
}
TEST_CASE("Checking player's walking speed for left and right movements")
{
    auto player = Player();
    player.movePlayer(Direction::RIGHT);
    auto walkSpeed = player.getSpeed();
    CHECK(walkSpeed == 2.0);
    player.movePlayer(Direction::LEFT);
    CHECK(player.getSpeed() == 2.0);
}
TEST_CASE("Check player's jumping speed when moving up and down")
{
    auto player = Player();
    player.movePlayer(Direction::UP);
    auto jumpSpeed = player.getSpeed();
    CHECK(jumpSpeed == 50);
    player.movePlayer(Direction::DOWN);
    auto jumpDown = player.getSpeed();
    CHECK_EQ(jumpSpeed,jumpDown);
}
TEST_CASE("Check if player moves to the right")
{
   auto player = Player();
   auto movePos = 30;
   player.setXposition(movePos);
   auto pos = player.getXposition();
   player.movePlayer(Direction::RIGHT);
   auto postwo = player.getXposition();
   CHECK_FALSE(pos==postwo);
}
TEST_CASE("Check if player moves to the left")
{
   auto player = Player();
   auto prev_pos = player.getXposition();
   player.movePlayer(Direction::LEFT);
   auto new_pos = player.getXposition();
   CHECK_FALSE(prev_pos==new_pos);
}
TEST_CASE("Player's yposition remains constant when moving to the right or left")
{
   auto player = Player();
   player.movePlayer(Direction::RIGHT);
   auto ypos_right = player.getYposition();
   player.movePlayer(Direction::LEFT);
   auto ypos_left = player.getYposition();
   CHECK_EQ(ypos_right,ypos_left);
}
TEST_CASE("Check if player moves up")
{
   auto player = Player();
   auto prev_pos = player.getYposition();
   player.movePlayer(Direction::UP);
   auto postwo = player.getYposition();
   CHECK_FALSE(prev_pos==postwo);
}
TEST_CASE("Check if player moves down")
{
   auto player = Player();
   auto prev_pos = player.getYposition();
   player.movePlayer(Direction::DOWN);
   auto postwo = player.getYposition();
   CHECK_FALSE(prev_pos==postwo);
}
TEST_CASE("CHECK IF PLAYER JUMPS UP WITH A SPEED OF 50")
{
   auto player = Player();
   auto prev_pos = player.getYposition();
   player.movePlayer(Direction::UP);
   auto postwo = player.getYposition();
   CHECK_FALSE(prev_pos==postwo);
}
TEST_CASE("Player's xposition remains constant when moving up or down")
{
   auto player = Player();
   player.movePlayer(Direction::UP);
   auto xpos_up = player.getXposition();
   player.movePlayer(Direction::DOWN);
   auto xpos_down = player.getXposition();
   CHECK_EQ(xpos_up,xpos_down);
}
//TEST_CASE("verify ice initial position")
//{
//   auto ice = IceFloe();
//   auto xpos = ice.getXposition();
//   CHECK(xpo == 0);
//   CHECK(ice.getYposition() == 180);
//}
//TEST_CASE("Checking ice moving speed")
//{
//   auto ice = IceFloe();
//   ice.moveIceFloe(Direction::RIGHT);
//   CHECK(ice.getspeed() == Settings::IceFloeSpeed);
//}
//TEST_CASE("verify ice moves to the right")
//{
//   auto ice = IceFloe();
//   auto prev_pos = ice.getXposition();
//   ice.moveIceFloe(Direction::RIGHT);
//   CHECK_FALSE(prev_pos == ice,getXposition());
//}
