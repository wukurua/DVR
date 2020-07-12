#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QIcon>
#include <QDesktopWidget>
#include <QApplication>
#include <QPushButton>
#include <QToolButton>
#include <QLabel>
#include <QLineEdit>
#include <QMouseEvent>
#include <QKeyEvent>
#include <QBitmap>
#include <QPainter>
#include <QAction>
#include <QComboBox>
#include <QCheckBox>
#include <QFileDialog>
#include <QMessageBox>

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = nullptr);
    QPushButton *btnClose;
    QPushButton *btnMinimize;
protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
private:
    bool isMousePress;
    //the start position of mouse
    QPoint mouseStartPoint;
    //the start position of window
    QPoint windowTopLeftPoint;
    QLabel *lblBar;

public slots:
    void minisizeWindow();
    void closeWindow();
};
#endif // WIDGET_H
