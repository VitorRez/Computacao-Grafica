#include <GL/glut.h>
#include <math.h>

// Largura e altura da janela
GLfloat windowWidth;
GLfloat windowHeight;

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

//Faz o cisalhamento de um objeto em relação ao eixo X
//Basta utilizar como uma das funções do OpenGL como glTranslatef, glRotatef, glScalef
void skewX(GLfloat angle) {
    GLfloat m[16] = {
        1, 0, 0, 0,
        tan(angle), 1, 0, 0,
        0, 0, 1, 0,
        0, 0, 0 ,1
    };
    glMultMatrixf(m);
}

//Faz o cisalhamento de um objeto em relação ao eixo Y
//Basta utilizar como uma das funções do OpenGL como glTranslatef, glRotatef, glScalef
void skewY(GLfloat angle) {
    GLfloat m[16] = {
        1, tan(angle), 0, 0,
        0, 1, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1
    };
    glMultMatrixf(m);
}

// Função callback chamada para fazer o desenho
void Desenha(void)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Limpa a janela de visualização com a cor de fundo especificada
    glClear(GL_COLOR_BUFFER_BIT);

    // Aqui entra todo o seu código da casa 2D.
    //Vocês só pode usar as funções de desenho:
        // desenhaQuadrado, desenhaTriangulo, desenhaCirculo
    // as transformações geométricas:
        // glTranslatef, glRotatef, glScalef, skewX, skewY
    // e as funções de cor:
        // glColor3f
    // Não desenhe nenhuma primitiva utilizando glBegin/glEnd diretamente aqui.
    
    //Fundo épico

    glPushMatrix();
    glColor3f(0, 110, 1);
    glScalef(1000, 1000, 1);
    desenhaQuadrado();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0, 1, 0);
    glTranslatef(100, 0, 0);
    glScalef(1000, 100, 1);
    desenhaQuadrado();
    glPopMatrix();

    //Paredes
    glPushMatrix();
    glColor3f(0.89, 0.69, 0.341);
    glTranslatef(100, 80, 0);
    glScalef(100, 100, 1);
    desenhaQuadrado();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 0.773, 0.38);
    glTranslatef(200, 80, 0);
    glScalef(100, 100, 1);
    desenhaQuadrado();
    glPopMatrix();

    //Chaminé

    glPushMatrix();
    glColor3f(1, 0, 0);
    glTranslatef(160, 200, 0);
    glScalef(20, 20, 1);
    desenhaQuadrado();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 0, 0);
    glTranslatef(160, 210, 0);
    glScalef(30, 5, 1);
    desenhaQuadrado();
    glPopMatrix();

    //Telhado
    glPushMatrix();
    glColor3f(1, 0.286, 0);
    glTranslatef(118, 160, 0);
    skewX(-140*3.1415/180.0f);
    glScalef(104, 67, 1);
    desenhaQuadrado();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.89, 0.69, 0.341);
    glTranslatef(100, 160, 0);
    glScalef(100, 60, 1);
    desenhaTriangulo();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 0.286, 0);
    glTranslatef(174.5, 160, 0);
    skewX(140*3.1415/180.0f);
    glScalef(104, 67, 1);
    desenhaQuadrado();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.89, 0.69, 0.341);
    glTranslatef(99, 128, 0);
    glScalef(98, 4, 1);
    desenhaQuadrado();
    glPopMatrix();

    //Porta
    glPushMatrix();
    glColor3f(0.361, 0.161, 0.024);
    glTranslatef(100, 60, 0);
    glScalef(35, 60, 1);
    desenhaQuadrado();
    glPopMatrix();

    //Janela redonda no teto
    glPushMatrix();
    glColor3f(0.361, 0.161, 0.024);
    glTranslatef(100, 155, 0);
    glScalef(14,14,1);
    desenhaCirculo();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.388, 0.91, 0.878);
    glTranslatef(100, 155, 0);
    glScalef(12,12,1);
    desenhaCirculo();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.361, 0.161, 0.024);
    glTranslatef(100, 155, 0);
    glScalef(24, 2, 1);
    desenhaQuadrado();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.361, 0.161, 0.024);
    glTranslatef(100, 155, 0);
    glScalef(2, 24, 1);
    desenhaQuadrado();
    glPopMatrix();

    //Maçaneta Gamer
    glPushMatrix();
    glColor3f(1,1,0);
    glTranslatef(110, 55, 0);
    glScalef(2,2,1);
    desenhaCirculo();
    glPopMatrix();

    //Janelas laterais
    //Janela esquerda
    glPushMatrix();
    glColor3f(0.361, 0.161, 0.024);
    glTranslatef(175, 80, 0);
    glScalef(30, 30, 1);
    desenhaQuadrado();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.388, 0.91, 0.878);
    glTranslatef(175, 80, 0);
    glScalef(25, 25, 1);
    desenhaQuadrado();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.361, 0.161, 0.024);
    glTranslatef(175, 80, 0);
    glScalef(30, 3, 1);
    desenhaQuadrado();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.361, 0.161, 0.024);
    glTranslatef(175, 80, 0);
    glScalef(3, 30, 1);
    desenhaQuadrado();
    glPopMatrix();

    //Janela direita
    glPushMatrix();
    glColor3f(0.361, 0.161, 0.024);
    glTranslatef(225, 80, 0);
    glScalef(30, 30, 1);
    desenhaQuadrado();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.388, 0.91, 0.878);
    glTranslatef(225, 80, 0);
    glScalef(25, 25, 1);
    desenhaQuadrado();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.361, 0.161, 0.024);
    glTranslatef(225, 80, 0);
    glScalef(30, 3, 1);
    desenhaQuadrado();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.361, 0.161, 0.024);
    glTranslatef(225, 80, 0);
    glScalef(3, 30, 1);
    desenhaQuadrado();
    glPopMatrix();

    //Nuvem

    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslatef(180, 230, 0);
    glScalef(10, 10, 1);
    desenhaCirculo();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslatef(190, 230, 0);
    glScalef(15, 15, 1);
    desenhaCirculo();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslatef(200, 230, 0);
    glScalef(10, 10, 1);
    desenhaCirculo();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1, 1, 1);
    glTranslatef(210, 230, 0);
    glScalef(5, 5, 1);
    desenhaCirculo();
    glPopMatrix();

    // Executa os comandos OpenGL
    glutSwapBuffers();
}

