#include "Point.h"

Point::Point()
{

    rect.setSize(sf::Vector2f(16, 16));
    rect.setPosition(100,200);
    rect.setFillColor(sf::Color::Red);
}

void Point::update()
{
sprite.setPosition(rect.getPosition());
}

void Point::LosujPolozeniePunktu()
{

}


