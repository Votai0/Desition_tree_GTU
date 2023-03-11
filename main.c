#include <stdio.h>
#include "util.h"
//absolute==abs()

int main() {
  char quit;
  do {
      /* Asking for the problem selection (0,1,2,3) */
      int part_select;
      printf("Please select your problem\n0-Problem 0\n1-Problem 1\n2-Problem 2\n3-Problem 3\n");
      scanf("%d",&part_select);

      if (part_select==0) {
        int temperature,sunny_or_not,day_of_week,return_value;
        double pressure,humidity;

        printf("Please enter temperature:");
        scanf("%d",&temperature);
        do {
          printf("Please enter sunny or not(0 sunny,1 not):");
          scanf("%d",&sunny_or_not);
        } while(!(sunny_or_not==0 || sunny_or_not==1));
        printf("Please enter day of week:");
        scanf("%d",&day_of_week);
        printf("Please enter pressure:");
        scanf("%lf",&pressure);
        printf("Please enter humidity:");
        scanf("%lf",&humidity);

        return_value=dt0(temperature,pressure,humidity,sunny_or_not,day_of_week);
        printf("%d\n",return_value);
      }

      else if (part_select==1) {//part1
        float pl,pw,sl,sw;
        char dta,dtb;/*results of functions*/

        printf("Please enter pl: ");
        scanf("%f",&pl);
        printf("Please enter pw: ");
        scanf("%f",&pw);
        printf("Please enter sl: ");
        scanf("%f",&sl);
        printf("Please enter sw: ");
        scanf("%f",&sw);

        dta=dt1a(pl,pw,sl,sw);
        dtb=dt1b(pl,pw,sl,sw);

        if (dta==dtb) {
          if (dta=='s') {
            printf("setosa\n");
          }
          else if(dta=='v'){
            printf("virginica\n");
          }
          else{
            printf("versicolor\n");
          }
        }
        else{//if tree a and tree b's results aren't equal print both part
          if (dta=='s') {
            printf("dta : setosa\n");
            if (dtb=='s') {
              printf("dtb : setosa\n");
            }
            else if(dtb=='v'){
              printf("dtb : virginica\n");
            }
            else{
              printf("dtb : versicolor\n");
            }
          }
          else if(dta=='v'){
            printf("dta : virginica\n");
            if (dtb=='s') {
              printf("dtb : setosa\n");
            }
            else if(dtb=='v'){
              printf("dtb : virginica\n");
            }
            else{
              printf("dtb : versicolor\n");
            }
          }
          else{
            printf("dta : versicolor\n");
            if (dtb=='s') {
              printf("dtb : setosa\n");
            }
            else if(dtb=='v'){
              printf("dtb : virginica\n");
            }
            else{
              printf("dtb : versicolor\n");
            }
          }
        }
      }

      else if (part_select==2) {//part2
        float x1,x2,x3;
        int x4,x5;
        double dta,dtb;/*results of functions*/

        printf("Please enter x1:");
        scanf("%f",&x1);
        printf("Please enter x2:");
        scanf("%f",&x2);
        printf("Please enter x3:");
        scanf("%f",&x3);
        do {
          printf("Please enter x4:");
          scanf("%d",&x4);
        } while(!(x4==0 || x4==1));

        do {
          printf("Please enter x5:");
          scanf("%d",&x5);
        } while(!(x5==0 || x5==1));

        dta=dt2a(x1,x2,x3,x4,x5);
        dtb=dt2b(x1,x2,x3,x4,x5);

        if (dta-dtb<CLOSE_ENOUGH && dtb-dta<CLOSE_ENOUGH) {
          printf("%lf\n",(dta+dtb)/2);
        }
        else if(dta==dtb){
          printf("%lf\n",dta);
        }
        else{
          printf("%lf,%lf\n",dta,dtb);
        }
      }

      else if(part_select==3){//part3
        double speed,weight,time_of_driving;
        int road_condition,night_or_day;
        double x1,x2;/*return values of functions*/

        printf("Please enter speed: ");
        scanf("%lf",&speed);
        printf("Please enter weight: ");
        scanf("%lf",&weight);

        do {/*control road conditions 0 or 1*/
          printf("Please enter road conditions 0 or 1 (0:dry,1:wet):");
          scanf("%d",&road_condition);
        } while(!(road_condition==1 || road_condition==0));

        do {/*control night or day 0 or 1*/
          printf("Please enter night or day (0:night,1:day):");
          scanf("%d",&night_or_day);
        } while(!(night_or_day==0 || night_or_day==1));

        printf("Please enter time of driving: ");
        scanf("%lf",&time_of_driving);

        x1=dt3a(speed,weight,time_of_driving,road_condition,night_or_day);
        x2=dt3b(speed,weight,time_of_driving,road_condition,night_or_day);
        if (x1==x2) {
          printf("Same values\n%lf,%lf\n",x1,x2);
        }
        else{
          printf("Different values\n%lf,%lf\n",x1,x2);
        }
      }

      else{
        printf("Please enter valid part number.\n");
      }

      printf("\n\nFor exit press q letter.For continue select operation\n");
      scanf("%c",&quit);
      scanf("%c",&quit);/*this is for solve bug*/

    } while(quit!='q');

  return 0;
}
