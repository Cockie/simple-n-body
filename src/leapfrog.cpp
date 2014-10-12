#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;
#include "leapfrog.h"
#define GRAVC (8.88711204/10000000000)

inline double squ(double x){
    return (x*x);
}

Leapfrog::Leapfrog(double timestep_):Integrator(timestep_)
{
    //ctor
}

Leapfrog::~Leapfrog()
{
    //dtor
}

void Leapfrog::tick(vector<Body*> &bodies){
    double vx1, vy1, vz1, x, y, z;
    for(vector<Body*>::iterator it = bodies.begin(); it != bodies.end(); ++it) {
        //save new positions for speed calculation
        x=(*it)->Getx();
        y=(*it)->Gety();
        z=(*it)->Getz();
        //save current speed for calculation of new speed
        vx1=(*it)->Getvx();
        vy1=(*it)->Getvy();
        vz1=(*it)->Getvz();
        //calculate new speed altered by gravity of all other bodies
        for(vector<Body*>::iterator it2 = bodies.begin(); it2 != bodies.end(); ++it2) {
            if((*it2)->Getname()!=(*it)->Getname()){
                vx1 -= timestep*GRAVC*(*it2)->Getmass()*pow(( squ(x-(*it2)->Getx()) + squ(y-(*it2)->Gety()) + squ(z-(*it2)->Getz()) ),-1.5)*(x-(*it2)->Getx());
                vy1 -= timestep*GRAVC*(*it2)->Getmass()*pow(( squ(x-(*it2)->Getx()) + squ(y-(*it2)->Gety()) + squ(z-(*it2)->Getz()) ),-1.5)*(y-(*it2)->Gety());
                vz1 -= timestep*GRAVC*(*it2)->Getmass()*pow(( squ(x-(*it2)->Getx()) + squ(y-(*it2)->Gety()) + squ(z-(*it2)->Getz()) ),-1.5)*(z-(*it2)->Getz());
            }
        }
        //update speeds
        (*it)->Setvx1(vx1);
        (*it)->Setvy1(vy1);
        (*it)->Setvz1(vz1);
    }
    for(vector<Body*>::iterator it = bodies.begin(); it != bodies.end(); ++it) {
        (*it)->updatev();
    }
    for(vector<Body*>::iterator it = bodies.begin(); it != bodies.end(); ++it) {
        //save coordinates of body for easy reference
        x=(*it)->Getx();
        y=(*it)->Gety();
        z=(*it)->Getz();
        //update positions based on current speed: x1 = x + v*t
        (*it)->Setx1( x + timestep*(*it)->Getvx() );
        (*it)->Sety1( y + timestep*(*it)->Getvy() );
        (*it)->Setz1( z + timestep*(*it)->Getvz() );
        (*it)->updater();
    }
}

void Leapfrog::start(vector<Body*> &bodies) {
    double x, y, z, x1, y1, z1;
    for(vector<Body*>::iterator it = bodies.begin(); it != bodies.end(); ++it) {
        x=(*it)->Getx();
        x1=(*it)->Getx();
        y=(*it)->Gety();
        y1=(*it)->Gety();
        z=(*it)->Getz();
        z1=(*it)->Getz();
        //update positions based on current speed: x1 = x + v*t
        x1 += timestep*(*it)->Getvx()/2;
        y1 += timestep*(*it)->Getvy()/2;
        z1 += timestep*(*it)->Getvz()/2;
        for(vector<Body*>::iterator it2 = bodies.begin(); it2 != bodies.end(); it2++) {
            if((*it2)->Getname()!=(*it)->Getname()){
                x1 -= GRAVC*(*it2)->Getmass()*pow(( squ(x-(*it2)->Getx()) + squ(y-(*it2)->Gety()) + squ(z-(*it2)->Getz()) ),-1.5)*(x-(*it2)->Getx())*timestep*timestep/8;
                y1 -= GRAVC*(*it2)->Getmass()*pow(( squ(x-(*it2)->Getx()) + squ(y-(*it2)->Gety()) + squ(z-(*it2)->Getz()) ),-1.5)*(y-(*it2)->Gety())*timestep*timestep/8;
                z1 -= GRAVC*(*it2)->Getmass()*pow(( squ(x-(*it2)->Getx()) + squ(y-(*it2)->Gety()) + squ(z-(*it2)->Getz()) ),-1.5)*(z-(*it2)->Getz())*timestep*timestep/8;
            }
        }
        (*it)->Setx1(x1);
        (*it)->Sety1(y1);
        (*it)->Setz1(z1);
    }
    for(vector<Body*>::iterator it = bodies.begin(); it != bodies.end(); ++it) {
        (*it)->updater();
    }
}
