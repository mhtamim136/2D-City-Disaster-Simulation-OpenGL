// city/environment.h
// Sky, sun, clouds, ground, rain and birds

#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

void drawSky()
{
    glBegin(GL_POLYGON);

    if(scene == 4)
    {
        int lightningFlash = frameCount % 90;

        if(lightningFlash < 5)
        {
            glColor3f(0.40f, 0.45f, 0.55f);
        }
        else
        {
            glColor3f(0.13f, 0.17f, 0.25f);
        }
        glVertex2f(0.0f, 170.0f);
        glVertex2f(1000.0f, 170.0f);

        glColor3f(0.05f, 0.08f, 0.14f);
        glVertex2f(1000.0f, 650.0f);
        glVertex2f(0.0f, 650.0f);
    }
    else if(scene == 3)
    {
        glColor3f(0.42f, 0.58f, 0.68f);
        glVertex2f(0.0f, 170.0f);
        glVertex2f(1000.0f, 170.0f);

        glColor3f(0.23f, 0.34f, 0.45f);
        glVertex2f(1000.0f, 650.0f);
        glVertex2f(0.0f, 650.0f);
    }
    else
    {
        glColor3f(0.52f, 0.80f, 0.93f);
        glVertex2f(0.0f, 170.0f);
        glVertex2f(1000.0f, 170.0f);

        glColor3f(0.17f, 0.48f, 0.75f);
        glVertex2f(1000.0f, 650.0f);
        glVertex2f(0.0f, 650.0f);
    }

    glEnd();
}

void drawSun()
{
    if(scene == 3 || scene == 4)
    {
        return;
    }

    glColor3f(1.0f, 0.78f, 0.20f);
    drawCircle(875.0f, 570.0f, 34.0f);

    glLineWidth(2.0f);
    glBegin(GL_LINES);
    for(int i = 0; i < 12; i++)
    {
        float angle = 2.0f * PI * i / 12.0f;
        glVertex2f(875.0f + 44.0f * cos(angle),
                   570.0f + 44.0f * sin(angle));
        glVertex2f(875.0f + 58.0f * cos(angle),
                   570.0f + 58.0f * sin(angle));
    }
    glEnd();
    glLineWidth(1.0f);
}

void drawCloud(float x, float y, float scale, int dark)
{
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glScalef(scale, scale, 1.0f);

    if(dark == 1)
    {
        glColor3f(0.27f, 0.31f, 0.38f);
    }
    else
    {
        glColor3f(0.92f, 0.95f, 0.97f);
    }

    drawCircle(-35.0f, 0.0f, 24.0f);
    drawCircle(0.0f, 12.0f, 32.0f);
    drawCircle(38.0f, 2.0f, 26.0f);
    drawRectangle(-55.0f, -18.0f, 58.0f, 8.0f);

    glPopMatrix();
}

void drawMovingClouds()
{
    float firstCloud = cloudMove - 180.0f;
    float secondCloud = cloudMove + 360.0f;

    if(firstCloud > 1100.0f)
    {
        firstCloud = firstCloud - 1280.0f;
    }

    if(secondCloud > 1100.0f)
    {
        secondCloud = secondCloud - 1280.0f;
    }

    if(scene == 4)
    {
        drawCloud(firstCloud, 565.0f, 1.45f, 1);
        drawCloud(secondCloud, 535.0f, 1.65f, 1);
        drawCloud(750.0f, 590.0f, 1.30f, 1);
    }
    else if(scene == 3)
    {
        drawCloud(firstCloud, 565.0f, 1.20f, 1);
        drawCloud(secondCloud, 535.0f, 1.35f, 1);
    }
    else
    {
        drawCloud(firstCloud, 555.0f, 0.85f, 0);
        drawCloud(secondCloud, 525.0f, 0.95f, 0);
    }
}

void drawGround()
{
    // Sidewalk
    glColor3f(0.73f, 0.72f, 0.68f);
    drawRectangle(0.0f, 170.0f, 1000.0f, 210.0f);

    glColor3f(0.88f, 0.80f, 0.58f);
    drawRectangle(0.0f, 170.0f, 1000.0f, 178.0f);

    // Road
    glColor3f(0.11f, 0.15f, 0.21f);
    drawRectangle(0.0f, 0.0f, 1000.0f, 170.0f);

    // Road border
    glColor3f(0.92f, 0.92f, 0.88f);
    drawRectangle(0.0f, 154.0f, 1000.0f, 160.0f);

    // Lane marks
    glColor3f(0.95f, 0.72f, 0.16f);
    for(float x = 25.0f; x < 1000.0f; x = x + 130.0f)
    {
        drawRectangle(x, 78.0f, x + 75.0f, 84.0f);
    }
}

void drawRain(int wind)
{
    glColor3f(0.70f, 0.88f, 1.0f);
    glLineWidth(1.5f);

    glBegin(GL_LINES);
    for(int i = 0; i < 75; i++)
    {
        int x = (i * 79) % 1030;
        int fall = (frameCount * 11 + i * 37) % 540;
        int y = 650 - fall;

        glVertex2i(x, y);
        glVertex2i(x - wind, y - 28);
    }
    glEnd();

    glLineWidth(1.0f);
}

void drawBird(float x, float y, float scale, float flap)
{
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glScalef(scale, scale, 1.0f);

    glColor3f(0.08f, 0.10f, 0.16f);

    // Body
    glBegin(GL_POLYGON);
        glVertex2f(5.0f, 0.0f);
        glVertex2f(-9.0f, -3.0f);
        glVertex2f(-20.0f, 0.0f);
        glVertex2f(-9.0f, 3.0f);
    glEnd();

    // Left wing
    glPushMatrix();
        glRotatef(flap, 0.0f, 0.0f, 1.0f);
        glBegin(GL_POLYGON);
            glVertex2f(0.0f, 1.0f);
            glVertex2f(-14.0f, 14.0f);
            glVertex2f(-28.0f, 10.0f);
            glVertex2f(-12.0f, 3.0f);
        glEnd();
    glPopMatrix();

    // Right wing
    glPushMatrix();
        glRotatef(-flap, 0.0f, 0.0f, 1.0f);
        glBegin(GL_POLYGON);
            glVertex2f(0.0f, 1.0f);
            glVertex2f(14.0f, 14.0f);
            glVertex2f(28.0f, 10.0f);
            glVertex2f(12.0f, 3.0f);
        glEnd();
    glPopMatrix();

    glPopMatrix();
}

void drawBirds()
{
    if(scene != 0)
    {
        return;
    }

    float flap = sin(frameCount * 0.25f) * 28.0f;

    float bird1 = birdMove;
    float bird2 = birdMove + 120.0f;
    float bird3 = birdMove + 260.0f;

    if(bird2 > 1100.0f)
    {
        bird2 = bird2 - 1100.0f;
    }

    if(bird3 > 1100.0f)
    {
        bird3 = bird3 - 1100.0f;
    }

    drawBird(bird1 - 100.0f, 545.0f, 1.0f, flap);
    drawBird(bird2 - 100.0f, 515.0f, 0.85f, flap * 0.8f);
    drawBird(bird3 - 100.0f, 570.0f, 0.7f, flap * 1.1f);
}

#endif
