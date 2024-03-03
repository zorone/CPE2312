#include "automataWorkspace.h"

// TODO: Seperate Debug codes out completely. If possible, function that you would like to inspect, should pass into debug() function.
// TODO: Add user interaction mode -i, that it waits for user testing string.

// TODO: Add support for Quiet -q[uiet]
// TODO: Add support for Progress bar -P[rogress]
// TODO: Add support for no cached -n[ocache]
// TODO: Add support for only report -R[eport]

// TODO: Add support for no recursive (for NFA -- check only until it is accept.) -c[ontinue]
// TODO: Add support for recursive checking (for NFA -- check all possible route.) -r[ecursive]
// TODO: Add support for Listing all route (for NFA) -l[ist]

// TODO: Add support for stat report -s[tat]
// TODO: Add support for verbose stat report (for NFA) -S[tat]

// TODO: Add support for force cache rewrite (In cases data is missing. -- default is skip character if possible.) -f[orce]

int main(int argc, char *argv[]){
    init();
    config();

    setup("w");
    loop();
    fileClose();

    setup("r");
    test();
    fileClose();

    return 0;
}