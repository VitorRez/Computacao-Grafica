#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int win_id;

/*
FUNÇÕES QUE DEVEM SER USADAS
void glutSolidCube(GLdouble size);
void glutSolidSphere(GLdouble radius, GLint slices, GLint stacks);
void glutSolidCone(GLdouble base, GLdouble height, GLint slices, GLint stacks);
void glRotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
void glTranslatef(GLfloat x, GLfloat y,  GLfloat z);
void glScalef(GLfloat x, GLfloat y, GLfloat z);
*/

void myKeyboard(unsigned char key, int x, int y){
  int z = 50;
  x = 0;
  y = 30;
  switch(key){
    case 'a':
      x = x - 10;
      printf("%d %d %d", x, y, z);
      gluLookAt(x, y, z, 20.0f, 20.0f, 0.0f, 0.0f, 1.0f, 0.0f);
      break;
    case 'd':
      x = x + 10;
      printf("%d %d %d", x, y, z);
      gluLookAt(x, y, z, 20.0f, 20.0f, 0.0f, 0.0f, 1.0f, 0.0f);
      break;
    case 'w':
      y = y + 10;
      printf("%d %d %d", x, y, z);
      gluLookAt(x, y, z, 20.0f, 20.0f, 0.0f, 0.0f, 1.0f, 0.0f);
      break;
    case 's':
      y = y - 10;
      printf("%d %d %d", x, y, z);
      gluLookAt(x, y, z, 20.0f, 20.0f, 0.0f, 0.0f, 1.0f, 0.0f);
      break;
  }
  return;
}

void init(void) 
{
  // Define a cor de fundo da janela de visualização como preto
  glClearColor (0.0, 0.0, 0.0, 0.0);
  // Define o modo de rastreio de cor utilizado para misturar a cor do material nos pontos da face (smoothing)
  glShadeModel (GL_SMOOTH);
  // Habilita a definição da cor do material a partir da cor corrente
  glEnable(GL_COLOR_MATERIAL);

  //Parâmetros para a luz ambiente, difusa e especular, definindo também a posição da luz
  GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
  GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
  GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
  GLfloat light_position[] = { 10.0, 10.0, 10.0, 0.0 };

  // Passa os parâmetros definidos acima para a OpenGL
  glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
  glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
  glLightfv(GL_LIGHT0, GL_POSITION, light_position);

  // Habilita a luz ambiente, a luz zero e o depth buffer
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_DEPTH_TEST);
}

//Desenha um quadrado de lado 1 centrado na origem
void desenhaQuadrado() {
    glBegin(GL_QUADS);
        glVertex2f(-0.5, -0.5);
        glVertex2f(0.5, -0.5);
        glVertex2f(0.5, 0.5);
        glVertex2f(-0.5, 0.5);
    glEnd();
}

//Desenha um triângulo equilátero de lado 1 centrado na origem
void desenhaTriangulo() {
    glBegin(GL_TRIANGLES);
        glVertex2d(0.0, 0.5);
        glVertex2d(-0.5, -0.5);
        glVertex2d(0.5, -0.5);
    glEnd();
}

//Desenha um círculo de raio 1 centrado na origem
void desenhaCirculo() {
    glBegin(GL_POLYGON);
        for (int i = 0; i < 200; i++) {
            glVertex2f(cos(i), sin(i));
        }
    glEnd();
}

