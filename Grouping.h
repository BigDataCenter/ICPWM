void Grouping(int NumOfCP, int MODNUM, int MODLINK, int BUDGET, int type)
{
    int i, ModToUpgrade, VMT, GI;
    
    CheckZero(NumOfCP, MODLINK);
    switch (type)
    {
        case 2:
            i = 0;
            while (i < NumOfCP - 1)
            {
                if (ATYPE[CP[i]][0] == ATYPE[CP[i + 1]][0])
                    i++;
                else
                {
                    ModToUpgrade = ATYPE[CP[i]][0] < ATYPE[CP[i + 1]][0] ? CP[i] : CP[i + 1];
                    VMT = ATYPE[ModToUpgrade][0];
                    GI    = ATYPE[ModToUpgrade][1];
                    if (VT[VMT].Group[GI].size() == 1)
                    {
                        Upgrade(ModToUpgrade, MODLINK);
                        //CalculateCost(MODNUM, MODLINK);
                        //if (TotalCost > BUDGET)    //check whether over budget
                        //{
                        //    Downgrade(ModToUpgrade, MODLINK);
                        //}
                    }
                    i++;
                }
            }
            break;
        case 3:
            i = 0;
            while (i < NumOfCP - 1)
            {
                if (ATYPE[CP[i]][0] == ATYPE[CP[i + 1]][0])
                    i++;
                else
                {
                    ModToUpgrade = ATYPE[CP[i]][0] < ATYPE[CP[i + 1]][0] ? CP[i] : CP[i + 1];
                    VMT = ATYPE[ModToUpgrade][0];
                    GI = ATYPE[ModToUpgrade][1];
                    if (VT[VMT].Group[GI].size() > 1)
                    {
                        Upgrade(ModToUpgrade, MODLINK);
                        //CalculateCost(MODNUM, MODLINK);
                        //if (TotalCost > BUDGET)    //check whether over budget
                        //{
                        //    Downgrade(ModToUpgrade, MODLINK);
                        //}
                    }
                    i++;
                }
            }
            break;
        default:
            i = 0;
            while (i < NumOfCP - 1)
            {
                if (ATYPE[CP[i]][0] == ATYPE[CP[i + 1]][0])
                    i++;
                else
                {
                    ModToUpgrade = ATYPE[CP[i]][0] < ATYPE[CP[i + 1]][0] ? CP[i] : CP[i + 1];
                    Upgrade(ModToUpgrade, MODLINK);
                    //CalculateCost(MODNUM, MODLINK);
                    //if (TotalCost > BUDGET)    //check whether over budget
                    //{
                    //    Downgrade(ModToUpgrade, MODLINK);
                    //}
                    i++;
                }
            }
            break;
    }
    CheckZero(NumOfCP, MODLINK);
}
