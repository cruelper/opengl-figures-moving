#define STB_IMAGE_IMPLEMENTATION

#include <GL/glew.h>
#include <GL/glut.h>
#include <cmath>

#include <GL/gl.h>
#include <GL/glu.h>
#include "stb_image.h"

void halfDisk(){
    int xShift = 2;
    int yShift = 1;

    /* top triangle */
    double i, resolution  = 0.005;
    double height = 0.05;
    double radius = 0.7;

    glPushMatrix();
    glTranslatef(0 + xShift, -0.5 + yShift, 0);

    glBegin(GL_TRIANGLE_FAN);
    glTexCoord2f( 0.5, 0.5 );
    glVertex3f(0 + xShift, height + yShift, 0);  /* center */
    for (i = M_PI; i >= 0; i -= resolution) {
        glTexCoord2f( 0.5f * cos(i) + 0.5f, 0.5f * sin(i) + 0.5f );
        glVertex3f(radius * cos(i) + xShift, height + yShift, radius * sin(i));
    }
    /* close the loop back to 0 degrees */
    glTexCoord2f( 0.5, 0.5 );
    glVertex3f(radius + xShift, height + yShift, 0);
    glEnd();

    /* bottom triangle: note: for is in reverse order */
    glBegin(GL_TRIANGLE_FAN);
    glTexCoord2f( 0.5, 0.5 );
    glVertex3f(0 + xShift, 0 + yShift, 0);  /* center */
    for (i = 0; i <= M_PI; i += resolution) {
        glTexCoord2f( 0.5f * cos(i) + 0.5f, 0.5f * sin(i) + 0.5f );
        glVertex3f(radius * cos(i) + xShift, 0 + yShift, radius * sin(i));
    }
    glEnd();

    /* middle tube */
    glBegin(GL_QUAD_STRIP);
    for (i = 0; i <= M_PI; i += resolution) {
        const float tc = ( i / (float)( 2 * M_PI ) );
        glTexCoord2f( tc, 0.0 );
        glVertex3f(radius * cos(i) + xShift, 0 + yShift, radius * sin(i));
        glTexCoord2f( tc, 1.0 );
        glVertex3f(radius * cos(i) + xShift, height + yShift, radius * sin(i));
    }
    /* close the loop back to zero degrees */
    glTexCoord2f( 0.0, 0.0 );
    glVertex3f(radius + xShift, 0 + yShift, 0);
    glTexCoord2f( 0.0, 1.0 );
    glVertex3f(radius + xShift, height + yShift, 0);
    glEnd();

    glPopMatrix();
}

void disk(){
    int xShift = 1;
    int yShift = -1;

    /* top triangle */
    double i, resolution  = 0.005;
    double height = 0.05;
    double radius = 0.7;

    glPushMatrix();
    glTranslatef(0 + xShift, -0.5 + yShift, 0);

    glBegin(GL_TRIANGLE_FAN);
    glTexCoord2f( 0.5, 0.5 );
    glVertex3f(0 + xShift, height + yShift, 0);  /* center */
    for (i = 2 * M_PI; i >= 0; i -= resolution) {
        glTexCoord2f( 0.5f * cos(i) + 0.5f, 0.5f * sin(i) + 0.5f );
        glVertex3f(radius * cos(i) + xShift, height + yShift, radius * sin(i));
    }
    /* close the loop back to 0 degrees */
    glTexCoord2f( 0.5, 0.5 );
    glVertex3f(radius + xShift, height + yShift, 0);
    glEnd();

    /* bottom triangle: note: for is in reverse order */
    glBegin(GL_TRIANGLE_FAN);
    glTexCoord2f( 0.5, 0.5 );
    glVertex3f(0 + xShift, 0 + yShift, 0);  /* center */
    for (i = 0; i <= 2 * M_PI; i += resolution) {
        glTexCoord2f( 0.5f * cos(i) + 0.5f, 0.5f * sin(i) + 0.5f );
        glVertex3f(radius * cos(i) + xShift, 0 + yShift, radius * sin(i));
    }
    glEnd();

    /* middle tube */
    glBegin(GL_QUAD_STRIP);
    for (i = 0; i <= 2 * M_PI; i += resolution) {
        const float tc = ( i / (float)( 2 * M_PI ) );
        glTexCoord2f( tc, 0.0 );
        glVertex3f(radius * cos(i) + xShift, 0 + yShift, radius * sin(i));
        glTexCoord2f( tc, 1.0 );
        glVertex3f(radius * cos(i) + xShift, height + yShift, radius * sin(i));
    }
    /* close the loop back to zero degrees */
    glTexCoord2f( 0.0, 0.0 );
    glVertex3f(radius + xShift, 0 + yShift, 0);
    glTexCoord2f( 0.0, 1.0 );
    glVertex3f(radius + xShift, height + yShift, 0);
    glEnd();

    glPopMatrix();
}

