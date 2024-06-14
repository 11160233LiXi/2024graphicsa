///先把 week08-1_glm_gundam 的程式貼上來
///等一下, 要再加貼圖的 18行程式
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <GL/glut.h>
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
#include <GL/glut.h>
#include "glm.h"
float teapotX=0, teapotY=0;
GLMmodel * pmodel = NULL;
GLMmodel * body= NULL;
GLMmodel * head= NULL;
GLMmodel * larm= NULL;
GLMmodel * rarm= NULL;
GLMmodel * lcalf = NULL;
GLMmodel * rcalf= NULL;
GLMmodel * lelbow= NULL;
GLMmodel * relbow= NULL;
GLMmodel * lfoot= NULL;
GLMmodel * rfoot = NULL;
GLMmodel * lpalm = NULL;
GLMmodel * rpalm= NULL;
GLMmodel * lshoulder= NULL;
GLMmodel * rshoulder= NULL;
GLMmodel * lthigh= NULL;
GLMmodel * rthigh = NULL;
GLMmodel * lwheel= NULL;
GLMmodel * rwheel= NULL;
GLMmodel * lwing= NULL;
GLMmodel * rwing = NULL;

void drawbody(void)///1
{
    if (!body) {
	body = glmReadOBJ("data/body.obj");
	if (!body) exit(0);
	glmUnitize(body);
	glmFacetNormals(body);
	glmVertexNormals(body, 90.0);
    }

    glmDraw(body, GLM_SMOOTH | GLM_MATERIAL);
}
void drawhead(void)///2
{
    if (!head) {
	head = glmReadOBJ("data/head.obj");
	if (!head) exit(0);
	glmUnitize(head);
	glmFacetNormals(head);
	glmVertexNormals(head, 90.0);
    }

    glmDraw(head, GLM_SMOOTH | GLM_MATERIAL);
}
void drawlarm(void)///3
{
    if (!larm) {
	larm = glmReadOBJ("data/larm.obj");
	if (!larm) exit(0);
	glmUnitize(larm);
	glmFacetNormals(larm);
	glmVertexNormals(larm, 90.0);
    }

    glmDraw(larm, GLM_SMOOTH | GLM_MATERIAL);
}
void drawrarm(void)///4
{
    if (!rarm) {
	rarm = glmReadOBJ("data/rarm.obj");
	if (!rarm) exit(0);
	glmUnitize(rarm);
	glmFacetNormals(rarm);
	glmVertexNormals(rarm, 90.0);
    }

    glmDraw(rarm, GLM_SMOOTH | GLM_MATERIAL);
}
void drawlcalf(void)///5
{
    if (!lcalf) {
	lcalf = glmReadOBJ("data/lcalf.obj");
	if (!lcalf) exit(0);
	glmUnitize(lcalf);
	glmFacetNormals(lcalf);
	glmVertexNormals(lcalf, 90.0);
    }

    glmDraw(lcalf, GLM_SMOOTH | GLM_MATERIAL);
}
void drawrcalf(void)///6
{
    if (!rcalf) {
	rcalf = glmReadOBJ("data/rcalf.obj");
	if (!rcalf) exit(0);
	glmUnitize(rcalf);
	glmFacetNormals(rcalf);
	glmVertexNormals(rcalf, 90.0);
    }

    glmDraw(rcalf, GLM_SMOOTH | GLM_MATERIAL);
}
void drawlelbow(void)///7
{
    if (!lelbow) {
	lelbow = glmReadOBJ("data/lelbow.obj");
	if (!lelbow) exit(0);
	glmUnitize(lelbow);
	glmFacetNormals(lelbow);
	glmVertexNormals(lelbow, 90.0);
    }

    glmDraw(lelbow, GLM_SMOOTH | GLM_MATERIAL);
}
void drawrelbow(void)///8
{
    if (!relbow) {
	relbow = glmReadOBJ("data/relbow.obj");
	if (!relbow) exit(0);
	glmUnitize(relbow);
	glmFacetNormals(relbow);
	glmVertexNormals(relbow, 90.0);
    }

    glmDraw(relbow, GLM_SMOOTH | GLM_MATERIAL);
}
void drawlfoot(void)///9
{
    if (!lfoot) {
	lfoot = glmReadOBJ("data/lfoot.obj");
	if (!lfoot) exit(0);
	glmUnitize(lfoot);
	glmFacetNormals(lfoot);
	glmVertexNormals(lfoot, 90.0);
    }

    glmDraw(lfoot, GLM_SMOOTH | GLM_MATERIAL);
}
void drawrfoot(void)///10
{
    if (!rfoot) {
	rfoot = glmReadOBJ("data/rfoot.obj");
	if (!rfoot) exit(0);
	glmUnitize(rfoot);
	glmFacetNormals(rfoot);
	glmVertexNormals(rfoot, 90.0);
    }

    glmDraw(rfoot, GLM_SMOOTH | GLM_MATERIAL);
}
void drawlpalm(void)///11
{
    if (!lpalm) {
	lpalm = glmReadOBJ("data/lpalm.obj");
	if (!lpalm) exit(0);
	///glmScale(lpalm, 1/170.0); //glmUnitize(lpalm); //jsyeh
	glmUnitize(lpalm);
	glmFacetNormals(lpalm);
	glmVertexNormals(lpalm, 90.0);
    }

    glmDraw(lpalm, GLM_SMOOTH | GLM_MATERIAL);
}
void drawrpalm(void)///12
{
    if (!rpalm) {
	rpalm = glmReadOBJ("data/rpalm.obj");
	if (!rpalm) exit(0);
	glmUnitize(rpalm);
	glmFacetNormals(rpalm);
	glmVertexNormals(rpalm, 90.0);
    }

    glmDraw(rpalm, GLM_SMOOTH | GLM_MATERIAL);
}
void drawlshoulder(void)///13
{
    if (!lshoulder) {
	lshoulder = glmReadOBJ("data/lshoulder.obj");
	if (!lshoulder) exit(0);
	glmUnitize(lshoulder);
	glmFacetNormals(lshoulder);
	glmVertexNormals(lshoulder, 90.0);
    }

    glmDraw(lshoulder, GLM_SMOOTH | GLM_MATERIAL);
}
void drawrshoulder(void)///14
{
    if (!rshoulder) {
	rshoulder = glmReadOBJ("data/rshoulder.obj");
	if (!rshoulder) exit(0);
	glmUnitize(rshoulder);
	glmFacetNormals(rshoulder);
	glmVertexNormals(rshoulder, 90.0);
    }

    glmDraw(rshoulder, GLM_SMOOTH | GLM_MATERIAL);
}
void drawlthigh(void)///15
{
    if (!lthigh) {
	lthigh = glmReadOBJ("data/lthigh.obj");
	if (!lthigh) exit(0);
	glmUnitize(lthigh);
	glmFacetNormals(lthigh);
	glmVertexNormals(lthigh, 90.0);
    }

    glmDraw(lthigh, GLM_SMOOTH | GLM_MATERIAL);
}
void drawrthigh(void)///16
{
    if (!rthigh) {
	rthigh = glmReadOBJ("data/rthigh.obj");
	if (!rthigh) exit(0);
	glmUnitize(rthigh);
	glmFacetNormals(rthigh);
	glmVertexNormals(rthigh, 90.0);
    }

    glmDraw(rthigh, GLM_SMOOTH | GLM_MATERIAL);
}
void drawlwheel(void)///17
{
    if (!lwheel) {
	lwheel = glmReadOBJ("data/lwheel.obj");
	if (!lwheel) exit(0);
	glmUnitize(lwheel);
	glmFacetNormals(lwheel);
	glmVertexNormals(lwheel, 90.0);
    }

    glmDraw(lwheel, GLM_SMOOTH | GLM_MATERIAL);
}
void drawrwheel(void)///18
{
    if (!rwheel) {
	rwheel = glmReadOBJ("data/rwheel.obj");
	if (!rwheel) exit(0);
	glmUnitize(rwheel);
	glmFacetNormals(rwheel);
	glmVertexNormals(rwheel, 90.0);
    }

    glmDraw(rwheel, GLM_SMOOTH | GLM_MATERIAL);
}
void drawlwing(void)///19
{
    if (!lwing) {
	lwing = glmReadOBJ("data/lwing.obj");
	if (!lwing) exit(0);
	glmUnitize(lwing);
	glmFacetNormals(lwing);
	glmVertexNormals(lwing, 90.0);
    }

    glmDraw(lwing, GLM_SMOOTH | GLM_MATERIAL);
}
void drawrwing(void)///20
{
    if (!rwing) {
	rwing = glmReadOBJ("data/rwing.obj");
	if (!rwing) exit(0);
	glmUnitize(rwing);
	glmFacetNormals(rwing);
	glmVertexNormals(rwing, 90.0);
    }

    glmDraw(rwing, GLM_SMOOTH | GLM_MATERIAL);
}



