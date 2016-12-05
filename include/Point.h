#ifndef POINT_H
#define POINT_H

#include "Entity.h"

class Point : public Entity
{
    public:
        bool ZebranyPunkt=false;
        Point();

        void update();
        void LosujPolozeniePunktu();
    protected:

    private:
};

#endif // POINT_H
