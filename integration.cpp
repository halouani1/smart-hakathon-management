#include "integration.h"
#include "ui_integration.h"

#include <QPushButton>
#include <QStackedWidget>
#include <QMessageBox>
#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QTextBrowser>
#include <QScrollArea>
#include <QScrollBar>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QHeaderView>
#include <QLineEdit>
#include <QComboBox>
#include <QSpinBox>
#include <QFrame>
#include <QColor>
#include <QPainter>
#include <QMap>

/* ============================================================
 *  CONSTRUCTEUR / DESTRUCTEUR
 * ============================================================ */
integration::integration(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::integration)
{
    ui->setupUi(this);

    ui->stackedWidget->setCurrentIndex(0);

    appliquerTheme();
    connecterLogin();
    connecterNavigation();
    connecterActions();

    remplirTableSalles();
    dessinerStatistiques();
}

integration::~integration()
{
    delete ui;
}

/* ============================================================
 *  HELPERS — DONNÉES ALÉATOIRES
 * ============================================================ */
static int randomInt(int min, int max)
{
    return QRandomGenerator::global()->bounded(min, max + 1);
}

/* ============================================================
 *  REMPLIR LE TABLEAU DES SALLES
 * ============================================================ */
void integration::remplirTableSalles()
{
    QString styleModifier = R"(
        QPushButton {
            background-color: #4338CA; color: #FFFFFF;
            border: none; border-radius: 6px;
            font-size: 10px; font-weight: 800;
            padding: 6px 12px; min-width: 90px;
        }
        QPushButton:hover { background-color: #6366F1; }
    )";

    QString styleSupprimer = R"(
        QPushButton {
            background-color: #B91C1C; color: #FFFFFF;
            border: none; border-radius: 6px;
            font-size: 10px; font-weight: 800;
            padding: 6px 12px; min-width: 90px;
        }
        QPushButton:hover { background-color: #F87171; }
    )";

    auto creerWidgetActions = [this, styleModifier, styleSupprimer](int row) {
        auto *container = new QWidget;
        auto *lay = new QHBoxLayout(container);
        lay->setContentsMargins(4, 2, 4, 2);
        lay->setSpacing(8);

        auto *btnModif = new QPushButton("MODIFIER");
        btnModif->setCursor(Qt::PointingHandCursor);
        btnModif->setStyleSheet(styleModifier);
        btnModif->setMinimumWidth(95);

        auto *btnSuppr = new QPushButton("SUPPRIMER");
        btnSuppr->setCursor(Qt::PointingHandCursor);
        btnSuppr->setStyleSheet(styleSupprimer);
        btnSuppr->setMinimumWidth(95);

        lay->addWidget(btnModif);
        lay->addWidget(btnSuppr);
        lay->addStretch();

        QObject::connect(btnModif, &QPushButton::clicked, this, [this, row]() {
            QMessageBox::information(this, "Modifier",
                                     QString("Modifier la ligne %1\n(Design uniquement)").arg(row + 1));
        });

        QObject::connect(btnSuppr, &QPushButton::clicked, this, [this, row]() {
            QMessageBox::question(this, "Supprimer",
                                  QString("Supprimer la ligne %1 ?\n(Design uniquement)").arg(row + 1));
        });

        return container;
    };

    auto *t = ui->tableSalles;
    const int NB = 8;
    t->setRowCount(NB);

    QStringList types = {"Salle informatique", "Salle de réunion",
                         "Salle conférence", "Laboratoire"};
    QStringList dispos = {"Disponible", "Occupée", "Maintenance"};

    for (int i = 0; i < NB; ++i) {
        QString id = QString("SAL-%1").arg(i + 1, 3, 10, QChar('0'));
        QString nom = QString("Salle %1").arg(i + 100);
        QString cap = QString::number(randomInt(20, 250));
        QString type = types[i % types.size()];
        QString dispo = dispos[i % dispos.size()];

        t->setItem(i, 0, new QTableWidgetItem(id));
        t->setItem(i, 1, new QTableWidgetItem(nom));
        t->setItem(i, 2, new QTableWidgetItem(cap));
        t->setItem(i, 3, new QTableWidgetItem(type));

        auto *itemDispo = new QTableWidgetItem(dispo);
        if (dispo == "Disponible")      itemDispo->setForeground(QColor("#34D399"));
        else if (dispo == "Occupée")    itemDispo->setForeground(QColor("#FBBF24"));
        else                            itemDispo->setForeground(QColor("#F87171"));
        t->setItem(i, 4, itemDispo);

        t->setCellWidget(i, 5, creerWidgetActions(i));
    }

    // Configuration finale
    t->verticalHeader()->setVisible(false);
    t->setEditTriggers(QAbstractItemView::NoEditTriggers);
    t->setSelectionBehavior(QAbstractItemView::SelectRows);
    t->setAlternatingRowColors(true);

    int lastCol = t->columnCount() - 1;
    for (int c = 0; c < lastCol; ++c) {
        t->horizontalHeader()->setSectionResizeMode(c, QHeaderView::Stretch);
    }
    if (lastCol >= 0) {
        t->horizontalHeader()->setSectionResizeMode(lastCol, QHeaderView::Fixed);
        t->setColumnWidth(lastCol, 240);
    }
    t->verticalHeader()->setDefaultSectionSize(46);
}

