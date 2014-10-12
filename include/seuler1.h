#ifndef SEULER1_H
#define SEULER1_H

#include <integrator.h>



class sEuler1 : public Integrator
{
    public:
        sEuler1(double timestep_);
        virtual ~sEuler1();
        void tick(vector<Body*> &bodies);
        void start(vector<Body*> &bodies);
    protected:
    private:
};


#endif // SEULER1_H
