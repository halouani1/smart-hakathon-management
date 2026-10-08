/********************************************************************************
** Form generated from reading UI file 'GestionEvaluateurs.ui'
**
** Created by: Qt User Interface Compiler version 6.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GESTIONEVALUATEURS_H
#define UI_GESTIONEVALUATEURS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GestionEvaluateurs
{
public:
    QWidget *centralwidget;
    QHBoxLayout *mainLayout;
    QFrame *sidebar;
    QVBoxLayout *sideLayout;
    QLabel *brand;
    QLabel *brand2;
    QSpacerItem *spacerBrand;
    QLabel *sectionTitle;
    QPushButton *navDashboard;
    QPushButton *navEvaluateurs;
    QPushButton *navParticipants;
    QPushButton *navSponsors;
    QPushButton *navProjects;
    QPushButton *navSales;
    QSpacerItem *spacerMenu;
    QFrame *separator;
    QLabel *roleLabel;
    QPushButton *logout;
    QWidget *content;
    QVBoxLayout *contentLayout;
    QVBoxLayout *headerLayout;
    QLabel *pageTitle;
    QLabel *subtitle;
    QHBoxLayout *metricsLayout;
    QFrame *cardTotal;
    QVBoxLayout *vboxLayout;
    QLabel *metricTotalLabel;
    QLabel *metricTotal;
    QFrame *cardForm;
    QVBoxLayout *vboxLayout1;
    QLabel *metricActiveLabel;
    QLabel *metricActive;
    QFrame *cardInactive;
    QVBoxLayout *vboxLayout2;
    QLabel *metricInactiveLabel;
    QLabel *metricInactive;
    QFrame *cardTableExtra;
    QVBoxLayout *vboxLayout3;
    QLabel *metricScoreLabel;
    QLabel *metricRepartitionActive;
    QLabel *metricRepartitionInactive;
    QFrame *cardExtra2;
    QVBoxLayout *vboxLayout4;
    QLabel *sectionHeader;
    QGridLayout *formLayout;
    QLabel *fieldLabel1;
    QLabel *fieldLabel2;
    QLabel *fieldLabel3;
    QLabel *fieldLabel4;
    QLabel *fieldLabel5;
    QLineEdit *idEvaluateurEdit;
    QLineEdit *nomEdit;
    QLineEdit *prenomEdit;
    QLineEdit *resultatEdit;
    QComboBox *statutCombo;
    QPushButton *ajouterButton;
    QPushButton *annulerButton;
    QFrame *cardTable;
    QVBoxLayout *vboxLayout5;
    QHBoxLayout *tableToolbar;
    QLabel *sectionHeader2;
    QSpacerItem *toolbarSpacer;
    QLineEdit *rechercheEdit;
    QPushButton *rechercherButton;
    QPushButton *trierButton;
    QPushButton *exporterButton;
    QTableWidget *evaluateursTable;
    QHBoxLayout *businessLayout;
    QPushButton *business1;
    QPushButton *business2;
    QSpacerItem *businessSpacer;
    QLabel *footer;

    void setupUi(QMainWindow *GestionEvaluateurs)
    {
        if (GestionEvaluateurs->objectName().isEmpty())
            GestionEvaluateurs->setObjectName("GestionEvaluateurs");
        GestionEvaluateurs->resize(1440, 900);
        GestionEvaluateurs->setStyleSheet(QString::fromUtf8("\n"
"QMainWindow{background:#F5F7FB;}\n"
"QWidget{font-family:\"Segoe UI\";color:#18243A;}\n"
"#sidebar{background:#07133A;}\n"
"#brand{color:white;font-size:24px;font-weight:700;}\n"
"#brand2{color:#C9D3EA;font-size:20px;font-weight:600;}\n"
"#sectionTitle{color:#AAB8D4;font-size:12px;font-weight:600;}\n"
"#navButton{background:transparent;border:0;border-radius:8px;color:#D9E2F4;text-align:left;padding:12px 16px;font-size:14px;}\n"
"#navButton:hover{background:#10224F;}\n"
"#navActive{background:#1F65D6;border:0;border-radius:8px;color:white;text-align:left;padding:12px 16px;font-size:14px;font-weight:700;}\n"
"#logout{background:#D64545;color:white;border:0;border-radius:7px;padding:11px 16px;font-weight:600;}\n"
"#pageTitle{font-size:30px;font-weight:750;color:#101C36;}\n"
"#subtitle{color:#6C7890;font-size:13px;}\n"
"#cardForm,#cardTableExtra{background:white;border:1px solid #E4E8F0;border-radius:12px;}\n"
"#cardTotal{background:#EEF5FF;border:1px solid #D9E8FF;border-radius:12px;}\n"
"#cardInactive{back"
                        "ground:#FFF1F1;border:1px solid #FFD8D8;border-radius:12px;}\n"
"#metricTotalLabel,#metricActiveLabel,#metricInactiveLabel,#metricScoreLabel{color:#68758B;font-size:13px;font-weight:600;}\n"
"#metricTotal,#metricActive,#metricScore{font-size:30px;font-weight:800;color:#12356B;}\n"
"#metricInactive{font-size:30px;font-weight:800;color:#C43C3C;}\n"
"#sectionHeader{font-size:17px;font-weight:750;color:#15213B;}\n"
"#fieldLabel{font-size:12px;font-weight:700;color:#59677F;}\n"
"QLineEdit,QComboBox{background:white;border:1px solid #D8DEE9;border-radius:7px;padding:9px 11px;min-height:20px;color:#17233B;}\n"
"QLineEdit:focus,QComboBox:focus{border:1px solid #1F65D6;}\n"
"#primary{background:#1F65D6;color:white;border:0;border-radius:7px;padding:10px 18px;font-weight:700;}\n"
"#secondary{background:#EEF1F6;color:#39465C;border:1px solid #D8DEE9;border-radius:7px;padding:10px 18px;font-weight:600;}\n"
"#danger{background:#D64545;color:white;border:0;border-radius:7px;padding:8px 13px;font-weight:600;}\n"
"#edit{backg"
                        "round:#EAF3FF;color:#1F65D6;border:1px solid #CFE2FF;border-radius:7px;padding:8px 13px;font-weight:600;}\n"
"#tableSearch{background:white;border:1px solid #D8DEE9;border-radius:7px;padding:9px 12px;}\n"
"QTableWidget{background:white;border:1px solid #E1E6EF;border-radius:9px;gridline-color:#EDF0F5;selection-background-color:#EAF3FF;selection-color:#15213B;}\n"
"QHeaderView::section{background:#1F437A;color:white;border:0;border-right:1px solid #31568F;padding:10px;font-size:12px;font-weight:700;}\n"
"#statusActive{background:#E7F7EF;color:#16804E;border-radius:10px;padding:4px 9px;font-weight:700;}\n"
"#statusInactive{background:#FCEAEA;color:#C43C3C;border-radius:10px;padding:4px 9px;font-weight:700;}\n"
"#footer{color:#8490A4;font-size:11px;}\n"
"QPushButton{outline:0;}\n"
"   "));
        centralwidget = new QWidget(GestionEvaluateurs);
        centralwidget->setObjectName("centralwidget");
        mainLayout = new QHBoxLayout(centralwidget);
        mainLayout->setSpacing(0);
        mainLayout->setObjectName("mainLayout");
        mainLayout->setContentsMargins(0, 0, 0, 0);
        sidebar = new QFrame(centralwidget);
        sidebar->setObjectName("sidebar");
        sidebar->setMinimumSize(QSize(255, 0));
        sidebar->setMaximumSize(QSize(255, 16777215));
        sideLayout = new QVBoxLayout(sidebar);
        sideLayout->setObjectName("sideLayout");
        sideLayout->setContentsMargins(20, 25, 20, 20);
        brand = new QLabel(sidebar);
        brand->setObjectName("brand");

        sideLayout->addWidget(brand);

        brand2 = new QLabel(sidebar);
        brand2->setObjectName("brand2");

        sideLayout->addWidget(brand2);

        spacerBrand = new QSpacerItem(20, 18, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        sideLayout->addItem(spacerBrand);

        sectionTitle = new QLabel(sidebar);
        sectionTitle->setObjectName("sectionTitle");

        sideLayout->addWidget(sectionTitle);

        navDashboard = new QPushButton(sidebar);
        navDashboard->setObjectName("navDashboard");

        sideLayout->addWidget(navDashboard);

        navEvaluateurs = new QPushButton(sidebar);
        navEvaluateurs->setObjectName("navEvaluateurs");

        sideLayout->addWidget(navEvaluateurs);

        navParticipants = new QPushButton(sidebar);
        navParticipants->setObjectName("navParticipants");

        sideLayout->addWidget(navParticipants);

        navSponsors = new QPushButton(sidebar);
        navSponsors->setObjectName("navSponsors");

        sideLayout->addWidget(navSponsors);

        navProjects = new QPushButton(sidebar);
        navProjects->setObjectName("navProjects");

        sideLayout->addWidget(navProjects);

        navSales = new QPushButton(sidebar);
        navSales->setObjectName("navSales");

        sideLayout->addWidget(navSales);

        spacerMenu = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        sideLayout->addItem(spacerMenu);

        separator = new QFrame(sidebar);
        separator->setObjectName("separator");
        separator->setFrameShape(QFrame::HLine);

        sideLayout->addWidget(separator);

        roleLabel = new QLabel(sidebar);
        roleLabel->setObjectName("roleLabel");

        sideLayout->addWidget(roleLabel);

        logout = new QPushButton(sidebar);
        logout->setObjectName("logout");

        sideLayout->addWidget(logout);


        mainLayout->addWidget(sidebar);

        content = new QWidget(centralwidget);
        content->setObjectName("content");
        contentLayout = new QVBoxLayout(content);
        contentLayout->setSpacing(16);
        contentLayout->setObjectName("contentLayout");
        contentLayout->setContentsMargins(30, 25, 30, 20);
        headerLayout = new QVBoxLayout();
        headerLayout->setSpacing(3);
        headerLayout->setObjectName("headerLayout");
        pageTitle = new QLabel(content);
        pageTitle->setObjectName("pageTitle");

        headerLayout->addWidget(pageTitle);

        subtitle = new QLabel(content);
        subtitle->setObjectName("subtitle");

        headerLayout->addWidget(subtitle);


        contentLayout->addLayout(headerLayout);

        metricsLayout = new QHBoxLayout();
        metricsLayout->setSpacing(14);
        metricsLayout->setObjectName("metricsLayout");
        cardTotal = new QFrame(content);
        cardTotal->setObjectName("cardTotal");
        vboxLayout = new QVBoxLayout(cardTotal);
        vboxLayout->setObjectName("vboxLayout");
        vboxLayout->setContentsMargins(18, 14, 18, 14);
        metricTotalLabel = new QLabel(cardTotal);
        metricTotalLabel->setObjectName("metricTotalLabel");

        vboxLayout->addWidget(metricTotalLabel);

        metricTotal = new QLabel(cardTotal);
        metricTotal->setObjectName("metricTotal");

        vboxLayout->addWidget(metricTotal);


        metricsLayout->addWidget(cardTotal);

        cardForm = new QFrame(content);
        cardForm->setObjectName("cardForm");
        vboxLayout1 = new QVBoxLayout(cardForm);
        vboxLayout1->setObjectName("vboxLayout1");
        vboxLayout1->setContentsMargins(18, 14, 18, 14);
        metricActiveLabel = new QLabel(cardForm);
        metricActiveLabel->setObjectName("metricActiveLabel");

        vboxLayout1->addWidget(metricActiveLabel);

        metricActive = new QLabel(cardForm);
        metricActive->setObjectName("metricActive");

        vboxLayout1->addWidget(metricActive);


        metricsLayout->addWidget(cardForm);

        cardInactive = new QFrame(content);
        cardInactive->setObjectName("cardInactive");
        vboxLayout2 = new QVBoxLayout(cardInactive);
        vboxLayout2->setObjectName("vboxLayout2");
        vboxLayout2->setContentsMargins(18, 14, 18, 14);
        metricInactiveLabel = new QLabel(cardInactive);
        metricInactiveLabel->setObjectName("metricInactiveLabel");

        vboxLayout2->addWidget(metricInactiveLabel);

        metricInactive = new QLabel(cardInactive);
        metricInactive->setObjectName("metricInactive");

        vboxLayout2->addWidget(metricInactive);


        metricsLayout->addWidget(cardInactive);

        cardTableExtra = new QFrame(content);
        cardTableExtra->setObjectName("cardTableExtra");
        vboxLayout3 = new QVBoxLayout(cardTableExtra);
        vboxLayout3->setObjectName("vboxLayout3");
        vboxLayout3->setContentsMargins(18, 14, 18, 14);
        metricScoreLabel = new QLabel(cardTableExtra);
        metricScoreLabel->setObjectName("metricScoreLabel");

        vboxLayout3->addWidget(metricScoreLabel);

        metricRepartitionActive = new QLabel(cardTableExtra);
        metricRepartitionActive->setObjectName("metricRepartitionActive");

        vboxLayout3->addWidget(metricRepartitionActive);

        metricRepartitionInactive = new QLabel(cardTableExtra);
        metricRepartitionInactive->setObjectName("metricRepartitionInactive");

        vboxLayout3->addWidget(metricRepartitionInactive);


        metricsLayout->addWidget(cardTableExtra);


        contentLayout->addLayout(metricsLayout);

        cardExtra2 = new QFrame(content);
        cardExtra2->setObjectName("cardExtra2");
        vboxLayout4 = new QVBoxLayout(cardExtra2);
        vboxLayout4->setSpacing(12);
        vboxLayout4->setObjectName("vboxLayout4");
        vboxLayout4->setContentsMargins(20, 18, 20, 18);
        sectionHeader = new QLabel(cardExtra2);
        sectionHeader->setObjectName("sectionHeader");

        vboxLayout4->addWidget(sectionHeader);

        formLayout = new QGridLayout();
        formLayout->setObjectName("formLayout");
        formLayout->setHorizontalSpacing(14);
        formLayout->setVerticalSpacing(6);
        fieldLabel1 = new QLabel(cardExtra2);
        fieldLabel1->setObjectName("fieldLabel1");

        formLayout->addWidget(fieldLabel1, 0, 0, 1, 1);

        fieldLabel2 = new QLabel(cardExtra2);
        fieldLabel2->setObjectName("fieldLabel2");

        formLayout->addWidget(fieldLabel2, 0, 1, 1, 1);

        fieldLabel3 = new QLabel(cardExtra2);
        fieldLabel3->setObjectName("fieldLabel3");

        formLayout->addWidget(fieldLabel3, 0, 2, 1, 1);

        fieldLabel4 = new QLabel(cardExtra2);
        fieldLabel4->setObjectName("fieldLabel4");

        formLayout->addWidget(fieldLabel4, 0, 3, 1, 1);

        fieldLabel5 = new QLabel(cardExtra2);
        fieldLabel5->setObjectName("fieldLabel5");

        formLayout->addWidget(fieldLabel5, 0, 4, 1, 1);

        idEvaluateurEdit = new QLineEdit(cardExtra2);
        idEvaluateurEdit->setObjectName("idEvaluateurEdit");

        formLayout->addWidget(idEvaluateurEdit, 1, 0, 1, 1);

        nomEdit = new QLineEdit(cardExtra2);
        nomEdit->setObjectName("nomEdit");

        formLayout->addWidget(nomEdit, 1, 1, 1, 1);

        prenomEdit = new QLineEdit(cardExtra2);
        prenomEdit->setObjectName("prenomEdit");

        formLayout->addWidget(prenomEdit, 1, 2, 1, 1);

        resultatEdit = new QLineEdit(cardExtra2);
        resultatEdit->setObjectName("resultatEdit");

        formLayout->addWidget(resultatEdit, 1, 3, 1, 1);

        statutCombo = new QComboBox(cardExtra2);
        statutCombo->addItem(QString());
        statutCombo->addItem(QString());
        statutCombo->addItem(QString());
        statutCombo->setObjectName("statutCombo");

        formLayout->addWidget(statutCombo, 1, 4, 1, 1);

        ajouterButton = new QPushButton(cardExtra2);
        ajouterButton->setObjectName("ajouterButton");

        formLayout->addWidget(ajouterButton, 1, 5, 1, 1);

        annulerButton = new QPushButton(cardExtra2);
        annulerButton->setObjectName("annulerButton");

        formLayout->addWidget(annulerButton, 1, 6, 1, 1);


        vboxLayout4->addLayout(formLayout);


        contentLayout->addWidget(cardExtra2);

        cardTable = new QFrame(content);
        cardTable->setObjectName("cardTable");
        vboxLayout5 = new QVBoxLayout(cardTable);
        vboxLayout5->setSpacing(12);
        vboxLayout5->setObjectName("vboxLayout5");
        vboxLayout5->setContentsMargins(20, 18, 20, 18);
        tableToolbar = new QHBoxLayout();
        tableToolbar->setObjectName("tableToolbar");
        sectionHeader2 = new QLabel(cardTable);
        sectionHeader2->setObjectName("sectionHeader2");

        tableToolbar->addWidget(sectionHeader2);

        toolbarSpacer = new QSpacerItem(80, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        tableToolbar->addItem(toolbarSpacer);

        rechercheEdit = new QLineEdit(cardTable);
        rechercheEdit->setObjectName("rechercheEdit");
        rechercheEdit->setMinimumSize(QSize(230, 0));

        tableToolbar->addWidget(rechercheEdit);

        rechercherButton = new QPushButton(cardTable);
        rechercherButton->setObjectName("rechercherButton");

        tableToolbar->addWidget(rechercherButton);

        trierButton = new QPushButton(cardTable);
        trierButton->setObjectName("trierButton");

        tableToolbar->addWidget(trierButton);

        exporterButton = new QPushButton(cardTable);
        exporterButton->setObjectName("exporterButton");

        tableToolbar->addWidget(exporterButton);


        vboxLayout5->addLayout(tableToolbar);

        evaluateursTable = new QTableWidget(cardTable);
        evaluateursTable->setObjectName("evaluateursTable");
        evaluateursTable->setMinimumSize(QSize(0, 250));
        evaluateursTable->setAlternatingRowColors(true);
        evaluateursTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        evaluateursTable->setSelectionMode(QAbstractItemView::SingleSelection);

        vboxLayout5->addWidget(evaluateursTable);


        contentLayout->addWidget(cardTable);

        businessLayout = new QHBoxLayout();
        businessLayout->setObjectName("businessLayout");
        business1 = new QPushButton(content);
        business1->setObjectName("business1");
        business1->setFlat(true);

        businessLayout->addWidget(business1);

        business2 = new QPushButton(content);
        business2->setObjectName("business2");
        business2->setFlat(true);

        businessLayout->addWidget(business2);

        businessSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        businessLayout->addItem(businessSpacer);

        footer = new QLabel(content);
        footer->setObjectName("footer");

        businessLayout->addWidget(footer);


        contentLayout->addLayout(businessLayout);


        mainLayout->addWidget(content);

        GestionEvaluateurs->setCentralWidget(centralwidget);

        retranslateUi(GestionEvaluateurs);

        QMetaObject::connectSlotsByName(GestionEvaluateurs);
    } // setupUi

    void retranslateUi(QMainWindow *GestionEvaluateurs)
    {
        GestionEvaluateurs->setWindowTitle(QCoreApplication::translate("GestionEvaluateurs", "Smart Hackathon Management \342\200\224 Gestion des \303\251valuateurs", nullptr));
        brand->setText(QCoreApplication::translate("GestionEvaluateurs", "Smart Hackathon", nullptr));
        brand2->setText(QCoreApplication::translate("GestionEvaluateurs", "Management", nullptr));
        sectionTitle->setText(QCoreApplication::translate("GestionEvaluateurs", "MENU PRINCIPAL", nullptr));
        navDashboard->setObjectName(QCoreApplication::translate("GestionEvaluateurs", "navButton", nullptr));
        navDashboard->setText(QCoreApplication::translate("GestionEvaluateurs", "\342\226\246   Tableau de Bord", nullptr));
        navEvaluateurs->setObjectName(QCoreApplication::translate("GestionEvaluateurs", "navActive", nullptr));
        navEvaluateurs->setText(QCoreApplication::translate("GestionEvaluateurs", "\342\227\217   Gestion des \303\251valuateurs", nullptr));
        navParticipants->setObjectName(QCoreApplication::translate("GestionEvaluateurs", "navButton", nullptr));
        navParticipants->setText(QCoreApplication::translate("GestionEvaluateurs", "\342\227\217   Gestion des participants", nullptr));
        navSponsors->setObjectName(QCoreApplication::translate("GestionEvaluateurs", "navButton", nullptr));
        navSponsors->setText(QCoreApplication::translate("GestionEvaluateurs", "\342\227\206   Gestion des sponsors", nullptr));
        navProjects->setObjectName(QCoreApplication::translate("GestionEvaluateurs", "navButton", nullptr));
        navProjects->setText(QCoreApplication::translate("GestionEvaluateurs", "\342\226\243   Gestion des projets", nullptr));
        navSales->setObjectName(QCoreApplication::translate("GestionEvaluateurs", "navButton", nullptr));
        navSales->setText(QCoreApplication::translate("GestionEvaluateurs", "\342\226\244   Gestion des salles", nullptr));
        separator->setStyleSheet(QCoreApplication::translate("GestionEvaluateurs", "color:#26375F;", nullptr));
        roleLabel->setText(QCoreApplication::translate("GestionEvaluateurs", "Connect\303\251 : Responsable", nullptr));
        roleLabel->setStyleSheet(QCoreApplication::translate("GestionEvaluateurs", "color:#AAB8D4;font-size:12px;", nullptr));
        logout->setText(QCoreApplication::translate("GestionEvaluateurs", "D\303\251connexion s\303\251curis\303\251e", nullptr));
        pageTitle->setText(QCoreApplication::translate("GestionEvaluateurs", "Gestion des \303\251valuateurs", nullptr));
        subtitle->setText(QCoreApplication::translate("GestionEvaluateurs", "Entit\303\251 : \303\251valuateur  \342\200\242  Utilisateurs : Responsables  \342\200\242  ", nullptr));
        metricTotalLabel->setText(QCoreApplication::translate("GestionEvaluateurs", "Nombre total d'\303\251valuateurs", nullptr));
        metricTotal->setText(QCoreApplication::translate("GestionEvaluateurs", "6", nullptr));
        metricActiveLabel->setText(QCoreApplication::translate("GestionEvaluateurs", "\303\211valuateurs actifs", nullptr));
        metricActive->setText(QCoreApplication::translate("GestionEvaluateurs", "4", nullptr));
        metricInactiveLabel->setText(QCoreApplication::translate("GestionEvaluateurs", "\303\211valuateurs inactifs", nullptr));
        metricInactive->setText(QCoreApplication::translate("GestionEvaluateurs", "2", nullptr));
        metricScoreLabel->setText(QCoreApplication::translate("GestionEvaluateurs", "R\303\251partition", nullptr));
        metricRepartitionActive->setText(QCoreApplication::translate("GestionEvaluateurs", "\342\227\217 Actifs : 67%", nullptr));
        metricRepartitionActive->setStyleSheet(QCoreApplication::translate("GestionEvaluateurs", "color:#198754;font-size:13px;font-weight:700;", nullptr));
        metricRepartitionInactive->setText(QCoreApplication::translate("GestionEvaluateurs", "\342\227\217 Inactifs : 33%", nullptr));
        metricRepartitionInactive->setStyleSheet(QCoreApplication::translate("GestionEvaluateurs", "color:#C43C3C;font-size:13px;font-weight:700;", nullptr));
        sectionHeader->setText(QCoreApplication::translate("GestionEvaluateurs", "Informations de l'\303\251valuateur", nullptr));
        fieldLabel1->setObjectName(QCoreApplication::translate("GestionEvaluateurs", "fieldLabel", nullptr));
        fieldLabel1->setText(QCoreApplication::translate("GestionEvaluateurs", "ID \303\251valuateur", nullptr));
        fieldLabel2->setObjectName(QCoreApplication::translate("GestionEvaluateurs", "fieldLabel", nullptr));
        fieldLabel2->setText(QCoreApplication::translate("GestionEvaluateurs", "Nom", nullptr));
        fieldLabel3->setObjectName(QCoreApplication::translate("GestionEvaluateurs", "fieldLabel", nullptr));
        fieldLabel3->setText(QCoreApplication::translate("GestionEvaluateurs", "Pr\303\251nom", nullptr));
        fieldLabel4->setObjectName(QCoreApplication::translate("GestionEvaluateurs", "fieldLabel", nullptr));
        fieldLabel4->setText(QCoreApplication::translate("GestionEvaluateurs", "R\303\251sultat", nullptr));
        fieldLabel5->setObjectName(QCoreApplication::translate("GestionEvaluateurs", "fieldLabel", nullptr));
        fieldLabel5->setText(QCoreApplication::translate("GestionEvaluateurs", "Statut", nullptr));
        idEvaluateurEdit->setPlaceholderText(QCoreApplication::translate("GestionEvaluateurs", "E004", nullptr));
        nomEdit->setPlaceholderText(QCoreApplication::translate("GestionEvaluateurs", "Nom", nullptr));
        prenomEdit->setPlaceholderText(QCoreApplication::translate("GestionEvaluateurs", "Pr\303\251nom", nullptr));
        resultatEdit->setPlaceholderText(QCoreApplication::translate("GestionEvaluateurs", "0 - 20", nullptr));
        statutCombo->setItemText(0, QCoreApplication::translate("GestionEvaluateurs", "S\303\251lectionner un statut", nullptr));
        statutCombo->setItemText(1, QCoreApplication::translate("GestionEvaluateurs", "Actifs", nullptr));
        statutCombo->setItemText(2, QCoreApplication::translate("GestionEvaluateurs", "Inactifs", nullptr));

        ajouterButton->setObjectName(QCoreApplication::translate("GestionEvaluateurs", "primary", nullptr));
        ajouterButton->setText(QCoreApplication::translate("GestionEvaluateurs", "Ajouter", nullptr));
        annulerButton->setObjectName(QCoreApplication::translate("GestionEvaluateurs", "secondary", nullptr));
        annulerButton->setText(QCoreApplication::translate("GestionEvaluateurs", "Annuler", nullptr));
        cardTable->setObjectName(QCoreApplication::translate("GestionEvaluateurs", "card", nullptr));
        sectionHeader2->setObjectName(QCoreApplication::translate("GestionEvaluateurs", "sectionHeader", nullptr));
        sectionHeader2->setText(QCoreApplication::translate("GestionEvaluateurs", "Liste des \303\251valuateurs", nullptr));
        rechercheEdit->setObjectName(QCoreApplication::translate("GestionEvaluateurs", "tableSearch", nullptr));
        rechercheEdit->setPlaceholderText(QCoreApplication::translate("GestionEvaluateurs", "Rechercher un \303\251valuateur...", nullptr));
        rechercherButton->setObjectName(QCoreApplication::translate("GestionEvaluateurs", "primary", nullptr));
        rechercherButton->setText(QCoreApplication::translate("GestionEvaluateurs", "Rechercher", nullptr));
        trierButton->setObjectName(QCoreApplication::translate("GestionEvaluateurs", "secondary", nullptr));
        trierButton->setText(QCoreApplication::translate("GestionEvaluateurs", "Trier", nullptr));
        exporterButton->setObjectName(QCoreApplication::translate("GestionEvaluateurs", "primary", nullptr));
        exporterButton->setText(QCoreApplication::translate("GestionEvaluateurs", "Exporter", nullptr));
        business1->setText(QCoreApplication::translate("GestionEvaluateurs", "\342\227\206  M\303\251tier 1 : Tech Challenge Analyst", nullptr));
        business1->setStyleSheet(QCoreApplication::translate("GestionEvaluateurs", "QPushButton{color:#1F65D6;font-weight:700;border:0;background:transparent;text-align:left;} QPushButton:hover{text-decoration:underline;}", nullptr));
        business2->setText(QCoreApplication::translate("GestionEvaluateurs", "\342\227\206  M\303\251tier 2 : D\303\251lib\303\251ration collaborative du jury", nullptr));
        business2->setStyleSheet(QCoreApplication::translate("GestionEvaluateurs", "QPushButton{color:#16804E;font-weight:700;border:0;background:transparent;text-align:left;} QPushButton:hover{text-decoration:underline;}", nullptr));
        footer->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class GestionEvaluateurs: public Ui_GestionEvaluateurs {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GESTIONEVALUATEURS_H
