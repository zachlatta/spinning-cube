#include <GLFW/glfw3.h>

float rotx, roty = 0;
float ambient[4] = {0.5, 0.5, 0.5, 1.0};
float diffuse[4] = {1, 1, 1, 1};
float lightpos[4] = {-5, 5, 10, 0};

int main(void)
{
  GLFWwindow* window;

  if (!glfwInit()) {
    return -1;
  }

  window = glfwCreateWindow(640, 480, "Spinning Cube", NULL, NULL);
  if (!window) {
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(window);

  glEnable(GL_DEPTH_TEST);
  glEnable(GL_LIGHTING);

  glClearColor(0, 0, 0, 0);
  glClearDepth(1);
  glDepthFunc(GL_LEQUAL);

  glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
  glLightfv(GL_LIGHT0, GL_POSITION, lightpos);
  glEnable(GL_LIGHT0);
  
  glViewport(0, 0, 640, 480);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  glFrustum(-1, 1, -1, 1, 1.0, 10.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  while (!glfwWindowShouldClose(window)) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0, 0, -3);
    glRotatef(rotx, 1, 0, 0);
    glRotatef(roty, 0, 1, 1);

    rotx += 0.5;
    roty += 0.5;

    glColor4f(1, 1, 1, 1);

    glBegin(GL_QUADS);

    glNormal3f(0, 0, 1);
    glVertex3f(-1, -1, 1);
    glVertex3f(1, -1, 1);
    glVertex3f(1, 1, 1);
    glVertex3f(-1, 1, 1);

    glNormal3f(0, 0, -1);
    glVertex3f(-1, -1, -1);
    glVertex3f(-1, 1, -1);
    glVertex3f(1, 1, -1);
    glVertex3f(1, -1, -1);

    glNormal3f(0, 1, 0);
    glVertex3f(-1, 1, -1);
    glVertex3f(-1, 1, 1);
    glVertex3f(1, 1, 1);
    glVertex3f(1, 1, -1);

    glNormal3f(0, -1, 0);
    glVertex3f(-1, -1, -1);
    glVertex3f(1, -1, -1);
    glVertex3f(1, -1, 1);
    glVertex3f(-1, -1, 1);

    glNormal3f(1, 0, 0);
    glVertex3f(1, -1, -1);
    glVertex3f(1, 1, -1);
    glVertex3f(1, 1, 1);
    glVertex3f(1, -1, 1);

    glNormal3f(-1, 0, 0);
    glVertex3f(-1, -1, -1);
    glVertex3f(-1, -1, 1);
    glVertex3f(-1, 1, 1);
    glVertex3f(-1, 1, -1);

    glEnd();

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}
