#include "TableModel.h"

TableModel::TableModel(QObject *parent) : QAbstractTableModel(parent)
{
    m_columnCount = 6;
    m_rowCount = 12;
    // 创建数据容器并初始化
    for (int i = 0; i < m_rowCount; i++)
    {
        QVector<qreal>* dataVec = new QVector<qreal>(m_columnCount);
        for (int k = 0; k < dataVec->size(); k++)
        {
            dataVec->replace(k, 100 + qrand() % 50);
        }
        m_data.append(dataVec);
    }
    // 每隔2秒超时
    timer.start(2000);
    connect(&timer, SIGNAL(timeout()), this, SLOT(onGenerateData()));
}

TableModel::~TableModel()
{
    qDeleteAll(m_data);
}

int TableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_data.count();
}

int TableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_columnCount;
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal)
        return QString("201%1").arg(section);
    else
        return QString("%1").arg(section + 1);
}

QVariant TableModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {
        return m_data[index.row()]->at(index.column());
    }
    else if (role == Qt::EditRole)
    {
        return m_data[index.row()]->at(index.column());
    }

    return QVariant();
}

bool TableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() && role == Qt::EditRole)
    {
        m_data[index.row()]->replace(index.column(), value.toDouble());
        emit dataChanged(index, index);
        return true;
    }
    return false;
}

Qt::ItemFlags TableModel::flags(const QModelIndex &index) const
{
    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

void TableModel::generateData()
{
    // 生成新的数据
    for (int i = 0; i < m_rowCount; i++)
    {
        for (int k = 0; k < m_data.at(i)->size(); k++)
        {
            m_data.at(i)->replace(k, 100 + qrand() % 50);
        }
    }
    QModelIndex leftTop = index(0, 0);
    QModelIndex rightBottom = index(m_rowCount - 1, m_columnCount - 1);
    // 生成新数据后发送模型数据发生变化的信号dataChanged
    emit dataChanged(leftTop, rightBottom);
}

void TableModel::onGenerateData()
{
    generateData();
}


