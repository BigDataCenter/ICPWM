void GenerateVMTYPE(int numVM)
{//generate VM type
    int        i, j;
    double    CPU[VMTYPE_MAX], IO[VMTYPE_MAX], storage[VMTYPE_MAX], price[VMTYPE_MAX], temp[VMTYPE_MAX], StartUpTime[VMTYPE_MAX];
    
    
    for(i = 0; i < numVM; i ++)
    {//generate values
        CPU[i]                = VMCPUCYCLE_LOW + (rand() / (double)RAND_MAX) * (double)VMCPUCYCLE_RANGE;
        IO[i]                = VMIO_LOW + (rand() / (double)RAND_MAX) * (double)VMIO_RANGE;
        storage[i]            = VMSTORAGE_LOW + (rand() / (double)RAND_MAX) * (double)VMSTORAGE_RANGE;
        price[i]            = VMPERPRICE * IO[i] * storage[i] / CPU[i];
        StartUpTime[i]        = VMSTART_UP_TIME_LOW + (rand() / (double)RAND_MAX) * (double)VMSTART_UP_TIME_RANGE;
    }
    //sort values
    InsertSortDescent(CPU, numVM);
    InsertSortAscent(IO, numVM);
    InsertSortAscent(storage, numVM);
    InsertSortAscent(price, numVM);
    InsertSortDescent(StartUpTime, numVM);
    
    for(i = 0; i < numVM; i ++)
    {
        VT[i].CPU            = CPU[i];
        VT[i].IO            = IO[i];
        VT[i].price            = price[i];
        VT[i].storage        = storage[i];
        VT[i].StartUpTime = StartUpTime[i];
    }
}
