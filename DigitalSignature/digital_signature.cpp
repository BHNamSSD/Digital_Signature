#include "digital_signature.h"

DIGITAL_SIGNATURE::DIGITAL_SIGNATURE()
    : QWidget()
{
    //Total = new QWidget(this);
    //Total->setFixedSize(600,400);
    this->setFixedSize(600,400);
    fromInterface = new QVBoxLayout(this);
    //tao widget create va verify====================================================
    create_fromCreate();
    create_fromVerify();
    //create group 1 la logo-------------------------------------------------------
    QPixmap logoImage("D:\\BHNam_QT\\app_QT\\DigitalSignature\\DigitalSignature\\logo\\logo.png");
    QIcon logoIcon(logoImage);
    nut_logo = new QPushButton("");
    nut_logo->setIcon(logoIcon);
    nut_logo->setIconSize(QSize(150,150));
    nut_logo->setFixedSize(150, 150);
    //logo->setFixedWidth(300);
    nut_logo->setFixedHeight(150);
    //tieng viet
    //QString content = "Chữ ký số (digital signature) là một kỹ thuật mật mã được sử dụng để\n"
    //                  "xác minh tính xác thực và tính toàn vẹn của các tin nhắn hoặc tài liệu số.\n"
    //                  "Chữ ký số hoạt động:\n"
    //                  "+ Băm: tạo giá trị băm của tin nhăn hoặc tài liệu cần ký.\n"
    //                  "+ Tạo cặp khóa: gồm khóa bí mật và khóa công khai.\n"
    //                  "+ Xác minh giá trị băm: tính giá
    //trị băm và giải mã chữ ký số.\n"
    //                  "+ So sánh: giá trị băm khớp với giá trị băm từ chữ ký số.";
    //english
    QString content = "A digital signature is a cryptographic technique used\n"
                      "to verify the authenticity and integrity of digital messages or documents\n"
                      "Digital signatures operate as follows:\n"
                      "+ Hashing: Creating a hash value of the message or document to be signed.\n"
                      "+ Key pair generation: Consisting of a private key and a public key.\n"
                      "+ Verifying the hash value: Calculating the hash value and decrypting the\ndigital signature.\n"
                      "+ Comparison: Matching the hash value with the hash value from the digital\nsignature.";


    QLabel *text = new QLabel(content);


    QWidget *wid_logoContent = new QWidget();
    QHBoxLayout *logo_textContent = new QHBoxLayout(wid_logoContent);
    logo_textContent->addWidget(nut_logo);
    logo_textContent->addWidget(text);

    fromInterface->addWidget(wid_logoContent);


    //create group 2 la 2 nut bam-----------------------------------------------
    QGroupBox *group_2 = new QGroupBox("Option:");
    QVBoxLayout *group_2_layout = new QVBoxLayout;


    QWidget *wid_Create = new QWidget();
    QWidget *wid_Verity = new QWidget();

    QHBoxLayout *group_CreateDigitalSignature = new QHBoxLayout(wid_Create);
    QHBoxLayout *group_VerifyDigitalSignature = new QHBoxLayout(wid_Verity);


    QLabel *Create = new QLabel("Create Digital Signature");
    QLabel *Verify = new QLabel("Verify Apps/Files");
    nut_CreateDigitalSignature = new QPushButton("Create");
    nut_VerifyDigitalSignature = new QPushButton("Verification");
    //custom
    nut_CreateDigitalSignature->setFixedWidth(300);
    nut_VerifyDigitalSignature->setFixedWidth(300);
    nut_CreateDigitalSignature->setFixedHeight(50); // Đặt chiều cao cố định
    nut_VerifyDigitalSignature->setFixedHeight(50);
    group_CreateDigitalSignature->setSpacing(50); // Đặt khoảng cách 10 pixel giữa các thành phần trong QHBoxLayout
    group_VerifyDigitalSignature->setSpacing(50);


    //add vao QHBoxlayout
    group_CreateDigitalSignature->addWidget(Create);
    group_CreateDigitalSignature->addWidget(nut_CreateDigitalSignature);

    group_VerifyDigitalSignature->addWidget(Verify);
    group_VerifyDigitalSignature->addWidget(nut_VerifyDigitalSignature);



    group_2_layout->addWidget(wid_Create);
    group_2_layout->addWidget(wid_Verity);
    group_2->setLayout(group_2_layout);
    fromInterface->addWidget(group_2);





    //create gruop 3 la 1 nut thoat------------------------------------------------------

    nut_exit = new QPushButton("EXIT");
    fromInterface->addWidget(nut_exit);
    nut_exit->setFixedHeight(50);


    connect_slot();


    this->setLayout(fromInterface);
    //Total->setLayout(fromInterface);


}

