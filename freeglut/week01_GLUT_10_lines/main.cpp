#include <GL/glut.h>//�}GLUT�~��

void display()
{
    glutSolidTeapot(0.3);
    glutSwapBuffers();
}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("2024�q���Ͼǲ�01�g");
    glutDisplayFunc(display);

    glutMainLoop();
}
