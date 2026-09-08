// scenes/accident.h
// Road accident scene with crashed cars, police and ambulance

#ifndef ACCIDENT_H
#define ACCIDENT_H

void drawCrashedCar(float x, float y, float angle, int flip,
                    float red, float green, float blue)
{
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glRotatef(angle, 0.0f, 0.0f, 1.0f);

    if(flip == 1)
    {
        glScalef(-1.0f, 1.0f, 1.0f);
    }

    // Crushed body
    glColor3f(red, green, blue);
    glBegin(GL_POLYGON);
        glVertex2f(0.0f, 2.0f);
        glVertex2f(0.0f, 26.0f);
        glVertex2f(36.0f, 26.0f);
        glVertex2f(50.0f, 46.0f);
        glVertex2f(94.0f, 44.0f);
        glVertex2f(106.0f, 26.0f);
        glVertex2f(124.0f, 18.0f);
        glVertex2f(132.0f, 2.0f);
    glEnd();

    // Dented front
    glColor3f(red * 0.55f, green * 0.55f, blue * 0.55f);
    glBegin(GL_POLYGON);
        glVertex2f(106.0f, 26.0f);
        glVertex2f(124.0f, 18.0f);
        glVertex2f(132.0f, 2.0f);
        glVertex2f(108.0f, 2.0f);
    glEnd();

    // Broken window
    glColor3f(0.10f, 0.14f, 0.20f);
    glBegin(GL_POLYGON);
        glVertex2f(54.0f, 26.0f);
        glVertex2f(62.0f, 41.0f);
        glVertex2f(78.0f, 33.0f);
        glVertex2f(88.0f, 40.0f);
        glVertex2f(92.0f, 26.0f);
    glEnd();

    // Cracks
    glColor3f(0.85f, 0.92f, 0.96f);
    glLineWidth(1.5f);
    glBegin(GL_LINES);
        glVertex2f(58.0f, 28.0f);
        glVertex2f(74.0f, 38.0f);

        glVertex2f(90.0f, 28.0f);
        glVertex2f(76.0f, 36.0f);
    glEnd();
    glLineWidth(1.0f);

    // Broken bumper
    glColor3f(0.05f, 0.08f, 0.12f);
    drawRectangle(136.0f, 0.0f, 158.0f, 6.0f);

    drawWheel(34.0f, 2.0f, 14.0f);
    drawWheel(108.0f, 2.0f, 14.0f);

    glPopMatrix();
}

void drawSkidMarks()
{
    glColor3f(0.04f, 0.05f, 0.07f);
    glPointSize(6.0f);
    drawDDALine(196, 64, 392, 78);
    drawDDALine(196, 82, 392, 96);
    glPointSize(1.0f);
}

void drawBrokenGlass()
{
    glColor3f(0.84f, 0.94f, 1.0f);
    glPointSize(3.0f);

    glBegin(GL_POINTS);
        glVertex2i(438, 132);
        glVertex2i(462, 146);
        glVertex2i(474, 128);
        glVertex2i(489, 150);
        glVertex2i(452, 138);
        glVertex2i(505, 131);
        glVertex2i(518, 147);
        glVertex2i(496, 136);
        glVertex2i(533, 129);
        glVertex2i(547, 145);
        glVertex2i(524, 139);
        glVertex2i(561, 133);
        glVertex2i(576, 148);
        glVertex2i(553, 137);
        glVertex2i(590, 130);
        glVertex2i(604, 143);
    glEnd();

    glPointSize(1.0f);
}

void drawTrafficCone(float x, float y)
{
    glColor3f(0.95f, 0.35f, 0.08f);
    glBegin(GL_TRIANGLES);
        glVertex2f(x - 13.0f, y);
        glVertex2f(x + 13.0f, y);
        glVertex2f(x, y + 34.0f);
    glEnd();

    glColor3f(0.96f, 0.96f, 0.92f);
    drawRectangle(x - 8.0f, y + 13.0f, x + 8.0f, y + 19.0f);

    glColor3f(0.55f, 0.20f, 0.06f);
    drawRectangle(x - 16.0f, y, x + 16.0f, y + 5.0f);
}

