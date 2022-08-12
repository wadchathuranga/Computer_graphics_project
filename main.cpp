#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>

#define ESCAPE 27

GLfloat T = 0;
GLfloat Ry = 0;
GLfloat Tby=0.8;
GLfloat Tbx=1.5,Rx=1.5; //table & rocket position x
GLfloat Tbz=-3.5,Rz=-3.5;   //table & rocket position z
GLfloat xt=0; // car move
GLfloat Cx=-4,Cy=1,Cz=4;   // for camera view change
GLfloat AT =0.0;
GLfloat ani=0;
GLfloat r=0,g=0,b=1;    // color define


void Animation()
{
    // tower head spinner
    T = T + 1;
    if(T>360){
        T = 0;
    }

    // roof open & rocket launch
    if(ani==1){
        if(AT<=0.8){
            AT=AT+0.002;
        }
        else{
            Ry=Ry+0.002;
        }
    }

    //rocket come back and roof close
    if(ani==2){
        if(Ry>0){
            Ry=Ry-0.002;
        }
        else if(AT>0){
            AT=AT-0.002;
        }
    }

    //pause animation
    if(ani==0){
        Ry=Ry;
        AT=AT;
    }



    glutPostRedisplay();
}

void surface()
{
    GLfloat Col_black[] = {0.7,0.7,0.7,1};
    GLfloat Col_green[] = {0,0.3,0,1};
    GLfloat Col_yellow[] = {1,1,0,1};

    //ground surface
    glPushMatrix();
        glLightfv(GL_LIGHT0,GL_DIFFUSE,Col_green);
        glTranslatef(0,-0.2,0);
        glScalef(100,0.01,100);
        glutSolidCube(1);
    glPopMatrix();

    //road
    glPushMatrix();
        glLightfv(GL_LIGHT0,GL_DIFFUSE,Col_black);
        glTranslatef(0,-0.19,0);
        glScalef(100,0.01,1);
        glutSolidCube(1);
    glPopMatrix();

    //middle line of road
    glPushMatrix();
        glLightfv(GL_LIGHT0,GL_DIFFUSE,Col_yellow);
        glTranslatef(0,-0.189,0);
        glScalef(100,0.01,0.1);
        glutSolidCube(1);
    glPopMatrix();
}

void Hut()
{
    GLfloat Col[] = {1,0,0,1};
    glLightfv(GL_LIGHT0,GL_DIFFUSE,Col);
    // ---------------- table top face ---------
    glPushMatrix();
    glTranslatef(AT+Tbx,Tby,Tbz);
        glScalef(1,0.05,1);
        glutSolidCube(1);
    glPopMatrix();

    // ---------------- table leg ---------
    glPushMatrix();
        glTranslatef(AT+Tbx-0.47,Tby-0.5,Tbz-0.47);
        glScalef(0.05,1,0.05);
        glutSolidCube(1);
    glPopMatrix();

    // ---------------- table leg ---------
    glPushMatrix();
        glTranslatef(AT+Tbx-0.47,Tby-0.5,Tbz+0.47);
        glScalef(0.05,1,0.05);
        glutSolidCube(1);
    glPopMatrix();

    // ---------------- table leg ---------
    glPushMatrix();
        glTranslatef(Tbx+0.47,Tby-0.5,Tbz+0.47);
        glScalef(0.05,1,0.05);
        glutSolidCube(1);
    glPopMatrix();

    // ---------------- table leg ---------
    glPushMatrix();
        glTranslatef(Tbx+0.47,Tby-0.5,Tbz-0.47);
        glScalef(0.05,1,0.05);
        glutSolidCube(1);
    glPopMatrix();
}

