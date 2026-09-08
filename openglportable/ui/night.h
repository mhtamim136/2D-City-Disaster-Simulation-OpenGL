// ui/night.h
// Night mode for the normal city scene

#ifndef NIGHT_H
#define NIGHT_H

void drawNightSky()
{
    glColor3f(0.03f, 0.05f, 0.18f);
    drawRectangle(0.0f, 0.0f, 1000.0f, 650.0f);

    // Stars
    glColor3f(1.0f, 1.0f, 0.90f);
    glPointSize(2.0f);
    glBegin(GL_POINTS);
    for(int i = 0; i < 80; i++)
    {
        int x = (i * 137) % 995;
        int y = 300 + (i * 71) % 340;
        glVertex2i(x, y);
    }
    glEnd();
    glPointSize(1.0f);
}

void drawMoon(float cx, float cy, float radius)
{
    // Glow
    glColor4f(0.86f, 0.90f, 1.0f, 0.05f);
    drawCircle(cx, cy, radius * 1.90f);
    glColor4f(0.88f, 0.92f, 1.0f, 0.07f);
    drawCircle(cx, cy, radius * 1.70f);
    glColor4f(0.90f, 0.93f, 1.0f, 0.10f);
    drawCircle(cx, cy, radius * 1.45f);
    glColor4f(0.93f, 0.95f, 1.0f, 0.16f);
    drawCircle(cx, cy, radius * 1.22f);

    // Surface
    glColor3f(0.78f, 0.79f, 0.72f);
    drawCircle(cx, cy, radius);
    glColor3f(0.89f, 0.89f, 0.82f);
    drawCircle(cx, cy, radius * 0.94f);
    glColor3f(0.98f, 0.98f, 0.92f);
    drawCircle(cx, cy, radius * 0.86f);

    // Dark patches
    glColor4f(0.68f, 0.69f, 0.65f, 0.50f);
    drawCircle(cx - radius * 0.28f, cy + radius * 0.30f, radius * 0.26f);
    drawCircle(cx + radius * 0.24f, cy + radius * 0.26f, radius * 0.17f);
    drawCircle(cx + radius * 0.32f, cy - radius * 0.14f, radius * 0.21f);
    drawCircle(cx - radius * 0.16f, cy - radius * 0.36f, radius * 0.19f);

    // Craters
    glColor4f(0.76f, 0.77f, 0.72f, 0.62f);
    drawCircle(cx - radius * 0.50f, cy - radius * 0.16f, radius * 0.12f);
    drawCircle(cx + radius * 0.08f, cy - radius * 0.60f, radius * 0.09f);
    drawCircle(cx + radius * 0.52f, cy + radius * 0.44f, radius * 0.08f);
}

void drawNightLights()
{
    // Dark tint
    glColor4f(0.02f, 0.03f, 0.14f, 0.45f);
    drawRectangle(0.0f, 0.0f, 1000.0f, 650.0f);

    drawMoon(880.0f, 588.0f, 28.0f);

    // Street lamp glow
    glColor4f(1.0f, 0.85f, 0.35f, 0.30f);
    drawCircle(64.0f, 297.0f, 26.0f);
    drawCircle(984.0f, 297.0f, 26.0f);
}

#endif
