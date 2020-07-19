/******************************************************************************************************
 * (C) 2016 markummitchell@github.com. This file is part of Engauge Digitizer, which is released      *
 * under GNU General Public License version 2 (GPLv2) or (at your option) any later version. See file *
 * LICENSE or go to gnu.org/licenses for details. Distribution requires prior written permission.     *
 ******************************************************************************************************/

#ifndef WINDOW_TABLE_H
#define WINDOW_TABLE_H

#include <QObject>
#include <QString>
#include <QTableView>

class QMouseEvent;
class WindowModelBase;

/// Table view class with support for both drag-and-drop and copy-and-paste
class WindowTable : public QTableView
{
  Q_OBJECT;

public:
  /// Single constructor.
  WindowTable(WindowModelBase &model);
  ~WindowTable();

  /// Catch this table status change
  virtual void focusInEvent (QFocusEvent *);

  /// Catch this table status change
  virtual void focusOutEvent (QFocusEvent *);

  /// Trigger drag operation if cursor was dragged more than a minimum distance
  virtual void mouseMoveEvent (QMouseEvent *event);

  /// Track the starting point of drag operations
  virtual void mousePressEvent (QMouseEvent *event);

  /// Catch this table status change
  virtual void selectionChanged(const QItemSelection &selected,
                                const QItemSelection &deselected);

signals:
  /// Sent when a change occurs that should affect the Copy menu item
  void signalTableStatusChange ();

private:
  WindowTable();

  void doDragAndClipboardCopy();
  QString exportText () const;

  QPoint m_pressPos;
};

#endif // WINDOW_TABLE_H
