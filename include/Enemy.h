#ifndef __InstallingSFML__enemy__
#define __InstallingSFML__enemy__
#include "Entity.h"

class Enemy : public Entity
{
    public:
       int PredkoscPoruszaniaPostaci=2;
       int KrawedzPola=100;
       int direction = 0;
       int counter = 0;
       int movingLenght=40;


        Enemy();

      void update();
      void Steruj();

    protected:

    private:
};

#endif /* defined(__InstallingSFML__enemy__) */
