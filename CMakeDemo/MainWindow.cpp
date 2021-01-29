#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
{
    m_model = new TableModel();
    m_barModelMapperChartWidget = new BarModelMapperChartWidget(this);
    m_barModelMapperChartWidget->initModelMapper(m_model);

    m_tableView = new QTableView(this);
    m_tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    m_tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    m_tableView->setModel(m_model);
    QHBoxLayout* layout = new QHBoxLayout;
    layout->addWidget(m_tableView);
    layout->addWidget(m_barModelMapperChartWidget);
    setLayout(layout);
    resize(800, 400);
}


