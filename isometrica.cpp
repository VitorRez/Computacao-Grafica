// Este c�digo est� baseado nos exemplos dispon�veis no livro 
// "OpenGL SuperBible", 2nd Edition, de Richard S. e Wright Jr.

#include <GL/glut.h>

GLint width = 640, height = 480;
GLfloat fAspect = (float)width/(float)height;
GLint isometrica;
GLfloat tx=0.0f, tz=0.0f;

void DesenhaEixos(void)
{
	glBegin(GL_LINES);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(100.0f, 0.0f, 0.0f);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 100.0f, 0.0f);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 0.0f, 100.0f);
	glEnd();
}
            
// Fun��o callback chamada para fazer o desenho
void Desenha(void)
{
	// Especifica sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);
	// Inicializa sistema de coordenadas do modelo
	glLoadIdentity();

    // Limpa a janela e o depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
    //Posisiona a c�mera em vis�o isom�trica (https://en.wikipedia.org/wiki/Isometric_projection)
    if(isometrica==1) {
        glRotatef(35.264f, 1, 0, 0); 
        glRotatef(-45.0f, 0, 1, 0);
    }
    
	//Desenha os eixos b�sicos na origem
	DesenhaEixos();

    for(int i = -10; i < 10; i++) {
        for(int j = -10; j < 10; j++) {
            if((j+i)%2==0)
    	        glColor3f(0.25f, 0.25f, 0.25f);
    	    else
    	        glColor3f(0.75f, 0.75f, 0.75f);
            // Desenha o cubo com a cor corrente (solid)
            glPushMatrix();
	            glTranslatef(i*20.0f, 0.0f, j*20.0f);
	            glutSolidCube(20.0f);
	            //DesenhaEixos();
            glPopMatrix();
        }        
	}

	glColor3f(1.0f, 0.0f, 0.0f);
	// Desenha a esfera com a cor corrente (solid)
	glPushMatrix();
		glTranslatef(-60.0f, 25.0f, 0.0f);
		glutSolidSphere(20.0f, 10, 10);
		//DesenhaEixos();
	glPopMatrix();
	
	glColor3f(0.0f, 0.0f, 1.0f);
	// Desenha o teapot com a cor corrente (solid)
	glPushMatrix();
		glTranslatef(tx, 20.0f, tz);
		glutSolidTeapot(10.0f);
		//DesenhaEixos();
	glPopMatrix();


	glutSwapBuffers();
}

// Inicializa par�metros de rendering
void Inicializa (void)
{ 
	GLfloat luzAmbiente[4]={0.2,0.2,0.2,1.0}; 
	GLfloat luzDifusa[4]={0.7,0.7,0.7,1.0};		 // "cor" 
	GLfloat luzEspecular[4]={1.0, 1.0, 1.0, 1.0};// "brilho" 
	GLfloat posicaoLuz[4]={0.0, 50.0, 50.0, 1.0};

	// Capacidade de brilho do material
	GLfloat especularidade[4]={1.0,1.0,1.0,1.0}; 
	GLint especMaterial = 60;

 	// Especifica que a cor de fundo da janela ser� preta
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	
	// Habilita o modelo de coloriza��o de Gouraud
	glShadeModel(GL_SMOOTH);

	// Define a reflet�ncia do material 
	glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);
	// Define a concentra��o do brilho
	glMateriali(GL_FRONT,GL_SHININESS,especMaterial);

	// Ativa o uso da luz ambiente 
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);

	// Define os par�metros da luz de n�mero 0
	glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente); 
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa );
	glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular );
	glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz );

	// Habilita a defini��o da cor do material a partir da cor corrente
	glEnable(GL_COLOR_MATERIAL);
	//Habilita o uso de ilumina��o
	glEnable(GL_LIGHTING);  
	// Habilita a luz de n�mero 0
	glEnable(GL_LIGHT0);
	// Habilita o depth-buffering
	glEnable(GL_DEPTH_TEST);
}

// Fun��o usada para especificar o volume de visualiza��o
void EspecificaParametrosVisualizacao(void)
{
	// Especifica sistema de coordenadas de proje��o
	glMatrixMode(GL_PROJECTION);
	// Inicializa sistema de coordenadas de proje��o
	glLoadIdentity();

	// Especifica a proje��o perspectiva
    //gluPerspective(angle,fAspect,0.4,500);
    int scale=200;
    glOrtho(-fAspect*scale, fAspect*scale, -scale, scale, -10*scale, 10*scale);
    //glOrtho(-scale, scale, -scale, scale, -scale, scale);
}

// Fun��o callback chamada quando o tamanho da janela � alterado 
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
	// Para previnir uma divis�o por zero
	if ( h == 0 ) h = 1;

	// Especifica o tamanho da viewport
    glViewport(0, 0, w, h);
 
	// Calcula a corre��o de aspecto
	fAspect = (GLfloat)w/(GLfloat)h;

	EspecificaParametrosVisualizacao();
}

// Fun��o callback chamada para gerenciar eventos de teclado
void GerenciaTeclado(unsigned char key, int x, int y)
{
    switch (key) {
            case 'Q': 
            case 'q':// muda a cor corrente para vermelho
                     isometrica=0;
                     break;
            case 'E':
            case 'e':// muda a cor corrente para verde
                     isometrica=1;
                     break;
            case 'A':
            case 'a':// muda a cor corrente para verde
                     tx-=20;
                     break;
            case 'D':
            case 'd':// muda a cor corrente para verde
                     tx+=20;
                     break;
            case 'W':
            case 'w':// muda a cor corrente para verde
                     tz-=20;
                     break;
            case 'S':
            case 's':// muda a cor corrente para verde
                     tz+=20;
                     break;
    }
    glutPostRedisplay();
}

// Programa Principal
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(width,height);
	glutCreateWindow("Visualizacao 3D");
	glutDisplayFunc(Desenha);
    glutReshapeFunc(AlteraTamanhoJanela);
	glutKeyboardFunc(GerenciaTeclado);
	Inicializa();
	glutMainLoop();
}

