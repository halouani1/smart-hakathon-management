#ifndef GESTION_EVALUATEURS_H
#define GESTION_EVALUATEURS_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class GestionEvaluateurs; }
QT_END_NAMESPACE

class GestionEvaluateurs : public QMainWindow
{
    Q_OBJECT

public:
    explicit GestionEvaluateurs(QWidget *parent = nullptr);
    ~GestionEvaluateurs();

private slots:
    void ajouterOuModifier();
    void annulerFormulaire();
    void rechercherEvaluateur();
    void trierEvaluateurs();
    void exporterEvaluateurs();
    void modifierEvaluateur();
    void supprimerEvaluateur();
    void ouvrirTechChallengeAnalyst();
    void ouvrirDeliberationJury();

private:
    Ui::GestionEvaluateurs *ui;
    int editingRow = -1;

    void chargerDonneesExemple();
    void actualiserCompteurs();
    void ajouterBoutonsAction(int row);
    void remplirFormulaireDepuisLigne(int row);
    bool lireFormulaire(QString &id, QString &nom, QString &prenom,
                        int &score, QString &statut) const;
};

#endif
