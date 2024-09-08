#include <iostream>            //for input and output of statements
#include "youregraphics.h"     // including library 
#include<conio.h>              //to use getch
#include<windows.h>            //to include sound
#include<fstream>              //to read and write data in files


using namespace std;


// intitializing


int ball_x = 500, ball_y = 500, ball_y2 = 15, ball_x2 = 15, x = 5, y = 5; int  bat_x = 500, bat_y = 550, brick_x[5][14], brick_y[5][14], health[5][14];
int brkx = 100, brky = 80;
int lives = 3, score = 0;
bool quit;


void updatebatcoll() {
    if (ball_y + ball_y2 == 550 && ball_x >= bat_x && ball_x2 + ball_x <= bat_x + 190 && ball_y <= bat_y + 5) {
        //PlaySound(TEXT("one_beep-99630.wav"), NULL, SND_FILENAME | SND_ASYNC);
        y = -5;
        if (ball_x + ball_x2 > bat_x + 95) {    //collosin to right side of the bat
            x = 5;
        }
        if (ball_x + ball_x2 < bat_x + 95) {      //collosin to left side of the bat
            x = -5;
        }
        // collosion to the center straight collosion 
        if (ball_x + ball_x2 == bat_x + 70 || ball_x + ball_x2 == bat_x + 71 || ball_x + ball_x2 == bat_x + 72 || ball_x + ball_x2 == bat_x + 73 || ball_x + ball_x2 == bat_x + 74 || ball_x + ball_x2 == bat_x + 75 || ball_x + ball_x2 == bat_x + 76 || ball_x + ball_x2 == bat_x + 77 || ball_x + ball_x2 == bat_x + 78 || ball_x + ball_x2 == bat_x + 79 || ball_x + ball_x2 == bat_x + 80 || ball_x + ball_x2 == bat_x + 81 || ball_x + ball_x2 == bat_x + 82 || ball_x + ball_x2 == bat_x + 83 || ball_x + ball_x2 == bat_x + 84 || ball_x + ball_x2 == bat_x + 85 || ball_x + ball_x2 == bat_x + 86 || ball_x + ball_x2 == bat_x + 87 || ball_x + ball_x2 == bat_x + 88 || ball_x + ball_x2 == bat_x + 89 || ball_x + ball_x2 == bat_x + 90 || ball_x + ball_x2 == bat_x + 91 || ball_x + ball_x2 == bat_x + 92 || ball_x + ball_x2 == bat_x + 93 || ball_x + ball_x2 == bat_x + 94 || ball_x + ball_x2 == bat_x + 95 || ball_x + ball_x2 == bat_x + 96 || ball_x + ball_x2 == bat_x + 97 || ball_x + ball_x2 == bat_x + 98 || ball_x + ball_x2 == bat_x + 99 || ball_x + ball_x2 == bat_x + 100 || ball_x + ball_x2 == bat_x + 101 || ball_x + ball_x2 == bat_x + 102 || ball_x + ball_x2 == bat_x + 103 || ball_x + ball_x2 == bat_x + 104 || ball_x + ball_x2 == bat_x + 105) {
            x = 0;
        }
    }
}
void brickcoll() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 14; j++) {
            if (health[i][j] > 0) {          //showing the breaking of bricks
                if (ball_y <= brick_y[i][j] + 20 && ball_x >= brick_x[i][j] && ball_x2 + ball_x <= brick_x[i][j] + 75) {
                    //PlaySound(TEXT("mario-coin-200bpm-82548.wav"), NULL, SND_FILENAME | SND_ASYNC);
                    y *= -1;
                    score++;         //counting score
                    gotoxy(22, 2);
                    cout << score * 10;  //one brick is equal to 10 points
                    drawRectangle(brick_x[i][j], brick_y[i][j], brick_x[i][j] + 55, brick_y[i][j] + 20, 12, 12, 12, 12, 12, 12);
                    health[i][j]--;
                    if (health[i][j] > 0)//for double collosion
                    {
                        //PlaySound(TEXT("mixkit-hitting-golf-ball-2080.wav"), NULL, SND_FILENAME | SND_ASYNC);
                        drawRectangle(brick_x[i][j], brick_y[i][j], brick_x[i][j] + 55, brick_y[i][j] + 20, 255, 255, 255, 255, 0, 0);
                    }
                }
            }
        }
    }
}
void printbricks() {
    for (int i = 0; i < 1; i++) {
        for (int j = 0; j < 14; j++) {
            drawRectangle(brkx, brky, brkx + 55, brky + 20, 255, 255, 255, 0, 255, 0);           //making grid of bricks
            brick_x[i][j] = brkx;              //     storing the x cordinates of indivisual brick
            brick_y[i][j] = brky;                 //     storing the y cordinates of indivisual brick
            health[i][j] = 2;


            brkx += 65;
        }
        brky += 30;
        brkx = 100;
    }
    for (int i = 1; i < 5; i++)
    {
        for (int j = 0; j < 14; j++) {

            drawRectangle(brkx, brky, brkx + 55, brky + 20, 255, 255, 255, 255, 0, 25);           //making grid of bricks
            brick_x[i][j] = brkx;              //     storing the x cordinates of indivisual brick
            brick_y[i][j] = brky;                 //     storing the y cordinates of indivisual brick
            health[i][j] = 1;

            brkx += 65;
        }
        brky += 30;
        brkx = 100;
    }
    //makig boundary 
    drawLine(90, 70, 1010, 70, 255);
    drawLine(90, 570, 90, 70, 255);
    drawLine(90, 570, 1010, 570, 255);
    drawLine(1010, 570, 1010, 70, 255);
}
void ball(int start) {
    if (start == 1) {
        drawEllipse(500, 500, 515, 515, 255, 255, 255, 255, 255, 255);
    }
    drawEllipse(ball_x, ball_y, ball_x + ball_x2, ball_y + ball_y2, 12, 12, 12, 12, 12, 12);
    updatebatcoll();
    brickcoll();


    //collosion with walls 


    if (ball_x <= 95 || ball_x + ball_x2 >= 1000) {
        //PlaySound(TEXT("mixkit-light-impact-on-the-ground-2070.wav"), NULL, SND_FILENAME | SND_ASYNC);
        x *= -1;
    }
    if (ball_y <= 70 + 10 || ball_y + ball_y2 >= 570 - 10) {
        //PlaySound(TEXT("mixkit-light-impact-on-the-ground-2070.wav"), NULL, SND_FILENAME | SND_ASYNC);
        y *= -1;
    }
    if (ball_y + ball_y2 >= 570 - 10)                    //To disapeare the ball when it hits the floor 
    {
        //PlaySound(TEXT("gameboy-pluck-41265.wav"), NULL, SND_FILENAME | SND_ASYNC);
        lives--;         // decriment in lives 
        gotoxy(22, 0);
        cout << lives; cout << endl;
        ball_x *= -ball_x;
    }
    ball_x += x;
    ball_y += y;
    drawEllipse(ball_x, ball_y, ball_x + ball_x2, ball_y + ball_y2, 255, 255, 255, 255, 255, 255);
}
void bat(int start) {
    int getch();
    drawRectangle(bat_x, bat_y, bat_x + 170, bat_y + 5, 12, 12, 12, 12, 12, 12);
    if (start == 1) {
        bat_x = 500;
        drawRectangle(bat_x, 550, bat_x + 170, 555, 255, 255, 255, 255, 255, 255);
    }
    char key = getKey(), ch;
    if (key == 'a' || key == 'A') {       //left movement
        if (bat_x >= 115)
        {
            bat_x = bat_x - 30;
        }
    }
    if (key == 'd' || key == 'D')         //right movment
    {
        if (bat_x < 830) {
            bat_x = bat_x + 30;
        }
    }
    if (key == 's' || key == 'S')
    {
        ofstream  data_write("saved.txt");
        for (int i = 0; i < 5; i++) {                        // saving in file the location of bricks
            for (int j = 0; j < 14; j++) {
                data_write << health[i][j] << endl;
            }
        }
        // saving in file the location of ball ,bat and score. 
        data_write << ball_x << endl;
        data_write << ball_y << endl;
        data_write << ball_y2 << endl;
        data_write << ball_x2 << endl;
        data_write << bat_x << endl;
        data_write << bat_y << endl;
        data_write << x << endl;
        data_write << y << endl;
        data_write << score << endl;
        data_write << lives << endl;
        gotoxy(100, 0); cout << "SAVED";
    }
    if (key == 'q' || key == 'Q')            //quit game
    {
        quit = true;
    }
    if (key == 'p' || key == 'P')            //pause game
    {
        drawRectangle(bat_x, 550, bat_x + 170, 555, 255, 255, 255, 255, 255, 255);
        gotoxy(100, 2);
        cout << " paused";
        while (1) {
            ch = getch();
            if (ch == 'R' || ch == 'r')  //resume game
            {
                gotoxy(100, 2);
                cout << "Resumed";
                break;
            }
        }
    }
    drawRectangle(bat_x, 550, bat_x + 170, 555, 255, 255, 255, 255, 255, 255);
}


