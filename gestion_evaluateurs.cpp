#include "gestion_evaluateurs.h"
#include "ui_GestionEvaluateurs.h"

#include <QAction>
#include <QCursor>
#include <QFile>
#include <QFileDialog>
#include <QHeaderView>
#include <QMenu>
#include <QMessageBox>
#include <QPushButton>
#include <QTableWidgetItem>
#include <QTextStream>
#include <QDialog>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QGroupBox>
#include <QComboBox>
#include <QSpinBox>
#include <QTableWidget>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QAbstractItemView>
#include <QIntValidator>

GestionEvaluateurs::GestionEvaluateurs(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::GestionEvaluateurs)
{
    ui->setupUi(this);
    ui->resultatEdit->setValidator(new QIntValidator(0, 20, ui->resultatEdit));
    ui->resultatEdit->setMaxLength(2);

    setWindowTitle("Smart Hackathon Management - Gestion des évaluateurs");

    // IMPORTANT :
    // Le tableau est volontairement vide dans le fichier .ui.
    // Toutes les lignes sont créées ici après setupUi().
    // Cela évite le crash SIGSEGV observé dans QTableWidgetItem::setText()
    // pendant setupUi().

    ui->evaluateursTable->setColumnCount(6);
    ui->evaluateursTable->setHorizontalHeaderLabels(
        QStringList() << "ID évaluateur"
                      << "Nom"
                      << "Prénom"
                      << "Résultat"
                      << "Statut"
                      << "Action");

    QHeaderView *header = ui->evaluateursTable->horizontalHeader();
    for (int col = 0; col < 5; ++col)
        header->setSectionResizeMode(col, QHeaderView::Stretch);
    header->setSectionResizeMode(5, QHeaderView::Fixed);
    ui->evaluateursTable->setColumnWidth(5, 190);

    // Force Exporter to green so the global Qt button style cannot make it blue.
    ui->exporterButton->setStyleSheet(
        "QPushButton { background-color:#198754; color:white; border:none; "
        "border-radius:7px; padding:10px 18px; font-weight:700; }"
        "QPushButton:hover { background-color:#157347; }"
        "QPushButton:pressed { background-color:#146C43; }");
    ui->evaluateursTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->evaluateursTable->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->evaluateursTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    connect(ui->ajouterButton, &QPushButton::clicked,
            this, &GestionEvaluateurs::ajouterOuModifier);

    connect(ui->annulerButton, &QPushButton::clicked,
            this, &GestionEvaluateurs::annulerFormulaire);

    connect(ui->rechercherButton, &QPushButton::clicked,
            this, &GestionEvaluateurs::rechercherEvaluateur);

    connect(ui->trierButton, &QPushButton::clicked,
            this, &GestionEvaluateurs::trierEvaluateurs);

    connect(ui->exporterButton, &QPushButton::clicked,
            this, &GestionEvaluateurs::exporterEvaluateurs);

    // Les deux métiers sont de vrais boutons dans le pied de page.
    connect(ui->business1, &QPushButton::clicked,
            this, &GestionEvaluateurs::ouvrirTechChallengeAnalyst);
    connect(ui->business2, &QPushButton::clicked,
            this, &GestionEvaluateurs::ouvrirDeliberationJury);

    connect(ui->evaluateursTable, &QTableWidget::cellDoubleClicked,
            this, [this](int row, int) {
                ui->evaluateursTable->selectRow(row);
                modifierEvaluateur();
            });

    chargerDonneesExemple();
    actualiserCompteurs();
}

GestionEvaluateurs::~GestionEvaluateurs()
{
    delete ui;
}

