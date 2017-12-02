#include "voorgeschoteldwindow.h"
#include "ui_voorgeschoteldwindow.h"

VoorgeschoteldWindow::VoorgeschoteldWindow(QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::VoorgeschoteldWindow)
{
    m_ui->setupUi(this);
}



VoorgeschoteldWindow::~VoorgeschoteldWindow()
{
    delete m_ui;
}
