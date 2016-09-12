#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QObject>

//#include<C:\\OpenCV2.1\\include\\opencv\\highgui.h>
#include<C:\\OpenCV2.1\\include\\opencv\\cv.h>

#ifdef Q_WS_WIN
    #define WINVER 0x0500
    #include "Windows.h"
    #include "WinUser.h"
#endif

#ifdef _WIN32
    #include <windows.h>

    void sleep(unsigned milliseconds)
    {
        Sleep(milliseconds);
    }
#else
    #include <unistd.h>

    void sleep(unsigned milliseconds)
    {
        usleep(milliseconds * 1000); // takes microseconds
    }
#endif


//void vol_up();
//void vol_down();
void left();
void right();
void move(unsigned int a);
void LeftClick();
void MouseMove (int x, int y );
void jump();
void display(int p,int q);
void down();
int exitf();
int xglo,yglo;
int digit=99;
int exi=1;
int test1=150;

Ui::MainWindow *uk;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    uk=ui;
    //QObject::connect(&xglo, SIGNAL(valueChanged(int)),this, SLOT(test()));

}

MainWindow::~MainWindow()
{

    delete ui;
}


void display(int p,int q)
{
    xglo=p;
    yglo=q;
    uk->lcdNumber->display(xglo);
    uk->lcdNumber_2->display(yglo);

}


void MainWindow::on_pushButton_2_clicked()
{
    exi=0;

}


void MainWindow::on_pushButton_clicked()
{
    ui->lcdNumber->display(xglo);
    ui->lcdNumber_2->display(yglo);
}



void move(unsigned int a){
    if(a==1)
        left();
    if(a==0)
        right();
}



void LeftClick ( )
{
  INPUT    Input={0};
  // left down
  Input.type      = INPUT_MOUSE;
  Input.mi.dwFlags  = MOUSEEVENTF_LEFTDOWN;
  ::SendInput(1,&Input,sizeof(INPUT));

  // left up
  ::ZeroMemory(&Input,sizeof(INPUT));
  Input.type      = INPUT_MOUSE;
  Input.mi.dwFlags  = MOUSEEVENTF_LEFTUP;
  ::SendInput(1,&Input,sizeof(INPUT));
}

void LeftClickUp ( )
{
  INPUT    Input={0};
  // left up
  ::ZeroMemory(&Input,sizeof(INPUT));
  Input.type      = INPUT_MOUSE;
  Input.mi.dwFlags  = MOUSEEVENTF_LEFTUP;
  ::SendInput(1,&Input,sizeof(INPUT));
}

void LeftClickDown ( )
{
  INPUT    Input={0};
  // left down
  Input.type      = INPUT_MOUSE;
  Input.mi.dwFlags  = MOUSEEVENTF_LEFTDOWN;
  ::SendInput(1,&Input,sizeof(INPUT));
}

void jump()
{
    MouseMove(700,500);
    LeftClickDown();
    for(test1=501;test1>300;test1=test1-2)
    {
        MouseMove(700,test1);
        sleep(1);
    }
    LeftClickUp();
    sleep(100);
}

void MouseMove (int x, int y )
{
  double fScreenWidth    = ::GetSystemMetrics( SM_CXSCREEN )-1;
  double fScreenHeight  = ::GetSystemMetrics( SM_CYSCREEN )-1;
  double fx = x*(65535.0f/fScreenWidth);
  double fy = y*(65535.0f/fScreenHeight);
  INPUT  Input={0};
  Input.type      = INPUT_MOUSE;
  Input.mi.dwFlags  = MOUSEEVENTF_MOVE|MOUSEEVENTF_ABSOLUTE;
  Input.mi.dx = fx;
  Input.mi.dy = fy;
  ::SendInput(1,&Input,sizeof(INPUT));
}

void left(){
    MouseMove(900,500);
    LeftClickDown();
    for(test1=799;test1>500;test1-=2)
    {
        MouseMove(test1,500);
        sleep(1);
    }
    LeftClickUp();
}

void right(){
    MouseMove(500,700);
    LeftClickDown();
    for(test1=520;test1<750;test1+=2)
    {
        MouseMove(test1,700);
        sleep(1);
    }
    LeftClickUp();
}

void down(){

    MouseMove(700,300);
    LeftClickDown();
    for(test1=300;test1<500;test1=test1+2)
    {
        MouseMove(700,test1);
        sleep(1);
    }
    LeftClickUp();
    sleep(5);
}

int exitf(){
    return exi;
}
