#ifndef __CLABS_H__
#define __CLABS_H__
#define FOO_NAME_LENGTH 1000

typedef struct _tagFOO_DATA_S {
    int nIndex_;
    char szName_[FOO_NAME_LENGTH];
}FOO_DATA_S;

typedef struct _tagGOO_DATA_S {
    int nIndex_;
    const char *szName_;
}GOO_DATA_S;


#ifdef __cplusplus  
extern "C" {
#endif
    FOO_DATA_S* GetFooByID(FOO_DATA_S* foos, int nUnits, int id);
    int GeLabIntactInterlace(int nLoops);
    int GeLabIntactBatch(int nLoops);
    int GeLabIntactBatchUnlikely(int nLoops);
#ifdef __cplusplus 
}
#endif 

#endif // __CLABS_H__