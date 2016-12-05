#ifndef POINTS_H
#define POINTS_H

#include "Entity.h"

class Points : public Entity
{
    public:
        Points();

        void update();
        void LosujPolozeniePunktu();
    protected:

    private:
};

#endif // POINTS_H
