#include <QtGui/QApplication>
#include "mainwindow.h"
#include<C:\\OpenCV2.1\\include\\opencv\\highgui.h>
#include<C:\\OpenCV2.1\\include\\opencv\\cv.h>

#include <QSound>


IplImage* frame=0;
IplImage* frame1=0;
IplImage* frame2=0;
IplImage* frame3=0;

IplImage* saturate;
//IplImage* point_image=cvLoadImage("E:\\images2\\duck.jpg");


IplImage* p1=cvLoadImage("E:\\images2\\1.jpg");
IplImage* p2=cvLoadImage("E:\\images2\\2.jpg");
IplImage* p3=cvLoadImage("E:\\images2\\3.jpg");
IplImage* p4=cvLoadImage("E:\\images2\\4.jpg");
IplImage* p5=cvLoadImage("E:\\images2\\5.jpg");
IplImage* p6=cvLoadImage("E:\\images2\\6.jpg");
IplImage* gameover=cvLoadImage("E:\\images2\\gameover.jpg");
IplImage* presents=cvLoadImage("E:\\images2\\presents.jpg");

IplImage* gameover1=cvLoadImage("E:\\images1\\gameover.jpg");


int count=0;

int flag;
int flag1;

int delay=16;
//int repeat=0;

int time=0;

 CvCapture* capture= cvCreateCameraCapture(1);



 //CvCapture* capture_file= cvCreateFileCapture("E:\\duck_hunt_videos\\1.avi");

CvCapture* capture1= cvCreateFileCapture("E:\\duck_hunt_videos\\1.avi"); // introduction video
  CvCapture* capture2= cvCreateFileCapture("E:\\duck_hunt_videos\\2.avi"); // dog video
   CvCapture* capture3= cvCreateFileCapture("E:\\duck_hunt_videos\\3.avi"); // duck video



 int red1=0, green1=0;
 int xch,ych;
 int cnt=0;
 int xsmall,xlarge,ysmall,ylarge;

 QSound bells("E:\\qtsound.wav");



void sat1(IplImage* frame);
void sat2(IplImage* frame);
int display_point();

int came();

int point();



int main(int argc,char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();





 cvNamedWindow("cam",0);
  cvNamedWindow("cam_cam",0);

 //cvNamedWindow("cam1",0);
 //cvNamedWindow("cam2",0);


 //cvShowImage("cam1",presents);
 //cvWaitKey(100);

 while(1){     //main loop
        //cam1();



     time++;
     if(time==500)
     {

        cvShowImage("cam",gameover1);
        cvWaitKey(2000);
        exit(0);


     }

     /*
     if(repeat==1)
     {
         continue;
         repeat=0;
     }

     */

delay=16;

     while(1)  //loop for first video
     {

         frame1=cvQueryFrame(capture1);
         if(!frame1) break;
         cvShowImage("cam",frame1);
          cvWaitKey(delay/2);

          //came();
     }


     while(1)  //loop for second video
     {

         frame2=cvQueryFrame(capture2);
         if(!frame2) break;
          cvShowImage("cam",frame2);
         cvWaitKey(delay);
         //came();
     }


     while(1)  //loop for third video
     {

         //time++;
         frame3=cvQueryFrame(capture3);
         if(!frame3){
             cvShowImage("cam",gameover);

             exit(0);
         }
          cvShowImage("cam",frame3);
         cvWaitKey(delay);
         came();
     }



 }

    return a.exec();
}




    void sat1( IplImage* img ) {
        int x,y;
        for(y=0; y<img->height; y++ ) {
        uchar* ptr = (uchar*) (img->imageData + y * img->widthStep);
           for(x=0; x<img->width; x++ ) {

               //if(ptr[3*x]<60&&ptr[3*x+1]<60&&ptr[3*x+2]>150)   //red

             //if(ptr[3*x]<2&&ptr[3*x+1]<2&&ptr[3*x+2]>240) //black bckgnd red laser

               //if(ptr[3*x]<75&&ptr[3*x+1]<75&&ptr[3*x+2]>180) //ee cellar seminar hall without screen
                if(ptr[3*x]<65&&ptr[3*x+1]<65&&ptr[3*x+2]>150)


               {
                   red1=1;

                   xch=x;
                   ych=y;
                   break;
                   //break;


               }

              // ptr[3*x] = 155;// blue of BGRA
               // ptr[3*x+1] = 220; //green of BGRA
               // ptr[3*x+2] =0; //red of BGRA
                //ptr[3*x+3] = 0; // A of BGRA


           }
        }
    }




/*
    void sat2( IplImage* img ) {
        int x,y;
        //int px=0,py=0;
        for(y=0; y<img->height; y++ ) {
        uchar* ptr = (uchar*) (img->imageData + y * img->widthStep);
           for(x=0; x<img->width; x++ ) {

               if(ptr[3*x]<60&&ptr[3*x+1]>150&&ptr[3*x+2]<60){
                   //px+=x;
                   //py+=y;
                   //cnt++;

                   if(x<xsmall)
                       xsmall=x;
                   if(x>xlarge)
                       xlarge=x;
                   if(y<ysmall)
                       ysmall=y;
                   if(y>ylarge)
                       ylarge=y;


               }

              // ptr[3*x] = 155;// blue of BGRA
               // ptr[3*x+1] = 220; //green of BGRA
               // ptr[3*x+2] =0; //red of BGRA
                //ptr[3*x+3] = 0; // A of BGRA


           }
        }
           //cnt++;
       // px=px/cnt;
       // py=py/cnt;
        //if(fabs(px-xch)<250&&fabs(py-ych)<250)

        if((xch>xsmall)&&(xch<xlarge)&&(ych>ysmall)&&(ych<ylarge))
            green1=1;
    }


    */


int point()
{
    count++;
    delay=delay-2;
    return(count);
    flag1=1;
}


int display_point(){

    if(count==1){
      cvShowImage("cam",p1);
     cvWaitKey(3000);
    flag=1;
    flag1=0;

    }
    else if(count==2){
        cvShowImage("cam",p2);
     cvWaitKey(3000);
     flag=1;
    }
    else if(count==3){
      cvShowImage("cam",p3);
     cvWaitKey(3000);
     flag=1;
    }
    else if(count==4){
      cvShowImage("cam",p4);
     cvWaitKey(3000);
     flag=1;
    }
    else if(count==5){
      cvShowImage("cam",p5);
      cvWaitKey(3000);
      flag=1;
    }
    else if(count==6){
      cvShowImage("cam",gameover);
      cvWaitKey(3500);
      count=0;
      flag=1;
        // repeat=1;


    }

    return(0);

}



int came()
{


           frame=cvQueryFrame(capture);
           if(!frame) return(0);
           xsmall=(frame->width)/2;
           xlarge=(frame->width)/2;
           ysmall=(frame->height)/2;
           ylarge=(frame->height)/2;


           cvShowImage("cam_cam",frame);
           sat1(frame);
           if(red1==1&&flag==0&&flag1==0){
             // sat2(frame);
               //flag=0;
               bells.play();



               count=point();

              display_point();
           cvWaitKey(100);


           }
           else
              { flag=0;
               flag1=0;
           }


               //if(green1==1)
               //bells.play();

           cvWaitKey(4);
           red1=0;
           green1=0;

           cnt=0;

        return(0);

}
