#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    static bool faster_checked = true;
    static bool slower_checked = false;

    FacileMenu* menu = (new FacileMenu(this))
        ->setTipArea("Ctrl+P")
        ->setSplitInRow(true);

    menu->addAction(QIcon(":/icons/run"), "开始播放 (&S)", [=]{
        qDebug() << "=>开始播放";
    })->tip("Ctrl+S");

    menu->addAction(QIcon(":/icons/pause"), "暂停 (&P)", [=]{
        qDebug() << "=>暂停";
    })->tip("Ctrl+P");

    menu->addAction(QIcon(":/icons/resume"), "继续 (&R)", [=]{
        qDebug() << "=>继续";
    })->disable()->tip("Ctrl+R");

    menu->addAction(QIcon(":/icons/stop"), "停止 (&T)", [=]{
        qDebug() << "=>停止";
    })->tip("Ctrl+T");
    menu->addSeparator();

    menu->addAction(QIcon(":/icons/faster"), "加速", [=]{
        qDebug() << "=>加速";
        faster_checked = !faster_checked;
    })->check(faster_checked)->linger();

    menu->addAction(QIcon(":/icons/slower"), "减速", [=]{
        qDebug() << "=>减速";
        slower_checked = !slower_checked;
    })->check(slower_checked)->linger();

    menu->addRow([=]{
        menu->addAction("按钮1");
        menu->addAction("按钮2");
        menu->addAction("按钮3");
    });

    auto subMenu = menu->addMenu("子菜单0");
    {
        subMenu->addAction(QIcon(":/icons/run"), "开始播放", [=]{
            qDebug() << "=>开始播放";
        });

        subMenu->addAction(QIcon(":/icons/pause"), "暂停", [=]{
            qDebug() << "=>暂停";
        });

        subMenu->addAction(QIcon(":/icons/resume"), "继续", [=]{
            qDebug() << "=>继续";
        })->disable();

        subMenu->addAction(QIcon(":/icons/stop"), "停止", [=]{
            qDebug() << "=>停止";
        });

        subMenu->addAction(QIcon(":/icons/faster"), "加速", [=]{
            qDebug() << "=>加速";
            faster_checked = !faster_checked;
        })->setChecked(faster_checked);

        auto subMenu2 = subMenu->addMenu("子菜单");
        {
            subMenu2->addAction(QIcon(":/icons/run"), "开始播放", [=]{
                qDebug() << "=>开始播放";
            });

            subMenu2->addAction(QIcon(":/icons/pause"), "暂停", [=]{
                qDebug() << "=>暂停";
            });

            subMenu2->addAction(QIcon(":/icons/resume"), "继续", [=]{
                qDebug() << "=>继续";
            })->disable();

            subMenu2->addAction(QIcon(":/icons/stop"), "停止", [=]{
                qDebug() << "=>停止";
            });

            subMenu2->addAction(QIcon(":/icons/faster"), "加速", [=]{
                qDebug() << "=>加速";
                faster_checked = !faster_checked;
            })->setChecked(faster_checked);

            auto subMenu3 = subMenu2->addMenu("子菜单");
            subMenu3->addAction("没有子菜单了");
        }
    }

    auto subMenu2 = menu->addMenu("可选菜单");
    {
        auto ac1 = subMenu2->addAction(QIcon(":/icons/run"), "选中1", [=]{
            qDebug() << "=>选中1";
        })->setChecked(true)->linger();

        auto ac2 = subMenu2->addAction(QIcon(":/icons/pause"), "选中2", [=]{
            qDebug() << "=>选中2";
        })->setChecked(false)->linger();

        auto ac3 = subMenu2->addAction(QIcon(":/icons/resume"), "选中3", [=]{
            qDebug() << "=>选中3";
        })->setChecked(true)->linger();

        ac1->triggered([=]{
            subMenu2->uncheckAll(ac1);
        });
        ac2->triggered([=]{
            subMenu2->uncheckAll(ac2);
        });
        ac3->triggered([=]{
            subMenu2->uncheckAll(ac3);
        });
    }

    auto subMenu3 = menu->addMenu("子菜单2");
    {

        subMenu3->addAction(QIcon(":/icons/resume"), "继续", [=]{
            qDebug() << "=>继续";
        })->disable()->linger();

        subMenu3->addAction(QIcon(":/icons/stop"), "停止", [=]{
            qDebug() << "=>停止";
        })->linger();
    }

    auto subMenu4 = menu->addMenu("子菜单3");
    {
        subMenu4->addAction(QIcon(":/icons/faster"), "加速", [=]{
            qDebug() << "=>加速";
            faster_checked = !faster_checked;
        })->setChecked(faster_checked);
    }


    menu->exec(QCursor::pos());
}

