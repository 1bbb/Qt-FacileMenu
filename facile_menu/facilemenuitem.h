#ifndef FACILEMENUITEM_H
#define FACILEMENUITEM_H

#include "interactivebuttonbase.h"

class FacileMenu;
class FacileMenuItem;

typedef std::function<void()> const FuncType;
typedef std::function<void(int)> const FuncIntType;
typedef std::function<void(FacileMenuItem*)> const FuncItemType;

class FacileMenuItem : public InteractiveButtonBase
{
public:
    FacileMenuItem(QWidget* parent = nullptr);
    FacileMenuItem(QString t, QWidget* parent = nullptr);
    FacileMenuItem(QIcon i, QWidget* parent = nullptr);
    FacileMenuItem(QIcon i, QString t, QWidget* parent = nullptr);
    FacileMenuItem(QPixmap p, QString t, QWidget* parent = nullptr);

    FacileMenuItem* setEnabled(bool e);
    FacileMenuItem* setCheckable(bool c);
    bool isCheckable() const;
    FacileMenuItem* setChecked(bool c);
    bool isChecked();
    FacileMenuItem* setKey(Qt::Key key);
    bool isKey(Qt::Key key) const;
    FacileMenuItem* setSubMenu(FacileMenu* menu);
    bool isSubMenu() const;
    bool isLinger() const;

    FacileMenuItem* tip(QString sc);
    FacileMenuItem* tooltip(QString tt);
    FacileMenuItem* triggered(FuncType func);
    FacileMenuItem* disable(bool dis = true); // 满足情况下触发，不满足不变，下同
    FacileMenuItem* enable(bool en = true);
    FacileMenuItem* hide(bool hi = true);
    FacileMenuItem* visible(bool vi = true);
    FacileMenuItem* check(bool ch = true);
    FacileMenuItem* uncheck(bool uc = true);
    FacileMenuItem* text(bool te, QString str);
    FacileMenuItem* text(bool exp, QString tru, QString fal);
    FacileMenuItem* icon(bool ic, QIcon icon);
    FacileMenuItem* borderR(int radius = 3, QColor co = Qt::transparent);
    FacileMenuItem* linger();
    FacileMenuItem* bind(bool &val);
    FacileMenuItem* ifer(bool iff = true);
    FacileMenuItem* elser();
    FacileMenuItem* breaker(bool br = true);
    FacileMenuItem* ifer(bool iff, FuncItemType func, FuncItemType elseFunc = nullptr);
    FacileMenuItem* prefix(bool exp, QString pfix);
    FacileMenuItem* suffix(bool exp, QString sfix, bool inLeftParenthesis = true);

    FacileMenu* subMenu();

protected:
    void paintEvent(QPaintEvent *event) override;
    void drawIconBeforeText(QPainter &painter, QRect icon_rect) override;

    FacileMenuItem* createTempItem();

private:
    Qt::Key key;
    bool checkable = false;
    bool trigger_linger = false; // 点击后是否保存菜单
    FacileMenu* sub_menu = nullptr;
    QString shortcut_tip = ""; // 快捷键提示
    FacileMenuItem* parent_menu_item_in_if = nullptr; // elser专用
};

#endif // FACILEMENUITEM_H