void DIGITAL_SIGNATURE::connect_slot()
{
    //connect(nut_logo,SIGNAL(clicked(bool)),this,SLOT(show_fromLogo()));

    connect(nut_exit,SIGNAL(clicked(bool)),this,SLOT(exit_app()));
    connect(nut_CreateDigitalSignature,SIGNAL(clicked(bool)),this,SLOT(show_fromCreate()));
    connect(nut_VerifyDigitalSignature,SIGNAL(clicked(bool)),this,SLOT(show_fromVerify()));



    //thoat from Create
    connect(nut_ExitCreate, SIGNAL(clicked(bool)), this, SLOT(exit_fromCreate()));
    //thoat from Verify
    connect(nut_ExitVerify, SIGNAL(clicked(bool)), this, SLOT(exit_fromVerity()));

    //slot_Create------------------------------------------------------------------------------------
    connect(nut_ChooseApp_Create,SIGNAL(clicked(bool)),this,SLOT(dialogBox_ChooseApp_Create()));
    connect(nut_ViewPathChooseApp_Create,SIGNAL(clicked(bool)),this,SLOT(dialogBox_ShowPathChooseApp_Create()));

    connect(nut_CreatePairKey_Create, SIGNAL(clicked(bool)),this, SLOT(dialogBox_PairKey()));
    connect(nut_ViewPathChoosePairKey_Create, SIGNAL(clicked(bool)),this, SLOT(dialogBox_showPathPairKey()));

    connect(nut_SignDigitalSignature_Create, SIGNAL(clicked(bool)),this, SLOT(dialogBox_signDigitalSignature()));
    connect(nut_ViewPathSignDigitalSignature_Create, SIGNAL(clicked(bool)),this, SLOT(showPathSignDigitalSignature()));






    //slot_Verity----------------------------------------------------------------------------------
    connect(nut_ChooseApp_Verify,SIGNAL(clicked(bool)),this,SLOT(dialogBox_ChooseApp_Verify()));
    connect(nut_ViewPathChooseApp_Verify,SIGNAL(clicked(bool)),this,SLOT(dialogBox_ShowPathChooseApp_Verify()));

    connect(nut_ChoosePublicKey_Verify,SIGNAL(clicked(bool)),this,SLOT(dialogBox_PublicKey_Verify()));
    connect(nut_ViewPathChoosePublicKey_Verify,SIGNAL(clicked(bool)),this,SLOT(dialogBox_showPathPublicKey_Verify()));


    connect(nut_ChooseDigitalSignature,SIGNAL(clicked(bool)),this,SLOT(dialogBox_ChoosePathSignDigitalSignature_Verify()));
    connect(nut_ViewPathChooseDigitalSignature,SIGNAL(clicked(bool)),this,SLOT(showPathSignDigitalSignature_Verify()));

    connect(nut_CheckDigitalSignature,SIGNAL(clicked(bool)),this,SLOT(CheckDigitalSignature()));
}

void DIGITAL_SIGNATURE::show_fromCreate()
{
    fromCreateDigitalSignature->exec();
}
void DIGITAL_SIGNATURE::show_fromVerify()
{
    fromVerifyDigitalSignature->exec();
}

void DIGITAL_SIGNATURE::showParent()
{
    this->show();
}




