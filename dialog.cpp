#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>
#include <QWidget>
#include <QCloseEvent>
#include "AbstrFunction.h"
#include "F1.h"
#include "F2.h"
#include "F3.h"
#include "StopByFunctionValue.h"
#include "StopThroughIter.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->gradient->setChecked(isGragient);
    ui->numCriterion->setChecked(isNumCriterion);
    ui->maxIterationLineEdit->setText(QString::number(maxIter));
    ui->precisionLineEdit->setText(QString::number(eps));
    ui->deltaLineEdit->setText(QString::number(delta));
    ui->alphaLineEdit->setText(QString::number(alpha));
    ui->probabilityLineEdit->setText(QString::number(probability));
    ui->xminLineEdit->setText(QString::number(xMin));
    ui->xmaxLineEdit->setText(QString::number(xMax));
    ui->yminLineEdit->setText(QString::number(yMin));
    ui->ymaxLineEdit->setText(QString::number(yMax));
    ui->xLineEdit->setText(QString::number(xStart));
    ui->yLineEdit->setText(QString::number(yStart));
    ui->randomForm_2->hide();
    ui->funcList->setCurrentRow(funcIndex);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_gradient_clicked()
{
    isGragient = true;
    ui->randomForm_2->hide();
}


void Dialog::on_random_clicked()
{
    isGragient = false;
    ui->randomForm_2->show();
}


void Dialog::on_numCriterion_clicked()
{
    isNumCriterion = true;
}


void Dialog::on_absCriterion_clicked()
{
    isNumCriterion = false;
}


void Dialog::on_funcList_itemClicked()
{
    funcIndex = ui->funcList->currentIndex().row();
}

bool Dialog::check_values()
{
    std::string warnings = "";

    if (maxIter <= 0 || maxIter > 1000000)
        warnings += "Max number of iterations must be > 0 and <= 1000000.\n";

    if (eps <= 0)
        warnings += "Precision must be > 0.\n";
    if (!isGragient)
    {
        if ((alpha <= 0 || alpha > 1))
            warnings += "Alpha must be > 0 and <= 1.\n";

        if (delta <= 0)
            warnings += "Delta must be > 0.\n";

        if (probability <= 0 || probability > 1)
            warnings += "Probability must be > 0 and <= 1.\n";
    }

    if (warnings == "")
    {
        return true;
    }
    else
    {
        QMessageBox::warning(this, "Warning!", warnings.c_str());
        return false;
    }
}

void Dialog::closeEvent(QCloseEvent *event){
    if(check_values())
        QWidget::closeEvent(event);
    else
        event->ignore();
}

void Dialog::on_maxIterationLineEdit_textChanged(const QString &arg1) { maxIter = arg1.toUInt(); }


void Dialog::on_precisionLineEdit_textChanged(const QString &arg1) { eps = arg1.toDouble(); }


void Dialog::on_deltaLineEdit_textChanged(const QString &arg1) { delta = arg1.toDouble(); }


void Dialog::on_alphaLineEdit_textChanged(const QString &arg1) { alpha = arg1.toDouble(); }


void Dialog::on_probabilityLineEdit_textChanged(const QString &arg1) { probability = arg1.toDouble(); }


void Dialog::on_xminLineEdit_textChanged(const QString &arg1) { xMin = arg1.toDouble(); }


void Dialog::on_xmaxLineEdit_textChanged(const QString &arg1) { xMax = arg1.toDouble(); }


void Dialog::on_yminLineEdit_textChanged(const QString &arg1) { yMin = arg1.toDouble(); }


void Dialog::on_ymaxLineEdit_textChanged(const QString &arg1) { yMax = arg1.toDouble(); }


void Dialog::on_xLineEdit_textChanged(const QString &arg1){ xStart = arg1.toDouble(); }


void Dialog::on_yLineEdit_textChanged(const QString &arg1) { yStart = arg1.toDouble(); }


void Dialog::on_pushButton_clicked()
{
    bool check = check_values();
    if(check)
        close();
}


