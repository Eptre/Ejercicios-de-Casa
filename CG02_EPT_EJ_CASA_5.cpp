#include <GLUT/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include "Main.h"

/*
 Erick Paniagua Trejo
 Grupo 02
 XCode
 Ejercicio Casa 5
 Humanoide 4 brazos
 
 v y V para mover dedo meñique
 g y G para mover dedo anular
 t y T para mover dedo medio
 y y Y para mover dedo índice
 u Y u para mover dedo pulgar
*/

float angleX = 0.0f;
float angleY = 0.0f;
float angleZ = 0.0f;

float transX = -1.0f;
float transY = -1.0f;
float transZ = -5.0f;

float angHombro = 0.0f;
float angcodo = 0.0f;
float angmu = 0.0f;
float angpul = 0.0f;
float angind = 0.0f;
float angmed = 0.0f;
float anganu = 0.0f;
float angme = 0.0f;

void InitGL(GLvoid)     // Inicializamos parametros

{
    //glShadeModel(GL_SMOOTH);                            // Habilitamos Smooth Shading
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);                // Negro de fondo
    glClearDepth(1.0f);                                    // Configuramos Depth Buffer
    glEnable(GL_DEPTH_TEST);                            // Habilitamos Depth Testing
    //glEnable(GL_LIGHTING);
    glDepthFunc(GL_LEQUAL);                                // Tipo de Depth Testing a realizar
    //glEnable ( GL_COLOR_MATERIAL );
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    
}

void prisma(void)