void drawBarrier(float x, float y)
{
    // Legs
    glColor3f(0.20f, 0.24f, 0.30f);
    drawRectangle(x + 4.0f, y, x + 10.0f, y + 40.0f);
    drawRectangle(x + 62.0f, y, x + 68.0f, y + 40.0f);

    // Board
    glColor3f(0.96f, 0.96f, 0.92f);
    drawRectangle(x, y + 26.0f, x + 72.0f, y + 46.0f);

    // Red stripes
    glColor3f(0.90f, 0.14f, 0.14f);
    for(float i = 0.0f; i < 72.0f; i = i + 24.0f)
    {
        glBegin(GL_TRIANGLES);
            glVertex2f(x + i, y + 26.0f);
            glVertex2f(x + i + 12.0f, y + 26.0f);
            glVertex2f(x + i + 12.0f, y + 46.0f);
        glEnd();
    }
}

void drawPoliceCar(float x)
{
    glPushMatrix();
    glTranslatef(x, 73.0f, 0.0f);

    // Body
    glColor3f(0.92f, 0.94f, 0.97f);
    drawRectangle(0.0f, 0.0f, 170.0f, 30.0f);

    glBegin(GL_POLYGON);
        glVertex2f(40.0f, 30.0f);
        glVertex2f(56.0f, 54.0f);
        glVertex2f(116.0f, 54.0f);
        glVertex2f(132.0f, 30.0f);
    glEnd();

    // Windows
    glColor3f(0.22f, 0.40f, 0.60f);
    drawRectangle(60.0f, 34.0f, 82.0f, 50.0f);
    drawRectangle(90.0f, 34.0f, 112.0f, 50.0f);

    // Side band
    glColor3f(0.10f, 0.28f, 0.70f);
    drawRectangle(0.0f, 11.0f, 170.0f, 23.0f);

    glColor3f(1.0f, 1.0f, 1.0f);
    drawText(56.0f, 14.0f, GLUT_BITMAP_HELVETICA_12, "POLICE");

    // Siren
    if(frameCount % 20 < 10)
    {
        glColor3f(0.15f, 0.55f, 1.0f);
    }
    else
    {
        glColor3f(1.0f, 0.15f, 0.15f);
    }
    drawRectangle(72.0f, 54.0f, 100.0f, 63.0f);

    drawWheel(38.0f, 0.0f, 17.0f);
    drawWheel(132.0f, 0.0f, 17.0f);

    glPopMatrix();
}

void drawInjuredPerson(float x, float y)
{
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glRotatef(90.0f, 0.0f, 0.0f, 1.0f);

    drawPerson(0.0f, 0.0f, 0.50f,
               0.86f, 0.80f, 0.32f,
               22.0f, 14.0f, 0);

    glPopMatrix();
}

void drawAccidentScene()
{
    drawSkidMarks();

    drawCrashedCar(366.0f, 84.0f, -15.0f, 0,
                   0.85f, 0.20f, 0.18f);

    drawCrashedCar(652.0f, 78.0f, 8.0f, 1,
                   0.20f, 0.48f, 0.36f);

    drawBrokenGlass();

    // Barriers and cones
    drawBarrier(222.0f, 60.0f);
    drawBarrier(724.0f, 60.0f);

    drawTrafficCone(312.0f, 60.0f);
    drawTrafficCone(338.0f, 60.0f);
    drawTrafficCone(672.0f, 60.0f);
    drawTrafficCone(698.0f, 60.0f);

    drawPoliceCar(30.0f);
    drawAmbulance(ambMove);

    drawInjuredPerson(326.0f, 180.0f);

    // Traffic police
    drawPerson(452.0f, 182.0f, 0.60f,
               0.12f, 0.22f, 0.52f,
               150.0f, 0.0f, 1);

    // Crowd
    drawPerson(130.0f, 182.0f, 0.56f,
               0.90f, 0.55f, 0.20f,
               -12.0f, 0.0f, 0);

    drawPerson(186.0f, 182.0f, 0.52f,
               0.25f, 0.60f, 0.55f,
               14.0f, 0.0f, 0);

    drawHelpPerson(700.0f, 182.0f, 0.58f, 0.75f, 0.30f, 0.62f);
    drawHelpPerson(752.0f, 182.0f, 0.54f, 0.95f, 0.85f, 0.30f);
}

#endif
