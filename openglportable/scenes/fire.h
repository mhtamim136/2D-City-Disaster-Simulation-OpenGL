// scenes/fire.h
// Flames, smoke, fire truck, water jet and ambulance

#ifndef FIRE_H
#define FIRE_H

void drawFlame(float x, float y, float scale)
{
    float flicker = sin(frameCount * 0.32f + x) * 8.0f;

    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glScalef(scale, scale, 1.0f);

    glColor3f(0.95f, 0.18f, 0.05f);
    glBegin(GL_TRIANGLES);
        glVertex2f(-22.0f, 0.0f);
        glVertex2f(22.0f, 0.0f);
        glVertex2f(0.0f, 65.0f + flicker);
    glEnd();
    drawCircle(0.0f, 8.0f, 23.0f);

    glColor3f(1.0f, 0.72f, 0.08f);
    glBegin(GL_TRIANGLES);
        glVertex2f(-12.0f, 0.0f);
        glVertex2f(12.0f, 0.0f);
        glVertex2f(3.0f, 40.0f - flicker * 0.25f);
    glEnd();
    drawCircle(0.0f, 7.0f, 12.0f);

    glPopMatrix();
}

void drawSmoke(float x, float y)
{
    for(int i = 0; i < 4; i++)
    {
        float rise = ((frameCount * 17 + i * 250) % 1050) / 10.0f;
        float sway = sin(frameCount * 0.08f + i) * 10.0f;

        glColor3f(0.30f + i * 0.07f,
                  0.30f + i * 0.07f,
                  0.32f + i * 0.07f);
        drawCircle(x + sway, y + rise, 13.0f + i * 2.0f);
    }
}

void drawFireTruck()
{
    glPushMatrix();
    glTranslatef(525.0f, 73.0f, 0.0f);

    // Truck body
    glColor3f(0.86f, 0.10f, 0.12f);
    drawRectangle(0.0f, 0.0f, 190.0f, 58.0f);
    drawRectangle(125.0f, 58.0f, 190.0f, 102.0f);

    // Cabin window
    glColor3f(0.55f, 0.82f, 0.91f);
    drawRectangle(138.0f, 67.0f, 180.0f, 94.0f);

    // Yellow stripe
    glColor3f(1.0f, 0.75f, 0.14f);
    drawRectangle(0.0f, 29.0f, 190.0f, 39.0f);

    // Equipment boxes
    glColor3f(0.64f, 0.07f, 0.10f);
    drawRectangle(15.0f, 43.0f, 55.0f, 73.0f);
    drawRectangle(65.0f, 43.0f, 105.0f, 73.0f);

    // Ladder
    glColor3f(0.82f, 0.84f, 0.85f);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
        glVertex2f(18.0f, 84.0f);
        glVertex2f(120.0f, 104.0f);
        glVertex2f(18.0f, 94.0f);
        glVertex2f(120.0f, 114.0f);
    glEnd();

    for(float x = 30.0f; x <= 110.0f; x = x + 20.0f)
    {
        glBegin(GL_LINES);
            glVertex2f(x, 87.0f);
            glVertex2f(x, 100.0f);
        glEnd();
    }

    // Siren
    if(frameCount % 20 < 10)
    {
        glColor3f(0.15f, 0.60f, 1.0f);
    }
    else
    {
        glColor3f(1.0f, 0.15f, 0.15f);
    }
    drawRectangle(145.0f, 102.0f, 170.0f, 112.0f);

    drawWheel(42.0f, 0.0f, 22.0f);
    drawWheel(152.0f, 0.0f, 22.0f);

    glLineWidth(1.0f);
    glPopMatrix();
}

void drawWaterJet()
{
    if(waterOn == 0)
    {
        return;
    }

    float targetY = hoseTargetY;

    glColor3f(0.55f, 0.88f, 1.0f);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
        glVertex2f(710.0f, 145.0f);
        glVertex2f(hoseTargetX, targetY);
    glEnd();

    glPointSize(3.0f);
    glBegin(GL_POINTS);
    for(int i = 0; i < 14; i++)
    {
        float dropX = hoseTargetX - 18.0f + (i % 7) * 6.0f;
        float dropY = targetY - 12.0f + (i / 7) * 17.0f;
        glVertex2f(dropX, dropY);
    }
    glEnd();

    glPointSize(1.0f);
    glLineWidth(1.0f);
}

