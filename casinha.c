#include <GL/glut.h>
#include <math.h>

//Bom dia Madeira, ignora essa p#ta função megazord, eu ia mudar mas fiquei com preguiça, abraços

void reshape(int w, int h){
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0,w,0,h,-1,1);
    glScalef(1,-1,1);
    glTranslatef(0,-h,0);
}

//função tengen toppa gurren lagann (eu sei melhorar isso ta deixar bem claro viu)
void display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
        glColor3f(0.204,0.761,0.212);
        glVertex2i(0, 180);
        
        glColor3f(0.204,0.761,0.212);
        glVertex2i(0, 250);
        
        glColor3f(0.204,0.761,0.212);
        glVertex2i(400, 250);

        glColor3f(0.204,0.761,0.212);
        glVertex2i(400, 180); 
    glEnd();
    glBegin(GL_QUADS);
        glColor3f(0.208,0.651,0.761);
        glVertex2i(0, 0);
        
        glColor3f(0.208,0.651,0.761);
        glVertex2i(0, 180);
        
        glColor3f(0.208,0.651,0.761);
        glVertex2i(400, 180);

        glColor3f(0.208,0.651,0.761);
        glVertex2i(400, 0); 
    glEnd();
    glBegin(GL_QUADS);
        glColor3f(0.969,0.816,0.208);
        glVertex2i(100, 100);
        
        glColor3f(0.969,0.816,0.208);
        glVertex2i(200, 100);
        
        glColor3f(0.969,0.816,0.208);
        glVertex2i(200, 200);

        glColor3f(0.969,0.816,0.208);
        glVertex2i(100, 200); 
    glEnd();
    glBegin(GL_TRIANGLES);
        glColor3f(0.969,0.816,0.208);
        glVertex2i(100, 100);

        glColor3f(0.969,0.816,0.208);
        glVertex2i(150, 50);

        glColor3f(0.969,0.816,0.208);
        glVertex2i(200, 100);
    glEnd();
    glBegin(GL_QUADS);
        glColor3f(0.5,0.2,0);
        glVertex2i(150, 50);
        
        glColor3f(0.5,0.2,0);
        glVertex2i(250, 50);
        
        glColor3f(0.5,0.2,0);
        glVertex2i(300, 100);

        glColor3f(0.5,0.2,0);
        glVertex2i(200, 100); 
    glEnd();
    glBegin(GL_QUADS);
        glColor3f(0.961,0.769,0.027);
        glVertex2i(200, 100);
        
        glColor3f(0.961,0.769,0.027);
        glVertex2i(300, 100);
        
        glColor3f(0.961,0.769,0.027);
        glVertex2i(300, 200);

        glColor3f(0.961,0.769,0.027);
        glVertex2i(200, 200); 
    glEnd();
    glBegin(GL_QUADS);
        glColor3f(0.961,0.769,0.027);
        glVertex2i(200, 50);
        
        glColor3f(0.961,0.769,0.027);
        glVertex2i(200, 30);
        
        glColor3f(0.961,0.769,0.027);
        glVertex2i(220, 30);

        glColor3f(0.961,0.769,0.027);
        glVertex2i(220, 50); 
    glEnd();
    glBegin(GL_QUADS);
        glColor3f(0.5,0.2,0);
        glVertex2i(195, 30);
        
        glColor3f(0.5,0.2,0);
        glVertex2i(195, 20);
        
        glColor3f(0.5,0.2,0);
        glVertex2i(225, 20);

        glColor3f(0.5,0.2,0);
        glVertex2i(225, 30); 
    glEnd();
    glBegin(GL_QUADS);
        glColor3f(0.5,0.2,0);
        glVertex2i(130, 200);
        
        glColor3f(0.5,0.2,0);
        glVertex2i(130, 130);
        
        glColor3f(0.5,0.2,0);
        glVertex2i(170, 130);

        glColor3f(0.5,0.2,0);
        glVertex2i(170, 200); 
    glEnd();
    glBegin(GL_QUADS);
        glColor3f(1,1,1);
        glVertex2i(220, 140);
        
        glColor3f(1,1,1);
        glVertex2i(220, 160);
        
        glColor3f(1,1,1);
        glVertex2i(240, 160);

        glColor3f(1,1,1);
        glVertex2i(240, 140); 
    glEnd();
    glBegin(GL_QUADS);
        glColor3f(1,1,1);
        glVertex2i(260, 140);
        
        glColor3f(1,1,1);
        glVertex2i(260, 160);
        
        glColor3f(1,1,1);
        glVertex2i(280, 160);

        glColor3f(1,1,1);
        glVertex2i(280, 140); 
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
        GLfloat x = 150.0;
        GLfloat y = 80.0;
        GLfloat twicePi = 2.0f * 3.14;
        GLfloat radius = 10.0;
        glVertex2f(x, y);
        for(int i = 0; i <= 50; i++){
            glVertex2f(
                x + (radius * cos(i * twicePi / 50)),
                y + (radius * sin(i * twicePi / 50))
            );
            glColor3f(1,1,1);
        }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
        x = 250.0;
        y = 20.0;
        radius = 10.0;
        glVertex2f(x, y);
        for(int i = 0; i <= 50; i++){
            glVertex2f(
                x + (radius * cos(i * twicePi / 50)),
                y + (radius * sin(i * twicePi / 50))
            );
            glColor3f(1,1,1);
        }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
        x = 160.0;
        y = 175.0;
        radius = 2.0;
        glVertex2f(x, y);
        for(int i = 0; i <= 50; i++){
            glVertex2f(
                x + (radius * cos(i * twicePi / 50)),
                y + (radius * sin(i * twicePi / 50))
            );
            glColor3f(1,1,1);
        }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
        x = 260.0;
        y = 10.0;
        radius = 10.0;
        glVertex2f(x, y);
        for(int i = 0; i <= 50; i++){
            glVertex2f(
                x + (radius * cos(i * twicePi / 50)),
                y + (radius * sin(i * twicePi / 50))
            );
            glColor3f(1,1,1);
        }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
        x = 260.0;
        y = 30.0;
        radius = 10.0;
        glVertex2f(x, y);
        for(int i = 0; i <= 50; i++){
            glVertex2f(
                x + (radius * cos(i * twicePi / 50)),
                y + (radius * sin(i * twicePi / 50))
            );
            glColor3f(1,1,1);
        }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
        x = 260.0;
        y = 20.0;
        radius = 10.0;
        glVertex2f(x, y);
        for(int i = 0; i <= 50; i++){
            glVertex2f(
                x + (radius * cos(i * twicePi / 50)),
                y + (radius * sin(i * twicePi / 50))
            );
            glColor3f(1,1,1);
        }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
        x = 270.0;
        y = 20.0;
        radius = 10.0;
        glVertex2f(x, y);
        for(int i = 0; i <= 50; i++){
            glVertex2f(
                x + (radius * cos(i * twicePi / 50)),
                y + (radius * sin(i * twicePi / 50))
            );
            glColor3f(1,1,1);
        }
    glEnd();
    glFlush();
}

int main(int argc, char** argv){
    glutInitWindowSize(400, 250);
    glutInit(&argc, argv);
    glutCreateWindow("Casinha do madeira");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}