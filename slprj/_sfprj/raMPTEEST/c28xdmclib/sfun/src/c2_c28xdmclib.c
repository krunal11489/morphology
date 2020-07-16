/* Include files */

#include "blascompat32.h"
#include "c28xdmclib_sfun.h"
#include "c2_c28xdmclib.h"

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c2_b_paramVal                  (1.0)

/* Variable Declarations */

/* Variable Definitions */
static const mxArray *c2_eml_mx;
static const mxArray *c2_b_eml_mx;

/* Function Declarations */
static void initialize_c2_c28xdmclib(SFc2_c28xdmclibInstanceStruct
  *chartInstance);
static void initialize_params_c2_c28xdmclib(SFc2_c28xdmclibInstanceStruct
  *chartInstance);
static void enable_c2_c28xdmclib(SFc2_c28xdmclibInstanceStruct *chartInstance);
static void disable_c2_c28xdmclib(SFc2_c28xdmclibInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_c28xdmclib(SFc2_c28xdmclibInstanceStruct *
  chartInstance);
static void set_sim_state_c2_c28xdmclib(SFc2_c28xdmclibInstanceStruct
  *chartInstance, const mxArray *c2_st);
static void finalize_c2_c28xdmclib(SFc2_c28xdmclibInstanceStruct *chartInstance);
static void sf_c2_c28xdmclib(SFc2_c28xdmclibInstanceStruct *chartInstance);
static void initSimStructsc2_c28xdmclib(SFc2_c28xdmclibInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber);
static int32_T c2_emlrt_marshallIn(SFc2_c28xdmclibInstanceStruct *chartInstance,
  const mxArray *c2_y, const char_T *c2_identifier);
static int32_T c2_b_emlrt_marshallIn(SFc2_c28xdmclibInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static uint8_T c2_c_emlrt_marshallIn(SFc2_c28xdmclibInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_c28xdmclib, const char_T
  *c2_identifier);
static uint8_T c2_d_emlrt_marshallIn(SFc2_c28xdmclibInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId);
static void init_dsm_address_info(SFc2_c28xdmclibInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c2_c28xdmclib(SFc2_c28xdmclibInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c2_is_active_c2_c28xdmclib = 0U;
  sf_mex_assign(&c2_b_eml_mx, sf_mex_call("numerictype", 1U, 10U, 15,
    "WordLength", 6, 32.0, 15, "FractionLength", 6, 9.0, 15, "BinaryPoint", 6,
    9.0, 15, "Slope", 6, 0.001953125, 15, "FixedExponent", 6, -9.0), TRUE);
  sf_mex_assign(&c2_eml_mx, sf_mex_call("fimath", 1U, 42U, 15, "RoundMode", 15,
    "nearest", 15, "RoundingMethod", 15, "Nearest", 15, "OverflowMode", 15,
    "saturate", 15, "OverflowAction", 15, "Saturate", 15, "ProductMode", 15,
    "FullPrecision", 15, "ProductWordLength", 6, 32.0, 15,
    "MaxProductWordLength", 6, 65535.0, 15, "ProductFractionLength", 6, 30.0, 15,
    "ProductFixedExponent", 6, -30.0, 15, "ProductSlope", 6,
    9.3132257461547852E-10, 15, "ProductSlopeAdjustmentFactor", 6, 1.0, 15,
    "ProductBias", 6, 0.0, 15, "SumMode", 15, "FullPrecision", 15,
    "SumWordLength", 6, 32.0, 15, "MaxSumWordLength", 6, 65535.0, 15,
    "SumFractionLength", 6, 30.0, 15, "SumFixedExponent", 6, -30.0, 15,
    "SumSlope", 6, 9.3132257461547852E-10, 15, "SumSlopeAdjustmentFactor", 6,
    1.0, 15, "SumBias", 6, 0.0, 15, "CastBeforeSum", 3, TRUE), TRUE);
}

static void initialize_params_c2_c28xdmclib(SFc2_c28xdmclibInstanceStruct
  *chartInstance)
{
  real_T c2_d0;
  sf_set_error_prefix_string(
    "Error evaluating data 'paramVal' in the parent workspace.\n");
  sf_mex_import_named("paramVal", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      &c2_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c2_paramVal = c2_d0;
  sf_set_error_prefix_string("Stateflow Runtime Error (chart): ");
}

static void enable_c2_c28xdmclib(SFc2_c28xdmclibInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c2_c28xdmclib(SFc2_c28xdmclibInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static const mxArray *get_sim_state_c2_c28xdmclib(SFc2_c28xdmclibInstanceStruct *
  chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  const mxArray *c2_b_y = NULL;
  int32_T c2_u;
  const mxArray *c2_c_y = NULL;
  uint8_T c2_b_u;
  const mxArray *c2_d_y = NULL;
  int32_T *c2_e_y;
  c2_e_y = (int32_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellarray(2), FALSE);
  c2_b_y = NULL;
  c2_u = *c2_e_y;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c2_b_y, sf_mex_call("fi", 1U, 8U, 15, "fimath", 14, sf_mex_dup
    (c2_eml_mx), 15, "numerictype", 14, sf_mex_dup(c2_b_eml_mx), 15,
    "simulinkarray", 14, c2_c_y, 15, "fimathislocal", 3, TRUE), FALSE);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_b_u = chartInstance->c2_is_active_c2_c28xdmclib;
  c2_d_y = NULL;
  sf_mex_assign(&c2_d_y, sf_mex_create("y", &c2_b_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c2_y, 1, c2_d_y);
  sf_mex_assign(&c2_st, c2_y, FALSE);
  return c2_st;
}

static void set_sim_state_c2_c28xdmclib(SFc2_c28xdmclibInstanceStruct
  *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_u;
  int32_T *c2_y;
  c2_y = (int32_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c2_u = sf_mex_dup(c2_st);
  *c2_y = c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 0)),
    "y");
  chartInstance->c2_is_active_c2_c28xdmclib = c2_c_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_u, 1)),
     "is_active_c2_c28xdmclib");
  sf_mex_destroy(&c2_u);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_c28xdmclib(SFc2_c28xdmclibInstanceStruct *chartInstance)
{
  sf_mex_destroy(&c2_eml_mx);
  sf_mex_destroy(&c2_b_eml_mx);
}

static void sf_c2_c28xdmclib(SFc2_c28xdmclibInstanceStruct *chartInstance)
{
  int32_T *c2_y;
  c2_y = (int32_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  *c2_y = 512;
}

static void initSimStructsc2_c28xdmclib(SFc2_c28xdmclibInstanceStruct
  *chartInstance)
{
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber)
{
}

const mxArray *sf_c2_c28xdmclib_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo;
  c2_ResolvedFunctionInfo c2_info[7];
  c2_ResolvedFunctionInfo (*c2_b_info)[7];
  const mxArray *c2_m0 = NULL;
  int32_T c2_i0;
  c2_ResolvedFunctionInfo *c2_r0;
  c2_nameCaptureInfo = NULL;
  c2_b_info = (c2_ResolvedFunctionInfo (*)[7])c2_info;
  (*c2_b_info)[0].context = "";
  (*c2_b_info)[0].name = "numerictype";
  (*c2_b_info)[0].dominantType = "embedded.fi";
  (*c2_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/@embedded/@fi/numerictype.m";
  (*c2_b_info)[0].fileTimeLo = 1289503476U;
  (*c2_b_info)[0].fileTimeHi = 0U;
  (*c2_b_info)[0].mFileTimeLo = 0U;
  (*c2_b_info)[0].mFileTimeHi = 0U;
  (*c2_b_info)[1].context = "";
  (*c2_b_info)[1].name = "fi_impl";
  (*c2_b_info)[1].dominantType = "";
  (*c2_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/fi_impl.m";
  (*c2_b_info)[1].fileTimeLo = 1326711796U;
  (*c2_b_info)[1].fileTimeHi = 0U;
  (*c2_b_info)[1].mFileTimeLo = 0U;
  (*c2_b_info)[1].mFileTimeHi = 0U;
  (*c2_b_info)[2].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/fi_impl.m!fi_helper";
  (*c2_b_info)[2].name = "length";
  (*c2_b_info)[2].dominantType = "cell";
  (*c2_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m";
  (*c2_b_info)[2].fileTimeLo = 1303133606U;
  (*c2_b_info)[2].fileTimeHi = 0U;
  (*c2_b_info)[2].mFileTimeLo = 0U;
  (*c2_b_info)[2].mFileTimeHi = 0U;
  (*c2_b_info)[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/fi_impl.m!fi_helper";
  (*c2_b_info)[3].name = "eml_fi_checkforconst";
  (*c2_b_info)[3].dominantType = "embedded.numerictype";
  (*c2_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/eml_fi_checkforconst.m";
  (*c2_b_info)[3].fileTimeLo = 1326711794U;
  (*c2_b_info)[3].fileTimeHi = 0U;
  (*c2_b_info)[3].mFileTimeLo = 0U;
  (*c2_b_info)[3].mFileTimeHi = 0U;
  (*c2_b_info)[4].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/fi_impl.m!fi_helper";
  (*c2_b_info)[4].name = "isfi";
  (*c2_b_info)[4].dominantType = "double";
  (*c2_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m";
  (*c2_b_info)[4].fileTimeLo = 1289503410U;
  (*c2_b_info)[4].fileTimeHi = 0U;
  (*c2_b_info)[4].mFileTimeLo = 0U;
  (*c2_b_info)[4].mFileTimeHi = 0U;
  (*c2_b_info)[5].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m";
  (*c2_b_info)[5].name = "isnumerictype";
  (*c2_b_info)[5].dominantType = "char";
  (*c2_b_info)[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isnumerictype.m";
  (*c2_b_info)[5].fileTimeLo = 1289503412U;
  (*c2_b_info)[5].fileTimeHi = 0U;
  (*c2_b_info)[5].mFileTimeLo = 0U;
  (*c2_b_info)[5].mFileTimeHi = 0U;
  (*c2_b_info)[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/fi_impl.m!fi_helper";
  (*c2_b_info)[6].name = "eml_fi_checkforerror";
  (*c2_b_info)[6].dominantType = "embedded.numerictype";
  (*c2_b_info)[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/eml_fi_checkforerror.m";
  (*c2_b_info)[6].fileTimeLo = 1289503402U;
  (*c2_b_info)[6].fileTimeHi = 0U;
  (*c2_b_info)[6].mFileTimeLo = 0U;
  (*c2_b_info)[6].mFileTimeHi = 0U;
  sf_mex_assign(&c2_m0, sf_mex_createstruct("nameCaptureInfo", 1, 7), FALSE);
  for (c2_i0 = 0; c2_i0 < 7; c2_i0++) {
    c2_r0 = &c2_info[c2_i0];
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->context)), "context", "nameCaptureInfo",
                    c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->name, 15, 0U,
      0U, 0U, 2, 1, strlen(c2_r0->name)), "name", "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->dominantType,
      15, 0U, 0U, 0U, 2, 1, strlen(c2_r0->dominantType)), "dominantType",
                    "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", c2_r0->resolved, 15,
      0U, 0U, 0U, 2, 1, strlen(c2_r0->resolved)), "resolved", "nameCaptureInfo",
                    c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeLo,
      7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo", c2_i0);
    sf_mex_addfield(c2_m0, sf_mex_create("nameCaptureInfo", &c2_r0->mFileTimeHi,
      7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo", c2_i0);
  }

  sf_mex_assign(&c2_nameCaptureInfo, c2_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c2_nameCaptureInfo);
  return c2_nameCaptureInfo;
}

static int32_T c2_emlrt_marshallIn(SFc2_c28xdmclibInstanceStruct *chartInstance,
  const mxArray *c2_y, const char_T *c2_identifier)
{
  int32_T c2_b_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_y = c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_y), &c2_thisId);
  sf_mex_destroy(&c2_y);
  return c2_b_y;
}

static int32_T c2_b_emlrt_marshallIn(SFc2_c28xdmclibInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  const mxArray *c2_mxFi = NULL;
  const mxArray *c2_mxInt = NULL;
  int32_T c2_i1;
  sf_mex_check_fi(c2_parentId, c2_u, 0, 0U, 0, c2_eml_mx, c2_b_eml_mx);
  sf_mex_assign(&c2_mxFi, sf_mex_dup(c2_u), FALSE);
  sf_mex_assign(&c2_mxInt, sf_mex_call("simulinkarray", 1U, 1U, 14, sf_mex_dup
    (c2_mxFi)), FALSE);
  sf_mex_import(c2_parentId, sf_mex_dup(c2_mxInt), &c2_i1, 1, 6, 0U, 0, 0U, 0);
  sf_mex_destroy(&c2_mxFi);
  sf_mex_destroy(&c2_mxInt);
  c2_y = c2_i1;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static uint8_T c2_c_emlrt_marshallIn(SFc2_c28xdmclibInstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_c28xdmclib, const char_T
  *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_c28xdmclib), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_c28xdmclib);
  return c2_y;
}

static uint8_T c2_d_emlrt_marshallIn(SFc2_c28xdmclibInstanceStruct
  *chartInstance, const mxArray *c2_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_u);
  return c2_y;
}

static void init_dsm_address_info(SFc2_c28xdmclibInstanceStruct *chartInstance)
{
}

/* SFunction Glue Code */
void sf_c2_c28xdmclib_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4127462870U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1641590503U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2272196610U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2194931305U);
}

mxArray *sf_c2_c28xdmclib_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("LwZ5Y8NgDbThYVPSlo2mUD");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(11));

      {
        const char *fixptFields[] = { "isSigned", "wordLength", "bias", "slope",
          "exponent", "isScaledDouble" };

        mxArray *mxFixpt = mxCreateStructMatrix(1,1,6,fixptFields);
        mxSetField(mxFixpt,0,"isSigned",mxCreateDoubleScalar(1));
        mxSetField(mxFixpt,0,"wordLength",mxCreateDoubleScalar(32));
        mxSetField(mxFixpt,0,"bias",mxCreateDoubleScalar(0));
        mxSetField(mxFixpt,0,"slope",mxCreateDoubleScalar(1));
        mxSetField(mxFixpt,0,"exponent",mxCreateDoubleScalar(-9));
        mxSetField(mxFixpt,0,"isScaledDouble",mxCreateDoubleScalar(0));
        mxSetField(mxType,0,"fixpt",mxFixpt);
      }

      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(11));

      {
        const char *fixptFields[] = { "isSigned", "wordLength", "bias", "slope",
          "exponent", "isScaledDouble" };

        mxArray *mxFixpt = mxCreateStructMatrix(1,1,6,fixptFields);
        mxSetField(mxFixpt,0,"isSigned",mxCreateDoubleScalar(1));
        mxSetField(mxFixpt,0,"wordLength",mxCreateDoubleScalar(32));
        mxSetField(mxFixpt,0,"bias",mxCreateDoubleScalar(0));
        mxSetField(mxFixpt,0,"slope",mxCreateDoubleScalar(1));
        mxSetField(mxFixpt,0,"exponent",mxCreateDoubleScalar(-9));
        mxSetField(mxFixpt,0,"isScaledDouble",mxCreateDoubleScalar(0));
        mxSetField(mxType,0,"fixpt",mxFixpt);
      }

      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

