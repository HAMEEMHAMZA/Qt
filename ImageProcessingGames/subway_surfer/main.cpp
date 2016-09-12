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
int flag=0;
int loop;
unsigned int mov;

int xmd[5],ymd[5];
int deci;


int exitf();
void move(unsigned int a);
void left();
void right();
void LeftClick();
void MouseMove (int x, int y );
void jump();
void display(int x, int y);
void update();
int decide();
void down();
int count;
CvCapture* capture= cvCreateCameraCapture(0);


unsigned long xco=0;
unsigned long yco=0;

unsigned long xmid=0;
unsigned long ymid=0;
unsigned long infi=0;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
/////////////////////////////////////////////
    cvNamedWindow("cam",0);
       while(1)  //loop for video
               {
           if(exitf()==0)return 0;
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



                                  if(ptr[3*x]<50&&ptr[3*x+1]<40&&ptr[3*x+2]>160)
                                  {
                                      //ptr[3*x] = 0;// blue of BGRA
                                      //ptr[3*x+1] =0; //green of BGRA
                                      //ptr[3*x+2] =220; //red of BGRA

                                      infi++;
                                      xco+=x;
                                      yco+=y;
                                  }


                              }
                           }




                           xmid=xco/(infi+1);
                           ymid=yco/(infi+1);
                           update();
                           deci=decide();



                           if(xmid>440&&xmid<641&&ymid>70&&ymid<360&&flag==0){
                               flag=1;
                               left();
                           }

                           else if(xmid>1&&xmid<200&&ymid>70&&ymid<360&&flag==0){
                               flag=1;
                               right();
                           }


                           else if(deci==4&&flag==0){
                               flag=1;
                               down();
                              // cvWaitKey(30);
                           }
                           else if(deci==1&&flag==0){
                               flag=1;
                               jump();
                              // cvWaitKey(30);
                           }


                           else if(xmid>200&&xmid<440&&ymid>100&&ymid<330)
                               flag=0;
                           yco=0;xco=0;infi=0;
                           display(xmid,ymid);
   ///////////////////////////////////////////////////////////////////////////
   ////////////////////////////////////////////


    ///////////////////////////////////////////////////////////////////////////////////
                   cvShowImage("cam",frame);
                   cvWaitKey(31);

               }
       return a.exec();
   }


void update(){
    for(int p=0;p<4;p++){
        xmd[p]=xmd[p+1];
    }
    xmd[4]=xmid;

    for(int n=0;n<4;n++){
        ymd[n]=ymd[n+1];
    }
    ymd[4]=ymid;

}

int decide(){
    //1-jump, 2-left, 3-right, 4-down
  //  if(ymid<170&&ymid>1)

 if(ymid<100&&ymid>1)
     if(ymd[0]>ymd[1]+30||ymd[1]>ymd[2]+30||ymd[2]>ymd[3]+30||ymd[3]>ymd[4]+30)
        return 1;
 // if(ymid>290)
    if(ymid>330&&ymid<481)
    if(ymd[0]<ymd[1]-30||ymd[1]<ymd[2]-30||ymd[2]<ymd[3]-30||ymd[3]<ymd[4]-30)
    return 4;

    return 0;
}
//ymd[0]>ymd[1]&&ymd[1]>ymd[2]&&
//&&ymd[2]>ymd[3]&&ymd[3]>ymd[4]
