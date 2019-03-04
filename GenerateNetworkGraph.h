void GenerateNetworkGraph(int numNodes, int cloudIndex, double CPU, double IO, double storage, double trans)
{//generate clouds
    int        i;
    
    for(i = 0; i < numNodes; i ++)
    {
        PM[cloudIndex][i].CPU        = CPU;
        PM[cloudIndex][i].IO        = IO;
        PM[cloudIndex][i].storage    = storage;
        PM[cloudIndex][i].trans        = trans;
    }
}