//create=================================================================================
void DIGITAL_SIGNATURE::create_fromCreate()
{
    //fromCreateDigitalSignature = new QDialog(Total);
    fromCreateDigitalSignature = new QDialog();
    fromCreateDigitalSignature->setFixedSize(600,400);
    fromCreateDigitalSignature->setWindowTitle("Create Digital Signature");

    //tao cac thanh phan tren from
    QGroupBox *group_fromCreate = new QGroupBox("Option:",fromCreateDigitalSignature);
    QVBoxLayout *fromCDS_Tatol = new QVBoxLayout(fromCreateDigitalSignature);

    //label content
    QWidget *wid_TitleFromCreate = new QWidget();
    QHBoxLayout *HB_titleFromCreate = new QHBoxLayout(wid_TitleFromCreate);
    QPixmap logoImage("D:\\BHNam_QT\\app_QT\\DigitalSignature\\DigitalSignature\\logo\\logo.png");
    QIcon logoIcon(logoImage);

    QPushButton *nut_LogoFromCreate = new QPushButton("");
    nut_LogoFromCreate->setIcon(logoIcon);
    nut_LogoFromCreate->setIconSize(QSize(80,80));
    nut_LogoFromCreate->setFixedSize(80, 80);
    //logo->setFixedWidth(300);
    nut_LogoFromCreate->setFixedHeight(80);

//    QString text_contentFromCreate = "1. chọn app/file cần thực hiện tạo chữ ký số\n"
//                                     "2. tạo cặp khóa RSA\n"
//                                     "3. tạo file chữ ký số";
    QString text_contentFromCreate = "1. Select the app/file for digital signature creation\n"
                                     "2. Generate an RSA key pair\n"
                                     "3. Create a digital signature file";
    QLabel *textFromCreate = new QLabel(text_contentFromCreate);
    textFromCreate->setFixedHeight(80);
    HB_titleFromCreate->addWidget(nut_LogoFromCreate);
    HB_titleFromCreate->addWidget(textFromCreate);




    //cac tuy chon----------------------------------------------
    QVBoxLayout *fromCDS_option = new QVBoxLayout(group_fromCreate);

    //wid choose app--------------------------------------------
    QWidget *wid_ChooseApp_Create = new QWidget();
    QHBoxLayout *group_ChooseApp_Create = new QHBoxLayout(wid_ChooseApp_Create);

    nut_ViewPathChooseApp_Create = new QPushButton("View Application/File Path");
    nut_ViewPathChooseApp_Create->setFixedHeight(50);

    nut_ChooseApp_Create = new QPushButton("Choose App/file");
    nut_ChooseApp_Create->setFixedHeight(50);

    group_ChooseApp_Create->addWidget(nut_ViewPathChooseApp_Create);
    group_ChooseApp_Create->addWidget(nut_ChooseApp_Create);
    fromCDS_option->addWidget(wid_ChooseApp_Create);

    //wid choose pair key---------------------------------------
    QWidget *wid_ChoosePairKey_Create = new QWidget();
    QHBoxLayout *group_ChoosePairKey_Create = new QHBoxLayout(wid_ChoosePairKey_Create);

    nut_ViewPathChoosePairKey_Create = new QPushButton("View Pair Key Path");
    nut_ViewPathChoosePairKey_Create->setFixedHeight(50);

    nut_CreatePairKey_Create = new QPushButton("Generate Key Pairs");
    nut_CreatePairKey_Create->setFixedHeight(50);

    group_ChoosePairKey_Create->addWidget(nut_ViewPathChoosePairKey_Create);
    group_ChoosePairKey_Create->addWidget(nut_CreatePairKey_Create);
    fromCDS_option->addWidget(wid_ChoosePairKey_Create);

    //wid choose------------------------------------------------
    QWidget *wid_ChooseSignDigitalSignature = new QWidget();
    QHBoxLayout *group_ChooseSignDigitalSignature = new QHBoxLayout(wid_ChooseSignDigitalSignature);

    nut_ViewPathSignDigitalSignature_Create = new QPushButton("View Digital Signature Path");
    nut_ViewPathSignDigitalSignature_Create->setFixedHeight(50);

    nut_SignDigitalSignature_Create = new QPushButton("Create Digital Signature");
    nut_SignDigitalSignature_Create->setFixedHeight(50);

    group_ChooseSignDigitalSignature->addWidget(nut_ViewPathSignDigitalSignature_Create);
    group_ChooseSignDigitalSignature->addWidget(nut_SignDigitalSignature_Create);
    fromCDS_option->addWidget(wid_ChooseSignDigitalSignature);


    //exit from create------------------------------------------
    nut_ExitCreate = new QPushButton("EXIT");
    //nut_ExitCreate->setFixedWidth(300);
    nut_ExitCreate->setFixedHeight(40);

    //==========================================
    //fromCDS_Tatol->addWidget(textFromCreate);
    fromCDS_Tatol->addWidget(wid_TitleFromCreate);
    fromCDS_Tatol->addWidget(group_fromCreate);
    fromCDS_Tatol->addWidget(nut_ExitCreate);
    //fromCDS_Tatol->addWidget()
    fromCreateDigitalSignature->setLayout(fromCDS_Tatol);
}

