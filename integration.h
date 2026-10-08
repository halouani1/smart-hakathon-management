#ifndef INTEGRATION_H
#define INTEGRATION_H

#include <QMainWindow>
#include <QRandomGenerator>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui {
class integration;
}
QT_END_NAMESPACE

class integration : public QMainWindow
{
    Q_OBJECT

public:
    explicit integration(QWidget *parent = nullptr);
    ~integration() override;

private slots:
    void allerPage(int index);
    void goLogin();
    void goSalles();

    void onConnexion();
    void onCGU();
    void onPolitique();
    void onAPropos();
    void onNotifications();
    void onProfil();
    void onDeconnexion();

    void onSuggererSalle();   // Affectation intelligente
    void onValiderQR();       // QR Code

private:
    Ui::integration *ui;

    void appliquerTheme();
    void connecterLogin();
    void connecterNavigation();
    void connecterActions();
    void remplirTableSalles();
    void dessinerStatistiques();
};

#endif // INTEGRATION_H