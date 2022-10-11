//
// Created by 86184 on 2022/10/11.
//

#include "MainWindow.h"
#include <QCoreApplication>
#include <QFileInfoList>
#include <QDir>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent) {
    musicLayout();

    mediaPlayerInit();

    scanSongs();

    connect(pushButton[0], SIGNAL(clicked()),this, SLOT(btn_previous_clicked()));
    connect(pushButton[1], SIGNAL(clicked()),this, SLOT(btn_play_clicked()));
    connect(pushButton[2], SIGNAL(clicked()),this, SLOT(btn_next_clicked()));

    connect(musicPlayer, SIGNAL(stateChanged(QMediaPlayer::State)),this, SLOT(mediaPlayerStateChanged(QMediaPlayer::State)));
    connect(mediaPlaylist, SIGNAL(currentIndexChanged(int)),this, SLOT(mediaPlaylistCurrentIndexChanged(int)));
    connect(musicPlayer, SIGNAL(durationChanged(qint64)),this, SLOT(musicPlayerDurationChanged(qint64)));
    connect(musicPlayer, SIGNAL(positionChanged(qint64)),this, SLOT(mediaPlayerPositionChanged(qint64)));


    connect(listWidget, SIGNAL(itemClicked(QListWidgetItem *)),this, SLOT(listWidgetClicked(QListWidgetItem *)));
    connect(durationSlider, SIGNAL(sliderReleased()),this, SLOT(durationSliderReleased()));

    this->setFocus();

}

void MainWindow::musicLayout() {
    this->setGeometry(0,0,800,480);
    QPalette pal;

    for (int i = 0; i < 7; ++i) {
        pushButton[i]=new QPushButton();
    }
    for (int i = 0; i < 4; ++i) {
        label[i]=new QLabel();
    }
    for (int i = 0; i < 3; ++i) {
        vWidget[i]=new QWidget();
        vWidget[i]->setAutoFillBackground(true);
        vBoxLayout[i]=new QVBoxLayout();
    }
    for (int i = 0; i < 4; ++i) {
        hWidget[i]=new QWidget();
        hWidget[i]->setAutoFillBackground(true);
        hBoxLayout[i]=new QHBoxLayout();
        
    }
    durationSlider=new QSlider(Qt::Horizontal);
    durationSlider->setMinimumSize(300,15);
    durationSlider->setMaximumHeight(15);
    durationSlider->setObjectName("durationSlider");
    
    listWidget=new QListWidget();
    listWidget->setObjectName("listWidget");
    listWidget->resize(310,265);
    listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    listWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    
    listMask=new QWidget(listWidget);
    listMask->setMinimumSize(310,50);
    listMask->setMinimumHeight(50);
    listMask->setObjectName("listMask");
    listMask->setGeometry(0,listWidget->height()-50,310,50);
    
    pushButton[0]->setObjectName("btn_previous");
    pushButton[1]->setObjectName("btn_play");
    pushButton[2]->setObjectName("btn_next");
    pushButton[3]->setObjectName("btn_favorite");
    pushButton[4]->setObjectName("btn_mode");
    pushButton[5]->setObjectName("btn_menu");
    pushButton[6]->setObjectName("btn_volume");
    
    pushButton[1]->setCheckable(true);
    pushButton[3]->setCheckable(true);
    
    vWidget[0]->setMinimumSize(310,480);
    vWidget[0]->setMaximumWidth(310);
    vWidget[1]->setMinimumSize(320,480);
    QSpacerItem *hSpacer0 = new QSpacerItem(70,480,QSizePolicy::Minimum,QSizePolicy::Maximum);
    
    QSpacerItem *hSpacer1 = new QSpacerItem(65,480,QSizePolicy::Minimum,QSizePolicy::Maximum);
    
    QSpacerItem *hSpacer2=new QSpacerItem(40,480,QSizePolicy::Minimum,QSizePolicy::Maximum);
    
    
}
MainWindow::~MainWindow() noexcept {
    
}

void MainWindow::btn_play_clicked() {
    int state=musicPlayer->state();
    switch (state) {
        
    }
}
