#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QDebug>
#include <vector>

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

private:
    /**
     * @brief tempo armazena o valor do tempo selecionado no slider
     */
    int tempo = 1;
public:
    /**
    * @brief tempoNorm armazena um vetor com os valores de tempo coletados
    */
   vector<float> tempoNorm;
   /**
    * @brief valorNorm armazena um vetor com os valores de dados coletados
    */
   vector <float> valorNorm;
  explicit MainWindow(QWidget *parent = 0);
   void timerEvent(QTimerEvent *event);
   /**
    * @brief timerId armazena o identificador retornado pela função startTimer()
    */
   int timerId;
   /**
    * @brief flag controla a função do botão Start/Stop
    */
   bool flag = true;

   /**
    * @brief getData coleta os dados produzidos no servidor
    */
   void getData();

  ~MainWindow();

  
public slots:

   /**
   * @brief getHost exibe as opções de hosts que produziram dados no servidor
   */
  void getHost();
  /**
   * @brief tcpConnect faz a conexão entre o consumidor e o servidro
   */
  void tcpConnect();
  /**
   * @brief tcpDisconnect desconeta o consumidor do servidor
   */
  void tcpDisconnect();
  /**
   * @brief mudaTempo Armazena o valor associado ao horiontal slider do tempo
   * @param _tempo
   */
  void mudaTempo(int _tempo);
  /**
   * @brief timerControl Controla o tempo em que os dados serão coletados
   */
  void timerControl();

signals:
    vector <float> emiteDados(vector<float>, vector<float>);

private:
  Ui::MainWindow *ui;
  QTcpSocket *socket;
};

#endif // MAINWINDOW_H
