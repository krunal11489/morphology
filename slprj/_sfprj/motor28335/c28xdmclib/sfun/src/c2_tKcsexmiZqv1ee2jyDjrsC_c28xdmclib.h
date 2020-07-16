#ifndef __c2_tKcsexmiZqv1ee2jyDjrsC_c28xdmclib_h__
#define __c2_tKcsexmiZqv1ee2jyDjrsC_c28xdmclib_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_c2_tKcsexmiZqv1ee2jyDjrsC_ResolvedFunctionInfo
#define typedef_c2_tKcsexmiZqv1ee2jyDjrsC_ResolvedFunctionInfo

typedef struct {
  const char * context;
  const char * name;
  const char * dominantType;
  const char * resolved;
  uint32_T fileTimeLo;
  uint32_T fileTimeHi;
  uint32_T mFileTimeLo;
  uint32_T mFileTimeHi;
} c2_tKcsexmiZqv1ee2jyDjrsC_ResolvedFunctionInfo;

#endif                                 /*typedef_c2_tKcsexmiZqv1ee2jyDjrsC_ResolvedFunctionInfo*/

#ifndef typedef_SFc2_tKcsexmiZqv1ee2jyDjrsC_c28xdmclibInstanceStruct
#define typedef_SFc2_tKcsexmiZqv1ee2jyDjrsC_c28xdmclibInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint8_T c2_tKcsexmiZqv1ee2jyDjrsC_is_active_c2_tKcsexmiZqv1ee2jyDjrsC_c2;
  real_T c2_tKcsexmiZqv1ee2jyDjrsC_paramVal;
} SFc2_tKcsexmiZqv1ee2jyDjrsC_c28xdmclibInstanceStruct;

#endif                                 /*typedef_SFc2_tKcsexmiZqv1ee2jyDjrsC_c28xdmclibInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c2_tKcsexmiZqv1ee2jyDjrsC_c28xdmclib_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c2_tKcsexmiZqv1ee2jyDjrsC_c28xdmclib_get_check_sum(mxArray *plhs[]);
extern void c2_tKcsexmiZqv1ee2jyDjrsC_c28xdmclib_method_dispatcher(SimStruct *S,
  int_T method, void *data);

#endif