void GestionEvaluateurs::chargerDonneesExemple()
{
    const QStringList ids =
        {"E001", "E002", "E003", "E004", "E005", "E006"};

    const QStringList noms =
        {"Ben Salah", "Trabelsi", "Gharbi", "Ayari", "Jaziri", "Chaabane"};

    const QStringList prenoms =
        {"Amine", "Sara", "Yassine", "Hiba", "Malek", "Omar"};

    const QList<int> scores = {18, 17, 15, 19, 16, 12};

    const QStringList statuts =
        {"Actif", "Actif", "Inactif", "Actif", "Actif", "Inactif"};

    ui->evaluateursTable->setRowCount(0);

    for (int i = 0; i < ids.size(); ++i) {
        const int row = ui->evaluateursTable->rowCount();
        ui->evaluateursTable->insertRow(row);

        ui->evaluateursTable->setItem(row, 0, new QTableWidgetItem(ids.at(i)));
        ui->evaluateursTable->setItem(row, 1, new QTableWidgetItem(noms.at(i)));
        ui->evaluateursTable->setItem(row, 2, new QTableWidgetItem(prenoms.at(i)));
        ui->evaluateursTable->setItem(row, 3,
                                      new QTableWidgetItem(QString::number(scores.at(i))));
        ui->evaluateursTable->setItem(row, 4, new QTableWidgetItem(statuts.at(i)));
        ajouterBoutonsAction(row);
    }
}

void GestionEvaluateurs::ajouterBoutonsAction(int row)
{
    auto *container = new QWidget(ui->evaluateursTable);
    auto *layout = new QHBoxLayout(container);
    layout->setContentsMargins(4, 3, 4, 3);
    layout->setSpacing(5);
    layout->setAlignment(Qt::AlignCenter);

    auto *modifier = new QPushButton("Modifier", container);
    auto *supprimer = new QPushButton("Supprimer", container);

    modifier->setFixedSize(80, 30);
    supprimer->setFixedSize(80, 30);

    modifier->setStyleSheet(
        "QPushButton { background-color:#198754; color:white; border:none; "
        "border-radius:5px; padding:3px 5px; font-weight:700; }"
        "QPushButton:hover { background-color:#157347; }");
    supprimer->setStyleSheet(
        "QPushButton { background-color:#DC3545; color:white; border:none; "
        "border-radius:5px; padding:3px 5px; font-weight:700; }"
        "QPushButton:hover { background-color:#BB2D3B; }");

    layout->addWidget(modifier);
    layout->addWidget(supprimer);
    ui->evaluateursTable->setCellWidget(row, 5, container);

    connect(modifier, &QPushButton::clicked, this, [this, modifier]() {
        const QPoint pos = modifier->mapTo(ui->evaluateursTable, QPoint(2, 2));
        const int currentRow = ui->evaluateursTable->indexAt(pos).row();
        if (currentRow >= 0) {
            ui->evaluateursTable->selectRow(currentRow);
            remplirFormulaireDepuisLigne(currentRow);
        }
    });

    connect(supprimer, &QPushButton::clicked, this, [this, supprimer]() {
        const QPoint pos = supprimer->mapTo(ui->evaluateursTable, QPoint(2, 2));
        const int currentRow = ui->evaluateursTable->indexAt(pos).row();
        if (currentRow >= 0) {
            ui->evaluateursTable->selectRow(currentRow);
            supprimerEvaluateur();
        }
    });
}

bool GestionEvaluateurs::lireFormulaire(QString &id, QString &nom,
                                        QString &prenom, int &score,
                                        QString &statut) const
{
    id = ui->idEvaluateurEdit->text().trimmed();
    nom = ui->nomEdit->text().trimmed();
    prenom = ui->prenomEdit->text().trimmed();
    const QString resultat = ui->resultatEdit->text().trimmed();
    statut = ui->statutCombo->currentText();

    if (id.isEmpty() || nom.isEmpty() || prenom.isEmpty() ||
        resultat.isEmpty() || statut == QStringLiteral("Sélectionner un statut"))
        return false;

    bool ok = false;
    score = resultat.toInt(&ok);

    return ok && score >= 0 && score <= 20;
}