void display(void)
{
  // Limpa a janela de visualização com a cor de fundo especificada, e limpa também o depth buffer
  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  
  // Entra no modo de definição de matriz de visualização
  glMatrixMode(GL_MODELVIEW);
  // Carrega a matriz identidade
  glLoadIdentity();
  // Define a posição da câmera, para onde ela aponta e qual o vetor UP
  //gluLookAt(0.0f, 30.0f, 50.0f, 20.0f, 20.0f, 0.0f, 0.0f, 1.0f, 0.0f);
  
  // Desenha a casa

  //corpo
  glPushMatrix();
  glColor3f(0.89, 0.69, 0.341);
  glTranslatef(10, 10, 10);
  glutSolidCube(20);
  glPopMatrix();
  //porta
  glPushMatrix();
  glColor3f(0.361, 0.161, 0.024);
  glTranslatef(10, 7, 11);
  glScalef(0.3, 0.7, 1);
  glutSolidCube(20);
  glPopMatrix();
  //maçaneta
  glPushMatrix();
  glColor3f(1, 1, 0);
  glTranslatef(8, 10, 31);
  glutSolidSphere(1, 50, 50);
  glPopMatrix();
  //janela
  glPushMatrix();
  glColor3f(0.388, 0.91, 0.878);
  glTranslatef(10, 10, 10);
  glScalef(1.01, 0.3, 0.3);
  glutSolidCube(20);
  glPopMatrix();
  //telhado
  glPushMatrix();
  glColor3f(1, 0.286, 0);
  glTranslatef(10, 20, 10);
  glRotatef(-90, 1, 0, 0);
  glutSolidCone(16, 15, 50, 50);
  glPopMatrix();
  //chaminé
  glPushMatrix();
  glColor3f(1, 0, 0);
  glTranslatef(2, 20, 10);
  glScalef(0.5, 3, 0.5);
  glutSolidCube(7);
  glPopMatrix();
  //nuvem
  glPushMatrix();
  glColor3f(1, 1, 1);
  glTranslatef(2, 37, 10);
  glutSolidSphere(3, 50, 50);
  glPopMatrix();
  glPushMatrix();
  glColor3f(1, 1, 1);
  glTranslatef(1, 40, 10);
  glutSolidSphere(4, 50, 50);
  glPopMatrix();
  
  // Executa os comandos OpenGL, e depois troca os buffers de vídeo
  glFlush();
}

void reshape (int w, int h)
{
  // Define o viewport como o tamanho da janela
  glViewport (0, 0, (GLsizei) w, (GLsizei) h);
  // Entra no modo de definição de matriz de projeção
  glMatrixMode (GL_PROJECTION);
  // Carrega a matriz identidade
  glLoadIdentity();
  // Define a projeção ortogonal
  if (w <= h)
    // Se a largura for menor que a altura, a projeção é feita para manter a proporção da janela
    glOrtho (-50, 50, -50*(GLfloat)h/(GLfloat)w, 50*(GLfloat)h/(GLfloat)w, -100.0, 100.0);
  else
    // Se a altura for menor que a largura, a projeção é feita para manter a proporção da janela
    glOrtho (-50*(GLfloat)w/(GLfloat)h, 50*(GLfloat)w/(GLfloat)h, -50, 50, -100.0, 100.0);
   
}

int main(int argc, char** argv)
{
  // Inicializa a biblioteca GLUT e negocia uma seção com o gerenciador de janelas
  glutInit(&argc, argv);
  // Inicializa o display, indicando que usará:
  // - um buffer de imagem (single buffer);
  // - buffer de profundidade;
  // - padrão de cores RGB)
  glutInitDisplayMode (GLUT_SINGLE | GLUT_DEPTH | GLUT_RGB);
  // Especifica as dimensões da janela de exibição
  glutInitWindowSize (500, 500); 
  // Especifica a posição inicial da janela de exibição
  glutInitWindowPosition (100, 100);
  // Cria a janela de exibição
  win_id = glutCreateWindow ("casa3D");
  // Chama a função init
  init ();
  // Estabelece a função "display" como a função callback de exibição.
  glutDisplayFunc(display); 
  // Estabelece a função "reshape" como a função callback de redimensionamento da janela de exibição.
  glutReshapeFunc(reshape);
  // Entra no loop de eventos, não retorna
  glutKeyboardFunc(myKeyboard);
  glutMainLoop();
  return 0;
}