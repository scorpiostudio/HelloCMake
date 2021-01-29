#include "BarModelMapperChartWidget.h"

BarModelMapperChartWidget::BarModelMapperChartWidget(QWidget *parent) : QWidget(parent)
{
    m_chart = new QChart;
    m_chart->setAnimationOptions(QChart::AllAnimations);

    m_chartView = new QChartView(m_chart);
    m_chartView->setRenderHint(QPainter::Antialiasing);
    QHBoxLayout* layout = new QHBoxLayout;
    layout->addWidget(m_chartView);
    setLayout(layout);
}

void BarModelMapperChartWidget::initModelMapper(QAbstractTableModel *model)
{
    QBarSeries *series = new QBarSeries;
    int first = 3;
    int count = 5;
    QVBarModelMapper *mapper = new QVBarModelMapper(this);
    mapper->setFirstBarSetColumn(1);
    mapper->setLastBarSetColumn(4);
    mapper->setFirstRow(first);
    mapper->setRowCount(count);
    // 设置mapper的数据集对象
    mapper->setSeries(series);
    // 设置mapper对应的数据Model
    mapper->setModel(model);
    m_chart->addSeries(series);

    QStringList categories;
    categories << "April" << "May" << "June" << "July" << "August";
    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    m_chart->createDefaultAxes();
    m_chart->setAxisX(axis, series);
}
