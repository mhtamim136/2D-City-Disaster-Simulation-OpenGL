// city/vehicles.h
// Wheels and car

#ifndef VEHICLES_H
#define VEHICLES_H

void drawWheel(float x, float y, float radius)
{
    glColor3f(0.03f, 0.04f, 0.06f);
    drawCircle(x, y, radius);

    glColor3f(0.55f, 0.62f, 0.68f);
    drawCircle(x, y, radius * 0.45f);

    glColor3f(0.95f, 0.95f, 0.92f);
    glPointSize(2.0f);
    drawMidpointCircle((int)x, (int)y, (int)radius + 2);
    glPointSize(1.0f);
}

void drawCar(float x, float y, float scale, float angle)
{
    glPushMatrix();

    glTranslatef(x, y, 0.0f);
    glRotatef(angle, 0.0f, 0.0f, 1.0f);
    glScalef(scale, scale, 1.0f);

    // Body
    glColor3f(0.08f, 0.42f, 0.75f);

    glBegin(GL_POLYGON);
        glVertex2f(2.0f, 2.0f);
        glVertex2f(2.0f, 28.0f);
        glVertex2f(42.0f, 28.0f);

        glVertex2f(58.0f, 50.0f);
        glVertex2f(106.0f, 50.0f);

        glVertex2f(120.0f, 28.0f);
        glVertex2f(164.0f, 28.0f);

        glVertex2f(164.0f, 2.0f);
    glEnd();

    glColor3f(0.18f, 0.35f, 0.55f);

    // Back window
    glBegin(GL_POLYGON);
        glVertex2f(46.0f, 28.0f);
        glVertex2f(60.0f, 45.0f);
        glVertex2f(76.0f, 45.0f);
        glVertex2f(76.0f, 28.0f);
    glEnd();

    // Front window
    glBegin(GL_POLYGON);
        glVertex2f(86.0f, 45.0f);
        glVertex2f(100.0f, 45.0f);
        glVertex2f(110.0f, 28.0f);
        glVertex2f(86.0f, 28.0f);
    glEnd();

    // Pillar and door handles
    glColor3f(0.03f, 0.12f, 0.22f);
    glLineWidth(2.0f);

    glBegin(GL_LINES);
        glVertex2f(82.0f, 50.0f);
        glVertex2f(82.0f, 2.0f);

        glVertex2f(64.0f, 22.0f);
        glVertex2f(75.0f, 22.0f);

        glVertex2f(88.0f, 22.0f);
        glVertex2f(99.0f, 22.0f);
    glEnd();

    // Back light
    glColor3f(0.95f, 0.10f, 0.08f);
    glBegin(GL_POLYGON);
        glVertex2f(2.0f, 20.0f);
        glVertex2f(2.0f, 28.0f);
        glVertex2f(13.0f, 28.0f);
        glVertex2f(13.0f, 20.0f);
    glEnd();

    // Front light
    glColor3f(1.0f, 0.90f, 0.35f);
    glBegin(GL_POLYGON);
        glVertex2f(156.0f, 28.0f);
        glVertex2f(164.0f, 28.0f);
        glVertex2f(164.0f, 22.0f);
        glVertex2f(156.0f, 22.0f);
    glEnd();

    // Bumpers
    glColor3f(0.05f, 0.08f, 0.12f);
    drawRectangle(132.0f, 0.0f, 166.0f, 7.0f);
    drawRectangle(0.0f, 0.0f, 26.0f, 8.0f);

    // Wheels
    drawWheel(38.0f, 2.0f, 15.0f);
    drawWheel(118.0f, 2.0f, 15.0f);

    // Rims
    glColor3f(0.75f, 0.80f, 0.85f);
    drawCircle(38.0f, 2.0f, 6.0f);
    drawCircle(118.0f, 2.0f, 6.0f);

    glLineWidth(1.0f);
    glPopMatrix();
}

#endif
