#ifndef SUNSYSTEM_DISPLAY
#define SUNSYSTEM_DISPLAY

#include <vector>
#include <stdio.h>
#include <QMap>

#include <QtWidgets>
#include <QtOpenGL/QGLWidget>
#include <GL/GL.h>
#include <GL/GLU.h>
#include <gl/GLU.h>
#include "sunsystem_body.h"


typedef struct {
    int W;
    int H;
    unsigned char *Image;
}Tex;

#define TEX_N 9

class Sunsystem_display : public QGLWidget
{
    Q_OBJECT
private:
    double lx, rx, by, ty; //dekart coords of screen
    Sunsystem_body *pSSB;

    Tex	s_loadtex;

    QMap<uint, GLuint> textures;

    void TexLoad(const char *filename, GLuint &tex_id)
    {
        qDebug() << "xxxxxxxx";
        FILE *F;
        if ((F = fopen(filename, "rb")) == nullptr) return;
        //ТУТ ЯКИЙСЬ БАГ!!!
        //fseek(F, 18, SEEK_SET);
        //fread(&(s_loadtex.W), 2, 1, F);
        //fseek(F, 2, SEEK_CUR);
        //fread(&(s_loadtex.H), 2, 1, F);
        //qDebug() << s_loadtex.W <<"  " << s_loadtex.H;
        s_loadtex.W = 256;
        s_loadtex.H = 256;
        if ((s_loadtex.Image = (unsigned char *)malloc(sizeof(unsigned char) * 4 * s_loadtex.W*s_loadtex.H)) == nullptr){
            fclose(F);
            return;
        }
        fseek(F, 30, SEEK_CUR);
        fread(s_loadtex.Image, 4, s_loadtex.W*s_loadtex.H, F);
        glGenTextures(1, &tex_id);
        glBindTexture(GL_TEXTURE_2D, tex_id);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR); //GL_NEAREST
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR); //GL_LINEAR_MIPMAP_LINEAR
        gluBuild2DMipmaps(GL_TEXTURE_2D, 4, s_loadtex.W, s_loadtex.H, GL_BGRA_EXT, GL_UNSIGNED_BYTE, s_loadtex.Image);
        free(s_loadtex.Image);
        fclose(F);
    }

    void drawPlanet(const planet &p){
        glEnable(GL_TEXTURE_2D);
        glEnable(GL_BLEND);
        glBindTexture(GL_TEXTURE_2D, textures[p.number+1]);
        glBegin(GL_QUADS);
        glTexCoord2d(0, 1); glVertex2d(p.posx - p.mass, p.posy - p.mass);
        glTexCoord2d(0, 0); glVertex2d(p.posx + p.mass, p.posy - p.mass);
        glTexCoord2d(1, 0); glVertex2d(p.posx + p.mass, p.posy + p.mass);
        glTexCoord2d(1, 1); glVertex2d(p.posx - p.mass, p.posy + p.mass);
        glEnd();
        glDisable(GL_TEXTURE_2D);
        glDisable(GL_BLEND);
    }
    void drawSun(double rad){
        glEnable(GL_TEXTURE_2D);
        glEnable(GL_BLEND);
        glBindTexture(GL_TEXTURE_2D, textures[0]);
        glBegin(GL_QUADS);
        glTexCoord2d(0, 1); glVertex2d(-rad, -rad);
        glTexCoord2d(0, 0); glVertex2d(+rad, -rad);
        glTexCoord2d(1, 0); glVertex2d(+rad, +rad);
        glTexCoord2d(1, 1); glVertex2d(-rad, +rad);
        glEnd();
        glDisable(GL_TEXTURE_2D);
        glDisable(GL_BLEND);
    }

protected:
    virtual void initializeGL(){
        glEnable(GL_POINT_SMOOTH);
        glEnable(GL_LINE_SMOOTH);
        glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        qglClearColor(Qt::black);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        ///////////////////TEX////////////////////////////
        GLuint texture;
        TexLoad("D:/Temp/Sun_system/Sunsys/images/0.bmp", texture);
        textures[0] = texture;
        for (int i = 1; i < TEX_N; i++){
            ///////ТУТ_ШЛЯХ_ДО_ПАПКИ_IMAGES///////////////////
            QString str("D:/Temp/Sun_system/Sunsys/images/");
            str += QString::number(i, 10);
            str += ".bmp";
            TexLoad(str.toStdString().c_str(), texture);
            textures[i] = texture;
        }
    }
    virtual void resizeGL(int nWidth, int nHeight){
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glViewport(0, 0, (GLint)nWidth, (GLint)nHeight);
        gluOrtho2D(lx, rx, by, ty);//set decart coords
    }
    virtual void paintGL(){
        makeCurrent();//робить цей віджет поточним контекстом для промальовки
        glClear(GL_COLOR_BUFFER_BIT);
        vector<planet> *planets = pSSB->getSomePlanets();
        drawSun(17);
        for (int i = 0; i < planets->size(); i++){
            drawPlanet((*planets)[i]);
        }
    }
public:
    Sunsystem_display(double x_left,   double x_right,
                      double y_bottom, double y_top,
                      Sunsystem_body *system,
                      QWidget *parent = 0)
        : QGLWidget(parent),
          pSSB(system),
          lx(x_left),
          rx(x_right),
          by(y_bottom),
          ty(y_top){}
    //void set_trails(){}
    void draw(){paintGL();}
};


#endif // SUNSYSTEM_DISPLAY

