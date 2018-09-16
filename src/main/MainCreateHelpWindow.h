/******************************************************************************************************
 * (C) 2018 markummitchell@github.com. This file is part of Engauge Digitizer, which is released      *
 * under GNU General Public License version 2 (GPLv2) or (at your option) any later version. See file *
 * LICENSE or go to gnu.org/licenses for details. Distribution requires prior written permission.     *
 ******************************************************************************************************/

#ifndef MAIN_CREATE_HELP_WINDOW_H
#define MAIN_CREATE_HELP_WINDOW_H

#include <QObject>

class MainWindow;

/// Class to create help window for MainWindow class. This is derived from QObject
/// so the tr function can be accessed more easily
class MainCreateHelpWindow : public QObject
{
public:
  /// Single constructor.
  MainCreateHelpWindow();

  /// Create HelpWindow
  void create (MainWindow &mw);

};

#endif // MAIN_CREATE_HELP_WINDOW_H