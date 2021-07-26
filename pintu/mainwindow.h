#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    int map[3][3];       //注意前面是y，后面才是x！！！！！！
    int coord[2];        //空位置的x,y坐标
    QString pos;         //图片位置
    int start;           //标记是否开始游戏


    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void mousePressEvent(QMouseEvent *event);       //鼠标点击事件
    void move(int x,int y);       //移动
    void move_f(int i);     //有方向的移动
    void upset();           //打乱
    void showpicture();     //显示
    void first();           //初始化
    QPixmap img1,img2,img3,img4,img5,img6,img7,img8,img0;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
