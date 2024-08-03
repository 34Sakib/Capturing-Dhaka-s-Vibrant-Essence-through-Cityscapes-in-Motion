//Computer Graphics Final Project - Sec: H
//Group No - 06
//Member 1 - Istyak Ahmed (ID:21-45658-3)
//Member 2 - Sakib Al Mahamud (21-45655-3)
//Member 3 - Sakibul Haque Tanmoy (21-45659-3)


#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <cmath>
#include <windows.h>
#include <mmsystem.h>
#include <iostream>
#include <cstdlib>
#include <ctime>


//A,D,space ->> Move train
//M -> Morning, N->Night
//T-Traffic Sound
//1 -> Scene1
//2 -> Scene2


void display();
void reshape(int, int);
void trainTimer(int);
void handleKeyPress(unsigned char, int, int);
void drawCircle(float, float, float);
void drawCircle2(float, float, float);
void drawCircle3(float, float, float);
void drawCircle4(float, float, float);


int state = 0;
int spaceState = 0;
int environmentState = 0;
int sceneNo = 1;


int trainXposition = 1500;
int trainSpeed = 7;


int trafficSoundState = 0;


int car1Xposition = 1100;
int carSpeed = 4;



int car2Xposition = 2200;
int car3Xposition = -2300;
int car4Xposition = -1600;



int truckXPosition = -500;

int truck2Xposition = 0;


int sideWalkColorRed = 0.8;
int sideWalkColorGreen = 0.8;
int sideWalkColorBlue = 0.8;




float cloud1Position = -50;
float cloud2Position = -350;
float cloud3Position = -750;
float cloud4Position = 1000;
float cloud5Position = 500;
float cloud6Position = 200;


float cloudSpeed = 0.2;
//Change Background Color

//Boat2 Animation Function
GLfloat position1 = 0.0f;
GLfloat speed1 = 10.0f;
void boat2_update(int value) {
    if (position1 <= -2400) {
        position1 = 0;
    }
    position1 -= speed1;

    glutPostRedisplay();

    glutTimerFunc(70, boat2_update, 0);
}

//Wave Animation Function
GLfloat position2 = 0.0f;
GLfloat speed2 = 10.0f;

void wave2_update(int value) {
    if (position2 >= -960) {
        position2 = -1562;
    }
    position2 += speed2;

    glutPostRedisplay();

    glutTimerFunc(70, wave2_update, 0);
}


GLfloat position3 = 0.0f;
GLfloat speed3 = 10.0f;

void boat1_update(int value) {
    if (position3 >= 1363) {
        position3 = -400;
    }
    position3 += speed3;

    glutPostRedisplay();

    glutTimerFunc(70, boat1_update, 0);
}


void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(1920, 1080);
    glutCreateWindow("Window 1");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(1000, trainTimer, 0);
    glutKeyboardFunc(handleKeyPress);
    glutTimerFunc(40, boat2_update, 0);
    glutTimerFunc(70, wave2_update, 0);
    glutTimerFunc(70, boat1_update, 0);
    init();

    glutMainLoop();


}



//int SkyRed=131;
//int SkyGreen=231;
//int SkyBlue=246;

//int SkyRed=46;
//int SkyGreen=65;
//int SkyBlue=144;

int cloudColorRed = 255;
int cloudColorGreen = 255;
int cloudColorBlue = 255;

int BuildingWhiteColorRed = 255;
int BuildingWhiteColorGreen = 255;
int BuildingWhiteColorBlue = 255;

int BuildingBlueGlassColorRed = 67;
int BuildingBlueGlassColorGreen = 187;
int BuildingBlueGlassColorBlue = 240;


int mainBuildingColorRed = 235;
int mainBuildingColorGreen = 171;
int mainBuildingColorBlue = 122;


int mainBuildingWindowColorRed = 189;
int mainBuildingWindowColorGreen = 138;
int mainBuildingWindowColorBlue = 97;


int BackgroundBuilding1ColorRed = 127;
int BackgroundBuilding1ColorGreen = 178;
int BackgroundBuilding1ColorBlue = 229;

int BackgroundBuilding2ColorRed = 127;
int BackgroundBuilding2ColorGreen = 204;
int BackgroundBuilding2ColorBlue = 204;


int grassColorRed = 159;
int grassColorGreen = 217;
int grassColorBlue = 0;

int trainBaseColorRed = 255;
int trainBaseColorGreen = 255;
int trainBaseColorBlue = 255;

int trainBaseColor2Red = 255;
int trainBaseColor2Green = 255;
int trainBaseColor2Blue = 255;

int trainWindowColorRed = 90;
int trainWindowColorGreen = 90;
int trainWindowColorBlue = 90;


int trainBaseGreenColorRed = 0;
int trainBaseGreenColorGreen = 174;
int trainBaseGreenColorBlue = 86;

int car1YellowColorRed = 254;
int car1YellowColorGreen = 185;
int car1YellowColorBlue = 1;


int car1BlackColorRed = 72;
int car1BlackColorGreen = 72;
int car1BlackColorBlue = 72;



int car2GreenColorRed = 34;
int car2GreenColorGreen = 139;
int car2GreenColorBlue = 34;



int car4WhiteColorRed = 255;
int car4WhiteColorGreen = 255;
int car4WhiteColorBlue = 255;



int truck1RedcolorRed = 221;
int truck1RedcolorGreen = 67;
int truck1RedcolorBlue = 55;


int truck2BluecolorRed = 1;
int truck2BluecolorGreen = 142;
int truck2BluecolorBlue = 230;

int trainStationLightColorRed = 193;
int trainStationLightColorGreen = 196;
int trainStationLightColorBlue = 196;




int lampPostLightColorRed = 150;
int lampPostLightColorGreen = 150;
int lampPostLightColorBlue = 150;


