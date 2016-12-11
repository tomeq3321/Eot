#ifndef __InstallingSFML__enemy__
#define __InstallingSFML__enemy__
#include "Entity.h"


class Enemy : public Entity
{
    public:
        Enemy();
        void update();
        void Control();

    protected:

    private:
        int movementSpeed=2;
        int direction = 0;
        int counter = 0;
        int movingLenght=40;
};

#endif /* defined(__InstallingSFML__enemy__) */