//slot from Create==================================================================
void DIGITAL_SIGNATURE::exit_fromCreate()
{
    int luaCHon = QMessageBox::question(this,"Exit","Do you want to exit Create Digital Signature?");
    if(luaCHon == QMessageBox::Yes)
    {
        fromCreateDigitalSignature->close();
        pathApp_Create.clear();

        pathFolderPairKey_Create.clear();
        pathPrivateKey.clear();
        pathPublicKey.clear();

        pathFolderSignDigitalSignature.clear();
        pathSignature.clear();

    }
    else if(luaCHon == QMessageBox::No)
    {
    }
}
void DIGITAL_SIGNATURE::dialogBox_ChooseApp_Create()
{
    pathApp_Create = QFileDialog::getOpenFileName(this,"Choose App/File","","All file (*);;exe (*.exe)");
    if(!pathApp_Create.isEmpty())
    {
        //QMessageBox::information(this,"Path ",pathApp_Create);
        QMessageBox::information(this,"Path to application/files folder",pathApp_Create);
    }
    else
    {
        QMessageBox::critical(this, "Error", "No applications/files selected!");
    }
}

void DIGITAL_SIGNATURE::dialogBox_ShowPathChooseApp_Create()
{
    if(!pathApp_Create.isEmpty())
    {    
        QMessageBox::information(this,"Path to application/files folder",pathApp_Create);
    }
    else
    {
        QMessageBox::critical(this, "Error", "No applications/files selected!");
    }
}

//slot pair key---------------------------------------------------
void DIGITAL_SIGNATURE::dialogBox_PairKey()
{
    //Do you already have a public and private key pair?
//    int luaCHon;
//    luaCHon = QMessageBox::question(this,"Warnning","Do you already have a public and private key pair?");
//    if(luaCHon == QMessageBox::Yes)
//    {
//        pathPrivateKey = QFileDialog::getOpenFileName(this, "Choose where to save the private key","", "PEM (*.pem)");
//        QFile checkFilePrivate(pathPrivateKey);
//        if(checkFilePrivate.open(QIODevice::ReadOnly))
//        {
//            QTextStream in(&checkFilePrivate);
//            QString fileContents = in.readAll();
//            checkFilePrivate.close();
//            QMessageBox::information(nullptr, "Content", fileContents);
//        }
//        QProcess opensslProcess;
//        opensslProcess.start("powershell.exe", QStringList() << "-Command" << "cat " + pathPrivateKey);
//        opensslProcess.waitForFinished();


//    }
//    else if(luaCHon == QMessageBox::No)
//    {

//    }
    pathFolderPairKey_Create = QFileDialog::getExistingDirectory(this, "Select The Folder Containing The Key Pair");
    if (!pathFolderPairKey_Create.isEmpty())
    {
        QMessageBox::information(this,"Path to the folder containing the key pair",pathFolderPairKey_Create);
        //--------------
        if(create_PrivateKey(pathFolderPairKey_Create))
        {
            create_PublicKey(pathFolderPairKey_Create);
        }
    }
    else
    {
        QMessageBox::critical(this, "Error", "No folder selected!");
    }
}

void DIGITAL_SIGNATURE::dialogBox_showPathPairKey()
{
    if (!pathFolderPairKey_Create.isEmpty()) {
        QString Content;
        Content = "Folder Path:\n" + pathFolderPairKey_Create
                + "\nPrivate Key Path:\n" + pathPrivateKey
                + "\nPublic Key Path:\n" + pathPublicKey;

        QMessageBox::information(this,"The current key pair is in use",Content);
        //QFileDialog::getExistingDirectory(nullptr, "Show Pair Key", pathFolderPairKey_Create);
    } else {
        QMessageBox::critical(this, "Error", "No folder selected!");
    }
}

