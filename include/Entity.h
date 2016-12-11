#ifndef __InstallingSFML__entity__
#define __InstallingSFML__entity__

#include <SFML/Graphics.hpp>
#include <cstdlib>


using namespace std;

class Entity
{
    public:
        sf::RectangleShape rect;
        sf::Sprite sprite;
        sf::Text text;

    protected:

    private:
};

#endif // ENTITY_H
