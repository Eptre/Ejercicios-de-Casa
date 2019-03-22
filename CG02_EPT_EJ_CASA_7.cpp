/*
Erick Paniagua Trejo
Visual Studio 2017
Gpo 2
Práctica 7 (CASA)
Materiales
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
int venus = 0;
int tierra = 0;
int luna = 0;
int marte = 0;
int luna_mar = 0;
int jupiter = 0;
int luna_jup = 0;
int luna_jup2 = 0;
int saturno = 0;
int anillo_sat = 0;
int anillo_sat2 = 0;
int urano = 0;
int luna_ura = 0;
int neptuno = 0;
int luna_nep = 0;
int luna_nep2 = 0;

float camaraZ = 0.0;
float camaraX = 0.0;

bool positional = true;

GLfloat SunDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };			// Diffuse Light Values
GLfloat SunSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat SunPosition[] = { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position

GLfloat EarthDiffuse[] = { 0.0f, 0.0f, 0.3f, 1.0f };		// Tierra
GLfloat EarthSpecular[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat EarthShininess[] = { 50.0 };

GLfloat MoonDiffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };			// Luna
GLfloat MoonSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat MoonShininess[] = { 50.0 };

GLfloat MarsDiffuse[] = { 0.8f, 0.4f, 0.1f, 1.0f };			// Marte
GLfloat MarsSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat MarsShininess[] = { 50.0 };

GLfloat MoonMarsDiffuse[] = { 0.1f, 0.3f, 0.0f, 1.0f }; 	// Luna Marte
GLfloat MoonMarsSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat MoonMarsShininess[] = { 50.0 };


GLfloat MercDiffuse[] = { 0.5f, 0.6f, 0.0f, 1.0f };			// Mercurio
GLfloat MercSpecular[] = { 0.70, 0.65, 0.65, 1.0 };
GLfloat MercShininess[] = { 50.0 };

GLfloat VenDiffuse[] = { 0.5f, 0.1f, 0.1f, 1.0f };			// Venus
GLfloat VenSpecular[] = { 0.6, 0.6, 0.4, 1.0 };
GLfloat VenShininess[] = { 50.0 };

GLfloat JupDiffuse[] = { 0.240f, 0.230f, 0.25f, 1.0f };			// Jupiter
GLfloat JupSpecular[] = { 0.8, 0.8, 0.7, 1.0 };
GLfloat JupShininess[] = { 50.0 };

GLfloat MoonJupDiffuse[] = { 0.300f, 0.100f, 0.15f, 1.0f };			// Luna 1 Jupiter
GLfloat MoonJupSpecular[] = { 0.3, 0.3, 0.3, 1.0 };
GLfloat MoonJupShininess[] = { 50.0 };

GLfloat Moon2JupDiffuse[] = { 0.200f, 0.230f, 0.5f, 1.0f };			// Luna 2 Jupiter
GLfloat Moon2JupSpecular[] = { 0.7, 0.7, 0.2, 1.0 };
GLfloat Moon2JupShininess[] = { 50.0 };

GLfloat SatDiffuse[] = { 0.500f, 0.200f, 0.35f, 1.0f };			// Saturno
GLfloat SatSpecular[] = { 0.4, 0.5, 0.6, 1.0 };
GLfloat SatShininess[] = { 50.0 };

GLfloat AnSatDiffuse[] = { 0.500f, 0.200f, 0.35f, 1.0f };			// Anillo Saturno
GLfloat AnSatSpecular[] = { 0.6, 0.6, 0.3, 1.0 };
GLfloat AnSatShininess[] = { 50.0 };

GLfloat An2SatDiffuse[] = { 0.500f, 0.200f, 0.35f, 1.0f };			// Anillo 2 Saturno
GLfloat An2SatSpecular[] = { 0.1, 0.1, 0.3, 1.0 };
GLfloat An2SatShininess[] = { 50.0 };

GLfloat UranoDiffuse[] = { 0.150f, 0.500f, 0.25f, 1.0f };			// Urano
GLfloat UranoSpecular[] = { 0.3, 0.3, 0.2, 1.0 };
GLfloat UranoShininess[] = { 50.0 };

GLfloat MoonUranoDiffuse[] = { 0.100f, 0.300f, 0.25f, 1.0f };			// Luna Urano
GLfloat MoonUranoSpecular[] = { 0.6, 0.5, 0.4, 1.0 };
GLfloat MoonUranoShininess[] = { 50.0 };

GLfloat NepDiffuse[] = { 0.140f, 0.120f, 0.500f, 1.0f };			// Neptuno
GLfloat NepSpecular[] = { 0.7, 0.7, 0.0, 1.0 };
GLfloat NepShininess[] = { 50.0 };

GLfloat MoonNepDiffuse[] = { 0.100f, 0.90f, 0.500f, 1.0f };			// Luna Neptuno
GLfloat MoonNepSpecular[] = { 0.5, 0.5, 0.0, 1.0 };
GLfloat MoonNepShininess[] = { 50.0 };

GLfloat Moon2NepDiffuse[] = { 0.300f, 0.390f, 0.600f, 1.0f };			// Luna 2 Neptuno
GLfloat Moon2NepSpecular[] = { 0.2, 0.2, 0.0, 1.0 };
GLfloat Moon2NepShininess[] = { 50.0 };

GLfloat LightAmbient[] = { 0.0f, 0.0f, 0.0f, 1.0f }; 			// Ambient Light Values
GLfloat LightDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };			// Diffuse Light Values
GLfloat LightSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat LightPosition[] = { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position

void InitGL(GLvoid)     // Inicializamos parametros

{

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient);				// Setup The Ambient Light
	glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse);				// Setup The Diffuse Light
	glLightfv(GL_LIGHT1, GL_SPECULAR, LightSpecular);				// Setup The Diffuse Light

	glEnable(GL_LIGHT1);
}

void display(void)   // Creamos la funcion donde se dibuja

{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(camaraX, 0.0, -5.0 + camaraZ);			//camara

	glLightfv(GL_LIGHT1, GL_POSITION, LightPosition);
	glEnable(GL_LIGHTING);

	glPushMatrix();	//Sistema Solar



	glPushMatrix(); //Sol
	glRotatef(sol, 0.0, 1.0, 0.0);	//El Sol gira sobre su eje
	glMaterialfv(GL_FRONT, GL_DIFFUSE, SunDiffuse); // Material Sol
	glMaterialfv(GL_FRONT, GL_SPECULAR, SunSpecular); // Material Sol
	glDisable(GL_LIGHTING);
	glColor3f(1.0, 1.0, 0.0);	//Sol amarillo
	glutSolidSphere(1.9, 12, 12);  //Draw Sun (radio,H,V);
	glEnable(GL_LIGHTING);
	glPopMatrix(); //Fin Sol

	glPushMatrix(); // Mercurio
	glRotatef(mercurio, 0, 1, 0); //Traslación Va antes del pivote, del primer translate
	glTranslatef(8, 0, 0); // Se aleja 8 unidades del Sol
	glColor3f(1, 0.468, 0.078); // Color naranja
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MercDiffuse); // Material Mercurio
	glMaterialfv(GL_FRONT, GL_SPECULAR, MercSpecular); // Material Mercurio
	glRotatef(mercurio, 0, 1, 0);  //Rotación va antes de crear la figura para que gire en su propio eje
	glutSolidSphere(0.5, 12, 12); // Se crea la figura
	glPopMatrix(); // Fin Mercurio



	glPushMatrix(); // Venus
	glRotatef(venus, 0, 1, 0); //Traslación Va antes del pivote, del primer translate
	glTranslatef(8, 0, 0); // Se aleja 8 unidades del Sol
	glColor3f(0.9, 0.8, 0.4); // Color amarillo
	glMaterialfv(GL_FRONT, GL_DIFFUSE, VenDiffuse); // Material Mercurio
	glMaterialfv(GL_FRONT, GL_SPECULAR, VenSpecular); // Material Mercurio
	glRotatef(venus, 0, 1, 0);  //Rotación va antes de crear la figura para que gire en su propio eje
	glutSolidSphere(0.8, 12, 12); // Se crea la figura
	glPopMatrix(); // Fin Venus



	glPushMatrix(); // Tierra
	glRotatef(tierra, 0, 1, 0); //Traslación Va antes del pivote, del primer translate
	glTranslatef(9.5, 0, 0); // Se aleja 9.5 unidades del Sol
	//glEnable(GL_LIGHTING); // Habilita la luz
	glColor3f(0.0, 0.0, 0.9); // Color amarillo
	glMaterialfv(GL_FRONT, GL_DIFFUSE, EarthDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, EarthSpecular);
	glRotatef(tierra, 0, 1, 0);  //Rotación va antes de crear la figura para que gire en su propio eje
	glutSolidSphere(0.95, 12, 12); // Se crea la figura



	glPushMatrix(); // Luna
	glRotatef(luna, 0, 1, 0); //Traslación Va antes del pivote, del primer translate
	glTranslatef(3.5, 0, 0); // Se aleja 3.5 unidades de la tierra
	glColor3f(1, 1, 1); // Color blanco
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonDiffuse); // Material Luna
	glMaterialfv(GL_FRONT, GL_SPECULAR, MoonSpecular); // Material Luna
	glRotatef(luna, 0, 1, 0);  //Rotación va antes de crear la figura para que gire en su propio eje
	glutSolidSphere(0.35, 12, 12); // Se crea la figura
	glRotatef(luna, 0, 1, 0);
	glTranslatef(2.5, 0, 0); // Se aleja 10.5 unidades del Sol
	glPopMatrix(); // Fin Luna

	glPopMatrix(); // Fin Tierra

	glPushMatrix(); // Marte
	glRotatef(marte, 0, 1, 0); // Traslación va antes del pivote, del primer translate
	glTranslatef(10, 0, 0); // Se aleja 10 unidades del Sol
	glColor3f(0.239, 0.127, 0.26); // Color naranja
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MarsDiffuse); // Material Marte
	glMaterialfv(GL_FRONT, GL_SPECULAR, MarsSpecular); // Material Marte
	glRotatef(marte, 0, 1, 0);
	glutSolidSphere(0.50, 0, 0); // Se crea la esfera

	glPushMatrix(); // Luna Marte
	glRotatef(luna_mar, 0, 1, 0); //Traslación Va antes del pivote, del primer translate
	glTranslatef(2.5, 0, 0); // Se aleja 3.5 unidades de la tierra
	glColor3f(0.200,150, 0.15); // Color naranja
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonMarsDiffuse); // Material Luna Marte
	glMaterialfv(GL_FRONT, GL_SPECULAR, MoonMarsSpecular); // Material Luna Marte
	glRotatef(luna_mar, 0, 1, 0);  //Rotación va antes de crear la figura para que gire en su propio eje
	glutSolidSphere(0.10, 12, 12); // Se crea la figura
	glRotatef(luna_mar, 0, 1, 0);
	glTranslatef(2.5, 0, 0); // 
	glPopMatrix(); // Fin Luna Marte

	glPopMatrix(); // Fin Marte

	glPushMatrix(); // Jupiter
	glRotatef(jupiter, 0, 1, 0); //Traslación Va antes del pivote, del primer translate
	glTranslatef(11, 0, 0); // Se aleja 9.5 unidades del Sol
	glColor3f(0.239, 0.127, 0.026); // Color amarillo
	glMaterialfv(GL_FRONT, GL_DIFFUSE, JupDiffuse); // Material Jupiter
	glMaterialfv(GL_FRONT, GL_SPECULAR, JupSpecular); // Material Jupiter
	glRotatef(jupiter, 0, 1, 0);  //Rotación va antes de crear la figura para que gire en su propio eje
	glutSolidSphere(1.0, 12, 12); // Se crea la figura

	glPushMatrix(); // Luna Jupiter
	glRotatef(luna_jup, 0, 1, 0); //Traslación Va antes del pivote, del primer translate
	glTranslatef(3.5, 0, 0); // Se aleja 3.5 unidades de la tierra
	glColor3f(0.435, 0.306, 0.216); // Color café
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonJupDiffuse); // Material Jupiter
	glMaterialfv(GL_FRONT, GL_SPECULAR, MoonJupSpecular); // Material Jupiter
	glRotatef(luna_jup, 0, 1, 0);  //Rotación va antes de crear la figura para que gire en su propio eje
	glutSolidSphere(0.25, 12, 12); // Se crea la figura
	glRotatef(luna_jup, 0, 1, 0);
	glTranslatef(2.5, 0, 0); // Se aleja 10.5 unidades del Sol
	glPopMatrix(); // Fin Luna Jupiter

	glPushMatrix(); // Luna Jupiter 2
	glRotatef(luna_jup2, 0, 1, 0); //Traslación Va antes del pivote, del primer translate
	glTranslatef(2.5, 0, 0); // Se aleja 2.5 unidades de Jupiter
	glColor3f(0.435, 0.306, 0.216); // Color café
	glMaterialfv(GL_FRONT, GL_DIFFUSE, Moon2JupDiffuse); // Material Jupiter
	glMaterialfv(GL_FRONT, GL_SPECULAR, Moon2JupSpecular); // Material Jupiter
	glRotatef(luna_jup2, 0, 1, 0);  //Rotación va antes de crear la figura para que gire en su propio eje
	glutSolidSphere(0.25, 12, 12); // Se crea la figura
	glRotatef(luna_jup2, 0, 1, 0);
	glTranslatef(2.5, 0, 0); // Se aleja 5.5 unidades de Jupiter
	glPopMatrix(); // Fin Luna Jupiter

	glPopMatrix(); // Fin Jupiter

	glPushMatrix(); // Saturno
	glRotatef(saturno, 0, 1, 0); //Traslación Va antes del pivote, del primer translate
	glTranslatef(12, 0, 0); // Se aleja 12 unidades del Sol
	glColor3f(0.900, 0.500, 0.000); // Color amarillo
	glMaterialfv(GL_FRONT, GL_DIFFUSE, SatDiffuse); // Material Saturno
	glMaterialfv(GL_FRONT, GL_SPECULAR, SatSpecular); // Material Saturno
	glRotatef(saturno, 0, 1, 0);  //Rotación va antes de crear la figura para que gire en su propio eje
	glutSolidSphere(1.0, 12, 12); // Se crea la figura

	glPushMatrix(); // Anillo Saturno

	glRotatef(anillo_sat, 0, 1, 0); //Traslación Va antes del pivote, del primer translate
	glTranslatef(0, 0, 0); // Se aleja 0 unidades de Saturno
	glColor3f(0.500, 0.245, 0.220); // Color café
	glMaterialfv(GL_FRONT, GL_DIFFUSE, AnSatDiffuse); // Material Anillo Saturno
	glMaterialfv(GL_FRONT, GL_SPECULAR, AnSatSpecular); // Material Anillo Saturno
	glRotatef(90, 1, 0, 0);  //Rotación va antes de crear la figura para que gire en su propio eje
	glutSolidTorus(0.5, 0.75, 10, 10); // Se crea la figura
	glRotatef(anillo_sat, 1, 0, 0);
	glTranslatef(2.5, 0, 0); // Se aleja 10.5 unidades del Sol
	glPopMatrix(); // Fin Anillo Saturno

	glPushMatrix(); // Anillo Saturno 2
	glRotatef(anillo_sat2, 0, 1, 0); //Traslación Va antes del pivote, del primer translate
	glTranslatef(0, 0, 0); // Se aleja 2.5 unidades de Jupiter
	glColor3f(0.500, 0.245, 0.0); // Color café
	glMaterialfv(GL_FRONT, GL_DIFFUSE, An2SatDiffuse); // Material Anillo 2 Saturno
	glMaterialfv(GL_FRONT, GL_SPECULAR, An2SatSpecular); // Material Anillo 2 Saturno
	glRotatef(60, 1, 0, 0);  //Rotación va antes de crear la figura para que gire en su propio eje
	glutSolidTorus(0.5, 1.0, 10, 10); // Se crea la figura
	glRotatef(anillo_sat2, 0, 1, 0);
	glTranslatef(2.5, 0, 0); // Se aleja 2.5 unidades de Jupiter
	glPopMatrix(); // Fin Anillo Saturno 2

	glPopMatrix(); // Fin Saturno



	glPushMatrix(); // Urano
	glRotatef(urano, 0, 1, 0); //Traslación Va antes del pivote, del primer translate
	glTranslatef(13, 0, 0); // Se aleja 13 unidades del Sol
	glColor3f(0.0, 0.0, 0.7); // Color azul
	glMaterialfv(GL_FRONT, GL_DIFFUSE, UranoDiffuse); // Material Urano
	glMaterialfv(GL_FRONT, GL_SPECULAR, UranoSpecular); // Material Urano
	glRotatef(urano, 0, 1, 0);  //Rotación va antes de crear la figura para que gire en su propio eje
	glutSolidSphere(0.5, 12, 12); // Se crea la figura

	glPushMatrix(); // Luna Urano
	glRotatef(luna_ura, 0, 1, 0); //Traslación va antes del pivote, del primer translate
	glTranslatef(1.5, 0, 0); // Se aleja 1.5 unidades de la tierra
	glColor3f(0.500, 0.500, 0.500); // Color gris claro
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonUranoDiffuse); // Material Luna Urano
	glMaterialfv(GL_FRONT, GL_SPECULAR, MoonUranoSpecular); // Material Luna Urano
	glRotatef(luna_ura, 0, 1, 0);  //Rotación va antes de crear la figura para que gire en su propio eje
	glutSolidSphere(0.25, 12, 12); // Se crea la figura
	glRotatef(luna_ura, 0, 1, 0);
	glTranslatef(0.3, 0, 0); // Se aleja 0.3 unidades del Sol
	glPopMatrix(); // Fin Luna Urano

	glPopMatrix(); // Fin Urano

	glPushMatrix(); // Neptuno
	glRotatef(neptuno, 0, 1, 0); //Traslación Va antes del pivote, del primer translate
	glTranslatef(14, 0, 0); // Se aleja 13 unidades del Sol
	glColor3f(0.0, 0.0, 0.9); // Color azul
	glMaterialfv(GL_FRONT, GL_DIFFUSE, NepDiffuse); // Material Neptuno
	glMaterialfv(GL_FRONT, GL_SPECULAR, NepSpecular); // Material Neptuno
	glRotatef(neptuno, 0, 1, 0);  //Rotación va antes de crear la figura para que gire en su propio eje
	glutSolidSphere(0.75, 12, 12); // Se crea la figura

	glPushMatrix(); // Luna Neptuno
	glRotatef(luna_nep, 0, 1, 0); //Traslación va antes del pivote, del primer translate
	glTranslatef(1.0, 0, 0); // Se aleja 1.5 unidades de Neptuno
	glColor3f(0.500, 0.500, 0.000); // Color  amarillo
	glMaterialfv(GL_FRONT, GL_DIFFUSE, MoonNepDiffuse); // Material Luna  Neptuno
	glMaterialfv(GL_FRONT, GL_SPECULAR, MoonNepSpecular); // Material Luna Neptuno
	glRotatef(luna_nep, 0, 1, 0);  //Rotación va antes de crear la figura para que gire en su propio eje
	glutSolidSphere(0.25, 12, 12); // Se crea la figura
	glRotatef(luna_nep, 0, 1, 0);
	glTranslatef(0.3, 0, 0); // Se aleja 0.3 unidades del Sol
	glPopMatrix(); // Fin Luna Neptuno

	glPushMatrix(); // Luna Neptuno 2
	glRotatef(luna_nep2, 0, 1, 0); //Traslación va antes del pivote, del primer translate
	glTranslatef(1.6, 0, 0); // Se aleja 1.6 unidades de Neptuno
	glColor3f(0.500, 0.500, 0.000); // Color  amarillo
	glMaterialfv(GL_FRONT, GL_DIFFUSE, Moon2NepDiffuse); // Material Luna 2  Neptuno
	glMaterialfv(GL_FRONT, GL_SPECULAR, Moon2NepSpecular); // Material Luna 2 Neptuno
	glRotatef(luna_nep2, 0, 1, 0);  //Rotación va antes de crear la figura para que gire en su propio eje
	glutSolidSphere(0.25, 12, 12); // Se crea la figura
	glRotatef(luna_nep2, 0, 1, 0);
	glTranslatef(0.3, 0, 0); // Se aleja 0.3 unidades del Sol
	glPopMatrix(); // Fin Luna Neptuno

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

		tierra = (tierra - 6) % 360;
		dwLastUpdateTime = dwCurrentTime;

	}



	if (dwElapsedTime >= 30)

	{

		luna = (luna - 1) % 360;
		dwLastUpdateTime = dwCurrentTime;

	}

	if (dwElapsedTime >= 30)

	{

		marte = (marte - 6) % 360;
		dwLastUpdateTime = dwCurrentTime;

	}

	if (dwElapsedTime >= 30)

	{

		luna_mar = (luna_mar - 2) % 360;
		dwLastUpdateTime = dwCurrentTime;

	}



	if (dwElapsedTime >= 30)

	{

		jupiter = (jupiter - 5) % 360;
		dwLastUpdateTime = dwCurrentTime;

	}



	if (dwElapsedTime >= 30)

	{

		luna_jup = (luna_jup - 1) % 360;
		dwLastUpdateTime = dwCurrentTime;

	}



	if (dwElapsedTime >= 30)

	{

		luna_jup2 = (luna_jup2 - 1) % 360;
		dwLastUpdateTime = dwCurrentTime;

	}



	if (dwElapsedTime >= 30)

	{

		saturno = (saturno - 4) % 360;
		dwLastUpdateTime = dwCurrentTime;

	}



	if (dwElapsedTime >= 30)

	{

		anillo_sat = (anillo_sat - 1) % 360;
		dwLastUpdateTime = dwCurrentTime;

	}



	if (dwElapsedTime >= 30)

	{

		anillo_sat2 = (anillo_sat2 - 1) % 360;
		dwLastUpdateTime = dwCurrentTime;

	}





	if (dwElapsedTime >= 30)

	{

		urano = (urano - 3) % 360;
		dwLastUpdateTime = dwCurrentTime;

	}



	if (dwElapsedTime >= 30)

	{

		luna_ura = (luna_ura - 1) % 360;
		dwLastUpdateTime = dwCurrentTime;

	}



	if (dwElapsedTime >= 30)

	{

		neptuno = (neptuno - 1) % 360;
		dwLastUpdateTime = dwCurrentTime;

	}



	if (dwElapsedTime >= 30)

	{

		luna_nep = (luna_nep - 2) % 360;
		dwLastUpdateTime = dwCurrentTime;

	}



	if (dwElapsedTime >= 30)

	{

		luna_nep2 = (luna_nep2 - 1) % 360;
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

	glutCreateWindow("Practica 7"); // Nombre de la Ventana

	InitGL();						// Parametros iniciales de la aplicacion

	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo

	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano

	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado

	glutSpecialFunc(arrow_keys);	//Otras

	glutIdleFunc(animacion);

	glutMainLoop();          // 



	return 0;

}

