// core/shapes.h

#ifndef SHAPES_H
#define SHAPES_H

void drawRectangle(float x1, float y1, float x2, float y2)
{
    glBegin(GL_POLYGON);
        glVertex2f(x1, y1);
        glVertex2f(x2, y1);
        glVertex2f(x2, y2);
        glVertex2f(x1, y2);
    glEnd();
}

void drawCircle(float cx, float cy, float radius)
{
    glBegin(GL_POLYGON);
    for(int i = 0; i < 50; i++)
    {
        float angle = 2.0f * PI * i / 50.0f;
        glVertex2f(cx + radius * cos(angle),
                   cy + radius * sin(angle));
    }
    glEnd();
}

void drawText(float x, float y, void *font, const char *text)
{
    glRasterPos2f(x, y);

    for(int i = 0; text[i] != '\0'; i++)
    {
        glutBitmapCharacter(font, text[i]);
    }
}

#endif
