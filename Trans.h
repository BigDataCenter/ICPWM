void Trans(int MODNUM, int MODLINK, int VMTYPE, int BUDGET)
{//assign BW to edges between modules and adjust VM and BW considering budget
    int i, j, k, MaxCloudIndex, VMT, GI, size;
    
    AssignPM(MODNUM, MODLINK);                //assign PM
    AssignBW(MODNUM, MODLINK);                //assign BW
    CalculateCost(MODNUM, MODLINK);            //calculate cost
    if(TotalCost < BUDGET)
    {//if within budget
        if(UsedCloudNum > 1)
        {//if uses more than one cloud
            for(i = 0; i < UsedCloudNum; i++)
            {
                for(j = i + 1; j < UsedCloudNum; j++)
                {
                    if(BWTypeBetweenClouds[UsedCloud[i]][UsedCloud[j]] < BWTYPE - 1)
                    {//upgrade BW
                        BWTypeBetweenClouds[UsedCloud[i]][UsedCloud[j]]++;
                        BWTypeBetweenClouds[UsedCloud[j]][UsedCloud[i]]++;
                        UpdateBWChanges(i, j, MODLINK);
                        CalculateCost(MODNUM, MODLINK);
                        if(TotalCost > BUDGET && BWTypeBetweenClouds[UsedCloud[i]][UsedCloud[j]] > 0)
                        {//if over budget, restore
                            BWTypeBetweenClouds[UsedCloud[i]][UsedCloud[j]]--;
                            BWTypeBetweenClouds[UsedCloud[j]][UsedCloud[i]]--;
                            UpdateBWChanges(i, j, MODLINK);
                            break;
                        }
                    }
                    
                }
            }
        }
    }
    else
    {//if over budget, downgrade VM
        while (ExistVmToDowngrade(MODNUM))
            for (j = 1; j <= MODNUM; j++)
            {
                for (i = 0; i < MODNUM; i++)
                {
                    VMT = ATYPE[i][0];
                    GI    = ATYPE[i][1];
                    if (VT[VMT].Group[GI].size() == j)
                    {
                        if(ATYPE[i][0] > MINVT[i])
                        {
                            Downgrade(i, MODLINK);
                            CalculateCost(MODNUM, MODLINK);
                            if (TotalCost < BUDGET)
                                return;
                        }
                    }
                }
            }
    }
}
