// ui/ending.h
// End screen shown after the last scene

#ifndef ENDING_H
#define ENDING_H

void drawEnd()
{
    // Background
    glBegin(GL_POLYGON);
        glColor3f(0.06f, 0.20f, 0.26f);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(1000.0f, 0.0f);

        glColor3f(0.10f, 0.06f, 0.22f);
        glVertex2f(1000.0f, 650.0f);
        glVertex2f(0.0f, 650.0f);
    glEnd();

    // Title
    glColor3f(1.0f, 1.0f, 1.0f);
    drawText(380.0f, 602.0f, GLUT_BITMAP_TIMES_ROMAN_24, "PROJECT COMPLETE");

    glColor3f(0.18f, 0.72f, 0.72f);
    drawRectangle(150.0f, 584.0f, 850.0f, 590.0f);

    glColor3f(0.78f, 0.86f, 0.92f);
    drawText(392.0f, 556.0f, GLUT_BITMAP_HELVETICA_12,
             "All six city scenes have been shown");

    // Team
    glColor3f(1.0f, 0.78f, 0.22f);
    drawText(434.0f, 512.0f, GLUT_BITMAP_HELVETICA_18, "PRESENTED BY");

    glColor3f(0.92f, 0.95f, 0.98f);
    drawText(330.0f, 480.0f, GLUT_BITMAP_HELVETICA_18,
             "1.   FAHMIDA ISLAM BAYAN");
    drawText(330.0f, 454.0f, GLUT_BITMAP_HELVETICA_18,
             "2.   MD. MURAD HASAN");
    drawText(330.0f, 428.0f, GLUT_BITMAP_HELVETICA_18,
             "3.   MD. RABBY SARKER RONY");
    drawText(330.0f, 402.0f, GLUT_BITMAP_HELVETICA_18,
             "4.   NOSHIN SUNZIDA ALAM");
    drawText(330.0f, 376.0f, GLUT_BITMAP_HELVETICA_18,
             "5.   MD. SADMAN AMIN BHUIYAN SUNY");

    glColor3f(1.0f, 0.78f, 0.22f);
    drawText(430.0f, 334.0f, GLUT_BITMAP_TIMES_ROMAN_24, "THANK YOU");

    glColor3f(0.18f, 0.72f, 0.72f);
    drawRectangle(150.0f, 300.0f, 850.0f, 306.0f);

    // Keys
    glColor3f(0.88f, 0.92f, 0.96f);
    drawText(392.0f, 272.0f, GLUT_BITMAP_HELVETICA_12,
             "A         Back to the accident scene");
    drawText(392.0f, 252.0f, GLUT_BITMAP_HELVETICA_12,
             "R         Start again from the first scene");
    drawText(392.0f, 232.0f, GLUT_BITMAP_HELVETICA_12,
             "X         Exit the program");

    // Base
    glColor3f(0.05f, 0.09f, 0.15f);
    drawRectangle(0.0f, 0.0f, 1000.0f, 58.0f);
}

#endif
