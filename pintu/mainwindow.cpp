#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>               //标签
#include <QImage>
#include <QMessageBox>          //信息框
#include <QMouseEvent>          //鼠标点击事件
#include <iostream>             //swap
#include <math.h>               //abs
#include <QFileDialog>          //文件
#include<windows.h>            //sleep
const int N = 3;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    start = 0;          //游戏未开始

    ui->setupUi(this);
    //添加图片资源：https://www.cnblogs.com/lcgbk/p/13259754.html
    pos = ":/img/tup.jpg";
    //pos = "C:\\Users\\czh\\Desktop\\tup.jpg";
    first();


}

void MainWindow::move(int x,int y){
    int& c_x = coord[0], & c_y = coord[1];
    if( c_x == x ){
        if( abs(c_y - y ) == 1 ){
            std::swap(map[c_y][c_x],map[y][x]);
            c_x = x;
            c_y = y;
        }
    }else if( c_y == y ){
        if( abs(c_x - x ) == 1 ){
            std::swap(map[c_y][c_x],map[y][x]);
            c_x = x;
            c_y = y;
        }
    }

}

void MainWindow::move_f(int i) {
    int& x = coord[0], & y = coord[1];
    if (i == 1) {                   //上(0在下，和上面的换)
        if (y != 0) {
            std::swap(map[y][x], map[y-1][x]);
            y--;
        }

    }
    else if (i == 2) {             //下（0在上，和下面的换）
        if (y != N - 1) {
            std::swap(map[y][x], map[y+1][x]);
            y++;
        }

    }
    else if (i == 3) {             //左
        if (x != 0) {
            std::swap(map[y][x], map[y][x-1]);
            x--;
        }
    }
    else if (i == 4) {             //右
        if (x != N - 1) {
            std::swap(map[y][x], map[y][x+1]);
            x++;
        }
    }
}

void MainWindow::upset()
{
       //打乱300次
       for (int i = 0; i < 300; i++) {
           //Sleep(1000);
           move_f(rand() % 4 + 1);
           //showpicture();

       }
}

void MainWindow::showpicture(){


    //QString tmp_label = QString("QLabel_%1").arg(k);
    //QString tmp_img = QString("img%1").arg(k);
    //QLabel *p = QLabel::findChild("label_3");
    //QLabel* p =  QWidget::findChild<QLabel*>("QLabel_3");
    //QPixmap *imgd = QWidget::findChild<QPixmap*>("img6");

    int k = 3;

    for(int j = 0 ; j < N ; j++ ){
        for(int i = 0 ; i < N ; i++ ){
            QString tmp_label = QString("label_%1").arg(k);
            //tmp_img = QString("img%1").arg(map[j][i]);
            //根据控件名得到控件指针
             QLabel *p = QWidget::findChild<QLabel*>(tmp_label);
            if( map[j][i] == 0 ){
                p->setPixmap(img0);
            }else if( map[j][i] == 1 ){
                p->setPixmap(img1);
            }else if( map[j][i] == 2 ){
                p->setPixmap(img2);
            }else if( map[j][i] == 3 ){
                p->setPixmap(img3);
            }
            else if( map[j][i] == 4 ){
                p->setPixmap(img4);
            }
            else if( map[j][i] == 5 ){
                p->setPixmap(img5);
            }
            else if( map[j][i] == 6 ){
                p->setPixmap(img6);
            }
            else if( map[j][i] == 7 ){
                p->setPixmap(img7);
            }
            else if( map[j][i] == 8 ){
                p->setPixmap(img8);
            }
            k++;

        }
    }



}

//初始化
void MainWindow::first(){
    //初始化拼图
    int num = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            map[i][j] = num;
            num++;
        }
    }
    map[2][2] = 0;
    coord[0] = 2, coord[1] = 2;

    // Qt显示图片（https://blog.csdn.net/linuxweiyh/article/details/76683479）
    //ui->d_label->setScaledContents(true);

    QPixmap *pixmap = new QPixmap(pos);
    pixmap->scaled(ui->label->size(), Qt::KeepAspectRatio);
    ui->label_2->setScaledContents(true);
    ui->label_2->setPixmap(*pixmap);

    //空白图片
    QPixmap *pixmap3 = new QPixmap("C:\\Users\\czh\\Desktop\\blank1.jpg");
    pixmap3->scaled(ui->label->size(), Qt::KeepAspectRatio);
    img0 = pixmap3->copy(0, 0, pixmap3->width(), pixmap3->height());


    //ui->label_12->setScaledContents(true);
    QPixmap *pixmap1 = new QPixmap(pos);
    pixmap1->scaled(ui->label->size()*2, Qt::KeepAspectRatio);

    //切割图片
    img1 = pixmap1->copy(0, 0, pixmap1->width()/3, pixmap1->height()/3);
    img2 = pixmap1->copy(pixmap1->width()/3, 0, pixmap1->width()/3, pixmap1->height()/3);
    img3 = pixmap1->copy(pixmap1->width()/3*2, 0, pixmap1->width(), pixmap1->height()/3);
    img4 = pixmap1->copy(0, pixmap1->height()/3, pixmap1->width()/3, pixmap1->height()/3);
    img5 = pixmap1->copy(pixmap1->width()/3, pixmap1->height()/3, pixmap1->width()/3, pixmap1->height()/3);
    img6 = pixmap1->copy(pixmap1->width()/3*2, pixmap1->height()/3, pixmap1->width(), pixmap1->height()/3);
    img7 = pixmap1->copy(0, pixmap1->height()/3*2, pixmap1->width()/3, pixmap1->height());
    img8 = pixmap1->copy(pixmap1->width()/3, pixmap1->height()/3*2, pixmap1->width()/3, pixmap1->height());

    ui->label_3->setScaledContents(true);
    ui->label_4->setScaledContents(true);
    ui->label_5->setScaledContents(true);
    ui->label_6->setScaledContents(true);
    ui->label_7->setScaledContents(true);
    ui->label_8->setScaledContents(true);
    ui->label_9->setScaledContents(true);
    ui->label_10->setScaledContents(true);
    ui->label_11->setScaledContents(true);

    ui->label_3->setPixmap(img1);
    ui->label_4->setPixmap(img2);
    ui->label_5->setPixmap(img3);
    ui->label_6->setPixmap(img4);
    ui->label_7->setPixmap(img5);
    ui->label_8->setPixmap(img6);
    ui->label_9->setPixmap(img7);
    ui->label_10->setPixmap(img8);
    ui->label_11->setPixmap(img0);



}

