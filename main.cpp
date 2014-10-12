#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include "integrator.h"
#include "body.h"
#include "euler.h"
#include "leapfrog.h"
#include "seuler1.h"
using namespace std;

vector<Body*> bodies;

void parse(string filename)
{
    ifstream file;
    file.open(filename.c_str());
    string line;
    string x, y, z, vx, vy, vz, name, mass;
    while(getline(file, line)){
        stringstream iss(line);
        getline(iss,name,' ');
        getline(iss,mass,' ');
        getline(iss,x,' ');
        getline(iss,y,' ');
        getline(iss,z,' ');
        getline(iss,vx,' ');
        getline(iss,vy,' ');
        getline(iss,vz,' ');
        bodies.push_back(new Body(atof(x.c_str()), atof(y.c_str()), atof(z.c_str()), atof(vx.c_str()), atof(vy.c_str()), atof(vz.c_str()), atof(mass.c_str()), name));
    }
    file.close();
}
int main(int argc, char* argv[])
{
    string str;
    string steps;
    if (argc == 3)
    {
        str = string(argv[1]);
        steps = atoi(argv[2]);
    }
    else
    {
        cout << "System: ";
        cin >> str;
        cout << "Number of steps: ";
        cin >> steps;
    }
    parse(str);
    ofstream file;
    file.open("output.txt");
    Integrator* calc=new Leapfrog(0.1);
    calc->start(bodies);
    for(vector<Body*>::iterator it = bodies.begin(); it != bodies.end(); ++it) {
        file<<(*it)->Print();
    }
    file<<'\n';
    register int i=0;
    for (i=0;i<atoi(steps.c_str());i++) {
        calc->tick(bodies);
        for(vector<Body*>::iterator it = bodies.begin(); it != bodies.end(); ++it) {
            file<<(*it)->Print();
        }
        file<<'\n';
    }


}
