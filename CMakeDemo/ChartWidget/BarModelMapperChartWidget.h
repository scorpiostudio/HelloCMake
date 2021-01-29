#ifndef BARMODELMAPPERCHARTWIDGET_H
#define BARMODELMAPPERCHARTWIDGET_H

#include <QWidget>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QVXYModelMapper>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QVBarModelMapper>
#include <QtWidgets/QHeaderView>
#include <QtCharts/QBarCategoryAxis>
#include <QHBoxLayout>

QT_CHARTS_USE_NAMESPACE

/**
 * @brief 柱状图ModelMapper报表界面类
 */
class BarModelMapperChartWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BarModelMapperChartWidget(QWidget *parent = NULL);
    /**
     * @brief 初始化ModelMapper
     * @param model
     */
    void initModelMapper(QAbstractTableModel* model);
private:
    QChart* m_chart;//报表组件
    QChartView* m_chartView;//报表视图组件
};

#endif // BARMODELMAPPERCHARTWIDGET_H
