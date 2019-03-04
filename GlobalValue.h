double VCost;        //total execution cost
double ECost;        //total data transfer cost
double SCost;        //data storage cost
double TotalTime;    //total time
double TotalCost;    //total cost

int ATYPE[MODNUM_MAX][2];                        //VM type assigned to each module
int CP[MODNUM_MAX];                                //the module on CP
int BWTypeBetweenClouds[CLOUDNUM][CLOUDNUM];    //the BW type for each edge between clouds
int IfCloudInUse[CLOUDNUM];                        //whether a cloud in use(1 means in use, 0 means not)
int UsedCloud[CLOUDNUM];                        //which clouds in use
int UsedCloudNum;                                //the number of clouds in use
int VT_MIN[MODNUM_MAX];
int VT_MAX[MODNUM_MAX];
int MINVT[MODNUM_MAX];                            //the worst VM type for each module
int BWTYPENUM[CLOUDNUM];                        //the BW type number of each cloud
