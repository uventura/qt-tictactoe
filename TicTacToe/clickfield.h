#ifndef CLICKFIELD_H
#define CLICKFIELD_H

#include <QWidget>
#include <QPushButton>
#include <QSizePolicy>
#include <QString>

#include <QDebug>

class ClickField: public QPushButton
{
    Q_OBJECT

public:
    ClickField(QWidget* parent = nullptr);
    virtual ~ClickField(){};

    void setTextField(QString text);
    void setChangedValue(QString* value);
    void setIndex(int index);

    QString getValue();

signals:
    void pressedButtonField();

public slots:
    void changeValue();

private:
    QString* m_value;
    QString m_currentValue;
    int m_index;
};

#endif // CLICKFIELD_H
