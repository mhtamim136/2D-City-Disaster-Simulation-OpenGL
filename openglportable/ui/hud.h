// ui/hud.h
// Scene panel and controls panel

#ifndef HUD_H
#define HUD_H

void drawHUD()
{
    // Scene panel
    glColor4f(0.05f, 0.10f, 0.18f, 0.62f);
    drawRectangle(18.0f, 574.0f, 390.0f, 636.0f);

    glColor3f(0.18f, 0.72f, 0.72f);
    drawRectangle(18.0f, 628.0f, 390.0f, 636.0f);

    glColor3f(1.0f, 1.0f, 1.0f);
    drawText(32.0f, 612.0f, GLUT_BITMAP_HELVETICA_18,
             "2D CITY DISASTER SIMULATION");

    // Scene name and status
    if(scene == 0 && nightMode == 1)
    {
        glColor3f(1.0f, 0.78f, 0.22f);
        drawText(32.0f, 590.0f, GLUT_BITMAP_HELVETICA_12, "NIGHT CITY");

        glColor3f(0.88f, 0.92f, 0.96f);
        drawText(165.0f, 590.0f, GLUT_BITMAP_HELVETICA_12,
                 "Status: Night time, city lights are on");
    }
    else if(scene == 0 && eveningMode == 1)
    {
        glColor3f(1.0f, 0.78f, 0.22f);
        drawText(32.0f, 590.0f, GLUT_BITMAP_HELVETICA_12, "EVENING CITY");

        glColor3f(0.88f, 0.92f, 0.96f);
        drawText(165.0f, 590.0f, GLUT_BITMAP_HELVETICA_12,
                 "Status: Sun is setting, the day is ending");
    }
    else if(scene == 0)
    {
        glColor3f(1.0f, 0.78f, 0.22f);
        drawText(32.0f, 590.0f, GLUT_BITMAP_HELVETICA_12, "NORMAL CITY");

        glColor3f(0.88f, 0.92f, 0.96f);
        drawText(165.0f, 590.0f, GLUT_BITMAP_HELVETICA_12,
                 "Status: City operations are normal");
    }
    else if(scene == 1)
    {
        glColor3f(1.0f, 0.78f, 0.22f);
        drawText(32.0f, 590.0f, GLUT_BITMAP_HELVETICA_12, "EARTHQUAKE ALERT");

        glColor3f(0.88f, 0.92f, 0.96f);
        drawText(165.0f, 590.0f, GLUT_BITMAP_HELVETICA_12,
                 "Status: Move towards an open safe area");
    }
    else if(scene == 2)
    {
        glColor3f(1.0f, 0.78f, 0.22f);
        drawText(32.0f, 590.0f, GLUT_BITMAP_HELVETICA_12, "FIRE RESCUE");

        glColor3f(0.88f, 0.92f, 0.96f);
        drawText(165.0f, 590.0f, GLUT_BITMAP_HELVETICA_12,
                 "Status: Firefighters are controlling the fire");
    }
    else if(scene == 3)
    {
        glColor3f(1.0f, 0.78f, 0.22f);
        drawText(32.0f, 590.0f, GLUT_BITMAP_HELVETICA_12, "FLOOD RESCUE");

        glColor3f(0.88f, 0.92f, 0.96f);
        drawText(165.0f, 590.0f, GLUT_BITMAP_HELVETICA_12,
                 "Status: Rescue boat is helping trapped people");
    }
    else if(scene == 4)
    {
        glColor3f(1.0f, 0.78f, 0.22f);
        drawText(32.0f, 590.0f, GLUT_BITMAP_HELVETICA_12, "SEVERE STORM");

        glColor3f(0.88f, 0.92f, 0.96f);
        drawText(165.0f, 590.0f, GLUT_BITMAP_HELVETICA_12,
                 "Status: Stay indoors during the severe storm");
    }
    else
    {
        glColor3f(1.0f, 0.78f, 0.22f);
        drawText(32.0f, 590.0f, GLUT_BITMAP_HELVETICA_12, "ROAD ACCIDENT");

        glColor3f(0.88f, 0.92f, 0.96f);
        drawText(165.0f, 590.0f, GLUT_BITMAP_HELVETICA_12,
                 "Status: Police and ambulance are on the spot");
    }

    // Blinking alert
    if(scene > 0 && frameCount % 28 < 14)
    {
        glColor3f(0.92f, 0.12f, 0.14f);
        drawCircle(372.0f, 610.0f, 8.0f);
    }

    // Controls panel
    glColor3f(0.05f, 0.10f, 0.18f);
    drawRectangle(18.0f, 14.0f, 982.0f, 58.0f);

    glColor3f(0.18f, 0.72f, 0.72f);
    drawRectangle(18.0f, 52.0f, 982.0f, 58.0f);

    glColor3f(1.0f, 1.0f, 1.0f);
    drawText(34.0f, 37.0f, GLUT_BITMAP_HELVETICA_12,
             "A/D: Scene   P: Pause   R: Reset   N: Night   E: Evening   +/-: Zoom   X: Exit");

    glColor3f(1.0f, 0.78f, 0.22f);
    drawText(585.0f, 37.0f, GLUT_BITMAP_HELVETICA_12,
             "FIRE controls -> W: Water   J/L: Aim L-R   I/K: Aim U-D");

    if(paused == 1)
    {
        glColor3f(1.0f, 0.35f, 0.20f);
        drawText(452.0f, 610.0f, GLUT_BITMAP_HELVETICA_18,
                 "PAUSED");
    }
}

#endif
