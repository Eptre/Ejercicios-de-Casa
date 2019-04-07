/*
Erick Paniagua Trejo
Gpo 2
Visual Studio 2017
Práctica 9 "Transparencia"

Usar tecla S o W para moverse de manera vertical
No pude obtener la transparencia debido a que no entendí por qué añadiendo el canal alfa en GIMP no 
funcionaba.
*/
#include "texture.h"

float pos_camX = 0, pos_camY = 0, pos_camZ = -5; 
int eye_camX = 0, eye_camY = 0.0, eye_camZ = 0;


GLfloat Diffuse[]= { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[]= { 0.0f, 3.0f, 0.0f, 1.0f };			// Light Position
GLfloat Position2[]= { 0.0f, -5.0f, 0.0f, 1.0f };			// Light Position


CTexture t_Ajedrez1;
CTexture t_Ajedrez2;
CTexture t_metal01;
CTexture t_Cubo;
CTexture respaldo;


int font=(int)GLUT_BITMAP_TIMES_ROMAN_24;



void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.5f, 0.5f, 0.8f, 0.0f);				// Azul de fondo	

	glEnable(GL_TEXTURE_2D);

	//glShadeModel (GL_SMOOTH);
	glLightfv(GL_LIGHT0, GL_POSITION, Position);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);
	

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	t_Ajedrez1.LoadTGA("01.tga");
	t_Ajedrez1.BuildGLTexture();
	t_Ajedrez1.ReleaseImage();

	t_metal01.LoadBMP("metal2.bmp");
	t_metal01.BuildGLTexture();
	t_metal01.ReleaseImage();

	t_Ajedrez2.LoadTGA("02.tga");
	t_Ajedrez2.BuildGLTexture();
	t_Ajedrez2.ReleaseImage();

	t_Cubo.LoadBMP("Cubo.bmp");
	t_Cubo.BuildGLTexture();
	t_Cubo.ReleaseImage();

	t_Cubo.LoadTGA("respaldo__1.tga");
	t_Cubo.BuildGLTexture();
	t_Cubo.ReleaseImage();
}


void renderBitmapCharacter(float x, float y, float z, void *font,char *string)
{
  
  char *c;     //Almacena los caracteres a escribir
  glRasterPos3f(x, y, z);	//Posicion apartir del centro de la ventana
  //glWindowPos2i(150,100);
  for (c=string; *c != '\0'; c++) //Condicion de fin de cadena
  {
    glutBitmapCharacter(font, *c); //imprime
  }
}



