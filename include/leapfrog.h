#ifndef LEAPFROG_H
#define LEAPFROG_H

#include <integrator.h>


class Leapfrog : public Integrator
{
    public:
        Leapfrog(double timestep);
        virtual ~Leapfrog();
        void tick(vector<Body*> &bodies);
        void start(vector<Body*> &bodies);
    protected:
    private:
};

#endif // LEAPFROG_H
