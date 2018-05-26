#ifndef MAINMENU_H
#define MAINMENU_H

#include <QPixmap>
#include <QLabel>
#include <QPushButton>
#include <QDebug>
#include <QPainter>
#include <QMainWindow>

class MainMenu : public QMainWindow
{
    Q_OBJECT
public:
    MainMenu(QMainWindow *context);
    ~MainMenu();

    void paint(QPainter &painter);
private slots:
    void newGame();
private:
    QPixmap m_background;
    QLabel *m_gameTitle;
    QPushButton *m_newGameButton;

};

#endif // MAINMENU_H
