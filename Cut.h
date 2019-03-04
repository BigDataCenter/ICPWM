void Cut(int VMT, int GI, list<int>::iterator StartPoint, list<int>::iterator EndPoint)
{//cut VT[VMT].Group[GI] from GroupPoint
    list<int> NewGroupList;
    int NewGI, EtoRemove;
    list<int>::iterator GroupPoint;
    
    NewGroupList.clear();
    NewGroupList.assign(StartPoint, EndPoint);
    NewGI = *StartPoint;
    VT[VMT].Group.insert(make_pair(NewGI, NewGroupList));
    GroupPoint = StartPoint;
    while (GroupPoint != EndPoint)
    {
        EtoRemove = *GroupPoint;
        ATYPE[EtoRemove][1] = NewGI;
        GroupPoint++;
        VT[VMT].Group[GI].remove(EtoRemove);
    }
}