MainWindow::~MainWindow()
{
    delete ui;
}

//开始游戏
void MainWindow::on_pushButton_clicked()
{
    start = 1;      //标记为开始游戏
    MainWindow::upset();
    MainWindow::showpicture();
}


//使用说明
void MainWindow::on_pushButton_2_clicked()
{
    //信息框（https://www.cnblogs.com/zhoug2020/p/10094855.html，注意加上头文件）
    QMessageBox::information(NULL, "游戏说明", "介绍：\n拼图游戏是一张图片分为若干块，打乱次序，将其中一块变为空白块，其只能与相邻块互换，发挥你的聪明才智来将其复原。\n操作说明：\n用鼠标点击空白块附近的图即可以将该图移到空白块的位置。");
}

//退出游戏按钮
void MainWindow::on_pushButton_4_clicked()
{
     exit(1);
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    //鼠标点击事件（https://www.cnblogs.com/aiguona/p/9999507.html）
    // 如果是鼠标左键按下
    if(event->button() == Qt::LeftButton)
   {
        /*
        if (i == 1) {       //向下           //上(0在下，和上面的换)
        else if (i == 2) {  //向上           //下（0在上，和下面的换）
        else if (i == 3) {  //向右           //左(0在右，和左面的换)
        else if (i == 4) {  //向左           //右(0在左，和右面的换)
        */
        if (ui->label_3->geometry().contains(this->mapFromGlobal(QCursor::pos())))
        {
            if( start == 0 ){
                QMessageBox::information(NULL, "提示", "请先点击开始游戏按钮");
            }else{
                //0 0
                move(0,0);
                showpicture();
             }
        }
        else if (ui->label_4->geometry().contains(this->mapFromGlobal(QCursor::pos())))
        {
            if( start == 0 ){
                QMessageBox::information(NULL, "提示", "请先点击开始游戏按钮");
            }else{
                //1 0
                move(1,0);
                showpicture();
            }
        }
        else if (ui->label_5->geometry().contains(this->mapFromGlobal(QCursor::pos())))
        {
            if( start == 0 ){
                QMessageBox::information(NULL, "提示", "请先点击开始游戏按钮");
            }else{
                //2 0
                move(2,0);
                showpicture();
            }
        }
        else if (ui->label_6->geometry().contains(this->mapFromGlobal(QCursor::pos())))
        {
            if( start == 0 ){
                QMessageBox::information(NULL, "提示", "请先点击开始游戏按钮");
            }else{
                //0 1
                move(0,1);
                showpicture();
            }
        }
        else if (ui->label_7->geometry().contains(this->mapFromGlobal(QCursor::pos())))
        {
            if( start == 0 ){
                QMessageBox::information(NULL, "提示", "请先点击开始游戏按钮");
            }else{
                // 1 1
                move(1,1);
                showpicture();
            }
        }
        else if (ui->label_8->geometry().contains(this->mapFromGlobal(QCursor::pos())))
        {
            if( start == 0 ){
                QMessageBox::information(NULL, "提示", "请先点击开始游戏按钮");
            }else{
                // 2 1
                move(2,1);
                showpicture();
            }
        }
        else if (ui->label_9->geometry().contains(this->mapFromGlobal(QCursor::pos())))
        {
            if( start == 0 ){
                QMessageBox::information(NULL, "提示", "请先点击开始游戏按钮");
            }else{
                // 0 2
                move(0,2);
                showpicture();
            }
        }
        else if (ui->label_10->geometry().contains(this->mapFromGlobal(QCursor::pos())))
        {
            if( start == 0 ){
                QMessageBox::information(NULL, "提示", "请先点击开始游戏按钮");
            }else{
                // 1 2
                move(1,2);
                showpicture();
            }
        }
        else if (ui->label_11->geometry().contains(this->mapFromGlobal(QCursor::pos())))
        {
            if( start == 0 ){
                QMessageBox::information(NULL, "提示", "请先点击开始游戏按钮");
            }else{
                // 2 2
                move(2,2);
                showpicture();

            }
        }
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    //(文件对话框：http://c.biancheng.net/view/1870.html)
    //选择单个文件
    QString curPath=QDir::currentPath();//获取系统当前目录
    //获取应用程序的路径
    QString dlgTitle="请选择图片文件"; //对话框标题
    QString filter="图片文件(*.jpg *.gif *.png);"; //文件过滤器
    QString aFileName=QFileDialog::getOpenFileName(this,dlgTitle,curPath,filter);
    pos = aFileName;
    //qDebug()<<pos;
    first();

}
