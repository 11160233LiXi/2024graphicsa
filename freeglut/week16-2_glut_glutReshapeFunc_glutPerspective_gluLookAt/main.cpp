#include <GL/glut.h>//¶}GLUT¥~±¾

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutSolidTeapot(0.3);
    glutSwapBuffers();
}

void reshape(int w,int h) {
    glViewport(0,0,w,h);///設定視窗會看到的區域
    float ar = w/(float) h;///長寬比、寬長比
    glMatrixMode(GL_PROJECTION);///切換投影矩陣
    glLoadIdentity();
    gluPerspective(60,ar,0.01,100);///透視投影

    glMatrixMode(GL_MODELVIEW);///切換model view矩陣
    glLoadIdentity();
    gluLookAt(0,2,-2, 0,0,0, 0,1,0);
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(300,600); ///加這行可改視窗長寬
    glutCreateWindow("week16-2");
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);

    glutMainLoop();
}