{
    GLfloat vertice[8][3] = {
        {0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
        {-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
        {-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
        {0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
        {0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
        {0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
        {-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
        {-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
    };
    
    glBegin(GL_POLYGON);    //Front
    glColor3f(1.0, 0.0, 0.0);
    glVertex3fv(vertice[0]);
    glVertex3fv(vertice[4]);
    glVertex3fv(vertice[7]);
    glVertex3fv(vertice[1]);
    glEnd();
    
    glBegin(GL_POLYGON);    //Right
    glColor3f(0.0, 1.0, 0.0);
    glVertex3fv(vertice[0]);
    glVertex3fv(vertice[3]);
    glVertex3fv(vertice[5]);
    glVertex3fv(vertice[4]);
    glEnd();
    
    glBegin(GL_POLYGON);    //Back
    glColor3f(0.0, 1.0, 1.0);
    glVertex3fv(vertice[6]);
    glVertex3fv(vertice[5]);
    glVertex3fv(vertice[3]);
    glVertex3fv(vertice[2]);
    glEnd();
    
    glBegin(GL_POLYGON);  //Left
    glColor3f(0.0, 0.0, 1.0);
    glVertex3fv(vertice[1]);
    glVertex3fv(vertice[7]);
    glVertex3fv(vertice[6]);
    glVertex3fv(vertice[2]);
    glEnd();
    
    glBegin(GL_POLYGON);  //Bottom
    glColor3f(1.0, 1.0, 1.0);
    glVertex3fv(vertice[0]);
    glVertex3fv(vertice[1]);
    glVertex3fv(vertice[2]);
    glVertex3fv(vertice[3]);
    glEnd();
    
    glBegin(GL_POLYGON);  //Top
    glColor3f(1.0, 0.0, 1.0);
    glVertex3fv(vertice[4]);
    glVertex3fv(vertice[5]);
    glVertex3fv(vertice[6]);
    glVertex3fv(vertice[7]);
    glEnd();
}

void display(void)   // Creamos la funcion donde se dibuja

{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);    // Limiamos pantalla y Depth Buffer
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    glTranslatef(transX, transY, transZ);
    glRotatef(45, angleX, angleY, angleZ);
    //Poner Código Aquí.
    glTranslatef(1.0f, 2.0f, 0.0f);
    prisma();
    
    glTranslatef(0.0f, -0.7f, 0.0f);
    glRotatef(90, 0, 1, 0);
    glScalef(0.5f, 0.5f, 1.0f);
    prisma();
    
    glTranslatef(0.0f, -1.5f, 0.0f);
    glRotatef(270, 0.0f, 1.0f, 0.0f);
    glScalef(2.0f, 3.0f, -4.0f);
    prisma();
    
    glTranslatef(-0.7f, 0.0f, 0.0f);
    glRotatef(90, 0.0f, 2.0f, 0.0f);
    glScalef(0.5f, 0.5f,0.5f);
    prisma();
    
    glTranslatef(0.2f, 0.1f, -1.0f);
    glRotatef(-90, 0.0f, 1.0f, 0.0f);
    glScalef(1.5f, 0.7f, -0.5f);
    prisma();
    
    glTranslatef(-0.9f, 0.0f,0.1f);
    glRotatef(90, 0.0f, 1.0f, 0.0f);
    glScalef(-1.5f, 0.7f, 1.0f);
    prisma();
    
    glTranslatef(0.0f, 0.0f, -0.85f);
    glRotatef(90, 0.0f, 1.0f, 0.0f);
    glScalef(-0.7f, 0.7f, 1.0f);
    prisma();
    
    glTranslatef(6.0f, -0.2f, 0.0f);
    glRotatef(90, 0.0f, 1.0f, 0.0f);
    glScalef(-0.7f, 2.8f, -1.0f);
    prisma();   ////////////////////////
    
    glTranslatef(0.0f, 0.0f, -1.2f);
    glRotatef(-90, 0.0f, 1.0f, 0.0f);
    glScalef(1.5f, 0.7f, -1.0f);
    prisma();
    
    glTranslatef(-1.0f, 0.0f, 0.0f);
    glRotatef(90, 0.0f, 1.0f, 0.0f);
    glScalef(1.0f, 1.0f, 1.0f);
    prisma();
    
    glTranslatef(0.0f, 0.0f, -0.5f);
    glRotatef(-90, 0.0f, 1.0f, 0.0f);
    glScalef(0.5f, 1.0f, 1.0f);
    prisma();
    
    glTranslatef(7.0f, -2.5f, -1.0f);
    glRotatef(90, 0.0f, 1.0f, 0.0f);
    glScalef(1.0f, 2.5f, 1.0f);
    prisma();
    
    glTranslatef(0.0f, -0.75f, 0.0f);
    glRotatef(90, 0.0f, 1.0f, 0.0f);
    glScalef(1.0f, 0.5f, 1.0f);
    prisma();
    
    glTranslatef(0.0f, -1.25f, 0.0f);
    glRotatef(90, 0.0f, 1.0f, 0.0f);
    glScalef(1.0f, 1.5f, 1.0f);
    prisma();
    
    glTranslatef(0.0f, -0.75f, 0.0f); //pie
    glRotatef(90, 0.0f, 1.0f, 0.0f);
    glScalef(1.0f, 0.5f, 1.0f);
    prisma();
    
    glTranslatef(-1.5f, 5.0f, 0.0f); //pierna
    glRotatef(90, 0.0f, 1.0f, 0.0f);
    glScalef(1.0f, 2.5f, 1.0f);
    prisma();
    
    glTranslatef(0.0f, -0.75f, 0.0f); //rodilla
    glRotatef(90, 0.0f, 1.0f, 0.0f);
    glScalef(1.0f, 0.5f, 1.0f);
    prisma();
    
    glTranslatef(0.0f, -1.25f, 0.0f); //pierna
    glRotatef(90, 0.0f, 1.0f, 0.0f);
    glScalef(1.0f, 1.5f, 1.0f);
    prisma();
    
    glTranslatef(0.0f, -0.81f, 0.0f); //pie
    glRotatef(90, 0.0f, 1.0f, 0.0f);
    glScalef(1.0f, 0.62f, 1.0f);
    prisma();
    
    
    ////////////////////////////////////////////// Brazo
    
    //hombro
    glRotatef(angHombro, 0, 0, 1);
    glScalef(0.3f, 0.5f, 0.5f);
    glColor3f(1, 1, 1);
    prisma();
    glScalef(3, 2, 1);
    //bicep
    glTranslatef(2.5f, 6.5f, 4.0f);
    glScalef(1, 0.5, 1);
    glColor3f(1, 0, 0);
    prisma();
    
    //codo
    glScalef(1, 2, 1);
    glTranslatef(0.6f, 0.0, 0.0);
    glRotatef(angcodo, 0, 0, 1);
    glScalef(0.2f, 0.5f, 1.0f);
    glColor3f(0, 1, 0);
    prisma();
    
    //antebrazo
    glScalef(5, 2, 0.5);
    glTranslatef(0.5f, 0.0f, 0.0f);
    glScalef(0.8f, 0.5f, 1.0f);
    glColor3f(0, 0, 1);
    prisma();
    
    //muñeca
    glScalef(1.25, 2, 1);
    glTranslatef(0.45, 0, 0);
    glRotatef(angmu, 0, 1, 0);
    glScalef(0.1, 0.5, 1);
    glColor3f(1, 1, 0);
    prisma();
    
    glScalef(10, 2, 1);
    //palma
    glTranslatef(0.35, 0, 0);
    glScalef(0.6, 0.5, 1);
    glColor3f(0, 1, 1);
    prisma();
    
    glScalef(1.66, 2, 1);
    //pulgar
    glTranslatef(-0.2, 0.285, 0);
    glScalef(0.2, 0.07, 1);
    glColor3f(0.5, 0.3, 0);
    prisma();
    
    glScalef(5, 14.28, 1);
    //falanje pulgar
    glTranslatef(0, 0.035, 0);
    glRotatef(angpul, 1, 0, 0);
    glTranslatef(0.0, 0.035, 0);
    glScalef(0.2, 0.07, 1);
    glColor3f(0.2, 0.3, 0.1);
    prisma();
    
    glScalef(5, 14.29, 1);
    // índice
    glTranslatef(0.60, -0.13, 0);
    glScalef(0.2, 0.05, 1);
    glColor3f(1, 0, 1);
    prisma();
    
    glScalef(2, 20, 1);
    //falanje índice
    glTranslatef(0.50, 0, 0);
    glRotatef(angind, 0, 1, 0);
    glScalef(0.5, 0.05, 1);
    glColor3f(0, 0, 1);
    prisma();
    
    glScalef(2, 20, 1);
    // falanje índice 2
    glTranslatef(0.50, 0, 0);
    glRotatef(angind, 0, 0, 0);
    glScalef(0.5, 0.05, 1);
    glColor3f(1, 1, 0);
    prisma();
    
    glScalef(2, 20, 1);
    // medio
    glTranslatef(-1.0, -0.20, 0);
    glScalef(0.5, 0.05, 1);
    glColor3f(1, 0, 1);
    prisma();
    
    glScalef(2, 20, 1);
    //falanje medio 1
    glTranslatef(0.50, 0, 0);
    glRotatef(angmed, 0, 1, 0);
    glScalef(0.5, 0.05, 1);
    glColor3f(0, 0, 1);
    prisma();
    
    glScalef(2, 20, 1);
    //falanje medio 2
    glTranslatef(0.60, 0, 0);
    glRotatef(angmed, 0, 1, 0);
    glScalef(0.7, 0.05, 1);
    glColor3f(1, 1, 0);
    prisma();
    
    glScalef(1.48, 20, 1);
    //anular
    glTranslatef(-1.05, -0.13, 0);
    glScalef(0.5, 0.05, 1);
    glColor3f(1, 0, 1);
    prisma();
    
    glScalef(1.48, 20, 1);
    //falanje anular 1
    glTranslatef(0.58, 0, 0);
    glRotatef(anganu, 0, 1, 0);
    glScalef(0.5, 0.05, 1);
    glColor3f(0, 0, 1);
    prisma();
    
    glScalef(2, 20, 1);
    //falanje anular 2
    glTranslatef(0.60, 0, 0);
    glRotatef(anganu, 0, 1, 0);
    glScalef(0.71, 0.05, 1);
    glColor3f(1, 1, 0);
    prisma();
    
    glScalef(1.5, 20, 1);
    //meñique
    glTranslatef(-1.15, -0.12, 0);
    glScalef(-0.55, 0.05, 1);
    glColor3f(1, 0, 1);
    prisma();
    
    glScalef(1.9, 20, 1);
    // falanje meñique 1
    glTranslatef(-0.45, 0, 0);
    glRotatef(angme, 0, 1, 0);
    glScalef(0.4, 0.05, 1);
    glColor3f(0, 0, 1);
    prisma();
    
    glScalef(2.5, 20, 1);
    //falanje meñique 2
    glTranslatef(-0.40, 0, 0);
    glRotatef(angme, 0, 1, 0);
    glScalef(0.4, 0.05, 1);
    glColor3f(1, 1, 0);
    prisma();
    
    ////////////////////////////////////////////// Brazo 2
    glScalef(7,20,1);
    //hombro
    glRotatef(angHombro, 0, 0, 1);
    glScalef(0.3f, 0.5f, 0.5f);
    glColor3f(1, 1, 1);
    prisma();
    glScalef(3, 2, 1);
    //bicep
    glTranslatef(7.0f, 0.1f, 2.0f);
    glScalef(1, 0.5, 1);
    glColor3f(1, 0, 0);
    prisma();
    
    //codo
    glScalef(1, 2, 1);
    glTranslatef(0.6f, 0.0, 0.0);
    glRotatef(angcodo, 0, 0, 1);
    glScalef(0.2f, 0.5f, 1.0f);
    glColor3f(0, 1, 0);
    prisma();
    
    //antebrazo
    glScalef(5, 2, 0.5);
    glTranslatef(0.5f, 0.0f, 0.0f);
    glScalef(0.8f, 0.5f, 1.0f);
    glColor3f(0, 0, 1);
    prisma();
    
    //muñeca
    glScalef(1.25, 2, 1);
    glTranslatef(0.45, 0, 0);
    glRotatef(angmu, 0, 1, 0);
    glScalef(0.1, 0.5, 1);
    glColor3f(1, 1, 0);
    prisma();
    
    glScalef(10, 2, 1);
    //palma
    glTranslatef(0.35, 0, 0);
    glScalef(0.6, 0.5, 1);
    glColor3f(0, 1, 1);
    prisma();
    
    glScalef(1.66, 2, 1);
    //pulgar
    glTranslatef(-0.2, 0.285, 0);
    glScalef(0.2, 0.07, 1);
    glColor3f(0.5, 0.3, 0);
    prisma();
    
    glScalef(5, 14.28, 1);
    //falanje pulgar
    glTranslatef(0, 0.035, 0);
    glRotatef(angpul, 1, 0, 0);
    glTranslatef(0.0, 0.035, 0);
    glScalef(0.2, 0.07, 1);
    glColor3f(0.2, 0.3, 0.1);
    prisma();
    
    glScalef(5, 14.29, 1);
    // índice
    glTranslatef(0.60, -0.13, 0);
    glScalef(0.2, 0.05, 1);
    glColor3f(1, 0, 1);
    prisma();
    
    glScalef(2, 20, 1);
    //falanje índice
    glTranslatef(0.50, 0, 0);
    glRotatef(angind, 0, 1, 0);
    glScalef(0.5, 0.05, 1);
    glColor3f(0, 0, 1);
    prisma();
    
    glScalef(2, 20, 1);
    // falanje índice 2
    glTranslatef(0.50, 0, 0);
    glRotatef(angind, 0, 0, 0);
    glScalef(0.5, 0.05, 1);
    glColor3f(1, 1, 0);
    prisma();
    
    glScalef(2, 20, 1);
    // medio
    glTranslatef(-1.0, -0.20, 0);
    glScalef(0.5, 0.05, 1);
    glColor3f(1, 0, 1);
    prisma();
    
    glScalef(2, 20, 1);
    //falanje medio 1
    glTranslatef(0.50, 0, 0);
    glRotatef(angmed, 0, 1, 0);
    glScalef(0.5, 0.05, 1);
    glColor3f(0, 0, 1);
    prisma();
    
    glScalef(2, 20, 1);
    //falanje medio 2
    glTranslatef(0.60, 0, 0);
    glRotatef(angmed, 0, 1, 0);
    glScalef(0.7, 0.05, 1);
    glColor3f(1, 1, 0);
    prisma();
    
    glScalef(1.48, 20, 1);
    //anular
    glTranslatef(-1.05, -0.13, 0);
    glScalef(0.5, 0.05, 1);
    glColor3f(1, 0, 1);
    prisma();
    
    glScalef(1.48, 20, 1);
    //falanje anular 1
    glTranslatef(0.58, 0, 0);
    glRotatef(anganu, 0, 1, 0);
    glScalef(0.5, 0.05, 1);
    glColor3f(0, 0, 1);
    prisma();
    
    glScalef(2, 20, 1);
    //falanje anular 2
    glTranslatef(0.60, 0, 0);
    glRotatef(anganu, 0, 1, 0);
    glScalef(0.71, 0.05, 1);
    glColor3f(1, 1, 0);
    prisma();
    
    glScalef(1.5, 20, 1);
    //meñique
    glTranslatef(-1.15, -0.12, 0);
    glScalef(-0.55, 0.05, 1);
    glColor3f(1, 0, 1);
    prisma();
    
    glScalef(1.9, 20, 1);
    // falanje meñique 1
    glTranslatef(-0.45, 0, 0);
    glRotatef(angme, 0, 1, 0);
    glScalef(0.4, 0.05, 1);
    glColor3f(0, 0, 1);
    prisma();
    
    glScalef(2.5, 20, 1);
    //falanje meñique 2
    glTranslatef(-0.40, 0, 0);
    glRotatef(angme, 0, 1, 0);
    glScalef(0.4, 0.05, 1);
    glColor3f(1, 1, 0);
    prisma();
    
    
    
    
    
    
    
    
    
    ///////////////////////////////////////////////
    
    
    
    glutSwapBuffers();
    //glFlush();
    // Swap The Buffers
}



void reshape(int width, int height)   // Creamos funcion Reshape

{
    if (height == 0)                                        // Prevenir division entre cero
    {
        height = 1;
    }
    
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);                        // Seleccionamos Projection Matrix
    glLoadIdentity();
    
    // Tipo de Vista
    //glOrtho(-5, 5, -5, 5, 0.1, 20);
    glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 50.0);
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function

{
    switch (key) {
            
        case 'v':
            if (angme > 0)
                angme -= 0.5f;
            printf("ang menique: %f", angme);
            break;
            
        case 'V':
            if (angme >= 0 && angme <= 14)
                angme += 0.5f;
            printf("ang menique: %f", angme);
            break;
            
        case 'g':
            if (anganu < 0)
                anganu += 0.5f;
            printf("ang angular: %f", anganu);
            break;
            
        case 'G':
            if (anganu <= 0 && anganu <= 90)
                anganu -= 0.5f;
            printf("ang angular: %f", anganu);
            break;
            
        case 't':
            if (angmed < 0)
                angmed += 0.5f;
            printf("ang indice: %f", angmed);
            break;
            
        case 'T':
            if (angmed >= 0)
                angmed -= 0.5f;
            printf("ang indice: %f", angmed);
            break;
            
            
        case 'y':
            if (angind < 90)
                angind -= 0.5f;
            printf("ang indice: %f", angind);
            break;
            
        case 'Y':
            if (angind < 0)
                angind += 0.5f;
            printf("ang indice: %f", angind);
            break;
            
        case 'u':
            if (angpul < 90)
                angpul += 0.5f;
            printf("ang pulgar: %f", angpul);
            break;
        case 'U':
            if (angpul < 90)
                angpul -= 0.5f;
            printf("ang pulgar: %f", angpul);
            break;
            
        case 'i':
            if (angmu < 90)
                angmu += 0.5f;
            printf("ang muñeca: %f", angmu);
            break;
        case 'I':
            if (angmu < 90)
                angmu -= 0.5f;
            printf("ang muñeca: %f", angmu);
            break;
        case 'o':
            if (angcodo < 90)
                angcodo += 0.5f;
            printf("ang codo: %f", angcodo);
            break;
        case 'O':
            if (angcodo < 90)
                angcodo -= 0.5f;
            printf("ang codo: %f", angcodo);
            break;
            
            
        case 'p':
            if (angHombro < 90)
                angHombro += 0.5f;
            printf("ang: %f", angHombro);
            break;
        case 'P':
            if (angHombro > 90)
                angHombro -= 0.5f;
            break;

            
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
    //glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE | GLUT_DEPTH);
    // Display Mode (Clores RGB y alpha | Buffer Sencillo )
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
    glutInitWindowSize(1000, 1000);    // Tamaño de la Ventana
    glutInitWindowPosition(0, 0);    //Posicion de la Ventana
    glutCreateWindow("Practica 3"); // Nombre de la Ventana
    InitGL();                        // Parametros iniciales de la aplicacion
    glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
    glutReshapeFunc(reshape);    //Indicamos a Glut función en caso de cambio de tamano
    glutKeyboardFunc(keyboard);    //Indicamos a Glut función de manejo de teclado
    glutSpecialFunc(arrow_keys);    //Otras
    glutMainLoop();          //
    return 0;
}








