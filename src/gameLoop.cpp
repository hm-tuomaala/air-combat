#include "gameLoop.hpp"

gameLoop::gameLoop(){
    window.create(sf::VideoMode(800, 600), "Air combat", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);
    //Menu *menu = new Menu(window.getSize().x, window.getSize().y);
    setup();
}

gameLoop::~gameLoop(){

}

void gameLoop::setup(){
    /*sf::RenderWindow window(sf::VideoMode(800, 600), "Air combat", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);
    sf::Event event;
    sf::View view;
    int delayCounter;*/
    menu = new Menu(window.getSize().x, window.getSize().y);

    fighterWorld = new World();
    player = new Player(&fighterWorld->get2bWorld());
    enPlanes = new EnemyAir(&fighterWorld->get2bWorld());
    bullets = new Projectiles(&fighterWorld->get2bWorld());
    enPlanes->liftoff();
    enPlanes->liftoff();
    enPlanes->liftoff();

    renderMenu = true;

    Global g;
    std::string path = g.GetPath();

    sf::Font f;
    f.loadFromFile(path + std::string("/Images/arial.ttf"));

    hudXPos = 370;
    hudYPos = -280;
    sf::Text hpText;
    sf::Text livesText;
    hpText.setFont(f);
    livesText.setFont(f);

    std::string hp = std::to_string(player->getHp());
    std::string lives = std::to_string(player->getLives());

    hpText.setString("HP: " + hp);
    hpText.setPosition(view.getCenter().x - hudXPos, view.getCenter().y - hudYPos);
    hpText.setCharacterSize(20);
    hpText.setScale(1.0, -1.0);

    livesText.setString("Lives: " + lives);
    livesText.setPosition(view.getCenter().x - hudXPos + 100, view.getCenter().y - hudYPos);
    livesText.setCharacterSize(20);
    livesText.setScale(1.0, -1.0);
}

void gameLoop::startMenu(){
    while(window.pollEvent(event)){
        if (event.type == sf::Event::Closed){
            window.close();
        } else if (event.type == sf::Event::KeyReleased) {
            if (event.key.code == sf::Keyboard::Up) {
                menu->MoveUp();
                break;
            } else if (event.key.code == sf::Keyboard::Down) {
                menu->MoveDown();
                break;
            } else if (event.key.code == sf::Keyboard::Return && menu->GetIndex() == 0) {
                renderMenu = false;
            } else if (event.key.code == sf::Keyboard::Return && menu->GetIndex() == 2) {
                window.close();
            }
        } else if (event.type == sf::Event::MouseMoved && renderMenu) {
            if (event.mouseMove.x > 333 && event.mouseMove.x < 430 && event.mouseMove.y > 166 && event.mouseMove.y < 203) {
                menu->HighlightIndex(0);
            } else if (event.mouseMove.x > 333 && event.mouseMove.x < 516 && event.mouseMove.y > 315 && event.mouseMove.y < 356) {
                menu->HighlightIndex(1);
            } else if (event.mouseMove.x > 333 && event.mouseMove.x < 431 && event.mouseMove.y > 465 && event.mouseMove.y < 497) {
                menu->HighlightIndex(2);
            }
        } else if (event.type == sf::Event::MouseButtonPressed && renderMenu) {
            if (event.mouseButton.x > 333 && event.mouseButton.x < 430 && event.mouseButton.y > 166 && event.mouseButton.y < 203) {
                renderMenu = false;
            } else if (event.mouseButton.x > 333 && event.mouseButton.x < 516 && event.mouseButton.y > 315 && event.mouseButton.y < 356) {
                //Option lohko
            } else if (event.mouseButton.x > 333 && event.mouseButton.x < 431 && event.mouseButton.y > 465 && event.mouseButton.y < 497) {
                window.close();
            }
        }
    }
}

void gameLoop::worldStep(){
    if (!renderMenu) {
        fighterWorld->worldStep();
        player->step();
        enPlanes->step();
        bullets->projectileStep();
        bullets->remove();
        enPlanes->removal();
        view.setCenter(player->getSprite().getPosition().x, player->getSprite().getPosition().y);
        view.setSize(800, -600);
        window.setView(view);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
            bullets->create(player->getPosition(), player->getDirection());
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
            player->planeAccelerate();
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            player->planePitch(1);
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            player->planePitch(0);
        }
        enPlanes->planeControl(player->getPosition(), player->getDirection());

    }

}

void gameLoop::draw(){
    window.clear(sf::Color::Blue);
    if (!renderMenu) {
        window.draw(fighterWorld->getGround());
        window.draw(player->getSprite());
        for (auto i : enPlanes->getSprites()){
            window.draw(i);
        }
        for(auto i : bullets->getSprites()){
            window.draw(i);
        }
        
        hp = std::to_string(player->getHp());
        lives = std::to_string(player->getLives());
        hpText.setString("HP: " + hp);
        hpText.setPosition(view.getCenter().x - hudXPos, view.getCenter().y - hudYPos);
        livesText.setString("Lives: " + lives);
        livesText.setPosition(view.getCenter().x - hudXPos + 100, view.getCenter().y - hudYPos);
        window.draw(hpText);
        window.draw(livesText);
    } 
    else {
        menu->Draw(window);
    }
    window.display();
}

void gameLoop::loop(){
    while(window.isOpen()){
        startMenu();
        worldStep();
        draw();
    }

}