void Car()
{
    GLfloat Col_black[] = {0.7,0.7,0.7,1};
    GLfloat Col_Blue[] = {r,g,b,1};
    // car center body
    glPushMatrix();
        glLightfv(GL_LIGHT0,GL_DIFFUSE,Col_Blue);
        glTranslatef(xt,0.05,0);
        glScalef(0.5,0.3,0.5);
        glutSolidCube(1);
    glPopMatrix();

    // front
    glPushMatrix();
        glLightfv(GL_LIGHT0,GL_DIFFUSE,Col_Blue);
        glTranslatef(xt-0.37,0,0);
        glScalef(0.25,0.20,0.5);
        glutSolidCube(1);
    glPopMatrix();

    // back
    glPushMatrix();
        glLightfv(GL_LIGHT0,GL_DIFFUSE,Col_Blue);
        glTranslatef(xt+0.40,0,0);
        glScalef(0.3,0.20,0.5);
        glutSolidCube(1);
    glPopMatrix();

    // wheel-b1
    glPushMatrix();
        glLightfv(GL_LIGHT0,GL_DIFFUSE,Col_black);
        glTranslatef(xt+0.3,-0.05,0.25);
        glutSolidTorus(0.05,0.05,50,200);
    glPopMatrix();

    // wheel-b2
    glPushMatrix();
        glLightfv(GL_LIGHT0,GL_DIFFUSE,Col_black);
        glTranslatef(xt+0.3,-0.05,-0.25);
        glutSolidTorus(0.05,0.05,50,200);
    glPopMatrix();

    // wheel-f1
    glPushMatrix();
        glLightfv(GL_LIGHT0,GL_DIFFUSE,Col_black);
        glTranslatef(xt-0.3,-0.05,0.25);
        glutSolidTorus(0.05,0.05,50,200);
    glPopMatrix();

    // wheel-f2
    glPushMatrix();
        glLightfv(GL_LIGHT0,GL_DIFFUSE,Col_black);
        glTranslatef(xt-0.3,-0.05,-0.25);
        glutSolidTorus(0.05,0.05,50,200);
    glPopMatrix();
}

void Tree(GLfloat Tx, GLfloat Tz)
{
    GLfloat Col_green[] = {0,1,0,1};
    GLfloat Col_Brown[] = {1.0,0.5,0.0,1};

    // left leaves
    glPushMatrix();
        glLightfv(GL_LIGHT0,GL_DIFFUSE,Col_green);
        glTranslatef(Tx-0.15,0.45,Tz);
        glScalef(0.5,0.3,0.5);
        glutSolidSphere(0.5,100,100);
    glPopMatrix();

    // right leaves
    glPushMatrix();
        glLightfv(GL_LIGHT0,GL_DIFFUSE,Col_green);
        glTranslatef(Tx+0.15,0.45,Tz);
        glScalef(0.5,0.3,0.5);
        glutSolidSphere(0.5,100,100);
    glPopMatrix();

    // Top leaves
    glPushMatrix();
        glLightfv(GL_LIGHT0,GL_DIFFUSE,Col_green);
        glTranslatef(Tx,0.65,Tz);
        glScalef(0.5,0.3,0.5);
        glutSolidSphere(0.5,100,100);
    glPopMatrix();

    // tree body
    glPushMatrix();
        glLightfv(GL_LIGHT0,GL_DIFFUSE,Col_Brown);
        glTranslatef(Tx,-0.2,Tz);
        glRotatef(-90,1,0,0);
        glutSolidCone(0.1,1,100,100);
    glPopMatrix();
}

void Tower(GLfloat TWx, GLfloat TWz)
{
    GLfloat Col_Black[] = {0.7,0.7,0.7,1};
    GLfloat Col_Red[] = {1,0,0,1};

    // cone
    glPushMatrix();
        glLightfv(GL_LIGHT0,GL_DIFFUSE,Col_Black);
        glTranslatef(TWx,-0.2,TWz);
        glRotatef(-90,1,0,0);
        glutSolidCone(0.2,1.5,100,100);
    glPopMatrix();

    // torus
    glPushMatrix();
        glLightfv(GL_LIGHT0,GL_DIFFUSE,Col_Red);
        glTranslatef(TWx,1.4,TWz);
        glRotatef(T,0,1,0);
        glutSolidTorus(0.05,0.15,20,20);
    glPopMatrix();

    // tea pot
    glPushMatrix();
        glLightfv(GL_LIGHT0,GL_DIFFUSE,Col_Red);
        glTranslatef(TWx,1.4,TWz);
        //glutSolidTeapot(0.05);
        glutSolidSphere(0.05,20,20);
    glPopMatrix();
}

