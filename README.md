# broadcast_storm_simulator
broadcast storm simulator on OMNet++

A broadcast storm or broadcast radiation is the accumulation of broadcast and multicast traffic on a computer network. Extreme amounts of broadcast traffic constitute a broadcast storm. It can consume sufficient network resources so as to render the network unable to transport normal traffic. A packet that induces such a storm is occasionally nicknamed a Chernobyl packet.

Most commonly the cause is a switching loop in the Ethernet network topology (i.e. two or more paths exist between switches). A simple example is both ends of a single Ethernet patch cable connected to a switch. As broadcasts and multicasts are forwarded by switches out of every port, the switch or switches will repeatedly rebroadcast broadcast messages and flood the network. Since the layer-2 header does not support a time to live (TTL) value, if a frame is sent into a looped topology, it can loop forever.

In my project, it has a loop that it will cause the broadcast storm. You can download and put all file on the OMNet++ or the other network simulation.
