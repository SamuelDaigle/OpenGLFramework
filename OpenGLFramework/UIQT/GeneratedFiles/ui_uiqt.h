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
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UIQTClass
{
public:
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QGridLayout *gridLayout_5;
    QListWidget *emptyObjectListWidget;
    QFrame *frame_2;
    QGridLayout *gridLayout_4;
    QDoubleSpinBox *doubleSpinBox_3;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *label_30;
    QDoubleSpinBox *doubleSpinBox_2;
    QLabel *label_14;
    QLabel *label_27;
    QLabel *label_25;
    QLabel *label_21;
    QLabel *label_15;
    QSpinBox *spinBox_11;
    QLabel *label_26;
    QLabel *label_22;
    QSpinBox *spinBox_15;
    QLabel *label_20;
    QLabel *label_23;
    QSpinBox *spinBox_18;
    QLabel *label_24;
    QSpinBox *spinBox_17;
    QSpinBox *spinBox_19;
    QSpinBox *spinBox_16;
    QLabel *label_29;
    QLabel *label_28;
    QWidget *page_2;
    QGridLayout *gridLayout_6;
    QFrame *frame;
    QGridLayout *gridLayout_3;
    QLabel *label;
    QLabel *label_8;
    QSpinBox *spinBox_2;
    QSpinBox *spinBox_8;
    QSpinBox *spinBox_9;
    QLabel *label_2;
    QLabel *label_4;
    QSpinBox *spinBox_5;
    QLabel *label_5;
    QLabel *label_3;
    QLabel *label_6;
    QLabel *label_11;
    QLabel *label_7;
    QSpinBox *spinBox_7;
    QSpinBox *spinBox_6;
    QLabel *label_10;
    QLabel *label_13;
    QLabel *label_12;
    QLabel *label_16;
    QLabel *label_9;
    QSpinBox *spinBox_12;
    QLabel *label_18;
    QSpinBox *spinBox_13;
    QLabel *label_19;
    QDoubleSpinBox *doubleSpinBox_4;
    QLabel *label_17;
    QDoubleSpinBox *doubleSpinBox_5;
    QSpinBox *spinBox_14;
    QDoubleSpinBox *doubleSpinBox_6;
    QListWidget *modelObjectListWidget;
    QWidget *objetPage;
    QFrame *objet;
    QGridLayout *gridLayout;
    QLabel *positionZLabel;
    QSpinBox *positionXSpinBox;
    QSpinBox *couleurGSpinBox;
    QSpinBox *rotationXSpinBox;
    QLabel *couleurRLabel;
    QLabel *couleurGLabel;
    QSpinBox *positionYSpinBox;
    QLabel *couleurBLabel;
    QLabel *rotationLabel;
    QLabel *positionXLabel;
    QSpinBox *couleurBSpinBox;
    QLabel *rotationZLabel;
    QLabel *positionLabel;
    QLabel *couleurLabel;
    QSpinBox *rotationYSpinBox;
    QSpinBox *couleurRSpinBox;
    QLabel *positionYLabel;
    QSpinBox *positionZSpinBox;
    QLabel *rotationYLabel;
    QSpinBox *rotationZSpinBox;
    QLabel *shapeObjetLabel;
    QLabel *rotationXLabel;
    QLabel *scaleLabel;
    QLabel *scaleZLabel;
    QLabel *scaleYLabel;
    QLabel *scaleXLabel;
    QDoubleSpinBox *scaleXSpinBox;
    QDoubleSpinBox *scaleYSpinBox;
    QDoubleSpinBox *scaleZSpinBox;
    QListWidget *listWidget;
    QWidget *cameraPage;
    QFrame *camera;
    QGridLayout *gridLayout_2;
    QLabel *cameraLabel;
    QLabel *pitchLabel;
    QSpinBox *pitchSpinBox;
    QLabel *yawLabel;
    QSpinBox *yawSpinBox;
    QLabel *zoomLabel;
    QSpinBox *zoomSpinBox;
    QLabel *nearLabel;
    QSpinBox *nearSpinBox;
    QLabel *farLabel;
    QSpinBox *farSpinBox;
    QListWidget *CameraListWidget;
    QPushButton *undoPushButton;
    QPushButton *redoPushButton;
    QLabel *pageLabel;
    QSpinBox *spinBox;

    void setupUi(QMainWindow *UIQTClass)
    {
        if (UIQTClass->objectName().isEmpty())
            UIQTClass->setObjectName(QStringLiteral("UIQTClass"));
        UIQTClass->resize(368, 503);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(UIQTClass->sizePolicy().hasHeightForWidth());
        UIQTClass->setSizePolicy(sizePolicy);
        UIQTClass->setMinimumSize(QSize(368, 503));
        UIQTClass->setMaximumSize(QSize(368, 503));
        UIQTClass->setWindowOpacity(1);
        centralWidget = new QWidget(UIQTClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(30, 10, 311, 421));
        stackedWidget->setFrameShadow(QFrame::Plain);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        gridLayout_5 = new QGridLayout(page);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        emptyObjectListWidget = new QListWidget(page);
        emptyObjectListWidget->setObjectName(QStringLiteral("emptyObjectListWidget"));

        gridLayout_5->addWidget(emptyObjectListWidget, 0, 0, 1, 2);

        frame_2 = new QFrame(page);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::Box);
        frame_2->setFrameShadow(QFrame::Plain);
        gridLayout_4 = new QGridLayout(frame_2);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        doubleSpinBox_3 = new QDoubleSpinBox(frame_2);
        doubleSpinBox_3->setObjectName(QStringLiteral("doubleSpinBox_3"));
        doubleSpinBox_3->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(doubleSpinBox_3, 6, 5, 1, 1);

        doubleSpinBox = new QDoubleSpinBox(frame_2);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(doubleSpinBox, 6, 1, 1, 1);

        label_30 = new QLabel(frame_2);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_30, 5, 0, 1, 6);

        doubleSpinBox_2 = new QDoubleSpinBox(frame_2);
        doubleSpinBox_2->setObjectName(QStringLiteral("doubleSpinBox_2"));
        doubleSpinBox_2->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(doubleSpinBox_2, 6, 3, 1, 1);

        label_14 = new QLabel(frame_2);
        label_14->setObjectName(QStringLiteral("label_14"));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        label_14->setFont(font);
        label_14->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_14, 0, 0, 1, 6);

        label_27 = new QLabel(frame_2);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_27, 6, 4, 1, 1);

        label_25 = new QLabel(frame_2);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_25, 6, 0, 1, 1);

        label_21 = new QLabel(frame_2);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_21, 2, 4, 1, 1);

        label_15 = new QLabel(frame_2);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_15, 2, 0, 1, 1);

        spinBox_11 = new QSpinBox(frame_2);
        spinBox_11->setObjectName(QStringLiteral("spinBox_11"));
        spinBox_11->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(spinBox_11, 2, 1, 1, 1);

        label_26 = new QLabel(frame_2);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_26, 6, 2, 1, 1);

        label_22 = new QLabel(frame_2);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_22, 4, 0, 1, 1);

        spinBox_15 = new QSpinBox(frame_2);
        spinBox_15->setObjectName(QStringLiteral("spinBox_15"));
        spinBox_15->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(spinBox_15, 2, 3, 1, 1);

        label_20 = new QLabel(frame_2);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_20, 2, 2, 1, 1);

        label_23 = new QLabel(frame_2);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_23, 4, 2, 1, 1);

        spinBox_18 = new QSpinBox(frame_2);
        spinBox_18->setObjectName(QStringLiteral("spinBox_18"));
        spinBox_18->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(spinBox_18, 4, 3, 1, 1);

        label_24 = new QLabel(frame_2);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_24, 4, 4, 1, 1);

        spinBox_17 = new QSpinBox(frame_2);
        spinBox_17->setObjectName(QStringLiteral("spinBox_17"));
        spinBox_17->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(spinBox_17, 4, 1, 1, 1);

        spinBox_19 = new QSpinBox(frame_2);
        spinBox_19->setObjectName(QStringLiteral("spinBox_19"));
        spinBox_19->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(spinBox_19, 4, 5, 1, 1);

        spinBox_16 = new QSpinBox(frame_2);
        spinBox_16->setObjectName(QStringLiteral("spinBox_16"));
        spinBox_16->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(spinBox_16, 2, 5, 1, 1);

        label_29 = new QLabel(frame_2);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_29, 3, 0, 1, 6);

        label_28 = new QLabel(frame_2);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_28, 1, 0, 1, 6);


        gridLayout_5->addWidget(frame_2, 1, 0, 1, 2);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        gridLayout_6 = new QGridLayout(page_2);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        frame = new QFrame(page_2);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Plain);
        gridLayout_3 = new QGridLayout(frame);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label, 1, 0, 1, 6);

        label_8 = new QLabel(frame);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_8, 2, 0, 1, 6);

        spinBox_2 = new QSpinBox(frame);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));

        gridLayout_3->addWidget(spinBox_2, 5, 3, 1, 1);

        spinBox_8 = new QSpinBox(frame);
        spinBox_8->setObjectName(QStringLiteral("spinBox_8"));

        gridLayout_3->addWidget(spinBox_8, 3, 5, 1, 1);

        spinBox_9 = new QSpinBox(frame);
        spinBox_9->setObjectName(QStringLiteral("spinBox_9"));

        gridLayout_3->addWidget(spinBox_9, 5, 5, 1, 1);

        label_2 = new QLabel(frame);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_3->addWidget(label_2, 7, 2, 1, 1);

        label_4 = new QLabel(frame);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_3->addWidget(label_4, 7, 0, 1, 1);

        spinBox_5 = new QSpinBox(frame);
        spinBox_5->setObjectName(QStringLiteral("spinBox_5"));

        gridLayout_3->addWidget(spinBox_5, 3, 1, 1, 1);

        label_5 = new QLabel(frame);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_3->addWidget(label_5, 3, 0, 1, 1);

        label_3 = new QLabel(frame);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_3->addWidget(label_3, 5, 0, 1, 1);

        label_6 = new QLabel(frame);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_3->addWidget(label_6, 5, 2, 1, 1);

        label_11 = new QLabel(frame);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_3->addWidget(label_11, 3, 4, 1, 1);

        label_7 = new QLabel(frame);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_3->addWidget(label_7, 3, 2, 1, 1);

        spinBox_7 = new QSpinBox(frame);
        spinBox_7->setObjectName(QStringLiteral("spinBox_7"));

        gridLayout_3->addWidget(spinBox_7, 5, 1, 1, 1);

        spinBox_6 = new QSpinBox(frame);
        spinBox_6->setObjectName(QStringLiteral("spinBox_6"));

        gridLayout_3->addWidget(spinBox_6, 3, 3, 1, 1);

        label_10 = new QLabel(frame);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_10, 6, 0, 1, 6);

        label_13 = new QLabel(frame);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout_3->addWidget(label_13, 7, 4, 1, 1);

        label_12 = new QLabel(frame);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout_3->addWidget(label_12, 5, 4, 1, 1);

        label_16 = new QLabel(frame);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_16, 9, 0, 1, 1);

        label_9 = new QLabel(frame);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_9, 4, 0, 1, 6);

        spinBox_12 = new QSpinBox(frame);
        spinBox_12->setObjectName(QStringLiteral("spinBox_12"));

        gridLayout_3->addWidget(spinBox_12, 9, 1, 1, 1);

        label_18 = new QLabel(frame);
        label_18->setObjectName(QStringLiteral("label_18"));

        gridLayout_3->addWidget(label_18, 9, 2, 1, 1);

        spinBox_13 = new QSpinBox(frame);
        spinBox_13->setObjectName(QStringLiteral("spinBox_13"));

        gridLayout_3->addWidget(spinBox_13, 9, 3, 1, 1);

        label_19 = new QLabel(frame);
        label_19->setObjectName(QStringLiteral("label_19"));

        gridLayout_3->addWidget(label_19, 9, 4, 1, 1);

        doubleSpinBox_4 = new QDoubleSpinBox(frame);
        doubleSpinBox_4->setObjectName(QStringLiteral("doubleSpinBox_4"));

        gridLayout_3->addWidget(doubleSpinBox_4, 7, 1, 1, 1);

        label_17 = new QLabel(frame);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_17, 8, 0, 1, 6);

        doubleSpinBox_5 = new QDoubleSpinBox(frame);
        doubleSpinBox_5->setObjectName(QStringLiteral("doubleSpinBox_5"));

        gridLayout_3->addWidget(doubleSpinBox_5, 7, 3, 1, 1);

        spinBox_14 = new QSpinBox(frame);
        spinBox_14->setObjectName(QStringLiteral("spinBox_14"));

        gridLayout_3->addWidget(spinBox_14, 9, 5, 1, 1);

        doubleSpinBox_6 = new QDoubleSpinBox(frame);
        doubleSpinBox_6->setObjectName(QStringLiteral("doubleSpinBox_6"));

        gridLayout_3->addWidget(doubleSpinBox_6, 7, 5, 1, 1);

        modelObjectListWidget = new QListWidget(frame);
        modelObjectListWidget->setObjectName(QStringLiteral("modelObjectListWidget"));

        gridLayout_3->addWidget(modelObjectListWidget, 0, 0, 1, 2);


        gridLayout_6->addWidget(frame, 0, 1, 1, 1);

        stackedWidget->addWidget(page_2);
        objetPage = new QWidget();
        objetPage->setObjectName(QStringLiteral("objetPage"));
        objet = new QFrame(objetPage);
        objet->setObjectName(QStringLiteral("objet"));
        objet->setGeometry(QRect(430, 50, 333, 226));
        objet->setFrameShape(QFrame::Box);
        objet->setFrameShadow(QFrame::Plain);
        gridLayout = new QGridLayout(objet);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        positionZLabel = new QLabel(objet);
        positionZLabel->setObjectName(QStringLiteral("positionZLabel"));

        gridLayout->addWidget(positionZLabel, 2, 4, 1, 1);

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

        rotationXSpinBox = new QSpinBox(objet);
        rotationXSpinBox->setObjectName(QStringLiteral("rotationXSpinBox"));
        rotationXSpinBox->setAlignment(Qt::AlignCenter);
        rotationXSpinBox->setMinimum(-360);
        rotationXSpinBox->setMaximum(360);

        gridLayout->addWidget(rotationXSpinBox, 8, 1, 1, 1);

        couleurRLabel = new QLabel(objet);
        couleurRLabel->setObjectName(QStringLiteral("couleurRLabel"));

        gridLayout->addWidget(couleurRLabel, 21, 0, 1, 1);

        couleurGLabel = new QLabel(objet);
        couleurGLabel->setObjectName(QStringLiteral("couleurGLabel"));

        gridLayout->addWidget(couleurGLabel, 21, 2, 1, 1);

        positionYSpinBox = new QSpinBox(objet);
        positionYSpinBox->setObjectName(QStringLiteral("positionYSpinBox"));
        positionYSpinBox->setAlignment(Qt::AlignCenter);
        positionYSpinBox->setMinimum(-999999999);
        positionYSpinBox->setMaximum(999999999);

        gridLayout->addWidget(positionYSpinBox, 2, 3, 1, 1);

        couleurBLabel = new QLabel(objet);
        couleurBLabel->setObjectName(QStringLiteral("couleurBLabel"));

        gridLayout->addWidget(couleurBLabel, 21, 4, 1, 1);

        rotationLabel = new QLabel(objet);
        rotationLabel->setObjectName(QStringLiteral("rotationLabel"));
        rotationLabel->setAlignment(Qt::AlignCenter);
        rotationLabel->setTextInteractionFlags(Qt::NoTextInteraction);

        gridLayout->addWidget(rotationLabel, 7, 1, 1, 5);

        positionXLabel = new QLabel(objet);
        positionXLabel->setObjectName(QStringLiteral("positionXLabel"));

        gridLayout->addWidget(positionXLabel, 2, 0, 1, 1);

        couleurBSpinBox = new QSpinBox(objet);
        couleurBSpinBox->setObjectName(QStringLiteral("couleurBSpinBox"));
        couleurBSpinBox->setAlignment(Qt::AlignCenter);
        couleurBSpinBox->setMaximum(255);

        gridLayout->addWidget(couleurBSpinBox, 21, 5, 1, 1);

        rotationZLabel = new QLabel(objet);
        rotationZLabel->setObjectName(QStringLiteral("rotationZLabel"));

        gridLayout->addWidget(rotationZLabel, 8, 4, 1, 1);

        positionLabel = new QLabel(objet);
        positionLabel->setObjectName(QStringLiteral("positionLabel"));
        positionLabel->setAlignment(Qt::AlignCenter);
        positionLabel->setTextInteractionFlags(Qt::NoTextInteraction);

        gridLayout->addWidget(positionLabel, 1, 1, 1, 5);

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

        couleurRSpinBox = new QSpinBox(objet);
        couleurRSpinBox->setObjectName(QStringLiteral("couleurRSpinBox"));
        couleurRSpinBox->setAlignment(Qt::AlignCenter);
        couleurRSpinBox->setMaximum(255);

        gridLayout->addWidget(couleurRSpinBox, 21, 1, 1, 1);

        positionYLabel = new QLabel(objet);
        positionYLabel->setObjectName(QStringLiteral("positionYLabel"));

        gridLayout->addWidget(positionYLabel, 2, 2, 1, 1);

        positionZSpinBox = new QSpinBox(objet);
        positionZSpinBox->setObjectName(QStringLiteral("positionZSpinBox"));
        positionZSpinBox->setAlignment(Qt::AlignCenter);
        positionZSpinBox->setMinimum(-999999999);
        positionZSpinBox->setMaximum(999999999);

        gridLayout->addWidget(positionZSpinBox, 2, 5, 1, 1);

        rotationYLabel = new QLabel(objet);
        rotationYLabel->setObjectName(QStringLiteral("rotationYLabel"));

        gridLayout->addWidget(rotationYLabel, 8, 2, 1, 1);

        rotationZSpinBox = new QSpinBox(objet);
        rotationZSpinBox->setObjectName(QStringLiteral("rotationZSpinBox"));
        rotationZSpinBox->setAlignment(Qt::AlignCenter);
        rotationZSpinBox->setMinimum(-360);
        rotationZSpinBox->setMaximum(360);

        gridLayout->addWidget(rotationZSpinBox, 8, 5, 1, 1);

        shapeObjetLabel = new QLabel(objet);
        shapeObjetLabel->setObjectName(QStringLiteral("shapeObjetLabel"));
        shapeObjetLabel->setFont(font);
        shapeObjetLabel->setAlignment(Qt::AlignCenter);
        shapeObjetLabel->setTextInteractionFlags(Qt::NoTextInteraction);

        gridLayout->addWidget(shapeObjetLabel, 0, 1, 1, 5);

        rotationXLabel = new QLabel(objet);
        rotationXLabel->setObjectName(QStringLiteral("rotationXLabel"));

        gridLayout->addWidget(rotationXLabel, 8, 0, 1, 1);

        scaleLabel = new QLabel(objet);
        scaleLabel->setObjectName(QStringLiteral("scaleLabel"));
        scaleLabel->setAlignment(Qt::AlignCenter);
        scaleLabel->setTextInteractionFlags(Qt::NoTextInteraction);

        gridLayout->addWidget(scaleLabel, 9, 3, 1, 1);

        scaleZLabel = new QLabel(objet);
        scaleZLabel->setObjectName(QStringLiteral("scaleZLabel"));

        gridLayout->addWidget(scaleZLabel, 10, 4, 1, 1);

        scaleYLabel = new QLabel(objet);
        scaleYLabel->setObjectName(QStringLiteral("scaleYLabel"));

        gridLayout->addWidget(scaleYLabel, 10, 2, 1, 1);

        scaleXLabel = new QLabel(objet);
        scaleXLabel->setObjectName(QStringLiteral("scaleXLabel"));

        gridLayout->addWidget(scaleXLabel, 10, 0, 1, 1);

        scaleXSpinBox = new QDoubleSpinBox(objet);
        scaleXSpinBox->setObjectName(QStringLiteral("scaleXSpinBox"));
        scaleXSpinBox->setAlignment(Qt::AlignCenter);
        scaleXSpinBox->setDecimals(1);
        scaleXSpinBox->setMinimum(0.1);
        scaleXSpinBox->setValue(1);

        gridLayout->addWidget(scaleXSpinBox, 10, 1, 1, 1);

        scaleYSpinBox = new QDoubleSpinBox(objet);
        scaleYSpinBox->setObjectName(QStringLiteral("scaleYSpinBox"));
        scaleYSpinBox->setAlignment(Qt::AlignCenter);
        scaleYSpinBox->setDecimals(1);
        scaleYSpinBox->setMinimum(0.1);
        scaleYSpinBox->setValue(1);

        gridLayout->addWidget(scaleYSpinBox, 10, 3, 1, 1);

        scaleZSpinBox = new QDoubleSpinBox(objet);
        scaleZSpinBox->setObjectName(QStringLiteral("scaleZSpinBox"));
        scaleZSpinBox->setAlignment(Qt::AlignCenter);
        scaleZSpinBox->setDecimals(1);
        scaleZSpinBox->setMinimum(0.1);
        scaleZSpinBox->setValue(1);

        gridLayout->addWidget(scaleZSpinBox, 10, 5, 1, 1);

        listWidget = new QListWidget(objetPage);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(60, 30, 321, 321));
        listWidget->viewport()->setProperty("cursor", QVariant(QCursor(Qt::PointingHandCursor)));
        stackedWidget->addWidget(objetPage);
        cameraPage = new QWidget();
        cameraPage->setObjectName(QStringLiteral("cameraPage"));
        camera = new QFrame(cameraPage);
        camera->setObjectName(QStringLiteral("camera"));
        camera->setGeometry(QRect(550, 30, 131, 271));
        camera->setFrameShape(QFrame::Box);
        camera->setFrameShadow(QFrame::Plain);
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

        yawSpinBox = new QSpinBox(camera);
        yawSpinBox->setObjectName(QStringLiteral("yawSpinBox"));
        yawSpinBox->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(yawSpinBox, 4, 0, 1, 1);

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
        yawSpinBox->raise();
        zoomSpinBox->raise();
        nearSpinBox->raise();
        farSpinBox->raise();
        CameraListWidget = new QListWidget(cameraPage);
        CameraListWidget->setObjectName(QStringLiteral("CameraListWidget"));
        CameraListWidget->setGeometry(QRect(60, 30, 321, 321));
        stackedWidget->addWidget(cameraPage);
        undoPushButton = new QPushButton(centralWidget);
        undoPushButton->setObjectName(QStringLiteral("undoPushButton"));
        undoPushButton->setGeometry(QRect(40, 450, 61, 31));
        redoPushButton = new QPushButton(centralWidget);
        redoPushButton->setObjectName(QStringLiteral("redoPushButton"));
        redoPushButton->setGeometry(QRect(110, 450, 61, 31));
        pageLabel = new QLabel(centralWidget);
        pageLabel->setObjectName(QStringLiteral("pageLabel"));
        pageLabel->setGeometry(QRect(200, 460, 31, 16));
        pageLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBox = new QSpinBox(centralWidget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(260, 450, 41, 21));
        spinBox->setMaximum(3);
        UIQTClass->setCentralWidget(centralWidget);
        QWidget::setTabOrder(positionYSpinBox, couleurGSpinBox);
        QWidget::setTabOrder(couleurGSpinBox, rotationXSpinBox);
        QWidget::setTabOrder(rotationXSpinBox, couleurBSpinBox);
        QWidget::setTabOrder(couleurBSpinBox, rotationYSpinBox);
        QWidget::setTabOrder(rotationYSpinBox, couleurRSpinBox);
        QWidget::setTabOrder(couleurRSpinBox, positionZSpinBox);
        QWidget::setTabOrder(positionZSpinBox, rotationZSpinBox);
        QWidget::setTabOrder(rotationZSpinBox, positionXSpinBox);
        QWidget::setTabOrder(positionXSpinBox, pitchSpinBox);
        QWidget::setTabOrder(pitchSpinBox, yawSpinBox);
        QWidget::setTabOrder(yawSpinBox, zoomSpinBox);
        QWidget::setTabOrder(zoomSpinBox, nearSpinBox);
        QWidget::setTabOrder(nearSpinBox, farSpinBox);

        retranslateUi(UIQTClass);
        QObject::connect(positionXSpinBox, SIGNAL(valueChanged(int)), UIQTClass, SLOT(newXPosition(int)));
        QObject::connect(positionYSpinBox, SIGNAL(valueChanged(int)), UIQTClass, SLOT(newYPosition(int)));
        QObject::connect(positionZSpinBox, SIGNAL(valueChanged(int)), UIQTClass, SLOT(newZPosition(int)));
        QObject::connect(rotationXSpinBox, SIGNAL(valueChanged(int)), UIQTClass, SLOT(newXRotation(int)));
        QObject::connect(rotationYSpinBox, SIGNAL(valueChanged(int)), UIQTClass, SLOT(newYRotation(int)));
        QObject::connect(rotationZSpinBox, SIGNAL(valueChanged(int)), UIQTClass, SLOT(newZRotation(int)));
        QObject::connect(couleurRSpinBox, SIGNAL(valueChanged(int)), UIQTClass, SLOT(newRColor(int)));
        QObject::connect(couleurGSpinBox, SIGNAL(valueChanged(int)), UIQTClass, SLOT(newGColor(int)));
        QObject::connect(couleurBSpinBox, SIGNAL(valueChanged(int)), UIQTClass, SLOT(newBColor(int)));
        QObject::connect(pitchSpinBox, SIGNAL(valueChanged(int)), UIQTClass, SLOT(newPitch(int)));
        QObject::connect(yawSpinBox, SIGNAL(valueChanged(int)), UIQTClass, SLOT(newYaw(int)));
        QObject::connect(zoomSpinBox, SIGNAL(valueChanged(int)), UIQTClass, SLOT(newZoom(int)));
        QObject::connect(nearSpinBox, SIGNAL(valueChanged(int)), UIQTClass, SLOT(newNear(int)));
        QObject::connect(farSpinBox, SIGNAL(valueChanged(int)), UIQTClass, SLOT(newFar(int)));
        QObject::connect(UIQTClass, SIGNAL(currentXPosition(int)), positionXSpinBox, SLOT(setValue(int)));
        QObject::connect(UIQTClass, SIGNAL(currentYPosition(int)), positionYSpinBox, SLOT(setValue(int)));
        QObject::connect(UIQTClass, SIGNAL(currentZPosition(int)), positionZSpinBox, SLOT(setValue(int)));
        QObject::connect(UIQTClass, SIGNAL(currentXRotation(int)), rotationXSpinBox, SLOT(setValue(int)));
        QObject::connect(UIQTClass, SIGNAL(currentYRotation(int)), rotationYSpinBox, SLOT(setValue(int)));
        QObject::connect(UIQTClass, SIGNAL(currentZRotation(int)), rotationZSpinBox, SLOT(setValue(int)));
        QObject::connect(UIQTClass, SIGNAL(currentRColor(int)), couleurRSpinBox, SLOT(setValue(int)));
        QObject::connect(UIQTClass, SIGNAL(currentGColor(int)), couleurGSpinBox, SLOT(setValue(int)));
        QObject::connect(UIQTClass, SIGNAL(currentBColor(int)), couleurBSpinBox, SLOT(setValue(int)));
        QObject::connect(UIQTClass, SIGNAL(currentPitch(int)), pitchSpinBox, SLOT(setValue(int)));
        QObject::connect(UIQTClass, SIGNAL(currentYaw(int)), yawSpinBox, SLOT(setValue(int)));
        QObject::connect(UIQTClass, SIGNAL(currentZoom(int)), zoomSpinBox, SLOT(setValue(int)));
        QObject::connect(UIQTClass, SIGNAL(currentNear(int)), nearSpinBox, SLOT(setValue(int)));
        QObject::connect(UIQTClass, SIGNAL(currentFar(int)), farSpinBox, SLOT(setValue(int)));
        QObject::connect(UIQTClass, SIGNAL(currentObjectName(QString)), shapeObjetLabel, SLOT(setText(QString)));
        QObject::connect(UIQTClass, SIGNAL(changeStackedWidgetIndex(int)), stackedWidget, SLOT(setCurrentIndex(int)));
        QObject::connect(listWidget, SIGNAL(clicked(QModelIndex)), UIQTClass, SLOT(selectedObject(QModelIndex)));
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), stackedWidget, SLOT(setCurrentIndex(int)));
        QObject::connect(undoPushButton, SIGNAL(clicked()), UIQTClass, SLOT(undo()));
        QObject::connect(redoPushButton, SIGNAL(clicked()), UIQTClass, SLOT(redo()));
        QObject::connect(scaleXSpinBox, SIGNAL(valueChanged(double)), UIQTClass, SLOT(newXScale(double)));
        QObject::connect(UIQTClass, SIGNAL(currentXScale(double)), scaleXSpinBox, SLOT(setValue(double)));
        QObject::connect(scaleYSpinBox, SIGNAL(valueChanged(double)), UIQTClass, SLOT(newYScale(double)));
        QObject::connect(UIQTClass, SIGNAL(currentYScale(double)), scaleYSpinBox, SLOT(setValue(double)));
        QObject::connect(scaleZSpinBox, SIGNAL(valueChanged(double)), UIQTClass, SLOT(newZScale(double)));
        QObject::connect(UIQTClass, SIGNAL(currentZScale(double)), scaleZSpinBox, SLOT(setValue(double)));
        QObject::connect(UIQTClass, SIGNAL(currentEmptyXPosition(int)), spinBox_11, SLOT(setValue(int)));
        QObject::connect(UIQTClass, SIGNAL(currentEmptyYPosition(int)), spinBox_15, SLOT(setValue(int)));
        QObject::connect(UIQTClass, SIGNAL(currentEmptyZPosition(int)), spinBox_16, SLOT(setValue(int)));
        QObject::connect(UIQTClass, SIGNAL(currentEmptyXRotation(int)), spinBox_17, SLOT(setValue(int)));
        QObject::connect(UIQTClass, SIGNAL(currentEmptyYRotation(int)), spinBox_18, SLOT(setValue(int)));
        QObject::connect(UIQTClass, SIGNAL(currentEmptyZRotation(int)), spinBox_19, SLOT(setValue(int)));
        QObject::connect(UIQTClass, SIGNAL(currentEmptyXScale(double)), doubleSpinBox, SLOT(setValue(double)));
        QObject::connect(UIQTClass, SIGNAL(currentEmptyYScale(double)), doubleSpinBox_2, SLOT(setValue(double)));
        QObject::connect(UIQTClass, SIGNAL(currentEmptyZScale(double)), doubleSpinBox_3, SLOT(setValue(double)));
        QObject::connect(emptyObjectListWidget, SIGNAL(clicked(QModelIndex)), UIQTClass, SLOT(selectedObject(QModelIndex)));
        QObject::connect(modelObjectListWidget, SIGNAL(clicked(QModelIndex)), UIQTClass, SLOT(selectedObject(QModelIndex)));
        QObject::connect(spinBox_15, SIGNAL(valueChanged(int)), UIQTClass, SLOT(newEmptyYPosition(int)));
        QObject::connect(spinBox_16, SIGNAL(valueChanged(int)), UIQTClass, SLOT(newEmptyZPosition(int)));
        QObject::connect(spinBox_17, SIGNAL(valueChanged(int)), UIQTClass, SLOT(newEmptyXRotation(int)));
        QObject::connect(spinBox_18, SIGNAL(valueChanged(int)), UIQTClass, SLOT(newEmptyYRotation(int)));
        QObject::connect(spinBox_19, SIGNAL(valueChanged(int)), UIQTClass, SLOT(newEmptyZRotation(int)));
        QObject::connect(doubleSpinBox, SIGNAL(valueChanged(double)), UIQTClass, SLOT(newEmptyXScale(double)));
        QObject::connect(doubleSpinBox_2, SIGNAL(valueChanged(double)), UIQTClass, SLOT(newEmptyYScale(double)));
        QObject::connect(doubleSpinBox_3, SIGNAL(valueChanged(double)), UIQTClass, SLOT(newEmptyZScale(double)));
        QObject::connect(UIQTClass, SIGNAL(currentModelXPosition(int)), spinBox_5, SLOT(setValue(int)));
        QObject::connect(UIQTClass, SIGNAL(currentModelYPosition(int)), spinBox_6, SLOT(setValue(int)));
        QObject::connect(UIQTClass, SIGNAL(currentModelZPosition(int)), spinBox_8, SLOT(setValue(int)));
        QObject::connect(UIQTClass, SIGNAL(currentModelXRotation(int)), spinBox_7, SLOT(setValue(int)));
        QObject::connect(UIQTClass, SIGNAL(currentModelYRotation(int)), spinBox_2, SLOT(setValue(int)));
        QObject::connect(UIQTClass, SIGNAL(currentModelZRotation(int)), spinBox_9, SLOT(setValue(int)));
        QObject::connect(UIQTClass, SIGNAL(currentModelXScale(double)), doubleSpinBox_4, SLOT(setValue(double)));
        QObject::connect(UIQTClass, SIGNAL(currentModelYScale(double)), doubleSpinBox_5, SLOT(setValue(double)));
        QObject::connect(UIQTClass, SIGNAL(currentModelZScale(double)), doubleSpinBox_6, SLOT(setValue(double)));
        QObject::connect(UIQTClass, SIGNAL(currentModelRColor(int)), spinBox_12, SLOT(setValue(int)));
        QObject::connect(UIQTClass, SIGNAL(currentModelGColor(int)), spinBox_13, SLOT(setValue(int)));
        QObject::connect(UIQTClass, SIGNAL(currentModelBColor(int)), spinBox_14, SLOT(setValue(int)));
        QObject::connect(spinBox_5, SIGNAL(valueChanged(int)), UIQTClass, SLOT(newModelXPosition(int)));
        QObject::connect(spinBox_6, SIGNAL(valueChanged(int)), UIQTClass, SLOT(newModelYPosition(int)));
        QObject::connect(spinBox_8, SIGNAL(valueChanged(int)), UIQTClass, SLOT(newModelZPosition(int)));
        QObject::connect(spinBox_7, SIGNAL(valueChanged(int)), UIQTClass, SLOT(newModelXRotation(int)));
        QObject::connect(spinBox_2, SIGNAL(valueChanged(int)), UIQTClass, SLOT(newModelYRotation(int)));
        QObject::connect(spinBox_9, SIGNAL(valueChanged(int)), UIQTClass, SLOT(newModelZRotation(int)));
        QObject::connect(doubleSpinBox_4, SIGNAL(valueChanged(double)), UIQTClass, SLOT(newModelXScale(double)));
        QObject::connect(doubleSpinBox_5, SIGNAL(valueChanged(double)), UIQTClass, SLOT(newModelYScale(double)));
        QObject::connect(doubleSpinBox_6, SIGNAL(valueChanged(double)), UIQTClass, SLOT(newModelZScale(double)));
        QObject::connect(spinBox_12, SIGNAL(valueChanged(int)), UIQTClass, SLOT(newModelRColor(int)));
        QObject::connect(spinBox_13, SIGNAL(valueChanged(int)), UIQTClass, SLOT(newModelGColor(int)));
        QObject::connect(spinBox_14, SIGNAL(valueChanged(int)), UIQTClass, SLOT(newModelBColor(int)));
        QObject::connect(spinBox_11, SIGNAL(valueChanged(int)), UIQTClass, SLOT(newXPosition(int)));
        QObject::connect(doubleSpinBox, SIGNAL(valueChanged(double)), UIQTClass, SLOT(newXScale(double)));
        QObject::connect(spinBox_17, SIGNAL(valueChanged(int)), UIQTClass, SLOT(newXRotation(int)));

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(UIQTClass);
    } // setupUi

    void retranslateUi(QMainWindow *UIQTClass)
    {
        UIQTClass->setWindowTitle(QApplication::translate("UIQTClass", "UIQT", Q_NULLPTR));
        label_30->setText(QApplication::translate("UIQTClass", "Scale", Q_NULLPTR));
        label_14->setText(QApplication::translate("UIQTClass", "Empty Object", Q_NULLPTR));
        label_27->setText(QApplication::translate("UIQTClass", "z", Q_NULLPTR));
        label_25->setText(QApplication::translate("UIQTClass", "x", Q_NULLPTR));
        label_21->setText(QApplication::translate("UIQTClass", "z", Q_NULLPTR));
        label_15->setText(QApplication::translate("UIQTClass", "x", Q_NULLPTR));
        label_26->setText(QApplication::translate("UIQTClass", "y", Q_NULLPTR));
        label_22->setText(QApplication::translate("UIQTClass", "x", Q_NULLPTR));
        label_20->setText(QApplication::translate("UIQTClass", "y", Q_NULLPTR));
        label_23->setText(QApplication::translate("UIQTClass", "y", Q_NULLPTR));
        label_24->setText(QApplication::translate("UIQTClass", "z", Q_NULLPTR));
        label_29->setText(QApplication::translate("UIQTClass", "Rotation", Q_NULLPTR));
        label_28->setText(QApplication::translate("UIQTClass", "Position", Q_NULLPTR));
        label->setText(QApplication::translate("UIQTClass", "Model Object", Q_NULLPTR));
        label_8->setText(QApplication::translate("UIQTClass", "Position", Q_NULLPTR));
        label_2->setText(QApplication::translate("UIQTClass", "TextLabel", Q_NULLPTR));
        label_4->setText(QApplication::translate("UIQTClass", "TextLabel", Q_NULLPTR));
        label_5->setText(QApplication::translate("UIQTClass", "TextLabel", Q_NULLPTR));
        label_3->setText(QApplication::translate("UIQTClass", "TextLabel", Q_NULLPTR));
        label_6->setText(QApplication::translate("UIQTClass", "TextLabel", Q_NULLPTR));
        label_11->setText(QApplication::translate("UIQTClass", "TextLabel", Q_NULLPTR));
        label_7->setText(QApplication::translate("UIQTClass", "TextLabel", Q_NULLPTR));
        label_10->setText(QApplication::translate("UIQTClass", "Scale", Q_NULLPTR));
        label_13->setText(QApplication::translate("UIQTClass", "TextLabel", Q_NULLPTR));
        label_12->setText(QApplication::translate("UIQTClass", "TextLabel", Q_NULLPTR));
        label_16->setText(QApplication::translate("UIQTClass", "TextLabel", Q_NULLPTR));
        label_9->setText(QApplication::translate("UIQTClass", "Rotation", Q_NULLPTR));
        label_18->setText(QApplication::translate("UIQTClass", "TextLabel", Q_NULLPTR));
        label_19->setText(QApplication::translate("UIQTClass", "TextLabel", Q_NULLPTR));
        label_17->setText(QApplication::translate("UIQTClass", "Couleur", Q_NULLPTR));
        positionZLabel->setText(QApplication::translate("UIQTClass", "Z:", Q_NULLPTR));
        couleurRLabel->setText(QApplication::translate("UIQTClass", "R:", Q_NULLPTR));
        couleurGLabel->setText(QApplication::translate("UIQTClass", "G:", Q_NULLPTR));
        couleurBLabel->setText(QApplication::translate("UIQTClass", "B:", Q_NULLPTR));
        rotationLabel->setText(QApplication::translate("UIQTClass", "Rotation", Q_NULLPTR));
        positionXLabel->setText(QApplication::translate("UIQTClass", "X:", Q_NULLPTR));
        rotationZLabel->setText(QApplication::translate("UIQTClass", "Z:", Q_NULLPTR));
        positionLabel->setText(QApplication::translate("UIQTClass", "Position", Q_NULLPTR));
        couleurLabel->setText(QApplication::translate("UIQTClass", "Couleur", Q_NULLPTR));
        positionYLabel->setText(QApplication::translate("UIQTClass", "Y:", Q_NULLPTR));
        rotationYLabel->setText(QApplication::translate("UIQTClass", "Y:", Q_NULLPTR));
        shapeObjetLabel->setText(QApplication::translate("UIQTClass", "Shape Objet", Q_NULLPTR));
        rotationXLabel->setText(QApplication::translate("UIQTClass", "X:", Q_NULLPTR));
        scaleLabel->setText(QApplication::translate("UIQTClass", "Scale", Q_NULLPTR));
        scaleZLabel->setText(QApplication::translate("UIQTClass", "Z:", Q_NULLPTR));
        scaleYLabel->setText(QApplication::translate("UIQTClass", "Y:", Q_NULLPTR));
        scaleXLabel->setText(QApplication::translate("UIQTClass", "X:", Q_NULLPTR));
        cameraLabel->setText(QApplication::translate("UIQTClass", "Camera", Q_NULLPTR));
        pitchLabel->setText(QApplication::translate("UIQTClass", "Pitch", Q_NULLPTR));
        yawLabel->setText(QApplication::translate("UIQTClass", "Yaw", Q_NULLPTR));
        zoomLabel->setText(QApplication::translate("UIQTClass", "Zoom", Q_NULLPTR));
        nearLabel->setText(QApplication::translate("UIQTClass", "Near", Q_NULLPTR));
        farLabel->setText(QApplication::translate("UIQTClass", "Far", Q_NULLPTR));
        undoPushButton->setText(QApplication::translate("UIQTClass", "Undo", Q_NULLPTR));
        redoPushButton->setText(QApplication::translate("UIQTClass", "Redo", Q_NULLPTR));
        pageLabel->setText(QApplication::translate("UIQTClass", "Page", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class UIQTClass: public Ui_UIQTClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UIQT_H