bool DIGITAL_SIGNATURE::create_PrivateKey(QString &pathFolder)
{
    //pathPrivateKey = pathFolder+"/private.pem";
    int luaChon_private;
    do
    {
        pathPrivateKey = QFileDialog::getSaveFileName(nullptr, "Choose where to save the private key", pathFolder , "PEM (*.pem)");
        if(!pathPrivateKey.isEmpty())
        {
            //QMessageBox::information(this,"Private","ok");
            QProcess opensslProcess;
            opensslProcess.start("powershell.exe", QStringList() << "-Command" << "openssl genpkey -algorithm RSA -out " + pathPrivateKey);
            opensslProcess.waitForFinished();

            QFile checkFilePrivate(pathPrivateKey);
            if(checkFilePrivate.exists())
            {
                if(checkFilePrivate.open(QIODevice::ReadOnly))
                {
                    QTextStream in(&checkFilePrivate);
                    QString fileContents = in.readAll();
                    checkFilePrivate.close();
                    QMessageBox::information(nullptr, "Content", fileContents);
                }
                return true;
            }
            else
            {
                QMessageBox::critical(this,"Error Private Key","Not Found!\n"
                                                                "Private key generation failed.");
            }
        }
        else
        {
//          QMessageBox::critical(this,"Erro Private Key","Not Found!\n"
//                                                            "Private key generation failed.");
            luaChon_private = QMessageBox::question(this,"Error Generating Private Key","There was an error during the process of creating the private key.\n"
                                                                              "Do you want to regenerate it?");
            //                    if(luaCHon == QMessageBox::Yes)
            //                    {

            //                    }
            if(luaChon_private == QMessageBox::No)
            {
                QMessageBox::critical(this,"Error Generating Private Key","Not Found!\n"
                                                               "Private key generation failed.");
                return false;
            }
        }
    }while (luaChon_private == QMessageBox::Yes);





//    QProcess opensslProcessPublic;
//    opensslProcessPublic.start("powershell.exe", QStringList() << "-Command" << "openssl rsa -pubout -in "+ pathPrivateKey +" -out " + pathPublicKey);
//    opensslProcessPublic.waitForFinished();

    //pathPublicKey = pathFolder+"/public.pem";
}

void DIGITAL_SIGNATURE::create_PublicKey(QString &pathFolder)
{
    int luaChon_public;
    do
    {
        pathPublicKey = QFileDialog::getSaveFileName(nullptr, "Choose where to save the public key",pathFolder , "PEM (*.pem)");
        if(!pathPublicKey.isEmpty())
        {
            QProcess opensslProcess;
            opensslProcess.start("powershell.exe", QStringList() << "-Command" << "openssl rsa -pubout -in "+ pathPrivateKey +" -out " + pathPublicKey);
            opensslProcess.waitForFinished();


            QFile checkFilePublic(pathPublicKey);
            if(checkFilePublic.exists())
            {

                //QMessageBox::information(this,"Prirate","Public Key created successfully");
                if(checkFilePublic.open(QIODevice::ReadOnly))
                {
                    QTextStream in(&checkFilePublic);
                    QString fileContents = in.readAll();
                    checkFilePublic.close();
                    QMessageBox::information(nullptr, "Content", fileContents);
                }
            }
            else
            {
                QMessageBox::critical(this,"Error Generating Public Key","Not Found!\n"
                                                                          "Public key generation failed.");
            }
        }
        else
        {
            //                    QMessageBox::critical(this,"Erro Public Key","Not Found!\n"
            //                                                                   "Public key generation failed.");
            luaChon_public = QMessageBox::question(this,"Error Generating Public Key","There was an error during the process of creating the public key.\n"
                                                                                       "Do you want to regenerate it?");
            //                    if(luaCHon == QMessageBox::Yes)
            //                    {

            //                    }
            if(luaChon_public == QMessageBox::No)
            {
                QMessageBox::critical(this,"Error Public Key","Not Found!\n"
                                                               "Public key generation failed.");
            }
        }
    }while (luaChon_public == QMessageBox::Yes);
}



//slot sign digital signature----------------------------------------------
void DIGITAL_SIGNATURE::dialogBox_signDigitalSignature()
{
    QFile checkFileApp(pathApp_Create);
    if(checkFileApp.exists())
    {
        QFile checkFilePrivate(pathPrivateKey);
        if(checkFilePrivate.exists())
        {
            pathFolderSignDigitalSignature = QFileDialog::getExistingDirectory(this, "Select Folder Sign Digital Signature");
            if (!pathFolderSignDigitalSignature.isEmpty()) {
                QMessageBox::information(this,"Path to the folder containing the digital signature",pathFolderSignDigitalSignature);
                //--------------
                signDigitalSignature();

            } else {
                QMessageBox::critical(this, "Error", "No folder selected!");
            }
        }
        else
        {
            QMessageBox::critical(this,"Error Private Key","Not Found!\nyou need a private key to create a digital signature.");
        }
    }
    else
    {
        QMessageBox::critical(this,"Error App/File","Not Found!\nThere is no application or file to create a digital signature");
    }
}

