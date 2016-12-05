#include "Points.h"

Points::Points()
{

    rect.setSize(sf::Vector2f(32, 32));
    rect.setPosition(100,200);
    rect.setFillColor(sf::Color::Red);
}

void Points::update()
{
sprite.setPosition(rect.getPosition());
}

void Points::LosujPolozeniePunktu()
{

}


