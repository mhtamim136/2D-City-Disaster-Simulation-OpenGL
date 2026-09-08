// 2D City Disaster Simulation
// Scenes: Normal, Earthquake, Fire, Flood, Storm, Road Accident
//
// MD. MURAD HASAN ............... main.cpp, city/environment.h,
//                                 city/buildings.h, ui/night.h

// MD. RABBY SARKER RONY ......... core/algorithms.h, city/vehicles.h,
//                                 scenes/fire.h

// MD. SADMAN AMIN BHUIYAN SUNY .. core/shapes.h, city/people.h,
//                                 scenes/accident.h, ui/ending.h

// FAHMIDA ISLAM BAYAN ........... city/props.h, scenes/storm.h,
//                                 ui/evening.h, ui/intro.h

// NOSHIN SUNZIDA ALAM ........... scenes/earthquake.h, scenes/flood.h,
//                                 ui/hud.h

#include <GL/glut.h>
#include <cmath>
#include <cstdlib>

const float PI = 3.1415926f;

int scene = 0;
int frameCount = 0;
int paused = 0;
int waterOn = 0;
int nightMode = 0;
int eveningMode = 0;
int showIntro = 1;
int showEnd = 0;

float zoom = 1.0f;
float carMove = -180.0f;
float cloudMove = 0.0f;
float boatMove = -180.0f;
float boatDir = 1.0f;
float floodLevel = 170.0f;
float hoseTargetX = 810.0f;
float hoseTargetY = 428.0f;
float birdMove = 0.0f;
float doorOpen = 0.0f;
float runOut = 0.0f;
float windowOpen = 0.0f;
float ambMove = 1050.0f; //for ambulance move

#include "core/shapes.h"
#include "core/algorithms.h"
#include "city/environment.h"
#include "city/buildings.h"
#include "city/props.h"
#include "city/vehicles.h"
#include "city/people.h"
#include "scenes/earthquake.h"
#include "scenes/fire.h"
#include "scenes/flood.h"
#include "scenes/storm.h"
#include "scenes/accident.h"
#include "ui/hud.h"
#include "ui/night.h"
#include "ui/evening.h"
#include "ui/intro.h"
#include "ui/ending.h"

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    if(showIntro == 1)
    {
        drawIntro();
        glutSwapBuffers();
        return;
    }

    if(showEnd == 1)
    {
        drawEnd();
        glutSwapBuffers();
        return;
    }

    int night = 0;
    int evening = 0;

    if(scene == 0 && nightMode == 1)
    {
        night = 1;
    }

    if(scene == 0 && eveningMode == 1)
    {
        evening = 1;
    }

    // Zoom
    glPushMatrix();
    glTranslatef(500.0f, 325.0f, 0.0f);
    glScalef(zoom, zoom, 1.0f);
    glTranslatef(-500.0f, -325.0f, 0.0f);

    if(evening == 1)
    {
        drawEveningSky();
        drawSettingSun(352.0f, 390.0f, 52.0f);
    }
    else
    {
        drawSky();

        if(night == 1)
        {
            drawNightSky();
        }
        else
        {
            drawSun();
        }
    }

    drawMovingClouds();

    if(night == 0)
    {
        drawBirds();
    }

    float shakeX = 0.0f;
    float shakeY = 0.0f;

    if(scene == 1)
    {
        shakeX = sin(frameCount * 0.80f) * 4.0f;
        shakeY = cos(frameCount * 0.65f) * 2.5f;
    }

    glPushMatrix();
    glTranslatef(shakeX, shakeY, 0.0f);

    drawGround();

    float hospitalAngle = 0.0f;
    float towerAngle = 0.0f;
    float apartmentAngle = 0.0f;

    if(scene == 1)
    {
        hospitalAngle = -3.5f + sin(frameCount * 0.25f) * 1.5f;
        towerAngle = 2.5f - sin(frameCount * 0.23f) * 1.2f;
        apartmentAngle = -2.0f + sin(frameCount * 0.28f) * 1.0f;
    }

    drawHospital(hospitalAngle);
    drawTower(towerAngle);
    drawApartment(apartmentAngle);

    float treeAngle = 0.0f;
    float lampAngle = 0.0f;

    if(scene == 1)
    {
        treeAngle = sin(frameCount * 0.30f) * 4.0f;
        lampAngle = 8.0f;
    }
    else if(scene == 4)
    {
        treeAngle = sin(frameCount * 0.12f) * 13.0f;
        lampAngle = sin(frameCount * 0.10f) * 4.0f;
    }

    drawTree(340.0f, 203.0f, 0.45f, treeAngle);
    drawTree(640.0f, 203.0f, 0.40f, treeAngle * 0.75f);
    drawLamp(35.0f, 175.0f, lampAngle);
    drawLamp(955.0f, 175.0f, -lampAngle);

    if(scene == 0)
    {
        drawCar(carMove, 82.0f, 0.85f, 0.0f);
    }
    else if(scene == 1)
    {
        drawEarthquakeScene();
    }
    else if(scene == 2)
    {
        drawFireScene();
    }
    else if(scene == 3)
    {
        drawFloodScene();
    }
    else if(scene == 4)
    {
        drawStormScene();
    }
    else
    {
        drawAccidentScene();
    }

    glPopMatrix();

    if(night == 1)
    {
        drawNightLights();
    }

    if(evening == 1)
    {
        drawEveningLights();
    }

    glPopMatrix();

    drawHUD();
    glutSwapBuffers();
}