void DIGITAL_SIGNATURE::showPathSignDigitalSignature()
{
    if (!pathFolderSignDigitalSignature.isEmpty()) {
        QMessageBox::information(this,"Path to the folder containing the digital signature",pathFolderSignDigitalSignature);
//        //--------------
//        signDigitalSignature();
    } else {
        QMessageBox::critical(this, "Error", "No folder selected!");
    }
}
void DIGITAL_SIGNATURE::signDigitalSignature()
{
    //pathSignature = pathFolderSignDigitalSignature+"/tem.sign";
    pathSignature = QFileDialog::getSaveFileName(nullptr, "Choose where to save the Digital Signature",pathFolderSignDigitalSignature , "Tệp PEM (*.sign)");
    //QMessageBox::information(this,"loading","dang ki");
    if(!pathSignature.isEmpty())
    {
        QFile checkFileSign(pathSignature);
        QProcess opensslProcess;
        opensslProcess.start("powershell.exe", QStringList() << "-Command" << ""
                                                                "openssl dgst -sha256 -sign "
                                                                ""+ pathPrivateKey + " -out " + pathSignature + " " + pathApp_Create);
        opensslProcess.waitForFinished();
        if(checkFileSign.exists())
        {
            //QMessageBox::information(this,"Sign","Signature File Created Successfully");
            if(checkFileSign.open(QIODevice::ReadOnly))
            {
                QTextStream in(&checkFileSign);
                QString fileContents = in.readAll();
                checkFileSign.close();
                QMessageBox::information(nullptr, "Content", fileContents);
            }
        }
        else
        {
            QMessageBox::critical(this,"Error Sign","Not Found!");
        }
    }
    else
    {
        QMessageBox::critical(this,"Error Sign","Not Found!\n"
                                                 "Could not find where to save the digital signature file.");
    }



}




























//verify=================================================================================
void DIGITAL_SIGNATURE::create_fromVerify()
{
    //fromVerifyDigitalSignature = new QDialog(Total);
    fromVerifyDigitalSignature = new QDialog();
    fromVerifyDigitalSignature->setFixedSize(600,400);
    fromVerifyDigitalSignature->setWindowTitle("Verify Digital Signature");

    //tao cac thanh phan tren from
    QGroupBox *group_fromVerify = new QGroupBox("Option:",fromVerifyDigitalSignature);
    QVBoxLayout *fromVDS_Tatol = new QVBoxLayout(fromVerifyDigitalSignature);

    //label content
    QWidget *wid_TitleFromVerify = new QWidget();
    QHBoxLayout *HB_titleFromVerify = new QHBoxLayout(wid_TitleFromVerify);
    QPixmap logoImage("D:\\BHNam_QT\\app_QT\\DigitalSignature\\DigitalSignature\\logo\\logo.png");
    QIcon logoIcon(logoImage);

    QPushButton *nut_LogoFromVerify = new QPushButton("");
    nut_LogoFromVerify->setIcon(logoIcon);
    nut_LogoFromVerify->setIconSize(QSize(60,60));
    nut_LogoFromVerify->setFixedSize(60, 60);
    //logo->setFixedWidth(300);
    nut_LogoFromVerify->setFixedHeight(60);

//    QString text_contentFromCreate = "1. chọn app/file cần thực hiện xác minh chữ ký số\n"
//                                     "2. chọn khóa public\n"
//                                     "3. chọn file chữ ký số\n"
//                                     "4. kiểm tra chữ ký số";
    QString text_contentFromCreate = "1. Select the app/file to perform digital signature verification\n"
                                     "2. Select the public key\n"
                                     "3. Select the digital signature file\n"
                                     "4. Verify the digital signature";
    QLabel *textFromVerify = new QLabel(text_contentFromCreate);
    textFromVerify->setFixedHeight(60);
    HB_titleFromVerify->addWidget(nut_LogoFromVerify);
    HB_titleFromVerify->addWidget(textFromVerify);


    //cac tuy chon----------------------------------------------
    QVBoxLayout *fromVDS_option = new QVBoxLayout(group_fromVerify);

    //wid choose app--------------------------------------------
    QWidget *wid_ChooseApp_Verify = new QWidget();
    QHBoxLayout *group_ChooseApp_Verify = new QHBoxLayout(wid_ChooseApp_Verify);

    nut_ViewPathChooseApp_Verify = new QPushButton("View App/file Path");
    nut_ViewPathChooseApp_Verify->setFixedHeight(50);

    nut_ChooseApp_Verify = new QPushButton("Choose App/file");
    nut_ChooseApp_Verify->setFixedHeight(50);

    group_ChooseApp_Verify->addWidget(nut_ViewPathChooseApp_Verify);
    group_ChooseApp_Verify->addWidget(nut_ChooseApp_Verify);
    fromVDS_option->addWidget(wid_ChooseApp_Verify);

    //wid choose pair key---------------------------------------
    QWidget *wid_ChoosePublicKey = new QWidget();
    QHBoxLayout *group_ChoosePublicKey = new QHBoxLayout(wid_ChoosePublicKey);

    nut_ViewPathChoosePublicKey_Verify = new QPushButton("View Choose Public Key Path");
    nut_ViewPathChoosePublicKey_Verify->setFixedHeight(50);

    nut_ChoosePublicKey_Verify = new QPushButton("Choose Public Key");
    nut_ChoosePublicKey_Verify->setFixedHeight(50);
    group_ChoosePublicKey->addWidget(nut_ViewPathChoosePublicKey_Verify);
    group_ChoosePublicKey->addWidget(nut_ChoosePublicKey_Verify);
    fromVDS_option->addWidget(wid_ChoosePublicKey);

    //wid choose------------------------------------------------
    QWidget *wid_ChooseCheckDigitalSignature = new QWidget();
    QHBoxLayout *group_ChooseCheckDigitalSignature = new QHBoxLayout(wid_ChooseCheckDigitalSignature);

    nut_ViewPathChooseDigitalSignature = new QPushButton("View Choose Digital Signature Path");
    nut_ViewPathChooseDigitalSignature->setFixedHeight(50);

    nut_ChooseDigitalSignature = new QPushButton("Choose Digital Signature");
    nut_ChooseDigitalSignature->setFixedHeight(50);

    group_ChooseCheckDigitalSignature->addWidget(nut_ViewPathChooseDigitalSignature);
    group_ChooseCheckDigitalSignature->addWidget(nut_ChooseDigitalSignature);
    fromVDS_option->addWidget(wid_ChooseCheckDigitalSignature);

    //nut check digital signature
    nut_CheckDigitalSignature = new QPushButton("Check Digital Signature");
    nut_CheckDigitalSignature->setFixedHeight(30);
    //nut_CheckDigitalSignature->setFixedWidth(300);

    fromVDS_option->addWidget(nut_CheckDigitalSignature);

    //exit from verify------------------------------------------
    nut_ExitVerify = new QPushButton("EXIT");
    //nut_ExitCreate->setFixedWidth(300);
    nut_ExitVerify->setFixedHeight(30);

    //==========================================
    //fromVDS_Tatol->addWidget(textFromVerify);
    fromVDS_Tatol->addWidget(wid_TitleFromVerify);
    fromVDS_Tatol->addWidget(group_fromVerify);
    fromVDS_Tatol->addWidget(nut_ExitVerify);
    //fromCDS_Tatol->addWidget()
    fromCreateDigitalSignature->setLayout(fromVDS_Tatol);
}

