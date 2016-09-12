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


void LeftClick();
void MouseMove (int x, int y );

double scrnwid();
double scrnht();
int exitf();

int xglo,yglo;
int digit=99;

int test1=150;
int exitm=1;

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
    exitm=0;


}


void MainWindow::on_pushButton_clicked()
{
    ui->lcdNumber->display(xglo);
    ui->lcdNumber_2->display(yglo);
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


double scrnwid(){
    return ::GetSystemMetrics( SM_CXSCREEN )-1;
}

double scrnht(){
    return ::GetSystemMetrics( SM_CYSCREEN )-1;
}

int exitf(){
    return exitm;
}
