#include "qttestqtarrowitemsmodifydialog.h"
#include <boost/test/unit_test.hpp>

#include <boost/make_shared.hpp>
#include <boost/lambda/lambda.hpp>

#include <QKeyEvent>
#include <QTimer>

#include "qtquadbezierarrowitem.h"
#include "qtquadbezierarrowdialog.h"
#include "ribi_random.h"
#include "testtimer.h"
#include "trace.h"
#include "ui_qttestqtarrowitemsmodifydialog.h"

BOOST_AUTO_TEST_CASE(ribi_qtTestQtArrowItemsModifyDialog_test)
{
  using namespace ribi;
  const bool verbose{false};
  QtTestQtArrowItemsModifyDialog d;
  d.show();
  if (verbose) { TRACE("Must get after set"); }
  {
    const auto arrow = CreateRandomArrow();
    d.SetArrow(arrow);
    BOOST_CHECK(d.GetArrow() == arrow);
  }
  if (verbose) { TRACE("Changing the mid X via UI, must change the arrow"); }
  {
    const auto arrow = CreateRandomArrow();
    d.SetArrow(arrow);
    const double old_x{arrow->GetMidX()};
    const double new_x{old_x + 10.0};
    BOOST_CHECK(new_x != old_x);
    d.GetDialogLeft()->SetUiMidX(new_x);
    BOOST_CHECK(std::abs(arrow->GetMidX() - new_x) < 2.0);
  }
  if (verbose) { TRACE("Changing the mid X via arrow, must change the UI"); }
  {
    const auto arrow = CreateRandomArrow();
    d.SetArrow(arrow);
    const double old_x{arrow->GetMidX()};
    const double new_x{old_x + 10.0};
    BOOST_CHECK(new_x != old_x);
    arrow->SetMidX(new_x);
    BOOST_CHECK(std::abs(d.GetDialogLeft()->GetUiMidX() - new_x) < 2.0);
  }
}
