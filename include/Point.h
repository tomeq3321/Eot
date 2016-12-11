#ifndef POINT_H
#define POINT_H

#include "Entity.h"

class Point : public Entity
{
    public:
        bool ZebranyPunkt=false;
        int LiczbaPunktow=0;

        Point();

        void update();

    protected:

    private:
};

#endif // POINT_H
