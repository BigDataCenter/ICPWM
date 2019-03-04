double FindMaxStorage(int MODNUM)
{//find max storage on modules
    int i;
    double value = 0;
    
    for(i = 0; i < MODNUM; i++)
    {
        if(value < V[i].storage)
        {
            value = V[i].storage;
        }
    }
    return value;
}

double FindMaxComplexity(int MODNUM)
{//find max complexity on modules
    int i;
    double value = 0;
    
    for(i = 0; i < MODNUM; i++)
    {
        if(value < V[i].complexity)
        {
            value = V[i].complexity;
        }
    }
    return value;
}
