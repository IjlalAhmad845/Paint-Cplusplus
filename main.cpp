#include <iostream>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<stdio.h>
#include<string.h>

#define pi 3.1415926536

using namespace std;
void draw();
int x1[500],y[500],x2[500],y2[500],color[500],i,k=2,d=0,selector[500];
float j,angle[500],bold[500];
int main()
{selector[0]=1;
int tool=1005;

cout<<"\t\t\t\t\t\t\tWARNING\n\t\t\t\t\t    use right click instead of left";
cout<<"\n\n\n\t\t\t\tThis program is in development so plzzz cooperate";
Sleep(6000);

initwindow(1300,700,"");
POINT m;m.x=0;m.y=0;
int counter,counter1=0,p=0;            ///-----------------declared variables (max 100 lines)
/**two counters because one is for out side of the tool box and other is for inside. we want
*/

for(i=0;i<10;i++)
{x1[i]=0;x2[i]=0;                                   ///-------------------------assign all coordinate variables to 0
    y[i]=0;y2[i]=0;
}i=0;

while(1)                                    ///=====================================infinite loop
    {GetCursorPos(&m);if(GetAsyncKeyState(VK_ESCAPE))break;
    floodfill(1,1,WHITE);                     ///---------------------------change screen BG color to white
draw();                         ///-------------call function to draw permanent lines

if(m.x<970 || m.y>200 && m.x<1245)          ///-----------------------when cursor is not in the tool box            **CURSOR***
circle(x1[i]+2,y[i]-2,3);            ///----------------------drawing pointer
else
   circle(m.x+2,m.y-2,3);           ///-----------------------when cursor is  in the tool box

rectangle(1000,20,1250,50);         ///=================created tool box                                ****TOOL BOX****
setfillstyle(SOLID_FILL,8);
rectangle(1000,150,1210,190);floodfill(1001,151,0);               ///--------------box for showing boldness of line
setfillstyle(SOLID_FILL,color[i]);
rectangle(1220,150,1260,190);floodfill(1221,151,BLACK);               ///---------------for showing current line color
line(1010,35,1240,35);
rectangle(1065,60,1120,100);rectangle(1075,65,1110,95);             ///rectangle
rectangle(1130,60,1185,100);circle(1158,80,15);                   ///circle
rectangle(1000,60,1055,100);                                        ///line
for(j=1;j<5;j++)line(1005,65+j,1050,90+j);

rectangle(1195,60,1250,100);                                    ///undo
for(j=0;j<5;j++)
{line(1210,78+j,1240,78+j);                                      ///------for undo
line(1210-j,79,1228,70);
line(1210-j,81,1228,90);}
///===========================================================================================================================

setfillstyle(SOLID_FILL,BLACK);              ///-------------color of moving element
if(m.x>=1015 && m.x<=1235)///+5 because tool has m.x-5
if(GetAsyncKeyState(VK_RBUTTON) && m.x>1000 && m.x<1250 && m.y>20 && m.y<50)
   {rectangle(m.x-5,25,m.x+5,45);floodfill(m.x,26,BLACK);floodfill(m.x,44,BLACK);tool=m.x-5;}  ///---------------moving element
///-------------------------------------------tool is created at cursor's position
    rectangle(tool,25,tool+10,45);floodfill(tool+5,26,BLACK);floodfill(tool+5,44,BLACK);///tool+5->middle
   bold[i]=(tool-1010)/10; ///storing pixels by tool (total 200 PPi in tool and 50 PPi in line) means 4.4 tool's PPi/line



for(j=0;j<5;j++)                                                            ///     *******CONTAINER********
{rectangle(970+j,0,1300,200+j);
rectangle(1250-j,200,1300,700);}
///======================================================================================================*****color box*******
for(j=0;j<=15;j++)          ///color starts from 0 to 15 (black to white)
{setfillstyle(SOLID_FILL,j);rectangle(1255,210+j*40,1287,240+j*40);floodfill(1256,211+j*40,0);}
            /// boxes coordinates are in A.P. so they can printed easily
setfillstyle(SOLID_FILL,15);rectangle(1177,105,1248,130);floodfill(1181,111,0);         ///eraser
setfillstyle(SOLID_FILL,8);rectangle(1260,60,1280,100);line(1262,62,1278,98);line(1262,98,1278,62);floodfill(1261,65,0);
                                                                                ///---------------------------clear all tool
///==============================================================================================================================



           ///================================**************tools name
setcolor(WHITE);settextstyle(10,0,1);
outtextxy(1180,107,"Eraser");
char tmp[20];
sprintf(tmp,"%d,%d PPi =%d",m.x,m.y,(tool-1010)/10);
outtextxy(1000,105,tmp);

setcolor(color[i]);
for(j=0.5;j<bold[i];j+=0.5)
{line(1010,170-j/2,1200,170-j/2);
line(1010,170+j/2,1200,170+j/2);
}
setcolor(BLACK);                                                                       ///******COLOR SELECTION********
if(GetAsyncKeyState(VK_RBUTTON))
{if(m.x>1251 && m.x<1286 && m.y>211+0*40 && m.y<239+0*40)color[i]=0;
else if(m.x>1251 && m.x<1286 && m.y>211+1*40 && m.y<239+1*40)color[i]=1;
else if(m.x>1251 && m.x<1286 && m.y>211+2*40 && m.y<239+2*40)color[i]=2;
else if(m.x>1251 && m.x<1286 && m.y>211+3*40 && m.y<239+3*40)color[i]=3;
else if(m.x>1251 && m.x<1286 && m.y>211+4*40 && m.y<239+4*40)color[i]=4;
else if(m.x>1251 && m.x<1286 && m.y>211+5*40 && m.y<239+5*40)color[i]=5;
else if(m.x>1251 && m.x<1286 && m.y>211+6*40 && m.y<239+6*40)color[i]=6;
else if(m.x>1251 && m.x<1286 && m.y>211+7*40 && m.y<239+7*40)color[i]=7;
else if(m.x>1251 && m.x<1286 && m.y>211+8*40 && m.y<239+8*40)color[i]=8;
else if(m.x>1251 && m.x<1286 && m.y>211+9*40 && m.y<239+9*40)color[i]=9;
else if(m.x>1251 && m.x<1286 && m.y>211+10*40 && m.y<239+10*40)color[i]=10;
else if(m.x>1251 && m.x<1286 && m.y>211+11*40 && m.y<239+11*40)color[i]=11;
else if(m.x>1251 && m.x<1286 && m.y>211+12*40 && m.y<239+12*40)color[i]=12;
else if(m.x>1251 && m.x<1286 && m.y>211+13*40 && m.y<239+013*40)color[i]=13;
else if(m.x>1251 && m.x<1286 && m.y>211+14*40 && m.y<239+14*40)color[i]=14;
else if(m.x>1178 && m.x<1247 && m.y>107 && m.y<129)color[i]=15;
color[i+1]=color[i];///----------------------for storing color automatically to next line when color is not selected  further
}
                                                                          ///*******EDITING*******
if(GetAsyncKeyState(VK_RBUTTON))
{
if(m.x>1261 && m.x<1279 && m.y>61 && m.y<99)         ///--------------------------swipe
{for(d=0;d<=i;d++)
    {x1[d]=x2[d]=y[d]=y2[d]=0;}
i=1;selector[i]=1;}
else if(m.x>1196 && m.x<1249 && m.y>61 && m.y<99)            ///--------------undo
    x1[d]=x2[d]=y[d]=y2[d]=0;
else if(m.x>1001 && m.x<1034 && m.y>61 && m.y<99)            ///========line selection
    selector[i]=1;
else if(m.x>1066 && m.y<1121 && m.y>61 && m.y<99)            ///========rectangle selection
    selector[i]=2;
if(m.x>1131 && m.x<1186 && m.y>61 && m.y<99)            ///=========circle selection
    selector[i]=3;

}
selector[i+1]=selector[i];          ///============================shifts tool to next line/rec/circle



if(GetAsyncKeyState(VK_RBUTTON)==0)                 ///================if key is not PRESSED            ***CONDITIONS***
{if(counter1!=0){d--;counter1=0;}       ///----if key is LOW then it rapidly come to this portion and counter1 is first time !=0
///and then become 0 so that value of d is not decrease further
    if(m.x<970 || m.y>200 && m.x<1245)
{if(counter!=0){i++;counter=0;}         ///switch to next line
   x1[i]=x2[i]=m.x;              ///--------------------------all coordinates are same
y[i]=y2[i]=m.y;}                          ///--------------stop storing values when cursor is in the box
}
if(m.x<970 || m.y>200 && m.x<1245)d=i-1;
if(GetAsyncKeyState(VK_RBUTTON)!=0)             ///======================if key is PRESSED
  {if(m.x<970 || m.y>200 && m.x<1245){x2[i]=m.x;y2[i]=m.y;counter++;}///----------stop storing values when cursor is in the box
 if(m.x>970 && m.y<200)counter1++;
///---------if cursor is in the box then counter1++ until the key is LOW
 setfillstyle(SOLID_FILL,CYAN);
  circle(m.x+2,m.y-1,3);
  floodfill(m.x+2,m.y-1,BLACK);
}                    ///--------------only ending coordinates are in control of the key (code of 1st line)
/**------------------------if button is pressed then value of 'c' is starts increasing then on releasing the button
the above stat runs and switch to new line & the previous variables values become permanent and we draw them by function **/
angle[i]=180/pi*atan2((y2[i]-y[i]),x1[i]-x2[i]);
///===============================================================================================================================
                        ///---------------for coordinates printing                              ****PAINTING TOOL BOX

setfillstyle(SOLID_FILL,DARKGRAY);
floodfill(976,1,BLACK);            ///changing tool color
floodfill(1041,61,BLACK);           ///for rectangle
floodfill(1080,66,BLACK);
floodfill(1111,61,BLACK);           ///for circle
floodfill(1160,80,BLACK);
floodfill(1001,21,BLACK);           ///for width
floodfill(1161,61,BLACK);           ///for paint
floodfill(1221,61,BLACK);           ///for undo
floodfill(1001,61,BLACK);           ///for line

///===============================================================================================================================
/**
function auto call and work as tool creator that create lines so this place is not required line function
*/
        setfillstyle(SOLID_FILL,WHITE);
   setactivepage(1-p);      ///----------------for remove glitch
 setvisualpage(p);cleardevice();
p=1-p;
}


closegraph();
}
void draw()
{   ///"<=" because if '<' only then it print the the line and vanish it rapidly and print the line
for(k=1;k<=i;k++)
{setcolor(color[k]);
for(j=0.5;j<=bold[k];j+=0.5)
    {if(selector[k]==1)
    {if((angle[k]>=135 && angle[k]<=180)||(angle[k]>=-179.999 && angle[k]<=-135)||(angle[k]>=-45 && angle[k]<=45))
{        ///apply inequality at last condition
           line(x1[k],y[k]+j,x2[k],y2[k]+j);}
        else
           line(x1[k]+j,y[k],x2[k]+j,y2[k]);
           }
           else if(selector[k]==2)
            rectangle(x1[k]+j,y[k]+j,x2[k]-j,y2[k]-j);
else if(selector[k]==3)
    ellipse((x1[k]+x2[k])/2,(y[k]+y2[k])/2,0,360,-j+(x2[k]-x1[k])/2,-j+(y2[k]-y[k])/2);}

setcolor(BLACK);///---------------------------------auto set to black after printing every line
}}