/* ============================================================
 *  STATISTIQUES : camembert + barres horizontales
 * ============================================================ */
void integration::dessinerStatistiques()
{
    /* ---------- 1) CAMEMBERT : Disponibilité ---------- */
    {
        QPixmap pix(240, 220);
        pix.fill(Qt::transparent);
        QPainter p(&pix);
        p.setRenderHint(QPainter::Antialiasing);

        int dispo = 0, occ = 0, maint = 0;
        for (int i = 0; i < ui->tableSalles->rowCount(); ++i) {
            QString s = ui->tableSalles->item(i, 4)->text();
            if (s == "Disponible")      dispo++;
            else if (s == "Occupée")    occ++;
            else                        maint++;
        }
        int total = dispo + occ + maint;
        if (total == 0) total = 1;

        QRectF rect(20, 20, 140, 140);
        double startAngle = 90.0;

        auto drawSlice = [&](int val, const QColor &color) {
            if (val <= 0) return;
            double sweep = -360.0 * val / total;
            p.setBrush(color);
            p.setPen(Qt::NoPen);
            p.drawPie(rect, int(startAngle * 16), int(sweep * 16));
            startAngle += sweep;
        };

        drawSlice(dispo, QColor("#34D399"));
        drawSlice(occ,   QColor("#FBBF24"));
        drawSlice(maint, QColor("#F87171"));

        // Légende
        QFont f = p.font();
        f.setPointSize(8);
        f.setBold(true);
        p.setFont(f);
        p.setPen(QColor("#E5E7EB"));

        p.setBrush(QColor("#34D399"));
        p.drawRect(170, 30, 10, 10);
        p.drawText(185, 39, QString("Dispo (%1)").arg(dispo));

        p.setBrush(QColor("#FBBF24"));
        p.drawRect(170, 55, 10, 10);
        p.drawText(185, 64, QString("Occupée (%1)").arg(occ));

        p.setBrush(QColor("#F87171"));
        p.drawRect(170, 80, 10, 10);
        p.drawText(185, 89, QString("Maint. (%1)").arg(maint));

        f.setBold(false);
        f.setPointSize(8);
        p.setFont(f);
        p.setPen(QColor("#94A3B8"));
        p.drawText(20, 190, "Répartition par disponibilité");

        p.end();
        ui->labelStatutPie->setPixmap(pix);
    }

    /* ---------- 2) BARRES HORIZONTALES : Type de salle ---------- */
    {
        QPixmap pix(400, 220);
        pix.fill(Qt::transparent);
        QPainter p(&pix);
        p.setRenderHint(QPainter::Antialiasing);

        QMap<QString, int> types;
        for (int i = 0; i < ui->tableSalles->rowCount(); ++i)
            types[ui->tableSalles->item(i, 3)->text()]++;

        int maxVal = 1;
        for (int v : types) if (v > maxVal) maxVal = v;

        auto couleur = [](const QString &t) -> QColor {
            if (t == "Salle informatique") return QColor("#6366F1");
            if (t == "Salle de réunion")   return QColor("#FBBF24");
            if (t == "Salle conférence")   return QColor("#34D399");
            return QColor("#F87171");
        };

        int y = 25;
        const int barMaxW = 240;
        const int barH = 26;

        QFont f = p.font();
        f.setPointSize(8);
        f.setBold(true);
        p.setFont(f);

        for (auto it = types.begin(); it != types.end(); ++it) {
            p.setPen(QColor("#E5E7EB"));
            p.drawText(10, y + 17, it.key());

            p.setPen(Qt::NoPen);
            p.setBrush(QColor("#1F2937"));
            p.drawRoundedRect(140, y, barMaxW, barH, 6, 6);

            int w = int(barMaxW * (double)it.value() / maxVal);
            p.setBrush(couleur(it.key()));
            p.drawRoundedRect(140, y, w, barH, 6, 6);

            p.setPen(QColor("#FFFFFF"));
            p.drawText(140 + w + 8, y + 17, QString::number(it.value()));

            y += barH + 18;
        }

        f.setBold(false);
        f.setPointSize(8);
        p.setFont(f);
        p.setPen(QColor("#94A3B8"));
        p.drawText(10, 200, "Nombre de salles par type");

        p.end();
        ui->labelRoleBar->setPixmap(pix);
    }
}

