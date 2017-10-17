#ifndef LICENSEVALIDATOR_H
#define LICENSEVALIDATOR_H

#include <QWidget>

#include "licenseengine.h"
#include "leadbankpromainwindow.h"

namespace Ui {
class LicenseValidator;
}

class LicenseValidator : public QWidget
{
    Q_OBJECT
    LicenseEngine m_lEngine;
    LeadBankProMainWindow m_window;
    QString m_lText;

public:
    explicit LicenseValidator(QWidget *parent = 0);
    ~LicenseValidator();

private:
    Ui::LicenseValidator *ui;

private slots:
    void valid();
    void invalid();
    void on_validateButton_clicked();
};

#endif // LICENSEVALIDATOR_H
