#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <fstream>

//Global variables declaring
const double G=9.8;
const double dt=0.01; //Step for th method //M_PI/300.0;
const double eps=0.001;
//theta''+g/l theta + q theta' = F_d sin(Omega t)

class Pendulum
{
public:
  double L; //Lenght
  double q; //Friction coeficient
  float Fd; //External Force
  double Omega; //External force frequency
  double W; //Angular velocity 
  double Theta; //Angle
  Pendulum();// Initial values for the class
  ~Pendulum();//Anihilator
};
Pendulum::Pendulum()
{
  L=0.0;
  q=0.0;
  Fd=0.0;
  Omega=0.0;
  W=0.0;
  Theta=0.0;
}
Pendulum::~Pendulum()
{
}

void initial_conditions(Pendulum &p, float f);
void euler_cromer(Pendulum &p,double dt,double t);


int main(int argc, char** argv)
{
  Pendulum p;
  double t=0.0;//Time 
  double t_m=0.0;
  int N = atoi(argv[1]);
  float f = atoi(argv[2]);//steps of evolution
  // intialization
    initial_conditions(p,f);
    for (int ii=1; ii<=N; ii++)
    {
         std::cout << t << "\t" << p.Theta << "\t" << p.W  << "\t" << p.Fd << std::endl;  
         t+=dt;
    }
  }
  return 0;
}