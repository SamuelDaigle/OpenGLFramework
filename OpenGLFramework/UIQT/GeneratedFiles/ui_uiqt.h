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
    QLabel *cameraLabel;
    QLabel *pitchLabel;
    QSpinBox *pitchSpinBox;
    QLabel *yawLabel;
    QSpinBox *yallSpinBox;
    QLabel *zoomLabel;
    QSpinBox *zoomSpinBox;
    QLabel *nearLabel;
    QSpinBox *nearSpinBox;
    QLabel *farLabel;
    QSpinBox *farSpinBox;
    QSpinBox *pageSpinBox;
    QLabel *setPageLabel;

    void setupUi(QMainWindow *UIQTClass)
    {
        if (UIQTClass->objectName().isEmpty())
            UIQTClass->setObjectName(QStringLiteral("UIQTClass"));
        UIQTClass->resize(497, 477);
        centralWidget = new QWidget(UIQTClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(70, 40, 371, 361));
        stackedWidget->setFrameShadow(QFrame::Plain);
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
        positionYSpinBox->setAlignment(Qt::AlignCenter);
        positionYSpinBox->setMinimum(-999999999);
        positionYSpinBox->setMaximum(999999999);

        gridLayout->addWidget(positionYSpinBox, 2, 3, 1, 1);

        positionXSpinBox = new QSpinBox(objet);
        positionXSpinBox->setObjectName(QStringLiteral("positionXSpinBox"));
        positionXSpinBox->setAlignment(Qt::AlignCenter);
        positionXSpinBox->setMinimum(-999999999);
        positionXSpinBox->setMaximum(999999999);

        gridLayout->addWidget(positionXSpinBox, 2, 1, 1, 1);

        couleurGSpinBox = new QSpinBox(objet);
        couleurGSpinBox->setObjectName(QStringLiteral("couleurGSpinBox"));
        couleurGSpinBox->setAlignment(Qt::AlignCenter);
        couleurGSpinBox->setMaximum(255);

        gridLayout->addWidget(couleurGSpinBox, 21, 3, 1, 1);

        couleurRLabel = new QLabel(objet);
        couleurRLabel->setObjectName(QStringLiteral("couleurRLabel"));

        gridLayout->addWidget(couleurRLabel, 21, 0, 1, 1);

        rotationXSpinBox = new QSpinBox(objet);
        rotationXSpinBox->setObjectName(QStringLiteral("rotationXSpinBox"));
        rotationXSpinBox->setAlignment(Qt::AlignCenter);
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
        couleurBSpinBox->setAlignment(Qt::AlignCenter);
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
        rotationYSpinBox->setAlignment(Qt::AlignCenter);
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
        scaleSpinBox->setAlignment(Qt::AlignCenter);
        scaleSpinBox->setMinimum(-999999999);
        scaleSpinBox->setMaximum(999999999);

        gridLayout->addWidget(scaleSpinBox, 23, 3, 1, 1);

        positionYLabel = new QLabel(objet);
        positionYLabel->setObjectName(QStringLiteral("positionYLabel"));

        gridLayout->addWidget(positionYLabel, 2, 2, 1, 1);

        couleurRSpinBox = new QSpinBox(objet);
        couleurRSpinBox->setObjectName(QStringLiteral("couleurRSpinBox"));
        couleurRSpinBox->setAlignment(Qt::AlignCenter);
        couleurRSpinBox->setMaximum(255);

        gridLayout->addWidget(couleurRSpinBox, 21, 1, 1, 1);

        positionZSpinBox = new QSpinBox(objet);
        positionZSpinBox->setObjectName(QStringLiteral("positionZSpinBox"));
        positionZSpinBox->setAlignment(Qt::AlignCenter);
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
        rotationZSpinBox->setAlignment(Qt::AlignCenter);
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
        cameraLabel = new QLabel(camera);
        cameraLabel->setObjectName(QStringLiteral("cameraLabel"));
        cameraLabel->setFont(font);
        cameraLabel->setAlignment(Qt::AlignCenter);
        cameraLabel->setTextInteractionFlags(Qt::NoTextInteraction);

        gridLayout_2->addWidget(cameraLabel, 0, 0, 1, 1);

        pitchLabel = new QLabel(camera);
        pitchLabel->setObjectName(QStringLiteral("pitchLabel"));
        pitchLabel->setLayoutDirection(Qt::LeftToRight);
        pitchLabel->setAutoFillBackground(false);
        pitchLabel->setAlignment(Qt::AlignCenter);
        pitchLabel->setTextInteractionFlags(Qt::NoTextInteraction);

        gridLayout_2->addWidget(pitchLabel, 1, 0, 1, 1);

        pitchSpinBox = new QSpinBox(camera);
        pitchSpinBox->setObjectName(QStringLiteral("pitchSpinBox"));
        pitchSpinBox->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(pitchSpinBox, 2, 0, 1, 1);

        yawLabel = new QLabel(camera);
        yawLabel->setObjectName(QStringLiteral("yawLabel"));
        yawLabel->setCursor(QCursor(Qt::ArrowCursor));
        yawLabel->setAlignment(Qt::AlignCenter);
        yawLabel->setTextInteractionFlags(Qt::NoTextInteraction);

        gridLayout_2->addWidget(yawLabel, 3, 0, 1, 1);

        yallSpinBox = new QSpinBox(camera);
        yallSpinBox->setObjectName(QStringLiteral("yallSpinBox"));
        yallSpinBox->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(yallSpinBox, 4, 0, 1, 1);

        zoomLabel = new QLabel(camera);
        zoomLabel->setObjectName(QStringLiteral("zoomLabel"));
        zoomLabel->setAlignment(Qt::AlignCenter);
        zoomLabel->setTextInteractionFlags(Qt::NoTextInteraction);

        gridLayout_2->addWidget(zoomLabel, 5, 0, 1, 1);

        zoomSpinBox = new QSpinBox(camera);
        zoomSpinBox->setObjectName(QStringLiteral("zoomSpinBox"));
        zoomSpinBox->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(zoomSpinBox, 6, 0, 1, 1);

        nearLabel = new QLabel(camera);
        nearLabel->setObjectName(QStringLiteral("nearLabel"));
        nearLabel->setAlignment(Qt::AlignCenter);
        nearLabel->setTextInteractionFlags(Qt::NoTextInteraction);

        gridLayout_2->addWidget(nearLabel, 7, 0, 1, 1);

        nearSpinBox = new QSpinBox(camera);
        nearSpinBox->setObjectName(QStringLiteral("nearSpinBox"));
        nearSpinBox->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(nearSpinBox, 8, 0, 1, 1);

        farLabel = new QLabel(camera);
        farLabel->setObjectName(QStringLiteral("farLabel"));
        farLabel->setAlignment(Qt::AlignCenter);
        farLabel->setTextInteractionFlags(Qt::NoTextInteraction);

        gridLayout_2->addWidget(farLabel, 9, 0, 1, 1);

        farSpinBox = new QSpinBox(camera);
        farSpinBox->setObjectName(QStringLiteral("farSpinBox"));
        farSpinBox->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(farSpinBox, 10, 0, 1, 1);

        pitchLabel->raise();
        yawLabel->raise();
        cameraLabel->raise();
        zoomLabel->raise();
        nearLabel->raise();
        farLabel->raise();
        pitchSpinBox->raise();
        yallSpinBox->raise();
        zoomSpinBox->raise();
        nearSpinBox->raise();
        farSpinBox->raise();
        stackedWidget->addWidget(cameraPage);
        pageSpinBox = new QSpinBox(centralWidget);
        pageSpinBox->setObjectName(QStringLiteral("pageSpinBox"));
        pageSpinBox->setGeometry(QRect(370, 400, 42, 22));
        pageSpinBox->setMaximum(1);
        setPageLabel = new QLabel(centralWidget);
        setPageLabel->setObjectName(QStringLiteral("setPageLabel"));
        setPageLabel->setGeometry(QRect(330, 400, 31, 16));
        UIQTClass->setCentralWidget(centralWidget);
        QWidget::setTabOrder(positionYSpinBox, couleurGSpinBox);
        QWidget::setTabOrder(couleurGSpinBox, rotationXSpinBox);
        QWidget::setTabOrder(rotationXSpinBox, couleurBSpinBox);
        QWidget::setTabOrder(couleurBSpinBox, rotationYSpinBox);
        QWidget::setTabOrder(rotationYSpinBox, scaleSpinBox);
        QWidget::setTabOrder(scaleSpinBox, couleurRSpinBox);
        QWidget::setTabOrder(couleurRSpinBox, positionZSpinBox);
        QWidget::setTabOrder(positionZSpinBox, rotationZSpinBox);
        QWidget::setTabOrder(rotationZSpinBox, positionXSpinBox);
        QWidget::setTabOrder(positionXSpinBox, pitchSpinBox);
        QWidget::setTabOrder(pitchSpinBox, yallSpinBox);
        QWidget::setTabOrder(yallSpinBox, zoomSpinBox);
        QWidget::setTabOrder(zoomSpinBox, nearSpinBox);
        QWidget::setTabOrder(nearSpinBox, farSpinBox);

        retranslateUi(UIQTClass);
        QObject::connect(pageSpinBox, SIGNAL(valueChanged(int)), stackedWidget, SLOT(setCurrentIndex(int)));
        QObject::connect(positionXSpinBox, SIGNAL(valueChanged(int)), UIQTClass, SLOT(newXPosition()));
        QObject::connect(positionYSpinBox, SIGNAL(valueChanged(int)), UIQTClass, SLOT(newYPosition()));
        QObject::connect(positionZSpinBox, SIGNAL(valueChanged(int)), UIQTClass, SLOT(newZPosition()));
        QObject::connect(rotationXSpinBox, SIGNAL(valueChanged(int)), UIQTClass, SLOT(newXRotation()));
        QObject::connect(rotationYSpinBox, SIGNAL(valueChanged(int)), UIQTClass, SLOT(newYRotation()));
        QObject::connect(rotationZSpinBox, SIGNAL(valueChanged(int)), UIQTClass, SLOT(newZRotation()));
        QObject::connect(couleurRSpinBox, SIGNAL(valueChanged(int)), UIQTClass, SLOT(newRColor()));
        QObject::connect(couleurGSpinBox, SIGNAL(valueChanged(int)), UIQTClass, SLOT(newGColor()));
        QObject::connect(couleurBSpinBox, SIGNAL(valueChanged(int)), UIQTClass, SLOT(newBColor()));
        QObject::connect(scaleSpinBox, SIGNAL(valueChanged(int)), UIQTClass, SLOT(newScale()));
        QObject::connect(pitchSpinBox, SIGNAL(valueChanged(int)), UIQTClass, SLOT(newPitch()));
        QObject::connect(yallSpinBox, SIGNAL(valueChanged(int)), UIQTClass, SLOT(newYaw()));
        QObject::connect(zoomSpinBox, SIGNAL(valueChanged(int)), UIQTClass, SLOT(newZoom()));
        QObject::connect(nearSpinBox, SIGNAL(valueChanged(int)), UIQTClass, SLOT(newNear()));
        QObject::connect(farSpinBox, SIGNAL(valueChanged(int)), UIQTClass, SLOT(newFar()));

        stackedWidget->setCurrentIndex(1);


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
        cameraLabel->setText(QApplication::translate("UIQTClass", "Camera", Q_NULLPTR));
        pitchLabel->setText(QApplication::translate("UIQTClass", "Pitch", Q_NULLPTR));
        yawLabel->setText(QApplication::translate("UIQTClass", "Yaw", Q_NULLPTR));
        zoomLabel->setText(QApplication::translate("UIQTClass", "Zoom", Q_NULLPTR));
        nearLabel->setText(QApplication::translate("UIQTClass", "Near", Q_NULLPTR));
        farLabel->setText(QApplication::translate("UIQTClass", "Far", Q_NULLPTR));
        setPageLabel->setText(QApplication::translate("UIQTClass", "Page", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class UIQTClass: public Ui_UIQTClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UIQT_H
