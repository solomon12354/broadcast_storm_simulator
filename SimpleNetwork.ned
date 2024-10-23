network SimpleNetwork
{
    submodules:
        Alice: Node {
            
        }
        Bob: Node{
        }
        devices[4]: Node{
        }
        Cat: Node{
        }
        Dog: Node{
        }
        
    // 定義連接
    connections:
        Alice.port++ <--> devices[0].port++;
        Bob.port++ <--> devices[1].port++;
        Cat.port++ <--> devices[2].port++;
        Dog.port++ <--> devices[3].port++;
        for i = 0..1{
            devices[i].port++ <--> devices[2].port++;
            
            devices[i].port++ <--> devices[3].port++;
        }
        
}