//All of Drawing is in this Display Function

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    //Gradient Sky

    //Day
    if (sceneNo == 1) {
        if (environmentState == 0) {


            int SkyRed = 131;   //DAY SKY
            int SkyGreen = 231;
            int SkyBlue = 246;
            glBegin(GL_QUADS);
            glColor3ub(SkyRed, SkyGreen, SkyBlue); //TOP gradient
            glVertex2f(960, 540);
            glVertex2f(-960, 540);
            glColor3ub(SkyRed + 124, SkyGreen + 24, SkyBlue + 9);//Bottom Gradient
            glVertex2f(-960, -0);
            glVertex2f(960, -0);
            glEnd();



            BuildingWhiteColorRed = 255;
            BuildingWhiteColorGreen = 255;
            BuildingWhiteColorBlue = 255;

            BuildingBlueGlassColorRed = 67;
            BuildingBlueGlassColorGreen = 187;
            BuildingBlueGlassColorBlue = 240;


            BackgroundBuilding1ColorRed = 127;
            BackgroundBuilding1ColorGreen = 178;
            BackgroundBuilding1ColorBlue = 229;


            BackgroundBuilding2ColorRed = 127;
            BackgroundBuilding2ColorGreen = 204;
            BackgroundBuilding2ColorBlue = 204;

            mainBuildingColorRed = 235;
            mainBuildingColorGreen = 171;
            mainBuildingColorBlue = 122;


            mainBuildingWindowColorRed = 189;
            mainBuildingWindowColorGreen = 138;
            mainBuildingWindowColorBlue = 97;

            grassColorRed = 159;
            grassColorGreen = 217;
            grassColorBlue = 0;

            trainBaseColorRed = 255;
            trainBaseColorGreen = 255;
            trainBaseColorBlue = 255;

            trainBaseColor2Red = 215;
            trainBaseColor2Green = 215;
            trainBaseColor2Blue = 215;

            trainWindowColorRed = 90;
            trainWindowColorGreen = 90;
            trainWindowColorBlue = 90;

            trainBaseGreenColorRed = 0;
            trainBaseGreenColorGreen = 174;
            trainBaseGreenColorBlue = 86;

            trainStationLightColorRed = 193;
            trainStationLightColorGreen = 196;
            trainStationLightColorBlue = 196;

            cloudColorRed = 255;
            cloudColorGreen = 255;
            cloudColorBlue = 255;

            car1YellowColorRed = 254;
            car1YellowColorGreen = 185;
            car1YellowColorBlue = 1;

            car1BlackColorRed = 72;
            car1BlackColorGreen = 72;
            car1BlackColorBlue = 72;


            car2GreenColorRed = 34;
            car2GreenColorGreen = 139;
            car2GreenColorBlue = 34;



            car4WhiteColorRed = 255;
            car4WhiteColorGreen = 255;
            car4WhiteColorBlue = 255;

            truck2BluecolorRed = 1;
            truck2BluecolorGreen = 142;
            truck2BluecolorBlue = 230;




            truck1RedcolorRed = 221;
            truck1RedcolorGreen = 67;
            truck1RedcolorBlue = 55;


            truck2BluecolorRed = 1;
            truck2BluecolorGreen = 142;
            truck2BluecolorBlue = 230;


            sideWalkColorRed = 0.8;
            sideWalkColorGreen = 0.8;
            sideWalkColorBlue = 0.8;

            lampPostLightColorRed = 150;
            lampPostLightColorGreen = 150;
            lampPostLightColorBlue = 150;



        }
        else {

            int SkyRed = 1;    //NIGHT SKY
            int SkyGreen = 2;
            int SkyBlue = 40;
            glBegin(GL_QUADS);
            glColor3ub(SkyRed, SkyGreen, SkyBlue); //Top Gradient
            glVertex2f(960, 540);
            glVertex2f(-960, 540);


            glColor3ub(SkyRed + 1, SkyGreen + 84, SkyBlue + 86);//Bottom Gradient
            glVertex2f(-960, 0);
            glVertex2f(960, 0);
            glEnd();

            srand(5);

            for (int i = 1; i <= 500; i++) {
                int Xrandom = -960 + (rand() % 1921);
                int Yrandom = -540 + (rand() % 1081);
                int Radiusrandom = -3 + (rand() % 6);

                drawCircle(Xrandom, Yrandom, Radiusrandom);

            }





            BuildingWhiteColorRed = 50;
            BuildingWhiteColorGreen = 50;
            BuildingWhiteColorBlue = 50;


            BuildingBlueGlassColorRed = 240;
            BuildingBlueGlassColorGreen = 228;
            BuildingBlueGlassColorBlue = 130;


            BackgroundBuilding1ColorRed = 27;
            BackgroundBuilding1ColorGreen = 75;
            BackgroundBuilding1ColorBlue = 123;


            BackgroundBuilding2ColorRed = 21;
            BackgroundBuilding2ColorGreen = 58;
            BackgroundBuilding2ColorBlue = 95;

            mainBuildingColorRed = 50;
            mainBuildingColorGreen = 50;
            mainBuildingColorBlue = 50;


            mainBuildingWindowColorRed = 240;
            mainBuildingWindowColorGreen = 228;
            mainBuildingWindowColorBlue = 130;

            grassColorRed = 11;
            grassColorGreen = 61;
            grassColorBlue = 22;


            trainBaseColorRed = 75;
            trainBaseColorGreen = 75;
            trainBaseColorBlue = 75;

            trainBaseColor2Red = 45;
            trainBaseColor2Green = 45;
            trainBaseColor2Blue = 45;

            trainWindowColorRed = 255;
            trainWindowColorGreen = 249;
            trainWindowColorBlue = 196;


            trainBaseGreenColorRed = 17;
            trainBaseGreenColorGreen = 81;
            trainBaseGreenColorBlue = 49;

            trainStationLightColorRed = 255;
            trainStationLightColorGreen = 196;
            trainStationLightColorBlue = 14;


            car1YellowColorRed = 147;
            car1YellowColorGreen = 107;
            car1YellowColorBlue = 1;


            car2GreenColorRed = 9;
            car2GreenColorGreen = 85;
            car2GreenColorBlue = 9;



            car4WhiteColorRed = 175;
            car4WhiteColorGreen = 175;
            car4WhiteColorBlue = 175;



            cloudColorRed = 3;
            cloudColorGreen = 104;
            cloudColorBlue = 192;

            truck1RedcolorRed = 143;
            truck1RedcolorGreen = 36;
            truck1RedcolorBlue = 28;


            truck2BluecolorRed = 0;
            truck2BluecolorGreen = 92;
            truck2BluecolorBlue = 149;



            sideWalkColorRed = 0.6;
            sideWalkColorGreen = 0.6;
            sideWalkColorBlue = 0.6;



            lampPostLightColorRed = 240;
            lampPostLightColorGreen = 228;
            lampPostLightColorBlue = 130;


        }

        //Cloud

        glBegin(GL_QUADS);
        glColor3ub(cloudColorRed, cloudColorGreen, cloudColorBlue);
        glVertex2f(cloud1Position, 400);
        glVertex2f(cloud1Position - 200, 400);
        glVertex2f(cloud1Position - 200, 350);
        glVertex2f(cloud1Position, 350);
        glEnd();

        drawCircle4(cloud1Position - 200, 400, 50);
        drawCircle4(cloud1Position, 410, 60);
        drawCircle4(cloud1Position - 100, 430, 80);



        glBegin(GL_QUADS);
        glColor3ub(cloudColorRed, cloudColorGreen, cloudColorBlue);
        glVertex2f(cloud2Position, 270);
        glVertex2f(cloud2Position - 150, 270);
        glVertex2f(cloud2Position - 150, 220);
        glVertex2f(cloud2Position, 220);
        glEnd();

        drawCircle4(cloud2Position - 150, 270, 50);
        drawCircle4(cloud2Position, 260, 40);
        drawCircle4(cloud2Position - 80, 280, 60);


        glBegin(GL_QUADS);
        glColor3ub(cloudColorRed, cloudColorGreen, cloudColorBlue);
        glVertex2f(cloud3Position, 380);
        glVertex2f(cloud3Position - 150, 380);
        glVertex2f(cloud3Position - 150, 330);
        glVertex2f(cloud3Position, 330);
        glEnd();

        drawCircle4(cloud3Position - 150, 380, 50);
        drawCircle4(cloud3Position, 390, 60);
        drawCircle4(cloud3Position - 80, 390, 60);






        glBegin(GL_QUADS);
        glColor3ub(cloudColorRed, cloudColorGreen, cloudColorBlue);
        glVertex2f(cloud4Position, 320);
        glVertex2f(cloud4Position - 200, 320);
        glVertex2f(cloud4Position - 200, 270);
        glVertex2f(cloud4Position, 270);
        glEnd();

        drawCircle4(cloud4Position - 200, 320, 50);
        drawCircle4(cloud4Position, 330, 60);
        drawCircle4(cloud4Position - 100, 350, 80);



        glBegin(GL_QUADS);
        glColor3ub(cloudColorRed, cloudColorGreen, cloudColorBlue);
        glVertex2f(cloud5Position, 400);
        glVertex2f(cloud5Position - 150, 400);
        glVertex2f(cloud5Position - 150, 350);
        glVertex2f(cloud5Position, 350);
        glEnd();

        drawCircle4(cloud5Position - 150, 400, 50);
        drawCircle4(cloud5Position, 400, 50);
        drawCircle4(cloud5Position - 80, 420, 70);


        glBegin(GL_QUADS);
        glColor3ub(cloudColorRed, cloudColorGreen, cloudColorBlue);
        glVertex2f(cloud6Position, 290);
        glVertex2f(cloud6Position - 150, 290);
        glVertex2f(cloud6Position - 150, 240);
        glVertex2f(cloud6Position, 240);
        glEnd();

        drawCircle4(cloud6Position - 150, 290, 50);
        drawCircle4(cloud6Position, 300, 60);
        drawCircle4(cloud6Position - 80, 300, 60);


        //Cloud-End







        //    Gradient Sky ->End


        //Green Ground
        glBegin(GL_QUADS);
        glColor3ub(grassColorRed, grassColorGreen, grassColorBlue);
        glVertex2f(960, -200);
        glVertex2f(-960, -200);
        glVertex2f(-960, -540);
        glVertex2f(960, -540);
        glEnd();








        //Asphalt Road

        glBegin(GL_QUADS);
        glColor3ub(100, 100, 100);
        glVertex2f(960, -400);
        glVertex2f(-960, -400);
        glVertex2f(-960, -540);
        glVertex2f(960, -540);
        glEnd();

        //Road Lines

        int Road_Lines_X_Position = -930;

        for (int i = 0; i < 10; i++) {
            if (Road_Lines_X_Position < 930) {
                glBegin(GL_QUADS);
                glColor3f(1.0, 1.0, 1.0);
                glVertex2f(Road_Lines_X_Position + 100, -465);
                glVertex2f(Road_Lines_X_Position, -465);
                glVertex2f(Road_Lines_X_Position, -475);
                glVertex2f(Road_Lines_X_Position + 100, -475);
                glEnd();
                Road_Lines_X_Position += 200;
            }
        }

        //Asphalt Road ->End


        //Sidewalk

        glBegin(GL_QUADS);
        glColor3f(0.5, 0.5, 0.5);
        glVertex2f(960, -400);
        glVertex2f(-960, -400);
        glVertex2f(-960, -408);
        glVertex2f(960, -408);
        glEnd();


        glBegin(GL_QUADS);
        glColor3f(0.8, 0.8, 0.8);
        glVertex2f(960, -360);
        glVertex2f(-960, -360);
        glVertex2f(-960, -400);
        glVertex2f(960, -400);
        glEnd();


        //SideWalk -> Emd


        //Background Building 1

        glBegin(GL_POLYGON);
        glColor3ub(BackgroundBuilding2ColorRed, BackgroundBuilding2ColorGreen, BackgroundBuilding2ColorBlue);
        glVertex2f(950, 350);
        glVertex2f(750, 350);
        glVertex2f(750, -200);
        glVertex2f(950, -200);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(BackgroundBuilding2ColorRed, BackgroundBuilding2ColorGreen, BackgroundBuilding2ColorBlue);
        glVertex2f(920, 380);
        glVertex2f(780, 380);
        glVertex2f(780, 350);
        glVertex2f(920, 350);
        glEnd();


        //Background Building 2

        glBegin(GL_POLYGON);
        glColor3ub(BackgroundBuilding2ColorRed, BackgroundBuilding2ColorGreen, BackgroundBuilding2ColorBlue);
        glVertex2f(720, 400);
        glVertex2f(520, 400);
        glVertex2f(520, -200);
        glVertex2f(720, -200);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(BackgroundBuilding2ColorRed, BackgroundBuilding2ColorGreen, BackgroundBuilding2ColorBlue);
        glVertex2f(720, 420);
        glVertex2f(580, 420);
        glVertex2f(580, 400);
        glVertex2f(720, 400);
        glEnd();




        //Background Building 3

        glBegin(GL_POLYGON);
        glColor3ub(BackgroundBuilding1ColorRed, BackgroundBuilding1ColorGreen, BackgroundBuilding1ColorBlue);
        glVertex2f(850, 250);
        glVertex2f(650, 250);
        glVertex2f(650, -200);
        glVertex2f(850, -200);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(BackgroundBuilding1ColorRed, BackgroundBuilding1ColorGreen, BackgroundBuilding1ColorBlue);
        glVertex2f(800, 280);
        glVertex2f(700, 280);
        glVertex2f(700, 250);
        glVertex2f(800, 250);
        glEnd();



        //Building1 -> From Right

        glBegin(GL_QUADS);
        glColor3ub(BuildingBlueGlassColorRed, BuildingBlueGlassColorGreen, BuildingBlueGlassColorBlue);
        glVertex2f(600, 350);
        glVertex2f(350, 350);
        glVertex2f(350, -200);
        glVertex2f(600, -200);
        glEnd();


        //windows
        int building1_Window_Y_Position = 350;

        for (int i = 0; i < 10; i++) {
            if (building1_Window_Y_Position > -150) {
                glBegin(GL_QUADS);
                glColor3ub(BuildingWhiteColorRed, BuildingWhiteColorGreen, BuildingWhiteColorBlue);
                glVertex2f(600, building1_Window_Y_Position);
                glVertex2f(350, building1_Window_Y_Position);
                glVertex2f(350, building1_Window_Y_Position - 25);
                glVertex2f(600, building1_Window_Y_Position - 25);
                glEnd();
                building1_Window_Y_Position -= 52;
            }
        }

        int building1_Window_Y_Position2 = 325; //for shadow

        for (int j = 0; j < 10; j++) {
            if (building1_Window_Y_Position2 > -150) {
                glBegin(GL_QUADS);
                glColor3ub(BuildingWhiteColorRed - 30, BuildingWhiteColorGreen - 30, BuildingWhiteColorBlue - 30);
                glVertex2f(600, building1_Window_Y_Position2);
                glVertex2f(350, building1_Window_Y_Position2);
                glVertex2f(350, building1_Window_Y_Position2 - 5);
                glVertex2f(600, building1_Window_Y_Position2 - 5);
                glEnd();
                building1_Window_Y_Position2 -= 52;
            }
        }

        glBegin(GL_QUADS);  // Middle pillar
        glColor3ub(BuildingWhiteColorRed, BuildingWhiteColorGreen, BuildingWhiteColorBlue);
        glVertex2f(500, 390);
        glVertex2f(470, 390);
        glVertex2f(470, -200);
        glVertex2f(500, -200);
        glEnd();


        glBegin(GL_QUADS); //rooftop Back
        glColor3ub(BuildingWhiteColorRed - 30, BuildingWhiteColorGreen - 30, BuildingWhiteColorBlue - 30);
        glVertex2f(470, 390);
        glVertex2f(400, 390);
        glVertex2f(400, 350);
        glVertex2f(470, 350);
        glEnd();


        //Building1 -> From Right -> End


        //Building2

        glBegin(GL_QUADS);
        glColor3ub(BuildingBlueGlassColorRed, BuildingBlueGlassColorGreen, BuildingBlueGlassColorBlue);
        glVertex2f(960, 50);
        glVertex2f(580, 50);
        glVertex2f(580, -200);
        glVertex2f(960, -200);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(BuildingBlueGlassColorRed, BuildingBlueGlassColorGreen, BuildingBlueGlassColorBlue);
        glVertex2f(625, 50);
        glVertex2f(580, 50);
        glVertex2f(580, -200);
        glVertex2f(625, -200);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(BuildingBlueGlassColorRed, BuildingBlueGlassColorGreen, BuildingBlueGlassColorBlue);
        glVertex2f(960, 100);
        glVertex2f(700, 100);
        glVertex2f(700, -200);
        glVertex2f(960, -200);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(BuildingBlueGlassColorRed, BuildingBlueGlassColorGreen, BuildingBlueGlassColorBlue);
        glVertex2f(960, 150);
        glVertex2f(750, 150);
        glVertex2f(750, -200);
        glVertex2f(960, -200);
        glEnd();


        glBegin(GL_QUADS); //White Roof Top
        glColor3ub(BuildingWhiteColorRed, BuildingWhiteColorGreen, BuildingWhiteColorBlue);
        glVertex2f(960, 150);
        glVertex2f(740, 150);
        glVertex2f(740, 125);
        glVertex2f(960, 125);
        glEnd();


        glBegin(GL_QUADS); //White Roof Top
        glColor3ub(BuildingWhiteColorRed, BuildingWhiteColorGreen, BuildingWhiteColorBlue);
        glVertex2f(780, 150);
        glVertex2f(740, 150);
        glVertex2f(740, 125);
        glVertex2f(780, 125);
        glEnd();



        glBegin(GL_QUADS); //White Roof Top-1
        glColor3ub(BuildingWhiteColorRed, BuildingWhiteColorGreen, BuildingWhiteColorBlue);
        glVertex2f(960, 100);
        glVertex2f(690, 100);
        glVertex2f(690, 75);
        glVertex2f(960, 75);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(BuildingWhiteColorRed, BuildingWhiteColorGreen, BuildingWhiteColorBlue);
        glVertex2f(730, 100);
        glVertex2f(690, 100);
        glVertex2f(690, 75);
        glVertex2f(730, 75);
        glEnd();


        int building2_roof_y_position = 50;
        for (int j = 0; j < 10; j++) {
            if (building2_roof_y_position > -150) {
                glBegin(GL_QUADS);
                glColor3ub(BuildingWhiteColorRed, BuildingWhiteColorGreen, BuildingWhiteColorBlue);
                glVertex2f(960, building2_roof_y_position);
                glVertex2f(570, building2_roof_y_position);
                glVertex2f(570, building2_roof_y_position - 25);
                glVertex2f(960, building2_roof_y_position - 25);
                glEnd();
                building2_roof_y_position -= 50;

            }
        }

        int building2_roof_y_position2 = 50;  //shadow
        for (int j = 0; j < 10; j++) {
            if (building2_roof_y_position2 > -150) {
                glBegin(GL_QUADS);
                glColor3ub(BuildingWhiteColorRed, BuildingWhiteColorGreen, BuildingWhiteColorBlue);
                glVertex2f(630, building2_roof_y_position2);
                glVertex2f(570, building2_roof_y_position2);
                glVertex2f(570, building2_roof_y_position2 - 25);
                glVertex2f(630, building2_roof_y_position2 - 25);
                glEnd();
                building2_roof_y_position2 -= 50;

            }
        }



        //Building Second left

        glBegin(GL_QUADS);
        glColor3ub(BuildingBlueGlassColorRed, BuildingBlueGlassColorGreen, BuildingBlueGlassColorBlue);
        glVertex2f(-150, 300);
        glVertex2f(-475, 300);
        glVertex2f(-475, -200);
        glVertex2f(-150, -200);
        glEnd();


        //windows
        int building2_left_Window_Y_Position = 300;

        for (int i = 0; i < 10; i++) {
            if (building2_left_Window_Y_Position > -150) {
                glBegin(GL_QUADS);
                glColor3ub(BuildingWhiteColorRed, BuildingWhiteColorGreen, BuildingWhiteColorBlue);
                glVertex2f(-150, building2_left_Window_Y_Position);
                glVertex2f(-475, building2_left_Window_Y_Position);
                glVertex2f(-475, building2_left_Window_Y_Position - 25);
                glVertex2f(-150, building2_left_Window_Y_Position - 25);
                glEnd();
                building2_left_Window_Y_Position -= 52;
            }
        }


        //Building Second left-> End






        //Building Most Left

        glBegin(GL_QUADS);  //Base Layout
        glColor3ub(BuildingBlueGlassColorRed, BuildingBlueGlassColorGreen, BuildingBlueGlassColorBlue);
        glVertex2f(-450, 100);
        glVertex2f(-750, 50);
        glVertex2f(-750, -200);
        glVertex2f(-450, -200);
        glEnd();

        glBegin(GL_QUADS); //Base Layout
        glColor3ub(BuildingBlueGlassColorRed, BuildingBlueGlassColorGreen, BuildingBlueGlassColorBlue);
        glVertex2f(-750, 50);
        glVertex2f(-960, 75);
        glVertex2f(-960, -200);
        glVertex2f(-750, -200);
        glEnd();

        glBegin(GL_TRIANGLES); //Top
        glColor3ub(BuildingWhiteColorRed, BuildingWhiteColorGreen, BuildingWhiteColorBlue);
        glVertex2f(-430, 125);
        glVertex2f(-900, 90);
        glVertex2f(-750, 75);
        glEnd();

        int mostLeftBuildingWindowYPosition = 60;

        for (int i = 0;i < 6; i++) {
            if (mostLeftBuildingWindowYPosition > -150) {
                glBegin(GL_QUADS); //window
                glColor3ub(BuildingWhiteColorRed, BuildingWhiteColorGreen, BuildingWhiteColorBlue);
                glVertex2f(-450, mostLeftBuildingWindowYPosition);
                glVertex2f(-960, mostLeftBuildingWindowYPosition);
                glVertex2f(-960, mostLeftBuildingWindowYPosition - 5);
                glVertex2f(-450, mostLeftBuildingWindowYPosition - 5);
                glEnd();
            }
            mostLeftBuildingWindowYPosition -= 50;
        }


        int mostLeftBuildingWindowXPosition = -900;

        for (int i = 0;i < 2; i++) {
            if (mostLeftBuildingWindowXPosition < 930) {
                glBegin(GL_QUADS); //window
                glColor3ub(BuildingWhiteColorRed, BuildingWhiteColorGreen, BuildingWhiteColorBlue);
                glVertex2f(mostLeftBuildingWindowXPosition, 75);
                glVertex2f(mostLeftBuildingWindowXPosition - 5, 75);
                glVertex2f(mostLeftBuildingWindowXPosition - 5, -200);
                glVertex2f(mostLeftBuildingWindowXPosition, -200);
                glEnd();
            }
            mostLeftBuildingWindowXPosition += 75;
        }


        int mostLeftBuildingWindowXPosition2 = -675;

        for (int i = 0;i < 4; i++) {
            if (mostLeftBuildingWindowXPosition2 < 930) {
                glBegin(GL_QUADS); //window
                glColor3ub(BuildingWhiteColorRed, BuildingWhiteColorGreen, BuildingWhiteColorBlue);
                glVertex2f(mostLeftBuildingWindowXPosition2, 100);
                glVertex2f(mostLeftBuildingWindowXPosition2 - 5, 100);
                glVertex2f(mostLeftBuildingWindowXPosition2 - 5, -200);
                glVertex2f(mostLeftBuildingWindowXPosition2, -200);
                glEnd();
            }
            mostLeftBuildingWindowXPosition2 += 75;
        }





        glBegin(GL_QUADS); //Roof
        glColor3ub(BuildingWhiteColorRed - 50, BuildingWhiteColorGreen - 50, BuildingWhiteColorBlue - 50);
        glVertex2f(-430, 125);
        glVertex2f(-750, 75);
        glVertex2f(-750, 50);
        glVertex2f(-430, 100);
        glEnd();

        glBegin(GL_QUADS); //Roof
        glColor3ub(BuildingWhiteColorRed - 50, BuildingWhiteColorGreen - 50, BuildingWhiteColorBlue - 50);
        glVertex2f(-750, 75);
        glVertex2f(-960, 100);
        glVertex2f(-960, 75);
        glVertex2f(-750, 50);

        glEnd();


        // Building Most Left ->End


        //Final Building

        glBegin(GL_QUADS);

        glColor3ub(mainBuildingColorRed, mainBuildingColorGreen, mainBuildingColorBlue);
        glVertex2f(370, 50);
        glVertex2f(-180, 50);
        glVertex2f(-180, -200);
        glVertex2f(370, -200);
        glEnd();


        glBegin(GL_POLYGON);
        glColor3ub(mainBuildingColorRed, mainBuildingColorGreen, mainBuildingColorBlue);
        glVertex2f(155, 75);
        glVertex2f(85, 150);
        glVertex2f(15, 75);
        glVertex2f(15, -200);
        glVertex2f(155, -200);
        glEnd();





        int mainBuildingWindowXposition = -130;

        for (int i = 0;i < 10;i++) {
            if (mainBuildingWindowXposition < 360) {
                glBegin(GL_QUADS);
                glColor3ub(mainBuildingWindowColorRed, mainBuildingWindowColorGreen, mainBuildingWindowColorBlue);
                glVertex2f(mainBuildingWindowXposition, 30);
                glVertex2f(mainBuildingWindowXposition - 30, 30);
                glVertex2f(mainBuildingWindowXposition - 30, 0);
                glVertex2f(mainBuildingWindowXposition, 0);
                glEnd();
            }
            mainBuildingWindowXposition += 60;
        }


        mainBuildingWindowXposition = -130;

        for (int i = 0;i < 10;i++) {
            if (mainBuildingWindowXposition < 360) {
                glBegin(GL_QUADS);
                glColor3ub(mainBuildingWindowColorRed, mainBuildingWindowColorGreen, mainBuildingWindowColorBlue);
                glVertex2f(mainBuildingWindowXposition, -30);
                glVertex2f(mainBuildingWindowXposition - 30, -30);
                glVertex2f(mainBuildingWindowXposition - 30, -60);
                glVertex2f(mainBuildingWindowXposition, -60);
                glEnd();
            }
            mainBuildingWindowXposition += 60;
        }

        mainBuildingWindowXposition = -130;

        for (int i = 0;i < 3;i++) {
            if (mainBuildingWindowXposition < 360) {
                glBegin(GL_QUADS);
                glColor3ub(mainBuildingWindowColorRed, mainBuildingWindowColorGreen, mainBuildingWindowColorBlue);
                glVertex2f(mainBuildingWindowXposition, -90);
                glVertex2f(mainBuildingWindowXposition - 30, -90);
                glVertex2f(mainBuildingWindowXposition - 30, -120);
                glVertex2f(mainBuildingWindowXposition, -120);
                glEnd();
            }
            mainBuildingWindowXposition += 60;
        }


        mainBuildingWindowXposition = 230;

        for (int i = 0;i < 3;i++) {
            if (mainBuildingWindowXposition < 360) {
                glBegin(GL_QUADS);
                glColor3ub(mainBuildingWindowColorRed, mainBuildingWindowColorGreen, mainBuildingWindowColorBlue);
                glVertex2f(mainBuildingWindowXposition, -90);
                glVertex2f(mainBuildingWindowXposition - 30, -90);
                glVertex2f(mainBuildingWindowXposition - 30, -120);
                glVertex2f(mainBuildingWindowXposition, -120);
                glEnd();
            }
            mainBuildingWindowXposition += 60;
        }


        glBegin(GL_QUADS);
        glColor3ub(mainBuildingWindowColorRed, mainBuildingWindowColorGreen, mainBuildingWindowColorBlue);
        glVertex2f(150, -85);
        glVertex2f(45, -85);
        glVertex2f(45, -200);
        glVertex2f(150, -200);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(BuildingWhiteColorRed, BuildingWhiteColorGreen, BuildingWhiteColorBlue);
        glVertex2f(390, -180);
        glVertex2f(-200, -180);
        glVertex2f(-200, -220);
        glVertex2f(390, -220);
        glEnd();







        //Final Building -> End




        //Train Station
        glBegin(GL_QUADS);
        glColor3ub(146, 145, 144);
        glVertex2f(600, 225);
        glVertex2f(-600, 225);
        glVertex2f(-600, 200);
        glVertex2f(600, 200);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(78, 78, 76);
        glVertex2f(600, 200);
        glVertex2f(-600, 200);
        glVertex2f(-600, 185);
        glVertex2f(600, 185);
        glEnd();







        int trainStationPillarXposition = 500;   //Train Station Pillar

        for (int i = 0; i < 5;i++) {
            if (trainStationPillarXposition > -510) {
                glBegin(GL_QUADS);
                glColor3ub(78, 78, 76);
                glVertex2f(trainStationPillarXposition, 200);
                glVertex2f(trainStationPillarXposition - 20, 200);
                glVertex2f(trainStationPillarXposition - 20, 150);
                glVertex2f(trainStationPillarXposition, 150);
                glEnd();

                glBegin(GL_QUADS);
                glColor3ub(78, 78, 76);
                glVertex2f(trainStationPillarXposition - 4, 150);
                glVertex2f(trainStationPillarXposition - 16, 150);
                glVertex2f(trainStationPillarXposition - 16, 0);
                glVertex2f(trainStationPillarXposition - 4, 0);
                glEnd();

                glBegin(GL_QUADS);
                glColor3ub(253, 180, 78);
                glVertex2f(trainStationPillarXposition - 4, 100);
                glVertex2f(trainStationPillarXposition - 16, 100);
                glVertex2f(trainStationPillarXposition - 16, 85);
                glVertex2f(trainStationPillarXposition - 4, 85);
                glEnd();


            }
            trainStationPillarXposition -= 333;
        }

        glBegin(GL_QUADS);
        glColor3ub(204, 189, 172);
        glVertex2f(650, 25);
        glVertex2f(-650, 25);
        glVertex2f(-650, 0);
        glVertex2f(650, 0);
        glEnd();


        int trainStationBenchXPosition = 370; //TrainStationBench

        for (int i = 0;i < 3;i++) {
            if (trainStationBenchXPosition > -600) {
                glBegin(GL_QUADS);
                glColor3ub(62, 72, 123);
                glVertex2f(trainStationBenchXPosition, 70);
                glVertex2f(trainStationBenchXPosition - 30, 70);
                glVertex2f(trainStationBenchXPosition - 30, 40);
                glVertex2f(trainStationBenchXPosition, 40);
                glEnd();


                glBegin(GL_QUADS);
                glColor3ub(62, 72, 123);
                glVertex2f(trainStationBenchXPosition - 35, 70);
                glVertex2f(trainStationBenchXPosition - 65, 70);
                glVertex2f(trainStationBenchXPosition - 65, 40);
                glVertex2f(trainStationBenchXPosition - 35, 40);
                glEnd();

                glBegin(GL_QUADS);
                glColor3ub(62, 72, 123);
                glVertex2f(trainStationBenchXPosition - 70, 70);
                glVertex2f(trainStationBenchXPosition - 100, 70);
                glVertex2f(trainStationBenchXPosition - 100, 40);
                glVertex2f(trainStationBenchXPosition - 70, 40);
                glEnd();

                glBegin(GL_QUADS);
                glColor3ub(23, 24, 90);
                glVertex2f(trainStationBenchXPosition + 2, 38);
                glVertex2f(trainStationBenchXPosition - 32, 38);
                glVertex2f(trainStationBenchXPosition - 32, 46);
                glVertex2f(trainStationBenchXPosition + 2, 45);
                glEnd();


                glBegin(GL_QUADS);
                glColor3ub(23, 24, 90);
                glVertex2f(trainStationBenchXPosition - 33, 38);
                glVertex2f(trainStationBenchXPosition - 67, 38);
                glVertex2f(trainStationBenchXPosition - 67, 45);
                glVertex2f(trainStationBenchXPosition - 33, 45);
                glEnd();

                glBegin(GL_QUADS);
                glColor3ub(23, 24, 90);
                glVertex2f(trainStationBenchXPosition - 68, 38);
                glVertex2f(trainStationBenchXPosition - 102, 38);
                glVertex2f(trainStationBenchXPosition - 102, 45);
                glVertex2f(trainStationBenchXPosition - 68, 45);
                glEnd();


                glBegin(GL_QUADS);
                glColor3ub(210, 210, 210);
                glVertex2f(trainStationBenchXPosition + 5, 38);
                glVertex2f(trainStationBenchXPosition - 105, 38);
                glVertex2f(trainStationBenchXPosition - 105, 35);
                glVertex2f(trainStationBenchXPosition + 5, 35);
                glEnd();

                glBegin(GL_QUADS);
                glColor3ub(210, 210, 210);
                glVertex2f(trainStationBenchXPosition + 5, 35);
                glVertex2f(trainStationBenchXPosition + 2, 35);
                glVertex2f(trainStationBenchXPosition + 2, 25);
                glVertex2f(trainStationBenchXPosition + 5, 25);
                glEnd();

                glBegin(GL_QUADS);
                glColor3ub(210, 210, 210);
                glVertex2f(trainStationBenchXPosition - 102, 35);
                glVertex2f(trainStationBenchXPosition - 105, 35);
                glVertex2f(trainStationBenchXPosition - 105, 25);
                glVertex2f(trainStationBenchXPosition - 102, 25);
                glEnd();

            }
            trainStationBenchXPosition -= 325;

        }


        int trainStationLightXPosition = 355;  //Light

        for (int i = 0; i < 3; i++) {
            if (trainStationLightXPosition > -600) {
                glBegin(GL_QUADS);
                glColor3ub(120, 127, 117);
                glVertex2f(trainStationLightXPosition, 160);
                glVertex2f(trainStationLightXPosition - 75, 160);
                glVertex2f(trainStationLightXPosition - 75, 150);
                glVertex2f(trainStationLightXPosition, 150);
                glEnd();

                glBegin(GL_QUADS);
                glColor3ub(trainStationLightColorRed, trainStationLightColorGreen, trainStationLightColorBlue);
                glVertex2f(trainStationLightXPosition, 150);
                glVertex2f(trainStationLightXPosition - 75, 150);
                glVertex2f(trainStationLightXPosition - 70, 145);
                glVertex2f(trainStationLightXPosition - 5, 145);
                glEnd();

                glBegin(GL_QUADS);
                glColor3ub(120, 127, 117);
                glVertex2f(trainStationLightXPosition - 10, 185);
                glVertex2f(trainStationLightXPosition - 13, 185);
                glVertex2f(trainStationLightXPosition - 13, 160);
                glVertex2f(trainStationLightXPosition - 10, 160);
                glEnd();

                glBegin(GL_QUADS);
                glColor3ub(120, 127, 117);
                glVertex2f(trainStationLightXPosition - 65, 185);
                glVertex2f(trainStationLightXPosition - 62, 185);
                glVertex2f(trainStationLightXPosition - 62, 160);
                glVertex2f(trainStationLightXPosition - 65, 160);
                glEnd();

            }
            trainStationLightXPosition -= 325;
        }















        //Train -Begin

        //Body1

        glBegin(GL_POLYGON); //Train Base
        glColor3ub(trainBaseColorRed, trainBaseColorGreen, trainBaseColorBlue);
        glVertex2f(trainXposition + 435, 130);
        glVertex2f(trainXposition, 130);
        glVertex2f(trainXposition - 20, 120);
        glVertex2f(trainXposition - 70, 60);
        glVertex2f(trainXposition - 70, 25);
        glVertex2f(trainXposition - 50, 5);
        glVertex2f(trainXposition, 0);
        glVertex2f(trainXposition + 420, 0);
        glVertex2f(trainXposition + 450, 25);
        glVertex2f(trainXposition + 450, 120);
        glEnd();


        glBegin(GL_QUADS);
        glColor3ub(trainBaseColor2Red, trainBaseColor2Green, trainBaseColor2Blue);
        glVertex2f(trainXposition + 450, 120);
        glVertex2f(trainXposition - 20, 120);
        glVertex2f(trainXposition - 70, 60);
        glVertex2f(trainXposition + 450, 60);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(trainBaseGreenColorRed, trainBaseGreenColorGreen, trainBaseGreenColorBlue);
        glVertex2f(trainXposition + 450, 30);
        glVertex2f(trainXposition - 70, 30);
        glVertex2f(trainXposition - 70, 25);
        glVertex2f(trainXposition - 50, 0);
        glVertex2f(trainXposition + 420, 0);
        glVertex2f(trainXposition + 450, 25);
        glEnd();

        //Windows
        glBegin(GL_QUADS);
        glColor3ub(trainWindowColorRed, trainWindowColorGreen, trainWindowColorBlue);
        glVertex2f(trainXposition + 20, 110);
        glVertex2f(trainXposition - 28, 110);
        glVertex2f(trainXposition - 62, 70);
        glVertex2f(trainXposition + 20, 70);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(trainWindowColorRed, trainWindowColorGreen, trainWindowColorBlue);
        glVertex2f(trainXposition + 110, 110);
        glVertex2f(trainXposition + 30, 110);
        glVertex2f(trainXposition + 30, 70);
        glVertex2f(trainXposition + 110, 70);
        glEnd();


        glBegin(GL_QUADS);
        glColor3ub(trainWindowColorRed, trainWindowColorGreen, trainWindowColorBlue);
        glVertex2f(trainXposition + 200, 110);
        glVertex2f(trainXposition + 120, 110);
        glVertex2f(trainXposition + 120, 70);
        glVertex2f(trainXposition + 200, 70);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(trainWindowColorRed, trainWindowColorGreen, trainWindowColorBlue);
        glVertex2f(trainXposition + 290, 110);
        glVertex2f(trainXposition + 210, 110);
        glVertex2f(trainXposition + 210, 70);
        glVertex2f(trainXposition + 290, 70);
        glEnd();


        glBegin(GL_QUADS);
        glColor3ub(trainWindowColorRed, trainWindowColorGreen, trainWindowColorBlue);
        glVertex2f(trainXposition + 440, 110);
        glVertex2f(trainXposition + 360, 110);
        glVertex2f(trainXposition + 360, 70);
        glVertex2f(trainXposition + 440, 70);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(trainWindowColorRed, trainWindowColorGreen, trainWindowColorBlue);
        glVertex2f(trainXposition + 322, 110);
        glVertex2f(trainXposition + 300, 110);
        glVertex2f(trainXposition + 300, 70);
        glVertex2f(trainXposition + 322, 70);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(trainWindowColorRed, trainWindowColorGreen, trainWindowColorBlue);
        glVertex2f(trainXposition + 350, 110);
        glVertex2f(trainXposition + 328, 110);
        glVertex2f(trainXposition + 328, 70);
        glVertex2f(trainXposition + 350, 70);
        glEnd();


        glLineWidth(2.0f);
        glBegin(GL_LINES);
        glColor3b(50, 50, 50);
        glVertex2f(trainXposition + 325.5, 120);
        glVertex2f(trainXposition + 325.5, 20);
        glEnd();

        glBegin(GL_LINES);
        glColor3b(50, 50, 50);
        glVertex2f(trainXposition + 295, 120);
        glVertex2f(trainXposition + 295, 20);
        glEnd();

        glBegin(GL_LINES);
        glColor3b(50, 50, 50);
        glVertex2f(trainXposition + 355, 120);
        glVertex2f(trainXposition + 355, 20);
        glEnd();

        glBegin(GL_LINES);
        glColor3b(50, 50, 50);
        glVertex2f(trainXposition + 355, 120);
        glVertex2f(trainXposition + 295, 120);
        glEnd();

        glBegin(GL_LINES);
        glColor3b(50, 50, 50);
        glVertex2f(trainXposition + 355, 20);
        glVertex2f(trainXposition + 295, 20);
        glEnd();



        //Body2

        glBegin(GL_POLYGON); //Train Base
        glColor3ub(trainBaseColorRed, trainBaseColorGreen, trainBaseColorBlue);
        glVertex2f(trainXposition + 935, 130);
        glVertex2f(trainXposition + 480, 130);
        glVertex2f(trainXposition + 460, 120);
        glVertex2f(trainXposition + 460, 25);
        glVertex2f(trainXposition + 480, 0);
        glVertex2f(trainXposition + 920, 0);
        glVertex2f(trainXposition + 950, 25);
        glVertex2f(trainXposition + 950, 120);
        glEnd();


        glBegin(GL_QUADS);
        glColor3ub(trainBaseColor2Red, trainBaseColor2Green, trainBaseColor2Blue);
        glVertex2f(trainXposition + 950, 120);
        glVertex2f(trainXposition + 460, 120);
        glVertex2f(trainXposition + 460, 60);
        glVertex2f(trainXposition + 950, 60);
        glEnd();


        glBegin(GL_POLYGON);
        glColor3ub(trainBaseGreenColorRed, trainBaseGreenColorGreen, trainBaseGreenColorBlue);
        glVertex2f(trainXposition + 950, 30);
        glVertex2f(trainXposition + 460, 30);
        glVertex2f(trainXposition + 460, 25);
        glVertex2f(trainXposition + 480, 0);
        glVertex2f(trainXposition + 920, 0);
        glVertex2f(trainXposition + 950, 25);
        glEnd();



        //Windows

        glBegin(GL_QUADS);
        glColor3ub(trainWindowColorRed, trainWindowColorGreen, trainWindowColorBlue);
        glVertex2f(trainXposition + 550, 110);
        glVertex2f(trainXposition + 470, 110);
        glVertex2f(trainXposition + 470, 70);
        glVertex2f(trainXposition + 550, 70);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(trainWindowColorRed, trainWindowColorGreen, trainWindowColorBlue);
        glVertex2f(trainXposition + 640, 110);
        glVertex2f(trainXposition + 560, 110);
        glVertex2f(trainXposition + 560, 70);
        glVertex2f(trainXposition + 640, 70);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(trainWindowColorRed, trainWindowColorGreen, trainWindowColorBlue);
        glVertex2f(trainXposition + 730, 110);
        glVertex2f(trainXposition + 650, 110);
        glVertex2f(trainXposition + 650, 70);
        glVertex2f(trainXposition + 730, 70);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(trainWindowColorRed, trainWindowColorGreen, trainWindowColorBlue);
        glVertex2f(trainXposition + 820, 110);
        glVertex2f(trainXposition + 740, 110);
        glVertex2f(trainXposition + 740, 70);
        glVertex2f(trainXposition + 820, 70);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(trainWindowColorRed, trainWindowColorGreen, trainWindowColorBlue);
        glVertex2f(trainXposition + 850, 110);
        glVertex2f(trainXposition + 830, 110);
        glVertex2f(trainXposition + 830, 70);
        glVertex2f(trainXposition + 850, 70);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(trainWindowColorRed, trainWindowColorGreen, trainWindowColorBlue);
        glVertex2f(trainXposition + 876, 110);
        glVertex2f(trainXposition + 856, 110);
        glVertex2f(trainXposition + 856, 70);
        glVertex2f(trainXposition + 876, 70);
        glEnd();


        glBegin(GL_LINES);
        glColor3b(50, 50, 50);
        glVertex2f(trainXposition + 853.5, 120);
        glVertex2f(trainXposition + 853.5, 20);
        glEnd();

        glBegin(GL_LINES);
        glColor3b(50, 50, 50);
        glVertex2f(trainXposition + 825, 120);
        glVertex2f(trainXposition + 825, 20);
        glEnd();

        glBegin(GL_LINES);
        glColor3b(50, 50, 50);
        glVertex2f(trainXposition + 881, 120);
        glVertex2f(trainXposition + 881, 20);
        glEnd();

        glBegin(GL_LINES);
        glColor3b(50, 50, 50);
        glVertex2f(trainXposition + 881, 120);
        glVertex2f(trainXposition + 825, 120);
        glEnd();

        glBegin(GL_LINES);
        glColor3b(50, 50, 50);
        glVertex2f(trainXposition + 881, 20);
        glVertex2f(trainXposition + 825, 20);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(trainWindowColorRed, trainWindowColorGreen, trainWindowColorBlue);
        glVertex2f(trainXposition + 940, 110);
        glVertex2f(trainXposition + 886, 110);
        glVertex2f(trainXposition + 886, 70);
        glVertex2f(trainXposition + 940, 70);
        glEnd();



        //Body3

        glBegin(GL_POLYGON); //Train Base
        glColor3ub(trainBaseColorRed, trainBaseColorGreen, trainBaseColorBlue);
        glVertex2f(trainXposition + 1410, 130);
        glVertex2f(trainXposition + 980, 130);
        glVertex2f(trainXposition + 960, 120);

        glVertex2f(trainXposition + 960, 25);
        glVertex2f(trainXposition + 980, 0);
        glVertex2f(trainXposition + 1460, 0);
        glVertex2f(trainXposition + 1480, 25);
        glVertex2f(trainXposition + 1480, 60);
        glVertex2f(trainXposition + 1430, 120);
        glEnd();


        glBegin(GL_POLYGON);
        glColor3ub(trainBaseColor2Red, trainBaseColor2Green, trainBaseColor2Blue);
        glVertex2f(trainXposition + 1430, 120);
        glVertex2f(trainXposition + 960, 120);
        glVertex2f(trainXposition + 960, 60);
        glVertex2f(trainXposition + 1480, 60);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(trainBaseGreenColorRed, trainBaseGreenColorGreen, trainBaseGreenColorBlue);
        glVertex2f(trainXposition + 1480, 30);
        glVertex2f(trainXposition + 960, 30);
        glVertex2f(trainXposition + 960, 25);
        glVertex2f(trainXposition + 980, 0);
        glVertex2f(trainXposition + 1460, 0);
        glVertex2f(trainXposition + 1480, 25);
        glVertex2f(trainXposition + 1480, 30);


        glEnd();


        glBegin(GL_QUADS);
        glColor3ub(trainWindowColorRed, trainWindowColorGreen, trainWindowColorBlue);
        glVertex2f(trainXposition + 1050, 110);
        glVertex2f(trainXposition + 970, 110);
        glVertex2f(trainXposition + 970, 70);
        glVertex2f(trainXposition + 1050, 70);
        glEnd();


        glBegin(GL_QUADS);
        glColor3ub(trainWindowColorRed, trainWindowColorGreen, trainWindowColorBlue);
        glVertex2f(trainXposition + 1200, 110);
        glVertex2f(trainXposition + 1120, 110);
        glVertex2f(trainXposition + 1120, 70);
        glVertex2f(trainXposition + 1200, 70);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(trainWindowColorRed, trainWindowColorGreen, trainWindowColorBlue);
        glVertex2f(trainXposition + 1290, 110);
        glVertex2f(trainXposition + 1210, 110);
        glVertex2f(trainXposition + 1210, 70);
        glVertex2f(trainXposition + 1290, 70);
        glEnd();


        glBegin(GL_QUADS);
        glColor3ub(trainWindowColorRed, trainWindowColorGreen, trainWindowColorBlue);
        glVertex2f(trainXposition + 1380, 110);
        glVertex2f(trainXposition + 1300, 110);
        glVertex2f(trainXposition + 1300, 70);
        glVertex2f(trainXposition + 1380, 70);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(trainWindowColorRed, trainWindowColorGreen, trainWindowColorBlue);
        glVertex2f(trainXposition + 1440, 110);
        glVertex2f(trainXposition + 1390, 110);
        glVertex2f(trainXposition + 1390, 70);
        glVertex2f(trainXposition + 1472, 70);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(trainWindowColorRed, trainWindowColorGreen, trainWindowColorBlue);
        glVertex2f(trainXposition + 1110, 110);
        glVertex2f(trainXposition + 1088, 110);
        glVertex2f(trainXposition + 1088, 70);
        glVertex2f(trainXposition + 1110, 70);
        glEnd();


        glBegin(GL_QUADS);
        glColor3ub(trainWindowColorRed, trainWindowColorGreen, trainWindowColorBlue);
        glVertex2f(trainXposition + 1082, 110);
        glVertex2f(trainXposition + 1060, 110);
        glVertex2f(trainXposition + 1060, 70);
        glVertex2f(trainXposition + 1082, 70);
        glEnd();

        glBegin(GL_LINES);
        glColor3b(50, 50, 50);
        glVertex2f(trainXposition + 1085, 120);
        glVertex2f(trainXposition + 1085, 20);
        glEnd();

        glBegin(GL_LINES);
        glColor3b(50, 50, 50);
        glVertex2f(trainXposition + 1055, 120);
        glVertex2f(trainXposition + 1055, 20);
        glEnd();

        glBegin(GL_LINES);
        glColor3b(50, 50, 50);
        glVertex2f(trainXposition + 1115, 120);
        glVertex2f(trainXposition + 1115, 20);
        glEnd();

        glBegin(GL_LINES);
        glColor3b(50, 50, 50);
        glVertex2f(trainXposition + 1115, 120);
        glVertex2f(trainXposition + 1055, 120);
        glEnd();

        glBegin(GL_LINES);
        glColor3b(50, 50, 50);
        glVertex2f(trainXposition + 1115, 20);
        glVertex2f(trainXposition + 1055, 20);
        glEnd();










        //Train ->End



        glBegin(GL_QUADS); //Ground Floor Concrete
        glColor3f(0.85, 0.85, 0.85);
        glVertex2f(960, -195);
        glVertex2f(560, -195);
        glVertex2f(560, -205);
        glVertex2f(960, -205);
        glEnd();


        glBegin(GL_QUADS); //Ground Floor Concrete
        glColor3f(0.7, 0.7, 0.7);
        glVertex2f(590, -195);
        glVertex2f(560, -195);
        glVertex2f(560, -205);
        glVertex2f(590, -205);
        glEnd();


        //Metro-rail Line

        glBegin(GL_QUADS);
        glColor3f(0.4980f, 0.5059f, 0.5059f);
        glVertex2f(-987, -24);
        glVertex2f(-987, 14);
        glVertex2f(972, 14);
        glVertex2f(972, -24);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.2824f, 0.2824f, 0.2824f);
        glVertex2f(-987, -10);
        glVertex2f(-987, 10);
        glVertex2f(972, 10);
        glVertex2f(972, -10);
        glEnd();



        //1st Metro Rail Bridge
        glBegin(GL_QUADS);
        glColor3f(0.4980f, 0.5059f, 0.5059f);
        glVertex2f(-758, -308);
        glVertex2f(-758, -131);
        glVertex2f(-714, -131);
        glVertex2f(-714, -308);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.4980f, 0.5059f, 0.5059f);
        glVertex2f(-758, -131);
        glVertex2f(-869, -24);
        glVertex2f(-603, -24);
        glVertex2f(-714, -131);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.2824f, 0.2824f, 0.2824f);
        glVertex2f(-821, -70);
        glVertex2f(-869, -24);
        glVertex2f(-603, -24);
        glVertex2f(-651, -70);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.2824f, 0.2824f, 0.2824f);
        glVertex2f(-758, -131);
        glVertex2f(-714, -131);
        glVertex2f(-714, -145);
        glVertex2f(-758, -145);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.2824f, 0.2824f, 0.2824f);
        glVertex2f(-748, -308);
        glVertex2f(-748, -70);
        glVertex2f(-724, -70);
        glVertex2f(-724, -308);
        glEnd();



        //2nd Metro Rail Bridge
        glBegin(GL_QUADS);
        glColor3f(0.4980f, 0.5059f, 0.5059f);
        glVertex2f(-758 + 459, -308);
        glVertex2f(-758 + 459, -131);
        glVertex2f(-714 + 459, -131);
        glVertex2f(-714 + 459, -308);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.4980f, 0.5059f, 0.5059f);
        glVertex2f(-758 + 459, -131);
        glVertex2f(-869 + 459, -24);
        glVertex2f(-603 + 459, -24);
        glVertex2f(-714 + 459, -131);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.2824f, 0.2824f, 0.2824f);
        glVertex2f(-821 + 459, -70);
        glVertex2f(-869 + 459, -24);
        glVertex2f(-603 + 459, -24);
        glVertex2f(-651 + 459, -70);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.2824f, 0.2824f, 0.2824f);
        glVertex2f(-758 + 459, -131);
        glVertex2f(-714 + 459, -131);
        glVertex2f(-714 + 459, -145);
        glVertex2f(-758 + 459, -145);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.2824f, 0.2824f, 0.2824f);
        glVertex2f(-748 + 459, -308);
        glVertex2f(-748 + 459, -70);
        glVertex2f(-724 + 459, -70);
        glVertex2f(-724 + 459, -308);
        glEnd();


        //3rd Metro Rail Bridge
        glBegin(GL_QUADS);
        glColor3f(0.4980f, 0.5059f, 0.5059f);
        glVertex2f(-758 + 459 + 459, -308);
        glVertex2f(-758 + 459 + 459, -131);
        glVertex2f(-714 + 459 + 459, -131);
        glVertex2f(-714 + 459 + 459, -308);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.4980f, 0.5059f, 0.5059f);
        glVertex2f(-758 + 459 + 459, -131);
        glVertex2f(-869 + 459 + 459, -24);
        glVertex2f(-603 + 459 + 459, -24);
        glVertex2f(-714 + 459 + 459, -131);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.2824f, 0.2824f, 0.2824f);
        glVertex2f(-821 + 459 + 459, -70);
        glVertex2f(-869 + 459 + 459, -24);
        glVertex2f(-603 + 459 + 459, -24);
        glVertex2f(-651 + 459 + 459, -70);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.2824f, 0.2824f, 0.2824f);
        glVertex2f(-758 + 459 + 459, -131);
        glVertex2f(-714 + 459 + 459, -131);
        glVertex2f(-714 + 459 + 459, -145);
        glVertex2f(-758 + 459 + 459, -145);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.2824f, 0.2824f, 0.2824f);
        glVertex2f(-748 + 459 + 459, -308);
        glVertex2f(-748 + 459 + 459, -70);
        glVertex2f(-724 + 459 + 459, -70);
        glVertex2f(-724 + 459 + 459, -308);
        glEnd();



        //4th Metro Rail Bridge
        glBegin(GL_QUADS);
        glColor3f(0.4980f, 0.5059f, 0.5059f);
        glVertex2f(-758 + 459 + 459 + 459, -308);
        glVertex2f(-758 + 459 + 459 + 459, -131);
        glVertex2f(-714 + 459 + 459 + 459, -131);
        glVertex2f(-714 + 459 + 459 + 459, -308);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.4980f, 0.5059f, 0.5059f);
        glVertex2f(-758 + 459 + 459 + 459, -131);
        glVertex2f(-869 + 459 + 459 + 459, -24);
        glVertex2f(-603 + 459 + 459 + 459, -24);
        glVertex2f(-714 + 459 + 459 + 459, -131);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.2824f, 0.2824f, 0.2824f);
        glVertex2f(-821 + 459 + 459 + 459, -70);
        glVertex2f(-869 + 459 + 459 + 459, -24);
        glVertex2f(-603 + 459 + 459 + 459, -24);
        glVertex2f(-651 + 459 + 459 + 459, -70);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.2824f, 0.2824f, 0.2824f);
        glVertex2f(-758 + 459 + 459 + 459, -131);
        glVertex2f(-714 + 459 + 459 + 459, -131);
        glVertex2f(-714 + 459 + 459 + 459, -145);
        glVertex2f(-758 + 459 + 459 + 459, -145);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.2824f, 0.2824f, 0.2824f);
        glVertex2f(-748 + 459 + 459 + 459, -308);
        glVertex2f(-748 + 459 + 459 + 459, -70);
        glVertex2f(-724 + 459 + 459 + 459, -70);
        glVertex2f(-724 + 459 + 459 + 459, -308);
        glEnd();


        //LampPost

        int lampPostXPosition = -670;

        for (int i = 0;i < 4;i++) {
            if (lampPostXPosition < 700) {
                glBegin(GL_QUADS);
                glColor3ub(75, 75, 75);
                glVertex2f(lampPostXPosition, -370);
                glVertex2f(lampPostXPosition - 7.5, -370);
                glVertex2f(lampPostXPosition - 15, -390);
                glVertex2f(lampPostXPosition + 7.5, -390);
                glEnd();

                glBegin(GL_QUADS);
                glColor3ub(75, 75, 75);
                glVertex2f(lampPostXPosition - 1.5, -300);
                glVertex2f(lampPostXPosition - 6, -300);
                glVertex2f(lampPostXPosition - 6, -370);
                glVertex2f(lampPostXPosition - 1.5, -370);
                glEnd();

                glBegin(GL_QUADS);
                glColor3ub(75, 75, 75);
                glVertex2f(lampPostXPosition + 3.5, -290);
                glVertex2f(lampPostXPosition - 11, -290);
                glVertex2f(lampPostXPosition - 6, -300);
                glVertex2f(lampPostXPosition - 1.5, -300);
                glEnd();

                glBegin(GL_QUADS);
                glColor3ub(lampPostLightColorRed, lampPostLightColorGreen, lampPostLightColorBlue);
                glVertex2f(lampPostXPosition + 8.5, -270);
                glVertex2f(lampPostXPosition - 16, -270);
                glVertex2f(lampPostXPosition - 13, -290);
                glVertex2f(lampPostXPosition + 5.5, -290);
                glEnd();

                glBegin(GL_QUADS);
                glColor3ub(75, 75, 75);
                glVertex2f(lampPostXPosition + 2.5, -260);
                glVertex2f(lampPostXPosition - 10, -260);
                glVertex2f(lampPostXPosition - 13, -270);
                glVertex2f(lampPostXPosition + 5.5, -270);
                glEnd();
            }
            lampPostXPosition += 640;



        }


        int sideWalkBenchXPosition = -320; //TrainStationBench

        for (int i = 0;i < 3;i++) {
            if (sideWalkBenchXPosition < 960) {
                glBegin(GL_QUADS);
                glColor3ub(62, 72, 123);
                glVertex2f(sideWalkBenchXPosition, -320);
                glVertex2f(sideWalkBenchXPosition - 30, -320);
                glVertex2f(sideWalkBenchXPosition - 30, -350);
                glVertex2f(sideWalkBenchXPosition, -350);
                glEnd();


                glBegin(GL_QUADS);
                glColor3ub(62, 72, 123);
                glVertex2f(sideWalkBenchXPosition - 35, -320);
                glVertex2f(sideWalkBenchXPosition - 65, -320);
                glVertex2f(sideWalkBenchXPosition - 65, -350);
                glVertex2f(sideWalkBenchXPosition - 35, -350);
                glEnd();

                glBegin(GL_QUADS);
                glColor3ub(62, 72, 123);
                glVertex2f(sideWalkBenchXPosition - 70, -320);
                glVertex2f(sideWalkBenchXPosition - 100, -320);
                glVertex2f(sideWalkBenchXPosition - 100, -350);
                glVertex2f(sideWalkBenchXPosition - 70, -350);
                glEnd();

                glBegin(GL_QUADS);
                glColor3ub(23, 24, 90);
                glVertex2f(sideWalkBenchXPosition + 2, -352);
                glVertex2f(sideWalkBenchXPosition - 32, -352);
                glVertex2f(sideWalkBenchXPosition - 32, -344);
                glVertex2f(sideWalkBenchXPosition + 2, -344);
                glEnd();


                glBegin(GL_QUADS);
                glColor3ub(23, 24, 90);
                glVertex2f(sideWalkBenchXPosition - 33, -352);
                glVertex2f(sideWalkBenchXPosition - 67, -352);
                glVertex2f(sideWalkBenchXPosition - 67, -344);
                glVertex2f(sideWalkBenchXPosition - 33, -344);
                glEnd();

                glBegin(GL_QUADS);
                glColor3ub(23, 24, 90);
                glVertex2f(sideWalkBenchXPosition - 68, -352);
                glVertex2f(sideWalkBenchXPosition - 102, -352);
                glVertex2f(sideWalkBenchXPosition - 102, -344);
                glVertex2f(sideWalkBenchXPosition - 68, -344);
                glEnd();


                glBegin(GL_QUADS);
                glColor3ub(110, 110, 110);
                glVertex2f(sideWalkBenchXPosition + 5, -352);
                glVertex2f(sideWalkBenchXPosition - 105, -352);
                glVertex2f(sideWalkBenchXPosition - 105, -356);
                glVertex2f(sideWalkBenchXPosition + 5, -356);
                glEnd();

                glBegin(GL_QUADS);
                glColor3ub(110, 110, 110);
                glVertex2f(sideWalkBenchXPosition + 5, -355);
                glVertex2f(sideWalkBenchXPosition + 2, -355);
                glVertex2f(sideWalkBenchXPosition + 2, -370);
                glVertex2f(sideWalkBenchXPosition + 5, -370);
                glEnd();

                glBegin(GL_QUADS);
                glColor3ub(110, 110, 110);
                glVertex2f(sideWalkBenchXPosition - 102, -355);
                glVertex2f(sideWalkBenchXPosition - 105, -355);
                glVertex2f(sideWalkBenchXPosition - 105, -370);
                glVertex2f(sideWalkBenchXPosition - 102, -370);
                glEnd();

            }
            sideWalkBenchXPosition += 640;

        }











        //Car1

        glBegin(GL_POLYGON);
        glColor3ub(car1YellowColorRed, car1YellowColorGreen, car1YellowColorBlue);
        glVertex2f(car1Xposition - 5, -410);
        glVertex2f(car1Xposition - 145, -410);
        glVertex2f(car1Xposition - 150, -415);

        glVertex2f(car1Xposition - 150, -440);
        glVertex2f(car1Xposition - 145, -445);
        glVertex2f(car1Xposition - 5, -445);
        glVertex2f(car1Xposition, -440);
        glVertex2f(car1Xposition, -415);

        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(car1BlackColorRed, car1BlackColorGreen, car1BlackColorBlue);
        glVertex2f(car1Xposition - 10, -380);
        glVertex2f(car1Xposition - 92, -380);
        glVertex2f(car1Xposition - 100, -385);
        glVertex2f(car1Xposition - 125, -410);
        glVertex2f(car1Xposition - 5, -410);
        glVertex2f(car1Xposition - 5, -385);
        glEnd();


        drawCircle2(car1Xposition - 30, -445, 15); //Tyre
        drawCircle2(car1Xposition - 120, -445, 15);

        drawCircle3(car1Xposition - 30, -445, 10); //Tyre Inner Circle
        drawCircle3(car1Xposition - 120, -445, 10);




        //Car2

        glBegin(GL_POLYGON);
        glColor3ub(car2GreenColorRed, car2GreenColorGreen, car2GreenColorBlue);
        glVertex2f(car2Xposition - 5, -410);
        glVertex2f(car2Xposition - 145, -410);
        glVertex2f(car2Xposition - 150, -415);

        glVertex2f(car2Xposition - 150, -440);
        glVertex2f(car2Xposition - 145, -445);
        glVertex2f(car2Xposition - 5, -445);
        glVertex2f(car2Xposition, -440);
        glVertex2f(car2Xposition, -415);

        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(car1BlackColorRed, car1BlackColorGreen, car1BlackColorBlue);
        glVertex2f(car2Xposition - 10, -380);
        glVertex2f(car2Xposition - 92, -380);
        glVertex2f(car2Xposition - 100, -385);
        glVertex2f(car2Xposition - 125, -410);
        glVertex2f(car2Xposition - 5, -410);
        glVertex2f(car2Xposition - 5, -385);
        glEnd();


        drawCircle2(car2Xposition - 30, -445, 15); //Tyre
        drawCircle2(car2Xposition - 120, -445, 15);

        drawCircle3(car2Xposition - 30, -445, 10); //Tyre Inner Circle
        drawCircle3(car2Xposition - 120, -445, 10);


        //Car3
        glBegin(GL_POLYGON);
        glColor3ub(truck1RedcolorRed, truck1RedcolorGreen, truck1RedcolorBlue);
        glVertex2f(car3Xposition - 5, -490);
        glVertex2f(car3Xposition - 145, -490);
        glVertex2f(car3Xposition - 150, -495);

        glVertex2f(car3Xposition - 150, -520);
        glVertex2f(car3Xposition - 145, -525);
        glVertex2f(car3Xposition - 5, -525);
        glVertex2f(car3Xposition, -520);
        glVertex2f(car3Xposition, -495);

        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(car1BlackColorRed, car1BlackColorGreen, car1BlackColorBlue);
        glVertex2f(car3Xposition - 92, -460);
        glVertex2f(car3Xposition - 140, -465);
        glVertex2f(car3Xposition - 145, -490);
        glVertex2f(car3Xposition - 25, -490);
        glVertex2f(car3Xposition - 45, -465);
        glEnd();


        drawCircle2(car3Xposition - 30, -525, 15); //Tyre
        drawCircle2(car3Xposition - 120, -525, 15);

        drawCircle3(car3Xposition - 30, -525, 10); //Tyre Inner Circle
        drawCircle3(car3Xposition - 120, -525, 10);


        //Car4
        glBegin(GL_POLYGON);
        glColor3ub(car4WhiteColorRed, car4WhiteColorGreen, car4WhiteColorBlue);
        glVertex2f(car4Xposition - 5, -490);
        glVertex2f(car4Xposition - 145, -490);
        glVertex2f(car4Xposition - 150, -495);

        glVertex2f(car4Xposition - 150, -520);
        glVertex2f(car4Xposition - 145, -525);
        glVertex2f(car4Xposition - 5, -525);
        glVertex2f(car4Xposition, -520);
        glVertex2f(car4Xposition, -495);

        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(car1BlackColorRed, car1BlackColorGreen, car1BlackColorBlue);
        glVertex2f(car4Xposition - 92, -460);
        glVertex2f(car4Xposition - 140, -465);
        glVertex2f(car4Xposition - 145, -490);
        glVertex2f(car4Xposition - 25, -490);
        glVertex2f(car4Xposition - 45, -465);
        glEnd();


        drawCircle2(car4Xposition - 30, -525, 15); //Tyre
        drawCircle2(car4Xposition - 120, -525, 15);

        drawCircle3(car4Xposition - 30, -525, 10); //Tyre Inner Circle
        drawCircle3(car4Xposition - 120, -525, 10);


        //Truck1

        glBegin(GL_POLYGON);
        glColor3ub(truck1RedcolorRed, truck1RedcolorGreen, truck1RedcolorBlue);
        glVertex2f(truckXPosition - 5, -475);
        glVertex2f(truckXPosition - 90, -475);
        glVertex2f(truckXPosition - 90, -510);
        glVertex2f(truckXPosition - 5, -510);
        glVertex2f(truckXPosition, -505);
        glVertex2f(truckXPosition, -480);
        glEnd();


        glBegin(GL_POLYGON);
        glColor3ub(car1BlackColorRed, car1BlackColorGreen, car1BlackColorBlue);
        glVertex2f(truckXPosition - 40, -450);
        glVertex2f(truckXPosition - 90, -450);
        glVertex2f(truckXPosition - 90, -475);
        glVertex2f(truckXPosition - 25, -475);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(truck1RedcolorRed, truck1RedcolorGreen, truck1RedcolorBlue);
        glVertex2f(truckXPosition - 92, -483);
        glVertex2f(truckXPosition - 180, -483);
        glVertex2f(truckXPosition - 180, -510);
        glVertex2f(truckXPosition - 92, -510);
        glEnd();

        drawCircle2(truckXPosition - 30, -510, 15); //Tyre
        drawCircle2(truckXPosition - 135, -510, 15);

        drawCircle3(truckXPosition - 30, -510, 10); //Tyre Inner Circle
        drawCircle3(truckXPosition - 135, -510, 10);




        //Truck2

        glBegin(GL_POLYGON);
        glColor3ub(truck2BluecolorRed, truck2BluecolorGreen, truck2BluecolorBlue);
        glVertex2f(truck2Xposition + 40, -400);
        glVertex2f(truck2Xposition - 50, -400);
        glVertex2f(truck2Xposition - 50, -435);
        glVertex2f(truck2Xposition - 45, -440);
        glVertex2f(truck2Xposition + 40, -440);
        glEnd();


        glBegin(GL_POLYGON);
        glColor3ub(car1BlackColorRed, car1BlackColorGreen, car1BlackColorBlue);
        glVertex2f(truck2Xposition + 35, -360);
        glVertex2f(truck2Xposition - 30, -360);
        glVertex2f(truck2Xposition - 50, -400);
        glVertex2f(truck2Xposition + 40, -400);
        glVertex2f(truck2Xposition + 40, -365);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(truck2BluecolorRed, truck2BluecolorGreen, truck2BluecolorBlue);
        glVertex2f(truck2Xposition + 195, -330);
        glVertex2f(truck2Xposition + 47, -330);
        glVertex2f(truck2Xposition + 42, -335);
        glVertex2f(truck2Xposition + 42, -440);
        glVertex2f(truck2Xposition + 200, -440);
        glVertex2f(truck2Xposition + 200, -335);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(50, 50, 50);
        glVertex2f(truck2Xposition + 200, -430);
        glVertex2f(truck2Xposition - 50, -430);
        glVertex2f(truck2Xposition - 50, -435);
        glVertex2f(truck2Xposition - 45, -440);
        glVertex2f(truck2Xposition + 200, -440);

        glEnd();

        drawCircle2(truck2Xposition + 160, -440, 20); //Tyre
        drawCircle2(truck2Xposition - 10, -440, 20);

        drawCircle3(truck2Xposition + 160, -440, 13); //Tyre Inner Circle
        drawCircle3(truck2Xposition - 10, -440, 13);

    }
    else if (sceneNo == 2) {






        glBegin(GL_POLYGON);

        //Sky
        glColor3f(0.11f, 0.59f, 0.77f);
        glVertex2f(-960.00, 540.00);
        glVertex2f(960.00, 540.00);
        glColor3f(0.63f, 0.85f, 0.94f);
        glVertex2f(960, 21.00);
        glVertex2f(-960.00, 21.00);
        glEnd();
        glColor3f(0, 0, 0);
        glLineWidth(10.0);

        if (environmentState == 0) {


            int SkyRed = 131;   //DAY SKY
            int SkyGreen = 231;
            int SkyBlue = 246;
            glBegin(GL_QUADS);
            glColor3ub(SkyRed, SkyGreen, SkyBlue); //TOP gradient
            glVertex2f(960, 540);
            glVertex2f(-960, 540);
            glColor3ub(SkyRed + 124, SkyGreen + 24, SkyBlue + 9);//Bottom Gradient
            glVertex2f(-960, -0);
            glVertex2f(960, -0);
            glEnd();


            trainBaseColorRed = 255;
            trainBaseColorGreen = 255;
            trainBaseColorBlue = 255;

            trainBaseColor2Red = 215;
            trainBaseColor2Green = 215;
            trainBaseColor2Blue = 215;

            trainWindowColorRed = 90;
            trainWindowColorGreen = 90;
            trainWindowColorBlue = 90;

            trainBaseGreenColorRed = 0;
            trainBaseGreenColorGreen = 174;
            trainBaseGreenColorBlue = 86;


            cloudColorRed = 255;
            cloudColorGreen = 255;
            cloudColorBlue = 255;



        }
        else {

            int SkyRed = 13;    //NIGHT SKY
            int SkyGreen = 20;
            int SkyBlue = 69;
            glBegin(GL_QUADS);
            glColor3ub(SkyRed, SkyGreen, SkyBlue); //Top Gradient
            glVertex2f(960, 540);
            glVertex2f(-960, 540);


            glColor3ub(SkyRed + 79, SkyGreen + 64, SkyBlue + 95);//Bottom Gradient
            glVertex2f(-960, 0);
            glVertex2f(960, 0);
            glEnd();



            cloudColorRed = 3;
            cloudColorGreen = 104;
            cloudColorBlue = 192;


            trainBaseColorRed = 75;
            trainBaseColorGreen = 75;
            trainBaseColorBlue = 75;

            trainBaseColor2Red = 45;
            trainBaseColor2Green = 45;
            trainBaseColor2Blue = 45;

            trainWindowColorRed = 255;
            trainWindowColorGreen = 249;
            trainWindowColorBlue = 196;


            trainBaseGreenColorRed = 17;
            trainBaseGreenColorGreen = 81;
            trainBaseGreenColorBlue = 49;



        }


        //Cloud

        glBegin(GL_QUADS);
        glColor3ub(cloudColorRed, cloudColorGreen, cloudColorBlue);
        glVertex2f(cloud1Position, 400);
        glVertex2f(cloud1Position - 200, 400);
        glVertex2f(cloud1Position - 200, 350);
        glVertex2f(cloud1Position, 350);
        glEnd();

        drawCircle4(cloud1Position - 200, 400, 50);
        drawCircle4(cloud1Position, 410, 60);
        drawCircle4(cloud1Position - 100, 430, 80);



        glBegin(GL_QUADS);
        glColor3ub(cloudColorRed, cloudColorGreen, cloudColorBlue);
        glVertex2f(cloud2Position, 270);
        glVertex2f(cloud2Position - 150, 270);
        glVertex2f(cloud2Position - 150, 220);
        glVertex2f(cloud2Position, 220);
        glEnd();

        drawCircle4(cloud2Position - 150, 270, 50);
        drawCircle4(cloud2Position, 260, 40);
        drawCircle4(cloud2Position - 80, 280, 60);


        glBegin(GL_QUADS);
        glColor3ub(cloudColorRed, cloudColorGreen, cloudColorBlue);
        glVertex2f(cloud3Position, 380);
        glVertex2f(cloud3Position - 150, 380);
        glVertex2f(cloud3Position - 150, 330);
        glVertex2f(cloud3Position, 330);
        glEnd();

        drawCircle4(cloud3Position - 150, 380, 50);
        drawCircle4(cloud3Position, 390, 60);
        drawCircle4(cloud3Position - 80, 390, 60);






        glBegin(GL_QUADS);
        glColor3ub(cloudColorRed, cloudColorGreen, cloudColorBlue);
        glVertex2f(cloud4Position, 320);
        glVertex2f(cloud4Position - 200, 320);
        glVertex2f(cloud4Position - 200, 270);
        glVertex2f(cloud4Position, 270);
        glEnd();

        drawCircle4(cloud4Position - 200, 320, 50);
        drawCircle4(cloud4Position, 330, 60);
        drawCircle4(cloud4Position - 100, 350, 80);



        glBegin(GL_QUADS);
        glColor3ub(cloudColorRed, cloudColorGreen, cloudColorBlue);
        glVertex2f(cloud5Position, 400);
        glVertex2f(cloud5Position - 150, 400);
        glVertex2f(cloud5Position - 150, 350);
        glVertex2f(cloud5Position, 350);
        glEnd();

        drawCircle4(cloud5Position - 150, 400, 50);
        drawCircle4(cloud5Position, 400, 50);
        drawCircle4(cloud5Position - 80, 420, 70);


        glBegin(GL_QUADS);
        glColor3ub(cloudColorRed, cloudColorGreen, cloudColorBlue);
        glVertex2f(cloud6Position, 290);
        glVertex2f(cloud6Position - 150, 290);
        glVertex2f(cloud6Position - 150, 240);
        glVertex2f(cloud6Position, 240);
        glEnd();

        drawCircle4(cloud6Position - 150, 290, 50);
        drawCircle4(cloud6Position, 300, 60);
        drawCircle4(cloud6Position - 80, 300, 60);




        //Mountains
        glBegin(GL_POLYGON);
        glColor3f(0.56f, 0.30f, 0.31f);
        glVertex2f(-1028.00, 21.00);
        glVertex2f(-802.00, 182.00);
        glVertex2f(-796.00, 172.00);
        glVertex2f(-643.00, 277.00);
        glVertex2f(-634.00, 265.00);
        glVertex2f(-490.00, 370.00);
        glVertex2f(-319.00, 270.00);
        glVertex2f(-309.00, 281.00);
        glVertex2f(-152.00, 172.00);
        glVertex2f(-140.00, 186.00);
        glVertex2f(95.00, 21.00);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.56f, 0.30f, 0.31f);
        glVertex2f(-68.00, 21.00);
        glVertex2f(228, 241.00);
        glVertex2f(240.00, 201.00);
        glVertex2f(398.00, 307.00);
        glVertex2f(548.00, 210.00);
        glVertex2f(557.00, 220.00);
        glVertex2f(841.00, 22.00);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.56f, 0.30f, 0.31f);
        glVertex2f(512.00, 21.00);
        glVertex2f(836, 320.00);
        glVertex2f(847.00, 311.00);
        glVertex2f(960.00, 428.00);
        glVertex2f(960.00, 21.00);
        glEnd();


        glBegin(GL_POLYGON);
        glColor3f(0.16f, 0.58f, 0.37f);
        glVertex2f(-960.00, 21.00);
        glVertex2f(-693.00, 162.00);
        glVertex2f(-682.00, 157.00);
        glVertex2f(-500.00, 279.00);
        glVertex2f(-255.00, 160.00);
        glVertex2f(-211.00, 121.00);
        glVertex2f(-42.00, 21.00);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.16f, 0.58f, 0.37f);
        glVertex2f(118.00, 21.00);
        glVertex2f(248.00, 112.00);
        glVertex2f(270.00, 106.00);
        glVertex2f(404.00, 207.00);
        glVertex2f(583.00, 95.00);
        glVertex2f(597.00, 104.00);
        glVertex2f(744.00, 21.00);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0.16f, 0.58f, 0.37f);
        glVertex2f(707.00, 21.00);
        glVertex2f(960.00, 257.00);
        glVertex2f(960.00, 21.00);
        glEnd();

        //River UpperShade

        glBegin(GL_QUADS);
        glColor3f(0.11f, 0.64f, 0.93f);
        glVertex2f(-960.00, 21.00);
        glVertex2f(960.00, 21.00);
        glVertex2f(960.00, -540.00);
        glVertex2f(-960.00, -540.00);
        glEnd();


        //Metro-rail Line

        glBegin(GL_QUADS);
        glColor3f(0.4980f, 0.5059f, 0.5059f);
        glVertex2f(-987, -24);
        glVertex2f(-987, 14);
        glVertex2f(972, 14);
        glVertex2f(972, -24);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.2824f, 0.2824f, 0.2824f);
        glVertex2f(-987, -10);
        glVertex2f(-987, 10);
        glVertex2f(972, 10);
        glVertex2f(972, -10);
        glEnd();



        //1st Metro Rail Bridge
        glBegin(GL_QUADS);
        glColor3f(0.4980f, 0.5059f, 0.5059f);
        glVertex2f(-758, -308);
        glVertex2f(-758, -131);
        glVertex2f(-714, -131);
        glVertex2f(-714, -308);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.4980f, 0.5059f, 0.5059f);
        glVertex2f(-758, -131);
        glVertex2f(-869, -24);
        glVertex2f(-603, -24);
        glVertex2f(-714, -131);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.2824f, 0.2824f, 0.2824f);
        glVertex2f(-821, -70);
        glVertex2f(-869, -24);
        glVertex2f(-603, -24);
        glVertex2f(-651, -70);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.2824f, 0.2824f, 0.2824f);
        glVertex2f(-758, -131);
        glVertex2f(-714, -131);
        glVertex2f(-714, -145);
        glVertex2f(-758, -145);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.2824f, 0.2824f, 0.2824f);
        glVertex2f(-748, -308);
        glVertex2f(-748, -70);
        glVertex2f(-724, -70);
        glVertex2f(-724, -308);
        glEnd();



        //2nd Metro Rail Bridge
        glBegin(GL_QUADS);
        glColor3f(0.4980f, 0.5059f, 0.5059f);
        glVertex2f(-758 + 459, -308);
        glVertex2f(-758 + 459, -131);
        glVertex2f(-714 + 459, -131);
        glVertex2f(-714 + 459, -308);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.4980f, 0.5059f, 0.5059f);
        glVertex2f(-758 + 459, -131);
        glVertex2f(-869 + 459, -24);
        glVertex2f(-603 + 459, -24);
        glVertex2f(-714 + 459, -131);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.2824f, 0.2824f, 0.2824f);
        glVertex2f(-821 + 459, -70);
        glVertex2f(-869 + 459, -24);
        glVertex2f(-603 + 459, -24);
        glVertex2f(-651 + 459, -70);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.2824f, 0.2824f, 0.2824f);
        glVertex2f(-758 + 459, -131);
        glVertex2f(-714 + 459, -131);
        glVertex2f(-714 + 459, -145);
        glVertex2f(-758 + 459, -145);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.2824f, 0.2824f, 0.2824f);
        glVertex2f(-748 + 459, -308);
        glVertex2f(-748 + 459, -70);
        glVertex2f(-724 + 459, -70);
        glVertex2f(-724 + 459, -308);
        glEnd();


        //3rd Metro Rail Bridge
        glBegin(GL_QUADS);
        glColor3f(0.4980f, 0.5059f, 0.5059f);
        glVertex2f(-758 + 459 + 459, -308);
        glVertex2f(-758 + 459 + 459, -131);
        glVertex2f(-714 + 459 + 459, -131);
        glVertex2f(-714 + 459 + 459, -308);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.4980f, 0.5059f, 0.5059f);
        glVertex2f(-758 + 459 + 459, -131);
        glVertex2f(-869 + 459 + 459, -24);
        glVertex2f(-603 + 459 + 459, -24);
        glVertex2f(-714 + 459 + 459, -131);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.2824f, 0.2824f, 0.2824f);
        glVertex2f(-821 + 459 + 459, -70);
        glVertex2f(-869 + 459 + 459, -24);
        glVertex2f(-603 + 459 + 459, -24);
        glVertex2f(-651 + 459 + 459, -70);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.2824f, 0.2824f, 0.2824f);
        glVertex2f(-758 + 459 + 459, -131);
        glVertex2f(-714 + 459 + 459, -131);
        glVertex2f(-714 + 459 + 459, -145);
        glVertex2f(-758 + 459 + 459, -145);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.2824f, 0.2824f, 0.2824f);
        glVertex2f(-748 + 459 + 459, -308);
        glVertex2f(-748 + 459 + 459, -70);
        glVertex2f(-724 + 459 + 459, -70);
        glVertex2f(-724 + 459 + 459, -308);
        glEnd();



        //4th Metro Rail Bridge
        glBegin(GL_QUADS);
        glColor3f(0.4980f, 0.5059f, 0.5059f);
        glVertex2f(-758 + 459 + 459 + 459, -308);
        glVertex2f(-758 + 459 + 459 + 459, -131);
        glVertex2f(-714 + 459 + 459 + 459, -131);
        glVertex2f(-714 + 459 + 459 + 459, -308);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.4980f, 0.5059f, 0.5059f);
        glVertex2f(-758 + 459 + 459 + 459, -131);
        glVertex2f(-869 + 459 + 459 + 459, -24);
        glVertex2f(-603 + 459 + 459 + 459, -24);
        glVertex2f(-714 + 459 + 459 + 459, -131);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.2824f, 0.2824f, 0.2824f);
        glVertex2f(-821 + 459 + 459 + 459, -70);
        glVertex2f(-869 + 459 + 459 + 459, -24);
        glVertex2f(-603 + 459 + 459 + 459, -24);
        glVertex2f(-651 + 459 + 459 + 459, -70);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.2824f, 0.2824f, 0.2824f);
        glVertex2f(-758 + 459 + 459 + 459, -131);
        glVertex2f(-714 + 459 + 459 + 459, -131);
        glVertex2f(-714 + 459 + 459 + 459, -145);
        glVertex2f(-758 + 459 + 459 + 459, -145);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.2824f, 0.2824f, 0.2824f);
        glVertex2f(-748 + 459 + 459 + 459, -308);
        glVertex2f(-748 + 459 + 459 + 459, -70);
        glVertex2f(-724 + 459 + 459 + 459, -70);
        glVertex2f(-724 + 459 + 459 + 459, -308);
        glEnd();



        //Train -Begin

        //Body1

        glBegin(GL_POLYGON); //Train Base
        glColor3ub(trainBaseColorRed, trainBaseColorGreen, trainBaseColorBlue);
        glVertex2f(trainXposition + 435, 130);
        glVertex2f(trainXposition, 130);
        glVertex2f(trainXposition - 20, 120);
        glVertex2f(trainXposition - 70, 60);
        glVertex2f(trainXposition - 70, 25);
        glVertex2f(trainXposition - 50, 5);
        glVertex2f(trainXposition, 0);
        glVertex2f(trainXposition + 420, 0);
        glVertex2f(trainXposition + 450, 25);
        glVertex2f(trainXposition + 450, 120);
        glEnd();


        glBegin(GL_QUADS);
        glColor3ub(trainBaseColor2Red, trainBaseColor2Green, trainBaseColor2Blue);
        glVertex2f(trainXposition + 450, 120);
        glVertex2f(trainXposition - 20, 120);
        glVertex2f(trainXposition - 70, 60);
        glVertex2f(trainXposition + 450, 60);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(trainBaseGreenColorRed, trainBaseGreenColorGreen, trainBaseGreenColorBlue);
        glVertex2f(trainXposition + 450, 30);
        glVertex2f(trainXposition - 70, 30);
        glVertex2f(trainXposition - 70, 25);
        glVertex2f(trainXposition - 50, 0);
        glVertex2f(trainXposition + 420, 0);
        glVertex2f(trainXposition + 450, 25);
        glEnd();

        //Windows
        glBegin(GL_QUADS);
        glColor3ub(trainWindowColorRed, trainWindowColorGreen, trainWindowColorBlue);
        glVertex2f(trainXposition + 20, 110);
        glVertex2f(trainXposition - 28, 110);
        glVertex2f(trainXposition - 62, 70);
        glVertex2f(trainXposition + 20, 70);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(trainWindowColorRed, trainWindowColorGreen, trainWindowColorBlue);
        glVertex2f(trainXposition + 110, 110);
        glVertex2f(trainXposition + 30, 110);
        glVertex2f(trainXposition + 30, 70);
        glVertex2f(trainXposition + 110, 70);
        glEnd();


        glBegin(GL_QUADS);
        glColor3ub(trainWindowColorRed, trainWindowColorGreen, trainWindowColorBlue);
        glVertex2f(trainXposition + 200, 110);
        glVertex2f(trainXposition + 120, 110);
        glVertex2f(trainXposition + 120, 70);
        glVertex2f(trainXposition + 200, 70);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(trainWindowColorRed, trainWindowColorGreen, trainWindowColorBlue);
        glVertex2f(trainXposition + 290, 110);
        glVertex2f(trainXposition + 210, 110);
        glVertex2f(trainXposition + 210, 70);
        glVertex2f(trainXposition + 290, 70);
        glEnd();


        glBegin(GL_QUADS);
        glColor3ub(trainWindowColorRed, trainWindowColorGreen, trainWindowColorBlue);
        glVertex2f(trainXposition + 440, 110);
        glVertex2f(trainXposition + 360, 110);
        glVertex2f(trainXposition + 360, 70);
        glVertex2f(trainXposition + 440, 70);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(trainWindowColorRed, trainWindowColorGreen, trainWindowColorBlue);
        glVertex2f(trainXposition + 322, 110);
        glVertex2f(trainXposition + 300, 110);
        glVertex2f(trainXposition + 300, 70);
        glVertex2f(trainXposition + 322, 70);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(trainWindowColorRed, trainWindowColorGreen, trainWindowColorBlue);
        glVertex2f(trainXposition + 350, 110);
        glVertex2f(trainXposition + 328, 110);
        glVertex2f(trainXposition + 328, 70);
        glVertex2f(trainXposition + 350, 70);
        glEnd();


        glLineWidth(2.0f);
        glBegin(GL_LINES);
        glColor3b(50, 50, 50);
        glVertex2f(trainXposition + 325.5, 120);
        glVertex2f(trainXposition + 325.5, 20);
        glEnd();

        glBegin(GL_LINES);
        glColor3b(50, 50, 50);
        glVertex2f(trainXposition + 295, 120);
        glVertex2f(trainXposition + 295, 20);
        glEnd();

        glBegin(GL_LINES);
        glColor3b(50, 50, 50);
        glVertex2f(trainXposition + 355, 120);
        glVertex2f(trainXposition + 355, 20);
        glEnd();

        glBegin(GL_LINES);
        glColor3b(50, 50, 50);
        glVertex2f(trainXposition + 355, 120);
        glVertex2f(trainXposition + 295, 120);
        glEnd();

        glBegin(GL_LINES);
        glColor3b(50, 50, 50);
        glVertex2f(trainXposition + 355, 20);
        glVertex2f(trainXposition + 295, 20);
        glEnd();



        //Body2

        glBegin(GL_POLYGON); //Train Base
        glColor3ub(trainBaseColorRed, trainBaseColorGreen, trainBaseColorBlue);
        glVertex2f(trainXposition + 935, 130);
        glVertex2f(trainXposition + 480, 130);
        glVertex2f(trainXposition + 460, 120);
        glVertex2f(trainXposition + 460, 25);
        glVertex2f(trainXposition + 480, 0);
        glVertex2f(trainXposition + 920, 0);
        glVertex2f(trainXposition + 950, 25);
        glVertex2f(trainXposition + 950, 120);
        glEnd();


        glBegin(GL_QUADS);
        glColor3ub(trainBaseColor2Red, trainBaseColor2Green, trainBaseColor2Blue);
        glVertex2f(trainXposition + 950, 120);
        glVertex2f(trainXposition + 460, 120);
        glVertex2f(trainXposition + 460, 60);
        glVertex2f(trainXposition + 950, 60);
        glEnd();


        glBegin(GL_POLYGON);
        glColor3ub(trainBaseGreenColorRed, trainBaseGreenColorGreen, trainBaseGreenColorBlue);
        glVertex2f(trainXposition + 950, 30);
        glVertex2f(trainXposition + 460, 30);
        glVertex2f(trainXposition + 460, 25);
        glVertex2f(trainXposition + 480, 0);
        glVertex2f(trainXposition + 920, 0);
        glVertex2f(trainXposition + 950, 25);
        glEnd();



        //Windows

        glBegin(GL_QUADS);
        glColor3ub(trainWindowColorRed, trainWindowColorGreen, trainWindowColorBlue);
        glVertex2f(trainXposition + 550, 110);
        glVertex2f(trainXposition + 470, 110);
        glVertex2f(trainXposition + 470, 70);
        glVertex2f(trainXposition + 550, 70);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(trainWindowColorRed, trainWindowColorGreen, trainWindowColorBlue);
        glVertex2f(trainXposition + 640, 110);
        glVertex2f(trainXposition + 560, 110);
        glVertex2f(trainXposition + 560, 70);
        glVertex2f(trainXposition + 640, 70);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(trainWindowColorRed, trainWindowColorGreen, trainWindowColorBlue);
        glVertex2f(trainXposition + 730, 110);
        glVertex2f(trainXposition + 650, 110);
        glVertex2f(trainXposition + 650, 70);
        glVertex2f(trainXposition + 730, 70);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(trainWindowColorRed, trainWindowColorGreen, trainWindowColorBlue);
        glVertex2f(trainXposition + 820, 110);
        glVertex2f(trainXposition + 740, 110);
        glVertex2f(trainXposition + 740, 70);
        glVertex2f(trainXposition + 820, 70);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(trainWindowColorRed, trainWindowColorGreen, trainWindowColorBlue);
        glVertex2f(trainXposition + 850, 110);
        glVertex2f(trainXposition + 830, 110);
        glVertex2f(trainXposition + 830, 70);
        glVertex2f(trainXposition + 850, 70);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(trainWindowColorRed, trainWindowColorGreen, trainWindowColorBlue);
        glVertex2f(trainXposition + 876, 110);
        glVertex2f(trainXposition + 856, 110);
        glVertex2f(trainXposition + 856, 70);
        glVertex2f(trainXposition + 876, 70);
        glEnd();


        glBegin(GL_LINES);
        glColor3b(50, 50, 50);
        glVertex2f(trainXposition + 853.5, 120);
        glVertex2f(trainXposition + 853.5, 20);
        glEnd();

        glBegin(GL_LINES);
        glColor3b(50, 50, 50);
        glVertex2f(trainXposition + 825, 120);
        glVertex2f(trainXposition + 825, 20);
        glEnd();

        glBegin(GL_LINES);
        glColor3b(50, 50, 50);
        glVertex2f(trainXposition + 881, 120);
        glVertex2f(trainXposition + 881, 20);
        glEnd();

        glBegin(GL_LINES);
        glColor3b(50, 50, 50);
        glVertex2f(trainXposition + 881, 120);
        glVertex2f(trainXposition + 825, 120);
        glEnd();

        glBegin(GL_LINES);
        glColor3b(50, 50, 50);
        glVertex2f(trainXposition + 881, 20);
        glVertex2f(trainXposition + 825, 20);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(trainWindowColorRed, trainWindowColorGreen, trainWindowColorBlue);
        glVertex2f(trainXposition + 940, 110);
        glVertex2f(trainXposition + 886, 110);
        glVertex2f(trainXposition + 886, 70);
        glVertex2f(trainXposition + 940, 70);
        glEnd();



        //Body3

        glBegin(GL_POLYGON); //Train Base
        glColor3ub(trainBaseColorRed, trainBaseColorGreen, trainBaseColorBlue);
        glVertex2f(trainXposition + 1410, 130);
        glVertex2f(trainXposition + 980, 130);
        glVertex2f(trainXposition + 960, 120);

        glVertex2f(trainXposition + 960, 25);
        glVertex2f(trainXposition + 980, 0);
        glVertex2f(trainXposition + 1460, 0);
        glVertex2f(trainXposition + 1480, 25);
        glVertex2f(trainXposition + 1480, 60);
        glVertex2f(trainXposition + 1430, 120);
        glEnd();


        glBegin(GL_POLYGON);
        glColor3ub(trainBaseColor2Red, trainBaseColor2Green, trainBaseColor2Blue);
        glVertex2f(trainXposition + 1430, 120);
        glVertex2f(trainXposition + 960, 120);
        glVertex2f(trainXposition + 960, 60);
        glVertex2f(trainXposition + 1480, 60);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3ub(trainBaseGreenColorRed, trainBaseGreenColorGreen, trainBaseGreenColorBlue);
        glVertex2f(trainXposition + 1480, 30);
        glVertex2f(trainXposition + 960, 30);
        glVertex2f(trainXposition + 960, 25);
        glVertex2f(trainXposition + 980, 0);
        glVertex2f(trainXposition + 1460, 0);
        glVertex2f(trainXposition + 1480, 25);
        glVertex2f(trainXposition + 1480, 30);


        glEnd();


        glBegin(GL_QUADS);
        glColor3ub(trainWindowColorRed, trainWindowColorGreen, trainWindowColorBlue);
        glVertex2f(trainXposition + 1050, 110);
        glVertex2f(trainXposition + 970, 110);
        glVertex2f(trainXposition + 970, 70);
        glVertex2f(trainXposition + 1050, 70);
        glEnd();


        glBegin(GL_QUADS);
        glColor3ub(trainWindowColorRed, trainWindowColorGreen, trainWindowColorBlue);
        glVertex2f(trainXposition + 1200, 110);
        glVertex2f(trainXposition + 1120, 110);
        glVertex2f(trainXposition + 1120, 70);
        glVertex2f(trainXposition + 1200, 70);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(trainWindowColorRed, trainWindowColorGreen, trainWindowColorBlue);
        glVertex2f(trainXposition + 1290, 110);
        glVertex2f(trainXposition + 1210, 110);
        glVertex2f(trainXposition + 1210, 70);
        glVertex2f(trainXposition + 1290, 70);
        glEnd();


        glBegin(GL_QUADS);
        glColor3ub(trainWindowColorRed, trainWindowColorGreen, trainWindowColorBlue);
        glVertex2f(trainXposition + 1380, 110);
        glVertex2f(trainXposition + 1300, 110);
        glVertex2f(trainXposition + 1300, 70);
        glVertex2f(trainXposition + 1380, 70);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(trainWindowColorRed, trainWindowColorGreen, trainWindowColorBlue);
        glVertex2f(trainXposition + 1440, 110);
        glVertex2f(trainXposition + 1390, 110);
        glVertex2f(trainXposition + 1390, 70);
        glVertex2f(trainXposition + 1472, 70);
        glEnd();

        glBegin(GL_QUADS);
        glColor3ub(trainWindowColorRed, trainWindowColorGreen, trainWindowColorBlue);
        glVertex2f(trainXposition + 1110, 110);
        glVertex2f(trainXposition + 1088, 110);
        glVertex2f(trainXposition + 1088, 70);
        glVertex2f(trainXposition + 1110, 70);
        glEnd();


        glBegin(GL_QUADS);
        glColor3ub(trainWindowColorRed, trainWindowColorGreen, trainWindowColorBlue);
        glVertex2f(trainXposition + 1082, 110);
        glVertex2f(trainXposition + 1060, 110);
        glVertex2f(trainXposition + 1060, 70);
        glVertex2f(trainXposition + 1082, 70);
        glEnd();

        glBegin(GL_LINES);
        glColor3b(50, 50, 50);
        glVertex2f(trainXposition + 1085, 120);
        glVertex2f(trainXposition + 1085, 20);
        glEnd();

        glBegin(GL_LINES);
        glColor3b(50, 50, 50);
        glVertex2f(trainXposition + 1055, 120);
        glVertex2f(trainXposition + 1055, 20);
        glEnd();

        glBegin(GL_LINES);
        glColor3b(50, 50, 50);
        glVertex2f(trainXposition + 1115, 120);
        glVertex2f(trainXposition + 1115, 20);
        glEnd();

        glBegin(GL_LINES);
        glColor3b(50, 50, 50);
        glVertex2f(trainXposition + 1115, 120);
        glVertex2f(trainXposition + 1055, 120);
        glEnd();

        glBegin(GL_LINES);
        glColor3b(50, 50, 50);
        glVertex2f(trainXposition + 1115, 20);
        glVertex2f(trainXposition + 1055, 20);
        glEnd();










        //Train ->End


        //First Boat

        glPushMatrix();
        glTranslatef(position3, 0.0f, 0.0f);

        glBegin(GL_QUADS);
        glColor3f(0.11f, 0.20f, 0.32f);
        glVertex2f(-650.00, -293.00 - 45);
        glVertex2f(-650.00, -235.00 - 45);
        glVertex2f(-336.00, -223.00 - 45);
        glVertex2f(-388.00, -293.00 - 45);
        glEnd();

        glBegin(GL_TRIANGLES);
        glColor3f(0.96f, 0.95f, 0.85f);
        glVertex2f(-548.00, -231.00 - 45);
        glVertex2f(-428.00, -146.00 - 45);
        glVertex2f(-428.00, -226.00 - 45);
        glVertex2f(-548.00, -231.00 - 45);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.91f, 0.32f, 0.29f);
        glVertex2f(-592.00, -233.00 - 45);
        glVertex2f(-592.00, -153.00 - 45);
        glVertex2f(-570.00, -153.00 - 45);
        glVertex2f(-570.00, -232.00 - 45);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.84f, 0.74f, 0.37f);
        glVertex2f(-381.00, -224.00 - 45);
        glVertex2f(-381.00, -182.00 - 45);
        glVertex2f(-360.00, -182.00 - 45);
        glVertex2f(-360.00, -224.00 - 45);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.91f, 0.32f, 0.29f);
        glVertex2f(-560.00, -233.00 - 45);
        glVertex2f(-560.00, -169.00 - 45);
        glVertex2f(-538.00, -169.00 - 45);
        glVertex2f(-538.00, -233.00 - 45);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.91f, 0.32f, 0.29f);
        glVertex2f(-528.00, -232.00 - 45);
        glVertex2f(-528.00, -142.00 - 45);
        glVertex2f(-505.00, -142.00 - 45);
        glVertex2f(-505.00, -229.00 - 45);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.91f, 0.32f, 0.29f);
        glVertex2f(-494.00, -230.00 - 45);
        glVertex2f(-494.00, -120.00 - 45);
        glVertex2f(-471.00, -120.00 - 45);
        glVertex2f(-471.00, -228.00 - 45);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.69f, 0.76f, 0.72f);
        glVertex2f(-538.00, -274.00 - 45);
        glVertex2f(-538.00, -251.00 - 45);
        glVertex2f(-514.00, -251.00 - 45);
        glVertex2f(-514.00, -274.00 - 45);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.69f, 0.76f, 0.72f);
        glVertex2f(-538.00 + 34, -274.00 - 45);
        glVertex2f(-538.00 + 34, -251.00 - 45);
        glVertex2f(-514.00 + 34, -251.00 - 45);
        glVertex2f(-514.00 + 34, -274.00 - 45);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.69f, 0.76f, 0.72f);
        glVertex2f(-538.00 + 34 + 34, -274.00 - 45);
        glVertex2f(-538.00 + 34 + 34, -251.00 - 45);
        glVertex2f(-514.00 + 34 + 34, -251.00 - 45);
        glVertex2f(-514.00 + 34 + 34, -274.00 - 45);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.69f, 0.76f, 0.72f);
        glVertex2f(-538.00 + 34 + 34 + 34, -274.00 - 45);
        glVertex2f(-538.00 + 34 + 34 + 34, -251.00 - 45);
        glVertex2f(-514.00 + 34 + 34 + 34, -251.00 - 45);
        glVertex2f(-514.00 + 34 + 34 + 34, -274.00 - 45);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.69f, 0.76f, 0.72f);
        glVertex2f(-538.00 - 34, -274.00 - 45);
        glVertex2f(-538.00 - 34, -251.00 - 45);
        glVertex2f(-514.00 - 34, -251.00 - 45);
        glVertex2f(-514.00 - 34, -274.00 - 45);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.69f, 0.76f, 0.72f);
        glVertex2f(-538.00 - 34 - 34, -274.00 - 45);
        glVertex2f(-538.00 - 34 - 34, -251.00 - 45);
        glVertex2f(-514.00 - 34 - 34, -251.00 - 45);
        glVertex2f(-514.00 - 34 - 34, -274.00 - 45);
        glEnd();

        glPopMatrix();

        //1st Wave Shade

        glBegin(GL_QUADS);
        glColor3f(0.10f, 0.58f, 0.83f);
        glVertex2f(-960, -344);
        glVertex2f(960, -344);
        glVertex2f(960, -540);
        glVertex2f(-960, -540);
        glEnd();


        glPushMatrix();
        glTranslatef(position2, 0.0f, 0.0f);

        glBegin(GL_POLYGON);
        glColor3f(0.10f, 0.58f, 0.83f);

        int x1 = -1627;
        int y1 = -344;
        int width1 = 66;

        while (x1 < 2500) {
            glBegin(GL_POLYGON);
            glVertex2f(x1, y1);
            glVertex2f(x1 + width1, y1 + 18);
            glVertex2f(x1 + width1, y1);
            glEnd();

            x1 += width1;
        }

        glPopMatrix();

        //2nd Boat

        glPushMatrix();
        glTranslatef(position1, 0.0f, 0.0f);

        glBegin(GL_POLYGON);
        glColor3f(0.03f, 0.04f, 0.13f);
        glVertex2f(-165 + 1086, -343);
        glVertex2f(548 + 1086, -386);
        glVertex2f(549 + 1086, -426);
        glVertex2f(513 + 1086, -460);
        glVertex2f(-39 + 1086, -460);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(1.0, 1.0f, 1.0f);
        glVertex2f(-79 + 1086, -349);
        glVertex2f(-8 + 1086, -220);
        glVertex2f(498 + 1086, -255);
        glVertex2f(483 + 1086, -330);
        glVertex2f(522 + 1086, -331);
        glVertex2f(513 + 1086, -384);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.28f, 0.77f, 0.99f);
        glVertex2f(-16 + 1086, -234);
        glVertex2f(479 + 1086, -268);
        glVertex2f(469 + 1086, -314);
        glVertex2f(-40 + 1086, -278);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.28f, 0.77f, 0.99f);
        glVertex2f(-47 + 1086, -290);
        glVertex2f(469 + 1086, -330);
        glVertex2f(459 + 1086, -372);
        glVertex2f(-72 + 1086, -336);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.71f, 0.13f, 0.04f);
        glVertex2f(78 + 1086, -226);
        glVertex2f(86 + 1086, -162);
        glVertex2f(115 + 1086, -166);
        glVertex2f(107 + 1086, -228);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.52f, 0.52f, 0.52f);
        glVertex2f(83 + 1086, -184);
        glVertex2f(112 + 1086, -188);
        glVertex2f(111 + 1086, -200);
        glVertex2f(82 + 1086, -196);
        glEnd();


        glBegin(GL_QUADS);
        glColor3f(0.71f, 0.13f, 0.04f);
        glVertex2f(137 + 1086, -230);
        glVertex2f(144 + 1086, -170);
        glVertex2f(173 + 1086, -173);
        glVertex2f(167 + 1086, -232);
        glEnd();

        glBegin(GL_QUADS);
        glColor3f(0.52f, 0.52f, 0.52f);
        glVertex2f(140 + 1086, -204);
        glVertex2f(141 + 1086, -191);
        glVertex2f(171 + 1086, -195);
        glVertex2f(169 + 1086, -208);
        glEnd();

        glPopMatrix();



        //2md wave shade

        glBegin(GL_QUADS);
        glColor3f(0.08f, 0.51f, 0.74f);
        glVertex2f(-960, -460);
        glVertex2f(960, -460);
        glVertex2f(960, -540);
        glVertex2f(-960, -540);
        glEnd();


        glPushMatrix();
        glTranslatef(position2, 0.0f, 0.0f);

        glBegin(GL_POLYGON);
        glColor3f(0.08f, 0.51f, 0.74f);

        int x = -1628;
        int y = -460;
        int width = 66;

        while (x < 2400) {
            glBegin(GL_POLYGON);
            glVertex2f(x, y);
            glVertex2f(x + width, y + 18);
            glVertex2f(x + width, y);
            glEnd();

            x += width;
        }

        glPopMatrix();

    }




    glFlush();
    glutSwapBuffers();


}