void resetCurrentScene()
{
    frameCount = 0;
    waterOn = 0;
    hoseTargetX = 810.0f;
    hoseTargetY = 428.0f;
    doorOpen = 0.0f;
    runOut = 0.0f;
    windowOpen = 0.0f;

    if(scene == 0)
    {
        carMove = -180.0f;
    }

    if(scene == 3)
    {
        floodLevel = 170.0f;
        boatMove = -180.0f;
        boatDir = 1.0f;
    }

    if(scene == 5)
    {
        ambMove = 1050.0f;
    }
}

void changeScene(int newScene)
{
    if(newScene < 0)
    {
        newScene = 0;
    }

    scene = newScene;
    paused = 0;
    resetCurrentScene();
}

void keyboard(unsigned char key, int x, int y)
{
    if(showIntro == 1)
    {
        showIntro = 0;
        glutPostRedisplay();
        return;
    }

    if(showEnd == 1)
    {
        if(key == 'a' || key == 'A')
        {
            showEnd = 0;
        }
        else if(key == 'r' || key == 'R')
        {
            showEnd = 0;
            zoom = 1.0f;
            nightMode = 0;
            eveningMode = 0;
            changeScene(0);
        }
        else if(key == 'x' || key == 'X')
        {
            exit(0);
        }

        glutPostRedisplay();
        return;
    }

    switch(key)
    {
        case 'd':
        case 'D':
            if(scene == 5)
            {
                showEnd = 1;
            }
            else
            {
                changeScene(scene + 1);
            }
            break;

        case 'a':
        case 'A':
            changeScene(scene - 1);
            break;

        case 'w':
        case 'W':
            if(scene == 2)
            {
                if(waterOn == 0)
                {
                    waterOn = 1;
                }
                else
                {
                    waterOn = 0;
                }
            }
            break;

        case 'n':
        case 'N':
            if(scene == 0)
            {
                if(nightMode == 0)
                {
                    nightMode = 1;
                    eveningMode = 0;
                }
                else
                {
                    nightMode = 0;
                }
            }
            break;

        case 'e':
        case 'E':
            if(scene == 0)
            {
                if(eveningMode == 0)
                {
                    eveningMode = 1;
                    nightMode = 0;
                }
                else
                {
                    eveningMode = 0;
                }
            }
            break;

        case '+':
        case '=':
            zoom = zoom + 0.1f;
            if(zoom > 2.5f)
            {
                zoom = 2.5f;
            }
            break;

        case '-':
        case '_':
            zoom = zoom - 0.1f;
            if(zoom < 1.0f)
            {
                zoom = 1.0f;
            }
            break;

        case 'j':
        case 'J':
            if(scene == 2)
            {
                hoseTargetX = hoseTargetX - 8.0f;
                if(hoseTargetX < 735.0f)
                {
                    hoseTargetX = 735.0f;
                }
            }
            break;

        case 'l':
        case 'L':
            if(scene == 2)
            {
                hoseTargetX = hoseTargetX + 8.0f;
                if(hoseTargetX > 875.0f)
                {
                    hoseTargetX = 875.0f;
                }
            }
            break;

        case 'i':
        case 'I':
            if(scene == 2)
            {
                hoseTargetY = hoseTargetY + 8.0f;
                if(hoseTargetY > 470.0f)
                {
                    hoseTargetY = 470.0f;
                }
            }
            break;

        case 'k':
        case 'K':
            if(scene == 2)
            {
                hoseTargetY = hoseTargetY - 8.0f;
                if(hoseTargetY < 281.0f)
                {
                    hoseTargetY = 281.0f;
                }
            }
            break;

        case 'p':
        case 'P':
            if(paused == 0)
            {
                paused = 1;
            }
            else
            {
                paused = 0;
            }
            break;

        case 'r':
        case 'R':
            zoom = 1.0f;
            resetCurrentScene();
            break;

        case 'x':
        case 'X':
            exit(0);
            break;
    }

    glutPostRedisplay();
}