void drawAmbulance(float x)
{
    glPushMatrix();
    glTranslatef(x, 73.0f, 0.0f);

    // Cabin
    glColor3f(0.95f, 0.96f, 0.98f);
    drawRectangle(140.0f, 0.0f, 195.0f, 56.0f);

    // Cabin window
    glColor3f(0.55f, 0.82f, 0.91f);
    drawRectangle(147.0f, 30.0f, 189.0f, 52.0f);

    // Patient box
    glColor3f(0.95f, 0.96f, 0.98f);
    drawRectangle(0.0f, 0.0f, 140.0f, 80.0f);

    // Red stripe
    glColor3f(0.88f, 0.14f, 0.16f);
    drawRectangle(0.0f, 22.0f, 195.0f, 32.0f);

    // Red cross
    drawRectangle(70.0f, 50.0f, 100.0f, 60.0f);
    drawRectangle(80.0f, 40.0f, 90.0f, 70.0f);

    // Open back door
    glColor3f(0.10f, 0.13f, 0.18f);
    drawRectangle(3.0f, 6.0f, 27.0f, 62.0f);

    // Siren
    if(frameCount % 20 < 10)
    {
        glColor3f(1.0f, 0.15f, 0.15f);
    }
    else
    {
        glColor3f(0.15f, 0.60f, 1.0f);
    }
    drawRectangle(151.0f, 56.0f, 177.0f, 66.0f);

    drawWheel(35.0f, 0.0f, 20.0f);
    drawWheel(155.0f, 0.0f, 20.0f);

    glPopMatrix();
}

void drawRescuePerson(float startDelay, float scale,
                      float red, float green, float blue)
{
    float move = runOut - startDelay;

    if(move <= 0.0f)
    {
        return;
    }

    float t = move / 100.0f;

    if(t >= 1.0f)
    {
        return;
    }

    float x;
    float y;

    if(t < 0.65f)
    {
        float k = t / 0.65f;
        x = 810.0f + (790.0f - 810.0f) * k;
        y = 205.0f + (182.0f - 205.0f) * k;
    }
    else
    {
        float k = (t - 0.65f) / 0.35f;
        x = 790.0f + (775.0f - 790.0f) * k;
        y = 182.0f + (105.0f - 182.0f) * k;
    }

    float swing = sin(frameCount * 0.35f) * 20.0f;

    drawPerson(x, y, scale, red, green, blue, swing, swing, 0);
}

void drawFireScene()
{
    drawFlame(750.0f, 424.0f, 0.85f);
    drawFlame(852.0f, 424.0f, 0.90f);
    drawFlame(750.0f, 350.0f, 0.70f);

    drawSmoke(750.0f, 470.0f);
    drawSmoke(852.0f, 470.0f);

    // Open window
    drawOpenWindow(848.0f, 353.0f, 42.0f, 38.0f, windowOpen);

    if(windowOpen >= 1.0f)
    {
        drawHelpPerson(869.0f, 354.0f, 0.30f, 0.20f, 0.42f, 0.78f);
    }

    drawFireTruck();

    drawPerson(742.0f, 186.0f, 0.62f,
               0.78f, 0.10f, 0.10f,
               -35.0f, 4.0f, 1);

    drawPerson(935.0f, 187.0f, 0.52f,
               0.16f, 0.52f, 0.76f,
               45.0f, 2.0f, 0);

    drawRescuePerson(0.0f, 0.56f, 0.92f, 0.52f, 0.18f);
    drawRescuePerson(35.0f, 0.52f, 0.20f, 0.62f, 0.60f);
    drawRescuePerson(70.0f, 0.58f, 0.72f, 0.46f, 0.82f);

    drawAmbulance(760.0f);

    drawWaterJet();
}

#endif
