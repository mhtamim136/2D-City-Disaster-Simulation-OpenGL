// scenes/earthquake.h
// Road cracks, debris and escaping people

#ifndef EARTHQUAKE_H
#define EARTHQUAKE_H

void drawRoadCrack()
{
    glColor3f(0.01f, 0.02f, 0.03f);
    glLineWidth(6.0f);

    glBegin(GL_LINES);
        glVertex2f(390.0f, 155.0f);
        glVertex2f(430.0f, 122.0f);

        glVertex2f(430.0f, 122.0f);
        glVertex2f(410.0f, 95.0f);

        glVertex2f(410.0f, 95.0f);
        glVertex2f(470.0f, 62.0f);

        glVertex2f(470.0f, 62.0f);
        glVertex2f(450.0f, 25.0f);
    glEnd();

    glLineWidth(3.0f);
    glBegin(GL_LINES);
        glVertex2f(430.0f, 122.0f);
        glVertex2f(475.0f, 130.0f);

        glVertex2f(410.0f, 95.0f);
        glVertex2f(365.0f, 75.0f);

        glVertex2f(470.0f, 62.0f);
        glVertex2f(515.0f, 48.0f);
    glEnd();

    glLineWidth(1.0f);
}

void drawDebrisBox(float x, float y, float scale, float angle)
{
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glRotatef(angle, 0.0f, 0.0f, 1.0f);
    glScalef(scale, scale, 1.0f);

    // Front face
    glColor3f(0.28f, 0.30f, 0.32f);
    glBegin(GL_POLYGON);
        glVertex2f(-22.0f, 0.0f);
        glVertex2f(22.0f, 0.0f);
        glVertex2f(22.0f, 38.0f);
        glVertex2f(-22.0f, 38.0f);
    glEnd();

    // Right face
    glColor3f(0.18f, 0.20f, 0.22f);
    glBegin(GL_POLYGON);
        glVertex2f(22.0f, 0.0f);
        glVertex2f(35.0f, 11.0f);
        glVertex2f(35.0f, 49.0f);
        glVertex2f(22.0f, 38.0f);
    glEnd();

    // Top face
    glColor3f(0.42f, 0.44f, 0.46f);
    glBegin(GL_POLYGON);
        glVertex2f(-22.0f, 38.0f);
        glVertex2f(22.0f, 38.0f);
        glVertex2f(35.0f, 49.0f);
        glVertex2f(-9.0f, 49.0f);
    glEnd();

    glPopMatrix();
}

void drawEscapePerson(float doorX, float streetX, float streetY, float scale,
                      float startDelay,
                      float red, float green, float blue)
{
    float move = runOut - startDelay;

    if(move <= 0.0f)
    {
        return;
    }

    float t = move / 100.0f;

    if(t > 1.0f)
    {
        t = 1.0f;
    }

    float x = doorX + (streetX - doorX) * t;
    float y = 205.0f + (streetY - 205.0f) * t;

    float swing = sin(frameCount * 0.35f) * 20.0f;

    if(t >= 1.0f)
    {
        swing = sin(frameCount * 0.18f) * 6.0f;
    }

    drawPerson(x, y, scale, red, green, blue, swing, swing, 0);
}

void drawEarthquakeScene()
{
    drawRoadCrack();
    drawDebrisBox(390.0f, 176.0f, 0.70f, -18.0f);
    drawDebrisBox(650.0f, 178.0f, 0.55f, 24.0f);

    drawCar(505.0f, 88.0f, 0.82f, -8.0f);

    // Hospital
    drawEscapePerson(185.0f, 125.0f, 92.0f, 0.60f, 0.0f,
                     0.92f, 0.25f, 0.20f);

    // Tower
    drawEscapePerson(480.0f, 345.0f, 105.0f, 0.58f, 12.0f,
                     0.12f, 0.55f, 0.78f);

    drawEscapePerson(520.0f, 680.0f, 85.0f, 0.62f, 45.0f,
                     0.95f, 0.80f, 0.25f);

    // Apartment
    drawEscapePerson(810.0f, 865.0f, 196.0f, 0.50f, 22.0f,
                     0.30f, 0.70f, 0.35f);
}

#endif
