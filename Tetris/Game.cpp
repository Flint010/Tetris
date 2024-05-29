#include "Game.h"

#include "Board.h"

Game::Game()
{
    srand(time(NULL));
    using namespace sf::Style;
    sf::ContextSettings settings(0, 0, 6);
    window = new sf::RenderWindow(sf::VideoMode(300, 500), "Tetris", 7U, settings);//, Titlebar|Close, settings);    

    t_score.setFillColor(sf::Color::White);
    t_score.setPosition(250, 40);
    t_score.setCharacterSize(10);
    t_score.setString("Score: ");
    t_lines.setFillColor(sf::Color::White);
    t_lines.setPosition(250, 40);
    t_lines.setCharacterSize(10);
    t_lines.setString("Lines: ");
}

Game::~Game()
{
    delete window;
}

void Game::run()
{
     
    TetroType type = static_cast<TetroType>(rand() % (int)TetroType::NONE);
    Tetramino tetr(type);
    Board board(this);
    board.addNext(tetr);

    bool pause = false;

    sf::Clock timer;
    sf::Time time;        
    float deley = 0.7f;

    while (window->isOpen())
    {
        time += timer.restart();

        
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::KeyPressed) {
                board.eventHeandler(event);
            }
            if (event.type == sf::Event::Closed)
                window->close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window->close();
            }

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down) {
                deley = 0.05f;
            }
            if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Down) {
                deley = 0.7f;
            }

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P) {
                pause = !pause;
            }
 
        }

        if (time.asSeconds() > deley) {
            if(!pause)
                board.move();

            if (board.isGameOver()) {
                board.clear();
                TetroType type = static_cast<TetroType>(rand() % (int)TetroType::NONE);
                Tetramino tetr(type);
                board.addNext(tetr);
            }
            //board.update();
            time = sf::Time::Zero;
        } 


        board.update();
        window->clear();        
        board.draw(window);
        window->draw(t_score);
        window->draw(t_lines);

        window->display();
    }
}

void Game::update(Board& b)
{
    if (b_score < b.score())
        b_score = b.score();
    if (b_lines < b.lines())
        b_lines = b.lines();


    std::string str = { "Tetris: score " + std::to_string(b.score()) + "[best " + std::to_string(b_score) + "], lines " + std::to_string(b.lines()) + "[best " + std::to_string(b_lines) + "]" };
    
    window->setTitle(str);
}