/* ============================================================
 *  NAVIGATION
 * ============================================================ */
void integration::allerPage(int index)
{
    if (index < 0 || index >= ui->stackedWidget->count())
        return;
    ui->stackedWidget->setCurrentIndex(index);

    QWidget *w = ui->stackedWidget->currentWidget();
    if (w) {
        if (auto *sa = w->findChild<QScrollArea*>()) {
            sa->verticalScrollBar()->setValue(0);
        }
    }
}

void integration::goLogin()    { allerPage(0); }
void integration::goSalles()   { allerPage(1); }

/* ============================================================
 *  LOGIN
 * ============================================================ */
void integration::connecterLogin()
{
    if (ui->pushButtonConnexion)
        QObject::connect(ui->pushButtonConnexion, &QPushButton::clicked,
                         this, &integration::onConnexion);
    if (ui->pushButtonCGU)
        QObject::connect(ui->pushButtonCGU, &QPushButton::clicked,
                         this, &integration::onCGU);
    if (ui->pushButtonPolitique)
        QObject::connect(ui->pushButtonPolitique, &QPushButton::clicked,
                         this, &integration::onPolitique);
    if (ui->pushButtonAPropos)
        QObject::connect(ui->pushButtonAPropos, &QPushButton::clicked,
                         this, &integration::onAPropos);
    if (ui->lineEditMotDePasse)
        QObject::connect(ui->lineEditMotDePasse, &QLineEdit::returnPressed,
                         this, &integration::onConnexion);
}

/* ============================================================
 *  NAVIGATION — Boutons navbar (Notifications/Profil/Déconnexion uniquement)
 * ============================================================ */
void integration::connecterNavigation()
{
    if (ui->btnNotifications) QObject::connect(ui->btnNotifications, &QPushButton::clicked, this, &integration::onNotifications);
    if (ui->btnProfil)        QObject::connect(ui->btnProfil,        &QPushButton::clicked, this, &integration::onProfil);
    if (ui->btnDeconnexion)   QObject::connect(ui->btnDeconnexion,   &QPushButton::clicked, this, &integration::onDeconnexion);
}

/* ============================================================
 *  ACTIONS (Affectation intelligente + QR Code)
 * ============================================================ */
