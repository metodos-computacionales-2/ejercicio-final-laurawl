#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <fstream>

//Global variables declaring
const double G=9.8;
const double dt=0.001; //Step for th method //M_PI/300.0;
const double eps=0.0001;
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
  Pendulum p;//Time 
  int N = atoi(argv[1]);//steps of evolution
  // intialization
  for (float i=1.35; i<=1.70; i+=0.0001)
  {
    initial_conditions(p,i); 
    double mod=0.0;
    double dif=0.001;
    double t=0.0;
    for (int ii=1; ii<=N; ii++)
    {
      euler_cromer(p,dt,t);
      if(abs(mod-3*M_PI)<dif)
      {
         mod=0;
         std::cout << t << "\t" << p.Theta << "\t" << p.W  << "\t" << p.Fd << std::endl;  
      }
      mod+=dt;
      t+=dt;
        
      
    }
  }
  return 0;
}


void euler_cromer(Pendulum & p,double dt,double t)
{
  p.W=p.W+(-(G/p.L)*sin(p.Theta) - p.q*p.W + p.Fd*sin(p.Omega*t))*dt;
  p.Theta=p.Theta + p.W*dt;
  if(p.Theta < - M_PI)
    {
      p.Theta += 2*M_PI;
    }
  else if(p.Theta > M_PI)
    {
      p.Theta += -2*M_PI;
    }
} 
 
void initial_conditions(Pendulum & p, float f)
{
  p.q=0.5;
  p.Fd=f;
  p.Omega=0.666;
  p.L=G;
  p.W=0.0;
  p.Theta=0.2;  
}