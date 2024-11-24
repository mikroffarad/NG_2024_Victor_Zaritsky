#ifndef HOWL_H
#define HOWL_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMediaPlayer>
#include <QAudioOutput>

#include <QDebug>
#include <QAction>
#include <QMenu>

QT_BEGIN_NAMESPACE
namespace Ui {
class Howl;
}
QT_END_NAMESPACE

class Howl : public QMainWindow
{
    Q_OBJECT

public:
    Howl(QWidget *parent = nullptr);
    ~Howl();

private slots:
    void selectFiles();

    void setVolumeText(int volume);
    void setMedia(QString text);

    void setProgress(qint64 progress);
    void setVolume(int volume);
    void playStateChanged(QMediaPlayer::PlaybackState state);

    void setNextTrack();
    void setPreviousTrack();
    void stopAudio();
    void onSliderReleased();
    void updateSlider(qint64 position);
    void updateSliderRange(qint64 duration);

    void updateDuration(qint64 duration);
    void updatePosition(qint64 position);

private:
    Ui::Howl *ui;
    QMenu *m_file;
    QAction *m_select;

    const int c_startVolume = 50;

    QMediaPlayer *m_player;
    QAudioOutput *m_audioOutput;

    QString formatTime(qint64 ms);
};
#endif // HOWL_H
