void AssignPM(int MODNUM, int MODLINK)
{//assign module's VM to clouds' PM
    int i, j, PMN, VMT, GI;
    double PMS;
    list<int>::iterator GroupPoint;
    
    for(i = 0; i < CLOUDNUM; i++)
    {//assign each cloud's PM
        PMS = PM[i][0].storage;
        PMN = PMNUM;
        j = 0;
        while(j < MODNUM)
        {//assign to each module
            VMT = ATYPE[j][0];
            GI    = ATYPE[j][1];
            if(MPC[j].cloud != -1)
            {
                j++;
                continue;
            }
            if(PMN == 1) //PM used out
                break;
            if(PM[i][0].CPU > VT[VMT].CPU || PM[i][0].IO < VT[VMT].IO || PM[i][0].storage < VT[VMT].storage) //PM cannot meet VM's needs
            {
                j++;
                continue;
            }
            if(PMS < VT[VMT].storage)//current PM is short of storage
            {
                PMN--;
                PMS     = PM[i][0].storage;
                PMS -= VT[VMT].storage;
            }
            else//cut off the storage used by VM
                PMS        -= VT[VMT].storage;
            GroupPoint     = VT[VMT].Group[GI].begin();
            while (GroupPoint != VT[VMT].Group[GI].end())
            {
                MPC[*GroupPoint].cloud    = i;            //record module j's cloud index
                MPC[*GroupPoint].pm        = PMNUM - PMN;    //record module j's PM index
                IfCloudInUse[i]            = 1;                //record whether cloud i is in use
                GroupPoint++;
            }
            j++;
        }
    }
    for(i = 0; i < MODNUM; i++)
    {//check whether there is a module's VM can be assigned to any PM
        if(MPC[i].cloud == -1)
        {
            printf("Module %d's VM cannot meet by PM!\n", i);
            getchar();
            exit(0);
        }
    }
    j = 0;
    for(i = 0; i < CLOUDNUM; i++)
    {//record which and how many clouds in use
        if(IfCloudInUse[i] == 1)
        {
            UsedCloud[j++] = i;
        }
    }
    UsedCloudNum = j;
}

void AssignBW(int MODNUM, int MODLINK)
{//assign BW to each edge
    int i, j, indegree, outdegree;
    
    for (i = 0; i < MODNUM; i++)
        V[i].used = false;
    for (j = 0; j < MODLINK; j++)
        E[j].used = false;
    for(i = 0; i < MODLINK; i++)
    {
        if (MPC[E[i].from].cloud == MPC[E[i].to].cloud && !(ATYPE[E[i].from][0] == ATYPE[E[i].to][0] && ATYPE[E[i].from][1] == ATYPE[E[i].to][1]))
        {//if intra-cloud data transfer
            outdegree = 1;
            for(j = 0; j < MODLINK; j++)
            {//calculate the number of edges leaving module(E[i].from) intra-cloud
                if(i == j)
                    continue;
                if (E[i].from == E[j].from && MPC[E[i].to].cloud == MPC[E[j].to].cloud && !(ATYPE[E[j].from][0] == ATYPE[E[j].to][0] && ATYPE[E[j].from][1] == ATYPE[E[j].to][1]))
                    outdegree++;
            }
            E[i].BW        = PM[MPC[E[i].from].cloud][MPC[E[i].from].pm].trans/outdegree;//share BW
            E[i].price    = 0;//no cost intra-cloud
            UpdateEdgeChanges(i);
        }
        else if (MPC[E[i].from].cloud != MPC[E[i].to].cloud)
        {
            outdegree = 1;
            for(j = 0; j < MODLINK; j++)
            {//calculate the number of edges leaving module(E[i].from) intra-cloud
                if(i == j)
                    continue;
                if(E[i].from == E[j].from && MPC[E[i].to].cloud == MPC[E[j].to].cloud)
                    outdegree++;
            }
            E[i].BW        = BW[MPC[E[i].from].cloud][BWTypeBetweenClouds[MPC[E[i].from].cloud][MPC[E[i].to].cloud]].value/outdegree;//assign BW inter-cloud
            E[i].price    = BW[MPC[E[i].from].cloud][BWTypeBetweenClouds[MPC[E[i].from].cloud][MPC[E[i].to].cloud]].price;            //assign price of BW inter-cloud
            UpdateEdgeChanges(i);
        }
    }
}