void cylinder() {
    /* top triangle */
    double i, resolution  = 0.005;
    double height = 1;
    double radius = 0.5;

    glPushMatrix();
    glTranslatef(0, -0.5, 0);

    glBegin(GL_TRIANGLE_FAN);
    glTexCoord2f( 0.5, 0.5 );
    glVertex3f(0, height, 0);  /* center */
    for (i = 2 * M_PI; i >= 0; i -= resolution) {
        glTexCoord2f( 0.5f * cos(i) + 0.5f, 0.5f * sin(i) + 0.5f );
        glVertex3f(radius * cos(i), height, radius * sin(i));
    }
    /* close the loop back to 0 degrees */
    glTexCoord2f( 0.5, 0.5 );
    glVertex3f(radius, height, 0);
    glEnd();

    /* bottom triangle: note: for is in reverse order */
    glBegin(GL_TRIANGLE_FAN);
    glTexCoord2f( 0.5, 0.5 );
    glVertex3f(0, 0, 0);  /* center */
    for (i = 0; i <= 2 * M_PI; i += resolution) {
        glTexCoord2f( 0.5f * cos(i) + 0.5f, 0.5f * sin(i) + 0.5f );
        glVertex3f(radius * cos(i), 0, radius * sin(i));
    }
    glEnd();

    /* middle tube */
    glBegin(GL_QUAD_STRIP);
    for (i = 0; i <= 2 * M_PI; i += resolution) {
        const float tc = ( i / (float)( 2 * M_PI ) );
        glTexCoord2f( tc, 0.0 );
        glVertex3f(radius * cos(i), 0, radius * sin(i));
        glTexCoord2f( tc, 1.0 );
        glVertex3f(radius * cos(i), height, radius * sin(i));
    }
    /* close the loop back to zero degrees */
    glTexCoord2f( 0.0, 0.0 );
    glVertex3f(radius, 0, 0);
    glTexCoord2f( 0.0, 1.0 );
    glVertex3f(radius, height, 0);
    glEnd();

    glPopMatrix();
}

void cope() {
    int xShift = 1;
    int yShift = -2;

    /* top triangle */
    double i, resolution  = 0.005;
    double height = 1;
    double radius = 0.5;

    glPushMatrix();
    glTranslatef(0, -0.5, 0);

    glBegin(GL_TRIANGLE_FAN);
    /* center */
    for (i = 2 * M_PI; i >= 0; i -= resolution) {
        glTexCoord2f( 0.5f * cos(i) + 0.5f, 0.5f * sin(i) + 0.5f );
        glVertex3f(radius * cos(i) + xShift, height + yShift, radius * sin(i));
    }
    glEnd();

    /* middle tube */
    glBegin(GL_QUAD_STRIP);
    for (i = 0; i <= 2 * M_PI; i += resolution) {
        const float tc = ( i / (float)( 2 * M_PI ) );
        glTexCoord2f( tc, 0.0 );
        glVertex3f(0 + xShift, 0 + yShift, 0);
        glTexCoord2f( tc, 1.0 );
        glVertex3f(radius * cos(i) + xShift, height + yShift, radius * sin(i));
    }
    glEnd();

    glPopMatrix();
}

