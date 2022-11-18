/** \file main.cpp
    \brief Contains the main function

    NB:to document global objects (functions, typedefs, enum, macros, etc), you must document the file in which they are defined. That is,
    you must provide this file comment block.
 */


////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
/*#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Application.h"


/** \fn int main()
 *  \brief This function contains the majority of the code for the game
 *
 *  \return The application exit code: 0 for successful completion; a negative number to indicate an error
 *
 */

 /*
int main()
{
    Application app;
    app.Run();

    return EXIT_SUCCESS;
}
*/




/*****EDITS BY PHETOLO START HERE******/

#include "PlayGame.h"
#include <memory>
#include <iostream>

int main()
{
    auto game_ = std::make_unique<PlayGame>();
    game_->execute_game_logic();

    return 0;
}
