/*
Erick Paniagua Trejo
Visual Studio 2017
Gpo 2
Simulación de átomo sin lunas
*/
#include "Main.h"

// Variables used to calculate frames per second: (Windows)
DWORD dwFrames = 0;
DWORD dwCurrentTime = 0;
DWORD dwLastUpdateTime = 0;
DWORD dwElapsedTime = 0;

//Variables used to create movement

int sol = 0;
int mercurio = 0;
int anillo_merc = 0;
int venus = 0;
int tierra = 0;
int anillo_tie = 0;
int luna = 0;
int jupiter = 0;
int anillo_jup = 0;
int saturno = 0;
int anillo_sat = 0;

int urano = 0;
int neptuno = 0;


float camaraZ = 0.0;
float camaraX = 0.0;

GLfloat SunDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };			// Diffuse Light Values
GLfloat SunSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat SunPosition[] = { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position

GLfloat EarthDiffuse[] = { 0.2f, 0.2f, 1.0f, 1.0f };			// Tierra
GLfloat EarthSpecular[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat EarthShininess[] = { 50.0 };

GLfloat MoonDiffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };			// Luna
GLfloat MoonSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat MoonShininess[] = { 50.0 };

GLfloat MarsDiffuse[] = { 0.8f, 0.4f, 0.1f, 1.0f };			// Marte
GLfloat MarsSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat MarsShininess[] = { 50.0 };

void InitGL(GLvoid)     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);


}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(camaraX, 0.0, -5.0 + camaraZ);			//camara

	glPushMatrix();	//Sistema Solar

	glPushMatrix(); //Sol
	glRotatef(sol, 0.0, 1.0, 0.0);	//El Sol gira sobre su eje
	glColor3f(1.0, 1.0, 0.0);	//Sol amarillo
	glutSolidSphere(1.9, 12, 12);  //Draw Sun (radio,H,V);

	glPopMatrix(); //Fin Sol

	glPushMatrix(); // Mercurio
	glRotatef(mercurio, 0, 0, 1); //Traslación Va antes del pivote, del primer translate
	glTranslatef(4, 0, 0); // Se aleja 8 unidades del Sol
	glColor3f(1, 0.468, 0.078); // Color naranja
	//glRotatef(mercurio, 0, 1, 0);  //Rotación va antes de crear la figura para que gire en su propio eje
	glutSolidSphere(1.0, 12, 12); // Se crea la figura

	glPushMatrix(); // Anillo Mercurio
	glRotatef(anillo_merc, 0, 1, 0); //Traslación Va antes del pivote, del primer translate
	glTranslatef(0, 0, 0); // Se aleja 0 unidades de Saturno
	glColor3f(1, 1, 1); // Color café
	glRotatef(90, 0, 0, 1);  //Rotación va antes de crear la figura para que gire en su propio eje
	glutSolidTorus(0.5, 0.75, 10, 10); // Se crea la figura
	glRotatef(0, 0, 0, 0);
	glTranslatef(2.5, 0, 0); // Se aleja 10.5 unidades del Sol
	glPopMatrix(); // Fin Anillo Mercurio
	glPopMatrix(); // Fin Mercurio

	glPushMatrix(); // Venus
	glRotatef(venus, 0, 1, 0); //Traslación Va antes del pivote, del primer translate
	glTranslatef(4, 0, 0); // Se aleja 8 unidades del Sol
	glColor3f(0.9, 0.8, 0.4); // Color amarillo
	glRotatef(venus, 0, 1, 0);  //Rotación va antes de crear la figura para que gire en su propio eje
	glutSolidSphere(1.0, 12, 12); // Se crea la figura

	glPushMatrix(); // Anillo Venus
	glRotatef(anillo_sat, 0, 1, 0); //Traslación Va antes del pivote, del primer translate
	glTranslatef(0, 0, 0); // Se aleja 0 unidades de Saturno
	glColor3f(1, 1, 1); // Color café
	glRotatef(90, 1, 0, 0);  //Rotación va antes de crear la figura para que gire en su propio eje
	glutSolidTorus(0.5, 0.75, 10, 10); // Se crea la figura
	glRotatef(anillo_sat, 1, 0, 0);
	glTranslatef(2.5, 0, 0); // Se aleja 10.5 unidades del Sol
	glPopMatrix(); // Fin Anillo Venus
	glPopMatrix(); // Fin Venus

	glPushMatrix(); // Tierra
	glRotatef(tierra, 0, 0, 1); //Traslación Va antes del pivote, del primer translate
	glTranslatef(4.0, 0, 0); // Se aleja 9.5 unidades del Sol
	glColor3f(0.0, 0.0, 0.9); // Color amarillo
	//glRotatef(tierra, 1, 0, 0);  //Rotación va antes de crear la figura para que gire en su propio eje
	glutSolidSphere(0.30, 12, 12); // Se crea la figura

	glPushMatrix(); // Anillo Tierra
	glRotatef(anillo_tie, 0, 1, 0); //Traslación Va antes del pivote, del primer translate
	glTranslatef(0, 0, 0); // Se aleja 3.5 unidades de la tierra
	glColor3f(1, 1, 1); // Color blanco
	glRotatef(anillo_tie, 0, 1, 0);  //Rotación va antes de crear la figura para que gire en su propio eje
	glutSolidTorus(0.1, 0.3, 12, 12); // Se crea la figura
	glRotatef(0, 0, 0, 0);
	glTranslatef(2.5, 0, 0); // Se aleja 10.5 unidades del Sol
	glPopMatrix(); // Fin Anillo Tierra

	glPopMatrix(); // Fin Tierra

	glPushMatrix(); // Jupiter
	glRotatef(jupiter, 0, 0, 1); //Traslación Va antes del pivote, del primer translate
	glTranslatef(4, 0, 0); // Se aleja 4 unidades del Sol
	glColor3f(0.239, 0.127, 0.026); // Color amarillo
	glutSolidSphere(1.0, 12, 12); // Se crea la figura
	//glRotatef(jupiter, 0, 1, 0);  //Rotación va antes de crear la figura para que gire en su propio eje

	glPushMatrix(); // Anillo Jupiter
	glRotatef(anillo_jup, 0, 1, 0); //Traslación Va antes del pivote, del primer translate
	glTranslatef(0, 0, 0); // Se aleja 0 unidades de Saturno
	glColor3f(1, 1, 1); // Color blanco
	glRotatef(anillo_jup, 0, 0, 1);  //Rotación va antes de crear la figura para que gire en su propio eje
	glutSolidTorus(0.5, 0.75, 10, 10); // Se crea la figura
	glRotatef(anillo_jup, 0, 1, 0);
	glTranslatef(2.5, 0, 0); // Se aleja 10.5 unidades del Sol
	glPopMatrix(); // Fin Anillo Jupiter

	glPopMatrix(); // Fin Jupiter



	glPushMatrix(); // Saturno
	glRotatef(saturno, 0, 1, 0); //Traslación Va antes del pivote, del primer translate
	glTranslatef(4, 0, 0); // Se aleja 12 unidades del Sol
	glColor3f(0.900, 0.500, 0.000); // Color amarillo
	glRotatef(saturno, 0, 1, 0);  //Rotación va antes de crear la figura para que gire en su propio eje
	glutSolidSphere(1.0, 12, 12); // Se crea la figura

	glPushMatrix(); // Anillo Saturno
	glRotatef(anillo_sat, 0, 1, 0); //Traslación Va antes del pivote, del primer translate
	glTranslatef(0, 0, 0); // Se aleja 0 unidades de Saturno
	glColor3f(1, 1, 1); // Color café
	glRotatef(90, 1, 0, 0);  //Rotación va antes de crear la figura para que gire en su propio eje
	glutSolidTorus(0.5,0.75, 10, 10); // Se crea la figura
	glRotatef(anillo_sat, 1, 0, 0);
	glTranslatef(2.5, 0, 0); // Se aleja 10.5 unidades del Sol
	glPopMatrix(); // Fin Anillo Saturno

	glPopMatrix(); // Fin Saturno

	glPushMatrix(); // Urano
	glRotatef(urano, 0, 1, 0); //Traslación Va antes del pivote, del primer translate
	glTranslatef(4, 0, 0); // Se aleja 13 unidades del Sol
	glColor3f(0.0, 0.0, 0.7); // Color azul
	glRotatef(urano, 0, 1, 0);  //Rotación va antes de crear la figura para que gire en su propio eje
	glutSolidSphere(1.0, 12, 12); // Se crea la figura

	glPushMatrix(); // Anillo Urano
	glRotatef(anillo_sat, 0, 1, 0); //Traslación Va antes del pivote, del primer translate
	glTranslatef(0, 0, 0); // Se aleja 0 unidades de Saturno
	glColor3f(1, 1, 1); // Color café
	glRotatef(90, 1, 0, 0);  //Rotación va antes de crear la figura para que gire en su propio eje
	glutSolidTorus(0.5, 0.75, 10, 10); // Se crea la figura
	glRotatef(anillo_sat, 1, 0, 0);
	glTranslatef(2.5, 0, 0); // Se aleja 10.5 unidades del Sol
	glPopMatrix(); // Fin Anillo Urano

	glPopMatrix(); // Fin Urano

	glPushMatrix(); // Neptuno
	glRotatef(neptuno, 0, 1, 0); //Traslación Va antes del pivote, del primer translate
	glTranslatef(5, 0, 0); // Se aleja 13 unidades del Sol
	glColor3f(0.0, 0.0, 0.9); // Color azul
	glRotatef(neptuno, 0, 1, 0);  //Rotación va antes de crear la figura para que gire en su propio eje
	glutSolidSphere(0.75, 12, 12); // Se crea la figura

	glPushMatrix(); // Anillo Neptuno
	glRotatef(anillo_sat, 0, 1, 0); //Traslación Va antes del pivote, del primer translate
	glTranslatef(0, 0, 0); // Se aleja 0 unidades de Saturno
	glColor3f(1, 1, 1); // Color café
	glRotatef(90, 1, 0, 0);  //Rotación va antes de crear la figura para que gire en su propio eje
	glutSolidTorus(0.5, 0.75, 10, 10); // Se crea la figura
	glRotatef(anillo_sat, 1, 0, 0);
	glTranslatef(2.5, 0, 0); // Se aleja 10.5 unidades del Sol
	glPopMatrix(); // Fin Anillo Neptuno


	glPopMatrix(); // Fin Neptuno

	glPopMatrix(); // Fin Sistema Solar

	glutSwapBuffers();

}