void integration::connecterActions()
{
    if (ui->btnSuggerer_2)
        QObject::connect(ui->btnSuggerer_2, &QPushButton::clicked,
                         this, &integration::onSuggererSalle);

    if (ui->btnValiderQR_4)
        QObject::connect(ui->btnValiderQR_4, &QPushButton::clicked,
                         this, &integration::onValiderQR);
}

void integration::onSuggererSalle()
{
    if (!ui->leEffectif_2) return;
    QString effStr = ui->leEffectif_2->text().trimmed();
    bool ok = false;
    int effectif = effStr.toInt(&ok);

    if (!ok || effectif <= 0) {
        QMessageBox::warning(this, "Affectation",
                             "Veuillez saisir un effectif valide (nombre entier > 0).");
        return;
    }

    // Cherche la 1ère salle disponible avec capacité >= effectif
    QString suggestion;
    bool trouve = false;
    for (int i = 0; i < ui->tableSalles->rowCount(); ++i) {
        int cap = ui->tableSalles->item(i, 2)->text().toInt();
        QString dispo = ui->tableSalles->item(i, 4)->text();
        if (dispo == "Disponible" && cap >= effectif) {
            suggestion = QString("<b>%1</b> (cap. %2) — type : %3")
                             .arg(ui->tableSalles->item(i, 1)->text())
                             .arg(cap)
                             .arg(ui->tableSalles->item(i, 3)->text());
            trouve = true;
            break;
        }
    }

    if (trouve) {
        QMessageBox::information(this, "Affectation intelligente",
                                 "Salle recommandée pour un effectif de " +
                                     QString::number(effectif) + " :<br><br>" + suggestion);
    } else {
        QMessageBox::warning(this, "Affectation intelligente",
                             "Aucune salle disponible ne peut accueillir " +
                                 QString::number(effectif) + " personnes.");
    }
}

void integration::onValiderQR()
{
    if (!ui->leCodeQR_4) return;
    QString code = ui->leCodeQR_4->text().trimmed();

    if (code.isEmpty()) {
        QMessageBox::warning(this, "QR Code",
                             "Veuillez saisir ou scanner un code.");
        return;
    }

    QMessageBox::information(this, "QR Code · Accès",
                             QString("Code <b>%1</b> validé.<br>Accès autorisé.").arg(code.toHtmlEscaped()));

    ui->leCodeQR_4->clear();
}

/* ============================================================
 *  LOGIN
 * ============================================================ */
void integration::onConnexion()
{
    const QString user = ui->lineEditIdentifiant->text().trimmed();
    const QString pass = ui->lineEditMotDePasse->text();

    if (user.isEmpty() || pass.isEmpty()) {
        QMessageBox::warning(this, "Connexion",
                             "Veuillez saisir votre identifiant et votre mot de passe.");
        return;
    }
    goSalles();
}

/* ============================================================
 *  HELPERS DIALOGUES
 * ============================================================ */
static void afficherDialogue(QWidget *parent,
                             const QString &titre,
                             const QString &html)
{
    QDialog dlg(parent);
    dlg.setWindowTitle(titre);
    dlg.setMinimumSize(600, 520);

    auto *lay = new QVBoxLayout(&dlg);
    lay->setContentsMargins(20, 20, 20, 20);
    lay->setSpacing(12);

    auto *txt = new QTextBrowser;
    txt->setHtml(html);
    txt->setOpenExternalLinks(true);
    lay->addWidget(txt, 1);

    auto *btn = new QPushButton("FERMER");
    btn->setCursor(Qt::PointingHandCursor);
    btn->setMinimumHeight(38);
    QObject::connect(btn, &QPushButton::clicked, &dlg, &QDialog::accept);
    lay->addWidget(btn, 0, Qt::AlignRight);

    dlg.exec();
}

