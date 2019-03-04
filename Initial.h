void Initial(int MODNUM, int MODLINK, int VMTYPE)
{//initial all the global variables
    int i, j;
    
    TotalTime = 0;
    TotalCost = 0;
    
    for (i = 0; i < VMTYPE; i++)
    {
        VT[i].Group.clear();
    }
    for(i = 0; i < MODNUM; i++)
    {
        ATYPE[i][0]        = -1;
        ATYPE[i][1]        = -1;
        CP[i]            = 0;
        V[i].cost        = 0;
        V[i].time        = 0;
        MPC[i].cloud    = -1;
        MPC[i].pm        = -1;
    }
    
    for(j = 0; j < MODLINK; j++)
    {
        E[j].time    = 0;
        E[j].cost    = 0;
        E[j].BW        = -1;
        E[j].price    = -1;
    }
    
    for(i = 0; i < CLOUDNUM; i++)
    {
        UsedCloud[i]    = -1;
        IfCloudInUse[i]    = 0;
    }
    
    for(i = 0; i < CLOUDNUM; i++)
        for(j = 0; j < CLOUDNUM; j++)
            BWTypeBetweenClouds[i][j] = 0;
}
