#include<iostream>
#include <graphics.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include<math.h>
#include<ctime>

#define S_N_L (radius-10)        // Second Needle Length
#define S_N_C RED                   // Second needle Color
#define M_N_L (radius-20)           // Minute Needle Length
#define M_N_C LIGHTRED              // Minute Needle Color
#define H_N_L (radius-(radius/2))       // Hour Needle Length
#define H_N_C CYAN                     // Hour Needle Color

float cx,cy;
float radius=100;

void draw_face(float radius);
void get_time(int &h,int &m,int &s);
void second_needle(int s);
void minute_needle(int m,int s);
void hour_needle(int h,int m,int s);
using namespace std;

//8//
int outline()
{
    // Main Base
    line(100, 600, 1100, 600);

    // 1st Line
    line(300, 600, 300, 300);

    // 2nd Line
    line(600, 600, 600, 300);

    // 3rd Line
    line(900, 600, 900, 300);

    // Printing Message
    settextstyle(8, 0, 2);
    outtextxy(290, 620, "(1)");
    outtextxy(590, 620, "(2)");
    outtextxy(890, 620, "(3)");
}

// Function for moving the Green Disk
// to Third Tower On Top Of Blue Disk
void p7()
{
    getch();
    cleardevice();
    settextstyle(8, 0, 4);
    outtextxy(500, 50, "7th Phase");
    setfillstyle(SOLID_FILL, BLUE);
    rectangle(850, 500, 950, 550);
    floodfill(855, 545, 15);
    setfillstyle(SOLID_FILL, GREEN);
    rectangle(875, 450, 925, 500);
    floodfill(880, 495, 15);
    setfillstyle(SOLID_FILL, RED);
    rectangle(825, 600, 975, 550);
    floodfill(830, 555, 15);

    // Calling outline() function
    outline();
}

// Function to find the moving the Blue
// Disk To Third Tower On Top Of Red Disk
void p6()
{
    getch();
    cleardevice();
    settextstyle(8, 0, 4);
    outtextxy(500, 50, "6th Phase");
    setfillstyle(SOLID_FILL, BLUE);
    rectangle(850, 500, 950, 550);
    floodfill(855, 545, 15);
    setfillstyle(SOLID_FILL, GREEN);
    rectangle(275, 600, 325, 550);
    floodfill(280, 595, 15);
    setfillstyle(SOLID_FILL, RED);
    rectangle(825, 600, 975, 550);
    floodfill(830, 555, 15);

    // Calling outline() function
    outline();
}

// Function to find the moving Green Disk
// To the First Tower
void p5()
{
    getch();
    cleardevice();
    settextstyle(8, 0, 4);
    outtextxy(500, 50, "5th Phase");
    setfillstyle(SOLID_FILL, BLUE);
    rectangle(550, 550, 650, 600);
    floodfill(555, 595, 15);
    setfillstyle(SOLID_FILL, GREEN);
    rectangle(275, 600, 325, 550);
    floodfill(280, 595, 15);
    setfillstyle(SOLID_FILL, RED);
    rectangle(825, 600, 975, 550);
    floodfill(830, 555, 15);

    // Calling outline() function
    outline();
}

// Moving Red Disk To Third Tower
void p4()
{
    getch();
    cleardevice();
    settextstyle(8, 0, 4);
    outtextxy(500, 50, "4th Phase");
    setfillstyle(SOLID_FILL, BLUE);
    rectangle(550, 550, 650, 600);
    floodfill(555, 595, 15);
    setfillstyle(SOLID_FILL, GREEN);
    rectangle(575, 500, 625, 550);
    floodfill(580, 545, 15);
    setfillstyle(SOLID_FILL, RED);
    rectangle(825, 600, 975, 550);
    floodfill(830, 555, 15);

    // Calling outline() function
    outline();
}

// Function for moving the Green Disk
// To Second Tower On Top Of Blue Disk
void p3()
{
    getch();
    cleardevice();
    settextstyle(8, 0, 4);
    outtextxy(500, 50, "3rd Phase");
    setfillstyle(SOLID_FILL, BLUE);
    rectangle(550, 550, 650, 600);
    floodfill(555, 595, 15);
    setfillstyle(SOLID_FILL, GREEN);
    rectangle(575, 500, 625, 550);
    floodfill(580, 545, 15);
    setfillstyle(SOLID_FILL, RED);
    rectangle(225, 550, 375, 600);
    floodfill(230, 590, 15);

    // Calling outline() function
    outline();
}

// Function for moving the Blue Disk
// To Second Tower
void p2()
{
    getch();
    cleardevice();
    settextstyle(8, 0, 4);
    outtextxy(500, 50, "2nd Phase");
    setfillstyle(SOLID_FILL, BLUE);
    rectangle(550, 550, 650, 600);
    floodfill(555, 595, 15);
    setfillstyle(SOLID_FILL, GREEN);
    rectangle(875, 600, 925, 550);
    floodfill(880, 595, 15);
    setfillstyle(SOLID_FILL, RED);
    rectangle(225, 550, 375, 600);
    floodfill(230, 590, 15);

    // Calling outline() function
    outline();
}

