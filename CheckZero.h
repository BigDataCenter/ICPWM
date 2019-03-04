void CheckZero(int NumOfCP, int MODLINK)
{
    int i, j, VMT1, GI1, VMT2, GI2;
    list<int>::iterator GroupPoint;
    //check zero and merge adjacent groups
    i = 0;
    while (i < NumOfCP - 1)
    {
        VMT1 = ATYPE[CP[i]][0];
        GI1 = ATYPE[CP[i]][1];
        VMT2 = ATYPE[CP[i + 1]][0];
        GI2 = ATYPE[CP[i + 1]][1];
        
        if (VMT1 == VMT2 && GI1 != GI2)
        {
            GroupPoint = VT[VMT2].Group[GI2].begin();
            while (GroupPoint != VT[VMT2].Group[GI2].end())
            {
                if (*GroupPoint == 0)
                {
                    j = 1;
                }
                VT[VMT1].Group[GI1].push_back(*GroupPoint);
                ATYPE[*GroupPoint][1] = GI1;
                UpdateVmChanges(*GroupPoint, MODLINK);
                GroupPoint++;
            }
            VT[VMT2].Group.erase(GI2);
        }
        i++;
    }
}
