#include "CallStates.h"


SplashScreenState::SplashScreenState(_gameResources Data)
    : _gameData(Data)
{
}


void SplashScreenState::initial_state()
{
    Create_Screen();
}


void SplashScreenState::input_handler()
{
    sf::Event _event;
    while(_gameData->gameScreen_.getGameScreen().pollEvent(_event)) {
        if(_event.type == sf::Event::Closed) {
            _gameData->gameScreen_.CloseGameScreen();
        }
        CheckForInput();
    }
}

void SplashScreenState::state_update()
{
}

void SplashScreenState::draw_State()
{

    _gameData->gameScreen_.ClearScreen();
    _gameData->gameScreen_.DrawToGameScreen(_backSprite);
    _gameData->gameScreen_.UpdateGameScreen();
}



void SplashScreenState::Create_Screen()
{
    _gameData->gameScreen_.CreateScreen(ScreenDimensions::_Screen_Width, ScreenDimensions::_Screen_Height,
        "SplashScreen", static_cast<uint32_t>(WindowType::NONE));

    _gameData->_resources.texture_loader(Texture_::Splashscreen, filepath::splash_file_path);
    _backSprite.setTexture(_gameData->_resources.get_texture(Texture_::Splashscreen));
}




void SplashScreenState::CheckForInput()
{
    if(_gameData->_input.isButtonPressed(Key::Enter))
        _gameData->_states.adding_state(state_ptr(new MainMenuState(this->_gameData)), true);

    if(_gameData->_input.isButtonPressed(Key::Escape)) {
        _gameData->gameScreen_.CloseGameScreen();
    }
}



SplashScreenState::~SplashScreenState()
{
}





//////////////////////////////////////////////////////////////////////////////////////
MainMenuState::MainMenuState(_gameResources Data)
    : _gameData(Data)
{
}

void MainMenuState::initial_state()
{
    Create_Screen();
}

void MainMenuState::input_handler()
{
    sf::Event _event;
    while(_gameData->gameScreen_.getGameScreen().pollEvent(_event)) {
        if(_event.type == sf::Event::Closed) {
            _gameData->gameScreen_.CloseGameScreen();
            //    _gameData -> gameScreen_.CloseGameScreen();
        }
        CheckForInput();
    }
}

void MainMenuState::state_update()
{
}

void MainMenuState::draw_State()
{

    _gameData->gameScreen_.ClearScreen();
    _gameData->gameScreen_.DrawToGameScreen(_menuSprite);
    _gameData->gameScreen_.UpdateGameScreen();
}

void MainMenuState::Create_Screen()
{
    _gameData->gameScreen_.CreateScreen(ScreenDimensions::_Screen_Width, ScreenDimensions::_Screen_Height, "Main menu",
        static_cast<uint32_t>(WindowType::NONE));

    _gameData->_resources.texture_loader(Texture_::MainMenu_, filepath::menu_file_path);
    _menuSprite.setTexture(_gameData->_resources.get_texture(Texture_::MainMenu_));
}



void MainMenuState::CheckForInput()
{

    if(_gameData->_input.isButtonPressed(Key::Escape)) {
        _gameData->gameScreen_.CloseGameScreen();
    }
    if(_gameData->_input.isButtonPressed(Key::PlayButton))
        _gameData->_states.adding_state(state_ptr(new GamePlay(this->_gameData)), true);
}

MainMenuState::~MainMenuState()
{
}



////////////////////////xx////////////////////////////
GamePlay::GamePlay(_gameResources Data)
    : _gameData(Data)
{
}

void GamePlay::initial_state()
{

    Create_Screen();
    _bailey_logic =
        std::make_shared<Bailey>(GameConstants::_playerOriginalPositionX, GameConstants::_playerOriginalPositionY);

    _safe_logic=
        std::make_shared<Bailey>(0,60);

    bailey_SFML = std::make_shared<DrawBailey>(_bailey_logic, _gameData->_resources, filepath::player_file_path, 2,2);
    safe_SFML
     = std::make_shared<DrawBailey>(_safe_logic, _gameData->_resources, filepath::safe_file_path, 7, 3);


    _ice_blocks = std::make_shared<IceBlocks>(GameConstants::ice_blocks_cols, GameConstants::ice_blocks_rows,
        Direction::Right, GameConstants::ice_blocks_X, GameConstants::ice_blocks_Y);

    create_ice_block_drawable(GameConstants::ice_blocks_rows, GameConstants::ice_blocks_cols, _iceSFML, _ice_blocks,
        filepath::ice_file_path);


    collisions = std::make_shared<Collissions>();
    handling_col = std::make_unique<CollisionDetection>(collisions);

}

