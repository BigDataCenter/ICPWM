int RandNumGivenRange(int iStartNum, int iEndNum)
{//get a random number between iStartNum and iEndNum
    int iRandNum;
    
    iRandNum = iStartNum + rand() % (iEndNum - iStartNum + 1);
    return iRandNum;
}
