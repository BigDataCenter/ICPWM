void CalculateVCost(int MODNUM)
{//calculate cost on each module's VM
    int i;
    
    VCost = 0;
    for(i = 0; i < MODNUM; i++)
    {
        VCost += V[i].cost;
    }
}

void CalculateECost(int MODLINK)
{//calculate cost on each edge
    int i;
    
    ECost = 0;
    for(i = 0; i < MODLINK; i++)
    {
        ECost += E[i].cost;
    }
}

void CalculateTime(int MODNUM, int MODLINK)
{//calculate total time by using modified Dijkstra's algorithm
    int i, j;
    double ERequest[MODLINK_MAX], d[MODNUM_MAX] = {};
    
    for(i = 0; i < MODLINK; i++)
    {
        ERequest[i] = E[i].time + V[E[i].to].time;
    }
    for(j = 0; j < MODNUM; j++)
    {
        for(i = 0; i < MODLINK; i++)
        {
            if(j == E[i].from && d[E[i].to] < d[E[i].from] + ERequest[i])
            {
                d[E[i].to] = d[E[i].from] + ERequest[i];
            }
        }
    }
    TotalTime = d[MODNUM - 1];
}

void UpdateEdgeChanges(int EdgeIndex)
{//update the time and cost effected by EdgeIndex's BW change
    if (E[EdgeIndex].used == true)
        return;
    if (ATYPE[E[EdgeIndex].from][0] == ATYPE[E[EdgeIndex].to][0] && ATYPE[E[EdgeIndex].from][1] == ATYPE[E[EdgeIndex].to][1] && ATYPE[E[EdgeIndex].to][1] != -1)
    {
        E[EdgeIndex].time = 0;
        E[EdgeIndex].cost = 0;
    }
    else
    {
        E[EdgeIndex].time = E[EdgeIndex].size / VT[ATYPE[E[EdgeIndex].from][0]].IO + E[EdgeIndex].size / VT[ATYPE[E[EdgeIndex].to][0]].IO + E[EdgeIndex].size / E[EdgeIndex].BW;
        E[EdgeIndex].cost = (E[EdgeIndex].size / VT[ATYPE[E[EdgeIndex].from][0]].IO) * VT[ATYPE[E[EdgeIndex].from][0]].price + (E[EdgeIndex].size / VT[ATYPE[E[EdgeIndex].to][0]].IO) * VT[ATYPE[E[EdgeIndex].to][0]].price + E[EdgeIndex].size * E[EdgeIndex].price;
    }
}

void UpdateVmChanges(int ModIndex, int MODLINK)
{//update the time and cost effected by ModIndex's VM change
    //update the time and cost on modules
    if (V[ModIndex].used == true)
        return;
    V[ModIndex].time = VT[ATYPE[ModIndex][0]].CPU*V[ModIndex].complexity;
    V[ModIndex].cost = V[ModIndex].time*VT[ATYPE[ModIndex][0]].price;
    list<int>::iterator GroupHead = VT[ATYPE[ModIndex][0]].Group[ATYPE[ModIndex][1]].begin();
    if (*GroupHead == ModIndex)
        V[ModIndex].time = V[ModIndex].time + VT[ATYPE[ModIndex][0]].StartUpTime;
    for(int i = 0; i < MODLINK; i++)
    {//update the time and cost on edges
        if(E[i].from == ModIndex || E[i].to == ModIndex)
        {
            if (E[i].used == true)
                continue;
            if (ATYPE[E[i].from][0] == ATYPE[E[i].to][0] && ATYPE[E[i].from][1] == ATYPE[E[i].to][1] && ATYPE[E[i].to][1] != -1)
            {
                E[i].time = 0;
                E[i].cost = 0;
            }
            else
            {
                E[i].time = E[i].size / VT[ATYPE[E[i].from][0]].IO + E[i].size / VT[ATYPE[E[i].to][0]].IO + E[i].size / E[i].BW;
                E[i].cost = (E[i].size / VT[ATYPE[E[i].from][0]].IO) * VT[ATYPE[E[i].from][0]].price + (E[i].size / VT[ATYPE[E[i].to][0]].IO) * VT[ATYPE[E[i].to][0]].price + E[i].size * E[i].price;
            }
        }
    }
}

void UpdateBWChanges(int i, int j, int MODLINK)
{
    int k;
    for (k = 0; k < MODLINK; k++)
    {
        if (MPC[E[k].from].cloud == UsedCloud[i] && MPC[E[k].to].cloud == UsedCloud[j])
        {
            E[k].BW = BW[UsedCloud[i]][BWTypeBetweenClouds[UsedCloud[i]][UsedCloud[j]]].value;
            E[k].price = BW[UsedCloud[i]][BWTypeBetweenClouds[UsedCloud[i]][UsedCloud[j]]].price;
            UpdateEdgeChanges(k);
        }
    }
}

void CalculateWaitTimeCost(int MODNUM, int MODLINK)
{//calculate the storage cost during waiting time by modified Dijkstra's algorithm
    int i, j, indegree[MODNUM_MAX] = {}, count;
    double d[MODNUM_MAX] = {}, ERequest[MODLINK_MAX], latest, earliest;
    
    for(i = 0; i < MODLINK; i++)
    {
        ERequest[i] = E[i].time + V[E[i].to].time;
    }
    for(j = 0; j < MODNUM; j++)
    {
        for(i = 0; i < MODLINK; i++)
        {
            if(j == E[i].from && d[E[i].to] < d[E[i].from] + ERequest[i])
            {
                d[E[i].to] = d[E[i].from] + ERequest[i];
            }
        }
    }
    for(i = 0; i < MODLINK; i++)
    {//calculate indegree for each module
        indegree[E[i].to]++;
    }
    SCost = 0;
    for(i = 0; i < MODNUM; i++)
    {
        if(indegree[i] > 1)
        {//for a module whose indegree > 1
            latest = d[i];//get the latest data arriving time
            earliest = MAX_TIME;
            for(j = 0; j < MODLINK; j++)
            {
                if(E[j].to == i)
                    if(earliest > d[E[j].from] + ERequest[j])
                        earliest = d[E[j].from] + ERequest[j];//calculate the earliest data arriving time
            }
            SCost += VT[ATYPE[i][0]].price * (latest - earliest);//calculate the storage cost
        }
    }
}

void CalculateCost(int MODNUM, int MODLINK)
{
    CalculateVCost(MODNUM);
    CalculateECost(MODLINK);
    CalculateWaitTimeCost(MODNUM, MODLINK);
    TotalCost = VCost + ECost + SCost;
}

void CalculateSTD(double* A, int n, double* mean, double* std)
{
    int i;
    
    *mean = 0;
    *std = 0;
    for(i = 0; i < n; i++)
        *mean += A[i];
    
    *mean /= n;
    for(i = 0; i < n; i++)
        *std += (A[i] - *mean)*(A[i] - *mean);
    
    *std /= n - 1;
    *std = sqrt(*std);
}

