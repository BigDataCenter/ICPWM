void Upgrade(int ModIndex, int MODLINK)
{
    int VMT, GI, NewVMT, NewGI;
    list<int> glist;
    list<int>::iterator GroupPoint;
    
    VMT            = ATYPE[ModIndex][0];
    GI            = ATYPE[ModIndex][1];
    glist.clear();
    glist.assign(VT[VMT].Group[GI].begin(), VT[VMT].Group[GI].end());
    NewVMT        = VMT + 1;
    GroupPoint    = VT[VMT].Group[GI].begin();
    NewGI        = *GroupPoint;
    VT[NewVMT].Group.insert(make_pair(NewGI, glist));
    while (GroupPoint != VT[VMT].Group[GI].end())
    {
        ATYPE[*GroupPoint][0] = NewVMT;
        ATYPE[*GroupPoint][1] = NewGI;
        UpdateVmChanges(*GroupPoint, MODLINK);
        GroupPoint++;
    }
    VT[VMT].Group.erase(GI);
}
