/****************************************************************************
**
** Copyright (C) 2012 Nokia Corporation and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/
**
** This file is part of the Qt Designer of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  It exists for the convenience
// of Qt Designer.  This header
// file may change from version to version without notice, or even be removed.
//
// We mean it.
//

#ifndef QTRESOURCEEDITOR_H
#define QTRESOURCEEDITOR_H

#include <QtCore/QScopedPointer>
#include <QtGui/QDialog>

QT_BEGIN_NAMESPACE

class QtResourceModel;
class QDesignerDialogGuiInterface;
class QDesignerFormEditorInterface;

class QtResourceEditorDialog : public QDialog
{
    Q_OBJECT
public:
    QtResourceModel *model() const;
    void setResourceModel(QtResourceModel *model);

    QString selectedResource() const;

    static QString editResources(QDesignerFormEditorInterface *core, QtResourceModel *model,
                                 QDesignerDialogGuiInterface *dlgGui, QWidget *parent = 0);

    // Helper to display a message box with rcc logs in case of errors.
    static void displayResourceFailures(const QString &logOutput, QDesignerDialogGuiInterface *dlgGui, QWidget *parent = 0);

public slots:
    virtual void accept();

private:
    QtResourceEditorDialog(QDesignerFormEditorInterface *core, QDesignerDialogGuiInterface *dlgGui, QWidget *parent = 0);
    ~QtResourceEditorDialog();

    QScopedPointer<class QtResourceEditorDialogPrivate> d_ptr;
    Q_DECLARE_PRIVATE(QtResourceEditorDialog)
    Q_DISABLE_COPY(QtResourceEditorDialog)

    Q_PRIVATE_SLOT(d_func(), void slotQrcFileInserted(QtQrcFile *))
    Q_PRIVATE_SLOT(d_func(), void slotQrcFileMoved(QtQrcFile *))
    Q_PRIVATE_SLOT(d_func(), void slotQrcFileRemoved(QtQrcFile *))
    Q_PRIVATE_SLOT(d_func(), void slotResourcePrefixInserted(QtResourcePrefix *))
    Q_PRIVATE_SLOT(d_func(), void slotResourcePrefixMoved(QtResourcePrefix *))
    Q_PRIVATE_SLOT(d_func(), void slotResourcePrefixChanged(QtResourcePrefix *))
    Q_PRIVATE_SLOT(d_func(), void slotResourceLanguageChanged(QtResourcePrefix *))
    Q_PRIVATE_SLOT(d_func(), void slotResourcePrefixRemoved(QtResourcePrefix *))
    Q_PRIVATE_SLOT(d_func(), void slotResourceFileInserted(QtResourceFile *))
    Q_PRIVATE_SLOT(d_func(), void slotResourceFileMoved(QtResourceFile *))
    Q_PRIVATE_SLOT(d_func(), void slotResourceAliasChanged(QtResourceFile *))
    Q_PRIVATE_SLOT(d_func(), void slotResourceFileRemoved(QtResourceFile *))

    Q_PRIVATE_SLOT(d_func(), void slotCurrentQrcFileChanged(QListWidgetItem *))
    Q_PRIVATE_SLOT(d_func(), void slotCurrentTreeViewItemChanged(const QModelIndex &))
    Q_PRIVATE_SLOT(d_func(), void slotListWidgetContextMenuRequested(const QPoint &))
    Q_PRIVATE_SLOT(d_func(), void slotTreeViewContextMenuRequested(const QPoint &))
    Q_PRIVATE_SLOT(d_func(), void slotTreeViewItemChanged(QStandardItem *))

    Q_PRIVATE_SLOT(d_func(), void slotNewQrcFile())
    Q_PRIVATE_SLOT(d_func(), void slotImportQrcFile())
    Q_PRIVATE_SLOT(d_func(), void slotRemoveQrcFile())
    Q_PRIVATE_SLOT(d_func(), void slotMoveUpQrcFile())
    Q_PRIVATE_SLOT(d_func(), void slotMoveDownQrcFile())

    Q_PRIVATE_SLOT(d_func(), void slotNewPrefix())
    Q_PRIVATE_SLOT(d_func(), void slotAddFiles())
    Q_PRIVATE_SLOT(d_func(), void slotChangePrefix())
    Q_PRIVATE_SLOT(d_func(), void slotChangeLanguage())
    Q_PRIVATE_SLOT(d_func(), void slotChangeAlias())
    Q_PRIVATE_SLOT(d_func(), void slotClonePrefix())
    Q_PRIVATE_SLOT(d_func(), void slotRemove())
    Q_PRIVATE_SLOT(d_func(), void slotMoveUp())
    Q_PRIVATE_SLOT(d_func(), void slotMoveDown())
};

QT_END_NAMESPACE

#endif