void Rocket()
{
    GLfloat Col_Black[] = {0.7,0.7,0.7,1};
    GLfloat Col_Red[] = {1,0,0,1};

    // torus
    glPushMatrix();
        glLightfv(GL_LIGHT0,GL_DIFFUSE,Col_Red);
        glTranslatef(Rx,Ry+0.05,Rz);
        glRotatef(90,1,0,0);
        glScalef(1,1,5);
        glutSolidTorus(0.05,0.15,20,20);
    glPopMatrix();

    // cone 1
    glPushMatrix();
        glLightfv(GL_LIGHT0,GL_DIFFUSE,Col_Black);
        glTranslatef(Rx,Ry+0.2,Rz);
        glRotatef(-90,1,0,0);
        glutSolidCone(0.2,0.5,100,100);
    glPopMatrix();

    // cone 2
    glPushMatrix();
        glLightfv(GL_LIGHT0,GL_DIFFUSE,Col_Black);
        glTranslatef(Rx,Ry-0.2,Rz);
        glRotatef(-90,1,0,0);
        glutSolidCone(0.25,1.0,100,100);
    glPopMatrix();
}

void display()
{
    GLfloat Pos[] = {0,1,0,1};

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glClearColor(0.0,0.5,0.7,0);

    glLightfv(GL_LIGHT0,GL_POSITION,Pos);

    gluLookAt(Cx,Cy,Cz,0,0,0,0,1,0);

    // ground surface
    surface();

    //table
    Hut();

    //car
    Car();

    // Drawing trees
    Tree(-1.5,-1.0);  // Draw Tree 1
    Tree(1.5,1.0);    // Draw Tree 2
    Tree(3.0,-1.0);   // Draw Tree 3
    Tree(6.0,1.0);    // Draw Tree 4
    Tree(6.0,-1.0);    // Draw Tree 5
    Tree(7.5,-1.0);    // Draw Tree 6
    Tree(10,1.0);    // Draw Tree 7
    Tree(4,-3.0);    // Draw Tree 8
    Tree(-2.5,-5.0);    // Draw Tree 9

    // Draw Tower 1
    Tower(-1,-3);   // Draw Tower 1
    Tower(-2,-3.5); // Draw Tower 2
    Tower(2,2.5); // Draw Tower 3

    // rocket
    Rocket();

    glutSwapBuffers();
}


static void SpecialKeyFunc( int Key, int x, int y )
{
    switch ( Key ) {
        case GLUT_KEY_RIGHT:
            xt += 0.2;
            glutPostRedisplay();
            break;
        case GLUT_KEY_LEFT:
            xt -= 0.2;
            glutPostRedisplay();
            break;
    }
}


// Keyboard handling
void Key(unsigned char ch, int x, int y)
{
    switch(ch)
    {
        case 'x' : Cx = Cx - 0.5; break;
        case 'X' : Cx = Cx + 0.5; break;

        case 'y' : Cy = Cy - 0.5; break;
        case 'Y' : Cy = Cy + 0.5; break;

        case 'z' : Cz = Cz - 0.5; break;
        case 'Z' : Cz = Cz + 0.5; break;

        case ESCAPE : exit(0); break;
        case 'q' : exit(0); break;
        case 'Q' : exit(0); break;
    }
    glutPostRedisplay();
}


void resize(int width, int height)
{
    const float wh = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-wh, wh, -1.0, 1.0, 2.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void colorMenu(int id)
{
    if (id==1)
    {
        r=g=0;
        b=1;
    }
    if(id ==2)
    {
        r=1;
        b=g=0;
    }
    if(id==3)
    {
        g=0;
        r=b=1;
    }
    glutPostRedisplay();
}

void myMenu(int id)
{
    if (id==4)
    {
        ani=1;
    }
    if(id==5)
    {
        ani=2;
    }
    if(id==6)
    {
        ani=0;
    }
    if(id==7)
    {
        exit(0);
    }
    glutPostRedisplay();
}

void myInit()
{
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1,1,-1,1,2,10);
    glMatrixMode(GL_MODELVIEW);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
}



int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(1080,720);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Tea Table");

    myInit();
    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(Key);
    glutSpecialFunc(SpecialKeyFunc);
    glutIdleFunc(Animation);

    //sub-menu
    int submenu=glutCreateMenu(colorMenu);
    glutAddMenuEntry("blue", 1);
    glutAddMenuEntry("red", 2);
    glutAddMenuEntry("Pink",3);

    //main-menu
    glutCreateMenu(myMenu);
    glutAddSubMenu("Change car colors",submenu);
    glutAddMenuEntry("Animation Play", 4);
    glutAddMenuEntry("Animation Play Black", 5);
    glutAddMenuEntry("Animation Pause", 6);
    glutAddMenuEntry("Exit",7);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutMainLoop();
    return 0;
}