void animacion()
{
	// Calculate the number of frames per one second:
	//dwFrames++;
	dwCurrentTime = GetTickCount(); // Even better to use timeGetTime()
	dwElapsedTime = dwCurrentTime - dwLastUpdateTime;

	if (dwElapsedTime >= 30)
	{
		sol = (sol - 5) % 360;

		dwLastUpdateTime = dwCurrentTime;
	}


	if (dwElapsedTime >= 30)
	{
		mercurio = (mercurio - 10) % 360;

		dwLastUpdateTime = dwCurrentTime;
	}

	if (dwElapsedTime >= 30)
	{
		venus = (venus - 7) % 360;

		dwLastUpdateTime = dwCurrentTime;
	}

	if (dwElapsedTime >= 30)
	{
		tierra = (tierra - 5) % 360;

		dwLastUpdateTime = dwCurrentTime;
	}

	if (dwElapsedTime >= 30)
	{
		luna = (luna - 1) % 360;

		dwLastUpdateTime = dwCurrentTime;
	}

	if (dwElapsedTime >= 30)
	{
		jupiter = (jupiter - 6) % 360;

		dwLastUpdateTime = dwCurrentTime;
	}


	if (dwElapsedTime >= 30)
	{
		saturno = (saturno - 6) % 360;

		dwLastUpdateTime = dwCurrentTime;
	}

	if (dwElapsedTime >= 30)
	{
		anillo_sat = (anillo_sat - 1) % 360;

		dwLastUpdateTime = dwCurrentTime;
	}

	if (dwElapsedTime >= 30)
	{
		urano = (urano - 3) % 360;

		dwLastUpdateTime = dwCurrentTime;
	}



	if (dwElapsedTime >= 30)
	{
		neptuno = (neptuno - 1) % 360;

		dwLastUpdateTime = dwCurrentTime;
	}

	glutPostRedisplay();
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

	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
														//glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {
	case 'w':   //Movimientos de camara
	case 'W':
		camaraZ += 0.5f;
		break;
	case 's':
	case 'S':
		camaraZ -= 0.5f;
		break;
	case 'a':
	case 'A':
		camaraX -= 0.5f;
		break;
	case 'd':
	case 'D':
		camaraX += 0.5f;
		break;

	case 'i':		//Movimientos de Luz
	case 'I':

		break;
	case 'k':
	case 'K':

		break;

	case 'l':   //Activamos/desactivamos luz
	case 'L':
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

		break;
	case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...

		break;
	case GLUT_KEY_LEFT:

		break;
	case GLUT_KEY_RIGHT:

		break;
	default:
		break;
	}
	glutPostRedisplay();
}


int main(int argc, char** argv)   // Main Function
{
	glutInit(&argc, argv); // Inicializamos OpenGL
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
	glutInitWindowSize(500, 500);	// Tamaño de la Ventana
	glutInitWindowPosition(20, 60);	//Posicion de la Ventana
	glutCreateWindow("Practica 6"); // Nombre de la Ventana
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutIdleFunc(animacion);
	glutMainLoop();          // 

	return 0;
}




