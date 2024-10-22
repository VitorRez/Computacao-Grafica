
/* Copyright (c) Mark J. Kilgard, 1996. */

/* This program is freely distributable without licensing fees 
   and is provided without guarantee or warrantee expressed or 
   implied. This program is -not- in the public domain. */

/* This program is a response to a question posed by Gil Colgate
   <gcolgate@sirius.com> about how lengthy a program is required using
   OpenGL compared to using  Direct3D immediate mode to "draw a
   triangle at screen coordinates 0,0, to 200,200 to 20,200, and I
   want it to be blue at the top vertex, red at the left vertex, and
   green at the right vertex".  I'm not sure how long the Direct3D
   program is; Gil has used Direct3D and his guess is "about 3000
   lines of code". */

/* X compile line: cc -o simple simple.c -lglut -lGLU -lGL -lXmu -lXext -lX11 -lm */

#include <GL/glut.h>

float R1 = 0.0;
float G1 = 0.0;
float B1 = 1.0;
float R2 = 0.0;
float G2 = 1.0;
float B2 = 0.0;
float R3 = 1.0;
float G3 = 0.0;
float B3 = 0.0;
float R4 = 0.0;
float G4 = 1.0;
float B4 = 0.0;

void
reshape(int w, int h)
{
  /* Because Gil specified "screen coordinates" (presumably with an
     upper-left origin), this short bit of code sets up the coordinate
     system to correspond to actual window coodrinates.  This code
     wouldn't be required if you chose a (more typical in 3D) abstract
     coordinate system. */

  glViewport(0, 0, w, h);       /* Establish viewing area to cover entire window. */
  glMatrixMode(GL_PROJECTION);  /* Start modifying the projection matrix. */
  glLoadIdentity();             /* Reset project matrix. */
  glOrtho(0, w, 0, h, -1, 1);   /* Map abstract coords directly to window coords. */
  glScalef(1, -1, 1);           /* Invert Y axis so increasing Y goes down. */
  glTranslatef(0, -h, 0);       /* Shift origin up to upper-left corner. */
}

void
display(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_QUADS);
    glColor3f(R1, G1, B1);  /* blue */
    glVertex2i(0, 0);

    glColor3f(R2, G2, B2);
    glVertex2i(200, 0);

    glColor3f(R3, G3, B3);  /* red */
    glVertex2i(200, 200);

    glColor3f(R4, G4, B4);  /* green */
    glVertex2i(0, 200); 
  glEnd();
  glFlush();  /* Single buffered, so needs a flush. */
}

void meuTeclado(unsigned char key, int x, int y){
  switch(key){
    case 27:
      exit(0);
      break;
    case 'a':
    case 'A':
      R1 = (float)rand()/(float)(RAND_MAX);
      G1 = (float)rand()/(float)(RAND_MAX);
      B1 = (float)rand()/(float)(RAND_MAX);
      R2 = (float)rand()/(float)(RAND_MAX);
      G2 = (float)rand()/(float)(RAND_MAX);
      B2 = (float)rand()/(float)(RAND_MAX);
      R3 = (float)rand()/(float)(RAND_MAX);
      G3 = (float)rand()/(float)(RAND_MAX);
      B3 = (float)rand()/(float)(RAND_MAX);
      R4 = (float)rand()/(float)(RAND_MAX);
      G4 = (float)rand()/(float)(RAND_MAX);
      B4 = (float)rand()/(float)(RAND_MAX);
      glutPostRedisplay();
      break;
  }
}

int
main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutCreateWindow("single triangle");
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  while(1){
    glutKeyboardFunc(meuTeclado);
    glutMainLoop();
  }
  return 0;             /* ANSI C requires main to return int. */
}
