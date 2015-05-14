#ifndef WVS_MAIN_WINDOW_H
#define WVS_MAIN_WINDOW_H

#include <QMainWindow>

namespace Ui {
class wvs_main_window;
}

class wvs_main_window : public QMainWindow
{
    Q_OBJECT

public:
    explicit wvs_main_window(QWidget *parent = 0);
    ~wvs_main_window();

private:
    Ui::wvs_main_window *ui;

<<<<<<< HEAD

private:
=======
>>>>>>> 47eda7be3315b81d5ab46d3c230d0870a06bc503
    std::string strFilename;
    QTimer* ofTimer;

private slots:
    // trigger thread to open image
    void OpenFileAction();
    // thread to open image
    void OpenFileThread();
};

#endif // WVS_MAIN_WINDOW_H
