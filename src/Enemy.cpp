#include "Enemy.h"
#include "random.h"

Enemy::Enemy()
{
    rect.setSize(sf::Vector2f(32, 32));
    rect.setPosition(800,400);
    rect.setFillColor(sf::Color::Blue);

}

void Enemy::update()
{
sprite.setPosition(rect.getPosition());
}

void Enemy::Steruj()
{
  if(direction == 1)
 {
     if (sprite.getPosition().y>50)
     {
        rect.move(0,-PredkoscPoruszaniaPostaci);
     }
 }

 else if(direction == 2)
 {
     if (sprite.getPosition().y<600)
     {
        rect.move(0,PredkoscPoruszaniaPostaci);
     }
 }

 else if(direction == 3)
 {
     if (sprite.getPosition().x>50)
     {
        rect.move(-PredkoscPoruszaniaPostaci,0);
     }
 }
 else if(direction == 4)
 {
     if (sprite.getPosition().x<914)
     {
        rect.move(PredkoscPoruszaniaPostaci,0);
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