void integration::onCGU()
{
    afficherDialogue(this, "Conditions Générales d'Utilisation", R"(
        <div style='color:#E5E7EB;font-family:Arial;font-size:13px;line-height:1.6;'>
        <h2 style='color:#818CF8;'>1. Objet</h2>
        <p>Les présentes conditions régissent l'utilisation de la plateforme HACKNOVA.</p>
        <h2 style='color:#818CF8;'>2. Accès au service</h2>
        <p>L'accès est réservé aux utilisateurs autorisés par l'organisation.</p>
        <h2 style='color:#818CF8;'>3. Données personnelles</h2>
        <p>Les données sont traitées conformément à la réglementation en vigueur.</p>
        <h2 style='color:#818CF8;'>4. Responsabilités</h2>
        <p>L'utilisateur s'engage à ne pas divulguer ses identifiants.</p>
        </div>
    )");
}

void integration::onPolitique()
{
    afficherDialogue(this, "Politique d'utilisation", R"(
        <div style='color:#E5E7EB;font-family:Arial;font-size:13px;line-height:1.6;'>
        <h2 style='color:#818CF8;'>Confidentialité</h2>
        <p>Vos données ne sont jamais partagées avec des tiers.</p>
        <h2 style='color:#818CF8;'>Sécurité</h2>
        <p>Les mots de passe sont chiffrés et les sessions sécurisées.</p>
        <h2 style='color:#818CF8;'>Cookies</h2>
        <p>Aucun cookie de tracking n'est utilisé par la plateforme.</p>
        </div>
    )");
}

void integration::onAPropos()
{
    afficherDialogue(this, "À propos de HACKNOVA", R"(
        <div style='color:#E5E7EB;text-align:center;font-family:Arial;'>
        <h1 style='color:#818CF8;letter-spacing:5px;'>HACKNOVA</h1>
        <p style='color:#94A3B8;'>Smart Hackathon Management</p>
        <hr/>
        <p><b>Version :</b> 1.0.0</p>
        <p><b>Établissement :</b> Esprit School of Engineering</p>
        <p><b>Année :</b> 2025</p>
        <hr/>
        <h2 style='color:#818CF8;letter-spacing:3px;'>GROUPE EL FALLEGA</h2>
        <p style='color:#94A3B8;'>Groupe de développement</p>
        <hr/>
        <p style='color:#64748B;font-size:11px;'>
        © 2025 HACKNOVA. Tous droits réservés.</p>
        </div>
    )");
}

void integration::onNotifications()
{
    afficherDialogue(this, "Notifications", R"(
        <div style='color:#E5E7EB;font-family:Arial;font-size:13px;'>
        <p style='color:#818CF8;font-weight:800;'>Nouvelle salle ajoutée</p>
        <p style='color:#94A3B8;font-size:12px;'>La salle 105 est maintenant disponible.</p>
        <hr/>
        <p style='color:#FBBF24;font-weight:800;'>Maintenance</p>
        <p style='color:#94A3B8;font-size:12px;'>La salle 102 sera en maintenance demain.</p>
        </div>
    )");
}

void integration::onProfil()
{
    afficherDialogue(this, "Profil utilisateur", R"(
        <div style='color:#E5E7EB;text-align:center;font-family:Arial;'>
        <h1 style='color:#818CF8;'>HN</h1>
        <h2 style='color:#FFFFFF;'>Utilisateur</h2>
        <p style='color:#94A3B8;'><b>Rôle :</b> Administrateur</p>
        <p style='color:#94A3B8;'><b>Email :</b> user@hacknova.tn</p>
        <p style='color:#94A3B8;'><b>Statut :</b>
        <span style='color:#34D399;'>Actif</span></p>
        <hr/>
        <p style='color:#64748B;font-size:11px;'>
        HACKNOVA — Smart Hackathon Management</p>
        </div>
    )");
}