int main() {

    showConsoleCursor(false);
   //   PlaySound(TEXT("winsquare-6993.wav"), NULL, SND_FILENAME | SND_ASYNC);
    gotoxy(40, 0);
    cout << "Welcome to Brick Breaker Game";
    //  PlaySound(TEXT("winsquare-6993.wav"), NULL, SND_FILENAME | SND_ASYNC); PlaySound(TEXT("winsquare-6993.wav"), NULL, SND_FILENAME | SND_ASYNC); PlaySound(TEXT("winsquare-6993.wav"), NULL, SND_FILENAME | SND_ASYNC); PlaySound(TEXT("winsquare-6993.wav"), NULL, SND_FILENAME | SND_ASYNC); 

    gotoxy(0, 0);
    cout << "  L "; Sleep(250); cout << "  I "; Sleep(250); cout << "  V "; Sleep(250); cout << "  E "; Sleep(250); cout << "  S :   "; Sleep(250);
    gotoxy(22, 0);
    cout << lives;
    cout << "\n\n";
    cout << "  S  C  O  R  E :     ";
    gotoxy(40, 0);
    cout << "  Press any key to Start Game";
    gotoxy(35, 2);
    cout << "'P' for pause & 'R' for resume & 'Q' to quit ";
    printbricks();
    char load = _getch();
    if (load == 'l' || load == 'L')
    {
        fstream data_read("saved.txt");        // reading the file 
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 14; j++) {
                data_read >> health[i][j];                // the location of  bricks
                if (health[i][j] == 0) {                                                       // the location of broken  bricks
                    drawRectangle(brick_x[i][j], brick_y[i][j], brick_x[i][j] + 55, brick_y[i][j] + 20, 12, 12, 12, 12, 12, 12);
                }
            }
        }// using the changed variable from the file  location of ball ,bat and score. 
        data_read >> ball_x;
        data_read >> ball_y;
        data_read >> ball_y2;
        data_read >> ball_x2;
        data_read >> bat_x;
        data_read >> bat_y;
        data_read >> x;
        data_read >> y;
        data_read >> score;
        data_read >> lives;
    }
    while (1)
    {
        bat(0);
        ball(0);                  //calling functions of ball and bat 
        Sleep(10);
        if (ball_y + ball_y2 >= 570 - 10) //detection if ball fell down 
        {
            drawEllipse(ball_x, ball_y, ball_x + ball_x2, ball_y + ball_y2, 12, 12, 12, 12, 12, 12);

            ball(1);        // reprinting of ball after loss of life
            ball_x = 500;
            ball_y = 500;
            bat(1);        // reprinting of bat after loss of one life
        }
        if (quit == true)            //quit game
        {
            cls();
            gotoxy(50, 15);
            cout << "GAME QUIT\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
            break;

        }
        if (lives == 0) {
            cls();
           // PlaySound(TEXT("videogame-death-sound-43894.wav"), NULL, SND_FILENAME | SND_ASYNC);
            cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tG "; Sleep(250); cout << " A "; Sleep(250); cout << " M "; Sleep(250); cout << " E "; Sleep(250); cout << " O "; Sleep(250); cout << " V "; Sleep(250); cout << " E "; Sleep(250); cout << " R "; Sleep(250); cout << "\n\n";
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
            break;
        }
        if (score == 84) {
            cls();
         //   PlaySound(TEXT("winsquare-6993.wav"), NULL, SND_FILENAME | SND_ASYNC);

            cout << "\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tG "; Sleep(250); cout << " A "; Sleep(250); cout << " M "; Sleep(250); cout << " E "; Sleep(250); cout << " O "; Sleep(250); cout << " V "; Sleep(250); cout << " E "; Sleep(250); cout << " R "; Sleep(250);
            cout << "\n\n\t\t\t\t\t\tY "; Sleep(250); cout << " O "; Sleep(250); cout << " U "; Sleep(250); cout << "       W "; Sleep(250); cout << " I "; Sleep(250); cout << " N "; Sleep(250);
            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
            break;
        }
    }
    system("pause");
    return 0;
}