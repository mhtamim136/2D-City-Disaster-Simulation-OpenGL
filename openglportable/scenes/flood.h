// scenes/flood.h
// Flood water and rescue boat

#ifndef FLOOD_H
#define FLOOD_H

void drawFloodWater()
{
    glColor3f(0.08f, 0.45f, 0.64f);
    drawRectangle(0.0f, 0.0f, 1000.0f, floodLevel);

    // Top wave
    glColor3f(0.35f, 0.75f, 0.82f);
    glLineWidth(3.0f);
    glBegin(GL_LINES);
    for(float x = 0.0f; x < 1000.0f; x = x + 20.0f)
    {
        float y1 = floodLevel + sin(x * 0.035f + frameCount * 0.12f) * 7.0f;
        float y2 = floodLevel + sin((x + 20.0f) * 0.035f + frameCount * 0.12f) * 7.0f;

        glVertex2f(x, y1);
        glVertex2f(x + 20.0f, y2);
    }
    glEnd();

    // Small water lines
    glLineWidth(2.0f);
    for(int row = 0; row < 3; row++)
    {
        float y = floodLevel - 30.0f - row * 42.0f;

        glBegin(GL_LINES);
        for(float x = 20.0f; x < 960.0f; x = x + 120.0f)
        {
            glVertex2f(x, y);
            glVertex2f(x + 55.0f, y);
        }
        glEnd();
    }

    glLineWidth(1.0f);
}

void drawBoat()
{
    glPushMatrix();
    glTranslatef(boatMove, floodLevel + 10.0f, 0.0f);

    glColor3f(0.95f, 0.48f, 0.12f);
    glBegin(GL_POLYGON);
        glVertex2f(0.0f, 25.0f);
        glVertex2f(170.0f, 25.0f);
        glVertex2f(142.0f, -22.0f);
        glVertex2f(25.0f, -22.0f);
    glEnd();

    glColor3f(0.55f, 0.20f, 0.12f);
    drawRectangle(25.0f, -8.0f, 145.0f, 4.0f);

    glColor3f(1.0f, 1.0f, 1.0f);
    drawText(48.0f, 7.0f, GLUT_BITMAP_HELVETICA_12, "RESCUE");

    drawPerson(55.0f, 24.0f, 0.36f,
               0.86f, 0.12f, 0.12f,
               5.0f, 0.0f, 1);

    drawPerson(112.0f, 24.0f, 0.36f,
               0.12f, 0.48f, 0.70f,
               -5.0f, 0.0f, 1);

    glPopMatrix();
}

void drawFloodWindows()
{
    // Hospital
    drawOpenWindow(107.0f, 335.0f, 34.0f, 34.0f, windowOpen);
    drawOpenWindow(221.0f, 335.0f, 34.0f, 34.0f, windowOpen);

    // Tower
    drawOpenWindow(438.0f, 472.0f, 40.0f, 35.0f, windowOpen);

    // Apartment
    drawOpenWindow(848.0f, 353.0f, 42.0f, 38.0f, windowOpen);

    if(windowOpen < 1.0f)
    {
        return;
    }

    drawHelpPerson(124.0f, 336.0f, 0.28f, 0.92f, 0.35f, 0.22f);

    drawHelpPerson(450.0f, 474.0f, 0.24f, 0.95f, 0.82f, 0.25f);
    drawHelpPerson(466.0f, 474.0f, 0.24f, 0.25f, 0.70f, 0.42f);

    drawHelpPerson(869.0f, 354.0f, 0.30f, 0.20f, 0.42f, 0.78f);
}

void drawFloodScene()
{
    drawCar(315.0f, 82.0f, 0.88f, 2.0f);

    drawFloodWindows();

    drawFloodWater();
    drawBoat();

    // Floating wood
    glColor3f(0.35f, 0.20f, 0.09f);
    glPushMatrix();
    glTranslatef(560.0f, floodLevel + 12.0f, 0.0f);
    glRotatef(sin(frameCount * 0.08f) * 8.0f, 0.0f, 0.0f, 1.0f);
    drawRectangle(-35.0f, -5.0f, 35.0f, 5.0f);
    glPopMatrix();

    drawRain(5);
}

#endif