// Function for moving the Green Disk
// To Third Tower
void p1()
{
    getch();
    cleardevice();
    settextstyle(8, 0, 4);
    outtextxy(500, 50, "1st Phase");
    setfillstyle(SOLID_FILL, GREEN);
    rectangle(875, 600, 925, 550);
    floodfill(880, 595, 15);
    setfillstyle(SOLID_FILL, RED);
    rectangle(225, 550, 375, 600);
    floodfill(230, 590, 15);
    setfillstyle(SOLID_FILL, BLUE);
    rectangle(250, 500, 350, 550);
    floodfill(255, 545, 15);

    // Calling outline() function
    outline();
}

// Function to start the animations
void start()
{
    // Starting Condition
    cleardevice();
    settextstyle(8, 0, 4);
    outtextxy(500, 50, "TOWER OF HANOI");

    // Red Coloring Of Disk
    setfillstyle(SOLID_FILL, RED);
    rectangle(225, 550, 375, 600);
    floodfill(230, 590, 15);

    // Blue Coloring Of Disk
    setfillstyle(SOLID_FILL, BLUE);
    rectangle(250, 500, 350, 550);
    floodfill(255, 545, 15);

    // Green Coloring Of Disk
    setfillstyle(SOLID_FILL, GREEN);
    rectangle(275, 450, 325, 500);
    floodfill(285, 495, 15);

    // calling outline() function
    outline();
}

//9999999//
class doll
{
public:
    void dolldraw(int x)
    {
        int y=100;
        circle(x,y+10,10);
        line(x,y+20,x,y+100);
        line(x,y+40,x-20,y+70);
        line(x,y+40,x+20,y+70);
        line(x,y+100,x-20,y+120);
        line(x,y+100,x+20,y+120);
    }
    void dollmoll(int x)
    {
        int y=100;
        circle(x,y+10,10);
        line(x,y+20,x,y+100);
        line(x,y+50,x-20,y+30);
        line(x,y+50,x+20,y+30);
        line(x,y+100,x-20,y+90);
        line(x,y+100,x+20,y+90);
    }

};

//10//
void planetMotion(int xrad, int yrad,
                  int midx, int midy,
                  int x[70], int y[70])
{
    int i, j = 0;

    // Positions of planets in their
    // corresponding orbits
    for (i = 360; i > 0; i = i - 6)
    {
        x[j] = midx - (xrad * cos((i * 3.14) / 180));
        y[j++] = midy - (yrad * sin((i * 3.14) / 180));
    }

    return;
}


