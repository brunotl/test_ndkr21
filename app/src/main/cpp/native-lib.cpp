#include <jni.h>
#include <cmath>
#include <cassert>

extern "C"
JNIEXPORT jdouble JNICALL
Java_org_bruno_test_1ndkr21_MainActivity_DoubleFromJNI(JNIEnv *env, jobject thiz) {

    static constexpr double exp = 0.190263;
    static constexpr double base = 1013.25;

    // expected result : 3.7314416933840704
    double result = std::pow(base, exp);
    // but 'NaN' is returned when build with -O1, -O2 or -O3 build flag (NDKr21 ABI arm64-v8a)
    // seem's linked to this change in bionic/libm : https://android.googlesource.com/platform/bionic/+/f6b101d3ecfb2567834c6c439f1d1d3a4a7d844e

    assert(isfinite(result));
    return result;
}