GLuint tex[4];
void init() {

    int width, height, nrChannels;
    char* name = new char[]{"/home/cruelper/university/graphics/labs/opengl/3.jpg"};
    unsigned char *data = stbi_load(name, &width, &height, &nrChannels, 0);

    int width2, height2, nrChannels2;
    char* name2 = new char[]{"/home/cruelper/university/graphics/labs/opengl/2.jpg"};
    unsigned char *data2 = stbi_load(name2, &width2, &height2, &nrChannels2, 0);

    int width3, height3, nrChannels3;
    char* name3 = new char[]{"/home/cruelper/university/graphics/labs/opengl/1.jpg"};
    unsigned char *data3 = stbi_load(name3, &width3, &height3, &nrChannels3, 0);

    int width4, height4, nrChannels4;
    char* name4 = new char[]{"/home/cruelper/university/graphics/labs/opengl/4.jpg"};
    unsigned char *data4 = stbi_load(name4, &width4, &height4, &nrChannels4, 0);

    glGenTextures( 1, &tex[0] );
    glBindTexture( GL_TEXTURE_2D, tex[0] );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
//    glTexImage2D( GL_TEXTURE_2D, 0,GL_RGBA, 2, 2, 0, GL_RGBA, GL_UNSIGNED_BYTE, data );
    glTexImage2D(GL_TEXTURE_2D, 0, 3, width, height,0, GL_RGB, GL_UNSIGNED_BYTE,data);

    glGenTextures( 1, &tex[1] );
    glBindTexture( GL_TEXTURE_2D, tex[1] );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
//    glTexImage2D( GL_TEXTURE_2D, 0,GL_RGBA, 2, 2, 0, GL_RGBA, GL_UNSIGNED_BYTE, data );
    glTexImage2D(GL_TEXTURE_2D, 0, 3, width2, height2,0, GL_RGB, GL_UNSIGNED_BYTE,data2);

    glGenTextures( 1, &tex[2] );
    glBindTexture( GL_TEXTURE_2D, tex[2] );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
//    glTexImage2D( GL_TEXTURE_2D, 0,GL_RGBA, 2, 2, 0, GL_RGBA, GL_UNSIGNED_BYTE, data );
    glTexImage2D(GL_TEXTURE_2D, 0, 3, width3, height3,0, GL_RGB, GL_UNSIGNED_BYTE,data3);

    glGenTextures( 1, &tex[3] );
    glBindTexture( GL_TEXTURE_2D, tex[3] );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST );
//    glTexImage2D( GL_TEXTURE_2D, 0,GL_RGBA, 2, 2, 0, GL_RGBA, GL_UNSIGNED_BYTE, data );
    glTexImage2D(GL_TEXTURE_2D, 0, 3, width4, height4,0, GL_RGB, GL_UNSIGNED_BYTE,data4);

}

float angle = 0;
void timer( int value ) {
    angle += 1;
    glutPostRedisplay();
    glutTimerFunc( 16, timer, 0 );
}

void display() {
    glClearColor( 0, 0, 0, 1 );
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    gluPerspective( 60, 1.0, 0.1, 100.0 );

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();
    glTranslatef( 0, 0, -8 );

    glEnable( GL_CULL_FACE );
    glEnable( GL_DEPTH_TEST );

    glRotatef( angle, 0.2, 0.3, 0.1 );

    glEnable( GL_TEXTURE_2D );
    glBindTexture( GL_TEXTURE_2D, tex[0] );
    cylinder();

    glRotatef( -angle, 0, 0, -1 );
    glBindTexture( GL_TEXTURE_2D, tex[1] );
    cope();

    glRotatef( angle, 1, 2, -2 );
    glBindTexture( GL_TEXTURE_2D, tex[2] );
    disk();

    glRotatef( -2*angle, -2, 0, 1 );
    glBindTexture( GL_TEXTURE_2D, tex[3] );
    halfDisk();

    glutSwapBuffers();
}

int main(int argc, char **argv) {
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE );
    glutInitWindowSize( 1280, 720 );
    glutCreateWindow( "OpenGL" );
    init();
    glutDisplayFunc( display );
    glutTimerFunc( 0, timer, 0 );
    glutMainLoop();
    return 0;
}