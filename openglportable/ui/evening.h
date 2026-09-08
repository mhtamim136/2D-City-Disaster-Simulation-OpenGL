// ui/evening.h
// Evening mode for the normal city scene

#ifndef EVENING_H
#define EVENING_H

void drawEveningSky()
{
    // Lower sky
    glBegin(GL_POLYGON);
        glColor3f(1.0f, 0.76f, 0.38f);
        glVertex2f(0.0f, 170.0f);
        glVertex2f(1000.0f, 170.0f);

        glColor3f(0.95f, 0.44f, 0.22f);
        glVertex2f(1000.0f, 400.0f);
        glVertex2f(0.0f, 400.0f);
    glEnd();

    // Upper sky
    glBegin(GL_POLYGON);
        glColor3f(0.95f, 0.44f, 0.22f);
        glVertex2f(0.0f, 400.0f);
        glVertex2f(1000.0f, 400.0f);

        glColor3f(0.28f, 0.16f, 0.40f);
        glVertex2f(1000.0f, 650.0f);
        glVertex2f(0.0f, 650.0f);
    glEnd();

    // Cloud streaks
    glColor4f(0.62f, 0.24f, 0.30f, 0.45f);
    drawRectangle(120.0f, 466.0f, 430.0f, 476.0f);
    drawRectangle(560.0f, 508.0f, 900.0f, 518.0f);
    drawRectangle(240.0f, 552.0f, 620.0f, 560.0f);
}

void drawSettingSun(float cx, float cy, float radius)
{
    // Glow
    glColor4f(1.0f, 0.55f, 0.15f, 0.08f);
    drawCircle(cx, cy, radius * 2.10f);
    glColor4f(1.0f, 0.60f, 0.18f, 0.12f);
    drawCircle(cx, cy, radius * 1.75f);
    glColor4f(1.0f, 0.66f, 0.22f, 0.18f);
    drawCircle(cx, cy, radius * 1.45f);
    glColor4f(1.0f, 0.72f, 0.28f, 0.26f);
    drawCircle(cx, cy, radius * 1.20f);

    // Surface
    glColor3f(1.0f, 0.50f, 0.14f);
    drawCircle(cx, cy, radius);
    glColor3f(1.0f, 0.68f, 0.24f);
    drawCircle(cx, cy, radius * 0.82f);
    glColor3f(1.0f, 0.88f, 0.44f);
    drawCircle(cx, cy, radius * 0.55f);
}

void drawLongShadow(float left, float right)
{
    glBegin(GL_POLYGON);
        glVertex2f(left, 205.0f);
        glVertex2f(right, 205.0f);
        glVertex2f(right + 105.0f, 174.0f);
        glVertex2f(left + 105.0f, 174.0f);
    glEnd();
}

void drawEveningLights()
{
    // Warm tint
    glColor4f(0.95f, 0.42f, 0.12f, 0.20f);
    drawRectangle(0.0f, 0.0f, 1000.0f, 650.0f);

    // Long shadows
    glColor4f(0.20f, 0.08f, 0.16f, 0.38f);
    drawLongShadow(80.0f, 290.0f);
    drawLongShadow(415.0f, 585.0f);
    drawLongShadow(690.0f, 930.0f);

    // Street lamp glow
    glColor4f(1.0f, 0.82f, 0.32f, 0.24f);
    drawCircle(64.0f, 297.0f, 22.0f);
    drawCircle(984.0f, 297.0f, 22.0f);
}

#endif