void GestionEvaluateurs::ajouterOuModifier()
{
    QString id, nom, prenom, statut;
    int score = 0;

    if (!lireFormulaire(id, nom, prenom, score, statut)) {
        QMessageBox::warning(
            this,
            "Informations invalides",
            "Veuillez remplir tous les champs.\n"
            "Le résultat doit être compris entre 0 et 20.");
        return;
    }

    // Vérification de l'ID uniquement contre les autres lignes.
    for (int row = 0; row < ui->evaluateursTable->rowCount(); ++row) {
        if (row == editingRow)
            continue;

        QTableWidgetItem *item = ui->evaluateursTable->item(row, 0);
        if (item && item->text().compare(id, Qt::CaseInsensitive) == 0) {
            QMessageBox::warning(this, "ID existant",
                                 "Cet ID évaluateur existe déjà.");
            return;
        }
    }

    if (editingRow >= 0 && editingRow < ui->evaluateursTable->rowCount()) {
        ui->evaluateursTable->item(editingRow, 0)->setText(id);
        ui->evaluateursTable->item(editingRow, 1)->setText(nom);
        ui->evaluateursTable->item(editingRow, 2)->setText(prenom);
        ui->evaluateursTable->item(editingRow, 3)->setText(QString::number(score));
        ui->evaluateursTable->item(editingRow, 4)->setText(statut);

        QMessageBox::information(this, "Modification",
                                 "Évaluateur modifié avec succès.");
    } else {
        const int row = ui->evaluateursTable->rowCount();
        ui->evaluateursTable->insertRow(row);

        ui->evaluateursTable->setItem(row, 0, new QTableWidgetItem(id));
        ui->evaluateursTable->setItem(row, 1, new QTableWidgetItem(nom));
        ui->evaluateursTable->setItem(row, 2, new QTableWidgetItem(prenom));
        ui->evaluateursTable->setItem(row, 3,
                                      new QTableWidgetItem(QString::number(score)));
        ui->evaluateursTable->setItem(row, 4, new QTableWidgetItem(statut));
        ajouterBoutonsAction(row);

        QMessageBox::information(this, "Ajout",
                                 "Évaluateur ajouté avec succès.");
    }

    annulerFormulaire();
    actualiserCompteurs();
}

void GestionEvaluateurs::annulerFormulaire()
{
    editingRow = -1;
    ui->idEvaluateurEdit->clear();
    ui->nomEdit->clear();
    ui->prenomEdit->clear();
    ui->resultatEdit->clear();
    ui->statutCombo->setCurrentIndex(0);
    ui->ajouterButton->setText("Ajouter");
}

void GestionEvaluateurs::remplirFormulaireDepuisLigne(int row)
{
    if (row < 0 || row >= ui->evaluateursTable->rowCount())
        return;

    editingRow = row;

    ui->idEvaluateurEdit->setText(ui->evaluateursTable->item(row, 0)->text());
    ui->nomEdit->setText(ui->evaluateursTable->item(row, 1)->text());
    ui->prenomEdit->setText(ui->evaluateursTable->item(row, 2)->text());
    ui->resultatEdit->setText(ui->evaluateursTable->item(row, 3)->text());
    ui->statutCombo->setCurrentText(ui->evaluateursTable->item(row, 4)->text());
    ui->ajouterButton->setText("Enregistrer");
}

void GestionEvaluateurs::modifierEvaluateur()
{
    const int row = ui->evaluateursTable->currentRow();

    if (row < 0) {
        QMessageBox::information(this, "Modifier",
                                 "Sélectionnez un évaluateur.");
        return;
    }

    remplirFormulaireDepuisLigne(row);
}

void GestionEvaluateurs::supprimerEvaluateur()
{
    const int row = ui->evaluateursTable->currentRow();

    if (row < 0) {
        QMessageBox::information(this, "Supprimer",
                                 "Sélectionnez un évaluateur.");
        return;
    }

    const QString nom = ui->evaluateursTable->item(row, 1)->text();

    if (QMessageBox::question(
            this,
            "Confirmation",
            "Supprimer l'évaluateur " + nom + " ?")
        == QMessageBox::Yes) {

        ui->evaluateursTable->removeRow(row);

        if (editingRow == row)
            annulerFormulaire();
        else if (editingRow > row)
            --editingRow;

        actualiserCompteurs();
    }
}

