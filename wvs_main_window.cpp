#include "wvs_main_window.h"
#include "ui_wvs_main_window.h"

wvs_main_window::wvs_main_window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::wvs_main_window)
{
    ui->setupUi(this);

    connect(ui->actionOpen,	 SIGNAL(triggered()), this, SLOT(OpenFileAction()));
    ofTimer = new QTimer(this); connect(ofTimer, SIGNAL(timeout()), this, SLOT(OpenFileThread()));

    // actionSave_as_an_svg_file
    connect(ui->actionSave_as_an_svg_file,	 SIGNAL(triggered()), this, SLOT(SaveSVG()));

    // actionSave_as_a_bitmap
    connect(ui->actionSave_as_a_bitmap,	 SIGNAL(triggered()), this, SLOT(SaveBitmap()));
}

wvs_main_window::~wvs_main_window()
{
    delete ui;
}

void wvs_main_window::SaveSVG()
{
    ui->widget->GetGLWidget()->SaveToSvg();
}

void wvs_main_window::SaveBitmap()
{
    ui->widget->GetGLWidget()->SaveToBitmap();
}

void wvs_main_window::OpenFileThread()
{

    QApplication::setOverrideCursor(Qt::WaitCursor);
    QApplication::processEvents();
    //ui.statusBar->showMessage("Opening image...", 100000);

    QString qFilename = QString::fromStdString(strFilename);

    // Display image
    ui->widget->GetGLWidget()->SetImage(qFilename);
    ui->widget->GetGLWidget()->repaint();
    ui->widget->SetScrolls();

    std::cout << "Image loaded\n";

    ofTimer->stop();
    QApplication::restoreOverrideCursor();
}

void wvs_main_window::OpenFileAction()
{
    // Get Filename
    QString qFilename = QFileDialog::getOpenFileName(this, "/home/azer/Desktop/");
    if(qFilename.isEmpty()) return;
    strFilename = qFilename.toStdString();
    //std::cout << strFilename << "\n";

    ofTimer->start(1);						// Use timer to enable cursor override
}
