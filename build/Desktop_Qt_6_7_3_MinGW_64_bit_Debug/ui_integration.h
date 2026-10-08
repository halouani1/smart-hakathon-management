/********************************************************************************
** Form generated from reading UI file 'integration.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTEGRATION_H
#define UI_INTEGRATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_integration
{
public:
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QWidget *pageLogin;
    QFrame *frameLoginCard;
    QFrame *frameLoginBrand;
    QLabel *labelLoginLogo;
    QLabel *labelLoginBrandTitle;
    QLabel *labelLoginBrandSub;
    QLabel *labelLoginBrandSlogan;
    QLabel *labelLoginBrandVersion;
    QLabel *labelLoginBrandTeam;
    QLabel *labelLoginTitle;
    QLabel *labelLoginSub;
    QLabel *labelLoginField;
    QLineEdit *lineEditIdentifiant;
    QLabel *labelLoginField2;
    QLineEdit *lineEditMotDePasse;
    QCheckBox *checkBoxSouvenir;
    QPushButton *pushButtonConnexion;
    QPushButton *pushButtonCGU;
    QPushButton *pushButtonPolitique;
    QPushButton *pushButtonAPropos;
    QLabel *labelLoginFooter;
    QWidget *pageSalles;
    QScrollArea *scrollSalles;
    QWidget *scrollSallesContent;
    QFrame *frameNavbar;
    QLabel *labelNavLogo;
    QLabel *labelNavBrand;
    QLabel *labelNavSub;
    QPushButton *btnDashboard;
    QPushButton *btnEmployes;
    QPushButton *btnSalles;
    QPushButton *btnEvaluateurs;
    QPushButton *btnParticipants;
    QPushButton *btnSponsors;
    QPushButton *btnProjets;
    QPushButton *btnNotifications;
    QPushButton *btnProfil;
    QPushButton *btnDeconnexion;
    QLabel *labelTitleSalles;
    QLabel *labelSubSalles;
    QFrame *cardFormSalles;
    QLabel *labelFormTitleSalles;
    QLabel *lblSalleID;
    QLineEdit *lineEditSalleID;
    QLabel *lblSalleNom;
    QLineEdit *lineEditSalleNom;
    QLabel *lblSalleCapacite;
    QSpinBox *spinBoxSalleCapacite;
    QLabel *lblSalleType;
    QComboBox *comboBoxSalleType;
    QLabel *lblSalleDispo;
    QComboBox *comboBoxSalleDispo;
    QPushButton *btnAjouterSalle;
    QPushButton *btnAnnuler;
    QLineEdit *lineEdit_2;
    QPushButton *btnRechercherSalle;
    QPushButton *btnTrierSalle;
    QPushButton *btnExporterSalle;
    QFrame *cardTableSalles;
    QTableWidget *tableSalles;
    QLabel *labelTableTitleSalles;
    QFrame *frameAffectation_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *lblTitreAffect_2;
    QLabel *lblDescAffect_2;
    QFrame *frameSaisieAffect_2;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *leEffectif_2;
    QPushButton *btnSuggerer_2;
    QFrame *frameQR_4;
    QVBoxLayout *verticalLayout_5;
    QLabel *lblTitreQR_4;
    QLabel *lblDescQR_4;
    QFrame *frameSaisieQR_4;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *leCodeQR_4;
    QPushButton *btnValiderQR_4;
    QFrame *cardStats;
    QLabel *labelStatsTitle;
    QLabel *labelStatutPie;
    QLabel *labelRoleBar;
    QLabel *labelFooterSalles;

    void setupUi(QMainWindow *integration)
    {
        if (integration->objectName().isEmpty())
            integration->setObjectName("integration");
        integration->resize(1440, 900);
        integration->setMinimumSize(QSize(1280, 720));
        centralWidget = new QWidget(integration);
        centralWidget->setObjectName("centralWidget");
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 0, 1440, 900));
        pageLogin = new QWidget();
        pageLogin->setObjectName("pageLogin");
        frameLoginCard = new QFrame(pageLogin);
        frameLoginCard->setObjectName("frameLoginCard");
        frameLoginCard->setGeometry(QRect(320, 140, 800, 620));
        frameLoginCard->setFrameShape(QFrame::Shape::StyledPanel);
        frameLoginCard->setFrameShadow(QFrame::Shadow::Raised);
        frameLoginBrand = new QFrame(pageLogin);
        frameLoginBrand->setObjectName("frameLoginBrand");
        frameLoginBrand->setGeometry(QRect(320, 140, 380, 620));
        frameLoginBrand->setFrameShape(QFrame::Shape::StyledPanel);
        frameLoginBrand->setFrameShadow(QFrame::Shadow::Raised);
        labelLoginLogo = new QLabel(pageLogin);
        labelLoginLogo->setObjectName("labelLoginLogo");
        labelLoginLogo->setGeometry(QRect(440, 220, 140, 140));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(48);
        font.setBold(true);
        labelLoginLogo->setFont(font);
        labelLoginLogo->setAlignment(Qt::AlignmentFlag::AlignCenter);
        labelLoginBrandTitle = new QLabel(pageLogin);
        labelLoginBrandTitle->setObjectName("labelLoginBrandTitle");
        labelLoginBrandTitle->setGeometry(QRect(340, 390, 340, 50));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        font1.setPointSize(28);
        font1.setBold(true);
        labelLoginBrandTitle->setFont(font1);
        labelLoginBrandTitle->setAlignment(Qt::AlignmentFlag::AlignCenter);
        labelLoginBrandSub = new QLabel(pageLogin);
        labelLoginBrandSub->setObjectName("labelLoginBrandSub");
        labelLoginBrandSub->setGeometry(QRect(340, 440, 340, 25));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Arial")});
        font2.setPointSize(10);
        font2.setBold(true);
        labelLoginBrandSub->setFont(font2);
        labelLoginBrandSub->setAlignment(Qt::AlignmentFlag::AlignCenter);
        labelLoginBrandSlogan = new QLabel(pageLogin);
        labelLoginBrandSlogan->setObjectName("labelLoginBrandSlogan");
        labelLoginBrandSlogan->setGeometry(QRect(360, 500, 300, 80));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Times New Roman")});
        font3.setPointSize(12);
        labelLoginBrandSlogan->setFont(font3);
        labelLoginBrandSlogan->setAlignment(Qt::AlignmentFlag::AlignCenter);
        labelLoginBrandSlogan->setWordWrap(true);
        labelLoginBrandVersion = new QLabel(pageLogin);
        labelLoginBrandVersion->setObjectName("labelLoginBrandVersion");
        labelLoginBrandVersion->setGeometry(QRect(420, 670, 180, 20));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Arial")});
        font4.setPointSize(9);
        labelLoginBrandVersion->setFont(font4);
        labelLoginBrandVersion->setAlignment(Qt::AlignmentFlag::AlignCenter);
        labelLoginBrandTeam = new QLabel(pageLogin);
        labelLoginBrandTeam->setObjectName("labelLoginBrandTeam");
        labelLoginBrandTeam->setGeometry(QRect(420, 690, 180, 20));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Arial")});
        font5.setPointSize(9);
        font5.setBold(true);
        labelLoginBrandTeam->setFont(font5);
        labelLoginBrandTeam->setAlignment(Qt::AlignmentFlag::AlignCenter);
        labelLoginTitle = new QLabel(pageLogin);
        labelLoginTitle->setObjectName("labelLoginTitle");
        labelLoginTitle->setGeometry(QRect(780, 220, 280, 40));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Arial")});
        font6.setPointSize(24);
        font6.setBold(true);
        labelLoginTitle->setFont(font6);
        labelLoginSub = new QLabel(pageLogin);
        labelLoginSub->setObjectName("labelLoginSub");
        labelLoginSub->setGeometry(QRect(780, 265, 320, 30));
        QFont font7;
        font7.setFamilies({QString::fromUtf8("Times New Roman")});
        font7.setPointSize(11);
        labelLoginSub->setFont(font7);
        labelLoginSub->setWordWrap(true);
        labelLoginField = new QLabel(pageLogin);
        labelLoginField->setObjectName("labelLoginField");
        labelLoginField->setGeometry(QRect(780, 340, 200, 20));
        labelLoginField->setFont(font2);
        lineEditIdentifiant = new QLineEdit(pageLogin);
        lineEditIdentifiant->setObjectName("lineEditIdentifiant");
        lineEditIdentifiant->setGeometry(QRect(780, 365, 320, 45));
        lineEditIdentifiant->setFont(font7);
        labelLoginField2 = new QLabel(pageLogin);
        labelLoginField2->setObjectName("labelLoginField2");
        labelLoginField2->setGeometry(QRect(780, 430, 200, 20));
        labelLoginField2->setFont(font2);
        lineEditMotDePasse = new QLineEdit(pageLogin);
        lineEditMotDePasse->setObjectName("lineEditMotDePasse");
        lineEditMotDePasse->setGeometry(QRect(780, 455, 320, 45));
        lineEditMotDePasse->setFont(font7);
        lineEditMotDePasse->setEchoMode(QLineEdit::EchoMode::Password);
        checkBoxSouvenir = new QCheckBox(pageLogin);
        checkBoxSouvenir->setObjectName("checkBoxSouvenir");
        checkBoxSouvenir->setGeometry(QRect(780, 515, 200, 25));
        QFont font8;
        font8.setFamilies({QString::fromUtf8("Times New Roman")});
        font8.setPointSize(10);
        checkBoxSouvenir->setFont(font8);
        pushButtonConnexion = new QPushButton(pageLogin);
        pushButtonConnexion->setObjectName("pushButtonConnexion");
        pushButtonConnexion->setGeometry(QRect(780, 555, 320, 50));
        QFont font9;
        font9.setFamilies({QString::fromUtf8("Arial")});
        font9.setPointSize(12);
        font9.setBold(true);
        pushButtonConnexion->setFont(font9);
        pushButtonConnexion->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButtonCGU = new QPushButton(pageLogin);
        pushButtonCGU->setObjectName("pushButtonCGU");
        pushButtonCGU->setGeometry(QRect(780, 630, 320, 25));
        pushButtonCGU->setFont(font8);
        pushButtonCGU->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButtonPolitique = new QPushButton(pageLogin);
        pushButtonPolitique->setObjectName("pushButtonPolitique");
        pushButtonPolitique->setGeometry(QRect(780, 655, 320, 25));
        pushButtonPolitique->setFont(font8);
        pushButtonPolitique->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        pushButtonAPropos = new QPushButton(pageLogin);
        pushButtonAPropos->setObjectName("pushButtonAPropos");
        pushButtonAPropos->setGeometry(QRect(780, 680, 320, 25));
        pushButtonAPropos->setFont(font8);
        pushButtonAPropos->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        labelLoginFooter = new QLabel(pageLogin);
        labelLoginFooter->setObjectName("labelLoginFooter");
        labelLoginFooter->setGeometry(QRect(780, 720, 320, 20));
        QFont font10;
        font10.setFamilies({QString::fromUtf8("Times New Roman")});
        font10.setPointSize(8);
        labelLoginFooter->setFont(font10);
        labelLoginFooter->setAlignment(Qt::AlignmentFlag::AlignCenter);
        stackedWidget->addWidget(pageLogin);
        pageSalles = new QWidget();
        pageSalles->setObjectName("pageSalles");
        scrollSalles = new QScrollArea(pageSalles);
        scrollSalles->setObjectName("scrollSalles");
        scrollSalles->setGeometry(QRect(0, 0, 1440, 900));
        scrollSalles->setFrameShape(QFrame::Shape::NoFrame);
        scrollSalles->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAsNeeded);
        scrollSalles->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        scrollSalles->setWidgetResizable(false);
        scrollSallesContent = new QWidget();
        scrollSallesContent->setObjectName("scrollSallesContent");
        scrollSallesContent->setGeometry(QRect(0, 0, 1420, 1000));
        frameNavbar = new QFrame(scrollSallesContent);
        frameNavbar->setObjectName("frameNavbar");
        frameNavbar->setGeometry(QRect(9, 10, 1401, 76));
        frameNavbar->setFrameShape(QFrame::Shape::StyledPanel);
        frameNavbar->setFrameShadow(QFrame::Shadow::Raised);
        labelNavLogo = new QLabel(frameNavbar);
        labelNavLogo->setObjectName("labelNavLogo");
        labelNavLogo->setGeometry(QRect(10, 10, 61, 61));
        QFont font11;
        font11.setFamilies({QString::fromUtf8("Arial")});
        font11.setPointSize(13);
        font11.setBold(true);
        labelNavLogo->setFont(font11);
        labelNavLogo->setAlignment(Qt::AlignmentFlag::AlignCenter);
        labelNavBrand = new QLabel(scrollSallesContent);
        labelNavBrand->setObjectName("labelNavBrand");
        labelNavBrand->setGeometry(QRect(90, 20, 140, 28));
        labelNavBrand->setFont(font11);
        labelNavSub = new QLabel(scrollSallesContent);
        labelNavSub->setObjectName("labelNavSub");
        labelNavSub->setGeometry(QRect(90, 50, 140, 18));
        QFont font12;
        font12.setFamilies({QString::fromUtf8("Arial")});
        font12.setPointSize(8);
        font12.setBold(true);
        labelNavSub->setFont(font12);
        btnDashboard = new QPushButton(scrollSallesContent);
        btnDashboard->setObjectName("btnDashboard");
        btnDashboard->setGeometry(QRect(230, 30, 130, 40));
        btnDashboard->setFont(font12);
        btnDashboard->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnEmployes = new QPushButton(scrollSallesContent);
        btnEmployes->setObjectName("btnEmployes");
        btnEmployes->setGeometry(QRect(370, 30, 100, 40));
        btnEmployes->setFont(font12);
        btnEmployes->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnSalles = new QPushButton(scrollSallesContent);
        btnSalles->setObjectName("btnSalles");
        btnSalles->setGeometry(QRect(480, 30, 100, 40));
        btnSalles->setFont(font12);
        btnSalles->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnEvaluateurs = new QPushButton(scrollSallesContent);
        btnEvaluateurs->setObjectName("btnEvaluateurs");
        btnEvaluateurs->setGeometry(QRect(590, 30, 130, 40));
        btnEvaluateurs->setFont(font12);
        btnEvaluateurs->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnParticipants = new QPushButton(scrollSallesContent);
        btnParticipants->setObjectName("btnParticipants");
        btnParticipants->setGeometry(QRect(730, 30, 130, 40));
        btnParticipants->setFont(font12);
        btnParticipants->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnSponsors = new QPushButton(scrollSallesContent);
        btnSponsors->setObjectName("btnSponsors");
        btnSponsors->setGeometry(QRect(870, 30, 110, 40));
        btnSponsors->setFont(font12);
        btnSponsors->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnProjets = new QPushButton(scrollSallesContent);
        btnProjets->setObjectName("btnProjets");
        btnProjets->setGeometry(QRect(990, 30, 100, 40));
        btnProjets->setFont(font12);
        btnProjets->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnNotifications = new QPushButton(scrollSallesContent);
        btnNotifications->setObjectName("btnNotifications");
        btnNotifications->setGeometry(QRect(1100, 30, 110, 40));
        btnNotifications->setFont(font12);
        btnNotifications->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnProfil = new QPushButton(scrollSallesContent);
        btnProfil->setObjectName("btnProfil");
        btnProfil->setGeometry(QRect(1215, 30, 80, 40));
        btnProfil->setFont(font12);
        btnProfil->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnDeconnexion = new QPushButton(scrollSallesContent);
        btnDeconnexion->setObjectName("btnDeconnexion");
        btnDeconnexion->setGeometry(QRect(1300, 30, 101, 40));
        btnDeconnexion->setFont(font12);
        btnDeconnexion->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        labelTitleSalles = new QLabel(scrollSallesContent);
        labelTitleSalles->setObjectName("labelTitleSalles");
        labelTitleSalles->setGeometry(QRect(10, 100, 600, 36));
        QFont font13;
        font13.setFamilies({QString::fromUtf8("Arial")});
        font13.setPointSize(18);
        font13.setBold(true);
        labelTitleSalles->setFont(font13);
        labelSubSalles = new QLabel(scrollSallesContent);
        labelSubSalles->setObjectName("labelSubSalles");
        labelSubSalles->setGeometry(QRect(20, 140, 800, 22));
        labelSubSalles->setFont(font7);
        cardFormSalles = new QFrame(scrollSallesContent);
        cardFormSalles->setObjectName("cardFormSalles");
        cardFormSalles->setGeometry(QRect(10, 170, 1391, 181));
        cardFormSalles->setFrameShape(QFrame::Shape::StyledPanel);
        cardFormSalles->setFrameShadow(QFrame::Shadow::Raised);
        labelFormTitleSalles = new QLabel(scrollSallesContent);
        labelFormTitleSalles->setObjectName("labelFormTitleSalles");
        labelFormTitleSalles->setGeometry(QRect(30, 180, 500, 25));
        labelFormTitleSalles->setFont(font11);
        lblSalleID = new QLabel(scrollSallesContent);
        lblSalleID->setObjectName("lblSalleID");
        lblSalleID->setGeometry(QRect(50, 220, 120, 18));
        lblSalleID->setFont(font5);
        lineEditSalleID = new QLineEdit(scrollSallesContent);
        lineEditSalleID->setObjectName("lineEditSalleID");
        lineEditSalleID->setGeometry(QRect(40, 240, 150, 40));
        lineEditSalleID->setReadOnly(true);
        lblSalleNom = new QLabel(scrollSallesContent);
        lblSalleNom->setObjectName("lblSalleNom");
        lblSalleNom->setGeometry(QRect(230, 220, 120, 18));
        lblSalleNom->setFont(font5);
        lineEditSalleNom = new QLineEdit(scrollSallesContent);
        lineEditSalleNom->setObjectName("lineEditSalleNom");
        lineEditSalleNom->setGeometry(QRect(230, 240, 220, 40));
        lblSalleCapacite = new QLabel(scrollSallesContent);
        lblSalleCapacite->setObjectName("lblSalleCapacite");
        lblSalleCapacite->setGeometry(QRect(480, 220, 120, 18));
        lblSalleCapacite->setFont(font5);
        spinBoxSalleCapacite = new QSpinBox(scrollSallesContent);
        spinBoxSalleCapacite->setObjectName("spinBoxSalleCapacite");
        spinBoxSalleCapacite->setGeometry(QRect(480, 240, 150, 40));
        spinBoxSalleCapacite->setMaximum(9999);
        lblSalleType = new QLabel(scrollSallesContent);
        lblSalleType->setObjectName("lblSalleType");
        lblSalleType->setGeometry(QRect(660, 220, 140, 18));
        lblSalleType->setFont(font5);
        comboBoxSalleType = new QComboBox(scrollSallesContent);
        comboBoxSalleType->addItem(QString());
        comboBoxSalleType->addItem(QString());
        comboBoxSalleType->addItem(QString());
        comboBoxSalleType->addItem(QString());
        comboBoxSalleType->addItem(QString());
        comboBoxSalleType->setObjectName("comboBoxSalleType");
        comboBoxSalleType->setGeometry(QRect(660, 240, 220, 40));
        lblSalleDispo = new QLabel(scrollSallesContent);
        lblSalleDispo->setObjectName("lblSalleDispo");
        lblSalleDispo->setGeometry(QRect(900, 220, 140, 18));
        lblSalleDispo->setFont(font5);
        comboBoxSalleDispo = new QComboBox(scrollSallesContent);
        comboBoxSalleDispo->addItem(QString());
        comboBoxSalleDispo->addItem(QString());
        comboBoxSalleDispo->addItem(QString());
        comboBoxSalleDispo->setObjectName("comboBoxSalleDispo");
        comboBoxSalleDispo->setGeometry(QRect(900, 240, 200, 40));
        btnAjouterSalle = new QPushButton(scrollSallesContent);
        btnAjouterSalle->setObjectName("btnAjouterSalle");
        btnAjouterSalle->setGeometry(QRect(40, 300, 120, 40));
        btnAjouterSalle->setFont(font2);
        btnAjouterSalle->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnAnnuler = new QPushButton(scrollSallesContent);
        btnAnnuler->setObjectName("btnAnnuler");
        btnAnnuler->setGeometry(QRect(180, 300, 120, 40));
        btnAnnuler->setFont(font2);
        btnAnnuler->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        lineEdit_2 = new QLineEdit(scrollSallesContent);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(10, 360, 351, 51));
        btnRechercherSalle = new QPushButton(scrollSallesContent);
        btnRechercherSalle->setObjectName("btnRechercherSalle");
        btnRechercherSalle->setGeometry(QRect(380, 360, 130, 51));
        btnRechercherSalle->setFont(font2);
        btnRechercherSalle->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnTrierSalle = new QPushButton(scrollSallesContent);
        btnTrierSalle->setObjectName("btnTrierSalle");
        btnTrierSalle->setGeometry(QRect(530, 359, 120, 51));
        btnTrierSalle->setFont(font2);
        btnTrierSalle->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        btnExporterSalle = new QPushButton(scrollSallesContent);
        btnExporterSalle->setObjectName("btnExporterSalle");
        btnExporterSalle->setGeometry(QRect(670, 359, 130, 51));
        btnExporterSalle->setFont(font2);
        btnExporterSalle->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        cardTableSalles = new QFrame(scrollSallesContent);
        cardTableSalles->setObjectName("cardTableSalles");
        cardTableSalles->setGeometry(QRect(10, 420, 801, 461));
        cardTableSalles->setFrameShape(QFrame::Shape::StyledPanel);
        cardTableSalles->setFrameShadow(QFrame::Shadow::Raised);
        tableSalles = new QTableWidget(cardTableSalles);
        if (tableSalles->columnCount() < 6)
            tableSalles->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableSalles->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableSalles->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableSalles->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableSalles->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableSalles->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableSalles->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tableSalles->setObjectName("tableSalles");
        tableSalles->setGeometry(QRect(20, 50, 761, 391));
        tableSalles->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        tableSalles->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
        labelTableTitleSalles = new QLabel(cardTableSalles);
        labelTableTitleSalles->setObjectName("labelTableTitleSalles");
        labelTableTitleSalles->setGeometry(QRect(20, 10, 500, 25));
        labelTableTitleSalles->setFont(font11);
        frameAffectation_2 = new QFrame(scrollSallesContent);
        frameAffectation_2->setObjectName("frameAffectation_2");
        frameAffectation_2->setGeometry(QRect(830, 420, 571, 220));
        frameAffectation_2->setFrameShape(QFrame::Shape::Box);
        frameAffectation_2->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_2 = new QVBoxLayout(frameAffectation_2);
        verticalLayout_2->setSpacing(10);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(15, 15, 15, 15);
        lblTitreAffect_2 = new QLabel(frameAffectation_2);
        lblTitreAffect_2->setObjectName("lblTitreAffect_2");
        QFont font14;
        font14.setPointSize(11);
        font14.setBold(true);
        lblTitreAffect_2->setFont(font14);
        lblTitreAffect_2->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_2->addWidget(lblTitreAffect_2);

        lblDescAffect_2 = new QLabel(frameAffectation_2);
        lblDescAffect_2->setObjectName("lblDescAffect_2");
        lblDescAffect_2->setWordWrap(true);

        verticalLayout_2->addWidget(lblDescAffect_2);

        frameSaisieAffect_2 = new QFrame(frameAffectation_2);
        frameSaisieAffect_2->setObjectName("frameSaisieAffect_2");
        frameSaisieAffect_2->setFrameShape(QFrame::Shape::Box);
        horizontalLayout_2 = new QHBoxLayout(frameSaisieAffect_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        leEffectif_2 = new QLineEdit(frameSaisieAffect_2);
        leEffectif_2->setObjectName("leEffectif_2");

        horizontalLayout_2->addWidget(leEffectif_2);

        btnSuggerer_2 = new QPushButton(frameSaisieAffect_2);
        btnSuggerer_2->setObjectName("btnSuggerer_2");

        horizontalLayout_2->addWidget(btnSuggerer_2);


        verticalLayout_2->addWidget(frameSaisieAffect_2);

        frameQR_4 = new QFrame(scrollSallesContent);
        frameQR_4->setObjectName("frameQR_4");
        frameQR_4->setGeometry(QRect(830, 650, 571, 220));
        frameQR_4->setFrameShape(QFrame::Shape::Box);
        frameQR_4->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_5 = new QVBoxLayout(frameQR_4);
        verticalLayout_5->setSpacing(10);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(15, 15, 15, 15);
        lblTitreQR_4 = new QLabel(frameQR_4);
        lblTitreQR_4->setObjectName("lblTitreQR_4");
        lblTitreQR_4->setFont(font14);
        lblTitreQR_4->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_5->addWidget(lblTitreQR_4);

        lblDescQR_4 = new QLabel(frameQR_4);
        lblDescQR_4->setObjectName("lblDescQR_4");
        lblDescQR_4->setWordWrap(true);

        verticalLayout_5->addWidget(lblDescQR_4);

        frameSaisieQR_4 = new QFrame(frameQR_4);
        frameSaisieQR_4->setObjectName("frameSaisieQR_4");
        frameSaisieQR_4->setFrameShape(QFrame::Shape::Box);
        horizontalLayout_5 = new QHBoxLayout(frameSaisieQR_4);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        leCodeQR_4 = new QLineEdit(frameSaisieQR_4);
        leCodeQR_4->setObjectName("leCodeQR_4");

        horizontalLayout_5->addWidget(leCodeQR_4);

        btnValiderQR_4 = new QPushButton(frameSaisieQR_4);
        btnValiderQR_4->setObjectName("btnValiderQR_4");

        horizontalLayout_5->addWidget(btnValiderQR_4);


        verticalLayout_5->addWidget(frameSaisieQR_4);

        cardStats = new QFrame(scrollSallesContent);
        cardStats->setObjectName("cardStats");
        cardStats->setGeometry(QRect(830, 200, 571, 210));
        cardStats->setFrameShape(QFrame::Shape::Box);
        cardStats->setFrameShadow(QFrame::Shadow::Raised);
        labelStatsTitle = new QLabel(cardStats);
        labelStatsTitle->setObjectName("labelStatsTitle");
        labelStatsTitle->setGeometry(QRect(15, 8, 400, 25));
        QFont font15;
        font15.setFamilies({QString::fromUtf8("Arial")});
        font15.setPointSize(11);
        font15.setBold(true);
        labelStatsTitle->setFont(font15);
        labelStatutPie = new QLabel(cardStats);
        labelStatutPie->setObjectName("labelStatutPie");
        labelStatutPie->setGeometry(QRect(10, 35, 240, 170));
        labelRoleBar = new QLabel(cardStats);
        labelRoleBar->setObjectName("labelRoleBar");
        labelRoleBar->setGeometry(QRect(255, 35, 305, 170));
        labelFooterSalles = new QLabel(scrollSallesContent);
        labelFooterSalles->setObjectName("labelFooterSalles");
        labelFooterSalles->setGeometry(QRect(40, 930, 900, 20));
        QFont font16;
        font16.setFamilies({QString::fromUtf8("Times New Roman")});
        font16.setPointSize(9);
        labelFooterSalles->setFont(font16);
        scrollSalles->setWidget(scrollSallesContent);
        stackedWidget->addWidget(pageSalles);
        integration->setCentralWidget(centralWidget);

        retranslateUi(integration);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(integration);
    } // setupUi

    void retranslateUi(QMainWindow *integration)
    {
        integration->setWindowTitle(QCoreApplication::translate("integration", "HACKNOVA \342\200\224 Smart Hackathon Management", nullptr));
        labelLoginLogo->setText(QCoreApplication::translate("integration", "HN", nullptr));
        labelLoginBrandTitle->setText(QCoreApplication::translate("integration", "HACKNOVA", nullptr));
        labelLoginBrandSub->setText(QCoreApplication::translate("integration", "SMART HACKATHON MANAGEMENT", nullptr));
        labelLoginBrandSlogan->setText(QCoreApplication::translate("integration", "Plateforme intelligente de gestion de hackathons universitaires.", nullptr));
        labelLoginBrandVersion->setText(QCoreApplication::translate("integration", "VERSION 1.0.0", nullptr));
        labelLoginBrandTeam->setText(QCoreApplication::translate("integration", "GROUPE EL FALLEGA", nullptr));
        labelLoginTitle->setText(QCoreApplication::translate("integration", "Bienvenue", nullptr));
        labelLoginSub->setText(QCoreApplication::translate("integration", "Connectez-vous pour acc\303\251der \303\240 votre espace.", nullptr));
        labelLoginField->setText(QCoreApplication::translate("integration", "IDENTIFIANT", nullptr));
        lineEditIdentifiant->setPlaceholderText(QCoreApplication::translate("integration", "Entrez votre identifiant", nullptr));
        labelLoginField2->setText(QCoreApplication::translate("integration", "MOT DE PASSE", nullptr));
        lineEditMotDePasse->setPlaceholderText(QCoreApplication::translate("integration", "Entrez votre mot de passe", nullptr));
        checkBoxSouvenir->setText(QCoreApplication::translate("integration", "Se souvenir de moi", nullptr));
        pushButtonConnexion->setText(QCoreApplication::translate("integration", "SE CONNECTER", nullptr));
        pushButtonCGU->setText(QCoreApplication::translate("integration", "Conditions g\303\251n\303\251rales d'utilisation", nullptr));
        pushButtonPolitique->setText(QCoreApplication::translate("integration", "Politique d'utilisation", nullptr));
        pushButtonAPropos->setText(QCoreApplication::translate("integration", "\303\200 propos de HACKNOVA", nullptr));
        labelLoginFooter->setText(QCoreApplication::translate("integration", "\302\251 2025 HACKNOVA \342\200\224 Tous droits r\303\251serv\303\251s", nullptr));
        labelNavLogo->setText(QString());
        labelNavBrand->setText(QCoreApplication::translate("integration", "HACKNOVA", nullptr));
        labelNavSub->setText(QCoreApplication::translate("integration", "SMART HACKATHON", nullptr));
        btnDashboard->setText(QCoreApplication::translate("integration", "TABLEAU DE BORD", nullptr));
        btnEmployes->setText(QCoreApplication::translate("integration", "\360\237\221\244 EMPLOY\303\211S", nullptr));
        btnSalles->setText(QCoreApplication::translate("integration", "\360\237\217\233 SALLES", nullptr));
        btnEvaluateurs->setText(QCoreApplication::translate("integration", "\360\237\223\212 \303\211VALUATEURS", nullptr));
        btnParticipants->setText(QCoreApplication::translate("integration", "\360\237\221\245 PARTICIPANTS", nullptr));
        btnSponsors->setText(QCoreApplication::translate("integration", "\360\237\244\235 SPONSORS", nullptr));
        btnProjets->setText(QCoreApplication::translate("integration", "\360\237\222\241 PROJETS", nullptr));
        btnNotifications->setText(QCoreApplication::translate("integration", "NOTIFICATIONS", nullptr));
        btnProfil->setText(QCoreApplication::translate("integration", "PROFIL", nullptr));
        btnDeconnexion->setText(QCoreApplication::translate("integration", "D\303\211CONNEXION", nullptr));
        labelTitleSalles->setText(QCoreApplication::translate("integration", "\360\237\217\233 Gestion des salles", nullptr));
        labelSubSalles->setText(QCoreApplication::translate("integration", "Planifiez et optimisez les espaces du hackathon", nullptr));
        labelFormTitleSalles->setText(QCoreApplication::translate("integration", "Ajouter une salle", nullptr));
        lblSalleID->setText(QCoreApplication::translate("integration", "ID SALLE", nullptr));
        lineEditSalleID->setPlaceholderText(QCoreApplication::translate("integration", "Auto", nullptr));
        lblSalleNom->setText(QCoreApplication::translate("integration", "NOM SALLE", nullptr));
        lineEditSalleNom->setPlaceholderText(QCoreApplication::translate("integration", "Nom de la salle", nullptr));
        lblSalleCapacite->setText(QCoreApplication::translate("integration", "CAPACIT\303\211", nullptr));
        lblSalleType->setText(QCoreApplication::translate("integration", "TYPE SALLE", nullptr));
        comboBoxSalleType->setItemText(0, QCoreApplication::translate("integration", "Salle informatique", nullptr));
        comboBoxSalleType->setItemText(1, QCoreApplication::translate("integration", "Salle de r\303\251union", nullptr));
        comboBoxSalleType->setItemText(2, QCoreApplication::translate("integration", "Salle conf\303\251rence", nullptr));
        comboBoxSalleType->setItemText(3, QCoreApplication::translate("integration", "Laboratoire", nullptr));
        comboBoxSalleType->setItemText(4, QCoreApplication::translate("integration", "Autre", nullptr));

        lblSalleDispo->setText(QCoreApplication::translate("integration", "DISPONIBILIT\303\211", nullptr));
        comboBoxSalleDispo->setItemText(0, QCoreApplication::translate("integration", "Disponible", nullptr));
        comboBoxSalleDispo->setItemText(1, QCoreApplication::translate("integration", "Occup\303\251e", nullptr));
        comboBoxSalleDispo->setItemText(2, QCoreApplication::translate("integration", "Maintenance", nullptr));

        btnAjouterSalle->setText(QCoreApplication::translate("integration", "AJOUTER", nullptr));
        btnAnnuler->setText(QCoreApplication::translate("integration", "ANNULER", nullptr));
        lineEdit_2->setPlaceholderText(QCoreApplication::translate("integration", "Rechercher une salle", nullptr));
        btnRechercherSalle->setText(QCoreApplication::translate("integration", "RECHERCHER", nullptr));
        btnTrierSalle->setText(QCoreApplication::translate("integration", "TRIER", nullptr));
        btnExporterSalle->setText(QCoreApplication::translate("integration", "EXPORTER", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableSalles->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("integration", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableSalles->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("integration", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableSalles->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("integration", "Capacit\303\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableSalles->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("integration", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableSalles->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("integration", "Disponibilit\303\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableSalles->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("integration", "Action", nullptr));
        labelTableTitleSalles->setText(QCoreApplication::translate("integration", "Liste des salles", nullptr));
        lblTitreAffect_2->setText(QCoreApplication::translate("integration", "Affectation intelligente des salles \302\267 Automatique", nullptr));
        lblDescAffect_2->setText(QCoreApplication::translate("integration", "  Proposer la meilleure salle selon l'effectif\n"
"  D\303\251tecter les conflits de cr\303\251neaux\n"
"  R\303\251affecter automatiquement en cas de maintenance", nullptr));
        leEffectif_2->setPlaceholderText(QCoreApplication::translate("integration", "Effectif de l'\303\251quipe (ex. 6)", nullptr));
        btnSuggerer_2->setText(QCoreApplication::translate("integration", "Sugg\303\251rer", nullptr));
        lblTitreQR_4->setText(QCoreApplication::translate("integration", "QR Code \302\267 Acc\303\250s et pr\303\251sence", nullptr));
        lblDescQR_4->setText(QCoreApplication::translate("integration", "G\303\251n\303\251rer le QR code de chaque salle\n"
"V\303\251rifier l'acc\303\250s et la pr\303\251sence des \303\251quipes\n"
"Suivre l'occupation en temps r\303\251el", nullptr));
        leCodeQR_4->setPlaceholderText(QCoreApplication::translate("integration", "Scannez ou saisissez le code", nullptr));
        btnValiderQR_4->setText(QCoreApplication::translate("integration", "Valider", nullptr));
        labelStatsTitle->setText(QCoreApplication::translate("integration", "\360\237\223\212 Statistiques des salles", nullptr));
        labelStatutPie->setText(QString());
        labelRoleBar->setText(QString());
        labelFooterSalles->setText(QCoreApplication::translate("integration", "HACKNOVA \342\200\224 Smart Hackathon Management \342\200\224 Version 1.0.0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class integration: public Ui_integration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTEGRATION_H
