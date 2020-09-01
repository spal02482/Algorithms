void myInit()
{
	glClearColor(0.0,0.0,0.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,1.0,0.0);
	gluOrtho2D(0.0,650.0,0.0,650.0);
	glFlush();
}
void display()
{
	int i,j,row=0,col=0,flagr=0;

	float flag=0.0;
	glClear(GL_COLOR_BUFFER_BIT);
	for(i=0;i<8;i++)
	{
		row=0;
		if(i%2==0)
		{
			glColor3f(1.0,0.0,0.0);
			flagr=1;
		}
		else
		{
			glColor3f(0.0,0.0,1.0);
			flagr=0;
		}
		for(j=0;j<8;j++)
		{
			if(flagr==1)
			{
				if(j%2==0)
					glColor3f(1.0,0.0,0.0);
				else
					glColor3f(0.0,0.0,1.0);
			}
			else
			{
				if(j%2==0)
				 	glColor3f(0.0,0.0,1.0);
				else
					glColor3f(1.0,0.0,0.0);
			}
			glRecti(50+row,50+col,100+row,100+col);
			row+=50;
		}
		col+=50;
	}
	glFlush();

}
int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(600,600);
	glutInitWindowPosition(800,800);
	glutCreateWindow("DDA Line Drawing--");
	glutDisplayFunc(display);
	myInit();
	glutMainLoop();
	return 0;
}




