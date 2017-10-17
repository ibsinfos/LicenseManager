#ifndef TARGETFOLDER_H
#define TARGETFOLDER_H

#include <QWidget>

namespace Ui {
class TargetFolder;
}

class TargetFolder : public QWidget
{
    Q_OBJECT

public:
    explicit TargetFolder(QWidget *parent = 0);
    ~TargetFolder();

    QString getTargetPath();

private slots:
    void on_browseButton_clicked();

private:
    Ui::TargetFolder *ui;
};

#endif // TARGETFOLDER_H