void integration::onDeconnexion()
{
    const auto rep = QMessageBox::question(
        this, "Déconnexion",
        "Voulez-vous vraiment vous déconnecter ?",
        QMessageBox::Yes | QMessageBox::No);

    if (rep == QMessageBox::Yes) {
        if (ui->lineEditIdentifiant) ui->lineEditIdentifiant->clear();
        if (ui->lineEditMotDePasse)  ui->lineEditMotDePasse->clear();
        goLogin();
    }
}

/* ============================================================
 *  THÈME DARK MODE
 * ============================================================ */
void integration::appliquerTheme()
{
    this->setStyleSheet(R"(
QMainWindow, QWidget {
    background-color: #0B1020;
    color: #E5E7EB;
    font-family: "Arial";
}
QWidget#centralWidget { background-color: #0B1020; }

QToolTip {
    background-color: #1F2937; color: #E5E7EB;
    border: 1px solid #6366F1; padding: 6px 10px;
    border-radius: 6px; font-size: 11px;
}

QScrollArea { background-color: #0B1020; border: none; }
QScrollArea > QWidget > QWidget { background-color: #0B1020; }
QScrollBar:vertical {
    background: #111827; width: 10px; border-radius: 5px; margin: 0;
}
QScrollBar::handle:vertical {
    background: #374151; border-radius: 5px; min-height: 30px;
}
QScrollBar::handle:vertical:hover { background: #6366F1; }
QScrollBar::add-line:vertical,
QScrollBar::sub-line:vertical { height: 0; }

QFrame#frameNavbar {
    background-color: #111827; border: none;
    border-bottom: 1px solid #1F2937; border-radius: 0;
}

QLabel#labelNavLogo {
    background: qlineargradient(x1:0, y1:0, x2:1, y2:1,
        stop:0 #6366F1, stop:1 #8B5CF6);
    color: #FFFFFF; font-size: 17px; font-weight: 900;
    border-radius: 12px; qproperty-alignment: AlignCenter;
}
QLabel#labelNavBrand {
    color: #FFFFFF; font-size: 15px; font-weight: 900; letter-spacing: 2px;
}
QLabel#labelNavSub {
    color: #818CF8; font-size: 8px; font-weight: 700; letter-spacing: 2px;
}

QPushButton#btnDashboard, QPushButton#btnEmployes,
QPushButton#btnSalles, QPushButton#btnEvaluateurs,
QPushButton#btnParticipants, QPushButton#btnSponsors,
QPushButton#btnProjets, QPushButton#btnNotifications,
QPushButton#btnProfil {
    background-color: transparent; color: #C7D2FE;
    font-size: 11px; font-weight: 800; letter-spacing: 0.5px;
    border: none; border-radius: 8px; padding: 8px 14px;
}
QPushButton#btnDashboard:hover, QPushButton#btnEmployes:hover,
QPushButton#btnSalles:hover, QPushButton#btnEvaluateurs:hover,
QPushButton#btnParticipants:hover, QPushButton#btnSponsors:hover,
QPushButton#btnProjets:hover, QPushButton#btnNotifications:hover,
QPushButton#btnProfil:hover {
    background-color: #1F2937; color: #FFFFFF;
}

QPushButton#btnSalles {
    background-color: #312E81; color: #FFFFFF;
    border-bottom: 2px solid #6366F1;
}

QPushButton#btnDeconnexion {
    color: #F87171; border: 1px solid #7F1D1D;
    background-color: transparent;
    font-size: 11px; font-weight: 800;
    border-radius: 8px; padding: 8px 14px;
}
QPushButton#btnDeconnexion:hover {
    background-color: #B91C1C; color: #FFFFFF; border: 1px solid #B91C1C;
}

QLabel#labelTitleSalles {
    color: #FFFFFF; font-size: 22px; font-weight: 900;
}
QLabel#labelSubSalles { color: #94A3B8; font-size: 12px; }

