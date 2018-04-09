
#include<stdio.h>
#include<windows.h>  
#include<GL/glut.h>  
#include<math.h>  

  int first=0;  
  int xi,yi,xf,yf;  
  void putpixel(int x,int y)  
  {  
       glBegin(GL_POINTS);  
       glVertex2i(x,y);  
       glPointSize(30.0);
       glEnd();  
       glFlush();  
  }  
  
   void myinit()  
  {  

       glMatrixMode(GL_PROJECTION);  
       glLoadIdentity();  
       gluOrtho2D(0,500,0,500);  
       glMatrixMode(GL_MODELVIEW);  
  }  
    
  void bresenham_circle(int radius)  
  {  
  		int xc=200, yc=200;
       int x=0,y=radius,p;  
       p=3-(2*radius); 
       
       while(x<=y)
	   {  
            
            putpixel(xc+x, yc+y); 
			putpixel(xc+x, yc-y);  
			putpixel(xc-x, yc+y);  
            putpixel(xc-x, yc-y); 
            putpixel(xc+y, yc+x);  
            putpixel(xc+y, yc-x);  
            putpixel(xc-y, yc+x);  
            putpixel(xc-y, yc-x);  
           
			
			if(p<=0)
			{
			   p=p+(4*x)+6;  
            }
			
			else
			{  
               p=p+(4*(x-y))+10;  
               y--;  
            }  
            
			x++;  
      }  
  }  
  
  
    void display()  
  {  
       glClearColor(1.0,1.0,1.0,1.0);  
       glColor3f(0.5,0.3,0.0);  
       glClear(GL_COLOR_BUFFER_BIT);  
       bresenham_circle(100);  
      // glutSwapBuffers();  
       glFlush();  
  }  
  
 
  int main(int argc,char** argv)  
  {  
       glutInit(&argc,argv);  
       glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  
       glutInitWindowSize(500,500);  
       glutCreateWindow("Bresenham-Circle");  
       glutDisplayFunc(display);  
       myinit();  
       glutMainLoop(); 
	   glFlush(); 
       return 0;  
  }  