//train moverment




void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-960, 960, -540, 540);
    glMatrixMode(GL_MODELVIEW);
}


/*void handleKeypress1(unsigned char key, int x, int y) {

    glutPostRedisplay();
}*/



void handleKeyPress(unsigned char key, int x, int y) {
    if (key == 'A' || key == 'a') {
        state = 1;
        if (trainXposition > -2500) {
            sndPlaySound("train.wav", SND_ASYNC);
        }
        glutPostRedisplay();
    }
    else if (key == 'D' || key == 'd') {
        state = -1;
        if (trainXposition < 1000) {
            sndPlaySound("train.wav", SND_ASYNC);
        }
        glutPostRedisplay();
    }
    else if (key == ' ') {
        state = 0;
        sndPlaySound("trainStop.wav", SND_ASYNC);
    }
    else if (key == 'N' || key == 'n') {
        environmentState = 1;
        glutPostRedisplay();
    }
    else if (key == 'M' || key == 'm') {
        environmentState = 0;
        glutPostRedisplay();
    }
    else if (key == 't' || key == 'T') {
        trafficSoundState = 0;
        sndPlaySound("TrafficSound.wav", SND_ASYNC);
        glutPostRedisplay();
    }
    else if (key == 'y' || key == 'Y') {
        trafficSoundState = 1;
        sndPlaySound("trainStop.wav", SND_ASYNC);
        glutPostRedisplay();
    }
    else if (key == '1') {
        sceneNo = 1;
        glutPostRedisplay();

    }
    else if (key == '2') {
        sceneNo = 2;
        sndPlaySound("ocean.wav", SND_ASYNC);
        glutPostRedisplay();
    }

    switch (key) {
    case 'f':
        speed1 = 0.0f;
        break;
    case 'g':
        speed1 = 10.0f;
        break;
    case 'h':
        speed2 = 0.0f;
        break;
    case 'j':
        speed2 = 10.0f;
        break;
    case 'k':
        speed3 = 0.0f;
        break;
    case 'l':
        speed3 = 10.0f;
        break;
    }
    glutPostRedisplay();
}


