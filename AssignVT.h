void AssignVT(int MODNUM, int MODLINK, int VMTYPE, int BUDGET)
{//assign VM to each module
    int i, j, NumOfCP, VMT, GI;
    list<int> glist;
    
    //make sure every module hasn't been optimized in this function
    for (i = 0; i < MODNUM; i++)
        V[i].used = false;
    //make sure every edge hasn't been optimized in this function
    for (j = 0; j < MODLINK; j++)
        E[j].used = false;
    if (ATYPEIsEmpty(MODNUM))
        for (i = 0; i < MODNUM; i++)
        {
            for (j = 0; j < VMTYPE; j++)
            {
                if (VT[j].storage >= V[i].storage)//check if the VM can meet the module's need
                    break;
            }
            if (j == VMTYPE)
            {
                printf("VM %d provided cannot meet module needs!\n", i);
                getchar();
                exit(0);
            }
            MINVT[i] = j;
            ATYPE[i][0] = j;
            ATYPE[i][1] = i;
            glist.clear();
            glist.assign(1, i);
            VT[j].Group.insert(make_pair(i, glist));
            UpdateVmChanges(i, MODLINK);
        }
    while (HaveUnusedOrNot(MODNUM) == 1)//check if there are still existing some modules to optimize
    {
        NumOfCP = FindCP(MODNUM, MODLINK, VMTYPE);
        if (CheckCPsVM(NumOfCP) == 1)//if there is only one module on CP or all the modules on CP are in the same group
        {
            if (ATYPE[CP[0]][0] < VMTYPE - 1)
            {
                Upgrade(CP[0], MODLINK);
                //CalculateCost(MODNUM, MODLINK);
                //if (TotalCost > BUDGET)    //check whether over budget
                //{
                //    Downgrade(CP[0], MODLINK);
                //}
            }
        }
        else
        {//group for four types in ascent order
            for (i = 1; i <= 4; i++)
                Grouping(NumOfCP, MODNUM, MODLINK, BUDGET, i);
        }
        
        for (i = 0; i < NumOfCP; i++)
        {//remove CP from the Graph
            V[CP[i]].used = true;
            for (j = 0; j < MODLINK; j++)
                if (E[j].to == CP[i] || E[j].from == CP[i])
                    E[j].used = true;
        }
    }
}
