#include <GL/glut.h>
#include <stdio.h>
float angle = 0,oldX = 0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);///清背景
    glPushMatrix();
        glRotatef(angle++,0,0,1);///旋轉中的
        glTranslatef(0.8,0,0);///放到右邊去
        glScalef(0.3,0.3,0.3);///小小的
        glutSolidTeapot(0.3);///茶壺
    glPopMatrix();
    glutSwapBuffers();
}

int main(int argc,char*argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week04 mouse mouse motion");
    glutDisplayFunc(display);
    glutIdleFunc(display);///有空就重畫畫面
    glutMainLoop();
}