QWidget#pageLogin {
    background: qradialgradient(cx:0.3, cy:0.3, radius:1.4,
        stop:0 #1E1B4B, stop:0.5 #0B1020, stop:1 #05070F);
}
QFrame#frameLoginCard {
    background-color: #111827; border: 1px solid #1F2937;
    border-radius: 20px;
}
QFrame#frameLoginBrand {
    background: qlineargradient(x1:0, y1:0, x2:1, y2:1,
        stop:0 #1E1B4B, stop:0.6 #312E81, stop:1 #4338CA);
    border-top-left-radius: 20px; border-bottom-left-radius: 20px;
}
QLabel#labelLoginLogo {
    background: qlineargradient(x1:0, y1:0, x2:1, y2:1,
        stop:0 #6366F1, stop:1 #8B5CF6);
    color: #FFFFFF; border-radius: 20px;
    qproperty-alignment: AlignCenter;
}
QLabel#labelLoginBrandTitle  { color: #FFFFFF; letter-spacing: 5px; }
QLabel#labelLoginBrandSub    { color: #A5B4FC; letter-spacing: 3px; }
QLabel#labelLoginBrandSlogan { color: #E0E7FF; }
QLabel#labelLoginBrandVersion{ color: #94A3B8; }
QLabel#labelLoginBrandTeam   { color: #818CF8; }
QLabel#labelLoginTitle       { color: #FFFFFF; }
QLabel#labelLoginSub         { color: #94A3B8; }
QLabel#labelLoginField,
QLabel#labelLoginField2      { color: #94A3B8; letter-spacing: 1px; }
QLabel#labelLoginFooter      { color: #475569; }

QLineEdit#lineEditIdentifiant,
QLineEdit#lineEditMotDePasse {
    background-color: #0B1020; border: 1.5px solid #374151;
    border-radius: 8px; padding: 8px 12px;
    color: #E5E7EB; selection-background-color: #6366F1;
}
QLineEdit#lineEditIdentifiant:focus,
QLineEdit#lineEditMotDePasse:focus {
    border: 1.5px solid #6366F1; background-color: #111827;
}

QCheckBox#checkBoxSouvenir { color: #94A3B8; spacing: 8px; }
QCheckBox#checkBoxSouvenir::indicator {
    width: 16px; height: 16px;
    border: 1.5px solid #374151;
    border-radius: 4px; background-color: #0B1020;
}
QCheckBox#checkBoxSouvenir::indicator:checked {
    background-color: #6366F1; border: 1.5px solid #6366F1;
}

QPushButton#pushButtonConnexion {
    background-color: #6366F1; color: #FFFFFF;
    font-size: 13px; font-weight: 900; letter-spacing: 2px;
    border: none; border-radius: 10px; padding: 16px;
}
QPushButton#pushButtonConnexion:hover   { background-color: #818CF8; }
QPushButton#pushButtonConnexion:pressed { background-color: #4F46E5; }

QPushButton#pushButtonCGU,
QPushButton#pushButtonPolitique,
QPushButton#pushButtonAPropos {
    color: #94A3B8; background: transparent;
    border: none; font-size: 11px;
    text-align: left; padding: 2px 0;
}
QPushButton#pushButtonCGU:hover,
QPushButton#pushButtonPolitique:hover,
QPushButton#pushButtonAPropos:hover { color: #818CF8; }

QFrame#cardFormSalles, QFrame#cardTableSalles,
QFrame#frameAffectation_2, QFrame#frameQR_4,
QFrame#cardStats {
    background-color: #111827; border: 1px solid #1F2937;
    border-radius: 14px;
}

QLabel#labelFormTitleSalles, QLabel#labelTableTitleSalles,
QLabel#labelStatsTitle {
    color: #FFFFFF; font-size: 14px; font-weight: 800;
}

QLabel#lblSalleID, QLabel#lblSalleNom, QLabel#lblSalleCapacite,
QLabel#lblSalleType, QLabel#lblSalleDispo {
    color: #94A3B8; font-size: 10px; font-weight: 800; letter-spacing: 1px;
}

