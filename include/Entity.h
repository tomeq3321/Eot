#ifndef __InstallingSFML__entity__
#define __InstallingSFML__entity__

#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <tgmath.h>
#include <deque>
#include <list>
#include <vector>
#include <unistd.h>

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
