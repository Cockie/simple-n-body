#ifndef EULER_H
#define EULER_H

#include <integrator.h>


class Euler : public Integrator
{
    public:
        Euler(double timestep_);
        virtual ~Euler();
        void tick(vector<Body*> &bodies);
        void start(vector<Body*> &bodies);
    protected:
    private:
};

#endif // EULER_H
