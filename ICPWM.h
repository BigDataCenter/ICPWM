double ICPWM(int MODNUM, int MODLINK, int VMTYPE, int BUDGET, int LOOPTIME)
{//Multi-cloud Mapping Algorithm
    double LeastTotalTime = MAX_TIME;
    
    for (int i = 0; i < LOOPTIME; i++)
    {
        //ModNumOnCP = FindCP(MODNUM, MODLINK);
        AssignVT(MODNUM, MODLINK, VMTYPE, BUDGET);
        Trans(MODNUM, MODLINK, VMTYPE, BUDGET);
        CalculateCost(MODNUM, MODLINK);
        //cout << "TotalCost = " << TotalCost << endl;
        if (TotalCost > BUDGET)    //check whether over budget
            continue;
        CalculateTime(MODNUM, MODLINK);
        //cout << "TotalTime = " << TotalTime << endl;
        if(TotalTime < LeastTotalTime)
        {
            LeastTotalTime = TotalTime;
        }
        //cout << i << " is done." << endl;
    }
    if (LeastTotalTime == MAX_TIME)
        return -1;
    return LeastTotalTime;
}