QLineEdit, QComboBox, QSpinBox {
    background-color: #0B1020; border: 1.5px solid #374151;
    border-radius: 8px; padding: 8px 12px;
    color: #E5E7EB; font-size: 13px; min-height: 20px;
    selection-background-color: #6366F1; selection-color: #FFFFFF;
}
QLineEdit:focus, QComboBox:focus, QSpinBox:focus {
    border: 1.5px solid #6366F1; background-color: #111827;
}
QLineEdit:read-only { background-color: #1F2937; color: #94A3B8; }
QComboBox::drop-down { border: none; width: 24px; }
QComboBox QAbstractItemView {
    background-color: #111827; border: 1px solid #374151;
    selection-background-color: #6366F1; selection-color: #FFFFFF;
    color: #E5E7EB; outline: none;
}

QPushButton#btnAjouterSalle, QPushButton#btnExporterSalle,
QPushButton#btnValiderQR_4, QPushButton#btnSuggerer_2 {
    background-color: #047857; color: #FFFFFF;
    font-size: 11px; font-weight: 800; letter-spacing: 1px;
    border: none; border-radius: 8px; padding: 10px 18px;
}
QPushButton#btnAjouterSalle:hover, QPushButton#btnExporterSalle:hover,
QPushButton#btnValiderQR_4:hover, QPushButton#btnSuggerer_2:hover {
    background-color: #34D399;
}

QPushButton#btnModifierSalle, QPushButton#btnRechercherSalle {
    background-color: #4338CA; color: #FFFFFF;
    font-size: 11px; font-weight: 800; letter-spacing: 1px;
    border: none; border-radius: 8px; padding: 10px 18px;
}
QPushButton#btnModifierSalle:hover, QPushButton#btnRechercherSalle:hover {
    background-color: #6366F1;
}

QPushButton#btnSupprimerSalle {
    background-color: #B91C1C; color: #FFFFFF;
    font-size: 11px; font-weight: 800; letter-spacing: 1px;
    border: none; border-radius: 8px; padding: 10px 18px;
}
QPushButton#btnSupprimerSalle:hover { background-color: #F87171; }

QPushButton#btnTrierSalle, QPushButton#btnAnnuler {
    background-color: #475569; color: #E5E7EB;
    font-size: 11px; font-weight: 700;
    border: none; border-radius: 8px; padding: 10px 18px;
}
QPushButton#btnTrierSalle:hover, QPushButton#btnAnnuler:hover {
    background-color: #64748B; color: #FFFFFF;
}

QTableWidget {
    background-color: #0B1020; border: 1px solid #1F2937;
    border-radius: 10px; gridline-color: #1F2937;
    font-size: 12px; color: #E5E7EB;
    selection-background-color: #312E81; selection-color: #FFFFFF;
    alternate-background-color: #111827; outline: none;
}
QTableWidget::item { padding: 8px; border-bottom: 1px solid #1F2937; }
QTableWidget::item:selected { background-color: #312E81; color: #FFFFFF; }
QHeaderView::section {
    background-color: #111827; color: #818CF8;
    font-size: 10px; font-weight: 800; letter-spacing: 1px;
    padding: 12px 10px; border: none;
    border-right: 1px solid #1F2937;
    border-bottom: 2px solid #6366F1;
}
QTableCornerButton::section { background-color: #111827; border: none; }

QLabel#lblTitreAffect_2, QLabel#lblTitreQR_4 {
    color: #818CF8; font-size: 11px; font-weight: 900; letter-spacing: 1px;
}
QLabel#lblDescAffect_2, QLabel#lblDescQR_4 {
    color: #94A3B8; font-size: 11px;
}
QFrame#frameSaisieAffect_2, QFrame#frameSaisieQR_4 {
    background-color: #0B1020; border: 1px solid #1F2937;
    border-radius: 8px;
}

QLabel#labelStatutPie, QLabel#labelRoleBar {
    background-color: transparent;
}

QLabel#labelFooterSalles {
    color: #475569; font-size: 10px;
}
)");
}