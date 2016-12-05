#include "Player.h"

Player::Player()
{
    rect.setSize(sf::Vector2f(32, 32));
    rect.setPosition(600,400);
    rect.setFillColor(sf::Color::Blue);
}

void Player::update()
{
sprite.setPosition(rect.getPosition());
}

void Player::Steruj()
{
 if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
 {
    if(sprite.getPosition().y>50)
    {
    rect.move(0,-PredkoscPoruszaniaPostaci);
    }
 }

 if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
 {
    if(sprite.getPosition().y<718)
    {
    rect.move(0,PredkoscPoruszaniaPostaci);
    }
 }

 if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
 {
    if(rect.getPosition().x>50)
    {
    rect.move(-PredkoscPoruszaniaPostaci,0);
    }
 }

 if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
 {
    if(sprite.getPosition().x<910)
    {
    rect.move(PredkoscPoruszaniaPostaci,0);
    }
 }
}

