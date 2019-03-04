#include "Includes.h"
#include "Defines.h"
#include "GlobalValue.h"
#include "Structure.h"
#include "Functions.h"

int value[20][6]={
    {5,7,5,1000,1500,200000},
    {8,14,6,2200,2250,210000},
    {10,18,6,3000,3500,220000},
    {13,30,7,4000,6500,230000},
    {15,60,7,7500,8500,240000},
    {18,80,8,9000,9500,250000},
    {20,100,8,11000,13000,260000},
    {23,150,9,14000,17000,270000},
    {25,200,9,18000,19500,280000},
    {28,250,10,20000,25000,290000},
    {30,300,10,24000,32500,300000},
    {33,380,11,28000,37500,310000},
    {35,400,11,32000,42500,320000},
    {38,450,12,40000,47500,330000},
    {40,500,12,50000,60000,340000},
    {43,550,13,70000,76000,350000},
    {45,580,13,82000,90000,360000},
    {48,600,14,115000,130000,370000},
    {50,650,14,145000,147500,380000},
    {53,700,15,150000,155000,390000}
};

int main(int argc, const char * argv[]) {
    int index = 0;
    int MODNUM = 0;        //the number of modules
    int MODLINK = 0;    //the number of edges between modules
    int VMTYPE;        //the number of VM types
    int BUDGET;        //the upper bound of budget
    MODNUM = value[index][0];
    MODLINK = value[index][1];
    VMTYPE = value[index][2];
    BUDGET = value[index][3]/2;
    SimDataGenerator(index, MODNUM, MODLINK, VMTYPE);    //generate data
    Initial(MODNUM, MODLINK, VMTYPE);                                            //initialization
    cout << ICPWM(MODNUM, MODLINK, VMTYPE, BUDGET, 300) << endl;
    return 0;
}
