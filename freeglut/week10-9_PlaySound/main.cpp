#include <GL/glut.h>
#include <mmsystem.h>
void myBody()
{
	glPushMatrix();
        glColor3f(1,0,0);
        glutWireCube(0.6);///mybody
    glPopMatrix();
}
void myArm()
{
    glPushMatrix();
        glColor3f(0,1,0);
        glScalef(1,0.4,0.4);
        glutWireCube(0.3);///myArm
    glPopMatrix();
}
float angle = 0;
void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	myBody();
	glPushMatrix();///右半邊
        glTranslatef(0.3,0.3,0);///(3) 掛到肩上
        glRotatef(angle,0,0,1);///(2) 旋轉
        glTranslatef(0.15,0,0);///(1) 把旋轉中心，放在畫面的正中心
        myArm();
        glPushMatrix();
            glTranslatef(0.15,0,0);///(3) 掛到肩上
            glRotatef(angle,0,0,1);///(2) 旋轉
            glTranslatef(0.15,0,0);///(1) 把旋轉中心，放在畫面的正中心
            myArm();
        glPopMatrix();
    glPopMatrix();

    glPushMatrix();///左半邊
        glTranslatef(-0.3,0.3,0);///(3) 掛到肩上
        glRotatef(-angle,0,0,1);///(2) 旋轉
        glTranslatef(-0.15,0,0);///(1) 把旋轉中心，放在畫面的正中心
        myArm();
        glPushMatrix();
            glTranslatef(-0.15,0,0);///(3) 掛到肩上
            glRotatef(-angle,0,0,1);///(2) 旋轉
            glTranslatef(-0.15,0,0);///(1) 把旋轉中心，放在畫面的正中心
            myArm();
        glPopMatrix();
    glPopMatrix();

	glutSwapBuffers();
}
void motion(int x,int y) {
    angle = x; ///加上mouse motion
    glutPostRedisplay();///告訴GLUT有空就重劃畫面
}
int main(int argc, char*argv[])
{
    PlaySound("c:/horse.mav",NULL,SND_ASYNC);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("week10");

	glutDisplayFunc(display);
	glutMotionFunc(motion);///有空就旋轉
	glutIdleFunc(display);
	glutMainLoop();
}
