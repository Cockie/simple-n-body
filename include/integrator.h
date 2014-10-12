#ifndef INTEGRATOR_H
#define INTEGRATOR_H
#include <cmath>
#include <vector>
#include "body.h"
using namespace std;

class Integrator
{
    public:
        Integrator(double timestep_);
        virtual ~Integrator();
        double Gettimestep() { return timestep; }
        void Settimestep(double val) { timestep = val; }
        virtual void tick(vector<Body*> &bodies)=0;
        virtual void start(vector<Body*> &bodies)=0;
    protected:
        double timestep;
    private:

};

#endif // INTEGRATOR_H
