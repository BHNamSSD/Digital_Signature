#ifndef DIGITAL_SIGNATURE_H
#define DIGITAL_SIGNATURE_H

#include <QApplication>
#include <QWidget>
#include <QLabel>
//#include <QDialog>
#include <QFileDialog>
#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QGroupBox>
#include <QMessageBox>
#include <QDir>
#include <QIODevice>
#include <QSslKey>
#include <QCryptographicHash>
#include <openssl/pem.h>
#include <openssl/rsa.h>
#include <QCoreApplication>
#include <QProcess>
#include <QTemporaryDir>
#include <QDesktopServices>
#include <QUrl>
#include <QTextStream>


//config
class DIGITAL_SIGNATURE : public QWidget
{
    Q_OBJECT

public:
    DIGITAL_SIGNATURE();
    ~DIGITAL_SIGNATURE();
    void showParent();
private:
    //QWidget *Total;
    //QWidget *fromLogo;
    //QWidget *fromCreateDigitalSignature;
    //QWidget *fromVerifyDigitalSignature;

    QDialog *fromCreateDigitalSignature;
    QDialog *fromVerifyDigitalSignature;

    QVBoxLayout *fromInterface;
    QPushButton *nut_logo;
    QPushButton *nut_CreateDigitalSignature;
    QPushButton *nut_VerifyDigitalSignature;
    QPushButton *nut_exit;

//=============================================
    //from Create
    //-----------------------------
    QPushButton *nut_ViewPathChooseApp_Create;
    QPushButton *nut_ChooseApp_Create;
    QString pathApp_Create;
    //-----------------------------

    //tao cap khoa---------------
    QPushButton *nut_ViewPathChoosePairKey_Create;
    QPushButton *nut_CreatePairKey_Create;
    QString pathFolderPairKey_Create;
    QString pathPrivateKey;
    QString pathPublicKey;
    //--------------------------

    //tao file chu ki so----------------
    QPushButton *nut_ViewPathSignDigitalSignature_Create;
    QPushButton *nut_SignDigitalSignature_Create;
    QString pathFolderSignDigitalSignature;
    QString pathSignature;
    //---------------------------------


    QPushButton *nut_ExitCreate;
    //path choose app







//=============================================
    //from Verify
    QPushButton *nut_ViewPathChooseApp_Verify;
    QPushButton *nut_ChooseApp_Verify;
    QString pathApp_Verify;

    QPushButton *nut_ViewPathChoosePublicKey_Verify;
    QPushButton *nut_ChoosePublicKey_Verify;
    QString pathFilePublicKey;

    QPushButton *nut_ViewPathChooseDigitalSignature;
    QPushButton *nut_ChooseDigitalSignature;
    QString pathFileSign;

    QPushButton *nut_CheckDigitalSignature;


    QPushButton *nut_ExitVerify;
    //path choose app




signals:

private slots:
    //void show_fromLogo();

    void connect_slot();

    void create_fromCreate();
    void create_fromVerify();
//==============================================
    void show_fromCreate();
    void show_fromVerify();

//slot from Create==============================
    void exit_fromCreate();
    void dialogBox_ChooseApp_Create();
    void dialogBox_ShowPathChooseApp_Create();

    void dialogBox_PairKey();
    void dialogBox_showPathPairKey();
    bool create_PrivateKey(QString &pathFolder);
    void create_PublicKey(QString &pathFolder);

    void dialogBox_signDigitalSignature();
    void showPathSignDigitalSignature();

    void signDigitalSignature();






//slot from Verify==============================
    void exit_fromVerity();
    void dialogBox_ChooseApp_Verify();
    void dialogBox_ShowPathChooseApp_Verify();

    void dialogBox_PublicKey_Verify();
    void dialogBox_showPathPublicKey_Verify();

    void dialogBox_ChoosePathSignDigitalSignature_Verify();
    void showPathSignDigitalSignature_Verify();

    void CheckDigitalSignature();






    //an hoac hien widget




    //void tb_ERRO();
    void tb_MESS();

    void exit_app();
    //void checkLogo();




};
#endif // DIGITAL_SIGNATURE_H
