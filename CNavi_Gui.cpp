#include "CNavi_Gui.h"
#include "ui_CNavi_Gui.h"

CNavi_Gui::CNavi_Gui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CNavi_Gui)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    pt_qtimer = new QTimer(this);
    connect(pt_qtimer, SIGNAL(timeout()), this, SLOT(displaying()));

    ui->pushButton_stop->setEnabled(false);
    ui->pushButton_subscribe_stop->setEnabled(false);
}

CNavi_Gui::~CNavi_Gui()
{
    delete ui;
}

void CNavi_Gui::on_pushButton_start_clicked()
{
    ui->pushButton_start->setEnabled(false);
    ui->pushButton_stop->setEnabled(true);
    pt_qtimer->start(10);
}

void CNavi_Gui::on_pushButton_stop_clicked()
{
    ui->pushButton_start->setEnabled(true);
    ui->pushButton_stop->setEnabled(false);
    pt_qtimer->stop();
}

void CNavi_Gui::displaying()
{
    gps_x = m_ros_sub.ros_gps_x;
    gps_y = m_ros_sub.ros_gps_y;
    gps_heading = m_ros_sub.ros_gps_heading;
    pos_x = m_ros_sub.ros_pos_x;
    pos_y = m_ros_sub.ros_pos_y;
    pos_heading = m_ros_sub.ros_pos_heading;

    get_position = m_ros_sub.ros_get_position;
    get_heading = m_ros_sub.ros_get_heading;
    POS_init = m_ros_sub.ros_POS_init;
    GPS_init = m_ros_sub.ros_GPS_init;
    vehicle_speed = m_ros_sub.ros_vehicle_speed;

    ui->lineEdit_gps_x->setText(QString::number(gps_x));
    ui->lineEdit_gps_y->setText(QString::number(gps_y));
    ui->lineEdit_gps_heading->setText(QString::number(gps_heading));
    ui->lineEdit_pos_x->setText(QString::number(pos_x));
    ui->lineEdit_pos_y->setText(QString::number(pos_y));
    ui->lineEdit_pos_heading->setText(QString::number(pos_heading));

    if(get_position == 1.0){
        ui->lineEdit_get_position->setText("OK");
    }
    else {
        ui->lineEdit_get_position->setText("False");
    }
    if(get_heading == 1.0){
        ui->lineEdit_get_heading->setText("OK");
    }
    else {
        ui->lineEdit_get_heading->setText("False");
    }
    if(POS_init == 1.0){
        ui->lineEdit_pos_init->setText("initializing...");
    }
    else {
        ui->lineEdit_pos_init->setText("Done.");
    }
    if(GPS_init == 1.0){
        ui->lineEdit_gps_init->setText("GPS_init !!!");
    }
    else {
        ui->lineEdit_gps_init->setText("false");
    }

    ui->lineEdit_vehicle_speed->setText(QString::number(vehicle_speed));

    //point_x = pos_x - gps_x;
    //point_y = pos_y - gps_y;
    //point_x = pos_x ;
    //point_y = pos_y ;
    point_x = (pos_x - gps_x)*cos(pos_heading*M_PI/180.0)+(pos_y - gps_y)*sin(pos_heading*M_PI/180.0);
    point_y = -(pos_x - gps_x)*sin(pos_heading*M_PI/180.0)+(pos_y - gps_y)*cos(pos_heading*M_PI/180.0);

    scene->clear();
    ui->graphicsView->setScene(scene);

    for (int x=0; x<=500; x+=50)
        scene->addLine(x,0,x,500, QPen(Qt::red));

    // Now add the horizontal lines, paint them green
    for (int y=0; y<=500; y+=50)
        scene->addLine(0,y,500,y, QPen(Qt::green));

    scene->addRect(CUR_X-8, CUR_Y-25,16,40);

    scene->addEllipse(CUR_X-5+point_y*VEHICLE_DISPLAY_SCALE, CUR_Y-5+point_x*VEHICLE_DISPLAY_SCALE, 10, 10, QPen(Qt::blue), QBrush(Qt::blue));

    // Fit the view in the scene's bounding rect
    ui->graphicsView->fitInView(scene->itemsBoundingRect());
    ui->graphicsView->update();
    ui->graphicsView->items().clear();
    ui->graphicsView->clearMask();

    if(subscribe_check == true){
        ui->label_Subscribe_status->setText("ros_subscribe success!");
    }
    else {
        ui->label_Subscribe_status->setText("ros_subscribe failed..");
    }
}

void CNavi_Gui::on_pushButton_subscribe_start_clicked()
{
    ui->pushButton_subscribe_start->setEnabled(false);
    ui->pushButton_subscribe_stop->setEnabled(true);
    subscribe_check = m_ros_sub.thread_start();
}

void CNavi_Gui::on_pushButton_subscribe_stop_clicked()
{
    ui->pushButton_subscribe_start->setEnabled(true);
    ui->pushButton_subscribe_stop->setEnabled(false);
    m_ros_sub.thread_stop();
}

void CNavi_Gui::on_pushButton_gps_init_clicked()
{
    m_ros_pub.publish_topic();
}

void CNavi_Gui::on_pushButton_exit_clicked()
{
    this->close();
}
