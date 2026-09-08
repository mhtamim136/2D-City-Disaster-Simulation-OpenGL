// scenes/storm.h
// Lightning and flying objects

#ifndef STORM_H
#define STORM_H

void drawLightning()
{
    int flash = frameCount % 90;

    if(flash > 13)
    {
        return;
    }

    glColor3f(1.0f, 0.95f, 0.35f);
    glLineWidth(6.0f);
    glBegin(GL_LINES);
        glVertex2f(660.0f, 575.0f);
        glVertex2f(625.0f, 510.0f);

        glVertex2f(625.0f, 510.0f);
        glVertex2f(655.0f, 510.0f);

        glVertex2f(655.0f, 510.0f);
        glVertex2f(610.0f, 435.0f);

        glVertex2f(610.0f, 435.0f);
        glVertex2f(640.0f, 435.0f);

        glVertex2f(640.0f, 435.0f);
        glVertex2f(590.0f, 350.0f);
    glEnd();

    // Side branch
    glColor3f(1.0f, 1.0f, 0.72f);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
        glVertex2f(655.0f, 510.0f);
        glVertex2f(715.0f, 535.0f);
    glEnd();

    glLineWidth(1.0f);
}

void drawFlyingObjects()
{
    int step = (frameCount * 4) % 1200;

    float move = step - 100.0f;
    float wave = sin(frameCount * 0.15f) * 24.0f;

    // Flying paper
    glPushMatrix();
    glTranslatef(move, 430.0f + wave, 0.0f);
    glRotatef(sin(frameCount * 0.12f) * 35.0f,
              0.0f, 0.0f, 1.0f);

    glColor3f(0.94f, 0.88f, 0.72f);
    drawRectangle(-22.0f, -14.0f, 22.0f, 14.0f);

    glColor3f(0.35f, 0.27f, 0.18f);
    glBegin(GL_LINES);
        glVertex2f(-18.0f, 5.0f);
        glVertex2f(13.0f, 5.0f);
        glVertex2f(-18.0f, -3.0f);
        glVertex2f(8.0f, -3.0f);
    glEnd();
    glPopMatrix();

    // Flying leaf
    glPushMatrix();
    glTranslatef(950.0f - move, 300.0f - wave, 0.0f);
    glRotatef(frameCount * 5.0f, 0.0f, 0.0f, 1.0f);

    glColor3f(0.32f, 0.70f, 0.18f);
    glBegin(GL_POLYGON);
        glVertex2f(-24.0f, 0.0f);
        glVertex2f(-8.0f, 14.0f);
        glVertex2f(18.0f, 10.0f);
        glVertex2f(28.0f, 0.0f);
        glVertex2f(18.0f, -10.0f);
        glVertex2f(-8.0f, -14.0f);
    glEnd();

    glColor3f(0.12f, 0.34f, 0.08f);
    glBegin(GL_LINES);
        glVertex2f(-24.0f, 0.0f);
        glVertex2f(32.0f, 0.0f);
    glEnd();
    glPopMatrix();
}

void drawStormScene()
{
    drawCar(500.0f, 80.0f, 0.82f, 0.0f);
    drawUmbrellaPerson(760.0f, 188.0f, 0.65f);
    drawFlyingObjects();
    drawRain(16);
    drawLightning();
}

#endif
