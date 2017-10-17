#ifndef METASHOTPROFILECREATOR_H
#define METASHOTPROFILECREATOR_H

#include <QDialog>
#include <QList>

namespace Ui {
class MetaShotProfileCreator;
}

class MetaShotProfileCreator : public QDialog
{
    Q_OBJECT
private:
    QStringList m_uaList;

public:
    explicit MetaShotProfileCreator(QWidget *parent = 0);
    ~MetaShotProfileCreator();

private:
    void loadUAList();

public slots:
    void loadDataFromProfile(const QString &name);
    void saveProfile(const QString &path,bool isPath);

private slots:
    void on_saveButton_clicked();

    void on_imageOverlaySelect_clicked();

    void userAgentIndexChanged(int index);

    void on_previewButton_clicked();

    void on_overlayImageSize_valueChanged(int value);

    void on_comboBox_activated(int index);

    void on_comboBox_2_activated(int index);

    void on_pushButton_clicked();

private:
    Ui::MetaShotProfileCreator *ui;
};

#endif // METASHOTPROFILECREATOR_H
