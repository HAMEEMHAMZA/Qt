#include <QtGui/QApplication>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<C:\\OpenCV2.1\\include\\opencv\\highgui.h>
#include<C:\\OpenCV2.1\\include\\opencv\\cv.h>
#include <QTimer>


IplImage* frame=0;
IplImage* vid=0;
IplImage* modified=0;
IplImage* img;
unsigned int mov;

void display(int x,int y);
void move(unsigned int a);
int count;
void MouseMove(int, int);
void LeftClickUp ();
void LeftClickDown ();
int flagd=0,flagu=1;
double scrnwid();
double scrnht();
int exitk;
int exitf();


CvCapture* capture= cvCreateCameraCapture(0);


unsigned long xco=0;
unsigned long yco=0;

unsigned long xmid=0;
unsigned long ymid=0;
unsigned long infi=0;

double scrw;
double scrh;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    scrw=scrnwid();
    scrh=scrnht();
/////////////////////////////////////////////
    cvNamedWindow("cam",0);
       while(1)  //loop for video
               {

           if(!exitf())return (0);
                   frame=cvQueryFrame(capture);
                   if(!frame) break;
                   ///////////////////////////////////////////////////////////////////////////////////////
                   /////////////////////////////////////////////////////////////////////////////////////////////
                   int x,y;
                           for(y=0; y<frame->height; y++ ) {
                           uchar* ptr = (uchar*) (frame->imageData + y * frame->widthStep);
                              for(x=0; x<frame->width; x++ ) {
   /////////////////////////////////////////////////////////////////////////////
   /////////////////////////////////////////////////////////////////////////////



                                  if(ptr[3*x]<60&&ptr[3*x+1]<60&&ptr[3*x+2]>160)
                                  {

                                      //ptr[3*x] = 0;// blue of BGRA
                                      //ptr[3*x+1] =0; //green of BGRA
                                      //ptr[3*x+2] =220; //red of BGRA

                                      infi++;
                                      xco+=x;
                                      yco+=y;
                                      //count++;
                                  }


                              }
                           }
                           /*
                           if(xmid>((frame->width/2)+75))
                               mov=1;
                           else if(xmid>((frame->width/2)-75))
                               mov=1;
                           else
                               mov=2;
                          // move(mov);
                          */


                           xmid=xco/(infi+1);
                           ymid=yco/(infi+1);


                           display(xmid,ymid);

                           if(flagu==0&&infi<40){

                               LeftClickUp();
                               flagd=0;
                               flagu=1;
                           }
                           else if(infi>=40)
                           {
                               //if(flagd==0)
                               LeftClickDown();

                               MouseMove(scrw-(xmid*scrw/640),(ymid*scrh/480));
                                flagd=1;
                                flagu=0;
                           }

                           yco=0;xco=0;infi=0;
   ///////////////////////////////////////////////////////////////////////////
   ////////////////////////////////////////////
                   cvShowImage("cam",frame);
                   cvWaitKey(15);

               }

       return a.exec();
   }