void GamePlay::input_handler()
{
    sf::Event _event;
    while(_gameData->gameScreen_.getGameScreen().pollEvent(_event)) {
        if(_event.type == sf::Event::Closed) {
            _gameData->gameScreen_.CloseGameScreen();
        }
        CheckForInput();
    }
}


void GamePlay::state_update()
{

    handling_col->ice_player_col(_bailey_logic, _ice_blocks);



                   // std::cout << _bailey_logic->blueIsSet()<< std::endl;
    if(!_bailey_logic->isTop() && !_bailey_logic->blueIsSet()){
        _bailey_logic->move();
    }else if(_bailey_logic->blueIsSet()){
        _bailey_logic->move_at_speeds();

    }

    bailey_SFML->UpdateDrawBailey();
    safe_SFML->UpdateDrawBailey();
    _ice_blocks->move();

       for(auto i = 0u; i < _iceSFML.size(); i++) {
        for(auto j = 0u; j < _iceSFML[i].size(); j++) {
            _iceSFML[i][j]->UpdateIceDrawable();
        }
    }


}


void GamePlay::draw_State()
{
    //
    _gameData->gameScreen_.ClearScreen();
    _gameData->gameScreen_.DrawToGameScreen(_background);
     _gameData->gameScreen_.DrawToGameScreen(*safe_SFML);
    _gameData->gameScreen_.DrawToGameScreen(*bailey_SFML);


     for(const auto& i : _iceSFML) {
        for(const auto& j : i)
            _gameData->gameScreen_.DrawToGameScreen(*j);
    }

    _gameData->gameScreen_.UpdateGameScreen();
}


void GamePlay::Create_Screen()
{
    _gameData->gameScreen_.CreateScreen(ScreenDimensions::_Screen_Width, ScreenDimensions::_Screen_Height, "GamePlay",
        static_cast<uint32_t>(WindowType::NONE));
    //
    _gameData->_resources.texture_loader(Texture_::Game_Screen, filepath::game_screen_file_path);
    _background.setTexture(_gameData->_resources.get_texture(Texture_::Game_Screen));
}

void GamePlay::CheckForInput()
{

    if(_bailey_logic->isTop()){
    //
    if(_gameData->_input.isButtonPressed(Key::Escape)) {
        _gameData->gameScreen_.CloseGameScreen();
    }
    //
    if(_gameData->_input.isButtonPressed(Key::Left)) {
        _bailey_logic->move_manual(Direction::Left);
    }

    if(_gameData->_input.isButtonPressed(Key::Right)) {
        _bailey_logic->move_manual(Direction::Right);
    }

    if(_gameData->_input.isButtonPressed(Key::Up)) {
        _bailey_logic->move_manual(Direction::Up);
    }

    if(_gameData->_input.isButtonPressed(Key::Down)) {
        _bailey_logic->move_manual(Direction::Down);
    }}

    else {
        _bailey_logic->move();
    }

}


void GamePlay::create_ice_block_drawable(const unsigned& val,
        const unsigned& val2,
        ice_block_vec& _iceSFML,
        const ice_blocks_ptr& ice_blocks,
        const string& fl)

{
    for(auto i = 0u; i < val2; i++) {

        std::vector<std::unique_ptr<DrawIceBlocks>> en;

        for(auto j = 0u; j < val; j++) {
            auto ice =
                std::make_unique<DrawIceBlocks>(_ice_blocks->getIceBlocks().at(i)->getIce().at(j), _gameData->_resources, fl);
            en.push_back(std::move(ice));
        }

        _iceSFML.push_back(std::move(en));
    }
}

