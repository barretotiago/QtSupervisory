#ifndef PLOTTER_H
#define PLOTTER_H

#include <QWidget>
#include <vector>

using namespace std;

class Plotter : public QWidget
{
    Q_OBJECT

private:
    vector<float> ptempo, pvalores;
public:
    explicit Plotter(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);

signals:

public slots:
    /**
     * @brief armazenaPontos recebe como parâmetros os vetores que armazenam os valores de tempo e dos dados, respctivamente
     */
    void armazenaPontos(vector<float>, vector<float>);
};

#endif // PLOTTER_H