// Inicializa parâmetros de rendering
void Inicializa (void)
{
    // Define a cor de fundo da janela de visualização como preta
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

// Função callback chamada quando o tamanho da janela é alterado
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
    // Evita a divisao por zero
    if(h == 0) h = 1;

    // Especifica as dimensões da Viewport
    glViewport(0, 0, w, h);

    // Inicializa o sistema de coordenadas
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Estabelece a janela de seleção (left, right, bottom, top)
    // Se a largura da janela, em pixels, for menor que a altura, a largura da viewport é fixada em 250 e a altura é escalada para o necessário
    if (w <= h)  {
        windowHeight = 250.0f*h/w;
                windowWidth = 250.0f;
    }
    else  {
    // Se a altura da janela, em pixels, for menor que a largura, a altura da viewport é fixada em 250 e a largura é escalada para o necessário
                windowWidth = 250.0f*w/h;
                windowHeight = 250.0f;
    }

    // As dimensões da janela vão de (0.0, 0.0) até (windowWidth, windowHeight), essas são as coordenadas da tela
    gluOrtho2D(0.0f, windowWidth, 0.0f, windowHeight);
}

// Programa Principal
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(400,350);
    glutInitWindowPosition(10,10);
    glutCreateWindow("Minha Casa");
    glutDisplayFunc(Desenha);
    glutReshapeFunc(AlteraTamanhoJanela);
    Inicializa();
    glutMainLoop();
    return 0;
}