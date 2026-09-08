// city/people.h
// Limbs and human figures

#ifndef PEOPLE_H
#define PEOPLE_H

void drawLimb(float jointX, float jointY, float length,
              float angle, float width, int drawFoot)
{
    glPushMatrix();
    glTranslatef(jointX, jointY, 0.0f);
    glRotatef(angle, 0.0f, 0.0f, 1.0f);

    glLineWidth(width);
    glBegin(GL_LINES);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(0.0f, -length);
    glEnd();

    if(drawFoot == 1)
    {
        glColor3f(0.03f, 0.04f, 0.06f);
        glLineWidth(width + 1.0f);
        glBegin(GL_LINES);
            glVertex2f(0.0f, -length);
            glVertex2f(9.0f, -length);
        glEnd();
    }

    glPopMatrix();
    glLineWidth(1.0f);
}

void drawPerson(float x, float y, float scale,
                float red, float green, float blue,
                float armAngle, float legAngle, int helmet)
{
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glScalef(scale, scale, 1.0f);

    // Legs
    glColor3f(0.10f, 0.17f, 0.30f);
    drawLimb(-7.0f, 42.0f, 38.0f, legAngle, 7.0f, 1);

    glColor3f(0.10f, 0.17f, 0.30f);
    drawLimb(7.0f, 42.0f, 38.0f, -legAngle, 7.0f, 1);

    // Arms
    glColor3f(0.91f, 0.64f, 0.43f);
    drawLimb(-14.0f, 76.0f, 34.0f, armAngle, 6.0f, 0);

    glColor3f(0.91f, 0.64f, 0.43f);
    drawLimb(14.0f, 76.0f, 34.0f, -armAngle, 6.0f, 0);

    // Shirt
    glColor3f(red, green, blue);
    drawRectangle(-16.0f, 40.0f, 16.0f, 82.0f);

    // Belt
    glColor3f(0.08f, 0.10f, 0.14f);
    drawRectangle(-16.0f, 39.0f, 16.0f, 45.0f);

    // Neck and head
    glColor3f(0.91f, 0.64f, 0.43f);
    drawRectangle(-5.0f, 82.0f, 5.0f, 91.0f);
    drawCircle(0.0f, 104.0f, 14.0f);

    if(helmet == 1)
    {
        glColor3f(1.0f, 0.78f, 0.12f);
        drawCircle(0.0f, 110.0f, 14.0f);
        drawRectangle(-17.0f, 106.0f, 17.0f, 112.0f);

        glColor3f(1.0f, 0.90f, 0.34f);
        drawRectangle(-16.0f, 57.0f, 16.0f, 63.0f);
    }
    else
    {
        glColor3f(0.10f, 0.07f, 0.05f);
        drawRectangle(-12.0f, 109.0f, 12.0f, 119.0f);
    }

    glPopMatrix();
}

void drawUmbrellaPerson(float x, float y, float scale)
{
    drawPerson(x, y, scale, 0.35f, 0.25f, 0.55f,
               -15.0f, 5.0f, 0);

    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glScalef(scale, scale, 1.0f);

    glColor3f(0.95f, 0.55f, 0.18f);
    glBegin(GL_POLYGON);
        glVertex2f(0.0f, 126.0f);
        for(int i = 0; i <= 20; i++)
        {
            float angle = PI * i / 20.0f;
            glVertex2f(40.0f * cos(angle),
                       126.0f + 40.0f * sin(angle));
        }
    glEnd();

    glColor3f(0.12f, 0.14f, 0.18f);
    glLineWidth(3.0f);
    glBegin(GL_LINES);
        glVertex2f(0.0f, 126.0f);
        glVertex2f(0.0f, 65.0f);
    glEnd();

    glLineWidth(1.0f);
    glPopMatrix();
}

void drawHelpPerson(float x, float y, float scale,
                    float red, float green, float blue)
{
    float wave = sin(frameCount * 0.30f) * 18.0f;

    drawPerson(x, y, scale, red, green, blue,
               155.0f + wave, 0.0f, 0);
}

#endif
