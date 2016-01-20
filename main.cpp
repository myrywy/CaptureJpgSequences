#include <QCoreApplication>
#include <opencv2/opencv.hpp>

#include <QtSql>
#include <QtSql/QSqlDatabase>
#include <QDir>
#include <QFile>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    /*
     * Baza
     */
    QSqlDatabase database = QSqlDatabase::addDatabase("QMYSQL","my_sql_db");
    /*db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setDatabaseName("herring");
    db.setUserName("user1");
    db.setPassword("herring1");*/

/*
    //database.setHostName("192.168.0.17");
    database.setHostName("localhost");
    database.setPort(3306);
    //database.setDatabaseName("zdjecia");
    database.setDatabaseName("test1");
    database.setUserName("root");
    database.setPassword("admin");

    //db=new QSqlDatabase(database);

    if (!database.open())
    {
        qDebug() << "Błąd: nie można się połączyć z bazą!";
    }
    else
    {
        qDebug() << "Nawiązano połączenie z bazą danych.";
    }*/

    cv::Mat image;//= cv::imread("pic.jpg");
    cv::namedWindow("Camera");
    cv::VideoCapture cam(0);
    QDir dir;
    QStringList subdirs=dir.entryList();
    int max=0;
    for(QString& s : subdirs){
        bool ok;
        int j=s.toInt(&ok);
        if(ok){
            if(j>max){
                max=j;
            }
        }
    }
    QString newPath=QString::number(max+1);
    QString newPathR=newPath+"R";
    QDir dirR(dir);
    dir.mkdir(newPath);
    dir.cd(newPath);
    dirR.mkdir(newPathR);
    dirR.cd(newPathR);
    qDebug() << subdirs;
    int i=0;
    double ratio{160.0/90.0};
    while(cv::waitKey(30)!=30){
        cam >> image;
        int width=image.cols;
        int height=width/ratio;
        cv::Rect rect(0,0,width,height);
        cv::Mat roi=image(rect);

        QString filename=dir.path()+"/"+QString::number(i)+".jpg";
        QString filenameR=dirR.path()+"/"+QString::number(i)+".jpg";
        cv::imwrite(filename.toStdString(),image);
        cv::imwrite(filenameR.toStdString(),roi);

        cv::imshow("Camera", image);
        cv::imshow("roi", roi);
        i++;
    }
    //cv::waitKey(1000);

    return a.exec();
}
