#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QHBoxLayout>
#include <QTableView>
#include "ChartWidget/BarModelMapperChartWidget.h"
#include "Model/TableModel.h"

/**
 * @brief 程序主界面类
 */
class MainWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = NULL);

private:
    BarModelMapperChartWidget* m_barModelMapperChartWidget;//报表组件
    QTableView* m_tableView;//表格视图组件
    TableModel* m_model;//表格模型
};

#endif // MAINWINDOW_H
