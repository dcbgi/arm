// Geometry 3D Robot.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <GL/glut.h>

static int shoulder = 0, elbow = 0, wrist = 0, grab = 0;

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	
	//shoudler
	glTranslatef(-1.0, 0.0, 0.0);
	glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
	glTranslatef(1.0, 0.0, 0.0);

	glPushMatrix();
	glScalef(2.0, 0.4, 1.0);
	glutWireCube(1.0);
	glPopMatrix();

	//elbow
	glTranslatef(1.0, 0.0, 0.0);
	glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
	glTranslatef(1.0, 0.0, 0.0);

	glScalef(2.0, 0.4, 1.0);
	glutWireCube(1.0);

	 //wrist
	glTranslatef(.3, 0, 0);
	glRotatef((GLfloat)wrist, 1.0, 0.0, 0.0);
	glTranslatef(.3, 0, 0);

	
	glScalef(.2, 1, 1);
	glutWireCube(1);

	 //fingers
	//1
	glPushMatrix();

	glTranslatef(.8, .4, 0);
	glScalef(3, 1, 1);
	glutWireCube(.2);
	glTranslatef(.2, 0, 0);
	glRotatef((GLfloat)grab, 0, 0,-1.0 );
	glTranslatef(.2, 0, 0);
	glScalef(3, 1, 1);
	glutWireCube(.2);

	glPopMatrix();

	//2
	glPushMatrix();

	glTranslatef(.8, -.4, 0);
	glScalef(3, 1, 1);
	glutWireCube(.2);
	glTranslatef(.2, 0, 0);
	glRotatef((GLfloat)grab, 0,0,1.0);
	glTranslatef(.2, 0, 0);
	glScalef(3, 1, 1);
	glutWireCube(.2);

	glPopMatrix();

	//3
	glPushMatrix();
	glTranslatef(.8, 0, .4);
	glScalef(3, 1, 1);
	glutWireCube(.2);
	glTranslatef(.2, 0, 0);
	glRotatef((GLfloat)grab, 0, 1,0);
	glTranslatef(.2, 0, 0);
	glScalef(3, 1, 1);
	glutWireCube(.2);
	glPopMatrix();

	//4
	glPushMatrix();
	glTranslatef(.8, 0, -.4);
	glScalef(3, 1, 1);
	glutWireCube(.2);
	glTranslatef(.2, 0, 0);
	glRotatef((GLfloat)grab, 0,-1,0);//move finger inward with 'g'
	glTranslatef(.2, 0, 0);
	glScalef(3, 1, 1);//make long
	glutWireCube(.2);
	glPopMatrix();
	

	glPopMatrix();
	glutSwapBuffers();

}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -5.0);
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 's':
		shoulder = (shoulder + 5) % 360;
		glutPostRedisplay();
		break;
	case 'S':
		shoulder = (shoulder - 5) % 360;
		glutPostRedisplay();
		break;
	case 'e':
		elbow = (elbow + 5) % 360;
		glutPostRedisplay();
		break;
	case 'E':
		elbow = (elbow - 5) % 360;
		glutPostRedisplay();
		break;
	case 'w':
		wrist = (wrist + 5) % 360;
		glutPostRedisplay();
		break;
	case 'W':
		wrist = (wrist - 5) % 360;
		glutPostRedisplay();
		break;

	case 'g':
			grab = (grab + 5) % 360;
			glutPostRedisplay();
			break;
	case 'G':
		grab = (grab - 5) % 360;
		glutPostRedisplay();
		break;
	default:
		break;
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}