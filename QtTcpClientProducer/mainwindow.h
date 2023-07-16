#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QDebug>

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
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
    /**
   * @brief timerEvent Controla o intervalo de tempo que  a função putData() deve ser executada
   */
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
   * @brief putData manda os dados para o servidor
   */
  void putData();
public slots:
  /**
   * @brief timerControl Controla o envio de dados ao servidor
   */
  void timerControl();
  /**
   * @brief tcpConnect Faz a conexão TCP entre o cliente produtor de dados e o servidor
   */
  void tcpConnect();
  /**
   * @brief tcpDisconnect Faz a desconexão TCP entre o cliente produtor de dados e o servidor
   */
  void tcpDisconnect();
  /**
   * @brief mudaMax Impede que o slider MAX tenha valor menor que o slider MIN
   */
  void mudaMax();
  /**
   * @brief mudaMin Impede que o slider MIN tenha valor maior que o slider MAX
   */
  void mudaMin();
  /**
   * @brief mudaTempo Guarda o valor do slider na variável tempo e reinicia o temporizador
   * @param _tempo Armazena o valor de tempo selecionado no slider
   */
  void mudaTempo(int _tempo);

private:
  /**
   * @brief ui Acessa a lista de objetos visuais
   */
  Ui::MainWindow *ui;
  /**
   * @brief socket Estabele a conexão entre o servidor e o cliente
   */
  QTcpSocket *socket;
};

#endif // MAINWINDOW_H
