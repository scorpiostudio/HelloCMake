#ifndef TABLEMODEL_H
#define TABLEMODEL_H


#include <QAbstractTableModel>
#include <QHash>
#include <QRect>
#include <QVector>
#include <QTime>
#include <QColor>
#include <QTimer>
/**
 * @brief 数据模型
 */
class TableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit TableModel(QObject *parent = 0);
    virtual ~TableModel();
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
    Qt::ItemFlags flags(const QModelIndex &index) const;
    /**
     * @brief 生成数据
     */
    void generateData();
private slots:
    /**
     * @brief 定时器超时信号的槽函数
     */
    void onGenerateData();
private:
    QList<QVector<qreal> * > m_data;//模型数据容器
    int m_columnCount;//列数
    int m_rowCount;//行数
    QTimer timer;//定时器
};

#endif // TABLEMODEL_H