void drawCircle(float cx, float cy, float radius)
{
    int numSegments = 100;
    float theta = 2.0f * 3.1415926f / float(numSegments);
    float cosTheta = cos(theta);
    float sinTheta = sin(theta);

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 255, 255);
    for (int i = 0; i < numSegments; i++)
    {
        float x = radius * cos(i * theta);
        float y = radius * sin(i * theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}


void drawCircle2(float cx, float cy, float radius)
{
    int numSegments = 100;
    float theta = 2.0f * 3.1415926f / float(numSegments);
    float cosTheta = cos(theta);
    float sinTheta = sin(theta);

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(55, 55, 55);
    for (int i = 0; i < numSegments; i++)
    {
        float x = radius * cos(i * theta);
        float y = radius * sin(i * theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}


void drawCircle3(float cx, float cy, float radius)
{
    int numSegments = 100;
    float theta = 2.0f * 3.1415926f / float(numSegments);
    float cosTheta = cos(theta);
    float sinTheta = sin(theta);

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(221, 221, 221);
    for (int i = 0; i < numSegments; i++)
    {
        float x = radius * cos(i * theta);
        float y = radius * sin(i * theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}


void drawCircle4(float cx, float cy, float radius)
{
    int numSegments = 100;
    float theta = 2.0f * 3.1415926f / float(numSegments);
    float cosTheta = cos(theta);
    float sinTheta = sin(theta);

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(cloudColorRed, cloudColorGreen, cloudColorBlue);
    for (int i = 0; i < numSegments; i++)
    {
        float x = radius * cos(i * theta);
        float y = radius * sin(i * theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}





void trainTimer(int) {
    glutPostRedisplay();
    glutTimerFunc(1000 / 75, trainTimer, 0);



    if (cloud4Position > -5000) {
        cloud4Position -= cloudSpeed;
        if (cloud4Position < -1000) {
            cloud4Position = 1200;
        }

        cloud1Position -= cloudSpeed;
        if (cloud1Position < -1000) {
            cloud1Position = 1200;
        }
        cloud2Position -= cloudSpeed;
        if (cloud2Position < -1000) {
            cloud2Position = 1200;
        }
        cloud3Position -= cloudSpeed;
        if (cloud3Position < -1000) {
            cloud3Position = 1200;
        }
        cloud5Position -= cloudSpeed;
        if (cloud5Position < -1000) {
            cloud5Position = 1200;
        }
        cloud6Position -= cloudSpeed;
        if (cloud6Position < -1000) {
            cloud6Position = 1200;
        }
    }



    car1Xposition -= carSpeed;
    if (car1Xposition < -2000) {
        car1Xposition = 1200;
    }


    car2Xposition -= carSpeed;
    if (car2Xposition < -2000) {
        car2Xposition = 1200;
    }


    car3Xposition += carSpeed;
    if (car3Xposition > 2000) {
        car3Xposition = -1200;
    }

    car4Xposition += carSpeed;
    if (car4Xposition > 2000) {
        car4Xposition = -1200;
    }




    truckXPosition += carSpeed;
    if (truckXPosition > 2000) {
        truckXPosition = -1200;
    }

    truck2Xposition -= carSpeed;
    if (truck2Xposition < -2000) {
        truck2Xposition = 1200;
    }




    switch (state) {



    case 0:
        trainXposition = trainXposition;
        break;

    case 1:

        if (trainXposition > -3000) {
            trainXposition -= trainSpeed;
        }
        else {

            state = 0;
        }
        break;

    case -1:
        if (trainXposition < 1500) {
            trainXposition += trainSpeed;
        }
        else {
            state = 0;
        }

        break;
    }

}


