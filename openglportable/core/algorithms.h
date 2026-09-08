// core/algorithms.h

#ifndef ALGORITHMS_H
#define ALGORITHMS_H

// DDA Line Algorithm
void drawDDALine(int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps;

    if(abs(dx) > abs(dy))
    {
        steps = abs(dx);
    }
    else
    {
        steps = abs(dy);
    }

    float xInc = dx / (float)steps;
    float yInc = dy / (float)steps;

    float x = x1;
    float y = y1;

    glBegin(GL_POINTS);
        glVertex2i((int)(x + 0.5f), (int)(y + 0.5f));

        for(int i = 0; i < steps; i++)
        {
            x = x + xInc;
            y = y + yInc;
            glVertex2i((int)(x + 0.5f), (int)(y + 0.5f));
        }
    glEnd();
}

void drawEightCirclePoints(int cx, int cy, int x, int y)
{
    glVertex2i(cx + x, cy + y);
    glVertex2i(cx - x, cy + y);
    glVertex2i(cx + x, cy - y);
    glVertex2i(cx - x, cy - y);
    glVertex2i(cx + y, cy + x);
    glVertex2i(cx - y, cy + x);
    glVertex2i(cx + y, cy - x);
    glVertex2i(cx - y, cy - x);
}

// Midpoint Circle Algorithm
void drawMidpointCircle(int cx, int cy, int radius)
{
    int x = 0;
    int y = radius;
    int d = 1 - radius;

    glBegin(GL_POINTS);
        drawEightCirclePoints(cx, cy, x, y);

        while(x < y)
        {
            if(d < 0)
            {
                d = d + 2 * x + 3;
            }
            else
            {
                d = d + 2 * (x - y) + 5;
                y = y - 1;
            }

            x = x + 1;
            drawEightCirclePoints(cx, cy, x, y);
        }
    glEnd();
}

#endif
