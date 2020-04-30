# Low-Cost-Multipath-Routing-Protocol-by-Adapting-Opportunistic-Routing-in-Wireless-Sensor-Networks
This repository is an implementation of the paper - "Low-Cost Multipath Routing Protocol  by Adapting Opportunistic Routing  in Wireless Sensor Networks ". However the algorithm mentioned in the paper had some flaws due to which the code is implemented on a modified algorithm in order to showcase the concept of the paper.

Requirements:
The code was implemented using CodeBlocks IDE

ABSTRACT:
The wireless sensor networks (WSNs) are special network which has purpose of gathering information in certain area. The reliability is an important factor in the WSNs for transferring the information to the destination. However, the reliability is decreased while multi-hop transmission of the information because a node which composes the WSNs has limited communication range. Also, the transmission process may suffer from the various factors including the faulty nodes and network congestion. To solve this, the multipath routing protocols, which transfer the information through a multipath to the destination at the same time, have been proposed for improving the reliability.  In the existing multipath routing protocols, however, the network scale should be sufficient for constructing multipath to guarantee of the disjoint path and the energy is consumed for multipath construction/maintenance consistently. The energy consumption leads to the reduction of networks lifetime and the restricted network scale may not even ensure the enough reliability. Thus, we proposed Low-Cost Multipath Routing Protocol by Adapting Opportunistic Routing which can reduce consistent energy consumption and less affected by network scale. The proposed protocol exploits the opportunistic routing that improves the single-hop reliability in order to improve the reliability in each path. It reduces the number of paths, which constructed for ensuring the enough reliability. Also, a fewer path reduces the energy consumption and alleviates the restriction of network scale. Simulation results show that the proposed protocol provides the more reliable performance than the existing protocols in the network, which restricted scale, and consumes the less energy.

> Note: The algorithm 1 in the paper had a flaw which i have confirmed with the author and have tried to fix it in order to make the code work.