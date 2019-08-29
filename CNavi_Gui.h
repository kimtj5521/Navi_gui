#ifndef CNAVI_GUI_H
#define CNAVI_GUI_H

#include <QDialog>
#include <math.h>
#include <QImage>
#include <QPixmap>
#include <QtGui>
#include <QTimer>
#include <QDebug>
#include <QBrush>
#include <QGraphicsEllipseItem>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>

#include <stdio.h>
#include <iostream>

#include "ros_subscribe.h"
#include "ros_publish.h"

#define CUR_X 250
#define CUR_Y 400

#define VEHICLE_DISPLAY_SCALE 10

using namespace std;

namespace Ui {
class CNavi_Gui;
}

class CNavi_Gui : public QDialog
{
    Q_OBJECT

public:
    explicit CNavi_Gui(QWidget *parent = nullptr);
    ~CNavi_Gui();

private:
    Ui::CNavi_Gui *ui;
    QTimer* pt_qtimer;

private slots:
    void on_pushButton_start_clicked();
    void on_pushButton_stop_clicked();
    void on_pushButton_subscribe_start_clicked();
    void on_pushButton_subscribe_stop_clicked();
    void on_pushButton_gps_init_clicked();
    void on_pushButton_exit_clicked();

public slots:
    void displaying(void);

public:
    QGraphicsScene* scene;
    QGraphicsEllipseItem *ellipse;

    double point_x = 0.0;
    double point_y = 0.0;

    double gps_x = 0.0;
    double gps_y = 0.0;
    double gps_heading = 0.0;
    double pos_x = 0.0;
    double pos_y = 0.0;
    double pos_heading = 0.0;

    double get_position = 0.0;
    double get_heading = 0.0;
    double POS_init = 1.0;
    double GPS_init = 0.0;
    double vehicle_speed = 0.0;

    ros_subscribe m_ros_sub;

    bool subscribe_check = false;

    ros_publish m_ros_pub;
};

#endif // CNAVI_GUI_H