float angle[20] = {};
int angleID = 0;
int oldX = 0,oldY = 0;
FILE * fin = NULL;
FILE * fout = NULL;
#include <stdio.h>
void motion(int x,int y) {
    if(0) {
        teapotX +=(x - oldX)/250.0;
        teapotY -=(y - oldY)/250.0;
        printf("glTranslatef(%.3f,%.3f, 0);\n",teapotX,teapotY);
    } else {
        angle[angleID]+=y-oldY;
    }
    angle[angleID] += y-oldY;
    oldX = x;
    oldY = y;
    glutPostRedisplay();
    ///if(fout==NULL) fout = fopen("angle.txt","w+");
    ///for(int i=0;i<20;i++) {
        ///printf("%.1f ",angle[i]);
        ///fprintf(fout,".1f",angle[i]);
    ///}
   /// printf("\n");
    ///fprintf(fout,"\n");
}
void mouse(int button,int state,int x,int y) {
    oldX = x;
    oldY = y;
}
void keyboard(unsigned char key,int x,int y){
    if(key=='r'){
        if(fin==NULL) fin = fopen("angle.txt","r");
        for(int i=0;i<20;i++) {
            fscanf(fin, "%f", & angle[i]);
        }
        glutPostRedisplay();
    }
    if(key=='0') angleID = 0;
    if(key=='1') angleID = 1;
    if(key=='2') angleID = 2;
    if(key=='3') angleID = 3;
    if(key=='4') angleID = 4;
    if(key=='5') angleID = 5;
    if(key=='6') angleID = 6;
    if(key=='7') angleID = 7;
    if(key=='8') angleID = 8;
    if(key=='9') angleID = 9;
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glDisable(GL_TEXTURE_2D);
    glutSolidSphere(0.02,30,30);///放在畫面正心，校對用的
    glPushMatrix();
        drawbody();
        glPushMatrix();
            glTranslatef(0.132,0.184, 0);//glTranslatef(teapotX, teapotY, 0);
            glRotatef(angle[1], 0, 0, 1);
            glTranslatef(-0.004,0.008, 0);
            drawlshoulder();
            glPushMatrix();
                glTranslatef(0.120,0.064, 0);
                drawlarm();
                glPushMatrix();
                    glTranslatef(0.136,-0.012, 0);
                    glRotatef(angle[2], 0, 0, 1);
                    glTranslatef(0.092,0.008, 0);
                    drawlelbow();
                    glPushMatrix();
                        glTranslatef(0.096,-0.008, 0);
                        glRotatef(angle[3], 0, 0, 1);
                        glTranslatef(0.040,0.004, 0);
                        drawlpalm();
                    glPopMatrix();
                glPopMatrix();
            glPopMatrix();

        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };///加這行, 讓它轉動

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

int main(int argc, char*argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowSize(500,500);
    glutCreateWindow("week12-3 Gundam");
    glutDisplayFunc(display);
    glutIdleFunc(display); ///加這行, 讓它轉動
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard);

    //myTexture("data/Diffuse.jpg");

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutMainLoop();
}
