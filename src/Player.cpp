#include "Player.h"

Player::Player()
{
    rect.setSize(sf::Vector2f(25,25));
    rect.setPosition(512,700);
    rect.setFillColor(sf::Color::Blue);
}

void Player::update()
{
    sprite.setPosition(rect.getPosition());
    sprite.setOrigin(22,17);
}

void Player::Control()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        if(sprite.getPosition().y>50)
        {
        sprite.setRotation(+0);
        rect.move(0,-movementSpeedChar);
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        if(sprite.getPosition().y<718)
        {
            sprite.setRotation(+180);
            rect.move(0,movementSpeedChar);
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        if(rect.getPosition().x>50)
        {
        sprite.setRotation(-90);
        rect.move(-movementSpeedChar,0);
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        if(sprite.getPosition().x<935)
        {
            sprite.setRotation(+90);
            rect.move(movementSpeedChar,0);
        }
    }

   if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        sprite.setRotation(+225);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)  && sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        sprite.setRotation(+135);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        sprite.setRotation(-45);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        sprite.setRotation(+45);
    }
}

