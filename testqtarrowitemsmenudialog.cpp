// ---------------------------------------------------------------------------
/*
TestQtArrowItems, tool to test Qt arrow QGraphicsItems
Copyright (C) 2012-2016 Richel Bilderbeek

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.If not, see <http://www.gnu.org/licenses/>.
*/
// ---------------------------------------------------------------------------
//From http://www.richelbilderbeek.nl/ToolTestQtArrowItems.htm
// ---------------------------------------------------------------------------
#include "testqtarrowitemsmenudialog.h"

#include <cassert>
#include <iostream>

#include "trace.h"
#include "testtimer.h"

int ribi::TestQtArrowItemsMenuDialog::ExecuteSpecific(const std::vector<std::string>& argv) noexcept
{
  const int argc = static_cast<int>(argv.size());
  if (argc == 1)
  {
    std::cout << GetHelp() << '\n';
    return 1;
  }
  std::cout << "Cannot run TestQtArrowItemsMenuDialog from the command line." << '\n';
  return 0;
}

ribi::About ribi::TestQtArrowItemsMenuDialog::GetAbout() const noexcept
{
  About a(
    "Richel Bilderbeek",
    "TestQtArrowItems",
    "tool to test Qt arrow QGraphicsItems",
    "January 17th of 2016",
    "2012-2016",
    "http://www.richelbilderbeek.nl/ToolTestQtArrowItems.htm",
    GetVersion(),
    GetVersionHistory()
  );
  //a.AddLibrary("ProFile version: " + ProFile::GetVersion());
  a.AddLibrary("Trace version: " + Trace::GetVersion());
  return a;
}

ribi::Help ribi::TestQtArrowItemsMenuDialog::GetHelp() const noexcept
{
  return Help(
    this->GetAbout().GetFileTitle(),
    this->GetAbout().GetFileDescription(),
    {

    },
    {

    }
  );
}

std::string ribi::TestQtArrowItemsMenuDialog::GetVersion() const noexcept
{
  return "2.1";
}

std::vector<std::string> ribi::TestQtArrowItemsMenuDialog::GetVersionHistory() const noexcept
{
  return {
    "2012-12-07: version 0.1: initial version",
    "2013-01-01: version 1.0: added menu",
    "2013-11-05: version 1.1: conformized for ProjectRichelBilderbeekConsole",
    "2014-07-29: version 1.2: added Modify dialog",
    "2015-02-08: version 1.3: added legend to Compare dialog",
    "2016-01-17: version 2.0: moved to own GitHub",
    "2016-05-01: version 2.1: notify that command-line-only version does nothing",
  };
}
