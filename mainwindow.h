#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "dialog.h"
#include <QMainWindow>
#include <QGraphicsScene>
#include "AbstrOptimization.h"
#include "MyGraph.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void on_settingsBtn_clicked();

    void on_startBtn_clicked();

    void on_scene_clicked(const QPointF &pos);

    void plot();

    void startOptimaze(std::vector<double> startPoint);

    void plot_trajectory(MyGraph* scene);

private:
    Ui::MainWindow *ui;
    Dialog settingPage;
    MyGraph *scene;

    std::vector<std::vector<double>>trajectory;

};
#endif // MAINWINDOW_H
