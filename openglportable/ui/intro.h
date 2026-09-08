// ui/intro.h
// Intro screen shown before the simulation starts

#ifndef INTRO_H
#define INTRO_H

void drawIntro()
{
    // Background
    glColor3f(0.05f, 0.09f, 0.17f);
    drawRectangle(0.0f, 0.0f, 1000.0f, 650.0f);

    // Title
    glColor3f(1.0f, 1.0f, 1.0f);
    drawText(268.0f, 560.0f, GLUT_BITMAP_TIMES_ROMAN_24,
             "2D CITY DISASTER SIMULATION");

    glColor3f(0.18f, 0.72f, 0.72f);
    drawRectangle(150.0f, 540.0f, 850.0f, 546.0f);

    glColor3f(0.70f, 0.80f, 0.88f);
    drawText(396.0f, 512.0f, GLUT_BITMAP_HELVETICA_12,
             "Computer Graphics Project");

    // Scene list
    glColor3f(1.0f, 0.78f, 0.22f);
    drawText(300.0f, 458.0f, GLUT_BITMAP_HELVETICA_18, "SCENES");

    glColor3f(0.88f, 0.92f, 0.96f);
    drawText(300.0f, 430.0f, GLUT_BITMAP_HELVETICA_12, "1.  Normal City");
    drawText(300.0f, 410.0f, GLUT_BITMAP_HELVETICA_12, "2.  Earthquake");
    drawText(300.0f, 390.0f, GLUT_BITMAP_HELVETICA_12, "3.  Fire");
    drawText(300.0f, 370.0f, GLUT_BITMAP_HELVETICA_12, "4.  Flood");
    drawText(300.0f, 350.0f, GLUT_BITMAP_HELVETICA_12, "5.  Storm");
    drawText(300.0f, 330.0f, GLUT_BITMAP_HELVETICA_12, "6.  Road Accident");

    // Controls
    glColor3f(1.0f, 0.78f, 0.22f);
    drawText(300.0f, 288.0f, GLUT_BITMAP_HELVETICA_18, "CONTROLS");

    glColor3f(0.88f, 0.92f, 0.96f);
    drawText(300.0f, 260.0f, GLUT_BITMAP_HELVETICA_12,
             "A  /  D        Previous or next scene");
    drawText(300.0f, 240.0f, GLUT_BITMAP_HELVETICA_12,
             "P              Pause or continue");
    drawText(300.0f, 220.0f, GLUT_BITMAP_HELVETICA_12,
             "R              Reset scene and zoom");
    drawText(300.0f, 200.0f, GLUT_BITMAP_HELVETICA_12,
             "N              Night mode (normal city only)");
    drawText(300.0f, 180.0f, GLUT_BITMAP_HELVETICA_12,
             "E              Evening mode (normal city only)");
    drawText(300.0f, 160.0f, GLUT_BITMAP_HELVETICA_12,
             "+  /  -        Zoom in or out");
    drawText(300.0f, 140.0f, GLUT_BITMAP_HELVETICA_12,
             "X              Exit");

    glColor3f(1.0f, 0.55f, 0.30f);
    drawText(300.0f, 118.0f, GLUT_BITMAP_HELVETICA_12,
             "Fire scene:   W  Water     J / L  Aim left-right     I / K  Aim up-down");

    // Start line
    glColor3f(0.18f, 0.72f, 0.72f);
    drawRectangle(150.0f, 104.0f, 850.0f, 108.0f);

    glColor3f(1.0f, 1.0f, 1.0f);
    drawText(404.0f, 72.0f, GLUT_BITMAP_HELVETICA_18, "Press any key to start");
}

#endif