int main()
{

    int n;
    int gd = DETECT, gm;
    int gdriver = DETECT, gmode, errorcode;
    int d=DETECT,m;
    int err;
    int i, j = 0;

    cout<<"++ Projects Details ++"<<endl;
    cout<<"1. My Detail."<<endl;
    cout<<"2. Emoji "<<endl;
    cout<<"3. Football Feild "<<endl;
    cout<<"4. Bycyle "<<endl;
    cout<<"5. Clock "<<endl;
    cout<<"6. Rollball "<<endl;
    cout<<"7. Car "<<endl;
    cout<<"8. Tower of Hanoi "<<endl;
    cout<<"9. Dancing Doll "<<endl;
    cout<<"10. Solar System "<<endl;
    cout<<"11. Tajmahal "<<endl;

    while(1)
    {
        cout<<"Choose the option: ";
        cin>>n;

        if(n==1)
        {
            //initgraph(&gd, &gm, "");
            initwindow(1000,800,"Rifat");

            //R
            setcolor(11);
            line(50,49,50,70);
            arc(52,56,270,90,7);
            line(50,62,58,70);
            //I
            line(64,70,72,70);
            line(68,50,68,70);
            line(64,50,72,50);
            //F
            line(80,50,80,70);
            line(80,50,92,50);
            line(80,60,92,60);
            //A
            line(96,70,103,50);
            line(103,50,110,70);
            line(100,62,107,62);
            //T
            line(120,50,120,70);
            line(112,50,128,50);

            //A
            line(145,70,152,50);
            line(152,50,159,70);
            line(149,62,156,62);
            //L
            line(165,50,165,70);
            line(165,70,175,70);
            //I
            line(180,50,188,50);
            line(184,50,184,70);
            line(180,70,188,70);

//id

            arc(52,101,75,279,11);//c
            //s
            arc(65,96,40,260,6);
            arc(63,107,220,95,6);
            //E
            line(77,90,77,110);
            line(77,90,87,90);
            line(77,110,87,110);
            line(77,100,84,100);
            //2
            arc(94,97,270,90,8);
            line(94,104,94,112);
            line(94,112,102,112);
            //0
            ellipse(112,102,0,360,7,11);
            ellipse(129,102,0,360,7,11);
            //1
            line(142,92,142,112);
            ellipse(154,102,0,360,7,11);//0
            line(165,92,165,112);//1
            circle(175,96,6);
            arc(172,102,270,90,11);//9
            line(187,92,187,112);//1
            ellipse(200,102,0,360,7,11);//0
            circle(222,107,6);
            arc(222,102,80,280,11);//6

            getch();
            closegraph();

        }
        else if(n==2)
        {
            initgraph(&gd, &gm, "");

            //R
            line(50,49,50,70);
            arc(52,56,270,90,7);
            line(50,62,58,70);
            //I
            line(64,70,72,70);
            line(68,50,68,70);
            line(64,50,72,50);
            //F
            line(80,50,80,70);
            line(80,50,92,50);
            line(80,60,92,60);
            //A
            line(96,70,103,50);
            line(103,50,110,70);
            line(100,62,107,62);
            //T
            line(120,50,120,70);
            line(112,50,128,50);

            //A
            line(145,70,152,50);
            line(152,50,159,70);
            line(149,62,156,62);
            //L
            line(165,50,165,70);
            line(165,70,175,70);
            //I
            line(180,50,188,50);
            line(184,50,184,70);
            line(180,70,188,70);

//id

            arc(52,101,75,279,11);//c
            //s
            arc(65,96,40,260,6);
            arc(63,107,220,95,6);
            //E
            line(77,90,77,110);
            line(77,90,87,90);
            line(77,110,87,110);
            line(77,100,84,100);
            //2
            arc(94,97,270,90,8);
            line(94,104,94,112);
            line(94,112,102,112);
            //0
            ellipse(112,102,0,360,7,11);
            ellipse(129,102,0,360,7,11);
            //1
            line(142,92,142,112);
            ellipse(154,102,0,360,7,11);//0
            line(165,92,165,112);//1
            circle(175,96,6);
            arc(172,102,270,90,11);//9
            line(187,92,187,112);//1
            ellipse(200,102,0,360,7,11);//0
            circle(222,107,6);
            arc(222,102,80,280,11);//6

            setcolor(YELLOW);
            circle(300, 100, 40);
            setfillstyle(SOLID_FILL, YELLOW);
            floodfill(300, 100, YELLOW);
            // Set color of background to black
            setcolor(BLACK);
            setfillstyle(SOLID_FILL, BLACK);
            // Use fill ellipse for creating eyes
            fillellipse(310, 85, 2, 6);
            fillellipse(290, 85, 2, 6);
            // Use ellipse for creating mouth
            ellipse(300, 100, 205, 335, 20, 9);
            ellipse(300, 100, 205, 335, 20, 10);
            ellipse(300, 100, 205, 335, 20, 11);

            getch();
            closegraph();
            initgraph(&gd, &gm, "");

            //R
            line(50,49,50,70);
            arc(52,56,270,90,7);
            line(50,62,58,70);
            //I
            line(64,70,72,70);
            line(68,50,68,70);
            line(64,50,72,50);
            //F
            line(80,50,80,70);
            line(80,50,92,50);
            line(80,60,92,60);
            //A
            line(96,70,103,50);
            line(103,50,110,70);
            line(100,62,107,62);
            //T
            line(120,50,120,70);
            line(112,50,128,50);

            //A
            line(145,70,152,50);
            line(152,50,159,70);
            line(149,62,156,62);
            //L
            line(165,50,165,70);
            line(165,70,175,70);
            //I
            line(180,50,188,50);
            line(184,50,184,70);
            line(180,70,188,70);

//id

            arc(52,101,75,279,11);//c
            //s
            arc(65,96,40,260,6);
            arc(63,107,220,95,6);
            //E
            line(77,90,77,110);
            line(77,90,87,90);
            line(77,110,87,110);
            line(77,100,84,100);
            //2
            arc(94,97,270,90,8);
            line(94,104,94,112);
            line(94,112,102,112);
            //0
            ellipse(112,102,0,360,7,11);
            ellipse(129,102,0,360,7,11);
            //1
            line(142,92,142,112);
            ellipse(154,102,0,360,7,11);//0
            line(165,92,165,112);//1
            circle(175,96,6);
            arc(172,102,270,90,11);//9
            line(187,92,187,112);//1
            ellipse(200,102,0,360,7,11);//0
            circle(222,107,6);
            arc(222,102,80,280,11);//6

            setcolor(YELLOW);
            circle(300, 100, 40);
            setfillstyle(SOLID_FILL, YELLOW);
            floodfill(300, 100, YELLOW);
            // Set color of background to black
            setcolor(BLACK);
            setfillstyle(SOLID_FILL, BLACK);
            // Use fill ellipse for creating eyes
            fillellipse(310, 85, 2, 6);
            fillellipse(290, 85, 2, 6);
            // Use ellipse for creating mouth
            ellipse(300, 100, 205, 335, 20, 9);
            ellipse(300, 100, 205, 335, 20, 10);
            ellipse(300, 100, 205, 335, 20, 11);

            getch();
            closegraph();
        }
        else if(n==3)
        {
            initgraph(&gd, &gm, "");
            initwindow(1400,1400,"Rifat");

            // Ground Outline
            rectangle(100, 50, 1200, 550);

            // Coloring Green
            setfillstyle(SOLID_FILL, GREEN);
            floodfill(150, 150, 15);

            // Ground Middle Line
            line(650, 50, 650, 550);
            line(656, 50, 656, 550);

            // Coloring White
            setfillstyle(SOLID_FILL, WHITE);
            floodfill(652, 150, 15);

            // Mid Circles
            circle(653, 300, 60);
            circle(653, 300, 65);
            circle(653, 300, 10);

            // Outer Rectangle Left
            rectangle(100, 200, 250, 400);
            rectangle(100, 205, 245, 395);

            // Inner Rectangle Left
            rectangle(100, 230, 200, 370);
            rectangle(100, 235, 195, 365);

            // Arc Left Side
            arc(250, 300, 270, 90, 40);
            arc(250, 300, 270, 90, 35);

            // Outer Rectangle Right
            rectangle(1200, 200, 1050, 400);
            rectangle(1200, 205, 1055, 395);

            // Inner Rectangle Right
            rectangle(1200, 230, 1100, 370);
            rectangle(1200, 235, 1105, 365);

            // Arc Right Side
            arc(1051, 300, 90, 270, 40);
            arc(1051, 300, 90, 270, 35);

            // Coloring All White
            floodfill(714, 300, 15);
            floodfill(592, 300, 15);
            floodfill(657, 300, 15);
            floodfill(645, 300, 15);
            floodfill(247, 300, 15);
            floodfill(197, 300, 15);
            floodfill(287, 300, 15);
            floodfill(1053, 300, 15);
            floodfill(1103, 300, 15);
            floodfill(1013, 300, 15);

            // Holding Screen For a While
            getch();

            // Close the initialized gdriver
            closegraph();
        }
        else if(n==4)
        {
            int i, a;

            // Path of the program
            initgraph(&gd, &gm, "");


            // Move the cycle
            for (i = 0; i < 600; i++)
            {
                // Upper body of cycle
                line(50 + i, 405, 100 + i, 405);
                line(75 + i, 375, 125 + i, 375);
                line(50 + i, 405, 75 + i, 375);
                line(100 + i, 405, 100 + i, 345);
                line(150 + i, 405, 100 + i, 345);
                line(75 + i, 365, 75 + i, 375);
                line(70 + i, 365, 80 + i, 365);
                line(80 + i, 345, 100 + i, 345);

                // Wheel
                circle(150 + i, 405, 30);
                circle(50 + i, 405, 30);


                // Road
                line(0, 436, getmaxx(), 436);
                line(0, 442, getmaxx(), 442);
                line(0, 438, getmaxx(), 438);
                line(0, 440, getmaxx(), 440);

                // Stone
                rectangle(getmaxx() - i, 436,
                          650 - i, 431);

                // Stop the screen for 10 secs
                delay(20);

                // Clear the screen
                cleardevice();
            }


            getch();

            // Close the graph
            closegraph();
        }
        else if(n==5)
        {
            initgraph(&gdriver,&gmode,"");

//R
            line(50,49,50,70);
            arc(52,56,270,90,7);
            line(50,62,58,70);
            //I
            line(64,70,72,70);
            line(68,50,68,70);
            line(64,50,72,50);
            //F
            line(80,50,80,70);
            line(80,50,92,50);
            line(80,60,92,60);
            //A
            line(96,70,103,50);
            line(103,50,110,70);
            line(100,62,107,62);
            //T
            line(120,50,120,70);
            line(112,50,128,50);

            //A
            line(145,70,152,50);
            line(152,50,159,70);
            line(149,62,156,62);
            //L
            line(165,50,165,70);
            line(165,70,175,70);
            //I
            line(180,50,188,50);
            line(184,50,184,70);
            line(180,70,188,70);

//id

            arc(52,101,75,279,11);//c
            //s
            arc(65,96,40,260,6);
            arc(63,107,220,95,6);
            //E
            line(77,90,77,110);
            line(77,90,87,90);
            line(77,110,87,110);
            line(77,100,84,100);
            //2
            arc(94,97,270,90,8);
            line(94,104,94,112);
            line(94,112,102,112);
            //0
            ellipse(112,102,0,360,7,11);
            ellipse(129,102,0,360,7,11);
            //1
            line(142,92,142,112);
            ellipse(154,102,0,360,7,11);//0
            line(165,92,165,112);//1
            circle(175,96,6);
            arc(172,102,270,90,11);//9
            line(187,92,187,112);//1
            ellipse(200,102,0,360,7,11);//0
            circle(222,107,6);
            arc(222,102,80,280,11);//6
            /***********************************/
            cx=getmaxx()/2.0; // cx is center x value.
            cy=getmaxy()/2.0; // cy is center y value.
            /** Now the point (cx,cy) is the center of your screen. **/

            float x,y;
            int hour,minute,second;
            draw_face(radius);
            while(!kbhit())
            {
                get_time(hour,minute,second);
                second_needle(second);
                minute_needle(minute,second);
                hour_needle(hour,minute,second);
                circle(cx,cy,2);
                delay(100);
            }


            getch();
            closegraph();
        }
        else if(n==6)
        {
            initgraph(&d,&m,"");
            float x=1,y=0.00000,j=.5,count=.1;
            float r=15;
            setcolor(GREEN);
            line(0,215,650,215);
            line(0,216,650,216);
            line(0,217,650,217);
            line(0,218,650,218);
            sleep(1);
            for(int k=0; k<=7; k++)
            {

                for(float i=90; i<270; i+=10)
                {
                    y=cos(((i*22/7)/180))/j;

                    if(y>0)
                        y=-y;
                    x+=5;

                    setcolor(14);
                    setfillstyle(1,14);
                    circle(x,y*100+200,r);
                    floodfill(x,y*100+200,14);

                    delay(100);

                    setcolor(0);
                    setfillstyle(1,0);
                    circle(x,y*100+200,r);
                    floodfill(x,y*100+200,0);

                }

                j+=count;
                count+=.1;

            }
            getch();

        }
        else if(n==7)
        {
            initgraph(&gd, &gm, "");

            for (i = 0; i <= 420; i = i + 10)
            {

                setcolor(1);
                line(0, 346, getmaxx(), 346);
                line(0, 350, getmaxx(), 350);
                line(0, 348, getmaxx(), 348);
                line(0, 352, getmaxx(), 352);

                // Set color of car as red
                setcolor(2);

                // These lines for bonnet and
                // body of car
                line(0 + i, 300, 210 + i, 300);
                line(50 + i, 300, 75 + i, 270);
                line(75 + i, 270, 150 + i, 270);
                line(150 + i, 270, 165 + i, 300);
                line(0 + i, 300, 0 + i, 330);
                line(210 + i, 300, 210 + i, 330);

                // For left wheel of car
                circle(65 + i, 330, 15);
                circle(65 + i, 330, 2);

                // For right wheel of car
                circle(145 + i, 330, 15);
                circle(145 + i, 330, 2);

                // Line left of left wheel
                line(0 + i, 330, 50 + i, 330);

                // Line middle of both wheel
                line(80 + i, 330, 130 + i, 330);

                // Line right of right wheel
                line(210 + i, 330, 160 + i, 330);

                delay(150);


                setcolor(BLACK);

                // Lines for bonnet and body of car
                line(0 + i, 300, 210 + i, 300);
                line(50 + i, 300, 75 + i, 270);
                line(75 + i, 270, 150 + i, 270);
                line(150 + i, 270, 165 + i, 300);
                line(0 + i, 300, 0 + i, 330);
                line(210 + i, 300, 210 + i, 330);

                // For left wheel of car
                circle(65 + i, 330, 15);
                circle(65 + i, 330, 2);

                // For right wheel of car
                circle(145 + i, 330, 15);
                circle(145 + i, 330, 2);

                // Line left of left wheel
                line(0 + i, 330, 50 + i, 330);

                // Line middle of both wheel
                line(80 + i, 330, 130 + i, 330);

                // Line right of right wheel
                line(210 + i, 330, 160 + i, 330);


            }

            getch();

            closegraph();
        }
        else if(n==8)
        {
            initgraph(&gd, &gm, "");
            initwindow(1300,800,"Rifat");

            //R
            line(50,49,50,70);
            arc(52,56,270,90,7);
            line(50,62,58,70);
            //I
            line(64,70,72,70);
            line(68,50,68,70);
            line(64,50,72,50);
            //F
            line(80,50,80,70);
            line(80,50,92,50);
            line(80,60,92,60);
            //A
            line(96,70,103,50);
            line(103,50,110,70);
            line(100,62,107,62);
            //T
            line(120,50,120,70);
            line(112,50,128,50);

            //A
            line(145,70,152,50);
            line(152,50,159,70);
            line(149,62,156,62);
            //L
            line(165,50,165,70);
            line(165,70,175,70);
            //I
            line(180,50,188,50);
            line(184,50,184,70);
            line(180,70,188,70);

//id

            arc(52,101,75,279,11);//c
            //s
            arc(65,96,40,260,6);
            arc(63,107,220,95,6);
            //E
            line(77,90,77,110);
            line(77,90,87,90);
            line(77,110,87,110);
            line(77,100,84,100);
            //2
            arc(94,97,270,90,8);
            line(94,104,94,112);
            line(94,112,102,112);
            //0
            ellipse(112,102,0,360,7,11);
            ellipse(129,102,0,360,7,11);
            //1
            line(142,92,142,112);
            ellipse(154,102,0,360,7,11);//0
            line(165,92,165,112);//1
            circle(175,96,6);
            arc(172,102,270,90,11);//9
            line(187,92,187,112);//1
            ellipse(200,102,0,360,7,11);//0
            circle(222,107,6);
            arc(222,102,80,280,11);//6

            // Calling start() function
            start();

            // Calling p1() function
            p1();

            // Calling p2() function
            p2();

            // Calling p3() function
            p3();

            // Calling p4() function
            p4();

            // Calling p5() function
            p5();

            // Calling p6() function
            p6();

            // Calling p7() function
            p7();

            // Holding screen for a while
            getch();

            // Close the initialized gdriver
            closegraph();
        }
        else if(n==9)
        {
            doll a,b,c,d,e;
            int h,i,j,k;
            initgraph(&gd,&gm,"");

            int w=50;
            while(!kbhit())
            {
                a.dolldraw(w);
                h=w+45;
                b.dolldraw(h);
                j=h+45;
                c.dolldraw(j);
                i=j+45;
                d.dolldraw(i);
                k=i+45;
                e.dolldraw(k);
                delay(600);
                cleardevice();
                w=250;
                a.dollmoll(w);
                b.dollmoll(h);
                c.dollmoll(i);
                d.dollmoll(j);
                e.dollmoll(k);
                delay(600);
                cleardevice();
            }
            getch();
            closegraph();
        }
        else if(n==10)
        {
            int i = 0, midx, midy;
            int xrad[9], yrad[9], x[9][70], y[9][70];
            int pos[9], planet[9], tmp;

            initwindow(1000,700,"Rifat");
            //initgraph(&gdriver, &gmode, "");


            err = graphresult();

            if(err != grOk)
            {

                // Error occurred
                printf("Graphics Error: %s",grapherrormsg(err));
                return 0;
            }


            // Mid positions at x and y-axis
            midx = getmaxx() - 450;
            midy = getmaxy() - 280;

            // Manipulating radius of all
            // the nine planets
            planet[0]=8;
            for (i = 1; i < 9; i++)
            {
                planet[i] = planet[i - 1] + 1;
            }

            // Offset position for the planets
            // on their corresponding orbit
            for (i = 0; i < 9; i++)
            {
                pos[i] = i * 6;
            }

            // Orbits for all 9 planets
            xrad[0] = 70, yrad[0] = 40;
            for (i = 1; i < 9; i++)
            {
                xrad[i] = xrad[i - 1] + 38;
                yrad[i] = yrad[i - 1] + 20;
            }

            // Positions of planets on their
            // corresponding orbits
            for (i = 0; i < 9; i++)
            {
                planetMotion(xrad[i], yrad[i],
                             midx, midy, x[i],
                             y[i]);
            }

            while (!kbhit())
            {

                // Drawing 9 orbits
                setcolor(WHITE);
                for (i = 0; i < 9; i++)
                {
                    setcolor(CYAN);
                    ellipse(midx, midy, 0, 360,
                            xrad[i], yrad[i]);
                }

                // Sun at the mid of solar system
                outtextxy(midx, midy, " SUN");
                setcolor(YELLOW);
                setfillstyle(SOLID_FILL, YELLOW);
                circle(midx, midy, 30);
                floodfill(midx, midy, YELLOW);

                // Mercury in first orbit
                setcolor(CYAN);

                setfillstyle(SOLID_FILL, CYAN);
                outtextxy(x[0][pos[0]],
                          y[0][pos[0]],
                          " MERCURY");

                pieslice(x[0][pos[0]],
                         y[0][pos[0]],
                         0, 360, planet[0]);

                // Venus in second orbit
                setcolor(GREEN);
                setfillstyle(SOLID_FILL, GREEN);
                outtextxy(x[1][pos[1]],
                          y[1][pos[1]],
                          " VENUS");
                pieslice(x[1][pos[1]],
                         y[1][pos[1]],
                         0, 360, planet[1]);

                // Earth in third orbit
                setcolor(BLUE);
                setfillstyle(SOLID_FILL, BLUE);
                outtextxy(x[2][pos[2]],
                          y[2][pos[2]],
                          " EARTH");
                pieslice(x[2][pos[2]],
                         y[2][pos[2]],
                         0, 360, planet[2]);

                // Mars in fourth orbit
                setcolor(RED);
                setfillstyle(SOLID_FILL, RED);
                outtextxy(x[3][pos[3]],
                          y[3][pos[3]],
                          " MARS");
                pieslice(x[3][pos[3]],
                         y[3][pos[3]],
                         0, 360, planet[3]);

                // Jupiter in fifth orbit
                setcolor(BROWN);
                setfillstyle(SOLID_FILL, BROWN);
                outtextxy(x[4][pos[4]],
                          y[4][pos[4]],
                          " JUPITER");
                pieslice(x[4][pos[4]],
                         y[4][pos[4]],
                         0, 360, planet[4]);

                // Saturn in sixth orbit
                setcolor(LIGHTGRAY);
                setfillstyle(SOLID_FILL, LIGHTGRAY);
                outtextxy(x[5][pos[5]],
                          y[5][pos[5]],
                          " SATURN");
                pieslice(x[5][pos[5]],
                         y[5][pos[5]],
                         0, 360, planet[5]);

                // Uranus in seventh orbit
                setcolor(LIGHTGREEN);
                setfillstyle(SOLID_FILL, LIGHTGREEN);
                outtextxy (x [6] [pos [6]],
                           y [6] [pos [6]],"URANUS");
                pieslice (x [6] [pos [6]],
                          y [6] [pos [6]],
                          0, 360, planet [6]);

                // Neptune in eighth orbit
                setcolor (LIGHTBLUE);
                setfillstyle (SOLID_FILL, LIGHTBLUE);
                outtextxy (x [7] [pos [7]],
                           y [7] [pos [7]],
                           " NEPTUNE");
                pieslice (x [7] [pos [7]],
                          y [7] [pos [7]],
                          0, 360, planet [7]);

                // Pluto in ninth orbit
                setcolor (LIGHTRED);
                setfillstyle (SOLID_FILL, LIGHTRED);
                outtextxy (x [8] [pos [8]],
                           y [8] [pos [8]],
                           " PLUTO");
                pieslice (x [8] [pos [8]],
                          y [8] [pos [8]],
                          0, 360, planet [8]);

                // Checking for one complete
                // rotation
                for (i = 0; i < 9; i++)
                {
                    if (pos[i] <= 0)
                    {
                        pos[i] = 59;
                    }
                    else
                    {
                        pos[i] = pos[i] - 1;
                    }
                }

                // Sleep for 100 milliseconds
                delay (100);

                // Clears graphic screen
                cleardevice ();
            }

            closegraph();
        }
        else if(n==11)
        {
            initwindow(700,800,"Rifat");

  //R
    line(50,49,50,70);
    arc(52,56,270,90,7);
    line(50,62,58,70);
    //I
    line(64,70,72,70);
    line(68,50,68,70);
    line(64,50,72,50);
    //F
    line(80,50,80,70);
    line(80,50,92,50);
    line(80,60,92,60);
    //A
    line(96,70,103,50);
    line(103,50,110,70);
    line(100,62,107,62);
    //T
    line(120,50,120,70);
    line(112,50,128,50);

    //A
    line(145,70,152,50);
    line(152,50,159,70);
    line(149,62,156,62);
    //L
    line(165,50,165,70);
    line(165,70,175,70);
    //I
    line(180,50,188,50);
    line(184,50,184,70);
    line(180,70,188,70);

//id

    arc(52,101,75,279,11);//c
    //s
    arc(65,96,40,260,6);
    arc(63,107,220,95,6);
    //E
    line(77,90,77,110);
    line(77,90,87,90);
    line(77,110,87,110);
    line(77,100,84,100);
    //2
    arc(94,97,270,90,8);
    line(94,104,94,112);
    line(94,112,102,112);
    //0
    ellipse(112,102,0,360,7,11);
    ellipse(129,102,0,360,7,11);
    //1
    line(142,92,142,112);
    ellipse(154,102,0,360,7,11);//0
    line(165,92,165,112);//1
    circle(175,96,6);
    arc(172,102,270,90,11);//9
    line(187,92,187,112);//1
    ellipse(200,102,0,360,7,11);//0
    circle(222,107,6);
    arc(222,102,80,280,11);//6

 rectangle(1,450,620,470);
 line(10,450,12,380);
 line(40,450,38,380);
 line(9,380,41,380);
 line(9,375,41,375);
 ellipse(10,377,90,270,3,3);
 ellipse(41,378,270,90,3,3);
 line(12,375,14,320);
 line(38,375,36,320);

       // ellipse(25,331,0,360,12,2.5);

 line(11,320,39,320);
 line(11,315,39,315);
 ellipse(11,318,90,270,3,2);
 ellipse(39,318,270,90,3,2);
 line(14,315,16,250);
 line(36,315,34,250);

       // ellipse(25,268,0,360,10,4);

 ellipse(25,244,20,200,11,6);
 ellipse(25,245,200,10,11,6);
 line(17,239,17,227);
 line(33,239,33,227);
 line(14,227,37,227);
 ellipse(14,224,90,270,3,3);
 ellipse(36,224,270,90,3,3);
 ellipse(25,220,0,180,10,13);
 line(25,207,25,197);


 //right
 line(580,450,582,380);
 line(610,450,608,380);
 line(578,380,612,380);
 line(578,375,612,375);
 ellipse(579,377,90,270,3,3);
 ellipse(612,378,270,90,3,3);
 line(582,375,584,320);
 line(608,375,606,320);
 line(581,320,611,320);
 line(581,315,611,315);
 ellipse(581,318,90,270,3,2);
 ellipse(611,318,270,90,3,2);
 line(584,315,586,250);
 line(606,315,604,250);

       // ellipse(25,268,0,360,10,4);

 ellipse(595,245,20,200,11,6);
 ellipse(595,246,200,10,11,6);
 line(585,242,585,227);
 line(603,242,603,227);
 line(583,227,605,227);
 ellipse(583,224,90,270,3,3);
 ellipse(605,224,270,90,3,3);
 ellipse(594,220,0,180,10,13);
 line(593,207,593,197);


rectangle(245,340,345,450);
rectangle(235,330,355,450);
line(263,390,263,450);
line(330,390,330,450);
ellipse(297, 390,0,180,34,34);
rectangle(235,325,355,330);
line(235,317,235,325);
line(355,317,355,325);
ellipse(295,316,0,180,60,9);
ellipse(295,270, 320,220,75,75);
line(260,203,290,180);

       line(330,203,290,180);


       circle(290,178,3);

       ellipse(290,168,0,360,2,6);

       ellipse(290,158,0,360,1,4);

       line(290,148,290,155);


       rectangle(355,345,420,450);

       line(460,363,460,450);

       line(416,345,460,363);


       line(397,397,370,397);

       line(370,397,370,366);

       line(397,397,397,366);

       ellipse(383,374,30,150,15,15);


       line(370,424,370,450);

       line(397,424,397,450);

       ellipse(383,432,30,150,15,15);



       line(430,397,450,397);

       line(450,397,450,376);

       line(430,397,430,376);

       ellipse(440,385,30,150,11,15);


       line(450,424,450,450);

       line(430,424,430,450);

       ellipse(440,432,30,150,11,15);


       line(401,318,401,344);

       ellipse(378,327,40,130,34,12);

       line(361,309,406,309);

       line(406,309,403,318);


 ellipse(383,334,30,89,24,50);

 ellipse(381,338,85,120,26,55);

 line(383,274,382,282);

 line(383,274,385,284);


       //left

       rectangle(235,345,165,450);

       line(125,363,125,450);

       line(165,345,125,363);


       line(185,397,211,397);

       line(185,397,185,366);

       line(211,397,211,366);

       ellipse(198,374,30,150,15,15);


       line(185,424,185,450);

       line(211,424,211,450);

       ellipse(198,432,30,150,15,15);



       line(135,397,155,397);

       line(135,397,135,376);

       line(155,397,155,376);

       ellipse(145,385,30,150,11,15);
       line(135,424,135,450);
       line(155,424,155,450);
ellipse(145,432,30,150,11,15);
line(189,318,189,344);
ellipse(212,327,45,130,34,12);
line(187,309,230,309);
line(187,309,190,318);
 ellipse(217,310,100,180,26,32);

 ellipse(210,319,70,85,26,40);

 line(212,270,209,280);

 line(212,270,215,280);


       //pool left


 line(112,450,110,415);

 line(84,450,86,415);


 line(83,415,113,415);

 line(83,410,113,410);

 ellipse(82,412,90,270,3,2);
 ellipse(113,412,270,90,3,2);
 line(86,410,88,370);
 line(110,410,108,370);

       // ellipse(25,331,0,360,12,2.5);
 line(86,370,110,370);
 line(86,365,110,365);
 ellipse(86,368,90,270,3,2);
 ellipse(110,368,270,90,3,2);
 line(88,365,90,335);
 line(108,365,106,335);

       // ellipse(25,268,0,360,10,4);

 ellipse(98,330,20,200,11,6);
 ellipse(98,330,200,10,11,6);
 line(90,327,90,314);
 line(106,327,106,314);
 line(87,314,109,314);
 ellipse(87,311,90,270,3,3);
 ellipse(109,311,270,90,3,3);
 ellipse(98,307,0,180,10,13);
 line(98,295,98,284);

       // right
 line(474,450,475,420);
 line(500,450,498,420);
 line(472,415,500,415);
 line(472,420,500,420);
 ellipse(472,418,90,270,3,2);
 ellipse(500,418,270,90,3,2);
 line(475,415,477,375);
 line(498,415,496,375);

       // ellipse(25,331,0,360,12,2.5);

 line(474,374,499,374);
 line(474,370,499,370);
 ellipse(473,372,90,270,3,2);
 ellipse(499,372,270,90,3,2);
 line(495,369,493,340);
 line(476,369,478,340);

       // ellipse(25,268,0,360,10,4);

ellipse(485,334,20,200,11,6);
ellipse(485,334,200,10,11,6);
line(478,329,478,317);
line(492,329,492,317);
line(496,316,474,316);
ellipse(473,312,90,270,3,3);
ellipse(495,312,270,90,3,3);
ellipse(484,309,0,180,10,13);
line(484,295,484,284);

settextstyle(4,0,5);
outtextxy(300,50,"TAJ MAHAL");

 getch();
 closegraph();
        }
        else
        {
            cout<<"Wrong Input. Try Again."<<endl;
        }
    }

}
void draw_face(float radius)
{

    int theta=0; // theta is the angle variable.
    float x,y;
    /** Draw Clock Border. **/
    circle(cx,cy,radius+24);
    circle(cx,cy,radius+23);
    /** Draw GREEN material border. **/
    setcolor(BROWN);    // I like a wooden frame!
    /** Paint the border. **/
    for(int i=0; i<9; i++)
        circle(cx,cy,radius+13+i);
    /** Set the color white. **/
    setcolor(WHITE);
    /** Draw outer-inner border. **/
    circle(cx,cy,radius+12);
    circle(cx,cy,radius+10);
    /** Draw center dot. **/
    circle(cx,cy,2);
    int i=0;
    /** DRAW NUMERIC POINTS **/
    do
    {
        /** Getting (x,y) for numeric points **/
        x=cx+radius*cos(theta*M_PI/180);
        y=cy+radius*sin(theta*M_PI/180);
        /** Draw Numeric Points **/
        circle(x,y,2);
        /* Draw Dots around each numeric points **/
        circle(x+5,y,0);
        circle(x-5,y,0);
        circle(x,y+5,0);
        circle(x,y-5,0);
        /** Increase angle by 30 degrees, which is the circular distance between each numeric points. **/
        theta+=30;
        /** Increase i by 1. **/
        i++;

    }
    while(i!=12);   //LIMIT NUMERIC POINTS UPTO =12= Numbers.
    i=0;
    /** DRAW DOTS BETWEEN NUMERIC POINTS. **/
    do
    {
        putpixel(cx+radius*cos(i*M_PI/180),cy+radius*sin(i*M_PI/180),DARKGRAY);
        i+=6;
    }
    while(i!=360);

    /** FACE COMPLETELY DRAWN. **/
}
//================
/** Function to get the current time. **/
void get_time(int &h,int &m,int &s)
{
    time_t rawtime;
    struct tm *t;
    time(&rawtime);
    t = gmtime(&rawtime);
    h=t->tm_hour+6;
    m=t->tm_min;
    s=t->tm_sec;
}
//=================
/** Function to draw Second needle. **/
void second_needle(int s)
{

    float angle=-90;
    float sx,sy;
    setcolor(0);
    sx=cx+S_N_L*cos((angle+s*6-6)*M_PI/180);
    sy=cy+S_N_L*sin((angle+s*6-6)*M_PI/180);
    line(cx,cy,sx,sy);
    setcolor(S_N_C);
    sx=cx+S_N_L*cos((angle+s*6)*M_PI/180);
    sy=cy+S_N_L*sin((angle+s*6)*M_PI/180);
    line(cx,cy,sx,sy);
}
/** Function to draw Minute needle. **/
void minute_needle(int m,int s)
{
    float angle=-90;
    float sx,sy;
    setcolor(0);
    sx=cx+M_N_L*cos((angle+m*6-6)*M_PI/180);
    sy=cy+M_N_L*sin((angle+m*6-6)*M_PI/180);
    line(cx,cy,sx,sy);
    setcolor(M_N_C);
    sx=cx+M_N_L*cos((angle+m*6/*+(s*6/60)*/)*M_PI/180);
    sy=cy+M_N_L*sin((angle+m*6/*+(s*6/60)*/)*M_PI/180);
    line(cx,cy,sx,sy);
}
/** Function to draw Hour needle. **/
void hour_needle(int h,int m,int s)
{
    float angle=-90;
    float sx,sy;
    setcolor(0);
    sx=cx+H_N_L*cos((angle+h*30-(m*30/60))*M_PI/180);
    sy=cy+H_N_L*sin((angle+h*30-(m*30/60))*M_PI/180);
    line(cx,cy,sx,sy);
    setcolor(H_N_C);
    sx=cx+H_N_L*cos((angle+h*30+(m*30/60))*M_PI/180);
    sy=cy+H_N_L*sin((angle+h*30+(m*30/60))*M_PI/180);
    line(cx,cy,sx,sy);
}


