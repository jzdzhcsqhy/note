#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtNote.h"

class QtNote : public QMainWindow
{
	Q_OBJECT

public:
	QtNote(QWidget *parent = Q_NULLPTR);

private:
	Ui::QtNoteClass ui;
};
