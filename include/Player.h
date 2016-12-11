#ifndef __InstallingSFML__player__
#define __InstallingSFML__player__
#include "Entity.h"

class Player : public Entity
{
    public:
        int movementSpeedChar=3;
        int livesCounter=3;

        Player();

       void update();
       void Control();
    protected:

    private:
};

#endif /* defined(__InstallingSFML__player__) */
