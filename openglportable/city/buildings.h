// city/buildings.h
// Windows, doors, hospital, tower and apartment

#ifndef BUILDINGS_H
#define BUILDINGS_H

void drawWindow(float x, float y, float width, float height, int lightOn)
{
    if(nightMode == 1)
    {
        glColor3f(1.0f, 0.92f, 0.45f);
    }
    else if(eveningMode == 1)
    {
        glColor3f(1.0f, 0.72f, 0.28f);
    }
    else if(lightOn == 1)
    {
        glColor3f(1.0f, 0.80f, 0.30f);
    }
    else
    {
        glColor3f(0.55f, 0.82f, 0.90f);
    }

    drawRectangle(x, y, x + width, y + height);

    // Frame
    glColor3f(0.12f, 0.24f, 0.32f);
    glLineWidth(1.5f);
    glBegin(GL_LINE_LOOP);
        glVertex2f(x, y);
        glVertex2f(x + width, y);
        glVertex2f(x + width, y + height);
        glVertex2f(x, y + height);
    glEnd();

    glBegin(GL_LINES);
        glVertex2f(x + width / 2.0f, y);
        glVertex2f(x + width / 2.0f, y + height);
    glEnd();

    glLineWidth(1.0f);
}

// open = 0 to 1
void drawOpenWindow(float x, float y, float width, float height, float open)
{
    glColor3f(0.10f, 0.13f, 0.18f);
    drawRectangle(x, y, x + width, y + height);

    float half = width / 2.0f;
    float shift = half * 0.80f * open;

    // Glass
    glColor3f(0.55f, 0.82f, 0.90f);
    drawRectangle(x - shift, y, x + half - shift, y + height);
    drawRectangle(x + half + shift, y, x + width + shift, y + height);

    // Frame
    glColor3f(0.12f, 0.24f, 0.32f);
    glLineWidth(1.5f);
    glBegin(GL_LINE_LOOP);
        glVertex2f(x, y);
        glVertex2f(x + width, y);
        glVertex2f(x + width, y + height);
        glVertex2f(x, y + height);
    glEnd();
    glLineWidth(1.0f);
}

// open = 0 to 1
void drawEntranceDoor(float cx, float baseY, float halfWidth, float height,
                      float open)
{
    float shift = halfWidth * 0.85f * open;

    drawRectangle(cx - halfWidth - shift, baseY,
                  cx - 2.0f - shift, baseY + height);

    drawRectangle(cx + 2.0f + shift, baseY,
                  cx + halfWidth + shift, baseY + height);
}

void drawHospital(float angle)
{
    glPushMatrix();
    glTranslatef(185.0f, 205.0f, 0.0f);
    glRotatef(angle, 0.0f, 0.0f, 1.0f);

    // Main body
    glColor3f(0.18f, 0.55f, 0.54f);
    drawRectangle(-105.0f, 0.0f, 105.0f, 280.0f);

    // Side shade
    glColor3f(0.12f, 0.40f, 0.43f);
    drawRectangle(80.0f, 0.0f, 105.0f, 280.0f);

    // Roof
    glColor3f(0.08f, 0.24f, 0.31f);
    drawRectangle(-115.0f, 280.0f, 115.0f, 292.0f);

    // Window grid
    for(int row = 0; row < 3; row++)
    {
        for(int column = 0; column < 3; column++)
        {
            float x = -78.0f + column * 57.0f;
            float y = 72.0f + row * 58.0f;
            drawWindow(x, y, 34.0f, 34.0f, (row + column) % 2);
        }
    }

    // Entrance
    glColor3f(0.09f, 0.24f, 0.30f);
    drawRectangle(-28.0f, 0.0f, 28.0f, 58.0f);

    float open = 0.0f;

    if(scene == 1)
    {
        open = doorOpen;
    }

    // Hall
    glColor3f(0.06f, 0.08f, 0.11f);
    drawRectangle(-22.0f, 5.0f, 22.0f, 53.0f);

    // Door
    glColor3f(0.62f, 0.88f, 0.91f);
    drawEntranceDoor(0.0f, 5.0f, 22.0f, 48.0f, open);

    // Hospital sign
    glColor3f(0.96f, 0.96f, 0.92f);
    drawRectangle(-38.0f, 238.0f, 38.0f, 272.0f);

    glColor3f(0.88f, 0.12f, 0.16f);
    drawRectangle(-5.0f, 243.0f, 5.0f, 267.0f);
    drawRectangle(-15.0f, 250.0f, 15.0f, 260.0f);

    glPopMatrix();
}