void prisma (GLuint textura1, GLuint textura2)  //Funcion creacion prisma
{

	GLfloat vertice [8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
				};

	glBindTexture(GL_TEXTURE_2D, textura2);   // choose the texture to use.
	glBegin(GL_POLYGON);	//Front
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[1]);
	glEnd();

	glBegin(GL_POLYGON);	//Right
	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);	//Back
	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Left
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Bottom
	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[2]);
	glTexCoord2f(0.0f, 1.0f); glVertex3fv(vertice[3]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura1);   // choose the texture to use.
	glBegin(GL_POLYGON);  //Top
	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(1.0, 0.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(1.0, 1.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(0.0, 1.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[7]);
	glEnd();
		
}


void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();

	glPushMatrix();
	glTranslatef(pos_camX, pos_camY, pos_camZ);
		glRotatef(eye_camX, 1.0, 0.0, 0.0);
		glRotatef(eye_camY, 0.0, 1.0, 0.0);
		glRotatef(eye_camZ, 0.0, 0.0, 1.0);
	
		glPushMatrix(); // Cuadrado
			glColor3f(1.0, 1.0, 1.0);
			glScalef(1, 1, 0.5);
			prisma(t_metal01.GLindex,t_metal01.GLindex);
		glPopMatrix(); // Fin Cuadrado

		glPushMatrix(); // Soporte
			glTranslatef(0.0, 0, 1.25);
			glColor3f(1, 1, 1);
			glScalef(0.05, 0.05, 2);
			prisma(t_metal01.GLindex, t_metal01.GLindex);
		glPopMatrix(); // Fin Soporte

		glPushMatrix(); //Piso
			glTranslatef(0, 0, 2.25);
			glColor3f(1, 1, 1);
			glScalef(2.5, 2.5, 0.05);
			prisma(t_metal01.GLindex, t_metal01.GLindex);
		glPopMatrix(); // Fin Piso

		// Primera fila del tablero

		glPushMatrix(); //		1/4
			glTranslatef(-0.25, -0.25, -0.25);
			glColor3f(1, 1, 1);
			glScalef(0.1, 0.1, 0.005);
			prisma(t_Ajedrez2.GLindex, t_Ajedrez2.GLindex);
		glPopMatrix();

		glPushMatrix(); //		2/4
			glTranslatef(-0.15, -0.25, -0.25);
			glColor3f(1, 1, 1);
			glScalef(0.1, 0.1, 0.005);
			prisma(t_Ajedrez2.GLindex, t_Ajedrez2.GLindex);
		glPopMatrix();

		glPushMatrix(); //		3/4
		glTranslatef(-0.05, -0.25, -0.25);
		glColor3f(1, 1, 1);
		glScalef(0.1, 0.1, 0.005);
		prisma(t_Ajedrez2.GLindex, t_Ajedrez2.GLindex);
		glPopMatrix();

		glPushMatrix(); //		4/4
		glTranslatef(0.05, -0.25, -0.25);
		glColor3f(1, 1, 1);
		glScalef(0.1, 0.1, 0.005);
		prisma(t_Ajedrez2.GLindex, t_Ajedrez2.GLindex);
		glPopMatrix();

		// Segunda fila del tablero 

		glPushMatrix(); //		1/4
		glTranslatef(0.05, -0.15, -0.25);
		glColor3f(1, 1, 1);
		glScalef(0.1, 0.1, 0.005);
		prisma(t_Ajedrez2.GLindex, t_Ajedrez2.GLindex);
		glPopMatrix();

		glPushMatrix(); //		2/4
		glTranslatef(-0.05, -0.15, -0.25);
		glColor3f(1, 1, 1);
		glScalef(0.1, 0.1, 0.005);
		prisma(t_Ajedrez2.GLindex, t_Ajedrez2.GLindex);
		glPopMatrix();

		glPushMatrix(); //		3/4
		glTranslatef(-0.15, -0.15, -0.25);
		glColor3f(1, 1, 1);
		glScalef(0.1, 0.1, 0.005);
		prisma(t_Ajedrez2.GLindex, t_Ajedrez2.GLindex);
		glPopMatrix();

		glPushMatrix(); //		4/4
		glTranslatef(-0.25, -0.15, -0.25);
		glColor3f(1, 1, 1);
		glScalef(0.1, 0.1, 0.005);
		prisma(t_Ajedrez2.GLindex, t_Ajedrez2.GLindex);
		glPopMatrix();

		// Tercera fila del tablero 

		glPushMatrix(); //		1/4
		glTranslatef(-0.25, -0.05, -0.25);
		glColor3f(1, 1, 1);
		glScalef(0.1, 0.1, 0.005);
		prisma(t_Ajedrez2.GLindex, t_Ajedrez2.GLindex);
		glPopMatrix();

		glPushMatrix(); //		2/4
		glTranslatef(-0.15, -0.05, -0.25);
		glColor3f(1, 1, 1);
		glScalef(0.1, 0.1, 0.005);
		prisma(t_Ajedrez2.GLindex, t_Ajedrez2.GLindex);
		glPopMatrix();

		glPushMatrix(); //		3/4
		glTranslatef(-0.05, -0.05, -0.25);
		glColor3f(1, 1, 1);
		glScalef(0.1, 0.1, 0.005);
		prisma(t_Ajedrez2.GLindex, t_Ajedrez2.GLindex);
		glPopMatrix();

		glPushMatrix(); //		4/4
		glTranslatef(0.05, -0.05, -0.25);
		glColor3f(1, 1, 1);
		glScalef(0.1, 0.1, 0.005);
		prisma(t_Ajedrez2.GLindex, t_Ajedrez2.GLindex);
		glPopMatrix();

		// Cuarta fila del tablero

		glPushMatrix(); //		1/4
		glTranslatef(0.05, 0.05, -0.25);
		glColor3f(1, 1, 1);
		glScalef(0.1, 0.1, 0.005);
		prisma(t_Ajedrez2.GLindex, t_Ajedrez2.GLindex);
		glPopMatrix();

		glPushMatrix(); //		2/4
		glTranslatef(-0.05, 0.05, -0.25);
		glColor3f(1, 1, 1);
		glScalef(0.1, 0.1, 0.005);
		prisma(t_Ajedrez2.GLindex, t_Ajedrez2.GLindex);
		glPopMatrix();

		glPushMatrix(); //		3/4
		glTranslatef(-0.15, 0.05, -0.25);
		glColor3f(1, 1, 1);
		glScalef(0.1, 0.1, 0.005);
		prisma(t_Ajedrez2.GLindex, t_Ajedrez2.GLindex);
		glPopMatrix();

		glPushMatrix(); //		4/4
		glTranslatef(-0.25, 0.05, -0.25);
		glColor3f(1, 1, 1);
		glScalef(0.1, 0.1, 0.005);
		prisma(t_Ajedrez2.GLindex, t_Ajedrez2.GLindex);
		glPopMatrix();

		glPushMatrix(); //cuadrado silla 1
		glTranslatef(1, 0, 0.5);
		glColor3f(1, 1, 1);
		glScalef(0.5, 1.0, 0.3);
		prisma(t_metal01.GLindex, t_metal01.GLindex);
		glPopMatrix(); //fin cuadrado silla 1

		glPushMatrix(); //respaldo silla 1 ///////////////////////////
		glEnable(GL_ALPHA_TEST);
		glAlphaFunc(GL_GREATER, 0.1);
		glTranslatef(1.5, 0, -0.3);
		glColor3f(1, 1, 1);
		glScalef(0.5, 1.0, 1.5);
		prisma(t_metal01.GLindex, respaldo.GLindex);
		glDisable(GL_ALPHA_TEST);
		glPopMatrix(); //fin respaldo silla 1 /////////////////////////////

		glPushMatrix(); //soporte silla 1
		glTranslatef(1.0, 0, 1.5);
		glColor3f(1, 1, 1);
		glScalef(0.05, 0.05, 1.6);
		prisma(t_metal01.GLindex, t_metal01.GLindex);
		glPopMatrix(); //fin soporte silla 1

		//////////////////////////////////////////////////////////////////////

		glPushMatrix(); //cuadrado silla 1
		glTranslatef(-1, 0, 0.5);
		glColor3f(1, 1, 1);
		glScalef(0.5, 1.0, 0.3);
		prisma(t_metal01.GLindex, t_metal01.GLindex);
		glPopMatrix(); //fin cuadrado silla 1

		glPushMatrix(); //respaldo silla 1
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glTranslatef(-1.5, 0, -0.3);
		glColor3f(1, 1, 1);
		glScalef(0.5, 1.0, 1.5);
		prisma(t_metal01.GLindex, respaldo.GLindex);
		glDisable(GL_BLEND);
		glPopMatrix(); //fin respaldo silla 1

		glPushMatrix(); //soporte silla 1
		glTranslatef(-1.0, 0, 1.5);
		glColor3f(1, 1, 1);
		glScalef(0.05, 0.05, 1.6);
		prisma(t_metal01.GLindex, t_metal01.GLindex);
		glPopMatrix(); //fin soporte silla 1


		///////////////////////////////////////////////////////////////////////




	glPopMatrix();
	glDisable(GL_TEXTURE_2D);
		renderBitmapCharacter(-11, 12.0, -14.0, (void *)font, "Practica 9");
		renderBitmapCharacter(-11, 10.5, -14, (void *)font, "Transparencia");
	glEnable(GL_TEXTURE_2D);

	glutSwapBuffers ( );

}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void animacion()
{
	

	glutPostRedisplay();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':   //Movimientos de camara
		case 'W':
			pos_camZ += 0.5f;
			//eye_camZ -= 0.5f;
			break;

		case 's':
		case 'S':
			pos_camZ -= 0.5f;
			//eye_camZ += 0.5f;
			break;

		case 'a':
		case 'A':
			pos_camX += 0.5f;
			//eye_camX -= 0.5f;
			break;
		case 'd':
		case 'D':
			pos_camX -= 0.5f;
			//eye_camX += 0.5f;
			break;

		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
			break;        
		default:        // Cualquier otra
			break;
  }
	glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
	case GLUT_KEY_PAGE_UP:
		pos_camY -= 0.5f;
		//eye_camY += 0.5f;
		break;

	case GLUT_KEY_PAGE_DOWN:
		pos_camY += 0.5f;
		//eye_camY -= 0.5f;
		break;

    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		eye_camX = (eye_camX-15) % 360;
		break;

    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		eye_camX = (eye_camX+15) % 360;
		break;

	case GLUT_KEY_LEFT:
		eye_camY = (eye_camY-15) % 360;
		break;

	case GLUT_KEY_RIGHT:
		eye_camY = (eye_camY+15) % 360;
		break;
    default:
      break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (5000, 5000);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 8"); // Nombre de la Ventana
  //glutFullScreen     ( );         // Full Screen
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );
  glutMainLoop        ( );          // 

  return 0;
}