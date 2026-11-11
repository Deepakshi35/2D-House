#include <GL/freeglut.h>
#include <cmath>

// Rectangle
void rectangle(float x1, float y1, float x2, float y2,
               float r, float g, float b)
{
    glColor3f(r, g, b);
    glBegin(GL_QUADS);
    glVertex2f(x1, y1);
    glVertex2f(x2, y1);
    glVertex2f(x2, y2);
    glVertex2f(x1, y2);
    glEnd();
}

// Triangle
void triangle(float x1, float y1, float x2, float y2,
              float x3, float y3,
              float r, float g, float b)
{
    glColor3f(r, g, b);
    glBegin(GL_TRIANGLES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glEnd();
}

// Circle
void circle(float x, float y, float radius,
            float r, float g, float b)
{
    glColor3f(r, g, b);
    glBegin(GL_TRIANGLE_FAN);

    glVertex2f(x, y);

    for (int i = 0; i <= 100; i++)
    {
        float angle = 2 * 3.14159f * i / 100;
        glVertex2f(x + radius * cos(angle),
                   y + radius * sin(angle));
    }

    glEnd();
}

// Display function
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Green ground
    rectangle(-1, -1, 1, -0.4,
              0.2, 0.6, 0.2);

    // Sun
    circle(0.75, 0.75, 0.13,
           1.0, 0.85, 0.0);

    // House walls
    rectangle(-0.5, -0.6, 0.5, 0.25,
              1.0, 0.85, 0.55);

    // Roof
    triangle(-0.6, 0.25,
              0.6, 0.25,
              0.0, 0.75,
              0.8, 0.1, 0.1);

    // Left window
    rectangle(-0.38, -0.05, -0.1, 0.15,
              0.1, 0.6, 0.9);

    // Right window
    rectangle(0.1, -0.05, 0.38, 0.15,
              0.1, 0.6, 0.9);

    // Window divisions
    rectangle(-0.25, -0.05, -0.23, 0.15,
              1, 1, 1);

    rectangle(0.23, -0.05, 0.25, 0.15,
              1, 1, 1);

    // Door
    rectangle(-0.12, -0.6, 0.12, -0.2,
              0.45, 0.2, 0.05);

    // Door knob
    circle(0.07, -0.4, 0.025,
           1, 0.85, 0);

    // Pathway
    triangle(-0.15, -0.6,
              0.15, -0.6,
              0.3, -1,
              0.55, 0.5, 0.35);

    // Small garden
    circle(-0.75, -0.3, 0.12,
           0.1, 0.65, 0.1);

    circle(0.75, -0.3, 0.12,
           0.1, 0.65, 0.1);

    glFlush();
}

// Main function
int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(900, 650);
    glutInitWindowPosition(100, 100);

    glutCreateWindow("2D House Drawing with Colour Filling");

    glClearColor(0.5, 0.75, 0.95, 1);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluOrtho2D(-1, 1, -1, 1);

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}