#include <GL/gl.h>
#include <GL/glut.h>


void init(void)
{
  glClearColor (0.0, 0.0, 0.0, 0.0);
  glShadeModel (GL_FLAT);
}

void display(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (1.0, 0.0, 1.0);
    glLoadIdentity ();
    gluLookAt(1.0, 2.0, 3.0, //eye (x,y,z)
              0.0, 0.0, 0.0, //at(x,y,z)
              0.0, 1.0, 0.0); //up (x,y,z)
    glScalef (1.0, 1.0, 1.0);
    //glutWireTorus(0.5, 1.0, 20, 20);
    glFlush ();
}


void menu(int valor){
    if(valor == 1)
    {
      punto(0,0);
    }
    if(valor == 3)
    {
      exit(0);
    }
  glutPostRedisplay();
  glFlush();
}

void menu_opciones(void)
{
  glutCreateMenu(menu);
  glutAddMenuEntry("Punto",1);
  glutAddMenuEntry("Salir",2);
  glutAttachMenu(GLUT_RIGHT_BUTTON); // Eligiendo con el click derecho del raton

}

void reshape (int w, int h)
{
  glViewport (0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode (GL_PROJECTION);
  //inicia menu
  menu_opciones();
  glLoadIdentity ();
  glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
  //gluPerspective(30, (GLfloat)w / (GLfloat)h, 1.0, 200.0);
  glMatrixMode (GL_MODELVIEW);
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Ejemplos de Menus");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
