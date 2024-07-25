QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AbstrFunction.cpp \
    AbstrOptimization.cpp \
    AbstrStopCriteria.cpp \
    F1.cpp \
    F2.cpp \
    F3.cpp \
    GradientDescentOptimizer.cpp \
    MyGraph.cpp \
    RectArea.cpp \
    StochasticOptimizer.cpp \
    StopByFunctionValue.cpp \
    StopByGradVal.cpp \
    StopByPoint.cpp \
    StopThroughIter.cpp \
    VectorOperations.cpp \
    dialog.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    AbstrFunction.h \
    AbstrOptimization.h \
    AbstrStopCriteria.h \
    F1.h \
    F2.h \
    F3.h \
    GradientDescentOptimizer.h \
    MyGraph.h \
    RectArea.h \
    StochasticOptimizer.h \
    StopByFunctionValue.h \
    StopByGradVal.h \
    StopByPoint.h \
    StopThroughIter.h \
    VectorOperations.h \
    dialog.h \
    mainwindow.h

FORMS += \
    dialog.ui \
    mainwindow.ui

CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
