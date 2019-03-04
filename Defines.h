//range for the time complexity of each module
#define MODCOMPLEXITY_LOW 1
#define MODCOMPLEXITY_HIGH 5
#define MODCOMPLEXITY_RANGE (MODCOMPLEXITY_HIGH - MODCOMPLEXITY_LOW)
//range for the storage request of each module
#define MODSTORAGE_LOW 1
#define MODSTORAGE_HIGH 3
#define MODSTORAGE_RANGE (MODSTORAGE_HIGH - MODSTORAGE_LOW)
//range for the data size to transfer on each edge
#define MODOUTPUTSIZE_LOW 0
#define MODOUTPUTSIZE_HIGH 1
#define MODOUTPUTSIZE_RANGE (MODOUTPUTSIZE_HIGH - MODOUTPUTSIZE_LOW)
//range for inter-cloud BW
#define BW_LOW 1
#define BW_HIGH 5
#define BW_RANGE (BW_HIGH - BW_LOW)
//range for CPU cycle on PM
#define PMCPUCYCLE_LOW 0
#define PMCPUCYCLE_HIGH 2
#define PMCPUCYCLE_RANGE (PMCPUCYCLE_HIGH - PMCPUCYCLE_LOW)
//range for I/O speed on PM
#define PMIO_LOW 3
#define PMIO_HIGH 6
#define PMIO_RANGE (PMIO_HIGH - PMIO_LOW)
//range for storage on PM
#define PMSTORAGE_LOW 4
#define PMSTORAGE_HIGH 10
#define PMSTORAGE_RANGE (PMSTORAGE_HIGH - PMSTORAGE_LOW)
//range for intra-cloud BW
#define PMTRANS_LOW 4
#define PMTRANS_HIGH 7
#define PMTRANS_RANGE (PMTRANS_HIGH - PMTRANS_LOW)
//range for CPU cycle on VM
#define VMCPUCYCLE_LOW 1
#define VMCPUCYCLE_HIGH 5
#define VMCPUCYCLE_RANGE (VMCPUCYCLE_HIGH - VMCPUCYCLE_LOW)
//range for I/O speed on VM
#define VMIO_LOW 1
#define VMIO_HIGH 5
#define VMIO_RANGE (VMIO_HIGH - VMIO_LOW)
//range for storage on VM
#define VMSTORAGE_LOW 2
#define VMSTORAGE_HIGH 5
#define VMSTORAGE_RANGE (VMSTORAGE_HIGH - VMSTORAGE_LOW)
//range for start up time on VM
#define VMSTART_UP_TIME_LOW 1
#define VMSTART_UP_TIME_HIGH 5
#define VMSTART_UP_TIME_RANGE (VMSTART_UP_TIME_HIGH - VMSTART_UP_TIME_LOW)

//#define MODNUM 5        //the number of modules
//#define MODLINK 7        //the number of edges among modules
//#define VMTYPE 5        //the number of VM types
//#define BUDGET 1000            //the upper bound of budget
#define MODNUM_MAX 60        //the maximum number of modules
#define MODLINK_MAX 1000    //the maximum number of edges among modules
#define VMTYPE_MAX 16        //the maximum number of VM types

#define CLOUDNUM 20            //the number of clouds
#define PMNUM 100            //the number of PM on each cloud
#define BWTYPE 8            //the number of BW type
#define MAX_TIME 1000000000    //the max total time
#define MAX_COST 1000000000
#define VMPERPRICE 1
#define BWPERPRICE 10

#define TIMES 20
