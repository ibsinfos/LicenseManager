#ifndef MOCKPAGEPREVIEW_H
#define MOCKPAGEPREVIEW_H

#include <QDialog>

namespace Ui {
class MockPagePreview;
}

class MockPagePreview : public QDialog
{
    Q_OBJECT

public:
    explicit MockPagePreview(QWidget *parent = 0);
    ~MockPagePreview();

    void setPreviewImage(const QString &path);

private:
    Ui::MockPagePreview *ui;
};

#endif // MOCKPAGEPREVIEW_H
