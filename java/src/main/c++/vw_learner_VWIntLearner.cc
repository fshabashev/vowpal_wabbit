#include "../../../../vowpalwabbit/vw.h"
#include "jni_base_learner.h"
#include "vw_learner_VWIntLearner.h"

jint intPredictor(example* vec, JNIEnv *env) { return vec->pred.multiclass; }

jint intCBADFPredictor(example* vec, JNIEnv *env) { return vec->pred.a_s[0].action; }

JNIEXPORT jint JNICALL Java_vw_learner_VWIntLearner_predict(JNIEnv *env, jobject obj, jstring example_string, jboolean learn, jlong vwPtr)
{ return base_predict<jint>(env, obj, example_string, learn, vwPtr, intPredictor);
}

JNIEXPORT jint JNICALL Java_vw_learner_VWIntLearner_predictMultiline(JNIEnv *env, jobject obj, jobjectArray example_strings, jboolean learn, jlong vwPtr)
{ vw* vwInstance = (vw*)vwPtr;
  std::cerr << vwInstance->final_regressor_name << std::endl;
  return base_predict<jint>(env, obj, example_strings, learn, vwPtr, intCBADFPredictor);
}
