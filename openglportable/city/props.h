// city/props.h
// Trees and street lamps

#ifndef PROPS_H
#define PROPS_H

void drawTree(float x, float y, float scale, float angle)
{
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glRotatef(angle, 0.0f, 0.0f, 1.0f);
    glScalef(scale, scale, 1.0f);

    // Trunk
    glColor3f(0.32f, 0.22f, 0.10f);
    glBegin(GL_POLYGON);
        glVertex2f(-12.0f, 0.0f);
        glVertex2f(-18.0f, 35.0f);
        glVertex2f(-14.0f, 80.0f);
        glVertex2f(-8.0f, 120.0f);
        glVertex2f(0.0f, 140.0f);
        glVertex2f(8.0f, 120.0f);
        glVertex2f(14.0f, 80.0f);
        glVertex2f(18.0f, 35.0f);
        glVertex2f(12.0f, 0.0f);
    glEnd();

    // Trunk shade
    glColor3f(0.18f, 0.12f, 0.05f);
    glBegin(GL_POLYGON);
        glVertex2f(-3.0f, 0.0f);
        glVertex2f(3.0f, 0.0f);
        glVertex2f(8.0f, 70.0f);
        glVertex2f(2.0f, 130.0f);
        glVertex2f(-2.0f, 130.0f);
        glVertex2f(0.0f, 70.0f);
    glEnd();

    // Roots
    glColor3f(0.20f, 0.14f, 0.06f);
    glBegin(GL_TRIANGLES);
        glVertex2f(0.0f, 5.0f);
        glVertex2f(-35.0f, -8.0f);
        glVertex2f(-8.0f, 15.0f);

        glVertex2f(0.0f, 5.0f);
        glVertex2f(35.0f, -8.0f);
        glVertex2f(8.0f, 15.0f);
    glEnd();

    // Thick branches
    glColor3f(0.08f, 0.06f, 0.03f);
    glLineWidth(6.0f);
    glBegin(GL_LINES);
        glVertex2f(0.0f, 90.0f);
        glVertex2f(-45.0f, 145.0f);

        glVertex2f(0.0f, 95.0f);
        glVertex2f(45.0f, 150.0f);

        glVertex2f(-5.0f, 70.0f);
        glVertex2f(-60.0f, 105.0f);

        glVertex2f(5.0f, 70.0f);
        glVertex2f(60.0f, 110.0f);
    glEnd();

    // Thin branches
    glLineWidth(3.0f);
    glBegin(GL_LINES);
        glVertex2f(-45.0f, 145.0f);
        glVertex2f(-70.0f, 170.0f);

        glVertex2f(45.0f, 150.0f);
        glVertex2f(70.0f, 175.0f);

        glVertex2f(-60.0f, 105.0f);
        glVertex2f(-85.0f, 120.0f);

        glVertex2f(60.0f, 110.0f);
        glVertex2f(85.0f, 125.0f);
    glEnd();

    glLineWidth(1.0f);

    // Dark leaves
    glColor3f(0.06f, 0.35f, 0.12f);
    drawCircle(0.0f, 190.0f, 35.0f);
    drawCircle(-45.0f, 160.0f, 30.0f);
    drawCircle(45.0f, 160.0f, 30.0f);
    drawCircle(-75.0f, 130.0f, 25.0f);
    drawCircle(75.0f, 135.0f, 25.0f);
    drawCircle(-30.0f, 215.0f, 28.0f);
    drawCircle(30.0f, 215.0f, 28.0f);

    // Mid leaves
    glColor3f(0.10f, 0.52f, 0.14f);
    drawCircle(0.0f, 185.0f, 28.0f);
    drawCircle(-42.0f, 158.0f, 22.0f);
    drawCircle(42.0f, 160.0f, 22.0f);
    drawCircle(-65.0f, 132.0f, 18.0f);
    drawCircle(65.0f, 135.0f, 18.0f);
    drawCircle(-25.0f, 210.0f, 20.0f);
    drawCircle(25.0f, 210.0f, 20.0f);

    // Light leaves
    glColor3f(0.25f, 0.70f, 0.18f);
    drawCircle(-20.0f, 220.0f, 12.0f);
    drawCircle(18.0f, 222.0f, 12.0f);
    drawCircle(-55.0f, 150.0f, 10.0f);
    drawCircle(55.0f, 155.0f, 10.0f);
    drawCircle(0.0f, 195.0f, 13.0f);

    glPopMatrix();
}

void drawLamp(float x, float y, float angle)
{
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glRotatef(angle, 0.0f, 0.0f, 1.0f);

    glColor3f(0.14f, 0.18f, 0.23f);
    drawRectangle(-4.0f, 0.0f, 4.0f, 125.0f);
    drawRectangle(-18.0f, 0.0f, 18.0f, 7.0f);
    drawRectangle(-4.0f, 120.0f, 28.0f, 126.0f);

    glColor3f(1.0f, 0.82f, 0.30f);
    drawCircle(29.0f, 122.0f, 11.0f);

    glPopMatrix();
}

#endif
