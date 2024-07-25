#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include "AbstrFunction.h"
#include "AbstrOptimization.h"
#include "AbstrStopCriteria.h"
#include "F1.h"
#include "F2.h"
#include "F3.h"
#include "GradientDescentOptimizer.h"
#include "RectArea.h"
#include "StochasticOptimizer.h"
#include "StopByFunctionValue.h"
#include "StopByGradVal.h"
#include "StopByPoint.h"
#include "StopThroughIter.h"
#include <QGraphicsScene>
#include "MyGraph.h"
#include <vector>
#include <QObject>
#include "RectArea.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new MyGraph(this);
    ui->graphicsView->setScene(scene);
    QFont font;
    font.setPixelSize(20);
    font.setBold(true);
    scene->addText("Press optimaze to start",font);

    connect(scene, &MyGraph::mousePressed, this, &MainWindow::on_scene_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
}


void MainWindow::on_settingsBtn_clicked()
{
    settingPage.show();
}

void MainWindow::on_scene_clicked(const QPointF &pos)
{

        int plot_width = ui->graphicsView->width();
        int plot_height = ui->graphicsView->height();

        std::vector<double> min_point = {settingPage.xMin, settingPage.yMin};
        std::vector<double> max_point = {settingPage.xMax, settingPage.yMax};

        double grid_step_x = (max_point[0] - min_point[0]) / plot_width;
        double grid_step_y = (max_point[1] - min_point[1]) / plot_height;

        double x = min_point[0] + grid_step_x * pos.x();
        double y = max_point[1] - grid_step_y * pos.y();
        RectArea area(2, min_point, max_point);
        qDebug() << "x = " << x << "y = "<< y;
        std::vector<double> startPoint = {x, y};
        MainWindow::startOptimaze(startPoint);
}

void MainWindow::plot()
{
    AbstrFunction* f = nullptr;
    switch (settingPage.funcIndex) {
        case 0:
            f = new F1();
            break;
        case 1:
            f = new F2();
            break;
        case 2:
            f = new F3();
            break;
        default:
            f = new F1();
            break;
    }
    int size_rect = 2;

    int scene_width = ui->graphicsView->width();
    int scene_height = ui->graphicsView->height();

    int width = scene_width / size_rect;
    int height = scene_height / size_rect;

    std::vector<double> min_point = {settingPage.xMin, settingPage.yMin};
    std::vector<double> max_point = {settingPage.xMax, settingPage.yMax};

    double grid_step_x = (max_point[0] - min_point[0]) / width;
    double grid_step_y = (max_point[1] - min_point[1]) / height;

    double min_value = std::numeric_limits<double>::infinity(),
        max_value = -min_value;

    double value;
    std::vector<double>point(2);
    for (int i = 0; i <= width; ++i) {
        for (int j = 0; j <= height; ++j) {
            point[0] = min_point[0] + i * grid_step_x;
            point[1] = min_point[1] + j * grid_step_y;

            value = f->GetFuncValue(point);
            max_value = std::max(max_value, value);
            min_value = std::min(min_value, value);
        }
    }

    double max_value_trunc = std::min(max_value, min_value + 255);
    int blue, green;
    for (int i = 0; i <= width; ++i) {
        for (int j = 0; j <= height; ++j) {
            point[0] = min_point[0] + i * grid_step_x;
            point[1] = min_point[1] + j * grid_step_y;
            value = f->GetFuncValue(point);
            if (value < max_value_trunc) {
                blue = (value - min_value) / (max_value_trunc - min_value) * 255;
                green = 0;
            }
            else {
                double proportion = (max_value - value) / (max_value - max_value_trunc);
                blue = proportion * 255;
                green = (1 - proportion) * 255;
            }
            QPen pen(QColor(0, green, blue));
            QBrush brush(QColor(0, green, blue));
            scene->addRect(size_rect * i, scene_height - j * size_rect, size_rect, size_rect, pen, brush);
        }
    }

    ui->graphicsView->setScene(scene);
    delete f;
}

void MainWindow::plot_trajectory(MyGraph* scene)
{
    int plot_width = ui->graphicsView->width(),
        plot_height = ui->graphicsView->height();

    double area_width = settingPage.xMax - settingPage.xMin,
        area_height = settingPage.yMax - settingPage.yMin;

    QPen pen(QColor(255, 20, 147));
    for (size_t i = 1; i < trajectory.size(); ++i) {
        scene->addLine(
            (trajectory[i - 1][0] - settingPage.xMin) * plot_width / area_width,
            (settingPage.yMax - trajectory[i - 1][1]) * plot_height / area_height,
            (trajectory[i][0] - settingPage.xMin) * plot_width / area_width,
            (settingPage.yMax - trajectory[i][1]) * plot_height / area_height, pen
            );
    }
}

void MainWindow::startOptimaze(std::vector<double> startPoint){

    std::vector<double> lower_point{ settingPage.xMin, settingPage.yMin };
    std::vector<double> upper_point{ settingPage.xMax, settingPage.yMax };
    RectArea area(2, lower_point, upper_point);

    QString templateString = "[ %1 ; %2 ]";
    QString result = templateString.arg(startPoint[0]).arg(startPoint[1]);

    AbstrFunction* function = nullptr;
    switch (settingPage.funcIndex) {
        case 0:
            function = new F1();
            break;
        case 1:
            function = new F2();
            break;
        case 2:
            function = new F3();
            break;
        default:
            function = new F1();
            break;
    }

    AbstrOptimization* optimization = nullptr;
    if (settingPage.isGragient)
    {
        optimization = new GradientDescentOptimizer();
    }
    else
    {
        std::vector<double> delta = {settingPage.delta, settingPage.delta};
        optimization = new StochasticOptimizer(settingPage.alpha, settingPage.probability, delta);
    }


    AbstrStopCriteria* stop = nullptr;
    if(settingPage.isNumCriterion)

    {
        stop = new StopThroughIter();
    }
    else
    {
        stop = new StopByFunctionValue();
    }
    stop->SetMaximumIterations(settingPage.maxIter);
    stop->SetEpsilon(settingPage.eps);

    optimization->optimise(startPoint, function, stop, area);

    ui->startInput->setText(result);
    ui->iterInput->setText(QString::number(stop->GetCurrentIteration()));

    std::vector<double> find_point(stop->GetCurrentLocation());
    QString currentLocation = templateString.arg(find_point[0]).arg(find_point[1]);

    ui->approxInput->setText(currentLocation);
    ui->funcInput->setText(QString::number(function->GetFuncValue(find_point)));

    trajectory = optimization->points;

    scene->clear();
    MainWindow::plot();
    MainWindow::plot_trajectory(scene);

    qDebug() << optimization->points.size();

    delete function;
    delete stop;
    delete optimization;
}


void MainWindow::on_startBtn_clicked()
{
     std::vector<double> init_point{ settingPage.xStart, settingPage.yStart };
     MainWindow::startOptimaze(init_point);
     MainWindow::plot();
}

