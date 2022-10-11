//
// Created by 86184 on 2022/10/11.
//

#ifndef MUSICPLAYER_MAINWINDOW_H
#define MUSICPLAYER_MAINWINDOW_H
#include <QMainWindow>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimedia/QMediaPlaylist>
#include <QPushButton>
#include <QSlider>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QListWidget>
#include <QLabel>
#include <QSpacerItem>
#include <QDebug>


class MediaObjectInfo{
public:
    QString fileName;
    QString filePath;
};
class MainWindow :public QMainWindow{
    Q_OBJECT
public:
    MainWindow(QWidget *parent= nullptr);
    ~MainWindow();
private:
    //媒体播放器
    QMediaPlayer *musicPlayer;

    //媒体列表
    QMediaPlaylist *mediaPlaylist;

    //音乐列表
    QListWidget *listWidget;

    //播放进度条
    QSlider *durationSlider;

    //音乐播放器按钮
    QPushButton *pushButton[7];

    //垂直布局
    QVBoxLayout *vBoxLayout[3];

    //水平布局
    QHBoxLayout *hBoxLayout[4];

    //垂直容器
    QWidget *vWidget[3];
    //水平容器
    QWidget *hWidget[4];

    QLabel *label[4];

    QWidget *listMask;

    void musicLayout();

    void resizeEvent(QResizeEvent *event);

    QVector<MediaObjectInfo> mediaObjectInfo;

    void scanSongs();

    void mediaPlayerInit();

private slots:
    //播放
    void btn_play_clicked();

    void btn_next_clicked();

    void btn_previous_clicked();
    //媒体状态改变
    void mediaPlayerStateChanged(QMediaPlayer::State);
    //列表单击
    void listWidgetClicked(QListWidgetItem*);
    //媒体列表项改变
    void mediaPlaylistCurrentIndexChanged(int);
    //媒体总长度改变
    void musicPlayerDurationChanged(qint64);
    //媒体播放位置改变
    void mediaPlayerPositionChanged(qint64);
    //播放进度条松开
    void durationSliderReleased();

};

#endif //MUSICPLAYER_MAINWINDOW_H
