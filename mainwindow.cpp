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

    FacileMenu* menu = new FacileMenu(this);

    menu->addAction(QIcon(":/icons/run"), "开始播放", [=]{
        qDebug() << "=>开始播放";
    });

    menu->addAction(QIcon(":/icons/pause"), "暂停", [=]{
        qDebug() << "=>暂停";
    });

    menu->addAction(QIcon(":/icons/resume"), "继续", [=]{
        qDebug() << "=>继续";
    })->disable();

    menu->addAction(QIcon(":/icons/stop"), "停止", [=]{
        qDebug() << "=>停止";
    });
    menu->addSeparator();

    menu->addAction(QIcon(":/icons/faster"), "加速", [=]{
        qDebug() << "=>加速";
        faster_checked = !faster_checked;
    })->setChecked(faster_checked);

    menu->addAction(QIcon(":/icons/slower"), "减速", [=]{
        qDebug() << "=>减速";
        slower_checked = !slower_checked;
    })->setChecked(slower_checked);

    auto subMenu = menu->addMenu("子菜单");
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
        }
    }

    auto subMenu2 = menu->addMenu("子菜单");
    {
        subMenu2->addAction(QIcon(":/icons/run"), "开始播放", [=]{
            qDebug() << "=>开始播放";
        });

        subMenu2->addAction(QIcon(":/icons/pause"), "暂停", [=]{
            qDebug() << "=>暂停";
        });
    }

    auto subMenu3 = menu->addMenu("子菜单");
    {

        subMenu3->addAction(QIcon(":/icons/resume"), "继续", [=]{
            qDebug() << "=>继续";
        })->disable();

        subMenu3->addAction(QIcon(":/icons/stop"), "停止", [=]{
            qDebug() << "=>停止";
        });
    }

    auto subMenu4 = menu->addMenu("子菜单");
    {
        subMenu4->addAction(QIcon(":/icons/faster"), "加速", [=]{
            qDebug() << "=>加速";
            faster_checked = !faster_checked;
        })->setChecked(faster_checked);
    }


    menu->execute(QCursor::pos());
}
