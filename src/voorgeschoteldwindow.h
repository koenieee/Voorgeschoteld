#ifndef VOORGESCHOTELDWINDOW_H
#define VOORGESCHOTELDWINDOW_H

#include <QMainWindow>

namespace Ui {
class VoorgeschoteldWindow;
}

class VoorgeschoteldWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit VoorgeschoteldWindow(QWidget *parent = 0);
    ~VoorgeschoteldWindow();

private:
    Ui::VoorgeschoteldWindow *ui;
};

#endif // VOORGESCHOTELDWINDOW_H
