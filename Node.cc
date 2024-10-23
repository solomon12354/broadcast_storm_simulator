#include "Node.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
Define_Module(Node);


void Node::initialize()
{
    numSent = 0;
    numReceived = 0;
    srand((int)time(NULL));
    char name[] = "Alice";

    EV << "My name is  " << getName() << endl;
    EV << "Device index = " << getDeviceIndex("devices") << endl;
    if (strcmp(name, getName()) == 0) {
        cMessage *msg = new cMessage("Hello Bob!");
        sendDelayed(msg, uniform(10, 30), "port$o", 0);
    }


}

void Node::handleMessage(cMessage *msg)
{
    // 當收到訊息時
    srand((int)time(NULL));
    EV << "Received message: " << msg->getName() << " at " << getName() << endl;
    numReceived++;
    int isDetecting = 0;
    // 如果是伺服器，只允許 Device 1 和 Device 3 互傳訊息
    if (strcmp("Bob", getName()) == 0) {
        delete msg;
        cMessage *newMsg = new cMessage("Hello Alice!");
        sendDelayed(newMsg, uniform(10, 30), "port$o", 0);

    }else if (strcmp("Alice", getName()) == 0) {
        delete msg;
        cMessage *newMsg = new cMessage("Hello Bob!");
        sendDelayed(newMsg, uniform(10, 30), "port$o", 0);
    }
    else{
        //EV << getName() << " " << senderGateIndex <<": Forwarding message to Device 1" << endl;
        int senderGateIndex = msg->getArrivalGate()->getIndex();
        EV << "senderGateIndex is "<< senderGateIndex << endl;
        int numberOfLine = gateSize("port$o");

        if(numberOfLine == 1){
            delete msg;
        }else{
            for (int i = 0; i < numberOfLine; i++) {
                if(i != senderGateIndex){
                    cMessage *newMsg = new cMessage(msg->getName());
                    sendDelayed(newMsg, uniform(10, 30), "port$o", i);
                }
            }
            delete msg;
        }
    }

}

int Node::getDeviceIndex(const char* deviceName)
{
    // 獲取伺服器埠的大小
    int size = gateSize("port$o");

    // 循環檢查每個埠，找到與指定裝置名稱匹配的埠
    for (int i = 0; i < size; i++) {
        cGate* outGate = gate("port$o", i);  // 取得指定索引的輸出埠
        const char* connectedNodeName = outGate->getNextGate()->getOwnerModule()->getName();
        if (strcmp(connectedNodeName, deviceName) == 0) {
            return i;
        }
    }

    return -1; // 如果找不到，返回 -1（錯誤情況）
}


void Node::finish()
{
    // 打印模擬結束時的統計數據
    EV << getName() << " sent " << numSent << " messages and received " << numReceived << " messages.\n";
}
