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
    QLabel *label_26;
    QLabel *label_22;
    QLabel *label_20;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *label_29;
    QLabel *label_28;
    QDoubleSpinBox *doubleSpinBox_7;
    QDoubleSpinBox *doubleSpinBox_8;
    QDoubleSpinBox *doubleSpinBox_9;
    QDoubleSpinBox *doubleSpinBox_10;
    QDoubleSpinBox *doubleSpinBox_11;
    QDoubleSpinBox *doubleSpinBox_12;
    QWidget *page_2;
    QGridLayout *gridLayout_6;
    QFrame *frame_3;
    QGridLayout *gridLayout_7;
    QLabel *label_7;
    QLabel *label_11;
    QLabel *label_5;
    QLabel *label_9;
    QLabel *label_6;
    QLabel *label_3;
    QLabel *label_12;
    QLabel *label_8;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox_4;
    QDoubleSpinBox *doubleSpinBox_5;
    QLabel *label_13;
    QDoubleSpinBox *doubleSpinBox_6;
    QLabel *label_10;
    QDoubleSpinBox *doubleSpinBox_13;
    QDoubleSpinBox *doubleSpinBox_14;
    QDoubleSpinBox *doubleSpinBox_15;
    QDoubleSpinBox *doubleSpinBox_16;
    QDoubleSpinBox *doubleSpinBox_17;
    QDoubleSpinBox *doubleSpinBox_18;
    QListWidget *modelObjectListWidget;
    QWidget *objetPage;
    QGridLayout *gridLayout_3;
    QListWidget *listWidget;
    QFrame *objet;
    QGridLayout *gridLayout;
    QLabel *positionZLabel;
    QSpinBox *positionXSpinBox;
    QSpinBox *rotationXSpinBox;
    QLabel *positionXLabel;
    QSpinBox *positionYSpinBox;
    QLabel *rotationLabel;
    QSpinBox *rotationYSpinBox;
    QLabel *positionLabel;
    QLabel *rotationZLabel;
    QSpinBox *rotationZSpinBox;
    QSpinBox *positionZSpinBox;
    QLabel *positionYLabel;
    QLabel *rotationYLabel;
    QLabel *scaleZLabel;
    QLabel *rotationXLabel;
    QLabel *shapeObjetLabel;
    QLabel *scaleLabel;
    QLabel *scaleXLabel;
    QDoubleSpinBox *scaleXSpinBox;
    QDoubleSpinBox *scaleYSpinBox;
    QLabel *scaleYLabel;
    QDoubleSpinBox *scaleZSpinBox;
    QWidget *cameraPage;
    QGridLayout *gridLayout_8;
    QFrame *camera;
    QGridLayout *gridLayout_2;
    QSpinBox *zoomSpinBox;
    QSpinBox *nearSpinBox;
    QSpinBox *farSpinBox;
    QSpinBox *pitchSpinBox;
    QSpinBox *yawSpinBox;
    QLabel *yawLabel;
    QLabel *pitchLabel;
    QLabel *nearLabel;
    QLabel *zoomLabel;
    QLabel *farLabel;
    QLabel *cameraLabel;
    QListWidget *CameraListWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_9;
    QPushButton *redoPushButton;
    QLabel *pageLabel;
    QPushButton *undoPushButton;
    QSpinBox *spinBox;

    void setupUi(QMainWindow *UIQTClass)
    {
        if (UIQTClass->objectName().isEmpty())
            UIQTClass->setObjectName(QStringLiteral("UIQTClass"));
        UIQTClass->resize(368, 480);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(UIQTClass->sizePolicy().hasHeightForWidth());
        UIQTClass->setSizePolicy(sizePolicy);
        UIQTClass->setMinimumSize(QSize(368, 480));
        UIQTClass->setMaximumSize(QSize(368, 480));
        UIQTClass->setWindowOpacity(1);
        centralWidget = new QWidget(UIQTClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(10, 10, 347, 404));
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
        doubleSpinBox_3->setReadOnly(true);
        doubleSpinBox_3->setMinimum(-999);
        doubleSpinBox_3->setMaximum(999);
        doubleSpinBox_3->setValue(0);

        gridLayout_4->addWidget(doubleSpinBox_3, 6, 5, 1, 1);

        doubleSpinBox = new QDoubleSpinBox(frame_2);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setAlignment(Qt::AlignCenter);
        doubleSpinBox->setReadOnly(true);
        doubleSpinBox->setMinimum(-999);
        doubleSpinBox->setMaximum(999);
        doubleSpinBox->setValue(0);

        gridLayout_4->addWidget(doubleSpinBox, 6, 1, 1, 1);

        label_30 = new QLabel(frame_2);
        label_30->setObjectName(QStringLiteral("label_30"));
        QFont font;
        font.setPointSize(10);
        label_30->setFont(font);
        label_30->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_30, 5, 0, 1, 6);

        doubleSpinBox_2 = new QDoubleSpinBox(frame_2);
        doubleSpinBox_2->setObjectName(QStringLiteral("doubleSpinBox_2"));
        doubleSpinBox_2->setAlignment(Qt::AlignCenter);
        doubleSpinBox_2->setReadOnly(true);
        doubleSpinBox_2->setMinimum(-999);
        doubleSpinBox_2->setMaximum(999);
        doubleSpinBox_2->setValue(0);

        gridLayout_4->addWidget(doubleSpinBox_2, 6, 3, 1, 1);

        label_14 = new QLabel(frame_2);
        label_14->setObjectName(QStringLiteral("label_14"));
        QFont font1;
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setWeight(75);
        label_14->setFont(font1);
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

        label_26 = new QLabel(frame_2);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_26, 6, 2, 1, 1);

        label_22 = new QLabel(frame_2);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_22, 4, 0, 1, 1);

        label_20 = new QLabel(frame_2);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_20, 2, 2, 1, 1);

        label_23 = new QLabel(frame_2);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_23, 4, 2, 1, 1);

        label_24 = new QLabel(frame_2);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_4->addWidget(label_24, 4, 4, 1, 1);

        label_29 = new QLabel(frame_2);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setFont(font);
        label_29->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_29, 3, 0, 1, 6);

        label_28 = new QLabel(frame_2);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setFont(font);
        label_28->setAlignment(Qt::AlignCenter);

        gridLayout_4->addWidget(label_28, 1, 0, 1, 6);

        doubleSpinBox_7 = new QDoubleSpinBox(frame_2);
        doubleSpinBox_7->setObjectName(QStringLiteral("doubleSpinBox_7"));
        doubleSpinBox_7->setAlignment(Qt::AlignCenter);
        doubleSpinBox_7->setReadOnly(false);
        doubleSpinBox_7->setMinimum(-999);
        doubleSpinBox_7->setMaximum(999);
        doubleSpinBox_7->setValue(0);

        gridLayout_4->addWidget(doubleSpinBox_7, 4, 1, 1, 1);

        doubleSpinBox_8 = new QDoubleSpinBox(frame_2);
        doubleSpinBox_8->setObjectName(QStringLiteral("doubleSpinBox_8"));
        doubleSpinBox_8->setAlignment(Qt::AlignCenter);
        doubleSpinBox_8->setReadOnly(false);
        doubleSpinBox_8->setMinimum(-999);
        doubleSpinBox_8->setMaximum(999);
        doubleSpinBox_8->setValue(0);

        gridLayout_4->addWidget(doubleSpinBox_8, 4, 3, 1, 1);

        doubleSpinBox_9 = new QDoubleSpinBox(frame_2);
        doubleSpinBox_9->setObjectName(QStringLiteral("doubleSpinBox_9"));
        doubleSpinBox_9->setAlignment(Qt::AlignCenter);
        doubleSpinBox_9->setReadOnly(false);
        doubleSpinBox_9->setMinimum(-999);
        doubleSpinBox_9->setMaximum(999);
        doubleSpinBox_9->setValue(0);

        gridLayout_4->addWidget(doubleSpinBox_9, 4, 5, 1, 1);

        doubleSpinBox_10 = new QDoubleSpinBox(frame_2);
        doubleSpinBox_10->setObjectName(QStringLiteral("doubleSpinBox_10"));
        doubleSpinBox_10->setAlignment(Qt::AlignCenter);
        doubleSpinBox_10->setReadOnly(false);
        doubleSpinBox_10->setMinimum(-999);
        doubleSpinBox_10->setMaximum(999);
        doubleSpinBox_10->setValue(0);

        gridLayout_4->addWidget(doubleSpinBox_10, 2, 1, 1, 1);

        doubleSpinBox_11 = new QDoubleSpinBox(frame_2);
        doubleSpinBox_11->setObjectName(QStringLiteral("doubleSpinBox_11"));
        doubleSpinBox_11->setAlignment(Qt::AlignCenter);
        doubleSpinBox_11->setReadOnly(false);
        doubleSpinBox_11->setMinimum(-999);
        doubleSpinBox_11->setMaximum(999);
        doubleSpinBox_11->setValue(0);

        gridLayout_4->addWidget(doubleSpinBox_11, 2, 3, 1, 1);

        doubleSpinBox_12 = new QDoubleSpinBox(frame_2);
        doubleSpinBox_12->setObjectName(QStringLiteral("doubleSpinBox_12"));
        doubleSpinBox_12->setAlignment(Qt::AlignCenter);
        doubleSpinBox_12->setReadOnly(false);
        doubleSpinBox_12->setMinimum(-999);
        doubleSpinBox_12->setMaximum(999);
        doubleSpinBox_12->setValue(0);

        gridLayout_4->addWidget(doubleSpinBox_12, 2, 5, 1, 1);


        gridLayout_5->addWidget(frame_2, 1, 0, 1, 2);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        gridLayout_6 = new QGridLayout(page_2);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        frame_3 = new QFrame(page_2);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setFrameShape(QFrame::Box);
        frame_3->setFrameShadow(QFrame::Plain);
        gridLayout_7 = new QGridLayout(frame_3);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        label_7 = new QLabel(frame_3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_7->addWidget(label_7, 2, 0, 1, 1);

        label_11 = new QLabel(frame_3);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_7->addWidget(label_11, 2, 4, 1, 1);

        label_5 = new QLabel(frame_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_7->addWidget(label_5, 2, 2, 1, 1);

        label_9 = new QLabel(frame_3);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font);
        label_9->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(label_9, 3, 0, 1, 6);

        label_6 = new QLabel(frame_3);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_7->addWidget(label_6, 4, 2, 1, 1);

        label_3 = new QLabel(frame_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_7->addWidget(label_3, 4, 0, 1, 1);

        label_12 = new QLabel(frame_3);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_7->addWidget(label_12, 4, 4, 1, 1);

        label_8 = new QLabel(frame_3);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font);
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(label_8, 1, 0, 1, 6);

        label = new QLabel(frame_3);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(label, 0, 0, 1, 6);

        label_4 = new QLabel(frame_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_7->addWidget(label_4, 6, 2, 1, 1);

        label_2 = new QLabel(frame_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_7->addWidget(label_2, 6, 0, 1, 1);

        doubleSpinBox_4 = new QDoubleSpinBox(frame_3);
        doubleSpinBox_4->setObjectName(QStringLiteral("doubleSpinBox_4"));
        doubleSpinBox_4->setAlignment(Qt::AlignCenter);
        doubleSpinBox_4->setMinimum(-999);
        doubleSpinBox_4->setMaximum(999);

        gridLayout_7->addWidget(doubleSpinBox_4, 6, 1, 1, 1);

        doubleSpinBox_5 = new QDoubleSpinBox(frame_3);
        doubleSpinBox_5->setObjectName(QStringLiteral("doubleSpinBox_5"));
        doubleSpinBox_5->setAlignment(Qt::AlignCenter);
        doubleSpinBox_5->setMinimum(-999);
        doubleSpinBox_5->setMaximum(999);

        gridLayout_7->addWidget(doubleSpinBox_5, 6, 3, 1, 1);

        label_13 = new QLabel(frame_3);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_7->addWidget(label_13, 6, 4, 1, 1);

        doubleSpinBox_6 = new QDoubleSpinBox(frame_3);
        doubleSpinBox_6->setObjectName(QStringLiteral("doubleSpinBox_6"));
        doubleSpinBox_6->setAlignment(Qt::AlignCenter);
        doubleSpinBox_6->setMinimum(-999);
        doubleSpinBox_6->setMaximum(999);

        gridLayout_7->addWidget(doubleSpinBox_6, 6, 5, 1, 1);

        label_10 = new QLabel(frame_3);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font);
        label_10->setAlignment(Qt::AlignCenter);

        gridLayout_7->addWidget(label_10, 5, 0, 1, 6);

        doubleSpinBox_13 = new QDoubleSpinBox(frame_3);
        doubleSpinBox_13->setObjectName(QStringLiteral("doubleSpinBox_13"));
        doubleSpinBox_13->setAlignment(Qt::AlignCenter);
        doubleSpinBox_13->setMinimum(-999);
        doubleSpinBox_13->setMaximum(999);

        gridLayout_7->addWidget(doubleSpinBox_13, 4, 1, 1, 1);

        doubleSpinBox_14 = new QDoubleSpinBox(frame_3);
        doubleSpinBox_14->setObjectName(QStringLiteral("doubleSpinBox_14"));
        doubleSpinBox_14->setAlignment(Qt::AlignCenter);
        doubleSpinBox_14->setMinimum(-999);
        doubleSpinBox_14->setMaximum(999);

        gridLayout_7->addWidget(doubleSpinBox_14, 4, 3, 1, 1);

        doubleSpinBox_15 = new QDoubleSpinBox(frame_3);
        doubleSpinBox_15->setObjectName(QStringLiteral("doubleSpinBox_15"));
        doubleSpinBox_15->setAlignment(Qt::AlignCenter);
        doubleSpinBox_15->setMinimum(-999);
        doubleSpinBox_15->setMaximum(999);

        gridLayout_7->addWidget(doubleSpinBox_15, 4, 5, 1, 1);

        doubleSpinBox_16 = new QDoubleSpinBox(frame_3);
        doubleSpinBox_16->setObjectName(QStringLiteral("doubleSpinBox_16"));
        doubleSpinBox_16->setAlignment(Qt::AlignCenter);
        doubleSpinBox_16->setMinimum(-999);
        doubleSpinBox_16->setMaximum(999);

        gridLayout_7->addWidget(doubleSpinBox_16, 2, 1, 1, 1);

        doubleSpinBox_17 = new QDoubleSpinBox(frame_3);
        doubleSpinBox_17->setObjectName(QStringLiteral("doubleSpinBox_17"));
        doubleSpinBox_17->setAlignment(Qt::AlignCenter);
        doubleSpinBox_17->setMinimum(-999);
        doubleSpinBox_17->setMaximum(999);

        gridLayout_7->addWidget(doubleSpinBox_17, 2, 3, 1, 1);

        doubleSpinBox_18 = new QDoubleSpinBox(frame_3);
        doubleSpinBox_18->setObjectName(QStringLiteral("doubleSpinBox_18"));
        doubleSpinBox_18->setAlignment(Qt::AlignCenter);
        doubleSpinBox_18->setMinimum(-999);
        doubleSpinBox_18->setMaximum(999);

        gridLayout_7->addWidget(doubleSpinBox_18, 2, 5, 1, 1);


        gridLayout_6->addWidget(frame_3, 1, 1, 1, 1);

        modelObjectListWidget = new QListWidget(page_2);
        modelObjectListWidget->setObjectName(QStringLiteral("modelObjectListWidget"));

        gridLayout_6->addWidget(modelObjectListWidget, 0, 1, 1, 1);

        stackedWidget->addWidget(page_2);
        objetPage = new QWidget();
        objetPage->setObjectName(QStringLiteral("objetPage"));
        gridLayout_3 = new QGridLayout(objetPage);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        listWidget = new QListWidget(objetPage);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->viewport()->setProperty("cursor", QVariant(QCursor(Qt::PointingHandCursor)));

        gridLayout_3->addWidget(listWidget, 0, 0, 1, 1);

        objet = new QFrame(objetPage);
        objet->setObjectName(QStringLiteral("objet"));
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

        rotationXSpinBox = new QSpinBox(objet);
        rotationXSpinBox->setObjectName(QStringLiteral("rotationXSpinBox"));
        rotationXSpinBox->setAlignment(Qt::AlignCenter);
        rotationXSpinBox->setMinimum(-360);
        rotationXSpinBox->setMaximum(360);

        gridLayout->addWidget(rotationXSpinBox, 8, 1, 1, 1);

        positionXLabel = new QLabel(objet);
        positionXLabel->setObjectName(QStringLiteral("positionXLabel"));

        gridLayout->addWidget(positionXLabel, 2, 0, 1, 1);

        positionYSpinBox = new QSpinBox(objet);
        positionYSpinBox->setObjectName(QStringLiteral("positionYSpinBox"));
        positionYSpinBox->setAlignment(Qt::AlignCenter);
        positionYSpinBox->setMinimum(-999999999);
        positionYSpinBox->setMaximum(999999999);

        gridLayout->addWidget(positionYSpinBox, 2, 3, 1, 1);

        rotationLabel = new QLabel(objet);
        rotationLabel->setObjectName(QStringLiteral("rotationLabel"));
        rotationLabel->setFont(font);
        rotationLabel->setAlignment(Qt::AlignCenter);
        rotationLabel->setTextInteractionFlags(Qt::NoTextInteraction);

        gridLayout->addWidget(rotationLabel, 7, 1, 1, 5);

        rotationYSpinBox = new QSpinBox(objet);
        rotationYSpinBox->setObjectName(QStringLiteral("rotationYSpinBox"));
        rotationYSpinBox->setAlignment(Qt::AlignCenter);
        rotationYSpinBox->setMinimum(-360);
        rotationYSpinBox->setMaximum(360);

        gridLayout->addWidget(rotationYSpinBox, 8, 3, 1, 1);

        positionLabel = new QLabel(objet);
        positionLabel->setObjectName(QStringLiteral("positionLabel"));
        positionLabel->setFont(font);
        positionLabel->setAlignment(Qt::AlignCenter);
        positionLabel->setTextInteractionFlags(Qt::NoTextInteraction);

        gridLayout->addWidget(positionLabel, 1, 1, 1, 5);

        rotationZLabel = new QLabel(objet);
        rotationZLabel->setObjectName(QStringLiteral("rotationZLabel"));

        gridLayout->addWidget(rotationZLabel, 8, 4, 1, 1);

        rotationZSpinBox = new QSpinBox(objet);
        rotationZSpinBox->setObjectName(QStringLiteral("rotationZSpinBox"));
        rotationZSpinBox->setAlignment(Qt::AlignCenter);
        rotationZSpinBox->setMinimum(-360);
        rotationZSpinBox->setMaximum(360);

        gridLayout->addWidget(rotationZSpinBox, 8, 5, 1, 1);

        positionZSpinBox = new QSpinBox(objet);
        positionZSpinBox->setObjectName(QStringLiteral("positionZSpinBox"));
        positionZSpinBox->setAlignment(Qt::AlignCenter);
        positionZSpinBox->setMinimum(-999999999);
        positionZSpinBox->setMaximum(999999999);

        gridLayout->addWidget(positionZSpinBox, 2, 5, 1, 1);

        positionYLabel = new QLabel(objet);
        positionYLabel->setObjectName(QStringLiteral("positionYLabel"));

        gridLayout->addWidget(positionYLabel, 2, 2, 1, 1);

        rotationYLabel = new QLabel(objet);
        rotationYLabel->setObjectName(QStringLiteral("rotationYLabel"));

        gridLayout->addWidget(rotationYLabel, 8, 2, 1, 1);

        scaleZLabel = new QLabel(objet);
        scaleZLabel->setObjectName(QStringLiteral("scaleZLabel"));

        gridLayout->addWidget(scaleZLabel, 10, 4, 1, 1);

        rotationXLabel = new QLabel(objet);
        rotationXLabel->setObjectName(QStringLiteral("rotationXLabel"));

        gridLayout->addWidget(rotationXLabel, 8, 0, 1, 1);

        shapeObjetLabel = new QLabel(objet);
        shapeObjetLabel->setObjectName(QStringLiteral("shapeObjetLabel"));
        shapeObjetLabel->setFont(font1);
        shapeObjetLabel->setAlignment(Qt::AlignCenter);
        shapeObjetLabel->setTextInteractionFlags(Qt::NoTextInteraction);

        gridLayout->addWidget(shapeObjetLabel, 0, 1, 1, 5);

        scaleLabel = new QLabel(objet);
        scaleLabel->setObjectName(QStringLiteral("scaleLabel"));
        scaleLabel->setFont(font);
        scaleLabel->setAlignment(Qt::AlignCenter);
        scaleLabel->setTextInteractionFlags(Qt::NoTextInteraction);

        gridLayout->addWidget(scaleLabel, 9, 3, 1, 1);

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

        scaleYLabel = new QLabel(objet);
        scaleYLabel->setObjectName(QStringLiteral("scaleYLabel"));

        gridLayout->addWidget(scaleYLabel, 10, 2, 1, 1);

        scaleZSpinBox = new QDoubleSpinBox(objet);
        scaleZSpinBox->setObjectName(QStringLiteral("scaleZSpinBox"));
        scaleZSpinBox->setAlignment(Qt::AlignCenter);
        scaleZSpinBox->setDecimals(1);
        scaleZSpinBox->setMinimum(0.1);
        scaleZSpinBox->setValue(1);

        gridLayout->addWidget(scaleZSpinBox, 10, 5, 1, 1);


        gridLayout_3->addWidget(objet, 1, 0, 1, 1);

        stackedWidget->addWidget(objetPage);
        cameraPage = new QWidget();
        cameraPage->setObjectName(QStringLiteral("cameraPage"));
        gridLayout_8 = new QGridLayout(cameraPage);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        camera = new QFrame(cameraPage);
        camera->setObjectName(QStringLiteral("camera"));
        camera->setFrameShape(QFrame::Box);
        camera->setFrameShadow(QFrame::Plain);
        gridLayout_2 = new QGridLayout(camera);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        zoomSpinBox = new QSpinBox(camera);
        zoomSpinBox->setObjectName(QStringLiteral("zoomSpinBox"));
        zoomSpinBox->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(zoomSpinBox, 6, 1, 1, 1);

        nearSpinBox = new QSpinBox(camera);
        nearSpinBox->setObjectName(QStringLiteral("nearSpinBox"));
        nearSpinBox->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(nearSpinBox, 8, 1, 1, 1);

        farSpinBox = new QSpinBox(camera);
        farSpinBox->setObjectName(QStringLiteral("farSpinBox"));
        farSpinBox->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(farSpinBox, 10, 1, 1, 1);

        pitchSpinBox = new QSpinBox(camera);
        pitchSpinBox->setObjectName(QStringLiteral("pitchSpinBox"));
        pitchSpinBox->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(pitchSpinBox, 2, 1, 1, 1);

        yawSpinBox = new QSpinBox(camera);
        yawSpinBox->setObjectName(QStringLiteral("yawSpinBox"));
        yawSpinBox->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(yawSpinBox, 4, 1, 1, 1);

        yawLabel = new QLabel(camera);
        yawLabel->setObjectName(QStringLiteral("yawLabel"));
        yawLabel->setFont(font);
        yawLabel->setCursor(QCursor(Qt::ArrowCursor));
        yawLabel->setAlignment(Qt::AlignCenter);
        yawLabel->setTextInteractionFlags(Qt::NoTextInteraction);

        gridLayout_2->addWidget(yawLabel, 4, 0, 1, 1);

        pitchLabel = new QLabel(camera);
        pitchLabel->setObjectName(QStringLiteral("pitchLabel"));
        pitchLabel->setFont(font);
        pitchLabel->setLayoutDirection(Qt::LeftToRight);
        pitchLabel->setAutoFillBackground(false);
        pitchLabel->setAlignment(Qt::AlignCenter);
        pitchLabel->setTextInteractionFlags(Qt::NoTextInteraction);

        gridLayout_2->addWidget(pitchLabel, 2, 0, 1, 1);

        nearLabel = new QLabel(camera);
        nearLabel->setObjectName(QStringLiteral("nearLabel"));
        nearLabel->setFont(font);
        nearLabel->setAlignment(Qt::AlignCenter);
        nearLabel->setTextInteractionFlags(Qt::NoTextInteraction);

        gridLayout_2->addWidget(nearLabel, 8, 0, 1, 1);

        zoomLabel = new QLabel(camera);
        zoomLabel->setObjectName(QStringLiteral("zoomLabel"));
        zoomLabel->setFont(font);
        zoomLabel->setAlignment(Qt::AlignCenter);
        zoomLabel->setTextInteractionFlags(Qt::NoTextInteraction);

        gridLayout_2->addWidget(zoomLabel, 6, 0, 1, 1);

        farLabel = new QLabel(camera);
        farLabel->setObjectName(QStringLiteral("farLabel"));
        farLabel->setFont(font);
        farLabel->setAlignment(Qt::AlignCenter);
        farLabel->setTextInteractionFlags(Qt::NoTextInteraction);

        gridLayout_2->addWidget(farLabel, 10, 0, 1, 1);

        cameraLabel = new QLabel(camera);
        cameraLabel->setObjectName(QStringLiteral("cameraLabel"));
        cameraLabel->setFont(font1);
        cameraLabel->setAlignment(Qt::AlignCenter);
        cameraLabel->setTextInteractionFlags(Qt::NoTextInteraction);

        gridLayout_2->addWidget(cameraLabel, 0, 0, 1, 2);


        gridLayout_8->addWidget(camera, 1, 0, 1, 1);

        CameraListWidget = new QListWidget(cameraPage);
        CameraListWidget->setObjectName(QStringLiteral("CameraListWidget"));

        gridLayout_8->addWidget(CameraListWidget, 0, 0, 1, 1);

        stackedWidget->addWidget(cameraPage);
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(20, 420, 331, 31));
        gridLayout_9 = new QGridLayout(gridLayoutWidget);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        gridLayout_9->setContentsMargins(0, 0, 0, 0);
        redoPushButton = new QPushButton(gridLayoutWidget);
        redoPushButton->setObjectName(QStringLiteral("redoPushButton"));

        gridLayout_9->addWidget(redoPushButton, 0, 1, 1, 1);

        pageLabel = new QLabel(gridLayoutWidget);
        pageLabel->setObjectName(QStringLiteral("pageLabel"));
        pageLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_9->addWidget(pageLabel, 0, 2, 1, 1);

        undoPushButton = new QPushButton(gridLayoutWidget);
        undoPushButton->setObjectName(QStringLiteral("undoPushButton"));

        gridLayout_9->addWidget(undoPushButton, 0, 0, 1, 1);

        spinBox = new QSpinBox(gridLayoutWidget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setMaximum(3);

        gridLayout_9->addWidget(spinBox, 0, 3, 1, 1);

        UIQTClass->setCentralWidget(centralWidget);
        QWidget::setTabOrder(positionYSpinBox, rotationXSpinBox);
        QWidget::setTabOrder(rotationXSpinBox, rotationYSpinBox);
        QWidget::setTabOrder(rotationYSpinBox, positionZSpinBox);
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
        QObject::connect(UIQTClass, SIGNAL(currentEmptyXScale(double)), doubleSpinBox, SLOT(setValue(double)));
        QObject::connect(UIQTClass, SIGNAL(currentEmptyYScale(double)), doubleSpinBox_2, SLOT(setValue(double)));
        QObject::connect(UIQTClass, SIGNAL(currentEmptyZScale(double)), doubleSpinBox_3, SLOT(setValue(double)));
        QObject::connect(emptyObjectListWidget, SIGNAL(clicked(QModelIndex)), UIQTClass, SLOT(selectedObject(QModelIndex)));
        QObject::connect(modelObjectListWidget, SIGNAL(clicked(QModelIndex)), UIQTClass, SLOT(selectedObject(QModelIndex)));
        QObject::connect(doubleSpinBox, SIGNAL(valueChanged(double)), UIQTClass, SLOT(newEmptyXScale(double)));
        QObject::connect(doubleSpinBox_2, SIGNAL(valueChanged(double)), UIQTClass, SLOT(newEmptyYScale(double)));
        QObject::connect(doubleSpinBox_3, SIGNAL(valueChanged(double)), UIQTClass, SLOT(newEmptyZScale(double)));
        QObject::connect(UIQTClass, SIGNAL(currentModelXScale(double)), doubleSpinBox_4, SLOT(setValue(double)));
        QObject::connect(UIQTClass, SIGNAL(currentModelYScale(double)), doubleSpinBox_5, SLOT(setValue(double)));
        QObject::connect(UIQTClass, SIGNAL(currentModelZScale(double)), doubleSpinBox_6, SLOT(setValue(double)));
        QObject::connect(doubleSpinBox_4, SIGNAL(valueChanged(double)), UIQTClass, SLOT(newModelXScale(double)));
        QObject::connect(doubleSpinBox_5, SIGNAL(valueChanged(double)), UIQTClass, SLOT(newModelYScale(double)));
        QObject::connect(doubleSpinBox_6, SIGNAL(valueChanged(double)), UIQTClass, SLOT(newModelZScale(double)));
        QObject::connect(doubleSpinBox, SIGNAL(valueChanged(double)), UIQTClass, SLOT(newXScale(double)));

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
        label_7->setText(QApplication::translate("UIQTClass", "x", Q_NULLPTR));
        label_11->setText(QApplication::translate("UIQTClass", "z", Q_NULLPTR));
        label_5->setText(QApplication::translate("UIQTClass", "y", Q_NULLPTR));
        label_9->setText(QApplication::translate("UIQTClass", "Rotation", Q_NULLPTR));
        label_6->setText(QApplication::translate("UIQTClass", "y", Q_NULLPTR));
        label_3->setText(QApplication::translate("UIQTClass", "x", Q_NULLPTR));
        label_12->setText(QApplication::translate("UIQTClass", "z", Q_NULLPTR));
        label_8->setText(QApplication::translate("UIQTClass", "Position", Q_NULLPTR));
        label->setText(QApplication::translate("UIQTClass", "Model Object", Q_NULLPTR));
        label_4->setText(QApplication::translate("UIQTClass", "y", Q_NULLPTR));
        label_2->setText(QApplication::translate("UIQTClass", "x", Q_NULLPTR));
        label_13->setText(QApplication::translate("UIQTClass", "z", Q_NULLPTR));
        label_10->setText(QApplication::translate("UIQTClass", "Scale", Q_NULLPTR));
        positionZLabel->setText(QApplication::translate("UIQTClass", "Z:", Q_NULLPTR));
        positionXLabel->setText(QApplication::translate("UIQTClass", "X:", Q_NULLPTR));
        rotationLabel->setText(QApplication::translate("UIQTClass", "Rotation", Q_NULLPTR));
        positionLabel->setText(QApplication::translate("UIQTClass", "Position", Q_NULLPTR));
        rotationZLabel->setText(QApplication::translate("UIQTClass", "Z:", Q_NULLPTR));
        positionYLabel->setText(QApplication::translate("UIQTClass", "Y:", Q_NULLPTR));
        rotationYLabel->setText(QApplication::translate("UIQTClass", "Y:", Q_NULLPTR));
        scaleZLabel->setText(QApplication::translate("UIQTClass", "Z:", Q_NULLPTR));
        rotationXLabel->setText(QApplication::translate("UIQTClass", "X:", Q_NULLPTR));
        shapeObjetLabel->setText(QApplication::translate("UIQTClass", "Shape Objet", Q_NULLPTR));
        scaleLabel->setText(QApplication::translate("UIQTClass", "Scale", Q_NULLPTR));
        scaleXLabel->setText(QApplication::translate("UIQTClass", "X:", Q_NULLPTR));
        scaleYLabel->setText(QApplication::translate("UIQTClass", "Y:", Q_NULLPTR));
        yawLabel->setText(QApplication::translate("UIQTClass", "Yaw", Q_NULLPTR));
        pitchLabel->setText(QApplication::translate("UIQTClass", "Pitch", Q_NULLPTR));
        nearLabel->setText(QApplication::translate("UIQTClass", "Near", Q_NULLPTR));
        zoomLabel->setText(QApplication::translate("UIQTClass", "Zoom", Q_NULLPTR));
        farLabel->setText(QApplication::translate("UIQTClass", "Far", Q_NULLPTR));
        cameraLabel->setText(QApplication::translate("UIQTClass", "Camera", Q_NULLPTR));
        redoPushButton->setText(QApplication::translate("UIQTClass", "Redo", Q_NULLPTR));
        pageLabel->setText(QApplication::translate("UIQTClass", "Page", Q_NULLPTR));
        undoPushButton->setText(QApplication::translate("UIQTClass", "Undo", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class UIQTClass: public Ui_UIQTClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UIQT_H