void timer(int value)
{
    if(paused == 0)
    {
        frameCount++;
        cloudMove = cloudMove + 0.35f;
        if(cloudMove > 1280.0f)
        {
            cloudMove = 0.0f;
        }

        birdMove = birdMove + 1.1f;
        if(birdMove > 1100.0f)
        {
            birdMove = birdMove - 1100.0f;
        }

        if(scene == 0)
        {
            carMove = carMove + 2.2f;
            if(carMove > 1050.0f)
            {
                carMove = -180.0f;
            }
        }

        if(scene == 1 || scene == 2)
        {
            // Doors
            if(frameCount > 35)
            {
                doorOpen = doorOpen + 0.04f;
                if(doorOpen > 1.0f)
                {
                    doorOpen = 1.0f;
                }
            }

            // People
            if(frameCount > 60)
            {
                runOut = runOut + 1.6f;
                if(runOut > 170.0f)
                {
                    runOut = 170.0f;
                }
            }
        }

        // Windows
        if(scene == 2 || scene == 3)
        {
            if(frameCount > 35)
            {
                windowOpen = windowOpen + 0.04f;
                if(windowOpen > 1.0f)
                {
                    windowOpen = 1.0f;
                }
            }
        }

        if(scene == 3)
        {
            floodLevel = floodLevel + 0.35f;
            if(floodLevel > 290.0f)
            {
                floodLevel = 290.0f;
            }

            // Boat
            boatMove = boatMove + 1.6f * boatDir;

            if(boatMove > 830.0f)
            {
                boatMove = 830.0f;
                boatDir = -1.0f;
            }

            if(boatMove < 0.0f && boatDir < 0.0f)
            {
                boatMove = 0.0f;
                boatDir = 1.0f;
            }
        }

        // Ambulance
        if(scene == 5)
        {
            if(ambMove > 800.0f)
            {
                ambMove = ambMove - 2.5f;
            }
        }
    }

    glutPostRedisplay();
    glutTimerFunc(30, timer, 0);
}

void init()
{
    glClearColor(0.17f, 0.48f, 0.75f, 1.0f);

    // Blending
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1000.0, 0.0, 650.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    int screenW = glutGet(GLUT_SCREEN_WIDTH);
    int screenH = glutGet(GLUT_SCREEN_HEIGHT);
    glutInitWindowSize(1000, 650);
    glutInitWindowPosition((screenW - 1000) / 2, (screenH - 650) / 2);
    glutCreateWindow("2D City Disaster Simulation");

    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(30, timer, 0);

    glutMainLoop();
    return 0;
}