//slots from Verify================================================================
void DIGITAL_SIGNATURE::exit_fromVerity()
{
    int luaCHon = QMessageBox::question(this,"Exit","Do you want to exit Digital Signature Verification?");
    if(luaCHon == QMessageBox::Yes)
    {
        fromVerifyDigitalSignature->close();
        pathApp_Verify.clear();
        pathFilePublicKey.clear();
        pathFileSign.clear();
    }
    else if(luaCHon == QMessageBox::No)
    {

    }

}

void DIGITAL_SIGNATURE::dialogBox_ChooseApp_Verify()
{
    pathApp_Verify = QFileDialog::getOpenFileName(this,"Select Application/File to verify","","All file (*);;exe (*.exe)");
    if(!pathApp_Verify.isEmpty())
    {
        QMessageBox::information(this,"Path to the application to be verified",pathApp_Verify);
    }
    else
    {
        QMessageBox::critical(this, "Error", "No applications/files selected!");
    }
}

void DIGITAL_SIGNATURE::dialogBox_ShowPathChooseApp_Verify()
{
    if(!pathApp_Verify.isEmpty())
    {
        QMessageBox::information(this,"Path to the application to be verified",pathApp_Verify);
    }
    else
    {
        QMessageBox::critical(this, "Error", "No applications/files selected!");
    }
}
//---------------------------------------------------------
void DIGITAL_SIGNATURE::dialogBox_PublicKey_Verify()
{
    int luaCHon;
    do
    {
        pathFilePublicKey = QFileDialog::getOpenFileName(this,"Choose Public Key","","PEM (*.pem)");
        if(!pathFilePublicKey.isEmpty())
        {
            luaCHon = QMessageBox::question(this,"Warning","Are you sure this is the application's public key file or the file you selected?");
            //int luaCHon = QMessageBox::question(this,"Exit","Do you want to exit Digital Signature Verification?");
            if(luaCHon == QMessageBox::Yes)
            {
                QMessageBox::information(this,"Path Public Key",pathFilePublicKey);
            }
//            else if(luaCHon == QMessageBox::No)
//            {

//            }
        }
        else
        {
            QMessageBox::critical(this, "Error", "No File Public Key!");
        }


    }while (luaCHon == QMessageBox::No);



}
void DIGITAL_SIGNATURE::dialogBox_showPathPublicKey_Verify()
{
    if(!pathFilePublicKey.isEmpty())
    {
        QMessageBox::information(this,"Public key path being used for verification",pathFilePublicKey);
    }
    else
    {
        QMessageBox::critical(this, "Error", "There is no public key file!");
    }
}

