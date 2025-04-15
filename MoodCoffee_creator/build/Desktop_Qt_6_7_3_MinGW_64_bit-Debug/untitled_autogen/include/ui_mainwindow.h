/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QTabWidget *tabWidget;
    QWidget *tab1wake;
    QFrame *frame_2;
    QPushButton *pushButton;
    QLabel *label_4;
    QLabel *label_8;
    QWidget *tab2face;
    QFrame *frame_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QLabel *label;
    QLabel *label_5;
    QLabel *label_9;
    QLabel *label_19;
    QTextEdit *textEdit;
    QTextEdit *textEdit_2;
    QPushButton *pushButton_11;
    QWidget *tab3;
    QFrame *frame_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton_5;
    QLabel *label_6;
    QLabel *label_10;
    QLabel *label_2;
    QLabel *label_3;
    QTextEdit *textEdit_3;
    QTextEdit *textEdit_4;
    QTextEdit *textEdit_5;
    QTextEdit *textEdit_6;
    QWidget *tab4;
    QFrame *frame_6;
    QPushButton *pushButton_6;
    QLabel *label_7;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_20;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1024, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(0, 0, 1024, 600));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        tabWidget = new QTabWidget(frame);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setEnabled(true);
        tabWidget->setGeometry(QRect(0, -50, 1024, 660));
        tabWidget->setStyleSheet(QString::fromUtf8(""));
        tab1wake = new QWidget();
        tab1wake->setObjectName("tab1wake");
        tab1wake->setStyleSheet(QString::fromUtf8("background-color: #4A3C3B;\n"
""));
        frame_2 = new QFrame(tab1wake);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(0, 0, 1024, 660));
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        pushButton = new QPushButton(frame_2);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(-10, 140, 1031, 441));
        QFont font;
        font.setPointSize(36);
        pushButton->setFont(font);
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #E5D4C2; \n"
"    color: #4A3C3B;\n"
"    border-radius: 5px;                \n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #C56C34;\n"
"}\n"
""));
        pushButton->setAutoDefault(false);
        label_4 = new QLabel(frame_2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 40, 111, 21));
        label_4->setStyleSheet(QString::fromUtf8("color: #E5D4C2;"));
        label_8 = new QLabel(frame_2);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(270, 60, 521, 51));
        QFont font1;
        font1.setPointSize(26);
        font1.setBold(true);
        label_8->setFont(font1);
        label_8->setStyleSheet(QString::fromUtf8("color: #E5D4C2;\n"
"border: none;"));
        tabWidget->addTab(tab1wake, QString());
        tab2face = new QWidget();
        tab2face->setObjectName("tab2face");
        tab2face->setStyleSheet(QString::fromUtf8("background-color: #4A3C3B;\n"
""));
        frame_3 = new QFrame(tab2face);
        frame_3->setObjectName("frame_3");
        frame_3->setGeometry(QRect(0, 0, 1024, 660));
        frame_3->setStyleSheet(QString::fromUtf8("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
"<ui version=\"4.0\">\n"
" <widget name=\"__qt_fake_top_level\">\n"
"  <widget class=\"QFrame\" name=\"frame_3\">\n"
"   <property name=\"geometry\">\n"
"    <rect>\n"
"     <x>0</x>\n"
"     <y>0</y>\n"
"     <width>1024</width>\n"
"     <height>660</height>\n"
"    </rect>\n"
"   </property>\n"
"   <property name=\"frameShape\">\n"
"    <enum>QFrame::Shape::StyledPanel</enum>\n"
"   </property>\n"
"   <property name=\"frameShadow\">\n"
"    <enum>QFrame::Shadow::Raised</enum>\n"
"   </property>\n"
"  </widget>\n"
" </widget>\n"
" <resources/>\n"
"</ui>\n"
""));
        frame_3->setFrameShape(QFrame::Shape::StyledPanel);
        frame_3->setFrameShadow(QFrame::Shadow::Raised);
        pushButton_2 = new QPushButton(frame_3);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(800, 300, 101, 31));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        pushButton_2->setFont(font2);
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: #D47B40;\n"
"    color: white;\n"
"    border-radius: 5px;"));
        pushButton_4 = new QPushButton(frame_3);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(800, 400, 101, 31));
        pushButton_4->setFont(font2);
        pushButton_4->setStyleSheet(QString::fromUtf8("background-color: #D47B40;\n"
"    color: white;\n"
"    border-radius: 5px;"));
        label = new QLabel(frame_3);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 200, 251, 271));
        label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/images/1.jpg")));
        label->setScaledContents(true);
        label_5 = new QLabel(frame_3);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 40, 111, 21));
        label_5->setStyleSheet(QString::fromUtf8("color: #E5D4C2;"));
        label_9 = new QLabel(frame_3);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(340, 60, 431, 61));
        label_9->setFont(font1);
        label_9->setStyleSheet(QString::fromUtf8("color: #E5D4C2;\n"
"border: none;"));
        label_19 = new QLabel(frame_3);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(440, 280, 261, 101));
        QFont font3;
        font3.setPointSize(36);
        font3.setUnderline(false);
        label_19->setFont(font3);
        label_19->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        label_19->setStyleSheet(QString::fromUtf8("color: #C56C34;\n"
"border: none;"));
        textEdit = new QTextEdit(frame_3);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(310, 180, 431, 71));
        QFont font4;
        font4.setBold(false);
        textEdit->setFont(font4);
        textEdit->setStyleSheet(QString::fromUtf8("color: #E5D4C2;\n"
"border: none;"));
        textEdit_2 = new QTextEdit(frame_3);
        textEdit_2->setObjectName("textEdit_2");
        textEdit_2->setGeometry(QRect(300, 490, 441, 61));
        textEdit_2->setStyleSheet(QString::fromUtf8("color: #C56C34;\n"
"border: none;"));
        pushButton_11 = new QPushButton(frame_3);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setGeometry(QRect(800, 500, 101, 31));
        pushButton_11->setFont(font2);
        pushButton_11->setAutoFillBackground(false);
        pushButton_11->setStyleSheet(QString::fromUtf8("background-color: #D47B40;\n"
"    color: white;\n"
"    border-radius: 5px;"));
        pushButton_11->setAutoDefault(false);
        tabWidget->addTab(tab2face, QString());
        tab3 = new QWidget();
        tab3->setObjectName("tab3");
        frame_4 = new QFrame(tab3);
        frame_4->setObjectName("frame_4");
        frame_4->setGeometry(QRect(0, 0, 1024, 660));
        frame_4->setStyleSheet(QString::fromUtf8("background-color: #E5D4C2;\n"
""));
        frame_4->setFrameShape(QFrame::Shape::StyledPanel);
        frame_4->setFrameShadow(QFrame::Shadow::Raised);
        pushButton_3 = new QPushButton(frame_4);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(800, 300, 101, 31));
        pushButton_3->setFont(font2);
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color: #D47B40;\n"
"    color: white;\n"
"    border-radius: 5px;"));
        pushButton_5 = new QPushButton(frame_4);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(800, 400, 101, 31));
        pushButton_5->setFont(font2);
        pushButton_5->setStyleSheet(QString::fromUtf8("background-color: #D47B40;\n"
"    color: white;\n"
"    border-radius: 5px;"));
        label_6 = new QLabel(frame_4);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 40, 111, 21));
        label_6->setStyleSheet(QString::fromUtf8("color: #4A3C3B;"));
        label_10 = new QLabel(frame_4);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(340, 60, 371, 61));
        label_10->setFont(font1);
        label_10->setStyleSheet(QString::fromUtf8("color: #4A3C3B;\n"
"border: none;"));
        label_2 = new QLabel(frame_4);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(360, 250, 161, 81));
        QFont font5;
        font5.setPointSize(48);
        label_2->setFont(font5);
        label_2->setStyleSheet(QString::fromUtf8("color: #E08850;\n"
"border: none;"));
        label_3 = new QLabel(frame_4);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(360, 380, 131, 91));
        label_3->setFont(font5);
        label_3->setStyleSheet(QString::fromUtf8("color: #E08850;\n"
"border: none;"));
        textEdit_3 = new QTextEdit(frame_4);
        textEdit_3->setObjectName("textEdit_3");
        textEdit_3->setGeometry(QRect(160, 220, 461, 131));
        textEdit_3->setFrameShape(QFrame::Shape::NoFrame);
        textEdit_3->setLineWidth(0);
        textEdit_3->setCursorWidth(0);
        textEdit_4 = new QTextEdit(frame_4);
        textEdit_4->setObjectName("textEdit_4");
        textEdit_4->setGeometry(QRect(160, 350, 461, 141));
        textEdit_4->setFrameShape(QFrame::Shape::NoFrame);
        textEdit_4->setLineWidth(0);
        textEdit_4->setCursorWidth(0);
        textEdit_5 = new QTextEdit(frame_4);
        textEdit_5->setObjectName("textEdit_5");
        textEdit_5->setGeometry(QRect(530, 290, 91, 41));
        textEdit_5->setFrameShape(QFrame::Shape::NoFrame);
        textEdit_5->setLineWidth(0);
        textEdit_5->setCursorWidth(0);
        textEdit_6 = new QTextEdit(frame_4);
        textEdit_6->setObjectName("textEdit_6");
        textEdit_6->setGeometry(QRect(530, 420, 61, 51));
        textEdit_6->setFrameShape(QFrame::Shape::NoFrame);
        textEdit_6->setLineWidth(0);
        textEdit_6->setCursorWidth(0);
        textEdit_4->raise();
        textEdit_3->raise();
        pushButton_3->raise();
        pushButton_5->raise();
        label_6->raise();
        label_10->raise();
        label_2->raise();
        label_3->raise();
        textEdit_5->raise();
        textEdit_6->raise();
        tabWidget->addTab(tab3, QString());
        tab4 = new QWidget();
        tab4->setObjectName("tab4");
        frame_6 = new QFrame(tab4);
        frame_6->setObjectName("frame_6");
        frame_6->setGeometry(QRect(0, 0, 1024, 660));
        frame_6->setStyleSheet(QString::fromUtf8("background-color: #C56C34;\n"
""));
        frame_6->setFrameShape(QFrame::Shape::StyledPanel);
        frame_6->setFrameShadow(QFrame::Shadow::Raised);
        pushButton_6 = new QPushButton(frame_6);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(800, 400, 101, 61));
        pushButton_6->setFont(font2);
        pushButton_6->setStyleSheet(QString::fromUtf8("    background-color: #4A3C3B;\n"
"    color: white;\n"
"    border-radius: 5px;"));
        label_7 = new QLabel(frame_6);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(20, 40, 111, 21));
        label_7->setStyleSheet(QString::fromUtf8("color: #E5D4C2;"));
        label_11 = new QLabel(frame_6);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(70, 180, 201, 251));
        label_11->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/images/2.png")));
        label_11->setScaledContents(true);
        label_12 = new QLabel(frame_6);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(340, 60, 371, 51));
        label_12->setFont(font1);
        label_12->setStyleSheet(QString::fromUtf8("color: #E5D4C2;\n"
"border: none;"));
        label_20 = new QLabel(frame_6);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(340, 160, 381, 281));
        tabWidget->addTab(tab4, QString());
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Wake", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Mood Coffee", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Power on - Self Check", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab1wake), QCoreApplication::translate("MainWindow", "Tab 1", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "NEXT", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "BACK", nullptr));
        label->setText(QString());
        label_5->setText(QCoreApplication::translate("MainWindow", "Mood Coffee", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Mood Recognition", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "XXX", nullptr));
        textEdit->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:28pt; font-weight:700;\">Your Mood is:</span></p></body></html>", nullptr));
        textEdit_2->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:20pt; font-weight:700;\">WANT TO TEST AGAIN ?</span></p></body></html>", nullptr));
        pushButton_11->setText(QCoreApplication::translate("MainWindow", "YES!", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab2face), QCoreApplication::translate("MainWindow", "Tab 2", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "NEXT", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "BACK", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Mood Coffee", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Physical Signs", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "78 ", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "98", nullptr));
        textEdit_3->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; font-weight:700;\">Heart Rate:  </span></p></body></html>", nullptr));
        textEdit_4->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt; font-weight:700;\">SpO2 Level:  </span></p></body></html>", nullptr));
        textEdit_5->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">BPM</span></p></body></html>", nullptr));
        textEdit_6->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:14pt;\">% </span></p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab3), QCoreApplication::translate("MainWindow", "\351\241\265", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "BACK", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Mood Coffee", nullptr));
        label_11->setText(QString());
        label_12->setText(QCoreApplication::translate("MainWindow", "Coffer Maker", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:700;\">Coffee Recipe</span></p><p><br/></p><p><br/></p><p><span style=\" font-size:14pt; font-weight:700;\">Espresso</span><span style=\" font-size:14pt;\"><br/>Strong and bold shot of coffee</span></p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab4), QCoreApplication::translate("MainWindow", "\351\241\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
