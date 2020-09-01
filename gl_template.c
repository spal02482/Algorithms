#include<stdio.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
void disp()
{
	glClearColor(0,0,0,1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0,0,0);
	glFlush();
}
int main(int xx,char **yy)
{
	glutInit(&xx,yy);
	glutInitWindowSize(600,600);
	glutCreateWindow("Translation");
	gluOrtho2D(-300,300,-300,300);
	glutDisplayFunc(disp);
	glutMainLoop();
	return 0;
}
