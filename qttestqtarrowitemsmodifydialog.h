#ifndef QTTESTQTROUNDEDRECTITEMMODIFYDIALOG_H
#define QTTESTQTROUNDEDRECTITEMMODIFYDIALOG_H

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#pragma GCC diagnostic ignored "-Wunused-but-set-parameter"
#include <boost/shared_ptr.hpp>
#include "qthideandshowdialog.h"
#pragma GCC diagnostic pop

namespace Ui {
class QtTestQtArrowItemsModifyDialog;
}

namespace ribi {

struct QtQuadBezierArrowItem;
struct QtQuadBezierArrowDialog;

class QtTestQtArrowItemsModifyDialog : public QtHideAndShowDialog
{
  Q_OBJECT
    
public:

  explicit QtTestQtArrowItemsModifyDialog(QWidget *parent = 0);
  QtTestQtArrowItemsModifyDialog(const QtTestQtArrowItemsModifyDialog&) = delete;
  QtTestQtArrowItemsModifyDialog& operator=(const QtTestQtArrowItemsModifyDialog&) = delete;
  ~QtTestQtArrowItemsModifyDialog() noexcept;

  void SetArrow(const boost::shared_ptr<QtQuadBezierArrowItem>& arrow) noexcept;
  boost::shared_ptr<QtQuadBezierArrowItem> GetArrow() const noexcept;

  const QtQuadBezierArrowDialog * GetDialogLeft()  const noexcept { return m_dialog_left.get();  }
        QtQuadBezierArrowDialog * GetDialogLeft()        noexcept { return m_dialog_left.get();  }
  const QtQuadBezierArrowDialog * GetDialogRight() const noexcept { return m_dialog_right.get(); }
        QtQuadBezierArrowDialog * GetDialogRight()       noexcept { return m_dialog_right.get(); }

protected:
  void keyPressEvent(QKeyEvent * event);

private slots:

  void on_button_set_item_clicked();

private:
  Ui::QtTestQtArrowItemsModifyDialog *ui;

  ///The dialogs working on a same QtQuadBezierArrowItem
  boost::shared_ptr<QtQuadBezierArrowDialog> m_dialog_left;
  boost::shared_ptr<QtQuadBezierArrowDialog> m_dialog_right;

};

boost::shared_ptr<QtQuadBezierArrowItem> CreateRandomArrow() noexcept;

} //~namespace ribi

#endif // QTTESTQTROUNDEDRECTITEMMODIFYDIALOG_H
