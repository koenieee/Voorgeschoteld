#include "voorgeschoteldwindow.h"
#include "ui_voorgeschoteldwindow.h"

VoorgeschoteldWindow::VoorgeschoteldWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VoorgeschoteldWindow)
{
    ui->setupUi(this);
}



VoorgeschoteldWindow::~VoorgeschoteldWindow()
{
    delete ui;
}
