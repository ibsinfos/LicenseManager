#ifndef PREVIEWDIALOG_H
#define PREVIEWDIALOG_H

#include <QString>
#include <QEvent>
#include <QDialog>
#include <QPaintEvent>
#include <QPixmap>

#include "metashot.h"
#include "pjsobject.h"

namespace Ui {
class PreviewDialog;
}

class PreviewDialog : public QDialog
{
    Q_OBJECT
private:
    bool m_draw;
    QPixmap m_pix;
    PJSObject *m_pjs;
    bool m_finished;
public:
    explicit PreviewDialog(QWidget *parent = 0);
    ~PreviewDialog();
    void setImage(const QString &pix);
    void setPixMap(const QPixmap &pix);

    void setOverlayImageSize(int val);
    int overlayImageSize();
    void setPreviewUrl(const QString &url);

    void load();

protected:
    void paintEvent(QPaintEvent *e);
    bool eventFilter(QObject* watched, QEvent* event);

private slots:
    void on_goButton_clicked();
    void pjsMessage(int index,const QString &message);

    void on_overlaySlider_valueChanged(int value);

    void on_Save_clicked();

private:
    Ui::PreviewDialog *ui;
};

#endif // PREVIEWDIALOG_H