void MainWindow::on_pushButton_2_clicked()
{
    static bool faster_checked = true;
    static bool slower_checked = false;

    FacileMenu* menu = new FacileMenu(this);
    menu->setTipArea("Ctrl+P");

    menu->addRow([=]{
        menu->addAction("按钮1")->disable();
        menu->addAction("按钮2")->disable();
        menu->addAction("按钮3")->text(true, "按钮3 (&K)");
    });

    menu->addAction(QIcon(":/icons/run"), "开始播放 (&S)", [=]{
        qDebug() << "=>开始播放";
    })->tip("Ctrl+S");

    menu->addAction(QIcon(":/icons/pause"), "暂停 (&P)", [=]{
        qDebug() << "=>暂停";
    })->tip("Ctrl+P");

    QPushButton* button = new QPushButton("外部添加的按钮", this);
    menu->addWidget(button);

    QHBoxLayout* btn_hlayout = new QHBoxLayout;
    QPushButton* btn1= new QPushButton("按钮1", this);
    QPushButton* btn2 = new QPushButton("按钮2", this);
    btn_hlayout->addSpacing(40);
    btn_hlayout->addWidget(btn1);
    btn_hlayout->addItem(new QSpacerItem(4, 0));
    btn_hlayout->addWidget(btn2);
    menu->addLayout(btn_hlayout);

    menu->addAction(QIcon(":/icons/resume"), "继续 (&R)", [=]{
        qDebug() << "=>继续";
    })->disable()->tip("Ctrl+R");

    menu->addAction(QIcon(":/icons/stop"), "停止 (&T)", [=]{
        qDebug() << "=>停止";
    })->tip("Ctrl+T");
    menu->addSeparator();

    menu->addAction(QIcon(), "静态回调方法", staticFunction);
//    menu->fun2(1, "类内回调方法", this, &MainWindow::classFunction);

    menu->addAction(QIcon(":/icons/faster"), "加速", [=]{
        qDebug() << "=>加速";
        faster_checked = !faster_checked;
    })->setChecked(faster_checked);

    menu->addAction(QIcon(":/icons/slower"), "减速", [=]{
        qDebug() << "=>减速";
        slower_checked = !slower_checked;
    })->setChecked(slower_checked);

    menu->beginRow();
    menu->addAction(QIcon(":/icons/run"));
    menu->addAction(QIcon(":/icons/pause"));
    menu->split()->addAction(QIcon(":/icons/resume"));
    menu->addAction(QIcon(":/icons/stop"))->disable();
    menu->endRow();

    menu->addAction(QIcon(":/icons/faster"), "加速", [=]{
        qDebug() << "=>加速";
        faster_checked = !faster_checked;
    })->setChecked(faster_checked)->disable();

    menu->addAction(QIcon(":/icons/slower"), "减速", [=]{
        qDebug() << "=>减速";
        slower_checked = !slower_checked;
    })->setChecked(slower_checked)->disable();

    menu->beginRow();
    menu->addAction("按钮1");
    menu->addAction("按钮2")->disable();
    menu->addAction("按钮3")->disable();
    menu->endRow();


    menu->exec(QCursor::pos());
}

void MainWindow::staticFunction()
{
    qDebug() << "静态方法回调";
}

void MainWindow::classFunction()
{
    qDebug() << "类内方法回调";
}
