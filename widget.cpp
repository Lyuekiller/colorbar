#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QColor>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::paintEvent(QPaintEvent *event){
    QPainter painter(this);
        QColor color;
        QRect section;
        float colorBarLength=343.0;//设置颜色条的长度

        //------设置为gray颜色条---------//
        for(int i=0;i<=colorBarLength;i++)// gray
        {
           //color.setRgbF(i/colorBarLength,i/colorBarLength,i/colorBarLength);//也可以使用这种方法
           color.setHsv(0,0,(colorBarLength-i)/colorBarLength*255);
           section.setRect(150,50+i*1,20,1);
           painter.fillRect(section,color);
        }

        //------设置为jet颜色条---------//
        float tempLength=colorBarLength/4;
        for(int i=0;i<tempLength/2;i++)// jet
        {
            color.setRgbF(0,0,(tempLength/2+i)/tempLength);
            section.setRect(200,colorBarLength+50-i*1,20,1);
            painter.fillRect(section,color);
        }
        for(int i=tempLength/2+1;i<tempLength/2+tempLength;i++)// jet
        {
            color.setRgbF(0,(i-tempLength/2)/tempLength,1);
            section.setRect(200,colorBarLength+50-i*1,20,1);
            painter.fillRect(section,color);
        }
        for(int i=tempLength/2+tempLength+1;i<tempLength/2+2*tempLength;i++)// jet
        {
            color.setRgbF((i-tempLength-tempLength/2)/tempLength,1,(tempLength*2+tempLength/2-i)/tempLength);
            section.setRect(200,colorBarLength+50-i*1,20,1);
            painter.fillRect(section,color);
        }
        for(int i=tempLength/2+2*tempLength+1;i<tempLength/2+3*tempLength;i++)// jet
        {
            color.setRgbF(1,(tempLength*3+tempLength/2-i)/tempLength,0);
            section.setRect(200,colorBarLength+50-i*1,20,1);
            painter.fillRect(section,color);
        }
        for(int i=tempLength/2+3*tempLength+1;i<colorBarLength;i++)// jet
        {
            color.setRgbF((colorBarLength-i+tempLength/2)/(tempLength),0,0);
            section.setRect(200,colorBarLength+50-i*1,20,1);
            painter.fillRect(section,color);
        }
        //------设置为hsv颜色条---------//
        for(int i=0;i<=colorBarLength;i++)// hsv
        {
            color.setHsvF(i/colorBarLength,1,1);
            section.setRect(250,colorBarLength+50-i*1,20,1);
            painter.fillRect(section,color);
        }
        //------设置为hot颜色条---------//
        tempLength=colorBarLength/2.5;
        for(int i=0;i<tempLength/2;i++)// hot
        {
            color.setRgbF((tempLength/2+i)/tempLength,0,0);
            section.setRect(300,colorBarLength+50-i*1,20,1);
            painter.fillRect(section,color);
        }
        for(int i=tempLength/2+1;i<tempLength/2+tempLength;i++)// hot
        {
            color.setRgbF(1,(i-tempLength/2)/tempLength,0);
            section.setRect(300,colorBarLength+50-i*1,20,1);
            painter.fillRect(section,color);
        }

        for(int i=tempLength/2+tempLength+1;i<colorBarLength;i++)// hot
        {
            color.setRgbF(1,1,(i-tempLength/2-tempLength)/(colorBarLength-tempLength/2-tempLength+20));
            section.setRect(300,colorBarLength+50-i*1,20,1);
            painter.fillRect(section,color);
        }
        //---------设置边框--------------//
        //刻度值的绘制可以自己设计，使用drawText函数即可,刻度的绘制可以使用drawLine函数
        painter.setPen(Qt::black);
        painter.drawRect(150,50,20,colorBarLength);
        painter.setFont(QFont(QString::fromLocal8Bit("宋体"),10,-1,false));
        painter.drawText(130,55,QStringLiteral("-3"));
        painter.drawText(130,55+colorBarLength,QStringLiteral("-1"));
        painter.drawText(150,40,QStringLiteral("Gray"));

        painter.drawRect(200,50,20,colorBarLength);
        painter.setFont(QFont(QString::fromLocal8Bit("宋体"),10,-1,false));
        painter.drawText(200,40,QStringLiteral("Jet"));

        painter.drawRect(250,50,20,colorBarLength);
        painter.setFont(QFont(QString::fromLocal8Bit("宋体"),10,-1,false));
        painter.drawText(250,40,QStringLiteral("Hsv"));

        painter.drawRect(300,50,20,colorBarLength);
        painter.setFont(QFont(QString::fromLocal8Bit("宋体"),10,-1,false));
        painter.drawText(300,40,QStringLiteral("Hot"));
       // painter.drawText(150,320,QStringLiteral(" 0"));
}