void DIGITAL_SIGNATURE::dialogBox_ChoosePathSignDigitalSignature_Verify()
{
    int luaCHon;
    do
    {
        pathFileSign = QFileDialog::getOpenFileName(this,"Select the digital signature","","SIGN (*.sign)");
        if(!pathFileSign.isEmpty())
        {
            //QMessageBox::information(this,"Path Sign",pathFileSign);
            luaCHon = QMessageBox::question(this,"Warning","Are you sure this is the application's digital signature file or the file you selected?");
            //int luaCHon = QMessageBox::question(this,"Exit","Do you want to exit Digital Signature Verification?");
            if(luaCHon == QMessageBox::Yes)
            {
                QMessageBox::information(this,"Digital signature path",pathFileSign);
            }
        }
        else
        {
            QMessageBox::critical(this, "Error", "There is no Digital Signature file!");
        }
    }while (luaCHon == QMessageBox::No);

}
void DIGITAL_SIGNATURE::showPathSignDigitalSignature_Verify()
{
    if(!pathFileSign.isEmpty())
    {
        QMessageBox::information(this,"Digital signature path",pathFileSign);
    }
    else
    {
        QMessageBox::critical(this, "Error", "There is no Digital Signature file!");
    }
}


void DIGITAL_SIGNATURE::CheckDigitalSignature()
{
    //QMessageBox::information(this,"Load","-------- dang ki");


    if(!pathApp_Verify.isEmpty())
    {
        //QMessageBox::information(this,"Path",pathApp_Verify);
        if(!pathFilePublicKey.isEmpty())
        {
            //QMessageBox::information(this,"Path Public Key",pathFilePublicKey);
            if(!pathFileSign.isEmpty())
            {
                //QMessageBox::information(this,"Path Sign",pathFileSign);
                //check
                QProcess opensslProcess;
                opensslProcess.start("powershell.exe", QStringList() << "-Command" << ""
                                                                        "openssl dgst -sha256 -verify "
                                                                        ""+ pathFilePublicKey + " -signature " + pathFileSign + " " + pathApp_Verify);
                opensslProcess.waitForFinished();
                if (opensslProcess.exitCode() == 0)
                {
                    QMessageBox::information(this,"Result","Verified successfully OK !!!\n"
                                                             "The application or file is intact compared to the public key file and digital signature file.");
                }
                else
                {
                    QMessageBox::critical(this,"Error","The application or file you selected is no longer intact compared \n"
                                                         "to the public key file and digital signature file!");
                }
            }
            else
            {
                QMessageBox::critical(this, "Error", "There is no Digital Signature file!\n"
                                                    "You must have the digital signature file of the application or file you selected.");
            }
        }
        else
        {
            QMessageBox::critical(this, "Error", "No File Public Key!\n"
                                                "You must have the application's public key file or the file you selected.");
        }
    }
    else
    {
        QMessageBox::critical(this, "Error", "No applications/files selected!\n"
                                            "You must select the application or file to verify.");
    }

}









DIGITAL_SIGNATURE::~DIGITAL_SIGNATURE()
{
}

//void DIGITAL_SIGNATURE::show_fromLogo()
//{
//    QLabel *label = new QLabel(fromLogo);

//    QPixmap pixmap("D:\\BHNam_QT\\app_QT\\DigitalSignature\\DigitalSignature\\logo.png");
//    label->setPixmap(pixmap);


//    fromLogo->show();
//}


//void DIGITAL_SIGNATURE::checkLogo()
//{

//}

void DIGITAL_SIGNATURE::exit_app()
{

    int luaCHon = QMessageBox::question(this,"Exit","Do you want to exit the application?");
    if(luaCHon == QMessageBox::Yes)
    {
        qApp->exit(1);
    }
    else if(luaCHon == QMessageBox::No)
    {

    }
}

void DIGITAL_SIGNATURE::tb_MESS()
{
    QString message = "Here Logo";
    QMessageBox::information(this, "Logo", message);
}

