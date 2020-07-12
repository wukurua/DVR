#ifndef DAILOG_H
#define DAILOG_H

#include <QDialog>
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

class Dialog : public QDialog
{
    Q_OBJECT
public:
    explicit Dialog(QDialog *parent = nullptr);
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
    QPushButton *btnClose;
    QPushButton *btnMinimize;
public slots:
    void minisizeWindow();
    void closeWindow();
};

#endif // DAILOG_H
