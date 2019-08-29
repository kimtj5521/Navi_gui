#include "CNavi_Gui.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    if( !ros::isInitialized() )
    {
        ros::init( argc, argv, "RosQt", ros::init_options::AnonymousName );
    }

    QApplication a(argc, argv);
    CNavi_Gui w;
    w.show();

    return a.exec();
}
