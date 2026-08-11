#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget() override;
    void getTask();
    // void showcaseTask(vector );
    void exit();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
