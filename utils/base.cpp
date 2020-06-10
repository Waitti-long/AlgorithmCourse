#include "base.h"

using namespace std;

long long now() {
    return chrono::system_clock::now().time_since_epoch().count();
}