void GestionEvaluateurs::rechercherEvaluateur()
{
    const QString recherche = ui->rechercheEdit->text().trimmed();

    for (int row = 0; row < ui->evaluateursTable->rowCount(); ++row) {
        bool visible = recherche.isEmpty();

        if (!visible) {
            for (int col = 0; col < 5; ++col) {
                QTableWidgetItem *item = ui->evaluateursTable->item(row, col);

                if (item && item->text().contains(recherche, Qt::CaseInsensitive)) {
                    visible = true;
                    break;
                }
            }
        }

        ui->evaluateursTable->setRowHidden(row, !visible);
    }
}

void GestionEvaluateurs::trierEvaluateurs()
{
    ui->evaluateursTable->setSortingEnabled(true);
    ui->evaluateursTable->sortItems(3, Qt::DescendingOrder);
    ui->evaluateursTable->setSortingEnabled(false);
}

void GestionEvaluateurs::exporterEvaluateurs()
{
    const QString fileName = QFileDialog::getSaveFileName(
        this,
        "Exporter les évaluateurs",
        "evaluateurs.csv",
        "Fichiers CSV (*.csv)");

    if (fileName.isEmpty())
        return;

    QFile file(fileName);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Erreur",
                              "Impossible de créer le fichier.");
        return;
    }

    QTextStream out(&file);
    out << "ID évaluateur;Nom;Prénom;Résultat;Statut\n";

    for (int row = 0; row < ui->evaluateursTable->rowCount(); ++row) {
        if (ui->evaluateursTable->isRowHidden(row))
            continue;

        for (int col = 0; col < 5; ++col) {
            if (col > 0)
                out << ";";

            QTableWidgetItem *item = ui->evaluateursTable->item(row, col);

            if (item)
                out << item->text();
        }

        out << "\n";
    }

    file.close();

    QMessageBox::information(this, "Export",
                             "Export CSV terminé avec succès.");
}

void GestionEvaluateurs::actualiserCompteurs()
{
    int actifs = 0;
    int inactifs = 0;
    int somme = 0;
    int scores = 0;

    for (int row = 0; row < ui->evaluateursTable->rowCount(); ++row) {
        QTableWidgetItem *statut = ui->evaluateursTable->item(row, 4);
        QTableWidgetItem *score = ui->evaluateursTable->item(row, 3);

        if (statut && statut->text() == "Actif")
            ++actifs;
        else
            ++inactifs;

        if (score) {
            bool ok = false;
            const int value = score->text().toInt(&ok);

            if (ok) {
                somme += value;
                ++scores;
            }
        }
    }

    ui->metricTotal->setText(QString::number(ui->evaluateursTable->rowCount()));
    ui->metricActive->setText(QString::number(actifs));
    ui->metricInactive->setText(QString::number(inactifs));
    const int total = ui->evaluateursTable->rowCount();
    const int actifsPct = total > 0 ? (actifs * 100 / total) : 0;
    const int inactifsPct = total > 0 ? (inactifs * 100 / total) : 0;
    ui->metricRepartitionActive->setText(QString("● Actifs : %1%").arg(actifsPct));
    ui->metricRepartitionInactive->setText(QString("● Inactifs : %1%").arg(inactifsPct));
}


