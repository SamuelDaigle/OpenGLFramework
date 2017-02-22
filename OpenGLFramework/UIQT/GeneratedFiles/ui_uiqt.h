/********************************************************************************
** Form generated from reading UI file 'uiqt.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UIQT_H
#define UI_UIQT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UIQTClass
{
public:
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QWidget *objetPage;
    QFrame *objet;
    QGridLayout *gridLayout;
    QSpinBox *positionYSpinBox;
    QSpinBox *positionXSpinBox;
    QSpinBox *couleurGSpinBox;
    QLabel *couleurRLabel;
    QSpinBox *rotationXSpinBox;
    QLabel *couleurGLabel;
    QLabel *positionZLabel;
    QLabel *couleurBLabel;
    QLabel *positionXLabel;
    QSpinBox *couleurBSpinBox;
    QLabel *rotationLabel;
    QLabel *couleurLabel;
    QSpinBox *rotationYSpinBox;
    QLabel *positionLabel;
    QLabel *scaleLabel;
    QLabel *rotationZLabel;
    QSpinBox *scaleSpinBox;
    QLabel *positionYLabel;
    QSpinBox *couleurRSpinBox;
    QSpinBox *positionZSpinBox;
    QLabel *rotationXLabel;
    QLabel *rotationYLabel;
    QSpinBox *rotationZSpinBox;
    QLabel *objetLabel;
    QWidget *cameraPage;
    QFrame *camera;
    QGridLayout *gridLayout_2;
    QLabel *label_4;
    QLabel *PosXLabel_2;
    QSpinBox *spinBox_7;
    QLabel *label_3;
    QSpinBox *spinBox_8;
    QLabel *PosXLabel_3;
    QSpinBox *spinBox_9;
    QLabel *PosXLabel_4;
    QSpinBox *spinBox_10;
    QLabel *PosXLabel_5;
    QSpinBox *spinBox_11;

    void setupUi(QMainWindow *UIQTClass)
    {
        if (UIQTClass->objectName().isEmpty())
            UIQTClass->setObjectName(QStringLiteral("UIQTClass"));
        UIQTClass->resize(485, 457);
        centralWidget = new QWidget(UIQTClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(70, 40, 371, 361));
        objetPage = new QWidget();
        objetPage->setObjectName(QStringLiteral("objetPage"));
        objet = new QFrame(objetPage);
        objet->setObjectName(QStringLiteral("objet"));
        objet->setGeometry(QRect(20, 50, 333, 226));
        objet->setFrameShape(QFrame::Box);
        objet->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(objet);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        positionYSpinBox = new QSpinBox(objet);
        positionYSpinBox->setObjectName(QStringLiteral("positionYSpinBox"));
        positionYSpinBox->setMinimum(-999999999);
        positionYSpinBox->setMaximum(999999999);

        gridLayout->addWidget(positionYSpinBox, 2, 3, 1, 1);

        positionXSpinBox = new QSpinBox(objet);
        positionXSpinBox->setObjectName(QStringLiteral("positionXSpinBox"));
        positionXSpinBox->setMinimum(-999999999);
        positionXSpinBox->setMaximum(999999999);

        gridLayout->addWidget(positionXSpinBox, 2, 1, 1, 1);

        couleurGSpinBox = new QSpinBox(objet);
        couleurGSpinBox->setObjectName(QStringLiteral("couleurGSpinBox"));
        couleurGSpinBox->setMaximum(255);

        gridLayout->addWidget(couleurGSpinBox, 21, 3, 1, 1);

        couleurRLabel = new QLabel(objet);
        couleurRLabel->setObjectName(QStringLiteral("couleurRLabel"));

        gridLayout->addWidget(couleurRLabel, 21, 0, 1, 1);

        rotationXSpinBox = new QSpinBox(objet);
        rotationXSpinBox->setObjectName(QStringLiteral("rotationXSpinBox"));
        rotationXSpinBox->setMinimum(-360);
        rotationXSpinBox->setMaximum(360);

        gridLayout->addWidget(rotationXSpinBox, 8, 1, 1, 1);

        couleurGLabel = new QLabel(objet);
        couleurGLabel->setObjectName(QStringLiteral("couleurGLabel"));

        gridLayout->addWidget(couleurGLabel, 21, 2, 1, 1);

        positionZLabel = new QLabel(objet);
        positionZLabel->setObjectName(QStringLiteral("positionZLabel"));

        gridLayout->addWidget(positionZLabel, 2, 4, 1, 1);

        couleurBLabel = new QLabel(objet);
        couleurBLabel->setObjectName(QStringLiteral("couleurBLabel"));

        gridLayout->addWidget(couleurBLabel, 21, 4, 1, 1);

        positionXLabel = new QLabel(objet);
        positionXLabel->setObjectName(QStringLiteral("positionXLabel"));

        gridLayout->addWidget(positionXLabel, 2, 0, 1, 1);

        couleurBSpinBox = new QSpinBox(objet);
        couleurBSpinBox->setObjectName(QStringLiteral("couleurBSpinBox"));
        couleurBSpinBox->setMaximum(255);

        gridLayout->addWidget(couleurBSpinBox, 21, 5, 1, 1);

        rotationLabel = new QLabel(objet);
        rotationLabel->setObjectName(QStringLiteral("rotationLabel"));
        rotationLabel->setAlignment(Qt::AlignCenter);
        rotationLabel->setTextInteractionFlags(Qt::NoTextInteraction);

        gridLayout->addWidget(rotationLabel, 7, 1, 1, 5);

        couleurLabel = new QLabel(objet);
        couleurLabel->setObjectName(QStringLiteral("couleurLabel"));
        couleurLabel->setAlignment(Qt::AlignCenter);
        couleurLabel->setTextInteractionFlags(Qt::NoTextInteraction);

        gridLayout->addWidget(couleurLabel, 11, 3, 1, 1);

        rotationYSpinBox = new QSpinBox(objet);
        rotationYSpinBox->setObjectName(QStringLiteral("rotationYSpinBox"));
        rotationYSpinBox->setMinimum(-360);
        rotationYSpinBox->setMaximum(360);

        gridLayout->addWidget(rotationYSpinBox, 8, 3, 1, 1);

        positionLabel = new QLabel(objet);
        positionLabel->setObjectName(QStringLiteral("positionLabel"));
        positionLabel->setAlignment(Qt::AlignCenter);
        positionLabel->setTextInteractionFlags(Qt::NoTextInteraction);

        gridLayout->addWidget(positionLabel, 1, 1, 1, 5);

        scaleLabel = new QLabel(objet);
        scaleLabel->setObjectName(QStringLiteral("scaleLabel"));
        scaleLabel->setAlignment(Qt::AlignCenter);
        scaleLabel->setTextInteractionFlags(Qt::NoTextInteraction);

        gridLayout->addWidget(scaleLabel, 22, 3, 1, 1);

        rotationZLabel = new QLabel(objet);
        rotationZLabel->setObjectName(QStringLiteral("rotationZLabel"));

        gridLayout->addWidget(rotationZLabel, 8, 4, 1, 1);

        scaleSpinBox = new QSpinBox(objet);
        scaleSpinBox->setObjectName(QStringLiteral("scaleSpinBox"));
        scaleSpinBox->setMinimum(-999999999);
        scaleSpinBox->setMaximum(999999999);

        gridLayout->addWidget(scaleSpinBox, 23, 3, 1, 1);

        positionYLabel = new QLabel(objet);
        positionYLabel->setObjectName(QStringLiteral("positionYLabel"));

        gridLayout->addWidget(positionYLabel, 2, 2, 1, 1);

        couleurRSpinBox = new QSpinBox(objet);
        couleurRSpinBox->setObjectName(QStringLiteral("couleurRSpinBox"));
        couleurRSpinBox->setMaximum(255);

        gridLayout->addWidget(couleurRSpinBox, 21, 1, 1, 1);

        positionZSpinBox = new QSpinBox(objet);
        positionZSpinBox->setObjectName(QStringLiteral("positionZSpinBox"));
        positionZSpinBox->setMinimum(-999999999);
        positionZSpinBox->setMaximum(999999999);

        gridLayout->addWidget(positionZSpinBox, 2, 5, 1, 1);

        rotationXLabel = new QLabel(objet);
        rotationXLabel->setObjectName(QStringLiteral("rotationXLabel"));

        gridLayout->addWidget(rotationXLabel, 8, 0, 1, 1);

        rotationYLabel = new QLabel(objet);
        rotationYLabel->setObjectName(QStringLiteral("rotationYLabel"));

        gridLayout->addWidget(rotationYLabel, 8, 2, 1, 1);

        rotationZSpinBox = new QSpinBox(objet);
        rotationZSpinBox->setObjectName(QStringLiteral("rotationZSpinBox"));
        rotationZSpinBox->setMinimum(-360);
        rotationZSpinBox->setMaximum(360);

        gridLayout->addWidget(rotationZSpinBox, 8, 5, 1, 1);

        objetLabel = new QLabel(objet);
        objetLabel->setObjectName(QStringLiteral("objetLabel"));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        objetLabel->setFont(font);
        objetLabel->setAlignment(Qt::AlignCenter);
        objetLabel->setTextInteractionFlags(Qt::NoTextInteraction);

        gridLayout->addWidget(objetLabel, 0, 1, 1, 5);

        stackedWidget->addWidget(objetPage);
        cameraPage = new QWidget();
        cameraPage->setObjectName(QStringLiteral("cameraPage"));
        camera = new QFrame(cameraPage);
        camera->setObjectName(QStringLiteral("camera"));
        camera->setGeometry(QRect(120, 40, 121, 271));
        camera->setFrameShape(QFrame::Box);
        camera->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(camera);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_4 = new QLabel(camera);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignCenter);
        label_4->setTextInteractionFlags(Qt::NoTextInteraction);

        gridLayout_2->addWidget(label_4, 0, 0, 1, 1);

        PosXLabel_2 = new QLabel(camera);
        PosXLabel_2->setObjectName(QStringLiteral("PosXLabel_2"));
        PosXLabel_2->setLayoutDirection(Qt::LeftToRight);
        PosXLabel_2->setAutoFillBackground(false);
        PosXLabel_2->setAlignment(Qt::AlignCenter);
        PosXLabel_2->setTextInteractionFlags(Qt::NoTextInteraction);

        gridLayout_2->addWidget(PosXLabel_2, 1, 0, 1, 1);

        spinBox_7 = new QSpinBox(camera);
        spinBox_7->setObjectName(QStringLiteral("spinBox_7"));

        gridLayout_2->addWidget(spinBox_7, 2, 0, 1, 1);

        label_3 = new QLabel(camera);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignCenter);
        label_3->setTextInteractionFlags(Qt::NoTextInteraction);

        gridLayout_2->addWidget(label_3, 3, 0, 1, 1);

        spinBox_8 = new QSpinBox(camera);
        spinBox_8->setObjectName(QStringLiteral("spinBox_8"));

        gridLayout_2->addWidget(spinBox_8, 4, 0, 1, 1);

        PosXLabel_3 = new QLabel(camera);
        PosXLabel_3->setObjectName(QStringLiteral("PosXLabel_3"));
        PosXLabel_3->setAlignment(Qt::AlignCenter);
        PosXLabel_3->setTextInteractionFlags(Qt::NoTextInteraction);

        gridLayout_2->addWidget(PosXLabel_3, 5, 0, 1, 1);

        spinBox_9 = new QSpinBox(camera);
        spinBox_9->setObjectName(QStringLiteral("spinBox_9"));

        gridLayout_2->addWidget(spinBox_9, 6, 0, 1, 1);

        PosXLabel_4 = new QLabel(camera);
        PosXLabel_4->setObjectName(QStringLiteral("PosXLabel_4"));
        PosXLabel_4->setAlignment(Qt::AlignCenter);
        PosXLabel_4->setTextInteractionFlags(Qt::NoTextInteraction);

        gridLayout_2->addWidget(PosXLabel_4, 7, 0, 1, 1);

        spinBox_10 = new QSpinBox(camera);
        spinBox_10->setObjectName(QStringLiteral("spinBox_10"));

        gridLayout_2->addWidget(spinBox_10, 8, 0, 1, 1);

        PosXLabel_5 = new QLabel(camera);
        PosXLabel_5->setObjectName(QStringLiteral("PosXLabel_5"));
        PosXLabel_5->setAlignment(Qt::AlignCenter);
        PosXLabel_5->setTextInteractionFlags(Qt::NoTextInteraction);

        gridLayout_2->addWidget(PosXLabel_5, 9, 0, 1, 1);

        spinBox_11 = new QSpinBox(camera);
        spinBox_11->setObjectName(QStringLiteral("spinBox_11"));

        gridLayout_2->addWidget(spinBox_11, 10, 0, 1, 1);

        PosXLabel_2->raise();
        label_3->raise();
        label_4->raise();
        PosXLabel_3->raise();
        PosXLabel_4->raise();
        PosXLabel_5->raise();
        spinBox_7->raise();
        spinBox_8->raise();
        spinBox_9->raise();
        spinBox_10->raise();
        spinBox_11->raise();
        stackedWidget->addWidget(cameraPage);
        UIQTClass->setCentralWidget(centralWidget);

        retranslateUi(UIQTClass);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(UIQTClass);
    } // setupUi

    void retranslateUi(QMainWindow *UIQTClass)
    {
        UIQTClass->setWindowTitle(QApplication::translate("UIQTClass", "UIQT", Q_NULLPTR));
        couleurRLabel->setText(QApplication::translate("UIQTClass", "R:", Q_NULLPTR));
        couleurGLabel->setText(QApplication::translate("UIQTClass", "G:", Q_NULLPTR));
        positionZLabel->setText(QApplication::translate("UIQTClass", "Z:", Q_NULLPTR));
        couleurBLabel->setText(QApplication::translate("UIQTClass", "B:", Q_NULLPTR));
        positionXLabel->setText(QApplication::translate("UIQTClass", "X:", Q_NULLPTR));
        rotationLabel->setText(QApplication::translate("UIQTClass", "Rotation", Q_NULLPTR));
        couleurLabel->setText(QApplication::translate("UIQTClass", "Couleur", Q_NULLPTR));
        positionLabel->setText(QApplication::translate("UIQTClass", "Position", Q_NULLPTR));
        scaleLabel->setText(QApplication::translate("UIQTClass", "Scale", Q_NULLPTR));
        rotationZLabel->setText(QApplication::translate("UIQTClass", "Z:", Q_NULLPTR));
        positionYLabel->setText(QApplication::translate("UIQTClass", "Y:", Q_NULLPTR));
        rotationXLabel->setText(QApplication::translate("UIQTClass", "X:", Q_NULLPTR));
        rotationYLabel->setText(QApplication::translate("UIQTClass", "Y:", Q_NULLPTR));
        objetLabel->setText(QApplication::translate("UIQTClass", "Objet", Q_NULLPTR));
        label_4->setText(QApplication::translate("UIQTClass", "Camera", Q_NULLPTR));
        PosXLabel_2->setText(QApplication::translate("UIQTClass", "Pitch", Q_NULLPTR));
        label_3->setText(QApplication::translate("UIQTClass", "Yall", Q_NULLPTR));
        PosXLabel_3->setText(QApplication::translate("UIQTClass", "Zoom", Q_NULLPTR));
        PosXLabel_4->setText(QApplication::translate("UIQTClass", "Near", Q_NULLPTR));
        PosXLabel_5->setText(QApplication::translate("UIQTClass", "Far", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class UIQTClass: public Ui_UIQTClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UIQT_H
