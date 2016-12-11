#ifndef __InstallingSFML__player__
#define __InstallingSFML__player__
#include "Entity.h"

class Player : public Entity
{
    public:
        int PredkoscPoruszaniaPostaci=3;
        int KrawedzPola=100;
        int iloscZyc=3;

        Player();

       void update();
       void Steruj();
    protected:

    private:
};

#endif /* defined(__InstallingSFML__player__) */
