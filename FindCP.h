int FindCP(int MODNUM, int MODLINK, int VMTPYE)
{//find CP by modified Dijkstra's algorithm and return the module number on CP
    int i, j, k, count, GI, VMT, EtoRemove, NewGI, flag, SegNum, Seg[MODNUM_MAX][2];
    double td, Request[MODNUM_MAX], maxStorage, maxComplexity, d[MODNUM_MAX], pre[MODNUM_MAX], ReverseCP[MODNUM_MAX], ERequest[MODLINK_MAX];
    list<int>::iterator GroupPoint, NextGroupPoint, StartPoint, EndPoint;
    list<int> NewGroupList, GroupList;
    bool *IfOnCP;
    
    ////find the max storage and max complexity on modules
    //maxStorage        = FindMaxStorage(MODNUM);
    //maxComplexity    = FindMaxComplexity(MODNUM);
    //if(ATYPEIsEmpty(MODNUM))
    //{//if VM types haven't been assigned
    //    for(i = 0; i < MODNUM; i++)
    //    {//calculate the module weight considering module storage and complexity
    //        Request[i] = V[i].storage/VT[VMTPYE-1].IO + V[i].complexity*VT[VMTPYE-1].CPU;
    //    }
    //    for(i = 0; i < MODNUM; i++)
    //    {
    //        d[i]    = 0;
    //        pre[i]    = -1;
    //    }
    //    for(j = 0; j < MODNUM; j++)
    //    {
    //        for(i = 0; i < MODLINK; i++)
    //        {
    //            if(j == E[i].from && d[E[i].to] < d[E[i].from] + Request[E[i].to])
    //            {
    //                d[E[i].to] = d[E[i].from] + Request[E[i].to];
    //                pre[E[i].to] = E[i].from;
    //            }
    //        }
    //    }
    //    i = MODNUM - 1;
    //    count = 0;
    //    ReverseCP[count++] = i;
    //    while(i > 0)
    //    {//calculate reverse CP path
    //        ReverseCP[count++] = pre[i];
    //        i = pre[i];
    //    }
    //    for(i = 0; i < count; i++)
    //    {//calculate CP path
    //        CP[i] = ReverseCP[count - i - 1];
    //    }
    //    //for(i = 0; i < count; i++)
    //    //{//insert sort the module in CP by descent order of weight
    //    //    j = i;
    //    //    while(j > 0 && Request[CP[j-1]] < Request[CP[j]])
    //    //    {
    //    //        SWAPINT(&CP[j-1], &CP[j]);
    //    //        j--;
    //    //    }
    //    //}
    //}
    //else
    //{//if VM types have been assigned
    flag = 0;
    for (i = 0; i < MODNUM; i++)
    {
        if (V[i].used == false)
        {
            CP[0] = i;
            for (k = 0; k < MODLINK; k++)
            {
                if (E[k].used == false && (E[k].to == i || E[k].from == i))
                {
                    flag = 1;
                    break;
                }
            }
            
        }
    }
    if (flag == 0)
        return 1;
    for(i = 0; i < MODLINK; i++)
    {//calculate the time on edge and module as weight
        if (E[i].used == false)
            ERequest[i] = E[i].time + V[E[i].to].time;
    }
    for(i = 0; i < MODNUM; i++)
    {
        if (V[i].used == false)
        {
            d[i]    = 0;
            pre[i]    = -1;
        }
    }
    for(j = 0; j < MODNUM; j++)
    {
        for(i = 0; i < MODLINK; i++)
        {
            if (V[j].used == false && E[i].used == false)
                if(j == E[i].from && d[E[i].to] < d[E[i].from] + ERequest[i])
                {
                    d[E[i].to] = d[E[i].from] + ERequest[i];
                    pre[E[i].to] = E[i].from;
                }
        }
    }
    //find the end module of CP
    td = 0;
    for (j = 0; j < MODNUM; j++)
        if (V[j].used == false && td < d[j])
        {
            td    = d[j];
            i    = j;
        }
    count = 0;
    ReverseCP[count++] = i;
    while(pre[i] >= 0)
    {//calculate reverse CP path
        ReverseCP[count++]    = pre[i];
        i                    = pre[i];
    }
    //count--;
    for(i = 0; i < count; i++)
    {//calculate CP path
        CP[i] = ReverseCP[count - i - 1];
    }
    //for(i = 0; i < count; i++)
    //{//insert sort the module in CP by descent order of weight
    //    j = i;
    //    while(j > 0 && V[CP[j-1]].complexity*VT[ATYPE[CP[j-1]][0]].CPU < V[CP[j]].complexity*VT[ATYPE[CP[j]][0]].CPU)
    //    {
    //        SWAPINT(&CP[j-1], &CP[j]);
    //        j--;
    //    }
    //}
    
    //cut the connection between CP and nonCP
    i = 0;
    while (i < count)
    {
        VMT            = ATYPE[CP[i]][0];
        GI            = ATYPE[CP[i]][1];
        GroupPoint    = VT[VMT].Group[GI].begin();
        if (VT[VMT].Group[GI].size() > 1)
        {
            IfOnCP = (bool *)malloc(sizeof(bool)*VT[VMT].Group[GI].size());
            j = 0;
            while(GroupPoint != VT[VMT].Group[GI].end())
            {
                IfOnCP[j] = false;
                for (k = 0; k < count; k++)
                {
                    if (*GroupPoint == CP[k])
                    {
                        IfOnCP[j] = true;
                        break;
                    }
                }
                GroupPoint++;
                j++;
            }
            GroupPoint = VT[VMT].Group[GI].begin();
            SegNum                = 0;
            Seg[SegNum++][0]    = *GroupPoint;
            for (j = 0; j < VT[VMT].Group[GI].size() - 1; j++)
            {
                NextGroupPoint = GroupPoint;
                NextGroupPoint++;
                if (IfOnCP[j] != IfOnCP[j + 1] || (IfOnCP[j] == IfOnCP[j + 1] && *GroupPoint == CP[i] && *NextGroupPoint != CP[i + 1]) || (IfOnCP[j] == IfOnCP[j + 1] && *GroupPoint != CP[i] && *NextGroupPoint == CP[i + 1]))
                {
                    Seg[SegNum-1][1]    = *GroupPoint;
                    Seg[SegNum++][0]    = *NextGroupPoint;
                }
                GroupPoint++;
            }
            Seg[SegNum - 1][1] = *GroupPoint;
            free(IfOnCP);
            if (SegNum > 1)
            {
                for (j = 1; j < SegNum; j++)
                {
                    GroupPoint = VT[VMT].Group[GI].begin();
                    while (GroupPoint != VT[VMT].Group[GI].end())
                    {
                        if (*GroupPoint == Seg[j][0])
                            StartPoint    = GroupPoint;
                        if (*GroupPoint == Seg[j][1])
                        {
                            EndPoint = GroupPoint;
                            EndPoint++;
                        }
                        GroupPoint++;
                        k++;
                    }
                    Cut(VMT, GI, StartPoint, EndPoint);
                }
            }
        }
        i++;
    }
    //}
    
    return count;
}
