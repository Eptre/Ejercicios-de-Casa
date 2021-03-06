/*
Erick Paniagua Trejo 
Grupo lab 02
Visual Studio 2017
Ejercicio Casa 3
Se dise�� personaje de space invaders. 
Con una funci�n llamada prisma para colocar los prismas con tama�o deseado. 
Para a�adir prismas del tama�o requerido s�lo se coloca: 
prisma(tama�o_base,tama�o_techo,altura); en el .cpp
Q para subir y E para bajar.*/

//#include <gl/gl.h>     // The GL Header File
//#include <GL/glut.h>   // The GL Utility Toolkit (Glut) Header
//#include <stdlib.h>
#include "Main.h"

float angleX = 0.0f;
float angleY = 0.0f;
float angleZ = 0.0f;
float transX = -1.0f;
float transY = -1.0f;
float transZ = -5.0f;

void InitGL(GLvoid)     // Inicializamos parametros
{

	//glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	//glEnable(GL_LIGHTING);
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	//glEnable ( GL_COLOR_MATERIAL );
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

///////////////////////////////////////////////////////////////////////
//////////////////******Funci�n Prisma Modificada******///////////////
void prisma(double base, double techo, double alto)
{
	GLfloat vertice[8][3] = {
				{base ,-alto,base},    //Coordenadas V�rtice 0 V0
				{-base ,-alto, base},    //Coordenadas V�rtice 1 V1
				{-base ,-alto, -base},    //Coordenadas V�rtice 2 V2
				{base ,-alto, -base},    //Coordenadas V�rtice 3 V3
				{techo ,alto, techo},    //Coordenadas V�rtice 4 V4
				{techo ,alto, -techo},    //Coordenadas V�rtice 5 V5
				{-techo ,alto, -techo},    //Coordenadas V�rtice 6 V6
				{-techo ,alto, techo},    //Coordenadas V�rtice 7 V7
	};


	glBegin(GL_QUADS);	//Front
	glColor3f(0.0, 1.0, 0.0);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[4]);
	glColor3f(0.0, 0.0, 1.0);
	glVertex3fv(vertice[7]);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3fv(vertice[1]);
	glEnd();

	glBegin(GL_QUADS);	//Right
	glColor3f(0.0, 1.0, 0.0);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_QUADS);	//Back
	glColor3f(0.0, 1.0, 0.0);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[3]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_QUADS);  //Left
	glColor3f(0.0, 1.0, 0.0);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[7]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_QUADS);  //Bottom

	glColor3f(0.0, 1.0, 0.0);
	glVertex3fv(vertice[0]);
	glVertex3fv(vertice[1]);
	glVertex3fv(vertice[2]);
	glVertex3fv(vertice[3]);
	glEnd();

	glBegin(GL_QUADS);  //Top
	glColor3f(0.0, 0.1, 0.0);
	glVertex3fv(vertice[4]);
	glVertex3fv(vertice[5]);
	glVertex3fv(vertice[6]);
	glVertex3fv(vertice[7]);
	glEnd();
}



void display(void)   // Creamos la funcion donde se dibuja
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limpiamos pantalla y Depth Buffer
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	//Poner C�digo Aqu�.
	glTranslatef(transX, transY, transZ);
	glRotatef(45, angleX, angleY, angleZ);

	glTranslatef(-2.0f, -2.0f, -3.0f);
	prisma(0.6,0.6,0.4);

	glTranslatef(-1.0f, 2.0f, 0.0f);
	prisma(0.5, 0.5, 2.0);

	glTranslatef(-1.0f, 0.6f, 0.0f);
	prisma(0.5, 0.5, 0.7);

	glTranslatef(-1.0f, -1.0f, 0.0f);
	prisma(0.5, 0.5, 0.9);

	glTranslatef(4.0f, 2.0f, 0.0f);
	prisma(1.5, 1.5, 0.4);

	glTranslatef(2.0f,-1.5f, 0.0f);
	prisma(0.5, 0.5, 2.0);

	glTranslatef(-1.0f, -2.0f, 0.0f);
	prisma(0.6, 0.6, 0.4);

	glTranslatef(2.0f, 2.5f, 0.0f);
	prisma(0.5, 0.5, 0.7);

	glTranslatef(1.0f, -1.0, 0.0f);
	prisma(0.5, 0.5, 0.7);

	glTranslatef(-4.0f, 1.0f, 0.0f);
	prisma(0.3, 0.3, 1.0);

	glTranslatef(0.0f, -1.0f, -1.0f);
	prisma(1.4,1.4,0.3);

	glTranslatef(-1.0f, 3.0f, 0.0f);
	prisma(0.5, 0.5, 0.5);

	glTranslatef(-1.0f, 1.0f, 0.0f);
	prisma(0.5, 0.5, 0.5);

	glTranslatef(3.0f, -1.0f, 0.0f);
	prisma(0.5, 0.5, 0.5);

	glTranslatef(1.0f, 1.0f, 0.0f);
	prisma(0.5, 0.5, 0.5);

	glutSwapBuffers();
	//glFlush();
	// Swap The Buffers
}

void reshape(int width, int height)   // Creamos funcion Reshape
{
	if (height == 0)										// Prevenir division entre cero
	{
		height = 1;
	}

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	//glOrtho(-5, 5, -5, 5, 0.1, 20);
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {


	case 'Q':
	case 'q':
		transZ += 0.0f;
		transY += 0.2f;
		transX += 0.0f;
		break;
	case 'E':
	case 'e':
		transX += 0.0f;
		transY += -0.2f;
		transZ += 0.0f;
		break;

	case 'w':
	case 'W':
		transZ += 0.2f;
		printf("Posicion en Z: %f\n", transZ);
		break;
	case 's':
	case 'S':
		transZ -= 0.2f;
		printf("Posicion en Z: %f\n", transZ);
		break;
	case 'a':
	case 'A':
		transX -= 0.2f;
		break;
	case 'd':
	case 'D':
		transX += 0.2f;
		break;
	case 27:        // Cuando Esc es presionado...
		exit(0);   // Salimos del programa
		break;
	default:        // Cualquier otra
		break;
	}
	glutPostRedisplay();
}

void arrow_keys(int a_keys, int x, int y)  // Funcion para manejo de teclas especiales (arrow keys)
{
	switch (a_keys) {
	case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		angleX += 1.0f;
		break;
		//glutFullScreen ( ); // Full Screen Mode
		//break;
	case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		angleX -= 1.0f;
		break;
		//glutReshapeWindow ( 500, 500 ); // Cambiamos tamano de Ventana
		//break;
	case GLUT_KEY_LEFT:
		angleY += 1.0f;
		break;
	case GLUT_KEY_RIGHT:
		angleY -= 1.0f;
		break;
	default:
		break;
	}
	glutPostRedisplay();
}


int main(int argc, char** argv)   // Main Function
{
	glutInit(&argc, argv); // Inicializamos OpenGL
	//glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
	glutInitWindowSize(500, 500);	// Tama�o de la Ventana
	glutInitWindowPosition(0, 0);	//Posicion de la Ventana
	glutCreateWindow("Practica 3"); // Nombre de la Ventana
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut funci�n de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut funci�n en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut funci�n de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutMainLoop();          // 

	return 0;
}



