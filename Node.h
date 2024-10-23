#ifndef __SIMPLENETWORK_NODE_H_
#define __SIMPLENETWORK_NODE_H_

#include <omnetpp.h>

using namespace omnetpp;

class Node : public cSimpleModule
{
  private:
    int numSent;     // 追蹤發送的訊息數
    int numReceived; // 追蹤接收到的訊息數

  protected:
    virtual void initialize() override;   // 初始化模組
    virtual void handleMessage(cMessage *msg) override; // 處理訊息
    virtual void finish() override;       // 模擬結束時的動作
    int getDeviceIndex(const char* deviceName); // 獲取裝置索引的函數

};

#endif