void GestionEvaluateurs::ouvrirTechChallengeAnalyst()
{
    QDialog dialog(this);
    dialog.setWindowTitle("Métier 1 — Tech Challenge Analyst");
    dialog.resize(850, 520);

    auto *layout = new QVBoxLayout(&dialog);

    auto *title = new QLabel("Tech Challenge Analyst — Analyse des candidats");
    title->setStyleSheet("font-size:20px;font-weight:700;color:#173A70;");
    layout->addWidget(title);

    auto *info = new QLabel(
        "Analysez les candidats selon leur score, leur compatibilité avec le challenge "
        "et leur recommandation. Les données sont un exemple fonctionnel.");
    info->setWordWrap(true);
    layout->addWidget(info);

    auto *table = new QTableWidget(4, 5);
    table->setHorizontalHeaderLabels({"Candidat", "Projet", "Score", "Compatibilité", "Recommandation"});
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    table->setSelectionBehavior(QAbstractItemView::SelectRows);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);

    const QStringList candidats = {"Amine Ben Salah", "Sara Trabelsi", "Hiba Ayari", "Malek Jaziri"};
    const QStringList projets = {"Smart Campus", "Green City", "Health AI", "FinTech Junior"};
    const QList<int> scores = {18, 17, 19, 16};
    const QStringList compat = {"95 %", "88 %", "91 %", "79 %"};

    for (int i = 0; i < candidats.size(); ++i) {
        table->setItem(i, 0, new QTableWidgetItem(candidats.at(i)));
        table->setItem(i, 1, new QTableWidgetItem(projets.at(i)));
        table->setItem(i, 2, new QTableWidgetItem(QString::number(scores.at(i))));
        table->setItem(i, 3, new QTableWidgetItem(compat.at(i)));
        table->setItem(i, 4, new QTableWidgetItem(i < 3 ? "Recommandé" : "À examiner"));
    }
    layout->addWidget(table);

    auto *result = new QLabel("Sélectionnez un candidat puis cliquez sur Analyser.");
    result->setStyleSheet("background:#F3F7FF;padding:10px;border-radius:6px;font-weight:600;");
    layout->addWidget(result);

    auto *buttons = new QHBoxLayout();
    auto *analyser = new QPushButton("Analyser le candidat");
    analyser->setStyleSheet("background:#1F65D6;color:white;padding:9px 16px;border-radius:6px;font-weight:700;");
    auto *fermer = new QPushButton("Fermer");
    buttons->addStretch();
    buttons->addWidget(analyser);
    buttons->addWidget(fermer);
    layout->addLayout(buttons);

    connect(analyser, &QPushButton::clicked, &dialog, [table, result]() {
        const int row = table->currentRow();
        if (row < 0) {
            result->setText("Sélectionnez d'abord un candidat.");
            return;
        }
        const QString nom = table->item(row, 0)->text();
        const QString projet = table->item(row, 1)->text();
        const QString scoreText = table->item(row, 2)->text();
        bool ok = false;
        const int score = scoreText.toInt(&ok);

        // Le score du Métier 1 est strictement limité à 20/20.
        if (!ok || score < 0 || score > 20) {
            result->setText("Score invalide : le score doit être compris entre 0/20 et 20/20.");
            return;
        }

        const QString compatibilite = table->item(row, 3)->text();
        result->setText("Analyse : " + nom + " — projet " + projet +
                        " | Score " + QString::number(score) + "/20 | Compatibilité " + compatibilite +
                        " | Recommandation : " + table->item(row, 4)->text());
    });

    connect(fermer, &QPushButton::clicked, &dialog, &QDialog::accept);
    dialog.exec();
}

