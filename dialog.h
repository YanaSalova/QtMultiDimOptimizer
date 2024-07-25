#ifndef DIALOG_H
#define DIALOG_H
#include <QDialog>
#include <QListWidgetItem>
#include "AbstrFunction.h"
#include "AbstrStopCriteria.h"
#include "StopThroughIter.h"
#include "F1.h"
#include "F2.h"
#include "F3.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

    bool isGragient = true;
    bool isNumCriterion = true;
    int maxIter = 100;
    double eps = 0.001;
    double delta = 0;
    double alpha = 0;
    double probability = 0;
    double xMin = -10;
    double xMax = 10;
    double yMin = -10;
    double yMax = 10;
    double xStart = 2;
    double yStart = 2;
    int funcIndex = 0;

private slots:
    void on_gradient_clicked();

    void on_random_clicked();

    void on_numCriterion_clicked();

    void on_absCriterion_clicked();

    void on_funcList_itemClicked();

    void on_maxIterationLineEdit_textChanged(const QString &arg1);

    void on_precisionLineEdit_textChanged(const QString &arg1);

    void on_deltaLineEdit_textChanged(const QString &arg1);

    void on_alphaLineEdit_textChanged(const QString &arg1);

    void on_probabilityLineEdit_textChanged(const QString &arg1);

    void on_xminLineEdit_textChanged(const QString &arg1);

    void on_xmaxLineEdit_textChanged(const QString &arg1);

    void on_yminLineEdit_textChanged(const QString &arg1);

    void on_ymaxLineEdit_textChanged(const QString &arg1);

    void on_xLineEdit_textChanged(const QString &arg1);

    void on_yLineEdit_textChanged(const QString &arg1);

    void on_pushButton_clicked();

    bool check_values();


private:
    Ui::Dialog *ui;

protected:
    void closeEvent(QCloseEvent *event) override;
};



#endif // DIALOG_H
