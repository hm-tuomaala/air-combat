#include "gameLoop.hpp"

gameLoop::gameLoop(){
    window.create(sf::VideoMode(800, 600), "Air combat", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);
    menu = new Menu(window.getSize().x, window.getSize().y);
    options = new Options(window.getSize().x, window.getSize().y);
    setup();
}

gameLoop::~gameLoop(){

}

void gameLoop::setup(){
    ending = 0;
    renderMenu = true;
    renderOptions = false;

    fighterWorld = new World();
    player = new Player(&fighterWorld->get2bWorld());
    bullets = new Projectiles(&fighterWorld->get2bWorld());
    enPlanes = new EnemyAir(&fighterWorld->get2bWorld(), bullets);
    enPlanes->liftoff();
    enPlanes->liftoff();
    enPlanes->liftoff();

    Global g;
    path = g.GetPath();

    f.loadFromFile(path + std::string("/Images/arial.ttf"));

    hudXPos = 370;
    hudYPos = -280;

    hpText.setFont(f);
    livesText.setFont(f);

    hp = std::to_string(player->getHp());
    lives = std::to_string(player->getLives());


    hpText.setString("HP: " + hp);
    hpText.setPosition(view.getCenter().x - hudXPos, view.getCenter().y - hudYPos);
    hpText.setCharacterSize(20);
    hpText.setScale(1.0, -1.0);

    livesText.setString("Lives: " + lives);
    livesText.setPosition(view.getCenter().x - hudXPos + 100, view.getCenter().y - hudYPos);
    livesText.setCharacterSize(20);
    livesText.setScale(1.0, -1.0);

    loop();
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
            } else if (event.key.code == sf::Keyboard::Return && menu->GetIndex() == 1) {
                renderOptions = true;
            }
        } else if (event.type == sf::Event::MouseMoved && renderMenu && !renderOptions) {
            if (event.mouseMove.x > 333 && event.mouseMove.x < 430 && event.mouseMove.y > 166 && event.mouseMove.y < 203) {
                menu->HighlightIndex(0);
            } else if (event.mouseMove.x > 333 && event.mouseMove.x < 516 && event.mouseMove.y > 315 && event.mouseMove.y < 356) {
                menu->HighlightIndex(1);
            } else if (event.mouseMove.x > 333 && event.mouseMove.x < 431 && event.mouseMove.y > 465 && event.mouseMove.y < 497) {
                menu->HighlightIndex(2);
            }
        } else if (event.type == sf::Event::MouseButtonPressed && renderMenu && !renderOptions) {
            if (event.mouseButton.x > 333 && event.mouseButton.x < 430 && event.mouseButton.y > 166 && event.mouseButton.y < 203) {
                renderMenu = false;
            } else if (event.mouseButton.x > 333 && event.mouseButton.x < 516 && event.mouseButton.y > 315 && event.mouseButton.y < 356) {
                //op = new Options(window.getSize().x, window.getSize().y);
                renderOptions = true;
            } else if (event.mouseButton.x > 333 && event.mouseButton.x < 431 && event.mouseButton.y > 465 && event.mouseButton.y < 497) {
                window.close();
            }
        } else if (event.type == sf::Event::MouseButtonPressed && renderOptions) {
            std::cout << event.mouseButton.x << ", " << event.mouseButton.y << std::endl;
            if (event.mouseButton.x > 55 && event.mouseButton.x < 111 && event.mouseButton.y < 571 && event.mouseButton.y > 539) {
                renderOptions = false;
            } else if (event.mouseButton.x > 335 && event.mouseButton.x < 422 && event.mouseButton.y < 284 && event.mouseButton.y > 252) {
                options->ChangeDifficulty(0);
                //renderOptions = false;
            } else if (event.mouseButton.x > 335 && event.mouseButton.x < 479 && event.mouseButton.y < 398 && event.mouseButton.y > 373) {
                options->ChangeDifficulty(1);
                //renderOptions = false;
            } else if (event.mouseButton.x > 335 && event.mouseButton.x < 422 && event.mouseButton.y < 517 && event.mouseButton.y > 492) {
                options->ChangeDifficulty(2);
                //renderOptions = false;
            }
            //std::cout << "dif now: " << options->GetDifficulty() << std::endl;
        }
    }
}

void gameLoop::worldStep(){
    fighterWorld->worldStep();
    player->step();
    enPlanes->step();
    bullets->projectileStep();
    bullets->remove();
    if (enPlanes->removal() <= 0){
        ending = 1;
    }
    else if(player->getLives() <=0){
        ending = 2;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        player->planeShoot(bullets);
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

void gameLoop::draw(){
    view.setCenter(player->getSprite().getPosition().x, player->getSprite().getPosition().y);
    view.setSize(800, -600);
    window.setView(view);
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

void gameLoop::endScreen(){
    //deletes old objects and rests game to menu for now
    if (ending == 1){
        //win
    }
    else{
        //loss
    }
    delete bullets;
    delete player;
    delete enPlanes;
    delete fighterWorld;
    setup();
}

void gameLoop::loop(){
    while(window.isOpen()){
        startMenu();
        window.clear(sf::Color::Blue);
        if (!renderMenu && ending == 0){
            worldStep();
            draw();
        }
        else if(ending != 0){
            endScreen();
        }
        else {
            if (!renderOptions) {
                menu->Draw(window);
            } else {
                options->Draw(window);
            }
        }
        window.display();
    }
}