void GestionEvaluateurs::ouvrirDeliberationJury()
{
    QDialog dialog(this);
    dialog.setWindowTitle("Métier 2 — Délibération collaborative du jury");
    dialog.resize(900, 570);

    auto *layout = new QVBoxLayout(&dialog);

    auto *title = new QLabel("Délibération collaborative du jury");
    title->setStyleSheet("font-size:20px;font-weight:700;color:#16804E;");
    layout->addWidget(title);

    auto *info = new QLabel(
        "Chaque membre du jury peut voter. Le système calcule automatiquement le consensus "
        "et affiche la décision finale pour chaque candidat.");
    info->setWordWrap(true);
    layout->addWidget(info);

    auto *juryBox = new QGroupBox("Nouveau vote");
    auto *juryLayout = new QHBoxLayout(juryBox);

    auto *evaluateur = new QComboBox();
    for (int row = 0; row < ui->evaluateursTable->rowCount(); ++row) {
        if (!ui->evaluateursTable->item(row, 0) || !ui->evaluateursTable->item(row, 1))
            continue;
        evaluateur->addItem(ui->evaluateursTable->item(row, 0)->text() + " — " +
                            ui->evaluateursTable->item(row, 1)->text());
    }

    auto *candidat = new QComboBox();
    candidat->addItems({"Smart Campus", "Green City", "Health AI", "FinTech Junior"});

    auto *vote = new QComboBox();
    vote->addItems({"Pour", "Neutre", "Contre"});

    auto *voter = new QPushButton("Enregistrer le vote");
    voter->setStyleSheet("background:#16804E;color:white;padding:8px 12px;border-radius:6px;font-weight:700;");

    juryLayout->addWidget(new QLabel("Évaluateur :"));
    juryLayout->addWidget(evaluateur);
    juryLayout->addWidget(new QLabel("Candidat :"));
    juryLayout->addWidget(candidat);
    juryLayout->addWidget(new QLabel("Vote :"));
    juryLayout->addWidget(vote);
    juryLayout->addWidget(voter);
    layout->addWidget(juryBox);

    auto *table = new QTableWidget(4, 5);
    table->setHorizontalHeaderLabels({"Candidat", "Pour", "Neutre", "Contre", "Décision"});
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table->setSelectionBehavior(QAbstractItemView::SelectRows);

    const QStringList candidats = {"Smart Campus", "Green City", "Health AI", "FinTech Junior"};
    for (int i = 0; i < candidats.size(); ++i) {
        table->setItem(i, 0, new QTableWidgetItem(candidats.at(i)));
        table->setItem(i, 1, new QTableWidgetItem("0"));
        table->setItem(i, 2, new QTableWidgetItem("0"));
        table->setItem(i, 3, new QTableWidgetItem("0"));
        table->setItem(i, 4, new QTableWidgetItem("En attente"));
    }
    layout->addWidget(table);

    auto *consensus = new QLabel("Consensus : aucun vote enregistré.");
    consensus->setStyleSheet("background:#E7F7EF;color:#126B43;padding:10px;border-radius:6px;font-weight:700;");
    layout->addWidget(consensus);

    auto *bottom = new QHBoxLayout();
    auto *reset = new QPushButton("Réinitialiser les votes");
    auto *fermer = new QPushButton("Fermer");
    bottom->addStretch();
    bottom->addWidget(reset);
    bottom->addWidget(fermer);
    layout->addLayout(bottom);

    auto updateConsensus = [table, consensus]() {
        int totalVotes = 0;
        int totalPour = 0;
        int totalContre = 0;
        int decisions = 0;

        for (int row = 0; row < table->rowCount(); ++row) {
            const int pour = table->item(row, 1)->text().toInt();
            const int neutre = table->item(row, 2)->text().toInt();
            const int contre = table->item(row, 3)->text().toInt();
            totalVotes += pour + neutre + contre;
            totalPour += pour;
            totalContre += contre;

            QString decision = "En attente";
            if (pour + neutre + contre > 0) {
                if (pour > contre)
                    decision = "Validé";
                else if (contre > pour)
                    decision = "Refusé";
                else
                    decision = "À départager";
            }
            table->item(row, 4)->setText(decision);
            if (decision == "Validé")
                ++decisions;
        }

        if (totalVotes == 0) {
            consensus->setText("Consensus : aucun vote enregistré.");
        } else {
            consensus->setText(QString("Consensus du jury : %1 vote(s), %2 pour, %3 contre — %4 candidat(s) validé(s).")
                               .arg(totalVotes).arg(totalPour).arg(totalContre).arg(decisions));
        }
    };

    connect(voter, &QPushButton::clicked, &dialog, [=]() mutable {
        const int row = candidats.indexOf(candidat->currentText());
        if (row < 0)
            return;

        int col = 1;
        if (vote->currentText() == "Neutre")
            col = 2;
        else if (vote->currentText() == "Contre")
            col = 3;

        const int value = table->item(row, col)->text().toInt();
        table->item(row, col)->setText(QString::number(value + 1));
        updateConsensus();
    });

    connect(reset, &QPushButton::clicked, &dialog, [table, updateConsensus]() mutable {
        for (int row = 0; row < table->rowCount(); ++row) {
            table->item(row, 1)->setText("0");
            table->item(row, 2)->setText("0");
            table->item(row, 3)->setText("0");
            table->item(row, 4)->setText("En attente");
        }
        updateConsensus();
    });

    connect(fermer, &QPushButton::clicked, &dialog, &QDialog::accept);
    dialog.exec();
}
