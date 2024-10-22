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
  gluLookAt(10.0f, 10.0f, 10.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
  
  // Referencias
  glPushMatrix();
  glTranslatef(110, 0, 0);
  glColor3f(0, 0, 1);
  glutSolidCube(10);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(0, 0, 110);
  glColor3f(1, 0, 0);
  glutSolidCube(10);
  glPopMatrix();

  // Desenha a terreno
  glPushMatrix();
  glTranslatef(0, 0, 0);
  glScalef(100, 20, 100);
  glColor3f(1, 0.957, 0.741);
  glutSolidCube(1);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(25, 0, 0);
  glScalef(50.2, 20.2, 8);
  glColor3f(0.204, 0.322, 0.329);
  glutSolidCube(1);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(50, 0, 0);
  glScalef(10, 20.2, 100.2);
  glColor3f(0.204, 0.322, 0.329);
  glutSolidCube(1);
  glPopMatrix();

  // Desenha abacaxi
  // Desenha corpo do abacaxi
  glPushMatrix();
  glTranslatef(0, 15, 0);
  glScalef(1, 2, 1);
  glColor3f(1, 0.525, 0);
  glutSolidSphere(10, 50, 50);
  glPopMatrix();
  // Desenha coroa
  glPushMatrix();
  glTranslatef(0, 25, 0);
  glRotatef(-90, 1, 0, 0);
  glColor3f(0, 1, 0);
  glutSolidCone(2, 30, 50, 50);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(0, 25, 0);
  glRotatef(-70, 1, 0, 0);
  glColor3f(0, 1, 0);
  glutSolidCone(2, 30, 50, 50);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(0, 25, 0);
  glRotatef(-110, 1, 0, 0);
  glColor3f(0, 1, 0);
  glutSolidCone(2, 30, 50, 50);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(0, 25, 0);
  glRotatef(-90, 1, 0, 0);
  glRotatef(-20, 0, 1, 0);
  glColor3f(0, 1, 0);
  glutSolidCone(2, 30, 50, 50);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(0, 25, 0);
  glRotatef(-90, 1, 0, 0);
  glRotatef(20, 0, 1, 0);
  glColor3f(0, 1, 0);
  glutSolidCone(2, 30, 50, 50);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(0, 25, 0);
  glRotatef(-90, 1, 0, 0);
  glRotatef(20, 1, 1, 0);
  glColor3f(0, 1, 0);
  glutSolidCone(2, 30, 50, 50);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(0, 25, 0);
  glRotatef(-90, 1, 0, 0);
  glRotatef(-20, 1, 1, 0);
  glColor3f(0, 1, 0);
  glutSolidCone(2, 30, 50, 50);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(0, 25, 0);
  glRotatef(-90, 1, 0, 0);
  glRotatef(20, 0, 0, 1);
  glColor3f(0, 1, 0);
  glutSolidCone(2, 30, 50, 50);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(0, 25, 0);
  glRotatef(-90, 1, 0, 0);
  glRotatef(-20, 0, 0, 1);
  glColor3f(0, 1, 0);
  glutSolidCone(2, 30, 50, 50);
  glPopMatrix();

  // Porta
  glPushMatrix();
  glTranslatef(10, 12, 0);
  glScalef(1, 3, 1);
  glRotatef(270, 0, 1, 0);
  glColor3f(0.22, 0.22, 0.302);
  glutSolidCone(3, 20, 50, 50);
  glPopMatrix();

  //JanelaL
  glPushMatrix();
  glTranslatef(9.3, 22, 5);
  glRotatef(270, 0, 1, 0);
  glColor3f(0.22, 0.22, 0.302);
  glutSolidCone(2.2, 10, 50, 50);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(9.5, 22, 5);
  glRotatef(270, 0, 1, 0);
  glColor3f(0.741, 0.984, 1);
  glutSolidCone(1.5, 10, 50, 50);
  glPopMatrix();

  //JanelaR
  glPushMatrix();
  glTranslatef(9.4, 15, -5.5);
  glRotatef(270, 0, 1, 0);
  glColor3f(0.22, 0.22, 0.302);
  glutSolidCone(2.2, 10, 50, 50);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(9.6, 15, -5.5);
  glRotatef(270, 0, 1, 0);
  glColor3f(0.741, 0.984, 1);
  glutSolidCone(1.5, 10, 50, 50);
  glPopMatrix();

  // Desenha bob esponja
  // Corpo
  glPushMatrix();
  glTranslatef(20, 15, 20);
  glScalef(2, 5, 4);
  glColor3f(1, 0.812, 0);
  glutSolidCube(1);
  glPopMatrix();
  
  // Roupa
  glPushMatrix();
  glTranslatef(20, 12.5, 20);
  glScalef(2.05, 1.2, 4.05);
  glColor3f(0.49, 0.212, 0);
  glutSolidCube(1);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(20, 13.625, 20);
  glScalef(2.05, 1, 4.05);
  glColor3f(1, 1, 1);
  glutSolidCube(1);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(21, 13.78, 20);
  glColor3f(1, 0, 0);
  glScalef(0.5, 0.7, 0.5);
  glRotatef(45, 1, 0, 0);
  glutSolidCube(1);
  glPopMatrix();

  // Olhos
  glPushMatrix();
  glTranslatef(20.2, 16, 19);
  glColor3f(1, 1, 1);
  glutSolidSphere(1, 50, 50);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(20.2, 16, 21);
  glColor3f(1, 1, 1);
  glutSolidSphere(1, 50, 50);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(21, 16, 19);
  glColor3f(0, 0, 0);
  glutSolidSphere(0.3, 50, 50);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(21, 16, 21);
  glColor3f(0, 0, 0);
  glutSolidSphere(0.3, 50, 50);
  glPopMatrix();

  // Nariz
  glPushMatrix();
  glTranslatef(21, 15.3, 20);
  glColor3f(1, 0.812, 0);
  glScalef(4, 1, 1);
  glutSolidSphere(0.25, 50, 50);
  glPopMatrix();

  // Dentes

  glPushMatrix();
  glTranslatef(21, 14.5, 19.8);
  glColor3f(1, 1, 1);
  glScalef(0.2, 0.2, 0.2);
  glutSolidCube(1);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(21, 14.5, 20.2);
  glColor3f(1, 1, 1);
  glScalef(0.2, 0.2, 0.2);
  glutSolidCube(1);
  glPopMatrix();

  // Braços
  glPushMatrix();
  glTranslatef(20, 14, 22);
  glColor3f(1, 1, 1);
  glutSolidSphere(0.7, 50, 50);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(20, 14, 18);
  glColor3f(1, 1, 1);
  glutSolidSphere(0.7, 50, 50);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(20.2, 13, 23);
  glRotatef(-45, 1, 0, 0);
  glColor3f(1, 0.812, 0);
  glScalef(0.5, 2, 0.5);
  glutSolidSphere(0.6, 50, 50);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(20.2, 13, 17);
  glRotatef(45, 1, 0, 0);
  glColor3f(1, 0.812, 0);
  glScalef(0.5, 2, 0.5);
  glutSolidSphere(0.6, 50, 50);
  glPopMatrix();

  // Pernas
  // Calças
  glPushMatrix();
  glTranslatef(20.2, 11.8, 19);
  glColor3f(0.49, 0.212, 0);
  glutSolidCube(0.7);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(20.2, 11.8, 21);
  glColor3f(0.49, 0.212, 0);
  glutSolidCube(0.7);
  glPopMatrix();

  // Sapatos
  glPushMatrix();
  glTranslatef(20.2, 10, 19);
  glColor3f(0, 0, 0);
  glutSolidSphere(0.6, 50, 50);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(20.2, 10, 21);
  glColor3f(0, 0, 0);
  glutSolidSphere(0.6, 50, 50);
  glPopMatrix();

  // Pernas
  glPushMatrix();
  glTranslatef(20.2, 11, 19);
  glColor3f(1, 0.812, 0);
  glScalef(0.5, 3, 0.5);
  glutSolidSphere(0.6, 50, 50);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(20.2, 11, 21);
  glColor3f(1, 0.812, 0);
  glScalef(0.5, 3, 0.5);
  glutSolidSphere(0.6, 50, 50);
  glPopMatrix();

  // Plankton
  // Corpo
  glPushMatrix();
  glTranslatef(20, 13, 28);
  glColor3f(0.043, 0.388, 0.259);
  glScalef(1, 2, 1);
  glutSolidSphere(1, 50, 50);
  glPopMatrix();

  // Olho
  glPushMatrix();
  glTranslatef(20.8, 13.8, 28);
  glColor3f(1, 1, 1);
  glScalef(1, 2, 1);
  glutSolidSphere(0.4, 50, 50);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(21, 14, 28);
  glColor3f(1, 0, 0);
  glScalef(1, 2, 1);
  glutSolidSphere(0.2, 50, 50);
  glPopMatrix();

  // Pernas
  glPushMatrix();
  glTranslatef(20.2, 12, 28.5);
  glColor3f(0.043, 0.388, 0.259);
  glRotatef(90, 1, 0, 0);
  glutSolidCone(0.2, 4, 50, 50);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(20.2, 12, 27.5);
  glColor3f(0.043, 0.388, 0.259);
  glRotatef(90, 1, 0, 0);
  glutSolidCone(0.2, 4, 50, 50);
  glPopMatrix();

  // Antenas
  glPushMatrix();
  glTranslatef(20.2, 12, 28.2);
  glColor3f(0.043, 0.388, 0.259);
  glRotatef(-90, 1, 0, 0);
  glutSolidCone(0.2, 6, 50, 50);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(20.2, 12, 27.8);
  glColor3f(0.043, 0.388, 0.259);
  glRotatef(-90, 1, 0, 0);
  glutSolidCone(0.2, 6, 50, 50);
  glPopMatrix();

  // Braços
  glPushMatrix();
  glTranslatef(20.2, 13, 28.5);
  glRotatef(90, 1, 0, 0);
  glRotatef(-45, 1, 0, 0);
  glColor3f(0.043, 0.388, 0.259);
  glutSolidCone(0.25, 2, 50, 50);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(20.2, 13, 27.5);
  glRotatef(90, 1, 0, 0);
  glRotatef(45, 1, 0, 0);
  glColor3f(0.043, 0.388, 0.259);
  glutSolidCone(0.25, 2, 50, 50);
  glPopMatrix();

  
  // Algas
  glPushMatrix();
  glTranslatef(20, 10, -10);
  glRotatef(-90, 1, 0, 0);
  glColor3f(0, 1, 0);
  glutSolidCone(0.5, 5, 50, 50);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(21, 10, -11);
  glRotatef(-90, 1, 0, 0);
  glColor3f(0, 1, 0);
  glutSolidCone(0.8, 8, 50, 50);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(18, 10, -11);
  glRotatef(-90, 1, 0, 0);
  glColor3f(0, 1, 0);
  glutSolidCone(0.6, 5, 50, 50);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-20, 10, 13);
  glRotatef(-90, 1, 0, 0);
  glColor3f(0, 1, 0);
  glutSolidCone(0.5, 5, 50, 50);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-21, 10, 14);
  glRotatef(-90, 1, 0, 0);
  glColor3f(0, 1, 0);
  glutSolidCone(0.8, 8, 50, 50);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-18, 10, 14);
  glRotatef(-90, 1, 0, 0);
  glColor3f(0, 1, 0);
  glutSolidCone(0.6, 5, 50, 50);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-45, 10, -45);
  glRotatef(-90, 1, 0, 0);
  glColor3f(0, 1, 0);
  glutSolidCone(0.8, 7, 50, 50);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(45, 10, 45);
  glRotatef(-90, 1, 0, 0);
  glColor3f(0, 1, 0);
  glutSolidCone(0.8, 7, 50, 50);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-45, 10, 45);
  glRotatef(-90, 1, 0, 0);
  glColor3f(0, 1, 0);
  glutSolidCone(0.8, 7, 50, 50);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(45, 10, -45);
  glRotatef(-90, 1, 0, 0);
  glColor3f(0, 1, 0);
  glutSolidCone(0.8, 7, 50, 50);
  glPopMatrix();

  // Bolhas
  glPushMatrix();
  glTranslatef(20, 15, -20);
  glColor3f(0.631, 0.914, 0.969);
  glutSolidSphere(1, 50, 50);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(19, 18, -22);
  glColor3f(0.631, 0.914, 0.969);
  glScalef(3, 3, 3);
  glutSolidSphere(1, 50, 50);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(1, 14, 25);
  glColor3f(0.631, 0.914, 0.969);
  glutSolidSphere(1, 50, 50);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(1, 22, 27);
  glColor3f(0.631, 0.914, 0.969);
  glScalef(3, 3, 3);
  glutSolidSphere(1, 50, 50);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(1, 30, 25);
  glColor3f(0.631, 0.914, 0.969);
  glScalef(4, 4, 4);
  glutSolidSphere(1, 50, 50);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-10, 30, -20);
  glColor3f(0.631, 0.914, 0.969);
  glScalef(2, 2, 2);
  glutSolidSphere(1, 50, 50);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-10, 35, -25);
  glColor3f(0.631, 0.914, 0.969);
  glScalef(5, 5, 5);
  glutSolidSphere(1, 50, 50);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-20, 30, 30);
  glColor3f(0.631, 0.914, 0.969);
  glScalef(3, 3, 3);
  glutSolidSphere(1, 50, 50);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-21, 25, 29);
  glColor3f(0.631, 0.914, 0.969);
  glScalef(1, 1, 1);
  glutSolidSphere(1, 50, 50);
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

void GerenciaTeclado(unsigned char key, int x, int y){
    float px = 0.0f;
    float py = 0.0f;
    float pz = 0.0f;
    switch(key){
        case 'w':
            printf("w");
            py = py + 10;
            glTranslatef(px, py, pz);
            break;
        case 's':
            printf("s");
            py = py - 10;
            glTranslatef(px, py, pz);
            break;
        case 'd':
            printf("d");
            px = px + 10;
            glTranslatef(px, py, pz);
            break;
        case 'a':
            printf("a");
            px = px - 10;
            glTranslatef(px, py, pz);
            break;
    }
    glutPostRedisplay();
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
  win_id = glutCreateWindow ("Bob Esponja");
  // Chama a função init
  init ();
  // Estabelece a função "display" como a função callback de exibição.
  glutDisplayFunc(display); 
  // Estabelece a função "reshape" como a função callback de redimensionamento da janela de exibição.
  glutReshapeFunc(reshape);
  // Entra no loop de eventos, não retorna
  glutKeyboardFunc(GerenciaTeclado);
  glutMainLoop();
  return 0;
}