void drawTower(float angle)
{
    glPushMatrix();
    glTranslatef(500.0f, 205.0f, 0.0f);
    glRotatef(angle, 0.0f, 0.0f, 1.0f);

    // Main body
    glColor3f(0.31f, 0.36f, 0.62f);
    drawRectangle(-85.0f, 0.0f, 85.0f, 350.0f);

    // Center stripe
    glColor3f(0.22f, 0.25f, 0.48f);
    drawRectangle(-12.0f, 0.0f, 12.0f, 350.0f);

    // Roof and antenna
    glColor3f(0.10f, 0.15f, 0.30f);
    drawRectangle(-95.0f, 350.0f, 95.0f, 362.0f);
    drawRectangle(-4.0f, 362.0f, 4.0f, 400.0f);

    // Windows
    for(int row = 0; row < 4; row++)
    {
        for(int column = 0; column < 2; column++)
        {
            float x = -62.0f + column * 84.0f;
            float y = 75.0f + row * 64.0f;
            drawWindow(x, y, 40.0f, 35.0f, (row + column + 1) % 2);
        }
    }

    // Entrance
    glColor3f(0.10f, 0.15f, 0.30f);
    drawRectangle(-30.0f, 0.0f, 30.0f, 60.0f);

    float open = 0.0f;

    if(scene == 1)
    {
        open = doorOpen;
    }

    // Hall
    glColor3f(0.06f, 0.08f, 0.11f);
    drawRectangle(-24.0f, 6.0f, 24.0f, 54.0f);

    // Door
    glColor3f(0.73f, 0.88f, 0.95f);
    drawEntranceDoor(0.0f, 6.0f, 24.0f, 48.0f, open);

    glPopMatrix();
}

void drawApartment(float angle)
{
    glPushMatrix();
    glTranslatef(810.0f, 205.0f, 0.0f);
    glRotatef(angle, 0.0f, 0.0f, 1.0f);

    // Main body
    glColor3f(0.78f, 0.38f, 0.31f);
    drawRectangle(-120.0f, 0.0f, 120.0f, 305.0f);

    // Side shade
    glColor3f(0.58f, 0.24f, 0.25f);
    drawRectangle(92.0f, 0.0f, 120.0f, 305.0f);

    // Roof
    glColor3f(0.24f, 0.18f, 0.24f);
    glBegin(GL_TRIANGLES);
        glVertex2f(-135.0f, 305.0f);
        glVertex2f(135.0f, 305.0f);
        glVertex2f(0.0f, 350.0f);
    glEnd();

    // Balconies and windows
    for(int row = 0; row < 3; row++)
    {
        float y = 76.0f + row * 72.0f;

        drawWindow(-82.0f, y, 42.0f, 38.0f, row % 2);
        drawWindow(38.0f, y, 42.0f, 38.0f, (row + 1) % 2);

        glColor3f(0.34f, 0.19f, 0.24f);
        drawRectangle(-98.0f, y - 14.0f, -25.0f, y - 7.0f);
        drawRectangle(25.0f, y - 14.0f, 98.0f, y - 7.0f);
    }

    // Entrance
    glColor3f(0.28f, 0.16f, 0.18f);
    drawRectangle(-28.0f, 0.0f, 28.0f, 62.0f);

    float open = 0.0f;

    if(scene == 1 || scene == 2)
    {
        open = doorOpen;
    }

    // Hall
    glColor3f(0.06f, 0.08f, 0.11f);
    drawRectangle(-24.0f, 4.0f, 24.0f, 58.0f);

    // Door
    glColor3f(0.28f, 0.16f, 0.18f);
    drawEntranceDoor(0.0f, 4.0f, 24.0f, 54.0f, open);

    // Door handle
    float handleShift = 24.0f * 0.85f * open;

    glColor3f(0.95f, 0.72f, 0.24f);
    drawCircle(17.0f + handleShift, 31.0f, 3.0f);

    glPopMatrix();
}

#endif
