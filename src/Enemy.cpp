#include "Enemy.h"
#include "random.h"

Enemy::Enemy()
{
    rect.setSize(sf::Vector2f(20,20));
    rect.setPosition(800,400);
    rect.setFillColor(sf::Color::Blue);

}

void Enemy::update()
{
    sprite.setPosition(rect.getPosition());
    sprite.setOrigin(22,27);
}

void Enemy::Control()
{
    if(direction == 1)
    {
        if (sprite.getPosition().y>50)
        {
            sprite.setRotation(0);
            rect.move(0,-movementSpeed);
        }
    }
    else if(direction == 2)
    {
        if (sprite.getPosition().y<600)
        {
            sprite.setRotation(180);
            rect.move(0,movementSpeed);
        }
    }
    else if(direction == 3)
    {
        if (sprite.getPosition().x>50)
        {
            sprite.setRotation(-90);
            rect.move(-movementSpeed,0);
        }
    }
    else if(direction == 4)
    {
        if (sprite.getPosition().x<914)
        {
            sprite.setRotation(90);
            rect.move(movementSpeed,0);
        }
    }
    else
    {
        //nie porusza sie
    }

    counter++;
    if(counter>=movingLenght)
    {

        direction = generateRandom(8);
        counter=0;
    }
}
