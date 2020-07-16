/* Include files */

#include "c28xdmclib_sfun.h"
#include "c2_qCW84vY8LaeI6fBIdBFJdB_c28xdmclib.h"
#include "c2_tKcsexmiZqv1ee2jyDjrsC_c28xdmclib.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _c28xdmclibMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void c28xdmclib_initializer(void)
{
}

void c28xdmclib_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_c28xdmclib_method_dispatcher(SimStruct *simstructPtr, unsigned
  int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==2) {
    if (!strcmp(specsCksum, "qCW84vY8LaeI6fBIdBFJdB")) {
      c2_qCW84vY8LaeI6fBIdBFJdB_c28xdmclib_method_dispatcher(simstructPtr,
        method, data);
      return 1;
    }

    if (!strcmp(specsCksum, "tKcsexmiZqv1ee2jyDjrsC")) {
      c2_tKcsexmiZqv1ee2jyDjrsC_c28xdmclib_method_dispatcher(simstructPtr,
        method, data);
      return 1;
    }

    return 0;
  }

  return 0;
}

unsigned int sf_c28xdmclib_process_check_sum_call( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>2 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"library")) {
      char machineName[100];
      mxGetString(prhs[2], machineName,sizeof(machineName)/sizeof(char));
      machineName[(sizeof(machineName)/sizeof(char)-1)] = '\0';
      if (!strcmp(machineName,"c28xdmclib")) {
        if (nrhs==3) {
          ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4282727208U);
          ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(751911174U);
          ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2268821276U);
          ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(983295101U);
        } else if (nrhs==4) {
          unsigned int chartFileNumber;
          chartFileNumber = (unsigned int)mxGetScalar(prhs[3]);
          switch (chartFileNumber) {
           case 2:
            {
              extern void sf_c2_tKcsexmiZqv1ee2jyDjrsC_c28xdmclib_get_check_sum
                (mxArray *plhs[]);
              sf_c2_tKcsexmiZqv1ee2jyDjrsC_c28xdmclib_get_check_sum(plhs);
              break;
            }

           default:
            ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
            ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
            ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
            ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
          }
        } else {
          return 0;
        }
      } else {
        return 0;
      }
    } else {
      return 0;
    }
  } else {
    return 0;
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_c28xdmclib_autoinheritance_info( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 2:
      {
        if (strcmp(aiChksum, "NR4i17GRFWcSsqmBvUcn0F") == 0) {
          extern mxArray
            *sf_c2_qCW84vY8LaeI6fBIdBFJdB_c28xdmclib_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c2_qCW84vY8LaeI6fBIdBFJdB_c28xdmclib_get_autoinheritance_info();
          break;
        }

        if (strcmp(aiChksum, "2Nt8kkdxQxKbVuGV0tOIkF") == 0) {
          extern mxArray
            *sf_c2_tKcsexmiZqv1ee2jyDjrsC_c28xdmclib_get_autoinheritance_info
            (void);
          plhs[0] =
            sf_c2_tKcsexmiZqv1ee2jyDjrsC_c28xdmclib_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_c28xdmclib_get_eml_resolved_functions_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 2:
      {
        extern const mxArray
          *sf_c2_tKcsexmiZqv1ee2jyDjrsC_c28xdmclib_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_tKcsexmiZqv1ee2jyDjrsC_c28xdmclib_get_eml_resolved_functions_info
          ();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

void c28xdmclib_debug_initialize(void)
{
  _c28xdmclibMachineNumber_ = sf_debug_initialize_machine("c28xdmclib","sfun",1,
    1,0,0,0);
  sf_debug_set_machine_event_thresholds(_c28xdmclibMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(_c28xdmclibMachineNumber_,0);
}

void c28xdmclib_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_c28xdmclib_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info("c28xdmclib",
      "motor28335");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_c28xdmclib_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