static const mxArray *sf_get_sim_state_info_c2_c28xdmclib(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c2_c28xdmclib\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_c28xdmclib_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const char* sf_get_instance_specialization()
{
  return "8IxuhgWZAGCCmLIdJ0KtmB";
}

static void sf_opaque_initialize_c2_c28xdmclib(void *chartInstanceVar)
{
  initialize_params_c2_c28xdmclib((SFc2_c28xdmclibInstanceStruct*)
    chartInstanceVar);
  initialize_c2_c28xdmclib((SFc2_c28xdmclibInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c2_c28xdmclib(void *chartInstanceVar)
{
  enable_c2_c28xdmclib((SFc2_c28xdmclibInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_c28xdmclib(void *chartInstanceVar)
{
  disable_c2_c28xdmclib((SFc2_c28xdmclibInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_c28xdmclib(void *chartInstanceVar)
{
  sf_c2_c28xdmclib((SFc2_c28xdmclibInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c2_c28xdmclib(SimStruct* S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c2_c28xdmclib
    ((SFc2_c28xdmclibInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_c28xdmclib();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c2_c28xdmclib(SimStruct* S, const mxArray *
  st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c2_c28xdmclib();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c2_c28xdmclib((SFc2_c28xdmclibInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c2_c28xdmclib(SimStruct* S)
{
  return sf_internal_get_sim_state_c2_c28xdmclib(S);
}

static void sf_opaque_set_sim_state_c2_c28xdmclib(SimStruct* S, const mxArray
  *st)
{
  sf_internal_set_sim_state_c2_c28xdmclib(S, st);
}

static void sf_opaque_terminate_c2_c28xdmclib(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_c28xdmclibInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
    }

    finalize_c2_c28xdmclib((SFc2_c28xdmclibInstanceStruct*) chartInstanceVar);
    free((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }

  unload_c28xdmclib_optimization_info();
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc2_c28xdmclib((SFc2_c28xdmclibInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_c28xdmclib(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c2_c28xdmclib((SFc2_c28xdmclibInstanceStruct*)
      (((ChartInfoStruct *)ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_c28xdmclib(SimStruct *S)
{
  /* Actual parameters from chart:
     paramVal
   */
  const char_T *rtParamNames[] = { "p1" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for paramVal*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_c28xdmclib_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,2,
      "gatewayCannotBeInlinedMultipleTimes"));
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,1);
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1331829770U));
  ssSetChecksum1(S,(3986049386U));
  ssSetChecksum2(S,(2142502687U));
  ssSetChecksum3(S,(4255714689U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_c28xdmclib(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_c28xdmclib(SimStruct *S)
{
  SFc2_c28xdmclibInstanceStruct *chartInstance;
  chartInstance = (SFc2_c28xdmclibInstanceStruct *)malloc(sizeof
    (SFc2_c28xdmclibInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_c28xdmclibInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c2_c28xdmclib;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c2_c28xdmclib;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c2_c28xdmclib;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_c28xdmclib;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_c28xdmclib;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c2_c28xdmclib;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c2_c28xdmclib;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c2_c28xdmclib;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_c28xdmclib;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_c28xdmclib;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_c28xdmclib;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
}

void c2_c28xdmclib_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_c28xdmclib(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_c28xdmclib(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_c28xdmclib(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_c28xdmclib_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
