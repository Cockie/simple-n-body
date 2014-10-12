#ifndef BODY_H
#define BODY_H
using namespace std;

class Body
{
    public:
        Body(double x_, double y_, double z_, double vx_, double vy_, double vz_, double mass_, string name_);
        virtual ~Body();
        double Getx() { return x; }
        void Setx(double val) { x = val; }
        double Gety() { return y; }
        void Sety(double val) { y = val; }
        double Getz() { return z; }
        void Setz(double val) { z = val; }
        double Getvx() { return vx; }
        void Setvx(double val) { vx = val; }
        double Getvy() { return vy; }
        void Setvy(double val) { vy = val; }
        double Getvz() { return vz; }
        void Setvz(double val) { vz = val; }
        double Getmass() { return mass; }
        void Setmass(double val) { mass = val; }
        string Getname() { return name; }
        void Setname(string val) { name = val; }
        void Setx1(double val) { x1 = val;}
        void Sety1(double val) { y1 = val;}
        void Setz1(double val) { z1 = val;}
        void Setvx1(double val) { vx1 = val;}
        void Setvy1(double val) { vy1 = val;}
        void Setvz1(double val) { vz1 = val;}
        void update();
        void updatev();
        void updater();
        string Print();
    protected:
    private:
        double x;
        double y;
        double z;
        double vx;
        double vy;
        double vz;
        double x1;
        double y1;
        double z1;
        double vx1;
        double vy1;
        double vz1;
        double mass;
        string name;
};

#endif // BODY_H
