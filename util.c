#include <stdio.h>
#include "util.h"
#include <math.h>

/* Example decision tree - see the HW2 description */
int dt0(int t, double p, double h, int s, int w) {
    int r = 0;
    if (t>35 && w!=3) r = 1;
    else if (t<=35 && s==0) r = 1;
    return r;
}
/* Provide your implementations for all the requested functions here */

char dt1a(float pl1a,float pw1a,float sl1a,float sw1a) {
  if (pl1a<2.45) {
    return 's';
  }
  else{
    if (pw1a<1.75) {
      if (pl1a<4.95) {
        if (pw1a<1.65) {
          return 'e';
        }
        else{
          return 'v';
        }
      }
      else{
        return 'v';
      }
    }
    else{
      return 'v';
    }
  }
}

char dt1b(float pl1b,float pw1b,float sl1b,float sw1b) {
  if (pl1b<2.55) {
    return 's';
  }
  else{
    if (pw1b<1.69) {
      if (pl1b<4.85) {
        return 'e';
      }
      else{
        return 'v';
      }
    }
    else{
      return 'v';
    }
  }
}

double dt2a(float x1a ,float x2a ,float x3a ,int x4a ,int x5a) {
  if (x1a<31.5) {
    if (x2a>-2.5) {
      return 5;
    }
    else{
      if ((x2a-0.1)<=x1a && x1a<=(x2a+0.1)) {
        return 2.1;
      }
      else{
        return -1.1;
      }
    }
  }

  else{
      if (-1<=x3a && x3a<=2) {
        return 1.4;
      }
      else{
        if (x4a & x5a) {
          return -2.23;
        }
        else{
          return 11;
        }
      }
  }
}

double dt2b(float x1b ,float x2b ,float x3b ,int x4b ,int x5b) {
  if (x1b>12 && x1b<22) {
    if (x3b>(5/3)) {
      return -2;
    }
    else{
      if ((x1b-0.1)<=x3b && x3b<=(x1b+0.1)) {
        return 1.01;
      }
      else{
        return -8;
      }
    }
  }

  else{
      if (x4b & x5b) {
        return -1;
      }
      else{
        if (-1<=x2b && x2b<=2) {
          return -(1/7);
        }
        else{
          return sqrt(2)/3;
        }
      }
  }
}
/*I calculate the time to stop for car.Weather,speed and night or day effects fraction coefficient and reflex time*/
double dt3a(double aspeed,double aweight,double atime_of_driving,int aroad_condition,int anight_or_day){
  double length_to_stop,fraction_coefficient,time_to_stop=0;
  if (aspeed<=75) {
    if (atime_of_driving<=6) {
      fraction_coefficient=0.85;
      time_to_stop+=1;
    }
    else{
      if (anight_or_day==0) {
        if (aroad_condition==0) {
          fraction_coefficient=0.85;
          time_to_stop+=1.5;
        }
        else{
          fraction_coefficient=0.4;
          time_to_stop+=1.5;
        }
      }
      else{
        fraction_coefficient=0.85;
        time_to_stop+=1.5;
      }
    }
  }

  else{
    if (aspeed<=150) {
      if (anight_or_day==0) {
        if (atime_of_driving<=4) {
          fraction_coefficient=0.6;
          time_to_stop+=1.5;
        }
        else{
          fraction_coefficient=0.6;
          time_to_stop+=1.75;
        }
      }
      else{
        fraction_coefficient=0.75;
        time_to_stop+=1.25;
      }
    }

    else{
      if (aroad_condition==0) {
        fraction_coefficient=0.65;
        time_to_stop+=1.5;
      }
      else{
        if (anight_or_day==0) {
          if (atime_of_driving<=4) {
            fraction_coefficient=0.25;
            time_to_stop+=1.75;
          }
          else{
            fraction_coefficient=0.25;
            time_to_stop+=2;
          }
        }
        else{
          fraction_coefficient=0.25;
          time_to_stop+=1.5;
        }
      }
    }
  }
  length_to_stop=(aweight*aspeed*aspeed)/(2*fraction_coefficient*aweight*10);
  time_to_stop+=length_to_stop/3.6/(aspeed/2);
  return time_to_stop;
}

double dt3b(double bspeed,double bweight,double btime_of_driving,int broad_condition,int bnight_or_day){
  double length_to_stop,fraction_coefficient,time_to_stop=0;

  if (bspeed<=75) {
    if (broad_condition==0) {
      fraction_coefficient=0.85;
      time_to_stop+=1.25;
    }
    else{
      if (btime_of_driving<=5) {
        fraction_coefficient=0.35;
        time_to_stop+=1;
      }
      else{
        if (bnight_or_day==0) {
          fraction_coefficient=0.35;
          time_to_stop+=2;
        }
        else{
          fraction_coefficient=0.35;
          time_to_stop+=1.5;
        }
      }
    }
  }

  else if(bspeed<=150){
    if (bnight_or_day==0) {
      if (broad_condition==0) {
        fraction_coefficient=0.6;
        time_to_stop+=1.5;
      }
      else{
        if (btime_of_driving<=4) {
          fraction_coefficient=0.25;
          time_to_stop+=2;
        }
        else{
          fraction_coefficient=0.25;
          time_to_stop+=2.5;
        }
      }
    }
    else{
      fraction_coefficient=0.6;
      time_to_stop+=1.5;
    }
  }

  else{
    if (broad_condition==0) {
      fraction_coefficient=0.4;
      time_to_stop+=1.5;
    }
    else{
      if (bnight_or_day==0) {
        if (btime_of_driving<=3) {
          fraction_coefficient=0.15;
          time_to_stop+=1.7;
        }
        else{
          fraction_coefficient=0.15;
          time_to_stop+=2.75;
        }
      }
      else{
        fraction_coefficient=0.15;
        time_to_stop+=1.5;
      }
    }
  }
  length_to_stop=(bweight*bspeed*bspeed)/(2*fraction_coefficient*bweight*10);
  time_to_stop+=length_to_stop/3.6/(bspeed/2);
  return time_to_stop;
}
