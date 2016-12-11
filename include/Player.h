#ifndef __InstallingSFML__player__
#define __InstallingSFML__player__
#include "Entity.h"

class Player : public Entity
{
    public:
        int livesCounter=3;
        Player();

        void update();
        void Control();

    protected:

    private:

        int movementSpeedChar=3;

};

#endif /* defined(__InstallingSFML__player__) */
