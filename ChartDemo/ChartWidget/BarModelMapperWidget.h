#ifndef BARMODELMAPPERWIDGET_H
#define BARMODELMAPPERWIDGET_H

#include <QWidget>
#include <QTableView>
#include "Model/TableModel.h"

class BarModelMapperWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BarModelMapperWidget(QWidget *parent = NULL);

};

#endif // BARMODELMAPPERWIDGET_H
